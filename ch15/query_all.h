#ifndef QUERY_ALL_H
#define QUERY_ALL_H

#include <algorithm>
#include <string>
#include <memory>
#include <iostream>
#include "queryresult.h"
#include "textquery.h"

//class TextQuery;
//class QueryResult;

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;          //用于eval函数
	virtual ~Query_base() = default;
private:
	//eval返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&)  const = 0;        //纯虚函数
	//rep是表示查询的一个string
	virtual std::string rep() const = 0;

};

class Query
{
	//这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string&);			//构建一个新的WordQuery
	
	//接口函数：调用对应的Query_base操作
	QueryResult eval(const TextQuery &t) const
	{
		return q->eval(t);
	}
	std::string rep()const 
	{
		return q->rep();
	}

private:
	Query(std::shared_ptr<Query_base> query): q(query) {}
	std::shared_ptr<Query_base> q;

};

class WordQuery: public Query_base
{
	friend class Query;
	WordQuery(const std::string &s): query_word(s) { }

	//WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word);
	}

	std::string rep() const 
	{
		return query_word;
	}

	std::string query_word;    //要查找的单词

};

inline Query::Query(const std::string &s): q(new WordQuery(s)) { }    //Query的构造函数

class NotQuery: public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query &q): query(q) { }
	//NotQuery将定义所有继承而来的纯虚函数
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	Query query;

};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


//BinaryQuery也是个抽象基类，进行两个运算对象的运算
class BinaryQuery: public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s)  { }

	//直接继承eval纯虚函数
	std::string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; 
	}

	Query lhs, rhs;				//左侧和右侧运算对象
	std::string opSym;			//运算符的名字

};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") { }

	//声明eval,将其具体化
	QueryResult eval(const TextQuery&)  const;

};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|")  { }

	//声明eval,将其具体化
	QueryResult eval(const TextQuery&) const;

};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

//返回运算对象查询结果set的并集
QueryResult OrQuery::eval(const TextQuery &text) const
{
	//通过Query成员lhs和rhs进行的虚调用
	//调用eval返回每个运算对象的QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	//将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = std::make_shared<set<line_no>>(left.begin(), left.end());

	//插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(), right.end());

	//返回一个新的QueryResult，它表示lhs和rhs的并集
	return QueryResult(rep(), ret_lines, left.get_file());
}

//返回运算对象查询结果set的交集
QueryResult AndQuery::eval(const TextQuery& text) const
{
	//通过Query运算对象进行的虚调用，以获得运算对象的查询结果set
	auto left = lhs.eval(text), right = rhs.eval(text);
	//保存left和right交集的set
	auto ret_lines = std::make_shared<set<line_no>>();

	//将两个范围的交集写入一个插入迭代器中
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

//返回运算对象的结果set中不存在的行
QueryResult NotQuery::eval(const TextQuery &text) const
{
	//通过Query运算对象对eval进行虚调用
	auto result = query.eval(text);
	//开始时结果set为空
	auto ret_lines = std::make_shared<set<line_no>>();
	//我们必须在运算对象出现的所有行中进行迭代
	auto beg = result.begin(), end = result.end();
	//对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
	auto sz = result.get_file()->size();
	for(size_t n = 0; n != sz; ++n)
	{
		//如果我们还没有处理完result的所有行
		//检查当前行是否存在
		if(beg == end || *beg != n)
			ret_lines->insert(n);		//如果不在result当中，添加这一行
		else if(beg != end)
			++beg;						//否则继续获取result的下一行(如果有的话)
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

#endif

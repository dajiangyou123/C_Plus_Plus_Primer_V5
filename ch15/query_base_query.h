#ifndef _QUERY_BASE_QUERY
#define _QUERY_BASE_QUERY

#include <string>
#include <memory>

class TextQuery;
class QueryResult;

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

#endif

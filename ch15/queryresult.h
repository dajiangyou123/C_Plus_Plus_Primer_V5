#ifndef _Query_Result_H
#define _Query_Result_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::shared_ptr;
using std::set;
using std::map;

class TextQuery;
class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

private:
	string sought;           //查询单词
	shared_ptr<set<TextQuery::line_no>> lines;    //出现的行号
	shared_ptr<vector<string>> file;   //输入文件
};




#endif

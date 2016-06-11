#ifndef _Text_Query_H
#define _Text_Query_H

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

class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file;             //输入文件
	
	//单词到行号之间的映射
	map<string, shared_ptr<set<line_no>>> wm;
};


#endif

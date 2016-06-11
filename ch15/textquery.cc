#include "textquery.h"
#include "queryresult.h"

//读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(std::ifstream &is): file(new vector<string>)
{
	std::string text;
	while(getline(is, text))    //取得每一行
	{
		file->push_back(text);
		int n = file->size() - 1;     //行号虽然此处从0开始,但是输出时又加上了1
		std::istringstream line(text);  //拆分每一行
		string word;

		while(line >> word)
		{
			auto &lines = wm[word];
			if(!lines)    //该单词第一次出现是，lines指针为空
				lines.reset(new set<line_no>);
			lines->insert(n);    //将行号插入set中
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	//如果未找到sought，将返回一个指向空set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);   //未找到
	else
		return QueryResult(sought, loc->second, file);

}

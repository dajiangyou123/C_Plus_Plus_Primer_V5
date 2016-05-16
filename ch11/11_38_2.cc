//使用unordered_map实现单词转换程序

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

//建立unordered_map
unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string word, rule;
	while(map_file >> word && getline(map_file, rule))        //此处不使用两个">>"的原因有两个：一是短语不一定只有一个单词，二是可以处理规则不合法的情况
	{
		if(rule.size() > 1)
			trans_map[word] = rule.substr(1);
		else
			throw runtime_error("no rule for " + word);
	}
	return trans_map;
}

//单词转换函数
const string &transfrom(const string &s, const unordered_map<string, string> &m)
{
	//将单词进行转换
	auto map_it = m.find(s);
	if(map_it == m.end())
		return s;             //该单词不需要转换，直接返回
	else
		return map_it->second;     //返回替换的短语
}

//输入两个文件，输出转换后的内容
void word_transform(ifstream &map_file, ifstream &input)
{	
	unordered_map<string, string> trans_map = buildMap(map_file);
	string text;
	while(getline(input,text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;          //每行的首单词前不需要加空格
		while(stream >> word)
		{
			if(firstword)
				firstword = false;
			else
				cout<<" ";
			cout<<transfrom(word, trans_map);
		}
		cout<<endl;
	}

	return;
}


int main()
{
	ifstream map_file("map_file"), input("input_file");
	word_transform(map_file,input);
	return 0;
}


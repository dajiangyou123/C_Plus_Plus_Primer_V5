/*
   扩展你得程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while(cin>>word)
	{
		for(auto &i : word)
			i = tolower(i);
		
		auto punct_end = remove_if(word.begin(),word.end(),::ispunct);  //去除标点符号，此处的ispunct一定加上::,或者不写using namespace std。确定使用的是cctype中的函数。
		word.erase(punct_end,word.end());      //删除后面无效的字符
		
		++word_count[word];
	}

	for(const auto &i : word_count)
		cout<<i.first<<" : "<<i.second<<endl;
	return 0;
}

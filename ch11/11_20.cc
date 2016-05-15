//使用insert实现单词计数程序
//使用下标更容易编写，阅读，代码量少，且不需考虑insert返回的pair类型。

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while(cin >> word)
	{
		auto ret = word_count.insert({word,0});
//		if(!ret.second)
			++ret.first->second;
	}

	for(const auto &i : word_count)
		cout << i.first <<" occurs " << i.second << ((i.second > 1)? " times" : " time") <<endl;

	return 0;
}

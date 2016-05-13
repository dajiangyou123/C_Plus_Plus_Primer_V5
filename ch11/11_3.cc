//编写单词计数程序

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while(cin >> word)
		++word_count[word];

	for(const auto &i : word_count)
		cout << i.first <<" occurs " << i.second << ((i.second > 1)? " times" : " time") <<endl;

	return 0;
}

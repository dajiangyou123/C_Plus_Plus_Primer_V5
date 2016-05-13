//使用list代替vector重新实现10.2.3节（第343页）中的去除重复单词的程序

#include <iostream>
#include <list>

using namespace std;

void elimDups(list<string> &words)
{
	words.sort();
	words.unique();
}


int main()
{
	list<string> words = {"a","c","a","b"};
	elimDups(words);

	for(auto i: words)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}


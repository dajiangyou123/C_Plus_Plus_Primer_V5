/*
   11.31: 定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你得程序在元素不再map中时也能正常运行。
   11.32：按字典序打印作者列表和他们的作品
*/


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> contents = {{"a","abc"},{"b","bca"},{"c","zy"},{"a","ad"},{"c","adadf"}};
	auto iter = contents.find("a");
	while(iter != contents.end() && iter != contents.upper_bound("a"))
	{
		iter = contents.erase(iter);
		/*
			contents.erase(iter);
			++iter;                //set,map等所有的关联容器的迭代器只有删除的那个会失效，其它的都不会失效
		*/
	}		

	for(auto &i : contents)
		cout<<i.first<<" : "<<i.second<<endl;

	return 0;
}

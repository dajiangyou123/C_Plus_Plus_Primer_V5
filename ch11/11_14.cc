/*
   定义一个map，关键字是家庭的姓，值是一个vector，里面存储的是pair类型的家中孩子的名和生日。
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	map<string, vector<pair<string,string>> > family;
	string familyName,firstName,birthday;
	while(cin>>familyName>>firstName>>birthday)                   //先输入姓，再输入名和生日
	{
		family[familyName].push_back(make_pair(firstName,birthday));
	}

	for(const auto &i : family)
	{
		cout<<i.first<<endl;
		for(auto &j : i.second)
			cout<<j.first<<" : "<<j.second<<endl;
	}
	return 0;
}

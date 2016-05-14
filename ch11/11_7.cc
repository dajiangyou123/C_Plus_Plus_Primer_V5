/*
   定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string,vector<string>> family;
	string familyName,firstName;
	while(cin>>familyName>>firstName)                   //先输入姓，再输入名
	{
		family[familyName].push_back(firstName);
	}

	for(const auto &i : family)
	{
		cout<<i.first<<endl;
		for(auto &j : i.second)
			cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}

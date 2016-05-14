/*
	编写程序，读入string和int的序列，将每个string和int存入一个pair中，pair保存在一个vector中。
*/

#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;


int main()
{
	vector< pair<string,int> >  vec;
	string str;
	int val;
	while(cin>>str>>val)
	{
//		vec.push_back({str,val});              //列表初始化
//		vec.push_back(make_pair(str,val));   //调用函数 
//		vec.push_back(pair<string,int>(str,val));   //显示初始化
		vec.emplace_back(str,val);             //vec的尾部创建一个新元素
	}		
	
	for(auto &i : vec)
		cout<<i.first<<" : "<<i.second<<endl;

	return 0;
}

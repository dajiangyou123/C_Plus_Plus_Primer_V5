/*
   使用find在一个int的list中查找最后一个值为0的元素
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> li = {1,1,0,3,4,0,1,3};
	auto it = find(li.crbegin(), li.crend(),0);
	cout<<distance(it,li.crend())<<endl;

	return 0;
}



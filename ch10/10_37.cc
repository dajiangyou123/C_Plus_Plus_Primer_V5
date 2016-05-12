/*
   使用find在一个int的list中查找最后一个值为0的元素
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
	auto it_begin = vec.crbegin() + 3;            //位置7
	auto it_end = vec.crbegin() + 8;            //位置2
	list<int> li;
	copy(it_begin, it_end, back_inserter(li));

	for(auto i: li)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}



/*
   使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，并将结果写到标准输出,但只打印不重复的元素，使用unique_copy。
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	istream_iterator<int> in_iter(cin),eof;
	vector<int> vec;
	ostream_iterator<int> out_iter(cout," ");
	
	copy(in_iter,eof,back_inserter(vec));
	sort(vec.begin(),vec.end());

	unique_copy(vec.begin(),vec.end(),out_iter);
	cout<<endl;

	return 0;

}

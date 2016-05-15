#include <iostream>
#include <map>

using namespace std;

//测试对于不在map中的关键字，equal_range会返回什么。返回可以插入的位置的所在的元素。
int main()
{
	map<int, int> m;
	m[1] =1;
	m[2] = 2;
	m[3] = 3;
	m[5] = 5;
	m[7] = 7;
	auto it = m.equal_range(4);
	cout << it.second->first << endl;
	return 0;
}

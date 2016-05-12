/*
   使用普通迭代器逆序打印一个vector
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	vector<int> ve = {1,2,3,4,5,6,7,8,9};

	if(ve.empty())
		exit(1);

	for(auto it = ve.end() - 1; ; --it)
	{
		cout<<*it<<" ";
		if(it == ve.begin())
			break;

	}
	cout<<endl;

	return 0;

}

/*
 * 编写函数，返回一个动态分配的int的vector。
 * 将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。
 * 再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。
*/


#include <iostream>
#include <vector>
#include <new>

//创建一个动态分配的vector，里面元素是int型
std::vector<int>* create()
{
	return new std::vector<int>();
}

//读取输入
std::vector<int>* read()
{
	std::vector<int> *store = create();
	int tmp;	
	while(std::cin>>tmp)
		store->push_back(tmp);
	
	return store;
}

//打印读取的元素
void print()
{
	std::vector<int> *out = read();
	for(auto i : *out)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	delete out;       //释放空间
	return;
}

int main()
{
	print();
	return 0;
}



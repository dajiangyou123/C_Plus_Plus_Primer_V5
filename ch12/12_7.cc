/*
 * 编写函数，返回一个动态分配的int的vector。
 * 将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。
 * 再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。
 * 使用shared_ptr.
*/


#include <iostream>
#include <vector>
#include <new>
#include <memory>

//创建一个动态分配的vector，里面元素是int型

using pointer = std::shared_ptr<std::vector<int>>;

pointer create()
{
	return std::make_shared<std::vector<int>>();
}

//读取输入
pointer read()
{
	pointer store = create();
	int tmp;	
	while(std::cin>>tmp)
		store->push_back(tmp);
	
	return store;
}

//打印读取的元素
void print()
{
	pointer out = read();
	for(auto i : *out)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	return;
}

int main()
{
	print();
	return 0;
}



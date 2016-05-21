//对unique_ptr进行拷贝或赋值操作，查看编译器出错信息


#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> p(new int(1));
	//std::unique_ptr<int> p1(p);     
	// error| call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'  
	
	std::unique_ptr<int> p2;
	//p2 = p;
	// error| object of type 'std::__1::unique_ptr<int, std::__1::default_delete<int> >' cannot be assigned because its copy assignment operator is implicitly deleted return 0;
}

#include "hasptr1.h"

using std::string;

//行为像指针的类

HasPtr& HasPtr::operator=(const HasPtr &rhs)    //拷贝赋值函数
{
	++*rhs.use;   //先递增右值，防止自我赋值，提前释放了
	if(--*use == 0)
	{
		delete ps;
		delete use;	
	}

	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr::~HasPtr()
{
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
}

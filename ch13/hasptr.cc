#include "hasptr.h"

using std::string;

//行为像值的类

HasPtr& HasPtr::operator=(HasPtr rhs)    //拷贝赋值函数
{
	swap(*this, rhs);
	return *this;
}



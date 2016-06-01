#ifndef _HASPTR_H
#define _HASPTR_H

#include <string>

//行为像值的类

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }      //构造函数
	HasPtr(const HasPtr &p): ps(new std::string(*p.ps)), i(p.i) { }     //拷贝构造函数
	HasPtr& operator=(const HasPtr);    //拷贝赋值函数
	~HasPtr() { delete ps; }     //析构函数


private:
	std::string *ps;
	int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif

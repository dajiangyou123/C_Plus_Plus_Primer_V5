#ifndef _HASPTR_H
#define _HASPTR_H

#include <string>

//行为像指针的类

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)) { }      //构造函数
	HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }     //拷贝构造函数
	HasPtr& operator=(const HasPtr &);    //拷贝赋值函数
	~HasPtr();     //析构函数

private:
	std::string *ps;
	int i;
	std::size_t *use;   //计数，用来保存有多少个对象共享ps成员
};


#endif

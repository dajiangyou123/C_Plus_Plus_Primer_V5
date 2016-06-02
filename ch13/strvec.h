#ifndef _STRVEC_H
#define _STRVEC_H

#include <string>
#include <memory>
#include <initializer_list>
#include <utility>

//实现简易的vector

class StrVec
{
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }    //默认初始化
	StrVec(const StrVec&);    //拷贝构造函数
	StrVec &operator=(const StrVec&);        //拷贝赋值运算符
	StrVec(std::initializer_list<std::string>);  //列表初始化
	~StrVec();				//析构函数
	void push_back(const std::string&);		//添加元素到StrVec中
	size_t size() const { return first_free - elements; }     //StrVec中存储的元素数量
	size_t capacity() const { return cap - elements; }        //StrVec总空间大小
	std::string *begin() const { return elements; }			 //首元素地址
	std::string *end() const { return first_free; }			 //尾后元素地址
	void reserve(size_t);    //分配至少能容纳给定参数个的内存空间
	void resize(size_t);	//调整存储的数量为给定参数


private:
	static std::allocator<std::string> alloc;   //分配元素

	void allocate_n(size_t);	//分配指定参数的空间

	//添加元素时保证空间足够
	void chk_n_alloc()
	{
		if (size() == capacity()) 
			reallocate();
	}   

	//工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);

	void free();  //销毁元素并释放内存
	void reallocate();  //重新分配更大的内存空间
	std::string *elements;   //指向数组首元素的指针
	std::string *first_free;  //指向数组第一个空闲元素的指针
	std::string *cap;		 //指向数组尾后位置的指针

};

#endif

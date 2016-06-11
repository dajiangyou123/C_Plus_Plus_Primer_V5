#include "strvec.h"
#include <iostream>

using std::string;
using std::pair;
using std::initializer_list;

std::allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	//不能传递给deallocate一个空指针，即elements为0，则函数不做任何处理   
	if(elements)
	{
		//逆序销毁旧元素
		for(auto p = first_free; p != elements; )
			alloc.destroy(--p);           //调用string的析构函数
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	//alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}


StrVec::~StrVec() 
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::allocate_n(size_t n)
{
	auto newdata = alloc.allocate(n);

	//将原来内存中的数据移动到新内存空间中
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));        //此处使用string的移动构造函数

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;   //空间不够扩大两倍，若原来空间为0，则现在空间为1
	allocate_n(newcapacity);
}

void StrVec::reserve(size_t n)
{
	if(n <= capacity())	
		return;     //空间足够

	//若不够则重新分配
	allocate_n(n);
}


void StrVec::resize(size_t n)
{
	if(n == size())
		return;   //存储数量刚好足够,不做任何处理

	if(n > size())   //存储数量过少，进行扩充
	{
		if(n <= capacity())   //原存储空间不够
		{
			allocate_n(n);
			for( ; first_free != cap ; ++first_free)
				alloc.construct(first_free, "");
		}
		else
		{
			auto len = n - size();   //还需添加的元素数量
			for(size_t i = 0; i != len; ++i)
				alloc.construct(first_free++, "");
		}
	}
	else
	{
		//存储元素过多，将多余元素丢掉
		for(auto lbegin = elements + n;	lbegin != first_free; ++lbegin )
			alloc.destroy(lbegin);
		first_free = elements + n;
	}
}

StrVec::StrVec(initializer_list<string> il): elements(nullptr), first_free(nullptr), cap(nullptr)
{
	for(const auto &s : il)
	{
		push_back(s);
	}
}


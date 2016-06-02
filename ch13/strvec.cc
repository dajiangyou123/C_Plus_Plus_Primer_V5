#include "strvec.h"

using std::string;
using std::pair;

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

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;   //空间不够扩大两倍，若原来空间为0，则现在空间为1
	auto newdata = alloc.allocate(newcapacity);

	//将原来内存中的数据移动到新内存空间中
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));        //此处使用string的移动构造函数

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}







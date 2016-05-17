//定义自己的strBlob类，包含const版本的front和back。

#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <stdexcept>


class StrBlob
{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }

		void push_back(const std::string &t) {data->push_back(t);}
		void pop_back() { data->pop_back(); }

		//读取首尾元素
		std::string& front() const;
		std::string& back() const;

	private:
		std::shared_ptr<std::vector<std::string>> data;

		//检查下标取值是否合法
		void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob():data( std::make_shared<std::vector<std::string>>() ) { }
StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)) { }


std::string& StrBlob::front() const
{
	return data->front();
}


std::string& StrBlob::back() const
{
	return data->back();
}

void StrBlob::check(size_type i, const std::string &msg) const
{
	if(i >= data->size())		//i是下标，永远不可能大于等于长度的
		throw std::out_of_range(msg);
	return;
}

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a","an","the"};
		b1 = b2;
		b2.push_back("about");

		std::cout<<b1.size()<<std::endl;
		std::cout<<b2.size()<<std::endl;
	}
	const StrBlob b3 = b1;
	std::cout<<b3.front()<<std::endl;
	return 0;
}



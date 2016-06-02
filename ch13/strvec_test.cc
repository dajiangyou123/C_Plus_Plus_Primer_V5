#include "strvec.h"
#include <iostream>

int main()
{
	StrVec vec;
	vec.push_back("abc");
	vec.push_back("efg");
	

	StrVec vec1;
	vec1.push_back("a");
	vec1.push_back("b");
	for(auto i : vec)
		std::cout << i << std::endl;
	for(auto i : vec1)
		std::cout << i << std::endl;

	return 0;
}


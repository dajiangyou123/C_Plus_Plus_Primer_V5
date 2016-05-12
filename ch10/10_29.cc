/*
   实现使用流迭代器读取一个文本，存入一个vector中的string里。
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	ifstream fileS(argv[1],ifstream::in);
	istream_iterator<string> fileIn(fileS),eof;
	vector<string> vecs;

	while(fileIn != eof)
		vecs.push_back(*fileIn++);

	for(auto i: vecs)
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}

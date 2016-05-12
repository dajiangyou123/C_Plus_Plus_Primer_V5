/*
   编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
   输入文件保存的应该是整数。使用istream_iterator读取输入文件。
   使用ostream_iterator将奇数写入第一个输出文件，每个值之后都跟一个空格.
   将偶数写入第二个输出文件，每个值都独占一行。
*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	if(argc < 4)
	{
		cout<<"usage: three file name"<<endl;
		exit(1);
	}
	
	ifstream in(argv[1]);
	ofstream out1(argv[2]),out2(argv[3]);

	istream_iterator<int> inFile(in), eof;
	ostream_iterator<int> outFile1(out1 ," "),outFile2(out2 ," ");

	while(inFile != eof)
	{
		*inFile & 1 ? outFile1 = *inFile : outFile2 = *inFile;
		inFile++;
	}


	return 0;

}

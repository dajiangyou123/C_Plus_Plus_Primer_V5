//使用vector而不是set保存不重复的单词

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


int main()
{
	vector<string> words;
	string str;
	while(cin>>str)
	{
		if( find(words.begin(),words.end(),str) == words.end() )    //查找是否已经保存该单词了
			words.push_back(str);
	}

	for(auto i : words)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}


/*
   使用vector去保存不重复的单词，每次添加单词时都需要从头到尾遍历查询一下该单词是否已经保存。而set直接插入且效率为logN。
*/

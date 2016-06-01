#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <string>
#include <set>

class Folder;
class Message
{
	friend class Folder;
public:
	explicit Message(const std::string &str = ""): contents(str) {}

	//拷贝控制成员
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	//从给定Folder集合中添加/删除该Message
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;   

	//将该Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);
	//从folders中的每个Folder中删除该Message
	void remove_from_Folders();

};



#endif


#ifndef _FOLDER_H
#define _FOLDER_H

#include <set>

class Message;
class Folder
{
	friend class Message;
public:
	Folder() = default;
	
	//拷贝控制成员
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	
private:
	std::set<Message*> msgs;
	
	//这两个函数纯粹是为了完成message中的功能的，从当前的msgs集合中添加/删除给定的Message
	void addMsg(Message *);
	void remMsg(Message *);
	
	//将msgs集合添加到的参数Folder中
	void add_to_Messages(const Folder&);
	//从msgs集合中删除该Folder
	void remove_from_Messages();
};


#endif

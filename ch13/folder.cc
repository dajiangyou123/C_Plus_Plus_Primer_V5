#include "folder.h"
#include "message.h"

void Folder::addMsg(Message *m)
{
	msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	msgs.erase(m);
}

void Folder::add_to_Messages(const Folder &f)
{
	for(auto m : f.msgs)	
		m->folders.insert(this);
}

void Folder::remove_from_Messages()
{
	for(auto m : msgs)
		m->folders.erase(this);
}

Folder::Folder(const Folder &f): msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder::~Folder()
{
	remove_from_Messages();
}

Folder& Folder::operator=(const Folder &rhs)
{
	remove_from_Messages();
	msgs = rhs.msgs;
	add_to_Messages(rhs);

	return *this;
}

int main()
{
	return 0;
}



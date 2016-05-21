//编写用shared_ptr管理connection的函数


#include <iostream>
#include <memory>

//连接的目的信息
struct destination
{
	std::string ip;
	int port;
	destination(std::string _ip,int _port):ip(_ip),port(_port){}
};

//连接的信息
struct connection
{
	std::string ip;
	int port;
	connection(std::string _ip,int _port):ip(_ip),port(_port){}
};


connection connect(destination *destAddr)
{
	std::shared_ptr<connection>  conn(new connection(destAddr->ip,destAddr->port));
	std::cout<<"create connection: "<< conn->ip << ":" << conn->port << "(" << conn.use_count() << ")" <<std::endl;
	return *conn;
}

void disconnect(connection conn)
{
	std::cout<<"connection close: "<< conn.ip << ":" << conn.port <<std::endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
	std::cout<<"connection: "<< p->ip << ":" << p->port << "(" << p.use_count() << ")" <<std::endl;
}

int main()
{
	destination d("129.168.1.1",80);
	f(d);
	return 0;
}


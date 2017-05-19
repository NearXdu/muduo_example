#ifndef __ECHOSERVER_H__
#define __ECHOSERVER_H__

#include <muduo/net/TcpServer.h>
#include <string>
#include <iostream>
using namespace std;

// RFC 862
class EchoServer
{
    public:
	EchoServer(muduo::net::EventLoop* loop,
		const muduo::net::InetAddress& listenAddr);

	void start();  // calls server_.start();

    private:
	void onConnection(const muduo::net::TcpConnectionPtr& conn);

	void onMessage(const muduo::net::TcpConnectionPtr& conn,
		muduo::net::Buffer* buf,
		muduo::Timestamp time);

	muduo::net::TcpServer server_;
	string test_;
};

#endif

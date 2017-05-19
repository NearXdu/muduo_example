# ifndef __DISCARD_H__
# define __DISCARD_H__
#include <muduo/net/TcpServer.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <boost/bind.hpp>
#include <iostream>

class DiscardServer
{
    public:
	DiscardServer(muduo::net::EventLoop*loop,
		const muduo::net::InetAddress& listenAddr);
	void start();
    private:
	void onMessage(const muduo::net::TcpConnectionPtr&conn,
		muduo::net::Buffer*buf,
		muduo::Timestamp time);
	muduo::net::TcpServer server_;
};
# endif

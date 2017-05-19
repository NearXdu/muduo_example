# ifndef __DAYTIME_H__
# define __DAYTIME_H__
#include <muduo/net/TcpServer.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <boost/bind.hpp>

class DaytimeServer
{
    public:
	DaytimeServer(muduo::net::EventLoop*loop,
		const muduo::net::InetAddress& listenAddr);
	void start();
    private:
	void onMessage(const muduo::net::TcpConnectionPtr&conn,
		muduo::net::Buffer*buf,
		muduo::Timestamp time);
	void onConnection(const muduo::net::TcpConnectionPtr&conn);
	muduo::net::TcpServer server_;
};
# endif

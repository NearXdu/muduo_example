#ifndef __TIMECLIENT_H__
#define __TIMECLIENT_H__
#include <muduo/base/Logging.h>
#include <muduo/net/Endian.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpClient.h>

#include <boost/bind.hpp>

#include <utility>

#include <stdio.h>
#include <unistd.h>
using namespace muduo;
using namespace muduo::net;
class TimeClient:boost::noncopyable
{
    public:
	TimeClient(EventLoop* loop, const InetAddress& serverAddr);
	void connect();
    private:
	EventLoop* loop_;
	TcpClient client_;

	void onConnection(const TcpConnectionPtr &conn);
	void onMessage(const TcpConnectionPtr &conn,
		Buffer *buf,
		Timestamp receiveTime);



};


#endif

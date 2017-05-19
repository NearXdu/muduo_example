#include "daytime.h"

DaytimeServer::DaytimeServer(muduo::net::EventLoop*loop,
	const muduo::net::InetAddress& listenAddr)
    :server_(loop,listenAddr,"DaytimeServer")
{
    server_.setMessageCallback(
	    boost::bind(&DaytimeServer::onMessage,this,_1,_2,_3));
    server_.setConnectionCallback(
	    boost::bind(&DaytimeServer::onConnection,this,_1));
}

void DaytimeServer::onMessage(const muduo::net::TcpConnectionPtr &conn,
	muduo::net::Buffer* buf,
	muduo::Timestamp time)
{
    muduo::string msg(buf->retrieveAllAsString());
    LOG_INFO<<conn->name()<<" daytimes "
	<< msg.size() << " bytes received at "
	<<time.toString();
    LOG_INFO<<"zx debug";
}

void DaytimeServer::onConnection(const muduo::net::TcpConnectionPtr& conn)
{
  LOG_INFO << "DaytimeServer - " << conn->peerAddress().toIpPort() << " -> "
           << conn->localAddress().toIpPort() << " is "
           << (conn->connected() ? "UP" : "DOWN");
  if (conn->connected())
  {
    conn->send(muduo::Timestamp::now().toFormattedString() + "\n");
    conn->shutdown();
  }
}


void DaytimeServer::start()
{
    server_.start();
}

#include "discard.h"


DiscardServer::DiscardServer(muduo::net::EventLoop*loop,
	const muduo::net::InetAddress& listenAddr)
    :server_(loop,listenAddr,"DiscardServer")
{
    server_.setMessageCallback(
	    boost::bind(&DiscardServer::onMessage,this,_1,_2,_3));
}

void DiscardServer::onMessage(const muduo::net::TcpConnectionPtr &conn,
	muduo::net::Buffer* buf,
	muduo::Timestamp time)
{
    muduo::string msg (buf->retrieveAllAsString());
    std::cout << "recevie: "<< msg<<std::endl;
    /*
    muduo::string msg(buf->retrieveAllAsString());
    LOG_INFO<<msg<<endl;
    LOG_INFO<<conn->name()<<" discards "
	<< msg.size() << " bytes received at "
	<<time.toString();
    LOG_INFO<<"zx debug";
    */
}

void DiscardServer::start()
{
    server_.start();
}

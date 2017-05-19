#include <muduo/base/Logging.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <iostream>
#include <string>

using namespace muduo;
using namespace muduo::net;


void onConnection(const TcpConnectionPtr &conn)
{

#if 1
    LOG_INFO << "EchoServer - " << conn->peerAddress().toIpPort() << " -> "
	<< conn->localAddress().toIpPort() << " is "
	<< (conn->connected() ? "UP" : "DOWN");
#endif
}

void onMessage(const TcpConnectionPtr &conn,
	Buffer *buf,
	Timestamp time)
{
    std::string msg(buf->peek(),buf->peek()+buf->readableBytes());   
    std::cout << msg;

#if 1
    LOG_INFO << conn->name() << " echo " << msg.size() << " bytes, "
	<< "data received at " << time.toString();
    conn->send(msg);
#endif
}

int main(int argc, const char *argv[])
{
    EventLoop loop;
    InetAddress addr("127.0.0.1", 1024);
    TcpServer server(&loop, addr,"echo");
    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.start();
    loop.loop();
    return 0;
}

#include "time.h"
int main()
{
    muduo::net::InetAddress listenAddr(1024);
    muduo::net::EventLoop loop;
    TimeServer server(&loop,listenAddr);
    server.start();
    loop.loop();
    return 0;

}

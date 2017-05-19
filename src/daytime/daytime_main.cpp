#include "daytime.h"
int main()
{
    muduo::net::InetAddress listenAddr(1024);
    muduo::net::EventLoop loop;
    DaytimeServer server(&loop,listenAddr);
    server.start();
    loop.loop();
    return 0;
}

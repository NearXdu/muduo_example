#include "discard.h"
int main()
{
    muduo::net::InetAddress listenAddr(8888);
    muduo::net::EventLoop loop;
    DiscardServer server(&loop,listenAddr);
    server.start();
    loop.loop();
    return 0;
}

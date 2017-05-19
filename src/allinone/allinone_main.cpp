#include "../daytime/daytime.h"
#include "../discard/discard.h"
#include "../echo2/echoserver.h"
#include "../time/time.h"

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

int main()
{
  LOG_INFO << "pid = " << getpid();
  EventLoop loop;  // one loop shared by multiple servers


  DaytimeServer daytimeServer(&loop, InetAddress(2013));
  daytimeServer.start();

  DiscardServer discardServer(&loop, InetAddress(2009));
  discardServer.start();

  EchoServer echoServer(&loop, InetAddress(1024));
  echoServer.start();

  TimeServer timeServer(&loop, InetAddress(2037));
  timeServer.start();

  loop.loop();
}


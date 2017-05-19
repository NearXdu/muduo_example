#include "timeclient.h"
#include <cstdlib>
int main(int argc, char* argv[])
{
  LOG_INFO << "pid = " << getpid();
  if (argc > 2)
  {
    EventLoop loop;
    InetAddress serverAddr(argv[1], static_cast<unsigned short>(atoi(argv[2])));

    TimeClient timeClient(&loop, serverAddr);
    timeClient.connect();
    loop.loop();
  }
  else
  {
    printf("Usage: %s host_ip\n", argv[0]);
  }
}


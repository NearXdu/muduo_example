#include "timeclient.h"
TimeClient::TimeClient(EventLoop* loop, const InetAddress& serverAddr)
    :loop_(loop),client_(loop,serverAddr,"TimeClient")

{
    client_.setConnectionCallback(
	    boost::bind(&TimeClient::onConnection, this, _1));
    client_.setMessageCallback(
	    boost::bind(&TimeClient::onMessage, this, _1, _2, _3));

}
void TimeClient::connect()
{
    client_.connect();
}
void TimeClient::onConnection(const TcpConnectionPtr& conn)
{
    LOG_INFO << conn->localAddress().toIpPort() << " -> "
	<< conn->peerAddress().toIpPort() << " is "
	<< (conn->connected() ? "UP" : "DOWN");

    if (!conn->connected())
    {
	loop_->quit();
    }
}

void TimeClient::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime)
{
    LOG_INFO<<"haha";
#if 0
    if (buf->readableBytes() >= sizeof(int32_t))
    {
	const void* data = buf->peek();
	int32_t be32 = *static_cast<const int32_t*>(data);
	buf->retrieve(sizeof(int32_t));
	time_t time = sockets::networkToHost32(be32);
	Timestamp ts(implicit_cast<uint64_t>(time) * Timestamp::kMicroSecondsPerSecond);
	LOG_INFO << "Server time = " << time << ", " << ts.toFormattedString();
    }
    else
    {
	LOG_INFO << conn->name() << " no enough data " << buf->readableBytes()
	    << " at " << receiveTime.toFormattedString();
    }
#endif
}


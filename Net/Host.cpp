/**
 *
 *       @file  Host.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/22/2011 14:41:40
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/Host.h>
Host::Host():
    IpAddress(None),
    m_port(0)
{
}
Host::Host(const string& host, const uint8& port):
    IpAddress(host),
    m_port(port)
{
}

Host::Host(const char* host, const uint8& port):
    IpAddress(host),
    m_port(port)
{
}

Host::Host(IpAddress::Ip host, const uint8& port):
    IpAddress(host),
    m_port(port)
{
}

sockaddr_in Host::getHost()
{
    sockaddr_in addr;
    memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
    addr.sin_addr.s_addr = htonl(IpAddress::toInt());
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(m_port);
    return addr;
}

void Host::setHost(sockaddr_in& addr)
{
    IpAddress::setIp(ntohl(addr.sin_addr.s_addr));
    m_port = ntohs(addr.sin_port);
}

Host::operator string()
{
    return this->toString();
}

string Host::toString()
{
    return IpAddress::toString() + ":" + TypeCast::toString(m_port);
}



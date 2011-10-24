/**
 *
 *       @file  IpAddress.cpp
 *
 *      @brief  Ip address class
 *
 *    @version  1.0
 *       @date  10/22/2011 13:13:07
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */


#include <Net/IpAddress.h>

IpAddress::IpAddress(const string& rhost)
{
    IpAddress(rhost.c_str());
}

IpAddress::IpAddress(const char* rhost)
{
    m_ipAddr = inet_addr(rhost);

    /* Test weather the ip was valid or not */
    if (m_ipAddr == INADDR_NONE)
    {
        struct hostent* host;
        host = gethostbyname(rhost);

        /* Host found, retrieve the address */
        if (host)
        {
            m_ipAddr = reinterpret_cast<in_addr*>(host->h_addr)->s_addr;
        }

        else
        {
            m_ipAddr = INADDR_NONE;
        }
    }
}

IpAddress::IpAddress(const uint8& byte1, const uint8& byte2, const uint8& byte3, const uint8& byte4)
{
    m_ipAddr = htonl((byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4);
}

IpAddress::IpAddress(uint32 addr)
{
    m_ipAddr = htonl(addr);
}

IpAddress::IpAddress(Ip addr){
	switch(addr){
		case Any:
			m_ipAddr = INADDR_ANY;
			break;
		case None:
			m_ipAddr = INADDR_NONE;
			break;
	}
}

void IpAddress::setIp(uint32 addr){
	m_ipAddr = htonl(addr);
}

string IpAddress::toString()
{
    in_addr addr;
    addr.s_addr = m_ipAddr;
    return inet_ntoa(addr);
}

uint32 IpAddress::toInt()
{
    return ntohl(m_ipAddr);
}

/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <Net/IpAddress.h>
#include <Net/HttpProtocol.h>

IpAddress::IpAddress(const string& rhost)
{
    IpAddress(rhost.c_str());
}

IpAddress::IpAddress(const char* rhost)
{
    m_ipAddr = inet_addr(rhost);
    in_addr addr;
    addr.s_addr = m_ipAddr;

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

IpAddress::IpAddress(Ip addr)
{
    switch (addr)
    {
        case Any:
            m_ipAddr = INADDR_ANY;
            break;

        case None:
            m_ipAddr = INADDR_NONE;
            break;
    }
}

void IpAddress::setIp(uint32 addr)
{
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

IpAddress IpAddress::getPublicIpAddress()
{
    Host h("checkip.dyndns.org", 80);
    HttpProtocol proto(h);
    HttpRequest req("/", HttpRequest::Head);

    if (proto.sendRequest(req) < 0)
        return IpAddress(None);

    HttpResponse r = proto.getResponse();
    r.parse();

    if (r.getResponseCode() < 200)
        return IpAddress(None);

    HtmlParser parser(r.getBody());

    if (parser.parse() < 0)
        return IpAddress(None);

    string address = parser.getRootElement()["html"]["body"].getContents();
    address = address.substr(address.find(':') + 2);
    return IpAddress(address.c_str());
}

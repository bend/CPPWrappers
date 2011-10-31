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

#include <Net/Host.h>
Host::Host():
    IpAddress(None),
    m_port(0)
{
}

Host::Host(const string& host, const uint16& port):
    IpAddress(host),
    m_port(port)
{
}

Host::Host(const char* host, const uint16& port):
    IpAddress(host),
    m_port(port)
{
}

Host::Host(IpAddress::Ip host, const uint16& port):
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



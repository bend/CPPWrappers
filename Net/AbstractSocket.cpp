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

#include <Net/AbstractSocket.h>

AbstractSocket::AbstractSocket():
    m_socketfd(-1),
    m_isBlocking(true)
{
}

AbstractSocket::AbstractSocket(int socket):
    m_socketfd(socket),
    m_isBlocking(true)
{
}

uint8 AbstractSocket::getLocalPort() const
{
    if (m_socketfd != -1)
    {
        sockaddr_in address;
        socklen_t size = sizeof(address);

        if (getsockname(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1)
        {
            return ntohs(address.sin_port);
        }
    }

    return 0;
}

uint8 AbstractSocket::getRemotePort() const
{
    if (m_socketfd != -1)
    {
        sockaddr_in address;
        socklen_t size = sizeof(address);

        if (getpeername(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1)
        {
            return ntohs(address.sin_port);
        }
    }

    return 0;
}

IpAddress AbstractSocket::getRemoteAddress()
{
    if (m_socketfd != -1)
    {
        sockaddr_in address;
        socklen_t size = sizeof(address);

        if (getpeername(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1)
        {
            return IpAddress(ntohl(address.sin_addr.s_addr));
        }
    }

    return IpAddress::None;
}


void AbstractSocket::setBlocking(bool b)
{
    int status = fcntl(m_socketfd, F_GETFL);

    if (b)
        fcntl(m_socketfd, F_SETFL, status & ~O_NONBLOCK);

    else
        fcntl(m_socketfd, F_SETFL, status | O_NONBLOCK);

    m_isBlocking = b;
}

bool AbstractSocket::isBlocking()
{
    return m_isBlocking;
}

AbstractSocket::Status AbstractSocket::getSocketStatus()
{
    if ((errno == EAGAIN) || (errno == EINPROGRESS))
        return AbstractSocket::NotReady;

    switch (errno)
    {
        case EWOULDBLOCK :
            return AbstractSocket::NotReady;

        case ECONNABORTED :
            return AbstractSocket::Disconnected;

        case ECONNRESET :
            return AbstractSocket::Disconnected;

        case ETIMEDOUT :
            return AbstractSocket::Disconnected;

        case ENETRESET :
            return AbstractSocket::Disconnected;

        case ENOTCONN :
            return AbstractSocket::Disconnected;

        default :
            return AbstractSocket::Error;
    };
}

void AbstractSocket::close()
{
    ::close(m_socketfd);
}

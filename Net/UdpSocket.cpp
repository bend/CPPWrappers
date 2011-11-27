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

#include <Net/UdpSocket.h>

UdpSocket::UdpSocket()
{
}

AbstractSocket::Status UdpSocket::bind(const uint16& port)
{
    struct sockaddr_in addr;

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    addr = Host(Ipv4Address::Any, port).getHost();

    if (::bind(m_socketfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

void UdpSocket::unbind()
{
    close();
}

AbstractSocket::Status UdpSocket::sendInt8(const int8& c, Host& h)
{
    struct sockaddr_in peer;

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();

    if (sendto(m_socketfd, &c, sizeof(char), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendInt16(const int16& i, Host& h)
{
    struct sockaddr_in peer;
    int16 toSend = htons(i);

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();

    if (sendto(m_socketfd, &toSend, sizeof(int16), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendInt32(const int32& i, Host& h)
{
    struct sockaddr_in peer;
    int32 toSend = htonl(i);

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();

    if (sendto(m_socketfd, &toSend, sizeof(int32), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendString(const string& str, Host& h)
{
    struct sockaddr_in peer;
    const char* data = str.c_str();

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();

    if (sendto(m_socketfd, data, str.length(), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendCharArray(const char* str, const size_t& s, Host& h)
{
    struct sockaddr_in peer;

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();

    if (sendto(m_socketfd, str, s, 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer)) == -1)
        return getStatus();

    return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendFrame(Frame& f, Host& h)
{
    struct sockaddr_in peer;

    if (m_socketfd == -1)
        if ((m_socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
            return getStatus();

    peer = h.getHost();
    uint32 size = f.getSize();

    if (size  > MaxDatagramSize)
        return UdpDatagramTooBig;

    int r =  sendto(m_socketfd, f.getData(), size, 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer));

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status UdpSocket::receiveInt8(int8& c, Host& peer)
{
    char buffer;
    struct sockaddr_in from;
    int dataRead;
    int len = sizeof(from);

    if ((dataRead = recvfrom(m_socketfd, &buffer, sizeof(c), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    peer.setHost(from);
    c = buffer;
    return Done;
}

AbstractSocket::Status UdpSocket::receiveInt16(int16& i, Host& peer)
{
    int16 buffer;
    struct sockaddr_in from;
    int dataRead;
    int len = sizeof(from);

    if ((dataRead = recvfrom(m_socketfd, &buffer, sizeof(int16), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    peer.setHost(from);
    i = ntohs(buffer);
    return Done;
}

AbstractSocket::Status UdpSocket::receiveInt32(int32& i, Host& peer)
{
    int32 buffer;
    struct sockaddr_in from;
    int dataRead;
    int len = sizeof(from);

    if ((dataRead = recvfrom(m_socketfd, &buffer, sizeof(int32), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    peer.setHost(from);
    i = ntohl(buffer);
    return Done;
}

AbstractSocket::Status UdpSocket::receiveCharArray(char** str, Host& peer)
{
    *str = new char[MaxDatagramSize];
    struct sockaddr_in from;
    int dataRead;
    int len = sizeof(from);

    if ((dataRead = recvfrom(m_socketfd, *str, MaxDatagramSize, 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    peer.setHost(from);
    return Done;
}

AbstractSocket::Status UdpSocket::receiveString(string& str, Host& peer)
{
    char* buffer = new char[MaxDatagramSize];
    struct sockaddr_in from;
    int dataRead;
    int len = sizeof(from);

    if ((dataRead = recvfrom(m_socketfd, buffer, MaxDatagramSize, 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    peer.setHost(from);
    str.assign(buffer, dataRead);
    return Done;
}

AbstractSocket::Status UdpSocket::receiveFrame(Frame& f, Host& peer)
{
    uint32 size;
    struct sockaddr_in from;
    uint32 dataRead;
    int len = sizeof(from);
    char* buffer;
    buffer = new char[MaxDatagramSize];

    if ((dataRead = recvfrom(m_socketfd, buffer, MaxDatagramSize, 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len))) == -1)
        return getStatus();

    f.setData(buffer, dataRead);
    peer.setHost(from);
    return Done;
}

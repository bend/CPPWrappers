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

#include <Net/TcpSocket.h>

TcpSocket::TcpSocket()
{
    m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socketfd): AbstractSocket(socketfd)
{
}


AbstractSocket::Status TcpSocket::connect(const string& host, const uint16& port)
{
    m_portNo = (int)port;

    if (m_socketfd < 0)
        return EOPEN;

    m_server = gethostbyname(host.c_str());

    if (m_server == NULL)
    {
        return EHOST;
    }

    bzero((char*) &m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    bcopy((char*)m_server->h_addr, (char*)&m_servAddr.sin_addr.s_addr, m_server->h_length);
    m_servAddr.sin_port = htons(m_portNo);

    /* Connect to the host */
    if (::connect(m_socketfd, (struct sockaddr*) &m_servAddr, sizeof(m_servAddr)) < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::connect(Host& h)
{
    sockaddr_in s = h.getHost();

    if (::connect(m_socketfd, (struct sockaddr*) &s, sizeof(s)) < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendString(const string& str)
{
    int s = (int) strlen(str.c_str());
    /* Send the string */
    int r = send(m_socketfd, str.c_str(), s, 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendInt64(const int64& i)
{
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendInt32(const int32& i)
{
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendInt16(const int16& i)
{
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendInt8(const int8& c)
{
    int r = send(m_socketfd, &c, sizeof(c), 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendCharArray(const char* c, const size_t& s)
{
    int r = send(m_socketfd, c, s, 0);

    if (r < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveString(string& str, const size_t& s)
{
    char* buffer;
    buffer = new char[s];

    if (buffer == NULL)
        return EMEM;

    bzero(buffer, s);
    int n = read(m_socketfd, buffer, s);

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    str.assign(buffer, s);
    delete[] buffer;
    return Done;
}

AbstractSocket::Status TcpSocket::receiveInt64(int64& i)
{
    int n = read(m_socketfd, &i, sizeof(int64));

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveInt32(int32& i)
{
    int n = read(m_socketfd, &i, sizeof(int32));

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveInt16(int16& s)
{
    int n = read(m_socketfd, &s, sizeof(int16));

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveInt8(int8& c)
{
    int n = read(m_socketfd, &c, sizeof(int8));

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveCharArray(char** c, const size_t& s)
{
    *c = new char[s];

    if ((*c) == NULL)
        return EMEM;

    bzero(*c, s);
    int n = read(m_socketfd, *c, s);

    if (n == 0)
        return Disconnected;

    if (n < 0)
        return getStatus();

    return Done;
}

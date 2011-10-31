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

#include <Net/TcpServer.h>

TcpServer::TcpServer(int maxWaitingCon):
    m_maxWaitCon(maxWaitingCon)
{
    m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
}

AbstractSocket::Status TcpServer::bind(int port)
{
    m_portNo = (int) port;

    if (m_socketfd < 0)
        return EOPEN;

    bzero((char*) &m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    m_servAddr.sin_addr.s_addr = INADDR_ANY;
    m_servAddr.sin_port = htons(m_portNo);

    if (::bind(m_socketfd, (struct sockaddr*) &m_servAddr, sizeof(m_servAddr)) < 0)
        return getStatus();
	m_status = Done;
    return Done;
}

AbstractSocket::Status TcpServer::listen(int port)
{
    if (bind(port) != Done)
        return getStatus();

    if (::listen(m_socketfd, m_maxWaitCon) < 0)
        return getStatus();

    return Done;
}

TcpSocket* TcpServer::accept()
{
    socklen_t cliLen;
    int newSockfd;
    cliLen = sizeof(m_cliAddr);
    newSockfd = ::accept(m_socketfd, (struct sockaddr*) &m_cliAddr, &cliLen);

    if (newSockfd < 0)
        return NULL;

    return new TcpSocket(newSockfd);
}


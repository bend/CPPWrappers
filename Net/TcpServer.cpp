/**
 *
 *       @file  TcpServer.cpp
 *
 *      @brief  Tcp server
 *
 *    @version  1.0
 *       @date  10/10/2011 18:18:30
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/TcpServer.h>

TcpServer::TcpServer(int maxWaitingCon):
    m_maxWaitCon(maxWaitingCon) {
    m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
}

int TcpServer::bind(int port) {
    m_portNo = (int) port;

    if(m_socketfd < 0)
        return SocketErrors::SOCOPEN;

    bzero((char *) &m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    m_servAddr.sin_addr.s_addr = INADDR_ANY;
    m_servAddr.sin_port = htons(m_portNo);

    if (::bind(m_socketfd, (struct sockaddr *) &m_servAddr, sizeof(m_servAddr)) < 0)
        return SocketErrors::SOEBIND;

    return SocketErrors::SOSUCC;
}

int TcpServer::listen(int port) {
    if (bind(port) < 0)
        return SocketErrors::SOEBIND;

    if(::listen(m_socketfd, m_maxWaitCon) < 0)
        return SocketErrors::SOELIST;

    return SocketErrors::SOSUCC;
}

TcpSocket* TcpServer::accept() {
    socklen_t cliLen;
    int newSockfd;
    cliLen = sizeof(m_cliAddr);
    newSockfd = ::accept(m_socketfd, (struct sockaddr *) &m_cliAddr, &cliLen);

    if (newSockfd < 0)
        return NULL;

    return new TcpSocket(newSockfd);
}

int TcpServer::close() {
    if(::close(m_socketfd) < 0)
        return SocketErrors::SOCLO;

    return SocketErrors::SOSUCC;
}

/**
 *
 *       @file  TcpSocket.cpp
 *
 *      @brief  C++ wrapper for the socket library
 *
 *    @version  1.0
 *       @date  10/10/2011 14:46:18
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Socket/TcpSocket.h>

TcpSocket::TcpSocket() {
    m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socketfd):
    m_socketfd(socketfd) {
}

int TcpSocket::connect(string host, unsigned short port) {
    m_portNo = (int)port;

    if (m_socketfd < 0)
        return SOCOPEN;

    m_server = gethostbyname(host.c_str());

    if (m_server == NULL) {
        return SONHOST;
    }

    bzero((char *) &m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    bcopy((char *)m_server->h_addr, (char *)&m_servAddr.sin_addr.s_addr, m_server->h_length);
    m_servAddr.sin_port = htons(m_portNo);

    /* Connect to the host */
    if (::connect(m_socketfd, (struct sockaddr *) &m_servAddr, sizeof(m_servAddr)) < 0)
        return SOCONN;

    return SOSUCC;
}

int TcpSocket::disconnect() {
    if(::close(m_socketfd) < 0)
        return SOCLO;

    return SOSUCC;
}

int TcpSocket::sendString(string &str) {
    /* Send the string size */
    int s = (int) strlen(str.c_str());

    if(sendInt(s) < 0)
        return SOEWRITE;

    /* Send the string */
    int r = send(m_socketfd, str.c_str(), s, 0);

    if(r < 0)
        return SOEWRITE;

    return SOSUCC;
}

int TcpSocket::sendInt(int &i) {
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if(r < 0)
        return SOEWRITE;

    return SOSUCC;
}

int TcpSocket::sendShort(short &i) {
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if(r < 0)
        return SOEWRITE;

    return SOSUCC;
}

int TcpSocket::sendChar(char &c) {
    int r = send(m_socketfd, &c, sizeof(c), 0);

    if(r < 0)
        return SOEWRITE;

    return SOSUCC;
}

int TcpSocket::sendCharArray(char* c) {
    /* Send the string size */
    int s = (int) strlen(c);

    if(sendInt(s) < 0)
        return SOEWRITE;

    int r = send(m_socketfd, c, s, 0);

    if(r < 0)
        return SOEWRITE;

    return SOSUCC;
}

int TcpSocket::receiveString(string &str) {
    char* buffer;
    int s = 0;

    if(receiveInt(s) < 0)
        return SOEREAD;

  //   buffer = (char*)malloc(sizeof(char) * s);
  	buffer = new char[s];

    if(buffer == NULL)
        return SOEMEM;

    bzero(buffer, s);
    int n = read(m_socketfd, buffer, s);

    if(n < 0)
        return SOEREAD;

    str.assign(buffer, s);
    delete[] buffer;
    return SOSUCC;
}

int TcpSocket::receiveInt(int &i) {
    int n = read(m_socketfd, &i, sizeof(int));

    if(n < 0)
        return SOEREAD;

    return SOSUCC;
}

int TcpSocket::receiveShort(short& s) {
    int n = read(m_socketfd, &s, sizeof(short));

    if(n < 0)
        return SOEREAD;

    return SOSUCC;
}

int TcpSocket::receiveChar(char &c) {
    int n = read(m_socketfd, &c, sizeof(char));

    if(n < 0)
        return SOEREAD;

    return SOSUCC;
}

int TcpSocket::receiveCharArray(char **c) {
    int s = 0;

    if(receiveInt(s) < 0)
        return SOEREAD;

    *c = (char*)malloc(sizeof(char) * s);

    if((*c) == NULL)
        return SOEMEM;

    bzero(*c, s);
    int n = read(m_socketfd, *c, s);

    if(n < 0)
        return SOEREAD;

    return SOSUCC;
}

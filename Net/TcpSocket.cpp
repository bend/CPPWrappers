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

#include <Net/TcpSocket.h>

TcpSocket::TcpSocket() {
	m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socketfd):AbstractSocket(socketfd) {
}


AbstractSocket::Status TcpSocket::connect(string host, unsigned short port) {
	m_portNo = (int)port;

	if (m_socketfd < 0)
        return EOPEN;

    m_server = gethostbyname(host.c_str());

    if (m_server == NULL) {
        return EHOST;
    }

    bzero((char *) &m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    bcopy((char *)m_server->h_addr, (char *)&m_servAddr.sin_addr.s_addr, m_server->h_length);
    m_servAddr.sin_port = htons(m_portNo);

    /* Connect to the host */
    if (::connect(m_socketfd, (struct sockaddr *) &m_servAddr, sizeof(m_servAddr)) < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::connect(Host& h){
	sockaddr_in s = h.getHost();
    if (::connect(m_socketfd, (struct sockaddr *) &s, sizeof(s)) < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendString(const string &str) {
    /* Send the string size */
    int s = (int) strlen(str.c_str());

    if(sendInt(s) < 0)
        return getSocketStatus();

    /* Send the string */
    int r = send(m_socketfd, str.c_str(), s, 0);

    if(r < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendInt(const int &i) {
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if(r < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendShort(const short &i) {
    int r = send(m_socketfd, &i, sizeof(i), 0);

    if(r < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendChar(const char &c) {
    int r = send(m_socketfd, &c, sizeof(c), 0);

    if(r < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::sendCharArray(const char* c) {
    /* Send the string size */
    int s = (int) strlen(c);

    if(sendInt(s) < 0)
        return getSocketStatus();

    int r = send(m_socketfd, c, s, 0);

    if(r < 0)
        return getSocketStatus();

	return Done;
}

AbstractSocket::Status TcpSocket::receiveString(string &str) {
    char* buffer;
    int s = 0;

    if(receiveInt(s) < 0)
        return getSocketStatus();

    buffer = new char[s];

    if(buffer == NULL)
        return EMEM;

    bzero(buffer, s);
    int n = read(m_socketfd, buffer, s);

    if(n < 0)
        return getSocketStatus();

    str.assign(buffer, s);
    delete[] buffer;
    return Done;
}

AbstractSocket::Status TcpSocket::receiveInt(int &i) {
    int n = read(m_socketfd, &i, sizeof(int));

    if(n < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveShort(short& s) {
    int n = read(m_socketfd, &s, sizeof(short));

    if(n < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveChar(char &c) {
    int n = read(m_socketfd, &c, sizeof(char));

    if(n < 0)
        return getSocketStatus();

    return Done;
}

AbstractSocket::Status TcpSocket::receiveCharArray(char **c) {
    int s = 0;

    if(receiveInt(s) < 0)
        return getSocketStatus();

    *c = (char*)malloc(sizeof(char) * s);

    if((*c) == NULL)
        return EMEM;

    bzero(*c, s);
    int n = read(m_socketfd, *c, s);

    if(n < 0)
        return getSocketStatus();

    return Done;
}

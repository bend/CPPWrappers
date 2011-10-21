/**
 *
 *       @file  TcpSocket.h
 *
 *      @brief  C++ wrapper for the socket library
 *
 *    @version  1.0
 *       @date  10/10/2011 14:47:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef TCP_SOCKET_H__
#define TCP_SOCKET_H__

#include <Net/AbstractSocket.h>

class TcpSocket:public AbstractSocket {
public:
    /**
     * @brief default constructor
     */
    TcpSocket();

    TcpSocket(int socketfd);
	
    /**
     * @brief connects to the host on port
     * @param host : the host
     * @param the port
     * @return SOSUCC if succeded
     * 		   SOCOPEN if socket could not be opened
     * 		   SONHOST if host not found
     * 		   SOCONN if could not connect to host
     *
     */
	AbstractSocket::Status connect(string host, unsigned short port);

    /**
     * @brief sends a string over the net
     * @return 0 if successful
     */
	AbstractSocket::Status sendString(const string &str);

    /**
     * @brief sends an int over the net
     * @return 0 if successful
     */
	AbstractSocket::Status sendInt(const int &i);

    /**
     * @brief sends a short over the net
     * @return 0 if successful
     */
	AbstractSocket::Status sendShort(const short &i);

    /**
     * @brief sends a char over the net
     * @return 0 if successful
     */
	AbstractSocket::Status sendChar(const char &c);

    /**
     * @brief sends a char array over the net
     * @return 0 if successful
     */
	AbstractSocket::Status sendCharArray(const char* c);

    AbstractSocket::Status receiveString(string &str);

    AbstractSocket::Status receiveInt(int &i);

    AbstractSocket::Status receiveShort(short& s);

    AbstractSocket::Status receiveChar(char &c);

    AbstractSocket::Status receiveCharArray(char **c);

private:
    int m_portNo;
    struct sockaddr_in m_servAddr;
    struct hostent *m_server;

};

#endif

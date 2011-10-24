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
#include <Net/Host.h>

class TcpSocket: public AbstractSocket
{
    public:
        /**
         * @brief default constructor
         */
        TcpSocket();

        TcpSocket(int socketfd);

        /**
         * @brief connects to the host on port
         * @param host the host
         * @param port the port
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status connect(string host, uint8 port);

        /**
         * @brief connects the host
         * @param h a Host object containing the host and port
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status connect(Host& h);

        /**
         * @brief sends a string over the net
		 * @param str the string to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendString(const string& str);

        /**
         * @brief sends an int over the net
		 * @param i the int to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendInt(const int32& i);

        /**
         * @brief sends a short over the net
		 * @param i the short to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendShort(const int8& i);

        /**
         * @brief sends a char over the net
		 * @param c the char to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendChar(const char& c);

        /**
         * @brief sends a char array over the net
		 * @param c the char* tpo send
		 * @param s the size of the char*
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendCharArray(const char* c, const size_t &s);

        /**
         * @brief reads a string on the socket
         * @param str the string container in which the result will be put
		 * @param s the size of the string to receive
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveString(string& str, const size_t &s);

        /**
         * @brief reads an int on the socket
         * @param i the int container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveInt(int32& i);

        /**
         * @brief reads a short on the socket
         * @param s the short container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveShort(int8& s);

        /**
         * @brief reads a char on the socket
         * @param c the char container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveChar(char& c);

        /**
         * @brief reads a char*  on the socket
         * @param c a char** not initialized in which the result will be put
		 * @param s the size of the char to receive
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveCharArray(char** c, const size_t &s);

    private:
        int m_portNo;
        struct sockaddr_in m_servAddr;
        struct hostent* m_server;

};

#endif

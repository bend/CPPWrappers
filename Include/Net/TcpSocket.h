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

#ifndef TCP_SOCKET_H__
#define TCP_SOCKET_H__

#include <Net/AbstractSocket.h>
#include <Net/Host.h>
#include <Net/Frame.h>

/**
 * @brief TcpSocket class for establishing a Tcp connection with a TcpServer
 */
class TcpSocket: public AbstractSocket
{
    public:
        /**
         * @brief default constructor
         */
        TcpSocket();

        /**
         * @brief constructor
         * @param socketfd the socket file descriptor
         */
        TcpSocket(int socketfd);

        /**
         * @brief connects to the host on port
         * @param host the host
         * @param port the port
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status connect(const string& host, const uint16& port);

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
         * @brief sends a char over the net
         * @param c the char to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendInt8(const int8& c);

        /**
         * @brief sends a short over the net
         * @param i the short to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendInt16(const int16& i);

        /**
         * @brief sends an int32 over the net
         * @param i the int to send
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendInt32(const int32& i);

        /**
         * @brief sends a char array over the net
         * @param c the char* tpo send
         * @param s the size of the char*
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendCharArray(const char* c, const size_t& s);

        /**
         * @brief sends a Frame over the network
         * @param f the frame to send
         * @return AbstractSocket::Status
         */
        AbstractSocket::Status sendFrame(Frame& f);

        /**
         * @brief reads a string on the socket
         * @param str the string container in which the result will be put
         * @param s the size of the string to receive
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveString(string& str, const size_t& s);

        /**
         * @brief reads a char on the socket
         * @param c the char container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveInt8(int8& c);

        /**
         * @brief reads a short on the socket
         * @param s the short container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveInt16(int16& s);

        /**
         * @brief reads an int on the socket
         * @param i the int container in which the result will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveInt32(int32& i);

        /**
         * @brief reads a char*  on the socket
         * @param c a char** not initialized in which the result will be put
         * @param s the size of the char to receive
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveCharArray(char** c, const size_t& s);

        /**
         * @brief reads a frame from the network
         * @param f the frame where the data will be stored
         * @return AbstractSocket::Status
         */
        AbstractSocket::Status receiveFrame(Frame& f);

    private:
        int m_portNo;
        struct sockaddr_in m_servAddr;
        struct hostent* m_server;

};

#endif

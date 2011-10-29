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

#ifndef UDP_SOCKET_H__
#define UDP_SOCKET_H__
#include <Net/AbstractSocket.h>

class UdpSocket: public AbstractSocket
{
    public:
        /**
         * @brief Constants enum
         */
        enum
        {
            /** Max size of a datagram **/
            MaxDatagramSize = 65507
        };

        /**
         * @brief Constructor
         */
        UdpSocket();

        /**
         * @brief bind the socket to be able to read from it
         * @param port the port on which the socket must listen
         * @return AbstractSocket::Done is success
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status bind(const uint8& port);

        /**
         * @brief unbind the socket
         */
        void unbind();

        /**
         * @brief send a char on the socket to the host
         * @param c the char to send
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendChar(const char& c, Host& h);

        /**
         * @brief send a string on the socket to the host
         * @param str the string to send
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendString(const string& str, Host& h);

        /**
         * @brief send a char* on the socket to the host
         * @param str the char* to send
         * @param s the size of the char
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendCharArray(const char* str, const size_t& s,  Host& h);

        /**
         * @brief send an short on the socket to the host
         * @param i the int to send
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendShort(const int8& i, Host& h);

        /**
         * @brief send a int32 on the socket to the host
         * @param i the int32 to send
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendInt(const int32& i, Host& h);

        /**
         * @brief send a long on the socket to the host
         * @param i the int to send
         * @param h the Host
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status sendLong(const int64& i, Host& h);

        /**
         * @brief receive a char
         * 	You need to bind the socket to be able to receive data
         * @param c the char in which the read value will be put
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveChar(char& c, Host& peer);

        /**
         * @brief receive a string
         * 	You need to bind the socket to be able to receive data
         * @param str the string in which the read value will be put
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveString(string& str, Host& peer);

        /**
         * @brief receive a char*
         * 	You need to bind the socket to be able to receive data
         * @param c the char** in which the read value will be put. This char** must NOT be initialized,
         * oterwise it might lead to memory leaks.
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveCharArray(char** c, Host& peer);

        /**
         * @brief receive a short
         * 	You need to bind the socket to be able to receive data
         * @param i the char in which the read value will be put
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveShort(int8& i, Host& peer);

        /**
         * @brief receive a int
         * 	You need to bind the socket to be able to receive data
         * @param i the char in which the read value will be put
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveInt(int32& i, Host& peer);

        /**
         * @brief receive a long
         * 	You need to bind the socket to be able to receive data
         * @param i the char in which the read value will be put
         * @param peer the Host object in which the peer information will be put
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status receiveLong(int64& i, Host& peer);

};

#endif

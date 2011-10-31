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

#ifndef ABSTRACT_SOCKET_H__
#define ABSTRACT_SOCKET_H__

#include <System/Types.h>
#include <Net/Host.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include <iostream>
using namespace std;

class AbstractSocket
{
    public:
        /**
         * @brief Status of the socket
         */
        enum Status
        {
            /** No socket errors **/
            Done,
            /** Socket not ready **/
            NotReady,
            /** Socket disconnected **/
            Disconnected,
            /** Socket error **/
            Error,
            /** Could not open Socket descriptor **/
            EOPEN,
            /** Could not find host **/
            EHOST,
            /** Could not allocate memory **/
            EMEM,
            /** Http Request invalid **/
            InvalidRequest
        };

        /**
         * @brief Empry Constructor. This class must be inherited
         */
        AbstractSocket();

        /**
         * @brief Constructor. This class must be inherited
         * @param socket the Socket descriptor
         */
        AbstractSocket(int socket);

        /**
         * @brief gets the local port
         * @return the port >0 is found, 0 if the port could not be determined
         */
        uint16 getLocalPort() const;

        /**
         * @brief gets the remote port
         * @return the port >0 is found, 0 if the port could not be determined
         */
        uint16 getRemotePort() const;

        /**
         * @brief get the remote address
         * @return an IpAddress object is the ip could be determined
         *     	   IpAddress::None if no ip address determined
         */
        IpAddress getRemoteAddress();

        /**
         * @brief sets the blocking state of the socket
         * @param b a boolean
         */
        void setBlocking(bool b);

        /**
         * @brief get the blocking socket state
         * @return true is blocking, false otherwise
         */
        bool isBlocking();

        /**
         * @brief get the socket status
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status getStatus();

        /**
         * @brief disconnects from the host
         */
        void close();


    protected:
        /**
         * @brief socket file descriptor
         */
        int m_socketfd;

        Status m_status;

    private:
        bool m_isBlocking;
};

#endif

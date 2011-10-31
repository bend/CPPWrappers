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

#ifndef TCP_SERVER_H__
#define TCP_SERVER_H__

#include <Net/TcpSocket.h>

/**
 * @brief TcpServer. Waits for incomming TCP connection on a specified port
 */
class TcpServer: public AbstractSocket
{
    public:
        /**
         * @brief constructor
         * @param maxWaitingCon the number of queued connection that the server can handle, if this number is reached, the server will refuse connections
         */
        TcpServer(int maxWaitingCon = 5);

        /**
         * @brief listen for incomming connection
         * @param port the port on which the server will listen for inconming connections
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status listen(int port);

        /**
         * @brief accepts a connection and returns the socket
         * of the newly connected client
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        TcpSocket* accept();


    private:
        /* methods */
        AbstractSocket::Status bind(int port);

        /* variables */
        int m_socketfd;
        int m_portNo;
        int m_maxWaitCon;
        struct sockaddr_in m_servAddr;
        struct sockaddr_in m_cliAddr;
        struct hostent* m_server;
};

#endif

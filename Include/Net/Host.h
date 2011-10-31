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

#ifndef HOST_H__
#define HOST_H__

#include <Net/IpAddress.h>
#include <System/TypeCast.h>

#include <string.h>

/**
 * @brief Represents a Network host. Contains the IpAddress and the port
 */
class Host: public IpAddress
{
    public:
        /**
         * @brief empty Constructor.
         * Sets the port to O and the Ip the IpAddress::None
         */
        Host();
        /**
         * @brief Constructor
         * @param host the host name
         * @param port the port number
         */
        Host(const string& host, const uint16& port);

        /**
         * @brief Constructor
         * @param host the host name
         * @param port the port number
         */
        Host(const char* host, const uint16& port);

        /**
         * @brief Constructor
         * @param host the IpAddress::Ip
         * @param port the port number
         */
        Host(IpAddress::Ip host, const uint16& port);

        /**
         * @brief returns the host struct
         * @return the sockaddr_in struct containing the host and port
         */
        sockaddr_in getHost();

        /**
         * @brief sets the host (ip and port)
         * @param addr the sockaddr_in structure
         */
        void setHost(sockaddr_in& addr);

        /**
         * @brief cast operator redefinition
         */
        operator string();

        /**
         * @brief returns a string representation of the Host object
         * It will return a string of this form xxx.xxx.xxx.xxx:yyy
         * Where xxx are the bytes of the ip and yyy is the port
         * @return the string
         */
        string toString();

    private:
        uint16 m_port;




};

#endif

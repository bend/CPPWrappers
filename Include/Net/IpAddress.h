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

#ifndef IP_ADDRESS_H__
#define IP_ADDRESS_H__

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <stdlib.h>

#include <System/Types.h>
#include <Net/HtmlParser.h>
using namespace std;
class HttpProtocol;
class IpAddress
{
    public:
        /**
         * @brief Ip enum containing ip state
         */
        enum Ip
        {
            /** Any Ip **/
            Any,
            /** No ip determined **/
            None
        };

        /**
         * @brief Constructor
         * @param host the host name or ip
         */
        IpAddress(const string& host);

        /**
         * @brief Constructor
         * @param host the host name or ip
         */
        IpAddress(const char* host);

        /**
         * @brief Constructor
         * @param byte1 the first byte of the ip address (xxx.xxx.xxx.xxx)
         * @param byte2 the second byte
         * @param byte3 the third byte
         * @param byte4 the fourth byte
         */
        IpAddress(const  uint8& byte1, const uint8& byte2, const uint8& byte3, const uint8& byte4);

        /**
         * @brief Constructor
         * @param addr the ip address
         */
        IpAddress(uint32 addr);

        /**
         * @brief Constructor
         * @param addr the Ip
         * @see IpAddress::Ip
         */
        IpAddress(Ip addr);

        /**
         * @brief sets the ip address
         * @param addr a unit32 representing the ip
         */
        void setIp(uint32 addr);

        /**
         * @brief get the string representation of the ip
         * @return the string representation
         */
        string toString();

        /**
         * @brief gets the integer representation of the ip
         * @return the integer reprensentation
         */
        uint32 toInt();

        /**
         * @brief Retrives your Public ip address.
         * This use the internet and request your ip at checkip.dyndns.org
         * @return the IpAddress object if success , IpAddress(None) if failure
         */
        static IpAddress getPublicIpAddress();

    private:
        in_addr_t m_ipAddr;


};

#endif

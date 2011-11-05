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

#ifndef IPV4_ADDRESS_H__
#define IPV4_ADDRESS_H__

#include <System/Types.h>
#include <Parser/HtmlParser.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
class HttpProtocol;

/**
 * @brief Represents an ip address
 */
class Ipv4Address
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
        Ipv4Address(const string& host);

        /**
         * @brief Constructor
         * @param host the host name or ip
         */
        Ipv4Address(const char* host);

        /**
         * @brief Constructor
         * @param byte1 the first byte of the ip address (xxx.xxx.xxx.xxx)
         * @param byte2 the second byte
         * @param byte3 the third byte
         * @param byte4 the fourth byte
         */
        Ipv4Address(const  uint8& byte1, const uint8& byte2, const uint8& byte3, const uint8& byte4);

        /**
         * @brief Constructor
         * @param addr the ip address
         */
        Ipv4Address(uint32 addr);

        /**
         * @brief Constructor
         * @param addr the Ip
         * @see Ipv4Address::Ip
         */
        Ipv4Address(Ip addr);

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
         * @return the Ipv4Address object if success , Ipv4Address(None) if failure
         */
        static Ipv4Address getPublicIpAddress();

    private:
        in_addr_t m_ipAddr;


};

#endif

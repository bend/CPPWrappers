/**
 *
 *       @file  Host.h
 *
 *      @brief  Host class represents a host (ip + port)
 *
 *    @version  1.0
 *       @date  10/22/2011 14:41:40
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HOST_H__
#define HOST_H__
#include <Net/IpAddress.h>
#include <string.h>
class Host: public IpAddress
{
    public:
        /**
         * @brief Constructor
         * @param host the host name
         * @param port the port number
         */
        Host(const string& host, const uint8& port);

        /**
         * @brief Constructor
         * @param host the host name
         * @param port the port number
         */
        Host(const char* host, const uint8 port);

        /**
         * @brief returns the host struct
         * @return the sockaddr_in struct containing the host and port
         */
        sockaddr_in getHost();

        /**
         * @brief cast operator redefinition
         */
        operator sockaddr_in();

    private:
        uint8 m_port;




};

#endif

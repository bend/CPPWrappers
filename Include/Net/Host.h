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
#include <System/TypeCast.h>
#include <string.h>
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
        Host(const string& host, const uint8& port);

        /**
         * @brief Constructor
         * @param host the host name
         * @param port the port number
         */
        Host(const char* host, const uint8 &port);
        
		/**
		 * @brief Constructor
		 * @param host the IpAddress::Ip 
		 * @param port the port number
		 */
		Host(IpAddress::Ip host, const uint8 &port);

        /**
         * @brief returns the host struct
         * @return the sockaddr_in struct containing the host and port
         */
        sockaddr_in getHost();
		
		/**
		 * @brief sets the host (ip and port)
		 * @param addr the sockaddr_in structure
		 */
		void setHost(sockaddr_in &addr);

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
        uint8 m_port;




};

#endif

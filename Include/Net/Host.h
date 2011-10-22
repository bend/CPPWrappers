/**
 *
 *       @file  Host.h
 *
 *      @brief  
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

class Host:public IpAddress{
	public:
		Host(const string& host, const uint8& port);
		Host(const char* host, const uint8 port);
		sockaddr_in getHost();

		operator sockaddr_in();

	private:
		uint8 m_port;




};

#endif

/**
 *
 *       @file  IpAddress.h
 *
 *      @brief  Ip address class
 *
 *    @version  1.0
 *       @date  10/22/2011 13:13:07
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef IP_ADDRESS_H__
#define IP_ADDRESS_H__

#include <netinet/in.h> 
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <stdlib.h>

#include <System/Types.h>

using namespace std;
class IpAddress{
	public:
		
		enum Ip { 
			None
		};

		IpAddress(const string &host);

		IpAddress(const char* host);

		IpAddress(const  uint8 &byte1, const uint8 &byte2, const uint8 &byte3, const uint8 &byte4);

		IpAddress(uint32 addr);

		string toString();

		uint32 toInt();

	private:
		in_addr_t m_ipAddr;


};

#endif

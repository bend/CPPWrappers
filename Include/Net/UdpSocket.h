/**
 *
 *       @file  UdpSocket.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/24/2011 12:26:27
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef UDP_SOCKET_H__
#define UDP_SOCKET_H__
#include <Net/AbstractSocket.h>

class UdpSocket:public AbstractSocket{
	public:
		enum
		{
			MaxDatagramSize = 65507
		};
			
		UdpSocket();

		AbstractSocket::Status bind(const uint8 &port);

		void unbind();
	
		AbstractSocket::Status sendChar(const char& c, Host& h);
		
		AbstractSocket::Status sendString(const string& str, Host& h);
		
		AbstractSocket::Status sendCharArray(const char* str, size_t &s,  Host& h);

		AbstractSocket::Status sendShort(const int8 &i, Host &h);
		
		AbstractSocket::Status sendInt(const int32& i, Host &h);
		
		AbstractSocket::Status sendLong(const int64 &i, Host &h);
		
		
		AbstractSocket::Status receiveChar(char &c, Host &peer);

		AbstractSocket::Status receiveString(string &str, Host &peer);
		
		AbstractSocket::Status receiveCharArray(char** c, Host &peer);

		AbstractSocket::Status receiveShort(int8 &i, Host &peer);
		
		AbstractSocket::Status receiveInt(int32 &i, Host &peer);
		
		AbstractSocket::Status receiveLong(int64 &i, Host &peer);
		
};

#endif

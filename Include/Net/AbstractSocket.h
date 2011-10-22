/**
 *
 *       @file  AbstractSocket.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/21/2011 22:53:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
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

class AbstractSocket{
	public:

		enum Status {
			Done,
			NotReady,
			Disconnected,
			Error,
			EOPEN,
			EHOST,
			EMEM
		};

		AbstractSocket();
	
		AbstractSocket(int socket);
	
		uint8 getLocalPort() const;

		uint8 getRemotePort() const;

		IpAddress getRemoteAddress();

		void setBlocking(bool b);

		bool isBlocking();

		AbstractSocket::Status getSocketStatus();

		/**
		 * @brief disconnects from the host
		 */
		void close();
	

	protected:
		int m_socketfd;
	
	private:
		bool m_isBlocking;
};

#endif

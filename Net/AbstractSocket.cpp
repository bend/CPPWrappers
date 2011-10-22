/**
 *
 *       @file  AbstractSocket.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/21/2011 22:53:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/AbstractSocket.h>

AbstractSocket::AbstractSocket():m_isBlocking(true){
}

AbstractSocket::AbstractSocket(int socket):
	m_socketfd(socket),
	m_isBlocking(true){

}

uint8 AbstractSocket::getLocalPort() const{
	if(m_socketfd != -1){
		sockaddr_in address;
		socklen_t size = sizeof(address);
		if (getsockname(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1){
			return ntohs(address.sin_port);
		}
	}		
	return 0;
}

uint8 AbstractSocket::getRemotePort() const{
    if (m_socketfd != -1){
        sockaddr_in address;
        socklen_t size = sizeof(address);
        if (getpeername(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1)
        {
            return ntohs(address.sin_port);
        }
    }
    return 0;
}

IpAddress AbstractSocket::getRemoteAddress(){
	if (m_socketfd != -1){   
        sockaddr_in address;
        socklen_t size = sizeof(address);
        if (getpeername(m_socketfd, reinterpret_cast<sockaddr*>(&address), &size) != -1){
            return IpAddress(ntohl(address.sin_addr.s_addr));                            
        }                                                                                
    }                                                                                    
    
    return IpAddress::None;         
}


void AbstractSocket::setBlocking(bool b){
	int status = fcntl(m_socketfd, F_GETFL);
	if (b)
		fcntl(m_socketfd, F_SETFL, status & ~O_NONBLOCK);
	else
		fcntl(m_socketfd, F_SETFL, status | O_NONBLOCK);
	m_isBlocking = b;
}

bool AbstractSocket::isBlocking(){
	return m_isBlocking;
}

AbstractSocket::Status AbstractSocket::getSocketStatus(){
	if ((errno == EAGAIN) || (errno == EINPROGRESS))
        return AbstractSocket::NotReady;

    switch (errno)
    {
        case EWOULDBLOCK :  return AbstractSocket::NotReady;
        case ECONNABORTED : return AbstractSocket::Disconnected;
        case ECONNRESET :   return AbstractSocket::Disconnected;
        case ETIMEDOUT :    return AbstractSocket::Disconnected;
        case ENETRESET :    return AbstractSocket::Disconnected;
        case ENOTCONN :     return AbstractSocket::Disconnected;
        default :           return AbstractSocket::Error;
    }
}

void AbstractSocket::close() {
    ::close(m_socketfd);
}

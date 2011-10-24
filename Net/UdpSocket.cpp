/**
 *
 *       @file  UdpSocket.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/24/2011 12:26:27
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/UdpSocket.h>

UdpSocket::UdpSocket(){
}

AbstractSocket::Status UdpSocket::bind(const uint8 &port){
	struct sockaddr_in addr;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	addr = Host(IpAddress::Any, port).getHost();
	if (::bind(m_socketfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

void UdpSocket::unbind(){
	close();
}

AbstractSocket::Status UdpSocket::sendChar(const char& c, Host &h){
	struct sockaddr_in peer;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, &c, sizeof(char), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendString(const string& str, Host &h){
	struct sockaddr_in peer;
	const char* data = str.c_str();
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, data, str.length(), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendCharArray(const char* str, const size_t &s, Host &h){
	struct sockaddr_in peer;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, str, s, 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendShort(const int8& i, Host &h){
	struct sockaddr_in peer;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, &i, sizeof(i), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendInt(const int32& i, Host &h){
	struct sockaddr_in peer;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, &i, sizeof(i), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::sendLong(const int64& i, Host &h){
	struct sockaddr_in peer;
	if(m_socketfd == -1)
		if ((m_socketfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
			return getSocketStatus();
	peer = h.getHost();
	if (sendto(m_socketfd, &i, sizeof(i), 0, reinterpret_cast<sockaddr*>(&peer), sizeof(peer))==-1)
		return getSocketStatus();
	return AbstractSocket::Done;
}

AbstractSocket::Status UdpSocket::receiveChar(char &c, Host &peer){
	char* buffer = new char;
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, buffer, sizeof(c), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	c = *buffer;
	return Done;
}

AbstractSocket::Status UdpSocket::receiveCharArray(char** str, Host &peer){
	*str = new char[MaxDatagramSize];
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, *str, MaxDatagramSize, 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	return Done;
}

AbstractSocket::Status UdpSocket::receiveString(string &str, Host &peer){
	char* buffer = new char[MaxDatagramSize];
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, buffer, MaxDatagramSize, 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	str.assign(buffer, dataRead);
	return Done;
}


AbstractSocket::Status UdpSocket::receiveShort(int8 &i, Host &peer){
	short* buffer = new short;
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, buffer, sizeof(int), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	i = *buffer;
	return Done;
}

AbstractSocket::Status UdpSocket::receiveInt(int32 &i, Host &peer){
	int* buffer = new int;
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, buffer, sizeof(int), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	i = *buffer;
	return Done;
}

AbstractSocket::Status UdpSocket::receiveLong(int64 &i, Host &peer){
	long* buffer = new long;
	struct sockaddr_in from;
	int dataRead;
	int len = sizeof(from);
	if((dataRead = recvfrom(m_socketfd, buffer, sizeof(int), 0, reinterpret_cast<sockaddr*>(&from), reinterpret_cast<socklen_t*>(&len)))==-1)
		return getSocketStatus();
	peer.setHost(from);
	i = *buffer;
	return Done;
}



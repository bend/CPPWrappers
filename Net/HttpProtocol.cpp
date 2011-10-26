/**
 *
 *       @file  HttpProtocol.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/24/2011 18:44:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/HttpProtocol.h>

HttpProtocol::HttpProtocol(Host &h): 
	TcpSocket(),
	m_host(h)
{
}

AbstractSocket::Status HttpProtocol::sendRequest(HttpRequest &request)
{	
	m_response.clean();
	if(request.checkAndFix() < 0)
		return InvalidRequest;
		
	if(connect(m_host) != AbstractSocket::Done)
		return getSocketStatus();
	if(sendString(request.toString()) != AbstractSocket::Done)
		return getSocketStatus();
	
}


HttpResponse& HttpProtocol::getResponse()
{
	return m_response;
}

int HttpProtocol::checkRequest(HttpRequest &request)
{
	
}

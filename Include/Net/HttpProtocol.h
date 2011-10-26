/**
 *
 *       @file  HttpProtocol.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/24/2011 18:44:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HTTP_PROTOCOL_H__
#define HTTP_PROTOCOL_H__
#include <Net/TcpSocket.h>
#include <Net/HttpResponse.h>
#include <Net/HttpRequest.h>

class HttpProtocol : protected TcpSocket
{
    public:
		HttpProtocol(Host& h);
        /**
         * @brief sends the request to the Host specified in the constructor
         * The Response will be retrieved and can be accessed
         * with the HttpProtocol::getResponse() method
         * @param request a HttpRequest object containing the request
         * @return -1
         */
		AbstractSocket::Status sendRequest(HttpRequest& request);

        /**
         * @brief get the HttpResponse() from the last HttpRequest.
         * The method is only an accessor, it will not retrieve the Response.
         * This is automatically done while sending a request.
         * @return the HttpResponse object
         */
        HttpResponse& getResponse();

    private:

		int checkRequest(HttpRequest &request);
		Host m_host;
        HttpResponse m_response;

};

#endif

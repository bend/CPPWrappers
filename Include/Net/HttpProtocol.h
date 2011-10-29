/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
        Host m_host;
        HttpResponse m_response;

};

#endif

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

#include <Net/HttpProtocol.h>

HttpProtocol::HttpProtocol(Host& h):
    TcpSocket(),
    m_host(h)
{
}

AbstractSocket::Status HttpProtocol::sendRequest(HttpRequest& request)
{
    m_response.clean();

    if (request.checkAndFix() < 0)
        return InvalidRequest;

    if (connect(m_host) != Done)
        return getStatus();

    if (sendString(request.toString()) != Done)
        return getStatus();

    string str = "";

    while (receiveString(str, 1024) == Done)
    {
        m_response.append(str);
    }
}

HttpResponse& HttpProtocol::getResponse()
{
    return m_response;
}


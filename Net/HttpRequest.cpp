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

#include <Net/HttpRequest.h>

HttpRequest::HttpRequest(const string& sub, const RequestType& type):
    m_contents()
{
    setHttpVersion("1.1");
    setRequestType(type);
    setSub(sub);
}

void HttpRequest::setField(const string& field, const string& value)
{
    m_contents[field] = value;
}

void HttpRequest::setRequestType(const RequestType& type)
{
    switch (type)
    {
        case Get:
            m_requestType = "GET";
            break;

        case Post:
            m_requestType = "POST";
            break;

        case Head:
            m_requestType = "HEAD";
            break;
    };
}

void HttpRequest::setHttpVersion(const string& version)
{
    m_httpVersion = version;
}

void HttpRequest::setSub(const string& sub)
{
    if (sub.length() > 0)
        m_requestSub = (sub[0] == '/' ? sub : "/" + sub);
}

void HttpRequest::setBody(const string& body)
{
    m_body = body;
}

void HttpRequest::clean()
{
    m_contents.clear();
}

int HttpRequest::checkAndFix()
{
    // TODO better checks
    if (m_contents.count(UserAgent) == 0)
        m_contents[UserAgent] = "CPPWrappers/0.5";

    if (m_contents.count(ContentType) == 0)
        m_contents[ContentType] = "text/html";

    return 0;
}

string HttpRequest::toString()
{
    stringstream stream;
    map<string, string>::iterator it;
    stream << m_requestType << " " << m_requestSub << " " << "HTTP/" << m_httpVersion << "\n";

    for (it = m_contents.begin(); it != m_contents.end(); ++it)
    {
        stream << (*it).first << ": " << (*it).second << "\n";
    }

    stream << "\n";
    stream << m_body;
    return stream.str();
}


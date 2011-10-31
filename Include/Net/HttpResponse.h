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

#ifndef HTTP_RESPONSE_H__
#define HTTP_RESPONSE_H__
#include <iostream>
#include <sstream>
#include <map>
#include <Net/HttpTypes.h>
#include <stdlib.h>
using namespace std;

class HttpResponse : public HttpTypes
{
    public:
        /**
         * @brief empty constructor
         */
        HttpResponse();

        /**
         * @brief constructor
         * This class is used by the HttpProtocol and should therefore not be instanciated
         * @param str the response of the server
         */
        HttpResponse(string& str);

        /**
         * @brief cleans the HttpResponse contents
         */
        void clean();

        /**
         * @brief appends the stirng to the contents
         */
        void append(const string& str);

        /**
         * @brief return the content length
         * @return the length
         */
        int getContentLength();

        /**
         * @brief return the http version
         * @return the version
         */
        string getHttpVersion();

        /**
         * @brief return the status code
         * @return the code
         */
        int getResponseCode();

        /**
         * @brief return the http body
         * @return the http body
         */
        string getBody();

        /**
         * @brief returns a string representation of the Response
         * @return the string
         */
        string toString();

        /**
         * @brief parses the received header
         */
        void parse();

        /**
         * @brief returns a field
         * @param field the field you need
         * @return the value of the field if existing or an empty string if non existant
         * @see HtmlTypes to see (some) possible fields
         */
        string getField(const string& field);

    private:
        string m_response;
        int m_contentLength;
        int m_responseStatus;
        map<string, string> m_contents;
        string m_version;
        int m_code;
        string m_body;
};

#endif

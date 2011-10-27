/**
 *
 *       @file  HttpResponse.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/24/2011 18:38:00
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HTTP_RESPONSE_H__
#define HTTP_RESPONSE_H__
#include <iostream>
#include <sstream>
#include <Net/HttpTypes.h>
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
         * @brief returns a string representation of the Response
         * @return the string
         */
        string toString();

    private:
        void parse();

        string m_response;
        int m_contentLength;
        int m_responseStatus;
        string m_serverName;




};

#endif

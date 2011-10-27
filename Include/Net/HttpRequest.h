/**
 *
 *       @file  HttpRequest.h
 *
 *      @brief  Http Requests class
 *
 *    @version  1.0
 *       @date  10/24/2011 18:25:07
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HTTP_REQUEST_H__
#define HTTP_REQUEST_H__
#include <map>
#include <sstream>
#include <iterator>
#include <iostream>

#include <Net/HttpTypes.h>
using namespace std;

class HttpRequest : public HttpTypes
{

    public:
        /**
         * @brief Request types handled
         */
        enum RequestType
        {
            /** Get Request **/
            Get,
            /** Post Request **/
            Post,
            /** Head Requet (server does not return message body **/
            Head,
            /** Delete method **/
            Delete,
            /** Trace method **/
            Trace
        };

        /**
         * @brief Constructor
         * @param sub the sub url to load, default is root ('/')
         * @param type the RequestType default is Get
         */
        HttpRequest(const string& sub = "/", const RequestType& type = Get);

        /**
         * @brief sets the contents of field.
         * If the field does not exists, it will be created otherwise, the initial value will be overwritten
         * @param field the field name
         * @param value the value to set for the field
         */
        void setField(const string& field, const string& value);

        /**
         * @brief sets the request type
         * @param type the RequestType
         */
        void setRequestType(const RequestType& type) ;

        /**
         * @brief sets the Http version (default is 1.1)
         * The version is a string representing a number
         * @param version the version number
         */
        void setHttpVersion(const string& version);

        /**
         * @brief sets the Sub url to load
         * @param sub the sub url
         */
        void setSub(const string& sub ) ;

        /**
         * @brief sets the body of the request
         * The body will be appended at the end of the request
         * @param body the html body
         */
        void setBody(const string& body);

        /**
         * @brief clears the HttpRequest contents
         */
        void clean();

        /**
         * @brief checks if all the required fields are filled.
         * If not, they will be automatically filled with a default value
         * @return 0 is success, -1 otherwise
         */
        int checkAndFix();

        /**
         * @brief returns the string representation of the HttpRequest.
         * The string is ready to be sent as an http request
         * @return the string
         */
        string toString();



    private:
        map<string, string> m_contents;
        string m_requestType;
        string m_httpVersion;
        string m_requestSub;
        string m_body;


};

#endif

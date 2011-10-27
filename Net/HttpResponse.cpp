/**
 *
 *       @file  HttpResponse.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/24/2011 18:36:53
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/HttpResponse.h>

HttpResponse::HttpResponse():
    m_response(""),
    m_contentLength(-1),
    m_responseStatus(-1),
    m_serverName("")

{
}

HttpResponse::HttpResponse(string& str):
    m_response(str),
    m_contentLength(-1),
    m_responseStatus(-1),
    m_serverName("")
{
    parse();
}

void HttpResponse::clean()
{
    m_response.clear();
}

void HttpResponse::append(const string& str)
{
    m_response.append(str);
}

string HttpResponse::toString()
{
    return m_response;
}

void HttpResponse::parse()
{
    istringstream iss(m_response, istringstream::in);
    /* First line is Error code */
    //string err = iss.getline();
}

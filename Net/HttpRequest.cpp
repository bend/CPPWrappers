/**
 *
 *       @file  HttpRequest.cpp
 *
 *      @brief  HttpRequest.cpp
 *
 *    @version  1.0
 *       @date  10/24/2011 18:25:07
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
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

void HttpRequest::setBody(const string &body){
	m_body = body;
}

void HttpRequest::clean()
{
    m_contents.clear();
}

int HttpRequest::checkAndFix()
{	
	// TODO better checks 
	if(m_contents.count(UserAgent) == 0)
		m_contents[UserAgent] = "CPPWrappers/0.5";
	if(m_contents.count(ContentType) == 0)
		m_contents[ContentType] = "text/html";
	return 0;
}

string HttpRequest::toString()
{
    stringstream stream;
    map<string, string>::iterator it;
    stream << m_requestType << " " << m_requestSub << " " << "HTTP/"<<m_httpVersion << "\n";

    for (it = m_contents.begin(); it != m_contents.end(); ++it)
    {
        stream << (*it).first << ": " << (*it).second << "\n";
    }

    stream << "\n";
	stream << m_body;
    return stream.str();
}


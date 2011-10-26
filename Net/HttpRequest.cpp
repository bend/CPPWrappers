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

HttpRequest::HttpRequest(const string& sub, const RequestType &type):m_contents(){

}

void HttpRequest::setContentField(const string& field, const string& value){
	m_contents[field] = value;
}

void HttpRequest::setRequestType(const RequestType& type) {

}

void HttpRequest::setRequestSub(const string& sub) {
}

void HttpRequest::clean()
{
	m_contents.clear();
}

int HttpRequest::checkAndFix()
{
}

string HttpRequest::toString()
{
	stringstream stream;
	map<string, string>::iterator it;
	stream << m_requestType<<"\n";
	for(it = m_contents.begin(); it != m_contents.end(); ++it){
		stream<<(*it).first<<": "<<(*it).second<<"\n";
	}
	stream<<"\n";	
	return stream.str();
}

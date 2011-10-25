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
#include <iostream>
using namespace std;

class HttpRequest
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
		Post
	};
	
	/**
	 * @brief Constructor
	 * @param sub the sub url to load, default is root ('/')
	 * @param type the RequestType default is Get
	 */
	HttpRequest(const string &sub = "/", const RequestType &type = Get);
	
	/**
	 * @brief sets the contents of field.
	 * If the field does not exists, it will be created otherwise, the initial value will be overwritten
	 * @param field the field name
	 * @param value the value to set for the field
	 */
	void setContentField(const string &field, const string &value) const;
	
	/**
	 * @brief sets the request type 
	 * @param type the RequestType 
	 */
	void setRequestType(const RequestType& type);
	
	/**
	 * @brief sets the Sub url to load 
	 * @param field the sub url
	 */
	void setRequestSub(const string &sub );

    private:
		map<string, string> m_contents;




};

#endif

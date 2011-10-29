/**
 *
 *       @file  HtmlElement.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/29/2011 11:36:25
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HTML_ELEMENT_H__
#define HTML_ELEMENT_H__
#include <iostream>
#include <vector>
using namespace std;
class HtmlElement{
	public:
	HtmlElement();
	
	HtmlElement(string tag, vector<HtmlElement> elems, string contents);

	string& getTag();
	
	string& getContents();
	
	void addHtmlElement(HtmlElement elem);
	
	vector<HtmlElement>& getHtmlElements();

	void setTag(const string& str);

	void setContents(const string& str);

	HtmlElement& operator[] (const string& str);

	HtmlElement& operator = (const string& str);
	
	string toString();
	

	private:
		string m_tag;
		string m_contents;
		vector<HtmlElement> m_elems;


};

#endif

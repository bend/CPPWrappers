/**
 *
 *       @file  HtmlElement.cpp
 *
 *      @
 *
 *    @version  1.0
 *       @date  10/29/2011 11:36:25
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/HtmlElement.h>

HtmlElement::HtmlElement():
	m_tag(""),
	m_contents(""),
	m_elems()
{

}

HtmlElement::HtmlElement(string tag, vector<HtmlElement> elems, string contents):
	m_tag(tag),
	m_contents(contents),
	m_elems(elems){

}

string& HtmlElement::getTag(){
	return m_tag;
}

string& HtmlElement::getContents(){
	return m_contents;
}

vector<HtmlElement>& HtmlElement::getHtmlElements(){
	return m_elems;
}

void HtmlElement::addHtmlElement(HtmlElement elem){
	m_elems.push_back(elem);
}

void HtmlElement::setTag(const string& str){
	m_tag = str;
}

void HtmlElement::setContents(const string& str){
	m_contents = str;
}

HtmlElement& HtmlElement::operator[](const string& str){
	unsigned int i;
	for(i = 0; i<m_elems.size(); i++)
		if(m_elems[i].getTag() == str){
			return m_elems[i];
		}
	/* Create it if non existant */
	HtmlElement elem(str, vector<HtmlElement>(), "");
	m_elems.push_back(elem);
	return m_elems[m_elems.size()-1];
}

HtmlElement& HtmlElement::operator = (const string& str){
	m_contents = str;
	return *this;
}


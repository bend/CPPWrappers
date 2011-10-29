/**
 *
 *       @file  HtmlElement.h
 *
 *      @brief Represents an html elements
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
class HtmlElement
{
    public:
		/**
		 * @brief empty constructor
		 */
        HtmlElement();
		
		/**
		 * @brief Constructor 
		 * @param tag the tag name ex: div
		 * @param elems the sub elements
		 * @param contents the contents of the field
		 */
        HtmlElement(string tag, vector<HtmlElement> elems, string contents);
		
		/*
		 * @brief Constructor 
		 * @param tag the tag name ex div
		 * @param elems the sub elements
		 * @param contents the contents of the field
		 * @param flag the flag ex div id
		 */
        HtmlElement(string tag, vector<HtmlElement> elems, string contents, string flag);
		
		/** 
		 * @brief return the tag 
		 * @return a reference to the tag
		 */
        string& getTag();
		
		/**
		 * @brief return the contents
		 * @return the reference to the contents
		 */
        string& getContents();
		
		/**
		 * @brief returns the flags
		 * @return the reference to the flag
		 */
        string& getFlag();

		/**
		 * @brief adds an html element to the sub elements
		 * @param elem the HtmlElement 
		 */
        void addHtmlElement(HtmlElement elem);
		
		/**
		 * @brief return the sub elements
		 * @return a reference to the vector<HtmlElement>
		 */
        vector<HtmlElement>& getHtmlElements();
		
		/**
		 * @brief sets the tag
		 * @param str the tag to set
		 */
        void setTag(const string& str);
		
		/**
		 * @brief sets the contents
		 * @param str the contents to set
		 */
        void setContents(const string& str);
		
		/**
		 * @brief operator[] to access to child tag
		 * This will return the first matching tag
		 * If you want to access all the named tags use the HtmlElement::getHtmlElements() method
		 * @param str the tag name
		 * @return the HtmlElement searched or an new HtmlElement object with the tag name
		 */
        HtmlElement& operator[] (const string& str);
		
		/**
		 * @brief operator = sets the value of the contents field.
		 * This is the same as the HtmlElement::setContents() method
		 * @return *this
		 */
        HtmlElement& operator = (const string& str);
		
		/**
		 * @brief returns a string representation of the HtmlElement.
		 * This is a recursice method and will therefore return a representation of the current object and all the childs
		 */
        string toString();

    private:
        string m_tag;
        string m_contents;
        string m_flag;
        vector<HtmlElement> m_elems;


};

#endif

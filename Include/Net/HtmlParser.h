/**
 *
 *       @file  HtmlParser.h
 *
 *      @brief  Parses html and puts it in a map
 *
 *    @version  1.0
 *       @date  10/28/2011 08:33:34
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef HTML_PARSER_H__
#define HTML_PARSER_H__
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
using namespace std;

#include <Net/HtmlElement.h>

class HtmlParser
{
    public:
		/**
		 * @brief Constructor
		 * @param html the html text
		 */
        HtmlParser(string html);
		
		/**
		 * @brief parses the html text and represents it with HtmlElement objects
		 * @return 0 is success, -1 otherwise
		 */
        int parse();
		
		/**
		 * @brief return the root element
		 * This object contains only a vector of HtmlElement and does not have a tag or a content field
		 * @return the HtmlElement 
		 */
        HtmlElement& getRootElement();
		

    private:

        int preProcess(list<string> &tokens);
        
		HtmlElement parseTag(string tag, list<string> &tokens);

        HtmlElement parseSpecialTag(string tag, list<string> &tokens);

        bool isSpecialTag(string& tag, string& str);

        bool isSpecialOpenTag(string& tag, string& str);

        bool isNewTagOpen(string& tag, string& str);

        bool isCloseTag(string& tag, string& str);

        string getOpenTag(string str);

        string getCloseTag(string str);

        HtmlElement m_elem;
        string m_html;

};

#endif

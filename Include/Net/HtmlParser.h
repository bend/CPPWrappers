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
        HtmlParser(string html);

        int parse();

        HtmlElement& getElem();

        int preProcess(list<string> &tokens);

    private:

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

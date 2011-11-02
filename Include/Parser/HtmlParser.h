/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HTML_PARSER_H__
#define HTML_PARSER_H__

#include <Parser/HtmlElement.h>

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
using namespace std;

/**
 * @brief Parses an html content into HtmlElement
 */
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

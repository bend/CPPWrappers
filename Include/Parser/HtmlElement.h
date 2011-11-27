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

#ifndef HTML_ELEMENT_H__
#define HTML_ELEMENT_H__

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Represents an Html element
 */
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
         * @brief append flag for this element
         * @param flag the flag to add
         */
        void addFlag(string flag);

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

        /**
         * @brief redefinition for cout
         */
        friend ostream& operator << (ostream&, HtmlElement& e) ;

    private:
        string m_tag;
        string m_contents;
        string m_flag;
        vector<HtmlElement> m_elems;


};

#endif

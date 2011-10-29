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
    m_elems(elems)
{
}

HtmlElement::HtmlElement(string tag, vector<HtmlElement> elems, string contents, string flag):
    m_tag(tag),
    m_contents(contents),
    m_flag(flag),
    m_elems(elems)
{
}

string& HtmlElement::getTag()
{
    return m_tag;
}

string& HtmlElement::getContents()
{
    return m_contents;
}

string& HtmlElement::getFlag()
{
    return m_flag;
}

vector<HtmlElement>& HtmlElement::getHtmlElements()
{
    return m_elems;
}

void HtmlElement::addHtmlElement(HtmlElement elem)
{
    m_elems.push_back(elem);
}

void HtmlElement::setTag(const string& str)
{
    m_tag = str;
}

void HtmlElement::setContents(const string& str)
{
    m_contents = str;
}

HtmlElement& HtmlElement::operator[](const string& str)
{
    unsigned int i;

    for (i = 0; i < m_elems.size(); i++)
        if (m_elems[i].getTag() == str)
        {
            return m_elems[i];
        }

    /* Create it if non existant */
    HtmlElement elem(str, vector<HtmlElement>(), "");
    m_elems.push_back(elem);
    return m_elems[m_elems.size() - 1];
}

HtmlElement& HtmlElement::operator = (const string& str)
{
    m_contents = str;
    return *this;
}


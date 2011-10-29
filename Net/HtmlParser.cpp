/**
 *
 *       @file  HtmlParser.cpp
 *
 *      @brief  Parses html and puts it in a map
 *
 *    @version  1.0
 *       @date  10/28/2011 08:33:34
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/HtmlParser.h>

HtmlParser::HtmlParser(string html):
    m_html(html)
{
}

int HtmlParser::parse()
{
    list<string> tokens;

    if (preProcess(tokens) == -1)
        return -1;

    string tag = tokens.front();
    tokens.pop_front();
    m_elem.addHtmlElement(parseTag(getOpenTag(tag), tokens));
    return 0;
}

int HtmlParser::preProcess(list<string> &tokens)
{
    /* Parse the html on '<' and '>' */
    unsigned int i = 0;
    bool inTag = false;
    bool betweenTags = false;
    string contents = "";

    while (i < m_html.length())
    {
        char c = m_html[i];

        /* skip the spaces if not in tag */
        if ((c == ' ' || c == '\n' || c == '\r') && !betweenTags && !inTag)
        {
            ++i;
            continue;
        }

        else if (c == '<')
        {
            inTag = true;
            betweenTags = false;

            if (contents.length() > 0)
            {
                tokens.push_back(contents);
                contents.clear();
            }

            contents += c;
        }

        else if (c == '>')
        {
            if (inTag)
                betweenTags = true;

            contents += c;
            tokens.push_back(contents);
            contents.clear();
            inTag = false;
        }

        else
        {
            if ((c == ' ' || c == '\n' || c == '\r') && contents.length() == 0)
            {
                ++i;
                continue;
            }

            else contents += c;
        }

        ++i;
    }

    return 0;
}

HtmlElement HtmlParser::parseTag(string tag, list<string> &tokens)
{
    string temp = "";
    string contents = "";
    vector<HtmlElement> elems;

    while (tokens.size() > 0)
    {
        temp = tokens.front();
        tokens.pop_front();

        /* Skip special tags (like <br/> */
        if (isSpecialTag(tag, temp))
            continue;

        /* Check special tags like <a href=...> */
        if (isSpecialOpenTag(tag, temp))
            elems.push_back(parseSpecialTag(temp, tokens));

        else if (isNewTagOpen(tag, temp))
            elems.push_back(parseTag(getOpenTag(temp), tokens));

        else if (isCloseTag(tag, temp))
            return HtmlElement(tag, elems, contents);

        else contents += temp;
    }

    return HtmlElement(tag, elems, contents);
}

HtmlElement HtmlParser::parseSpecialTag(string tag, list<string> &tokens)
{
    /* Retrive the tag and the flags from the string */
    string flags = tag.substr(tag.find_first_of(' ') + 1, tag.find('>') - (tag.find_first_of(' ') + 1));
    string theTag = tag.substr(1, tag.find_first_of(' ') - 1);
    vector<HtmlElement> elems;
    string temp = "";
    string contents = "";

    while (tokens.size() > 0)
    {
        temp = tokens.front();
        tokens.pop_front();

        /* Skip special tags (like <br/> */
        if (isSpecialTag(tag, temp))
            continue;

        /* Check special tags like <a href=...> */
        if (isSpecialOpenTag(theTag, temp))
            elems.push_back(parseSpecialTag(temp, tokens));

        else if (isNewTagOpen(theTag, temp))
            elems.push_back(parseTag(getOpenTag(temp), tokens));

        else if (isCloseTag(theTag, temp))
            return HtmlElement(theTag, elems, contents, flags);

        else contents += temp;
    }
}

bool HtmlParser::isSpecialTag(string& tag, string& str)
{
    if (str[str.length() - 2 ] == '/' && str[str.length() - 1] == '>')
        return true;

    return false;
}

bool HtmlParser::isSpecialOpenTag(string& tag, string& str)
{
    if (str[0] == '<' && str[str.length() - 1] == '>')
    {
        int i = 0;

        while (i < str.length())
        {
            if (str[i] == ' ')
                return true;

            ++i;
        }
    }

    return false;
}

bool HtmlParser::isNewTagOpen(string& tag, string& str)
{
    if (str.length() > 0 && (str[0] != '<' || str[1] == '/') )
        return false;

    return getOpenTag(str) == tag ? false : true;
}

bool HtmlParser::isCloseTag(string& tag, string& str)
{
    if (str[1] != '/' || str[str.length() - 1] != '>')
        return false;

    return getCloseTag(str) == tag ? true : false;
}

string HtmlParser::getOpenTag(string tag)
{
    if (tag.length() > 0)
    {
        /* Remove '<' and '>' */
        tag = tag.substr(1);

        /* Check if there is a '>' and remove it */
        if (tag[tag.length() - 1] == '>')
            tag = tag.substr(0, tag.length() - 1);

        return tag;
    }

    return "";
}

string HtmlParser::getCloseTag(string tag)
{
    if (tag.length() > 0)
    {
        /* Check if there is a '<' and remove it */
        if (tag[0] == '<')
            tag = tag.substr(1);

        /* Remove '/' and '>' */
        if (tag[0] == '/' && tag[tag.length() - 1] == '>')
            tag = tag.substr(1, tag.length() - 2);

        else return "";

        return tag;
    }

    return "";
}

HtmlElement& HtmlParser::getElem()
{
    return m_elem;
}

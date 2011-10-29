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

#ifndef HTTP_TYPES_H__
#define HTTP_TYPES_H__
#include <iostream>
using namespace std;
class HttpTypes
{
    protected:
        /**
         * @brief protected constructor to avoid instanciation$
         */
        HttpTypes();

    public:
        /**
         * @brief Content-Types that are acceptable
         */
        static const string Accept ;

        /**
         * @brief Character sets that are acceptable
         */
        static const string AcceptCharset;

        /**
         * @brief Acceptable encodings
         */
        static const string AcceptEncoding;

        /**
         * @brief Acceptable languages for response
         */
        static const string AcceptLanguage;

        /**
         * @brief Authentication credentials for HTTP authenticatio
         */
        static const string Authorization;

        /**
         * @brief Used to specify directives that MUST be obeyed by all caching mechanisms along the request/response chain
         */
        static const string CacheControl;

        /**
         * @brief What type of connection the user-agent would prefer
         */
        static const string Connection;

        /**
         * @brief an HTTP cookie previously sent by the server with Set-Cookie
         */
        static const string Cookie;

        /**
         * @brief The length of the request body in octets (8-bit bytes)
         */
        static const string ContentLength;

        /**
         * @brief A Base64-encoded binary MD5 sum of the content of the request body
         */
        static const string ContentMD5;

        /**
         * @brief The mime type of the body of the request (used with POST and PUT requests)
         */
        static const string ContentType;

        /**
         * @brief  The date and time that the message was sent
         */
        static const string Date;

        /**
         * @brief Indicates that particular server behaviors are required by the client
         */
        static const string Expect;

        /**
         * @brief The email address of the user making the request
         */
        static const string From;

        /**
         * @brief The domain name of the server (for virtual hosting), mandatory since HTTP/1.1
         */
        static const string Host;

        /**
         * @brief Only perform the action if the client supplied entity matches the same entity on the server. This is mainly for methods like PUT to only update a resource if it has not been modified since the user last updated it.
         */
        static const string IfMatch;

        /**
         * @brief Allows a 304 Not Modified to be returned if content is unchanged
         */
        static const string IfModifiedSince ;

        /**
         * @brief Allows a 304 Not Modified to be returned if content is unchanged, see HTTP ETag
         */
        static const string IfNoneMatch;

        /**
         * @brief If the entity is unchanged, send me the part(s) that I am missing; otherwise, send me the entire new entity
         */
        static const string IfRange;

        /**
         * @brief Only send the response if the entity has not been modified since a specific time.
         */
        static const string IfUnmodifiedSince;

        /**
         * @brief Limit the number of times the message can be forwarded through proxies or gateways.
         */
        static const string MaxForwards;

        /**
         * @brief Implementation-specific headers that may have various effects anywhere along the request-response chain.
         */
        static const string Pragma;

        /**
         * @brief Authorization credentials for connecting to a proxy.
         */
        static const string ProxyAuthorization;

        /**
         * @brief Request only part of an entity. Bytes are numbered from 0.
         */
        static const string Range;

        /**
         * @brief This is the address of the previous web page from which a link to the currently requested page was followed. (The word “referrer” is misspelled in the RFC as well as in most implementations.)
         */
        static const string Referer;

        /**
         * @brief The transfer encodings the user agent is willing to accept: the same values as for the response header Transfer-Encoding can be used, plus the "trailers" value (related to the "chunked" transfer method) to notify the server it accepts to receive additional headers (the trailers) after the last, zero-sized, chunk
         */
        static const string TE;

        /**
         * @brief Ask the server to upgrade to another protocol.
         */
        static const string Upgrade;

        /**
         * @brief The user agent string of the user agent
         */
        static const string UserAgent ;

        /**
         * @brief Informs the server of proxies through which the request was sent.
         */
        static const string Via ;

        /**
         * @brief A general warning about possible problems with the entity body.
         */
        static const string Warning ;

        /**
         * @brief The type of encoding used on the data.
         */
        static const string ContentEncoding;

        /**
         * @brief  A name for the server
         */
        static const string Server;

};

#endif

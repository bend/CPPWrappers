
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

#ifndef EXCEPTION_H__
#define EXCEPTION_H__ 
#include <iostream>
using namespace std;

/**
 * Exceptions thrown by the classes in DS
 */
class Exception{
    public:
        inline Exception(){};

        inline Exception(string message){
            m_message = message;
        }

        inline string getMessage(){
            return m_message;
        }

    protected:
        string m_message;
};

/**
 * Exceptions thrown if the list is emtpy
 */
class EmptyListException: public Exception{
    public:
        inline EmptyListException():Exception(){
        }

        inline EmptyListException(string message):Exception(message){
        }
};

/**
 * Exception thrown if the node is null
 */
class EmptyNodeException: public Exception{
    public:
        inline EmptyNodeException():Exception(){
        }

        inline EmptyNodeException(string message):Exception(message){
        }
};

/**
 * Exception thrown is the Element is no found
 */
class ElementNotFoundException: public Exception{
    public:
        inline ElementNotFoundException():Exception(){
        }

        inline ElementNotFoundException(string message):Exception(message){
        }
};
#endif

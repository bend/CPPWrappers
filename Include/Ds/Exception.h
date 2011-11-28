
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

class EmptyListException: public Exception{
    public:
        inline EmptyListException():Exception(){
        }

        inline EmptyListException(string message):Exception(message){
        }
};

class EmptyNodeException: public Exception{
    public:
        inline EmptyNodeException():Exception(){
        }

        inline EmptyNodeException(string message):Exception(message){
        }
};

class ElementNotFoundException: public Exception{
    public:
        inline ElementNotFoundException():Exception(){
        }

        inline ElementNotFoundException(string message):Exception(message){
        }
};
#endif

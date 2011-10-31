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


#ifndef LOGGER_H__
#define LOGGER_H__

#include <System/Time.h>

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/**
 * @brief Logger for logging different events (errors, ...)
 */
class Logger
{
    public:
        /**
         * @brief Constructor
         * @param name the path to the log file.
         * If the file does not exist, it will be created, otherwise, it will be openned in append mode
         */
        Logger(string name);

        /**
         * @brief Virtual destructor
         */
        virtual ~Logger();

        /**
         * @brief Log the stream input
         * @param type: the Type of data to log (i.e. DEBUG, ERROR, ...)
         * @param indent the indent level
         */
        ofstream& log(string type, int indent = 0);


    private:
        string getTimeDate();
        ofstream m_out;


};

#endif

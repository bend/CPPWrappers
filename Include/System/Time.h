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


#ifndef TIME_H__
#define TIME_H__
#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <System/TypeCast.h>
class Time
{
    public:

        /**
         * @brief returns the system time in milliseconds
         * @return a long containing the time
         */
        static long getTimeMilliseconds();

        /**
         * @brief returns the time and date formatted
         * (i.e Wed Oct 12 19:43:44 2011)
         * @return the string containing the formated date
         */
        static string getTimeDate();

        /**
         * @brief returns the time and date formatted by the format string
         * @param format: the format (eg dd/MM/YYYY - HH:mm::SS).
         * You can use all formats you want the only restriction is to use
         * dd for the day
         * MM for the month
         * YYYY for the year
         * HH for the hour
         * mm for the minutes
         * SS for the seconds
         */
        static string getTimeDate(string format);






};

#endif

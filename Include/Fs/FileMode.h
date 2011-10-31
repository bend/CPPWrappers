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

#ifndef FILE_MODE_H__
#define FILE_MODE_H__

#include <Fs/FileTypes.h>

#include <iostream>
using namespace std;

/**
 * @brief Represents the file permissions
 */
class FileMode
{
    public:
        /**
         * @brief Constructor
         * @param mode the mode in int format (ex: 0744)
         */
        FileMode(int mode);

        /**
         * @brief get the mode of the file in int format
         * @return the mode
         * @see FileTypes for modes declaration
         */
        int getMode();

        /**
         * @brief allows the (char*) cast of the object
         */
        operator int();

        /**
         * @brief converts the mode to string representation (ex: 0755 -> rwxr-xr-x)
         * @return the string representation of the mode or empty string if error occurs
         */
        string getStringMode();

    private:
        int m_mode;
        string m_path;

};

#endif

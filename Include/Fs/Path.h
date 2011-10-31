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

#ifndef PATH_H__
#define PATH_H__

#include <iostream>
using namespace std;

/**
 * @brief Represents a Path
 */
class Path
{
    public:
        Path(string path);

        /**
         * @brief get the absolute path of the file
         * @return the absolute path of the file
         */
        Path getAbsolutePath();

        /**
         * @brief gets the file name of the file
         * @return the name
         */
        string getName();

        /**
         * @brief gets the parent directory
         * @return a Path object containing the parent path. If not parent ('/') the same path is returned
         */
        Path getParent();

        /**
         * @brief gets the path in string format
         * @return the string containing the path
         */
        string toString();

        /**
         * @brief allows (char*) cast
         */
        operator const char* ();

    private:
        string m_path;
};

#endif

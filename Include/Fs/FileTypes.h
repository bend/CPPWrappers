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

#ifndef FILE_TYPES_H__
#define FILE_TYPES_H__

#include <iostream>
using namespace std;

class FileTypes
{
    public:
        /**
         * @brief Size format enumeration
         */
        enum SizeFormat
        {
            /** Byte representation **/
            Byte,
            /** Kilobyte representation **/
            Kbyte,
            /** Megabyte representation **/
            Mbyte,
            /** Gigabyte representation **/
            Gbyte,
            /** Terabyte representation **/
            Tbyte
        };
        /**
         * @brief Open file in read mode
         */
        static const string Read ;

        /**
         * @brief Open file in write mode
         */
        static const string Write;

        /**
         * @brief Open the file in read write mode
         */
        static const string ReadWrite ;

        /**
         * @brief Open the file in read write append mode
         */
        static const string Append ;

        /**
         * @brief End of file marker
         */
        static const int Eof;

        /**
         * @brief seek from the begining of the file
         */
        static const int SeekfBegin;

        /**
         * @brief seek from the end of the file
         */
        static const int SeekfEnd;

        /**
         * @brief seek from the current position
         */
        static const int SeekCurrent;

        /*
         * @brief  RWX mask for owner
         */
        static const int RWXU;

        /**
         * @brief R for owner
         */
        static const int RU;

        /**
         * @brief  W for owner
         */
        static const int WU;

        /**
         * @brief X for owner
         */
        static const int XU;

        /**
         * @brief  RWX mask for group
         */
        static const int RWXG;

        /**
         * @brief  R for group
         */
        static const int RG;

        /**
         * @brief W for group
         */
        static const int WG;

        /**
         * @brief X for group
         */
        static const int XG;

        /**
         * @brief  RWX mask for other
         */
        static const int RWXO;

        /**
         * @brief  R for other
         */
        static const int RO;

        /**
         * @brief  W for other
         */
        static const int WO;

        /**
         * @brief  X for other
         */
        static const int XO;

        /**
         * @brief  set user id on execution
         */
        static const int SUID;

        /**
         * @brief  set group id on execution
         */
        static const int SGID;

        /**
         * @brief  save swapped text even after use
         */
        static const int SVTX;

};


#endif

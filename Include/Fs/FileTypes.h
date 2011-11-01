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
*m   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FILE_TYPES_H__
#define FILE_TYPES_H__

#include <iostream>
using namespace std;

/**
 * @brief Defines some constants used in File class
 */
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

		enum SeekMode
		{
			/** Seek from the beginning of the file **/
			SeekBegin = 0, 
			/** Seek from the current position **/
			SeekCurrent = 1,
			/** Seek from the end of the file **/
			SeekEnd  = 2
		};

		enum FilePermission
		{	
			/** No file mode found **/
			None = -1,
			/** RWX mask for owner **/
			RWXU = 0000700,
			
			/** R mask for owner **/
			RU = 0000400,
			
			/** W mask for owner **/
			WU = 0000200,
			
			/** X mask for owner **/
			XU = 0000100,
			
			/** RWX mask for group **/
			RWXG = 0000070,
			
			/** R mask for group **/
			RG = 0000040,	
			
			/** W mask for group **/
			WG = 0000020,	
			
			/** X mask for group **/
			XG = 0000010,
			
			/** RWX mask for others **/
			RWXO = 0000007,
			
			/** R mask for others **/
			RO = 0000004,
			
			/** W mask for others **/
			WO = 0000002,
		
			/** X masks for others **/
			XO = 0000001,
			
			/**  Set user id on execution **/
			SUID = 0004000,
			
			/** Set group id on execution **/
			SGID = 0002000,
			
			/** Save swapped text even after use **/
			SVTX = 0001000
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

};


#endif

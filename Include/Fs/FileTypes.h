/**
 *
 *       @file  FileTypes.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/16/2011 23:44:23
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
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

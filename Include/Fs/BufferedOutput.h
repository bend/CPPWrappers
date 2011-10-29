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

#ifndef BUFFERED_OUTPUT_H__
#define BUFFERED_OUTPUT_H__
#include <Fs/AbstractBufferIO.h>
#include <System/TypeCast.h>
#include <string.h>

class BufferedOutput: public AbstractBufferIO
{

    public:

        /**
         * @brief Constructor
         * @param f the File object in which we will write
         * @param openMode the open Mode (APPEND or WRITE)
         * @see FileTypes
         * @param buffLen the maximum buffer length to use (default is 1024 bytes)
         */
        BufferedOutput(File& f, const string& openMode, const int& buffLen = 1024);

        /**
         * @brief Destructor
         */
        ~BufferedOutput();

        /**
         * @brief writes the string to the buffer. When the buffer is full, the write function will flush it
         * @param str the string to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const string& str);

        /**
         * @brief writes the char* to the buffer. When the buffer is full, the write function will flush it
         * @param s the string to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const char* s);

        /**
         * @brief writes the int to the buffer. The int will be converted to string before being written.  When the buffer is full, the write function will flush it
         * @param i the int to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const int& i);

        /**
         * @brief writes the char to the buffer. When the buffer is full, the write function will flush it
         * @param c the char to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const char& c);

        /**
         * @brief writes the float to the buffer. The float will be converted to string before being written. When the buffer is full, the write function will flush it
         * @param f the float to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const float& f);

        /**
         * @brief writes the string to the buffer. The long will be converted to string before being written. When the buffer is full, the write function will flush it
         * @param l the long to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const long& l);

        /**
         * @brief writes the string to the buffer. The short will be converted to string before being written. When the buffer is full, the write function will flush it
         * @param s the short to write
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status write(const short& s);

        /**
         * @brief flushes the buffer and writes it contents to the file
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status flush();

        /**
         * @brief closes the file
         * @return AbstractBufferIO::Status with error code
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status close();

        /**
         * @brief writes the char
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const char& s);

        /**
         * @brief writes the short
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const short& s);

        /**
         * @brief writes the int
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const int& s);

        /**
         * @brief writes the long
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const long& s);

        /**
         * @brief writes the float
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const float& s);

        /**
         * @brief writes the string
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const string& s);

        /**
         * @brief writes the char*
         * Error status can be checked with AbstractBufferIO::getBufferStatus();
         * @see AbstractBufferIO::getBufferStatus();
         */
        BufferedOutput& operator <<(const char* s);

    private:

        AbstractBufferIO::Status appendInBuffer(const char* s, int l);

        File m_file;
        char* m_buffer;
        int m_buffLen;
        int m_lastIndex;

};

#endif


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

#ifndef FRAME_H__
#define FRAME_H__

#include <System/Types.h>

#include <string.h>

#include <iostream>
using namespace std;

/**
 * @brief Frame class. Allows High level data transmission over network
 */
class Frame
{
    public:

        /**
         * @brief Constructor
         * @param size initial memory allocation (default is 1024 bytes)
         */
        Frame(uint32 size = 1024);

        /**
         * @brief Destructor
         */
        ~Frame();

        Frame& operator << (const bool& b);
        Frame& operator << (const int8& i);
        Frame& operator << (const int16& i);
        Frame& operator << (const int32& i);
        Frame& operator << (const uint8& i);
        Frame& operator << (const uint16& i);
        Frame& operator << (const uint32& i);
        Frame& operator << (const char* c);
        Frame& operator << (const float& f);
        Frame& operator << (const double& d);
        Frame& operator << (const string& s);

        Frame& operator >> (bool& b);
        Frame& operator >> (int8& i);
        Frame& operator >> (int16& i);
        Frame& operator >> (int32& i);
        Frame& operator >> (uint8& i);
        Frame& operator >> (uint16& i);
        Frame& operator >> (uint32& i);
        Frame& operator >> (char* c);
        Frame& operator >> (float& f);
        Frame& operator >> (double& d);
        Frame& operator >> (string& s);

        /**
         * @brief append data to the buffer
         * @param data the data to add
         * @param size the size of the data to add
         */
        void append(const void* data, size_t size);

        /**
         * @brief read data from the buffer. This method reads from the buffer.
         * @param data the data container
         * @param size the number of bytes to read
         * @return 0 is size bytes were successfully read.
         * 		   -1 otherwise
         */
        int read(void* data, size_t size);

        /**
         * @brief Sets the current buffer position indicator. A positive integer will move the indicator forward.
         * A negative integer will move it backward
         * @param pos the offset
         */
        void setPosition(const int32& pos);

        /**
         * @brief get the data buffer
         * @return the data buffer
         */
        char* getData();

    private:
        void reallocateDouble();

        char* m_contents;
        uint32 m_realSize;
        uint32 m_allocSize;
        int m_currentSeek;



};

#endif

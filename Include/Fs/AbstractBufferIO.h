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

#ifndef ABSTRACT_BUFFER_IO_H__
#define ABSTRACT_BUFFER_IO_H__

#include <errno.h>

#include <Fs/File.h>
#include <Fs/FileTypes.h>
class AbstractBufferIO
{
    public:
        /**
         * @brief Status of the buffer io
         */
        enum Status
        {
            /** Stream not ready **/
            NotReady,
            /** Done with no errors **/
            Done,
            /** Error while reading/writing **/
            Error,
            /** File not found **/
            FileNotFound,
            /** File not openned **/
            NotOpen
        };

        /**
         * @brief get the buffer status
         * @return AbstractBufferIO::Status
         * @see AbstractBufferIO::Status
         */
        AbstractBufferIO::Status getStatus();
    protected:
        Status m_status;

};

#endif

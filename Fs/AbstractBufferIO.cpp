/**
 *
 *       @file  AbstractBufferIO.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/22/2011 18:43:28
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/AbstractBufferIO.h>

AbstractBufferIO::Status AbstractBufferIO::getBufferStatus() {
    if(m_status != Done) {
        return m_status;
    }

    if(errno == EAGAIN)
        return NotReady;

    switch (errno) {
    case EBADF:
        return FileNotFound;

    case EIO:
        return Error;

    case ETIMEDOUT:
        return Error;

    default:
        return Error;
    };
}

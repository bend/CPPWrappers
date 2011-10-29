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


#ifndef MUTEX_H__
#define MUTEX_H__
#include <pthread.h>
class Mutex
{
    public:
        /**
         * @brief Constructor
         */
        Mutex();

        /**
         * @brief locks the mutex.  If the mutex is already locked, the calling thread will block until the mutex becomes available.
         * @return  If successful, lock() will return zero.  Otherwise, an error number will be returned to indicate the error.
         */
        int lock();

        /**
         * @brief The trylock() method locks mutex.  If the mutex is already locked, trylock() will not block waiting for the mutex, but will return an error condition
         * @return  If successful, trylock() will return zero.  Otherwise, an error number will be returned to indicate the error.
         */
        int tryLock();

        /**
         * @brief  If the current thread holds the lock on mutex, then the unlock() function unlocks mutex.
         * Calling unlock() with a mutex that the calling thread does not hold will result in undefined behavior.
         * @return  If successful, unlock() will return zero.  Otherwise, an error number will be returned to indicate the error.
         */
        int unlock();

        /**
         * @brief The destroy() method frees the resources allocated for mutex.
         * @return  If successful, destroy() will return zero.  Otherwise, an error number will be returned to indicate the error.
         */
        int destroy();

    private:
        pthread_mutex_t* m_mutex;

};

#endif

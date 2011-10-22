/**
 *
 *       @file  Mutex.h

 *      @brief  Pthread_mutex wrapper
 *
 *    @version  1.0
 *       @date  10/11/2011 13:40:46
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
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

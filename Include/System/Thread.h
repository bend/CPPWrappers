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

#ifndef THREAD_H__
#define THREAD_H__

#include <pthread.h>

class Thread
{
    public:
        /**
         * @brief starts the thread and executes the run method
         * @return 0 if success, -1 otherwise
         */
        int start();

        /**
         * @brief Causes the calling thread to wait for the termination of the specified
         * thread
         */
        void* join();

        /**
         * @brief Used to indicate to the implementation that storage for the
         * thread can be reclaimed when the thread terminates.
         * If thread has not terminated, detach() will not cause it to terminate
         * @return 0 if success and a value < 0 if failure
         */
        int detach();

        /**
         * @brief tests if the 2 threads are the same
         * @return true is equals, false otherwise
         */
        int equals(Thread* t);

        /**
         * @brief The exit method terminates the calling thread
         */
        void exit(void* value_ptr);

        /**
         * @brief The cancel() method requests that thread be canceled.
         * The target thread's cancelability state and type determines when
         * the cancellation takes effect.
         * When the cancellation is acted on, the cancellation cleanup handlers
         * for thread are called.  When the last cancellation cleanup handler returns, the
         * thread-specific data destructor functions will be called for thread.
         * When the last destructor function returns, thread will be terminated.a
         */
        int cancel();

        /**
         * @brief returns the pthread
         */
        pthread_t getThread();
    protected:
        virtual void run() = 0;

    private:
        static void* go(void* obj);
        pthread_t m_thread;

};

#endif

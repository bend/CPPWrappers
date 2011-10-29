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

#include <System/Thread.h>
#include <iostream>
using namespace std;

int Thread::start()
{
    if (pthread_create( &m_thread, 0, &Thread::go, this))
    {
        cerr << "Thread::start could not start thread" << endl;
        return -1;
    }

    return 0;
}

void* Thread::go(void* obj)
{
    reinterpret_cast<Thread*>(obj)->run();
    return NULL;
}

void* Thread::join()
{
    void* ret;
    pthread_join(m_thread, &ret);
    return ret;
}

pthread_t Thread::getThread()
{
    return m_thread;
}

int Thread::detach()
{
    return pthread_detach(m_thread);
}

int Thread::equals(Thread* t)
{
    return pthread_equal(m_thread, t->getThread());
}

void Thread::exit(void* value_ptr)
{
    pthread_exit(value_ptr);
}

int Thread::cancel()
{
    return pthread_cancel(m_thread);
}


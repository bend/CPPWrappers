/**
 *
 *       	@file  Thread.h
 *
 *    		@brief  A C++ Thread Wrapper for the pthread lib
 *         @author  Ben D. (BD), dbapps2@gmail.com
 *
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


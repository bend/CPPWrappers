/*
 * =====================================================================================
 *
 *       Filename:  Thread.cpp
 *
 *    Description:  A C++ Thread Wrapper for the pthread lib
 *
 *        Version:  1.0
 *        Created:  07.06.2011 21:09:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */

#include <System/Thread.h>

#include <iostream>
using namespace std;

int Thread::start() {
    if (pthread_create( &m_thread, 0, &Thread::go, this))
        cerr << "Thread::start could not start thread" << endl;
    return 0;
}

void* Thread::go(void* obj){
	reinterpret_cast<Thread *>(obj)->run();
	return NULL;
}

void *Thread::join(Thread *thread) {
    void *ret;
    pthread_join(thread->getThread(), &ret);
    return ret;
}

pthread_t Thread::getThread() {
    return m_thread;
}

int Thread::detach() {
    return pthread_detach(m_thread);
}

int Thread::equals(Thread* t) {
    return pthread_equal(m_thread, t->getThread());
}

void Thread::exit(void* value_ptr) {
    pthread_exit(value_ptr);
}

int Thread::cancel() {
    return pthread_cancel(m_thread);
}


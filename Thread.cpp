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

#include "Thread.h"

#include <iostream>
using namespace std;

int Thread::start(void *(*function)(void *)){
	if (pthread_create( &(this->pthread), NULL,function,(void *)(this)))
		cerr<<"Thread::start could not start thread"<<endl;
	return 0;
}


void *Thread::join(Thread *thread){
	void *ret;
	pthread_join(thread->getThread(),&ret);
	return ret;
}


pthread_t Thread::getThread(){
	return this->pthread;
}

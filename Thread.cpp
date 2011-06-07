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

pthread_t Thread::start(void *(*function)(void *))
{
  pthread_t pthread;
  if (pthread_create( &pthread, NULL,function,(void *)(this)))
    cerr<<"Thread::start could not start thread"<<endl;
  return pthread;
}


void *Thread::join(pthread_t pthread)
{
  void *ret;
  pthread_join( pthread,&ret);
  return ret;
}

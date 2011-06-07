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

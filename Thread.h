#ifndef Thread_H
#define Thread_H

#include <pthread.h>

class Thread
{
public:
  pthread_t start(void *(*function)(void *));
  
  void *join(pthread_t pthread);
};

#endif

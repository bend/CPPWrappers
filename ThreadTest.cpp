#include "Thread.h"

#include <iostream>
using namespace std;

class Test: public Thread
{
public:
  Test(){ 
	  pthread_mutex_init(&mutex,NULL);
  }

  ~Test(){ 
	  pthread_mutex_destroy(&mutex);
  }

  void setString(string str){ 
	  s=str;
  }

  friend void *testThread1(void *t);
  friend void *testThread2(void *t);

private:
  string s;
  pthread_mutex_t mutex;
};

void *testThread1(void *t)
{
  Test *me=(Test *)t;

  pthread_mutex_lock( &(me->mutex) );
  for (int i=0;i<3;i++){ 
	  cout<<i<<":"<<me->s<<" ";cout.flush();sleep(1);
  }
  cout<<endl;
  pthread_mutex_unlock( &(me->mutex) );
  
  static int ret=1;
  return &ret;
}

void *testThread2(void *t)
{
  Test *me=(Test *)t;
  
  pthread_mutex_lock( &(me->mutex) );
  for (int i=0;i<3;i++){
	  cout<<i<<":"<<me->s<<" ";cout.flush();sleep(1);
  }
  cout<<endl;
  pthread_mutex_unlock( &(me->mutex) );

  static int ret=2;
  return &ret;
}

int main()
{
  Test t;
  t.setString("SomeText");
  
  cout<<"Thread1 starting"<<endl;
  cout<<"Thread2 starting"<<endl;
  pthread_t pthread1=t.start(testThread1);
  pthread_t pthread2=t.start(testThread2);
  
  // threads are now running

  void *ret1=t.join(pthread1);
  void *ret2=t.join(pthread2);
  cout<<"Thread1 joined with return value: "<<*((int *)ret1)<<endl;
  cout<<"Thread2 joined with return value: "<<*((int *)ret2)<<endl;
}

#include "Semaphore.h"
#include "Thread.h"
#include <iostream>
using namespace std;

Semaphore *sem;

void* Thread1(void* t){
	int i=0;
	while(i<10){
		sem->wait();
		cout<<"Thread 2 got lock"<<endl;
		sleep(1);
		sem->post();
		i++;
	}
	return NULL;
}

void* Thread2(void* t){
	int i=0;
	while(i<10){
		sem->wait();
		cout<<"Thread 1 got lock"<<endl;
		sleep(1);
		sem->post();
		i++;
	}
	return 0;
}


int main(){
	char* name ="test_sem";
	sem = new Semaphore(name,1);
	Thread tr1;

	pthread_t t1 = tr1.start(Thread1);
	pthread_t t2 = tr1.start(Thread2);
	tr1.join(t1);
	tr1.join(t2);
	return 1;
}

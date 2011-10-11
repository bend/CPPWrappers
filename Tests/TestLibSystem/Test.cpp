#include <System/Thread.h>
#include <System/Semaphore.h>
#include <iostream>
using namespace std;

class Test: public Thread {
public:
    Test(Semaphore *sem, Semaphore *mutex): m_sem(sem), m_mutex(mutex) {
    }

    void run() {
        while(1) {
			m_mutex->wait();
            m_sem->wait();
			m_mutex->post();
            cout << "Thread 1" << endl;
            m_sem->post();
        }
    }

private:
    Semaphore *m_sem;
	Semaphore *m_mutex;


};

class Test2: public Thread {
public:
    Test2(Semaphore *sem, Semaphore *mutex): m_sem(sem), m_mutex(mutex) {
    }

    void run() {
        while(1) {
			m_mutex->wait();
            m_sem->wait();
			m_mutex->post();
            cout << "Thread 2" << endl;
            sleep(1);
            m_sem->post();
        }
    }

private:
    Semaphore *m_sem;
	Semaphore *m_mutex;

};
int main() {
    char name[] = "test_sem";
    char name2[] = "test_mutex";
    Semaphore *sem = new Semaphore(name, 1);
    Semaphore *mutex = new Semaphore(name2, 1);
    Test test(sem, mutex);
    Test2 test2(sem, mutex);
    test2.start();
    test.start();
    test.join();
    test2.join();
}

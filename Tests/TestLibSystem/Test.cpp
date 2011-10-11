#include <System/Thread.h>
#include <System/Semaphore.h>
#include <iostream>
using namespace std;

class Test: public Thread {
public:
    Test(Semaphore *sem): m_sem(sem) {
    }

    void run() {
        while(1) {
            m_sem->wait();
            cout << "Thread 1" << endl;
			sleep(5);
            m_sem->post();
			sleep(1);
        }
    }

private:
    Semaphore *m_sem;


};

class Test2: public Thread {
public:
    Test2(Semaphore *sem): m_sem(sem) {
    }

    void run() {
        while(1) {
            m_sem->wait();
            cout << "Thread 2" << endl;
            sleep(1);
            m_sem->post();
			sleep(1);
        }
    }

private:
    Semaphore *m_sem;

};
int main() {
    char name[] = "test_sem";
    Semaphore *sem = new Semaphore(name, 1);
    Test test(sem);
    Test2 test2(sem);
    test2.start();
    test.start();
    test.join();
    test2.join();
}

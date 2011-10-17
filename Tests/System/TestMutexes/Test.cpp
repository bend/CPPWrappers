#include <System/Thread.h>
#include <System/Mutex.h>
#include <iostream>
using namespace std;

class Producer: public Thread {
public:
    Producer(Mutex *m): m_mutex(m) {
    }

    void run() {
        while(1) {
            m_mutex->lock();
            cout << "Producing item" << endl;
            sleep(2);
            m_mutex->unlock();
        }
    }

private:
    Mutex *m_mutex;


};

class Consumer: public Thread {
public:
    Consumer(Mutex *m): m_mutex(m) {
    }

    void run() {
        while(1) {
            m_mutex->lock();
            cout << "Consuming item" << endl;
            m_mutex->unlock();
        }
    }

private:
    Mutex *m_mutex;

};
int main() {
    Mutex *m = new Mutex;
    Producer p(m);
    Consumer c(m);
    p.start();
    c.start();
    p.join();
    c.join();
}

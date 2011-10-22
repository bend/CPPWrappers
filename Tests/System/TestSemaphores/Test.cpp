#include <System/Thread.h>
#include <System/Semaphore.h>
#include <iostream>
using namespace std;

class Producer: public Thread
{
    public:
        Producer(Semaphore* can_produce, Semaphore* can_consume): m_canConsume(can_consume), m_canProduce(can_produce)
        {
        }

        void run()
        {
            while (1)
            {
                m_canProduce->wait();
                cout << "Producing item" << endl;
                m_canConsume->post();
            }
        }

    private:
        Semaphore* m_canConsume;
        Semaphore* m_canProduce;


};

class Consumer: public Thread
{
    public:
        Consumer(Semaphore* can_produce, Semaphore* can_consume): m_canConsume(can_consume), m_canProduce(can_produce)
        {
        }

        void run()
        {
            while (1)
            {
                m_canConsume->wait();
                cout << "Consuming item" << endl;
                sleep(2);
                m_canProduce->post();
            }
        }

    private:
        Semaphore* m_canConsume;
        Semaphore* m_canProduce;

};
int main()
{
    char name[] = "/can_produce";
    char name2[] = "/can_consume";
    Semaphore* canProduce = new Semaphore(name, 10);
    Semaphore* canConsume = new Semaphore(name2, 0);
    Producer p(canProduce, canConsume);
    Consumer c(canProduce, canConsume);
    p.start();
    c.start();
    p.join();
    c.join();
}

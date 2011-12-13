/*
 *   Copyright © Ben D.
 *   dbapps2@gmail.com
 *
 *   This is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QUEUE_H__
#define QUEUE_H__

#include <Ds/Node.h>
#include <Ds/Exception.h>

/*
 * Queue implementation
 */
template<class E>
class Queue
{

    public:
        Queue();
        void enqueue(const E& elem);
        E& dequeue();
        E& front();
        int getSize();
        bool isEmpty();

    private:
        Node<E> *m_head;
        Node<E> *m_tail;
        int m_size;
};


template <class E> Queue<E>::Queue()
{
    m_size = 0;
    m_head = 0;
    m_tail = 0;
}

template <class E> void Queue<E>::enqueue(const E& elem)
{
    Node<E> *n = new Node<E>(elem, 0);

    if (m_tail != 0)
        m_tail->setNext(n);

    else
    {
        m_tail = n;
        m_head = m_tail;
    }

    ++m_size;
}

template <class E> E& Queue<E>::dequeue()
{
    if (m_size == 0)
        throw EmptyQueueException();

    E e = m_head->getElem();
    m_head->setNext(m_head->getNext());
    m_head = m_head->getNext();
    --m_size;
    return e;
}

template <class E> E& Queue<E>::front()
{
    if (m_size == 0) throw EmptyQueueException();

    return m_head->getElem();
}

template <class E> int Queue<E>::getSize()
{
    return m_size;
}

template <class E> bool Queue<E>::isEmpty()
{
    return m_size == 0;
}
#endif

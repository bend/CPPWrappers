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

#ifndef STACK_H__
#define STACK_H__
#include <Ds/Node.h>
#include <Ds/Exception.h>

template <class E>

class Stack
{

    public:
        Stack();
        void push(E elem);
        E pop();
        int getSize();
        E top();
        bool isEmpty();

    private:
        Node<E> *m_head;
        int m_size;
};

template <class E> Stack<E>::Stack()
{
    m_size = 0;
    m_head = 0;
}

template <class E> void Stack<E>::push(E elem)
{
    Node<E> *n = new Node<E>(elem, m_head);
    m_head = n;
    ++m_size;
}

template <class E> E Stack<E>::pop()
{
    if (m_size == 0) throw EmptyStackException();

    E e = m_head->getElem();
    m_head = m_head->getNext();
    --m_size;
    return e;
}

template <class E> E Stack<E>::top()
{
    if (m_size == 0) throw EmptyStackException();

    return m_head->getElem();
}

template <class E> int Stack<E>::getSize()
{
    return m_size;
}

template <class E> bool Stack<E>::isEmpty()
{
    return m_size == 0;
}


#endif


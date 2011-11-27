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

#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include <iostream>
using namespace std;

#include <Ds/Node.h>


template <class E>
class LinkedList {
public:
    inline LinkedList(): m_head(0), m_tail(0), m_size(0) {
    }

    inline void insertTop(const E &elem) {
        Node<E> *n = new Node<E>(elem, m_head);
        m_head = n;
        ++m_size;

        if (m_size == 1)
            m_tail = n;
    }

    inline void insertLast(E elem) {
        Node<E> *n = new Node<E>(elem, 0);

        if(m_tail != 0) {
            m_tail->setNext(n);
            m_tail = m_tail->getNext();
        } else {
            m_tail = n;
            m_head = m_tail;
        }

        ++m_size;
    }

    inline int getSize() {
        return m_size;
    }

    inline E& getHead() {
        if(m_size == 0) throw string("Empty List");

        return m_head->getElem();
    }

    inline E& getTail() {
        if(m_size == 0) throw string("Empty List");

        return m_tail->getElem();
    }

    inline E removeFirst() {
        if(m_size == 0) throw string("Empty List");

        E e = m_head->getElem();
        m_head = m_head->getNext();
        --m_size;
        return e;
    }

    inline E removeLast() {
        if(m_size == 0) throw string("Empty List");

        E e = m_tail->getElem();
        m_tail->setElem(0);
        Node<E> *t = m_head;

        while(t->getNext()->getElem() != 0)
            t = t->getNext();

        m_tail = t;
        t->setNext(0);
        --m_size;
        return e;
    }

    inline E* toArray() {
        E *tab = new E[m_size + 1];
        Node<E> *temp = m_head;
        int i = 0;

        while(temp != NULL) {
            tab[i++] = temp->getElem();
            temp = temp->getNext();
        }

        return tab;
    }


private:
    Node<E> *m_head;
    Node<E> *m_tail;
    int m_size;

};
#endif

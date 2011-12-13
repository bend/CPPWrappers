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
#include <Ds/Exception.h>

/**
 * Reprensents the single linked list structure
 */
template <class E>
class LinkedList
{
    public:


        /**
         * @brief Constructor
         */
        LinkedList();

        /**
         * @brief inserts at the beginning of the list
         * @param elem the element to insert
         */
        void insertTop(const E& elem);

        /**
         * @brief inserts at the end of the list
         * @param elem the element to insert
         */
        void insertLast(E elem);

        /**
         * @brief returns the size of the list
         * @return the size
         */
        int getSize();

        /**
         * @brief return the element stored at the beginning of the list
         * @return a reference to the element
         * @throw EmptyListException if the list is empty
         */
        E& getHead();

        /**
         * @brief return the element stored at the end of the list
         * @return a reference to the element
         * @throw EmptyListException if the list is empty
         */
        E& getTail();

        /**
         * @brief removes the first element
         * @return the removed element
         * @throw EmptyListException if the list is empty
         */
        E removeFirst();

        /**
         * @brief removes the last element
         * @return the removed element
         * @throw EmptyListException if the list is empty
         */
        E removeLast();

        /**
         * @brief transforms the list to an array
         * @return an array of the size of the list
         */
        E* toArray();


    private:
        Node<E> *m_head;
        Node<E> *m_tail;
        int m_size;

};


template <class E>
LinkedList<E>::LinkedList(): m_head(0), m_tail(0), m_size(0)
{
}

template <class E>
void LinkedList<E>::insertTop(const E& elem)
{
    Node<E> *n = new Node<E>(elem, m_head);
    m_head = n;
    ++m_size;

    if (m_size == 1)
        m_tail = n;
}
template<class E>
void LinkedList<E>::insertLast(E elem)
{
    Node<E> *n = new Node<E>(elem, 0);

    if (m_tail != 0)
    {
        m_tail->setNext(n);
        m_tail = m_tail->getNext();
    }

    else
    {
        m_tail = n;
        m_head = m_tail;
    }

    ++m_size;
}
template<class E>
int LinkedList<E>::getSize()
{
    return m_size;
}

template <class E>
E& LinkedList<E>::getHead()
{
    if (m_size == 0) throw EmptyListException();

    return m_head->getElem();
}

template <class E>
E& LinkedList<E>::getTail()
{
    if (m_size == 0) throw EmptyListException();

    return m_tail->getElem();
}

template<class E>
E LinkedList<E>::removeFirst()
{
    if (m_size == 0) throw EmptyListException();

    E e = m_head->getElem();
    Node<E> *next = m_head->getNext();
    delete m_head;
    m_head = next;
    --m_size;
    return e;
}

template<class E>
E LinkedList<E>::removeLast()
{
    if (m_size == 0) throw EmptyListException();

    if (m_size == 1 )
    {
        E e = m_tail->getElem();
        delete m_tail;
        --m_size;
        return e;
    }

    E e = m_tail->getElem();
    m_tail->setElem(0);
    Node<E> *t = m_head;

    while (t->getNext()->getElem() != 0)
        t = t->getNext();

    m_tail = t;
    t->setNext(0);
    --m_size;
    return e;
}

template <class E>
E* LinkedList<E>::toArray()
{
    E* tab = new E[m_size + 1];
    Node<E> *temp = m_head;
    int i = 0;

    while (temp != NULL)
    {
        tab[i++] = temp->getElem();
        temp = temp->getNext();
    }

    return tab;
}

#endif

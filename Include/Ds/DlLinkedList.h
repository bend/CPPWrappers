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

#ifndef DL_LINKEDLIST_H__
#define DL_LINKEDLIST_H__

#include <iostream>
using namespace std;

#include <Ds/DlNode.h>
#include <Ds/Exception.h>

/**
 * Double linked list
 */
template <class E>
class DlLinkedList
{
    public:

        /**
         * @brief Constructor
         */
        DlLinkedList();

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

        /**
         * @brief get the first node of the list. This method returns the node and not only the element
         * @return a pointer to the first node
         */
        DlNode<E>* getFirst();

        /**
         * @brief get the last node of the list. This method returns the node and not only the element
         * @return a pointer to the last node
         */
        DlNode<E>* getLast();

    private:
        DlNode<E> *m_head;
        DlNode<E> *m_tail;
        int m_size;

};


template <class E>
DlLinkedList<E>::DlLinkedList(): m_head(0), m_tail(0), m_size(0)
{
}

template <class E>
void DlLinkedList<E>::insertTop(const E& elem)
{
    DlNode<E> *n = new DlNode<E>(elem);

    if (m_head != 0)
        n->setNext(m_head);

    m_head = n;
    ++m_size;

    if (m_size == 1)
        m_tail = n;
}

template<class E>
void DlLinkedList<E>::insertLast(E elem)
{
    DlNode<E> *n = new DlNode<E>(elem);

    if (m_tail != 0)
    {
        m_tail->setNext(n);
        m_tail = (DlNode<E>*)m_tail->getNext();
    }

    else
    {
        m_tail = n;
        m_head = m_tail;
    }

    ++m_size;
}
template<class E>
int DlLinkedList<E>::getSize()
{
    return m_size;
}

template <class E>
E& DlLinkedList<E>::getHead()
{
    if (m_size == 0) throw EmptyListException();

    return m_head->getElem();
}

template <class E>
E& DlLinkedList<E>::getTail()
{
    if (m_size == 0) throw EmptyListException();

    return m_tail->getElem();
}

template <class E>
DlNode<E>* DlLinkedList<E>::getFirst()
{
    return m_head;
}

template <class E>
DlNode<E>* DlLinkedList<E>::getLast()
{
    return m_tail;
}

template<class E>
E DlLinkedList<E>::removeFirst()
{
    if (m_size == 0) throw EmptyListException();

    E e = m_head->getElem();

    if (m_head->getNext() != 0)
    {
        DlNode<E> *next = (DlNode<E>*)m_head->getNext();
        delete m_head;
        m_head = next;
    }

    else delete m_head;

    --m_size;
    return e;
}

template<class E>
E DlLinkedList<E>::removeLast()
{
    if (m_size == 0) throw EmptyListException();

    E e = m_tail->getElem();
    DlNode<E> *prev = m_tail->getPrevious();
    delete m_tail;
    m_tail = prev;
    --m_size;
    return e;
}

template <class E>
E* DlLinkedList<E>::toArray()
{
    E* tab = new E[m_size + 1];
    DlNode<E> *temp = m_head;
    int i = 0;

    while (temp != NULL)
    {
        tab[i++] = temp->getElem();
        temp = (DlNode<E>*)temp->getNext();
    }

    return tab;
}

#endif

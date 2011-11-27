
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

#ifndef DL_NODE_H__
#define DL_NODE_H__

#include <Ds/Node.h>

/**
 * Double linked node class
 */
template <class T>
class DlNode : public Node<T>
{
    public:

        /**
         * @brief Constructor
         * @param e the element to store in the node
         */
        DlNode(const T& e);

        /**
         * @brief Constructor
         * @param e the element to store in the node
         * @param prev the previous node
         * @param next the next node
         */
        DlNode(const T& e, DlNode<T> *prev, DlNode<T> *next);

        /**
         * @brief sets the next node
         * @param next the next node
         */
        void setNext(DlNode<T> *next);

        /**
         * @brief get the next element
         * @return DlNode*
         */
        DlNode<T>* getNext();

        /**
         * @brief sets the previous node
         * @param prev the previous node
         */
        void setPrevious(DlNode<T> *prev);

        /**
         * @brief gets the previous node
         * @return a pointer to the previous node or 0 (NULL) if there is no previous node
         */
        DlNode* getPrevious();

    private:
        DlNode<T> *m_prev;

};
template <class T>
DlNode<T>::DlNode(const T& e) : Node<T>(e),
    m_prev(0)
{
}

template <class T>
DlNode<T>::DlNode(const T& e, DlNode<T> *prev, DlNode<T> *next): Node<T>(e)
{
    this->setNext(next);
    this->setPrevious(prev);
}

template <class T>
void DlNode<T>::setNext(DlNode<T> *next)
{
    Node<T>::setNext(next);
    next->setPrevious(this);
}

template <class T>
void DlNode<T>::setPrevious(DlNode<T> *prev)
{
    m_prev = prev;
    prev->m_next = this;
}

template <class T>
DlNode<T>* DlNode<T>::getPrevious()
{
    if (m_prev == 0)
        return 0;

    return m_prev;
}

template <class T>
DlNode<T>* DlNode<T>::getNext()
{
    return (DlNode<T>*)(Node<T>::getNext());
}

#endif



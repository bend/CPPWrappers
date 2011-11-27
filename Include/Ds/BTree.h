
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

#ifndef BTREE_H__
#define BTREE_H__
/**
 * Represents a binary tree structure
 */
template <class T>
class BTree
{
    public:

        BTree(const T& elem);

        BTree(const T& elem, BTree<T> *left, BTree<T> *right);

        void setLeft(BTree<T> * l);
        void setRight(BTree<T> *r);
        void setParent(BTree<T> *r);

        void setElem(const T& elem);

        BTree<T>* getLeft();

        BTree<T>* getRight();

        BTree<T>* getParent();

        int getSize();

        T& getElem();
    protected:
        BTree();

    private:
        BTree<T> *m_left;
        BTree<T> *m_right;
        BTree<T> *m_parent;
        T m_elem;
        int m_size;

};

template <class T>
BTree<T>::BTree(const T& elem): m_right(0), m_left(0), m_parent(0), m_elem(elem)
{
    m_size = 1;
}

template <class T>
BTree<T>::BTree(): m_right(0), m_left(0), m_parent(0)
{
    m_size = 0;
}

template <class T>
BTree<T>::BTree(const T& elem, BTree<T> *left, BTree<T> *right):
    m_elem(elem),
    m_left(left),
    m_right(right),
    m_size(1)
{
    m_left->setParent(this);
    m_right->setParent(this);
}

template <class T>
void BTree<T>::setLeft(BTree<T> * l)
{
    m_left = l;
    m_left->setParent(this);
}

template <class T>
void BTree<T>::setRight(BTree<T> *r)
{
    m_right = r;
    m_right->setParent(this);
}

template <class T>
void BTree<T>::setParent(BTree<T> *r)
{
    m_parent = r;
}

template <class T>
void BTree<T>::setElem(const T& elem)
{
    m_size = 1;
    m_elem = elem;
}

template <class T>
BTree<T>* BTree<T>::getLeft()
{
    return m_left;
}

template <class T>
BTree<T>* BTree<T>::getRight()
{
    return m_right;
}

template <class T>
BTree<T>* BTree<T>::getParent()
{
    return m_parent;
}

template <class T>
T& BTree<T>::getElem()
{
    return m_elem;
}

template <class T>
int BTree<T>::getSize()
{
    int size = m_size;

    if (m_left != 0)
        size += m_left->getSize();

    if (m_right != 0)
        size += m_right->getSize();

    return size;
}
#endif

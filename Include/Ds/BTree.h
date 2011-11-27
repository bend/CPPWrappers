
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

        /**
         * @brief Constructor
         * @param elem the element to store at the root
         */
        BTree(const T& elem);
        
        /**
         * @brief Constructor
         * @param elem the element to store at the root
         * @param left the left child
         * @param right the right child
         */
        BTree(const T& elem, BTree<T> *left, BTree<T> *right);
        
        /**
         * @brief set the left child
         * @param l the child to set
         */
        void setLeft(BTree<T> * l);

        /**
         * @brief set the right child
         * @param r the right child to set
         */
        void setRight(BTree<T> *r);

        /**
         * @brief sets the parent
         * @param r the parent
         */
        void setParent(BTree<T> *r);
        
        /**
         * @brief sets the element in the node
         * @param elem the elem to store
         */
        void setElem(const T& elem);
        
        /**
         * @brief get the left child
         * @return a pointer to the left child tree
         */
        BTree<T>* getLeft();
        
        /**
         * @brief get the right child
         * @return a pointer to the right child
         */
        BTree<T>* getRight();
        
        /**
         * @brief get the parent of the node
         * @return a pointer to the parent tree
         */
        BTree<T>* getParent();
        
        /**
         * @brief calculates the tree size
         * @return the size of the tree
         */
        int getSize();
        
        /**
         * @brief get the element stored in the current node
         * @return a reference to this element
         */
        T& getElem();

    protected:
        
        /**
         * Empty constructor
         */
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


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
class BTree{
    public:
        inline BTree(const T& elem): m_elem(elem){
        }
        
        inline BTree(const T& elem, BTree<T> *left, BTree<T> *right):
            m_elem(elem), 
            m_left(left),
            m_right(right)
        {
            m_left->setParent(this);
            m_right->setParent(this);
        }

        inline void setLeft(BTree<T> * l){
            m_left = l;
            m_left->setParent(this);
        }

        inline void setRight(BTree<T> *r){
            m_right = r;
            m_right->setParent(this);
        }

        inline void setParent(BTree<T> *r){
            m_parent = r;
        }

        inline void setElem(const T& elem){
            m_elem = elem;
        }

        inline BTree<T>* getLeft(){
            return m_left;
        }

        inline BTree<T>* getRight(){
            return m_right;
        }

        inline BTree<T>* getParent(){
            return m_parent;
        }
        
        inline T& getElem(){
            return m_elem;
        }

    private:
        BTree<T> *m_left;
        BTree<T> *m_right;
        BTree<T> *m_parent;
        T& m_elem;

};

#endif

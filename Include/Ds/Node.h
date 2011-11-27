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

#ifndef NODE_H__
#define NODE_H__

/**
 * Single linked node class
 */
template <class T>
class Node {

public:
    /**
     * @brief Constructor
     * @param e the element to store in the node
     */
    inline Node(const T &e): m_elem(e), m_next(0) {
    }
    
    /**
     * @brief Constructor
     * @param elem the element to store in the node
     * @param next the next element
     */
    inline Node(const T& elem, Node<T> *next):
        m_elem(elem),
        m_next(next)
    {
    }
    
    /**
     * @brief Sets the next node
     * @param next the next node to set
     */
    inline void setNext(Node<T> *next) {
        this->m_next = next;
    }
    
    /**
     * @brief sets the element in the node
     * @param elem the element to store in the node
     */
    inline void setElem(const T& elem) {
        this->m_elem = elem;
    }
    
    /**
     * @brief returns the element stored in the node
     * The element cannot be null
     * @return a reference to the element
     */
    inline T& getElem() {
        return m_elem;
    }
    
    /**
     * @brief get the next node
     * @return a pointer to the node or 0 (NULL) if there is no next node
     */
    inline Node<T>* getNext() {
        if(m_next == 0)
            return 0;
        return m_next;
    }
    
    /**
     * @brief redefinition of the == operation
     * the comparison is only done on the element stored in the node
     */
    inline bool operator ==(Node<T>* n){
        return this.m_elem = n->getElem();
    }

protected:
    /**
     * The next node
     */
    Node<T> *m_next;

    /**
     * The element stored in the node
     */
    T m_elem;
};

#endif

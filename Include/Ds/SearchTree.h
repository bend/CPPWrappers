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

#ifndef SEARCH_TREE_H__
#define SEARCH_TREE_H__
#include <Ds/Pair.h>
#include <Ds/BTree.h>
#include <vector>
using namespace std;

/**
 * Reprensents a search tree structure
 */
template <class K, class V>
class SearchTree : private BTree<Pair<K, V> >
{
    public:
        /**
         * @brief Constructor
         */
        SearchTree();

        /**
         * @brief Constructor
         * @param k the key
         * @param v the value
         */
        SearchTree(const K& k, const V& v);

        /**
         * @brief inserts the pair key, value in the tree
         * A Pair object is with key key and value val and inserted in the tree at the correct position
         * @param key the key
         * @param val the value
         */
        void insert(const K& key, const V& val);

        /**
         * @brief searches for the key in the tree
         * @param key the key to search
         * @return true if the element is found, false otherwise
         */
        bool contains(const K& key);

        /**
         * @brief removes the first element with the key key
         * @param key the key of the element to remove
         * @return true if removed, false otherwise
         */
        bool remove(const K& key);

        /**
         * @brief removes all the occurences of the element with key key
         * @param key the key of the elements to remove
         * @return the number of nodes removed
         */
        int removeAll(const K& key);

        /**
         * @brief counts the number ot occurences of elements with key key
         * @param key the key
         * @return the number of elements with key key found
         */
        int count(const K& key);

        /**
         * @brief returns the first occurence of element with key key
         * @param key the key of the element searched
         * @return a reference to the value with key key
         */
        V& get(const K& key);

        /**
         * @brief returns all occurences of the elements with key key
         * @param key the key of the elements searched
         * @return a vector<V> containing all the value with key key
         */
        vector<V> getAll(const K& key);

        /**
         * @brief returns the elements in increasing order
         * @return a vector<Pair<K, V> > containing all the pairs(key, value) contained in the tree in increasing order
         */
        vector<Pair<K, V> > inorder();

};

template <class K, class V>
SearchTree<K, V>::SearchTree(const K& key, const V& val): BTree<Pair<K, V> >(Pair<K, V>(key, val))
{
}

template <class K, class V>
SearchTree<K, V>::SearchTree(): BTree<Pair<K, V> >()
{
}


template <class K, class V>
void SearchTree<K, V>::insert(const K& key, const V& val)
{
    Pair<K, V> p(key, val);

    if (this->getSize() == 0)
        this->setElem(p);

    else if (p < this->getElem())
        if (this->getLeft() == 0)
            this->setLeft(new BTree<Pair<K, V> >(Pair<K, V>(key, val)));

        else
            ((SearchTree<K, V>*)BTree<Pair<K, V> >::getLeft())->insert(key, val);

    else if (this->getRight() == 0)
        this->setRight(new BTree<Pair<K, V> >(Pair<K, V>(key, val)));

    else
        ((SearchTree<K, V>*)BTree<Pair<K, V> >::getRight())->insert(key, val);
}

template <class K, class V>
bool SearchTree<K, V>::contains(const K& key)
{
    Pair<K, V> p = this->getElem();

    if ( p == key)
        return true;

    else if (p < key)
    {
        if (this->getRight() == 0)
            return false;

        return ((SearchTree<K, V>*)this->getRight())->contains(key);
    }

    else
    {
        if (this->getLeft() == 0)
            return false;

        return ((SearchTree<K, V>*)this->getLeft())->contains(key);
    }

    return false;
}

template <class K, class V>
bool SearchTree<K, V>::remove(const K& key)
{
}

template <class K, class V>
int SearchTree<K, V>::count(const K& key)
{
    int count = 0;
    Pair<K, V> p = this->getElem();

    if ( p == key)
        ++count;

    if (p <= key)
    {
        if (this->getRight() != 0)
            count += ((SearchTree<K, V>*)this->getRight())->count(key);
    }

    else
    {
        if (this->getLeft() != 0)
            count += ((SearchTree<K, V>*)this->getLeft())->count(key);
    }

    return count;
}

template <class K, class V>
vector<Pair<K, V> > SearchTree<K, V>::inorder()
{
    vector<Pair<K, V> > res;

    if (this->getLeft() != 0)
    {
        vector<Pair<K, V> > v = ((SearchTree<K, V>*)this->getLeft())->inorder();
        res.insert(res.end(), v.begin(), v.end());
    }

    res.push_back(this->getElem());

    if (this->getRight() != 0)
    {
        vector<Pair<K, V> > v = ((SearchTree<K, V>*)this->getRight())->inorder();
        res.insert(res.end(), v.begin(), v.end());
    }

    return res;
}

template <class K, class V>
V& SearchTree<K, V>::get(const K& key)
{
    Pair<K, V> p = this->getElem();

    if ( p == key)
        return p.getValue();

    else if (p < key)
    {
        if (this->getRight() == 0)
            throw EmptyNodeException();

        return ((SearchTree<K, V>*)this->getRight())->get(key);
    }

    else
    {
        if (this->getLeft() == 0)
            throw EmptyNodeException();

        return ((SearchTree<K, V>*)this->getLeft())->get(key);
    }

    throw ElementNotFoundException();
}

template <class K, class V>
vector<V> SearchTree<K, V>::getAll(const K& key)
{
    vector<V> res;
    int count = 0;
    Pair<K, V> p = this->getElem();

    if ( p == key)
        res.push_back(p.getValue());

    if (p <= key)
    {
        if (this->getRight() != 0)
        {
            vector<V> v = ((SearchTree<K, V>*)this->getRight())->getAll(key);
            res.insert(res.end(), v.begin(), v.end());
        }
    }

    else
    {
        if (this->getLeft() != 0)
        {
            vector<V> v = ((SearchTree<K, V>*)this->getLeft())->getAll(key);
            res.insert(res.end(), v.begin(), v.end());
        }
    }

    return res;
}

#endif

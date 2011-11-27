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

template <class K, class V>
class SearchTree : public BTree<Pair<K, V> >
{
    public:
        SearchTree();
        SearchTree(const K& k, const V& v);

        void insert(const K& key, const V& val);

        bool contains(const K& key);

        bool remove(const K& key);
        
        int removeAll(const K& key);

        int count(const K & key);

        V& get(const K& key);

        vector<V> getAll(const K& key);

        vector<Pair<K,V> > inorder(); 

};

template <class K, class V>
SearchTree<K, V>::SearchTree(const K & key, const V& val):BTree<Pair<K, V> >(Pair<K, V>(key, val))
{
}

template <class K, class V>
SearchTree<K, V>::SearchTree():BTree<Pair<K, V> >()
{
}


template <class K, class V>
void SearchTree<K, V>::insert(const K& key, const V& val)
{
    Pair<K, V> p(key, val);
    if (this->getSize() == 0)
        this->setElem(p);
    else if(p < this->getElem())
        if(this->getLeft() == 0)
            this->setLeft(new BTree<Pair<K, V> >(Pair<K, V>(key, val)));
        else
            ((SearchTree<K, V>*)BTree<Pair<K, V> >::getLeft())->insert(key, val);
    else 
        if(this->getRight() == 0)
            this->setRight(new BTree<Pair<K, V> >(Pair<K, V>(key, val)));
        else
            ((SearchTree<K, V>*)BTree<Pair<K, V> >::getRight())->insert(key, val);
        
}

template <class K, class V>
bool SearchTree<K, V>::contains(const K& key)
{   
    Pair<K, V> p = this->getElem();
    if( p == key)
        return true;
    else if (p < key){
        if(this->getRight() == 0)
            return false;
        return ((SearchTree<K, V>*)this->getRight())->contains(key);
    }
    else{
        if(this->getLeft() == 0)
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
    if( p == key)
        ++count;

    if (p <= key){
        if(this->getRight() != 0)
            count+=((SearchTree<K, V>*)this->getRight())->count(key);
    }
    else{
        if(this->getLeft() != 0)
            count+=((SearchTree<K, V>*)this->getLeft())->count(key);
    }
    return count;
}

template <class K, class V>
vector<Pair<K,V> > SearchTree<K, V>::inorder()
{
    vector<Pair<K,V> > res;
    if(this->getLeft() != 0){
        vector<Pair<K,V> > v = ((SearchTree<K, V>*)this->getLeft())->inorder();
        res.insert(res.end(), v.begin(), v.end());
    }
    res.push_back(this->getElem());
    if(this->getRight() != 0){
        vector<Pair<K,V> > v = ((SearchTree<K, V>*)this->getRight())->inorder();
        res.insert(res.end(), v.begin(), v.end());
    }
    return res;
}

template <class K, class V>
V& SearchTree<K,V>::get(const K& key)
{
    Pair<K, V> p = this->getElem();
    if( p == key)
        return p.getValue();
    else if (p < key){
        if(this->getRight() == 0)
            throw string("Element not found");
        return ((SearchTree<K, V>*)this->getRight())->get(key);
    }
    else{
        if(this->getLeft() == 0)
            throw string("Element not found");
        return ((SearchTree<K, V>*)this->getLeft())->get(key);
    }
    throw string("Element not found");
}

template <class K, class V>
vector<V> SearchTree<K, V>::getAll(const K& key)
{
    vector<V> res;
    int count = 0;
    Pair<K, V> p = this->getElem();
    if( p == key)
       res.push_back(p.getValue());
    
    if (p <= key){
        if(this->getRight() != 0){
          vector<V> v = ((SearchTree<K, V>*)this->getRight())->getAll(key);
           res.insert(res.end(), v.begin(), v.end());
        }
    }
    else{
        if(this->getLeft() != 0){
           vector<V> v = ((SearchTree<K, V>*)this->getLeft())->getAll(key);
         res.insert(res.end(), v.begin(), v.end());
        }
    }
    return res;
}

#endif

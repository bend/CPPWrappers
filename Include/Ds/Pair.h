
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

#ifndef PAIR_H__
#define PAIR_H__ 

template <class K, class V>
class Pair{
    public:
        Pair();

        Pair(const K &key, const V &value);

        void setKey(const K& key);

        void setValue(const V& val);

        K& getKey();

        V& getValue();

        bool operator ==( Pair<K, V>& p);
        
        bool operator !=( Pair<K, V>& p);

        bool operator <( Pair<K, V>& p);

        bool operator >( Pair<K, V>& p);
 
        bool operator <=( Pair<K, V>& p);
        
        bool operator >=( Pair<K, V>& p);

        bool operator ==(const K& key);
        
        bool operator !=(const K& key);

        bool operator <( const K& key);

        bool operator >( const K& key);
 
        bool operator <=(const K& key);
        
        bool operator >=(const K& key);
    private:
        K m_key;
        V m_value;

};


template <class K, class V>
Pair<K, V>::Pair()
{
}

template <class K, class V>
Pair<K, V>::Pair(const K &key, const V &value):
    m_key(key),
    m_value(value)
{
}

template <class K, class V>
void Pair<K, V>::setKey(const K& key)
{
    m_key = key;
}

template <class K, class V>
void Pair<K, V>::setValue(const V& value)
{
    m_value = value;
}

template <class K, class V>
K& Pair<K, V>::getKey()
{
    return m_key;
}

template <class K, class V>
V& Pair<K, V>::getValue()
{
    return m_value;
}

template <class K, class V>
bool Pair<K, V>::operator == (Pair& p)
{
    return m_key == p.getKey();
}

    template <class K, class V>
bool Pair<K, V>::operator != (Pair& p)
{
    return m_key != p.getKey();
}

template <class K, class V>
bool Pair<K, V>::operator < (Pair& p)
{
    return m_key < p.getKey();
}

template <class K, class V>
bool Pair<K, V>::operator > (Pair& p)
{
    return m_key > p.getKey();
}

template <class K, class V>
bool Pair<K, V>::operator <= (Pair& p)
{
    return m_key <= p.getKey();
}

template <class K, class V>
bool Pair<K, V>::operator >= (Pair& p)
{
    return m_key >= p.getKey();
}


template <class K, class V>
bool Pair<K, V>::operator == (const K& k)
{
    return m_key == k;
}

    template <class K, class V>
bool Pair<K, V>::operator != (const K& k)
{
    return m_key != k;
}

template <class K, class V>
bool Pair<K, V>::operator < (const K& k)
{
    return m_key < k;
}

template <class K, class V>
bool Pair<K, V>::operator > (const K& k)
{
    return m_key > k;
}

template <class K, class V>
bool Pair<K, V>::operator <= (const K& k)
{
    return m_key <= k;
}

template <class K, class V>
bool Pair<K, V>::operator >= (const K& k)
{
    return m_key >= k;
}

#endif

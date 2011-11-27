/**
 *
 *       @file  Test.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/12/2011 19:04:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <iostream>
#include <assert.h>
#include <Ds/SearchTree.h>
#include <Ds/Pair.h>
using namespace std;
int main()
{
    SearchTree<int, int> tree;
    tree.insert(1, 1);
    tree.insert(3, 3);
    tree.insert(4, 4);
    tree.insert(4, 4);
    tree.insert(7, 7);
    tree.insert(6, 6);
    tree.insert(4, 4);
    tree.insert(4, 4);
    tree.insert(2, 2);
    assert(tree.contains(1) == true);
    assert(tree.contains(2) == true);
    assert(tree.contains(3) == true);
    assert(tree.contains(4) == true);
    assert(tree.contains(5) == false);
    assert(tree.contains(6) == true);
    vector<Pair<int, int> > v = tree.inorder();
    vector<Pair<int, int> > c;
    c.push_back(Pair<int, int>(1, 1));
    c.push_back(Pair<int, int>(2, 2));
    c.push_back(Pair<int, int>(3, 3));
    c.push_back(Pair<int, int>(4, 4));
    c.push_back(Pair<int, int>(4, 4));
    c.push_back(Pair<int, int>(4, 4));
    c.push_back(Pair<int, int>(4, 4));
    c.push_back(Pair<int, int>(6, 6));
    c.push_back(Pair<int, int>(7, 7));
    assert(tree.count(4) == 4);
    assert(tree.count(1) == 1);
    assert(tree.count(2) == 1);
    assert(tree.count(3) == 1);
    assert(tree.count(6) == 1);
    assert(tree.count(7) == 1);

    for (unsigned int i = 0; i < v.size(); i++)
        assert(c[i].getKey() == v[i].getKey());

    assert(tree.get(1) == 1);
    assert(tree.get(2) == 2);
    assert(tree.get(3) == 3);
    assert(tree.get(4) == 4);
    assert(tree.get(6) == 6);
    assert(tree.get(7) == 7);
    vector<int> s = tree.getAll(4);
    assert(s.size() == 4);
    assert(tree.getAll(1).size() == 1);
    cout << "All tests succeded" << endl;
    return 0;
}


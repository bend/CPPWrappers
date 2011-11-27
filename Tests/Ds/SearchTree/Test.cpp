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

    vector<int> v = tree.inorder();
    vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    c.push_back(4);
    c.push_back(4);
    c.push_back(4);
    c.push_back(6);
    c.push_back(7);

    assert(tree.count(4) == 4);
    assert(tree.count(1) == 1);
    assert(tree.count(2) == 1);
    assert(tree.count(3) == 1);
    assert(tree.count(6) == 1);
    assert(tree.count(7) == 1);

 //   for(unsigned int i=0; i<v.size(); i++)
   //     assert(c[i] == v[i]);

    cout << "All tests succeded" << endl;
    return 0;
}


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
#include <Ds/BTree.h>
using namespace std;
int main()
{
    BTree<int> tree(0);
    tree.setLeft(new BTree<int>(1));
    tree.setRight(new BTree<int>(2));
    assert(tree.getLeft()->getElem() == 1);
    assert(tree.getRight()->getElem() == 2);
    assert(tree.getRight()->getParent()->getElem() == tree.getElem());
    assert(tree.getLeft()->getParent()->getElem() == tree.getElem());
    assert(tree.getSize() == 3);
    assert(tree.getLeft()->getSize() == 1);
    assert(tree.getRight()->getSize() == 1);
    cout << "All tests succeded" << endl;
    return 0;
}


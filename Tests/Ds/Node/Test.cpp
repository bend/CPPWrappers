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
#include <Ds/Node.h>
#include <Ds/DlNode.h>
using namespace std;
int main()
{
    {
        Node<int> n1(1);
        Node<int> n2(2);
        Node<int> n4(3);
        Node<int> n3(3, &n4);
        n1.setNext(&n2);
        n2.setNext(&n3);
        assert(n1.getNext() == &n2);
        assert(n2.getNext() == &n3);
        assert(n1.getElem() == 1);
        assert(n2.getElem() == 2);
        assert(n3.getElem() == 3);
        assert(n1.getNext()->getElem() == 2);
        assert(n2.getNext()->getElem() == 3);
        assert(n3.getNext() == &n4);
    }
    {
        DlNode<int> n1(1);
        DlNode<int> n3(3);
        DlNode<int> n2(2);
        n2.setPrevious(&n1);
        assert(n1.getNext() == &n2);
        assert(n2.getPrevious() == &n1);
        n3.setPrevious(&n2);
        assert(n3.getPrevious() == &n2);
        assert(n2.getNext() == &n3);
        DlNode<int> *temp = n1.getPrevious();
        assert(temp == 0);
        DlNode<int> n4(4);
        DlNode<int> n6(6);
        DlNode<int> n5(5, &n4, &n6);
        assert(n4.getNext() == &n5);
        assert(n5.getPrevious() == &n4);
        assert(n6.getPrevious() == &n5);
    }
    cout << "All tests succeded" << endl;
    return 0;
}


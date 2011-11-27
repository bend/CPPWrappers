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
#include <Ds/DlLinkedList.h>
using namespace std;
int main()
{
    DlLinkedList<int> ll;
    ll.insertTop(1);
    ll.insertTop(2);
    ll.insertTop(3);
    ll.insertTop(4);
    ll.insertLast(0);
    assert(ll.getSize() == 5);
    assert(ll.getHead() == 4);
    assert(ll.getTail() == 0);
    assert((ll.getFirst()->getNext())->getPrevious()->getElem() == 4);
    int* arr = ll.toArray();
    int chk[5] = {4, 3, 2, 1 , 0};

    for (int i = 0; i < ll.getSize(); ++i)
        assert(arr[i] == chk[i]);
    ll.removeFirst();
    ll.removeLast();
    arr = ll.toArray();
    int chk2[3] = {3, 2, 1};

    for (int i = 0; i < ll.getSize(); ++i)
        assert(arr[i] == chk2[i]);
    cout << "All tests succeded" << endl;
    return 0;
}


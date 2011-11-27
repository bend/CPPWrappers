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
#include <Ds/Pair.h>
using namespace std;
int main()
{
    Pair<int, int> p1(1, 1);
    Pair<int, int> p2(2, 1);
    assert(p1 < p2);
    assert(p2 > p1);
    assert(p1 == p1);
    assert(p1 != p2);
    assert(p1 <= p2);
    assert(p2 >= p1);
    assert(p1 >= p1);
    assert(p1 <= p1);
    cout << "All tests succeded" << endl;
    return 0;
}


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
#include <System/Prime.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //   cout<<Prime::isPrime(18014398241046527)<<endl;
    Prime p(100);
    p.genPrimes();
    cout << "BiggestPrime : " << p.getBiggestPrime() << endl;
    cout << "Is prime ?: " << Prime::isPrime(p.getBiggestPrime()) << endl;
    vector<long> v = p.getPrimes();
    unsigned int i = 0;

    while(i < v.size()) {
        cout << v[i] << endl;
        ++i;
    }
}

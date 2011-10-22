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
#include <System/Random.h>
#include <vector>
#include <set>
using namespace std;
int main() {
    Random r(Random::BlumBlumShub);
    r.init();
    int i = 0;
    vector<int> v;
    srand(time(NULL));

    while(i < 10000) {
        v.push_back(r.random(0, 100));
        i++;
    }

    i = 0;
    cout << "Size : " << v.size() << endl;

    while(i < 100) {
        unsigned int j = 0;
        int count = 0;

        while(j < v.size()) {
            if(v[j] == i)
                count++;

            j++;
        }

        cout << "Count of " << i << " : " << count << endl;
        i++;
    }

    Random r2(Random::BlumBlumShub);
    r2.init();
    i = 0;
    long randomN = 0;
    long sum = 0;

    while(i < 100) {
        randomN = r2.random(0, 100);
        sum += randomN;
        i++;
    }

    cout << "AVG = " << sum / 100.0 << endl;
}

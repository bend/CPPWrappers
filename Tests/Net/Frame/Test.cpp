/**
 *
 *       @file  Client.cpp
 *
 *      @brief  test client
 *
 *    @version  1.0
 *       @date  10/10/2011 19:22:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/Frame.h>

int main()
{
    Frame fr(2);
    bool bl = true;
    int8 a = 'c';
    int16 b = -30000;
    int32 c = 2147483647;
    fr << bl << a << b << c;
    bool bl2;
    int8 d;
    int16 e;
    int32 f;
    fr >> bl2 >> d >> e >> f;
    cout << bl2 << " " << d << " " << e << " " << f << endl;
    string s = "hello";
    fr << s;
    string r;
    fr >> r;
    cout << r << endl;
    int16 po = 12345;
    fr << po;
    int16 aze;
    fr >> aze;
    cout << aze << endl;
    uint16 r1 = 62000;
    uint32 r2 = 4294967295;
    fr << r1 << r2;
    uint16 r3;
    uint32 r4;
    fr >> r3 >> r4;
    cout << r3 << " " << r4 << endl;
}


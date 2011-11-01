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

#include <Net/TcpSocket.h>
#include <Net/Frame.h>
#include <iostream>
using namespace std;
int main()
{
    TcpSocket s;
    Host h("localhost", 2000);
    s.connect(h);
    string r = "";
    int32 res;
    cout << s.getLocalPort() << endl;
    cout << s.getRemotePort() << endl;
    cout << s.getRemoteAddress().toString() << endl;
    sleep(1);
    s.receiveInt32(res);
    cout << "Received " << res << endl;
    string resStr;
    s.receiveString(resStr, 5);
    cout << "Received string " << resStr << endl;
    s.receiveString(resStr, 5);
    cout << "Received string " << resStr << endl;
	Frame f;
	s.receiveFrame(f);
	string str;
	f>>str;
	int32 t;
	f>>t;
	char c;
	f>>c;
	cout<<str<<" "<<t<<c;
    s.close();
}


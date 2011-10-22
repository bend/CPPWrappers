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

int main() {
    TcpSocket s;
	Host h("localhost", 2000);
    s.connect(h);
    string r = "";
    int res;
	cout<<s.getLocalPort()<<endl;
	cout<<s.getRemotePort()<<endl;
	cout<<s.getRemoteAddress().toString()<<endl;
	sleep(1);
    s.receiveInt(res);
    cout << "Received " << res << endl;
    string resStr;
    s.receiveString(resStr);
    cout << "Received string " << resStr << endl;
    s.close();
}


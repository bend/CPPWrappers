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

int main()
{
    TcpSocket s;
    Host h("www.sfml-dev.org", 80);
    if(s.connect(h) == AbstractSocket::Done){
		cout<<"Connected "<<endl;
		s.sendString("GET /ip-provider.php HTTP/1.1");
		string r;
		s.receiveString(r, 10);
		cout<<" Received : "<<r<<endl;
	}else
		cout<<"not connected"<<endl;

    s.close();
}


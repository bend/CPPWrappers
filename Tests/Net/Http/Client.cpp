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
    Host h("checkip.dyndns.org", 80);

    if (s.connect(h) == AbstractSocket::Done)
    {
        cout << "Connected " << endl;
        s.sendString("GET / HTTP/1.0\nFrom: user@sfml-dev.org\nUser-Agent: libsfml-network/2.x\n\n");
        string r;
        s.receiveString(r, 1024);
        cout << "something received" << endl;
        cout << " Received : " << r << endl;
    }

    else
        cout << "not connected" << endl;

    s.close();
}


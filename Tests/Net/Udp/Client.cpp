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

#include <Net/UdpSocket.h>

int main()
{
    UdpSocket s;
    Host h("localhost", 2001);

    if (s.sendString("hello world", h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    if (s.sendInt(666, h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    if (s.sendChar('&', h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    size_t ts = 21;

    if (s.sendCharArray("this is a char array", ts, h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    s.close();
}


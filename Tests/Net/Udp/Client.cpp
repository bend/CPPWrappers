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
#include <Net/Frame.h>
#include <stdio.h>
int main()
{
    UdpSocket s;
    Host h("localhost", 2001);

    if (s.sendString("hello world", h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    if (s.sendInt32(666, h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    if (s.sendInt8('&', h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

    size_t ts = 21;

    if (s.sendCharArray("this is a char array", ts, h) == AbstractSocket::Done)
        cout << "Done" << endl;

    else
        perror("Error");

	Frame f;
	f<<"This is a frame "<<666<<'\n';
	if(s.sendFrame(f, h) != AbstractSocket::Done)
		perror("error");
	else 
		cout<<"done"<<endl;

    s.close();
}


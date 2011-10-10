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

#include <Socket/TcpSocket.h>

int main(){
	TcpSocket s;
	s.connect("localhost", 2000);
	string r="";
	int res;
	s.receiveInt(res);
	cout<<"Received "<<res<<endl;
	string resStr;
	s.receiveString(resStr);
	cout<<"Received string "<<resStr<<endl;

}


/**
 *
 *       @file  Server.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/10/2011 19:24:10
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Socket/TcpServer.h>
#include <Socket/TcpSocket.h>
int main(){
	TcpServer *server =  new TcpServer;
	server->listen(2000);
	TcpSocket* s = server->accept();
	cout<<"Connected client"<<endl;
	int i = 4;
	i++;
	string r="gello ";
	s->sendInt(i);
	s->sendString(r);
	return 1;
}

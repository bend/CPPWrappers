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

#include <Net/HttpProtocol.h>

int main()
{
    /**
    TcpSocket s;
    Host h("checkip.dyndns.org", 80);

    if (s.connect(h) == AbstractSocket::Done)
    {
        cout << "Connected " << endl;
        s.sendString("GET / HTTP/1.0\nFrom: user@sfml-dev.org\nUser-Agent: libsfml-network/4.x\n\n");
        string r;
        s.receiveString(r, 1024);
        cout << "something received" << endl;
        cout << " Received : " << r << endl;
    }

    else{
        cout << "not connected" << endl;
    	perror("");
    }

    s.close();
    **/
    Host h("checkip.dyndns.org", 80);
    HttpProtocol proto(h);
    HttpRequest req("/", HttpRequest::Head);
    req.setField(HttpTypes::UserAgent, "Mozilla");
    req.setField(HttpTypes::From, "Ben D");
    req.setBody("<html> hello world </html>");
    req.checkAndFix();
    cout << "Request " << endl << req.toString() << endl;
    proto.sendRequest(req);
	HttpResponse r = proto.getResponse();
	r.parse();
	cout<<r.toString()<<endl;
	cout << "http version ["<<r.getHttpVersion()<<"]"<<endl;
	cout<< "Content length["<<r.getContentLength()<<"]"<<endl;
	cout<< "Code ["<<r.getResponseCode()<<"]"<<endl;
	cout<< "Body ["<<r.getBody()<<"]"<<endl;
	cout <<"Server ["<<r.getField("Server")<<"]"<<endl;
}


/**
 *
 *       @file  TcpServer.h
 *
 *      @brief Tcp server
 *
 *    @version  1.0
 *       @date  10/10/2011 18:18:30
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef TCP_SERVER_H__
#define TCP_SERVER_H__
#include <Socket/TcpSocket.h>

class TcpServer {
public:
    /**
     * @brief constructor
     */
    TcpServer(int maxWaitingCon = 5);


    /**
     * @brief listen for incomming connection
     */
    int listen(int port);

    /**
     * accepts a connection and returns the socket
     * of the newly connected client
     */
    TcpSocket* accept();

    /*
     * Closes the server
     */
    int close();

private:
    /* methods */
    int bind(int port);

    /* variables */
    int m_socketfd;
    int m_portNo;
    int m_maxWaitCon;
    struct sockaddr_in m_servAddr;
    struct sockaddr_in m_cliAddr;
    struct hostent *m_server;
};

#endif

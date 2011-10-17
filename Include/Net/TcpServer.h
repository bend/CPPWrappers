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
#include <Socket/SocketErrors.h>

class TcpServer {
public:
    /**
     * @brief constructor
     * @param maxWaitingCon the number of queued connection that the server can handle, if this number is reached, the server will refuse connections
     */
    TcpServer(int maxWaitingCon = 5);


    /**
     * @brief listen for incomming connection
     * @param port the port on which the server will listen for inconming connections
     * @return 0 if successful
     */
    int listen(int port);

    /**
     * @brief accepts a connection and returns the socket
     * of the newly connected client
     * @return 0 if successful
     */
    TcpSocket* accept();

    /*
     * @brief the server
     * @return 0 if successful
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

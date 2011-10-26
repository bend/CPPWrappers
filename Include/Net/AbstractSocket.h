/**
 *
 *       @file  AbstractSocket.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/21/2011 22:53:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef ABSTRACT_SOCKET_H__
#define ABSTRACT_SOCKET_H__

#include <System/Types.h>
#include <Net/Host.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include <iostream>
using namespace std;

class AbstractSocket
{
    public:
        /**
         * @brief Status of the socket
         */
        enum Status
        {
            /** No socket errors **/
            Done,
            /** Socket not ready **/
            NotReady,
            /** Socket disconnected **/
            Disconnected,
            /** Socket error **/
            Error,
            /** Could not open Socket descriptor **/
            EOPEN,
            /** Could not find host **/
            EHOST,
            /** Could not allocate memory **/
            EMEM,
            /** Http Request invalid **/
            InvalidRequest
        };

        /**
         * @brief Empry Constructor. This class must be inherited
         */
        AbstractSocket();

        /**
         * @brief Constructor. This class must be inherited
         * @param socket the Socket descriptor
         */
        AbstractSocket(int socket);

        /**
         * @brief gets the local port
         * @return the port >0 is found, 0 if the port could not be determined
         */
        uint8 getLocalPort() const;

        /**
         * @brief gets the remote port
         * @return the port >0 is found, 0 if the port could not be determined
         */
        uint8 getRemotePort() const;

        /**
         * @brief get the remote address
         * @return an IpAddress object is the ip could be determined
         *     	   IpAddress::None if no ip address determined
         */
        IpAddress getRemoteAddress();

        /**
         * @brief sets the blocking state of the socket
         * @param b a boolean
         */
        void setBlocking(bool b);

        /**
         * @brief get the blocking socket state
         * @return true is blocking, false otherwise
         */
        bool isBlocking();

        /**
         * @brief get the socket status
         * @return AbstractSocket::Status
         * @see AbstractSocket::Status
         */
        AbstractSocket::Status getSocketStatus();

        /**
         * @brief disconnects from the host
         */
        void close();


    protected:
        /**
         * @brief socket file descriptor
         */
        int m_socketfd;

    private:
        bool m_isBlocking;
};

#endif

/**
 *
 *       @file  Errors.h
 *
 *      @brief  Defines socket errors
 *
 *    @version  1.0
 *       @date  10/10/2011 15:40:54
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef SOCKET_ERRORS_H__
#define SOCKET_ERRORS_H__

class SocketErrors {
public:
    /**
     * Success
     */
    static const int SOSUCC = 1;

    /**
     * Could not open Socket
     */
    static const int SOCOPEN = -1;

    /**
     * Host not found
     */
    static const int SONHOST = -2;

    /**
     * Could not connect
     */
    static const int SOCONN = -3;

    /**
     * Could not close the connection
     */
    static const int SOCLO  = -4;

    /**
     * Could not write to socket
     */
    static const int SOEWRITE = -5;

    /**
     * Could not read from socket
     */
    static const int SOEREAD = -6;

    /**
     * Could not allocate mem
     */
    static const int SOEMEM = -7;

    /**
     * Could not bind socket
     */
    static const int SOEBIND = -8;

    /**
     * Could not listen on socket
     */
    static const int SOELIST = -9;

};

#endif

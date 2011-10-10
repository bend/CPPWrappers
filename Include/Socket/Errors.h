/**
 *
 *       @file  Errors.h
 *
 *      @brief  Defines errors 
 *
 *    @version  1.0
 *       @date  10/10/2011 15:40:54
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef ERRORS_H__
#define ERRORS_H__
/**
 * Success
 */
const int SOSUCC = 1;

/**
 * Could not open Socket 
 */
const int SOCOPEN = -1;

/**
 * Host not found
 */
const int SONHOST = -2;

/**
 * Could not connect
 */
const int SOCONN = -3;

/**
 * Could not close the connection
 */
const int SOCLO  = -4;

/**
 * Could not write to socket
 */
const int SOEWRITE = -5;

/**
 * Could not read from socket
 */
const int SOEREAD = -6;

/**
 * Could not allocate mem
 */
const int SOEMEM = -7;

/**
 * Could not bind socket
 */
const int SOEBIND = -8;

/**
 * Could not listen on socket
 */
const int SOELIST = -9;
#endif

/**
 *
 *       @file  IpAddress.h
 *
 *      @brief  Ip address class
 *
 *    @version  1.0
 *       @date  10/22/2011 13:13:07
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef IP_ADDRESS_H__
#define IP_ADDRESS_H__

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <stdlib.h>

#include <System/Types.h>

using namespace std;
class IpAddress {
public:
    /**
     * @brief Ip enum containing ip state
     */
    enum Ip {
        /** No ip determined **/
        None
    };

    /**
     * @brief Constructor
     * @param host the host name or ip
     */
    IpAddress(const string &host);

    /**
     * @brief Constructor
     * @param host the host name or ip
     */
    IpAddress(const char* host);

    /**
     * @brief Constructor
     * @param byte1 the first byte of the ip address (xxx.xxx.xxx.xxx)
     * @param byte2 the second byte
     * @param byte3 the third byte
     * @param byte4 the fourth byte
     */
    IpAddress(const  uint8 &byte1, const uint8 &byte2, const uint8 &byte3, const uint8 &byte4);

    /**
     * @brief Constructor
     * @param addr the ip address
     */
    IpAddress(uint32 addr);

    /**
     * @brief get the string representation of the ip
     * @return the string representation
     */
    string toString();

    /** 
     * @brief gets the integer representation of the ip
     * @return the integer reprensentation
     */
    uint32 toInt();

private:
    in_addr_t m_ipAddr;


};

#endif

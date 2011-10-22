/**
 *
 *       @file  FileTypes.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/16/2011 23:44:23
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef FILE_TYPES_H__
#define FILE_TYPES_H__

#include <iostream>
using namespace std;

class FileTypes {
public:
    /**
     * @brief Open file in read mode
     */
    static const string READ ;

    /**
     * @brief Open file in write mode
     */
    static const string WRITE;

    /**
     * @brief Open the file in read write mode
     */
    static const string READWRITE ;

    /**
     * @brief Open the file in read write append mode
     */
    static const string APPEND ;

    /**
     * @brief End of file marker
     */
    static const int ENDOFFILE;

    /**
     * @brief seek from the begining of the file
     */
    static const int SEEK_FBEGIN;

    /**
     * @brief seek from the end of the file
     */
    static const int SEEK_FEND;

    /**
     * @brief seek from the current position
     */
    static const int SEEK_CURRENT;

    /*
     * @brief  RWX mask for owner
     */
    static const int RWXU;

    /**
     * @brief R for owner
     */
    static const int RU;

    /**
     * @brief  W for owner
     */
    static const int WU;

    /**
     * @brief X for owner
     */
    static const int XU;

    /**
     * @brief  RWX mask for group
     */
    static const int RWXG;

    /**
     * @brief  R for group
     */
    static const int RG;

    /**
     * @brief W for group
     */
    static const int WG;

    /**
     * @brief X for group
     */
    static const int XG;

    /**
     * @brief  RWX mask for other
     */
    static const int RWXO;

    /**
     * @brief  R for other
     */
    static const int RO;

    /**
     * @brief  W for other
     */
    static const int WO;

    /**
     * @brief  X for other
     */
    static const int XO;

    /**
     * @brief  set user id on execution
     */
    static const int SUID;

    /**
     * @brief  set group id on execution
     */
    static const int SGID;

    /**
     * @brief  save swapped text even after use
     */
    static const int SVTX;

};


#endif

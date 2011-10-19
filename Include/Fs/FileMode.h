/**
 *
 *       @file  FileMode.h
 *
 *      @brief  File mode class, represents the file mode
 *
 *    @version  1.0
 *       @date  10/17/2011 15:40:16
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef FILE_MODE_H__
#define FILE_MODE_H__
#include <iostream>
using namespace std;
#include <Fs/FileTypes.h>
class FileMode {
public:
    /**
     * @brief Constructor
     * @param mode the mode in int format (ex: 0744)
     */
    FileMode(int mode);

    /**
     * @brief get the mode of the file in int format
     * @return the mode
     * @see FileTypes for modes declaration
     */
    int getMode();

    /**
     * @brief allows the (char*) cast of the object
     */
    operator int();

    /**
     * @brief converts the mode to string representation (ex: 0755 -> rwxr-xr-x)
     * @return the string representation of the mode or empty string if error occurs
     */
    string getStringMode();

private:
    int m_mode;
    string m_path;

};

#endif

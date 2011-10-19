/**
 *
 *       @file  Path.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/17/2011 17:23:15
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef PATH_H__
#define PATH_H__
#include <iostream>
using namespace std;
class Path {
public:
    Path(string path);

    /**
     * @brief get the absolute path of the file
     * @return the absolute path of the file
     */
    Path getAbsolutePath();


    /**
     * @brief gets the file name of the file
     * @return the name
     */
    string getName();

    /**
     * @brief gets the parent directory
     * @return a Path object containing the parent path. If not parent ('/') the same path is returned
     */
    Path getParent();

    /**
     * @brief gets the path in string format
     * @return the string containing the path
     */
    string toString();

    /**
     * @brief allows (char*) cast
     */
    operator const char*();

private:
    string m_path;
};

#endif

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

    Path getParent();

    string toString();

    operator const char*();

private:
    string m_path;
};

#endif

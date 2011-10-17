/**
 *
 *       @file  FileTypes.cpp
 *
 *      @brief  FileTypes
 *
 *    @version  1.0
 *       @date  10/17/2011 17:16:47
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <Fs/FileTypes.h>

const string FileTypes::READ = "r";

const string FileTypes::WRITE = "w";

const string FileTypes::READWRITE = "rw";

const string FileTypes::APPEND = "a+";

const int FileTypes::ENDOFFILE = -2;

const int FileTypes::SEEK_FBEGIN = 0;

const int FileTypes::SEEK_FEND = 2;

const int FileTypes::SEEK_CURRENT= 1;

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

const int FileTypes::SEEK_CURRENT = 1;

const int FileTypes::RWXU = 0000700;

const int FileTypes::RU = 0000400;

const int FileTypes::WU = 0000200;

const int FileTypes::XU = 0000100;

const int FileTypes::RWXG = 0000070;

const int FileTypes::RG = 0000040;

const int FileTypes::WG = 0000020;

const int FileTypes::XG = 0000010;

const int FileTypes::RWXO = 0000007;

const int FileTypes::RO = 0000004;

const int FileTypes::WO = 0000002;

const int FileTypes::XO = 0000001;

const int FileTypes::SUID = 0004000;

const int FileTypes::SGID = 0002000;

const int FileTypes::SVTX = 0001000;

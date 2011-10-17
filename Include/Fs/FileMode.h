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

class FileMode{
	public:
		FileMode(int mode);

		FileMode(string path);

		int getMode();

		string getStringMode();

	private:
		int m_mode;
		string m_path;

};

#endif

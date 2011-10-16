/**
 *
 *       @file  File.h
 *
 *      @brief File class
 *
 *    @version  1.0
 *       @date  10/16/2011 23:28:03
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef FILE_H__
#define FILE_H__

#include  <stdio.h>

#include <iostream>
using namespace std;

class File{
	
	public:
		
		/**
		 * @brief File class constructor. The file is not openned here, to open it you need to call the open() method
		 * @param path the path to the file
		 * @param mode the mode 
		 * @see FileTypes
		 */
		File(string path, string mode);
		
		/**
		 * @brief Opens the file in the defined mode
		 * @return 0 if success , -1 otherwise
		 */
		int open();

		bool exists();
	
		int remove();

		int close();

		string* getList();

		string getAbsolutePath();

		string getName();

		long getSize();

		int getMode();

		bool isFile();

		bool isDirectory();

		int mkdir();

		int renameTo(string name);

		int copyTo(string name);

	private:
		FILE* f;
		string m_path;
		string m_mode;


};

#endif

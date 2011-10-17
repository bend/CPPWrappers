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
#include <sys/stat.h>
#include <dirent.h>

#include <iostream>
#include <vector>
using namespace std;

#include <Fs/FileMode.h>
#include <Fs/Path.h>

class File{
	
	public:
		
		/**
		 * @brief File class constructor. The file is not openned here, to open it you need to call the open() method
		 * @param path the path to the file
		 * @param mode the mode 
		 * @see FileTypes
		 */
		File(Path& p, string mode);

		
		/**
		 * @brief Opens the file in the defined mode
		 * @return 0 if success , -1 otherwise
		 */
		int open();
		
		/**
		 * @brief Tells whether the file exists or not
		 * @return true if exists false otherwise 
		 */
		bool exists();
		
		/**
		 * @brief removes the file
		 * @return 0 if success, -1 otherwise
		 */
		int remove();
		
		/**
		 * @brief closes the file
		 * @return 0 is success, -1 otherwise
		 */
		int close();
		
		/**
		 * @brief lists all the file in a dir
		 * @return vector<string> containing the file names
		 * 	an empty vector can menan that either there is no files in the directory or either that an error occured 
		 */
		vector<string> getList();

		Path getPath();
		
		/**
		 * @brief get the file size
		 * @return the file size > 0 or -1 if error occured
		 */
		long getSize();
		
		/**
		 * @brief returns the mode of the file 
		 * @return an int corresponfing to the mode
		 */
		FileMode* getMode();
		
		/**
		 * @brief tells if the File is a file
		 * @return true if file false otherwise
		 */
		bool isFile();
		
		/**
		 * @brief tells if the File is a Folder
		 * @return true if folder, false otherwise
		 */
		bool isDirectory();
		
		/**
		 * @brief creates a directory with the current path
		 * @return TODO
		 */
		int mkdir();

		int renameTo(string name);

		int copyTo(string name);

	private:
		FILE* f;
		Path m_path;
		string m_mode;


};

#endif

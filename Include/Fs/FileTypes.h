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

class FileTypes{
	public:
		/**
		 * @brief Open file in read mode 
		 */
		static const string READ = "r";

		/**
		 * @brief Open file in write mode 
		 */
		static const string WRITE ="w";

		/**
		 * @brief Open the file in read write mode 
		 */
		static const string READWRITE = "rw";

		/**
		 * @brief Open the file in read write append mode 
		 */
		static const string APPEND = "a+";
};

#endif

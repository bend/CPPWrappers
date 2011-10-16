/**
 *
 *       @file  File.cpp
 *
 *      @brief  File class 
 *
 *    @version  1.0
 *       @date  10/16/2011 23:28:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/File.h>


File::File(string path, string mode):
	m_path(path), 
	m_mode(mode){
}

int File::open(){
	f = fopen(m_path.c_str(), m_mode.c_str());
	if(f == NULL)
		return -1;
	return 0;
}

bool File::exists(){

}

int File::remove(){
	return ::remove(m_path);
}

int File::close(){
	return fclose(f);
}

long File::getSize(){

}

int File::getMode(){

}


string* File::getList(){

}

string File::getAbsolutePath(){
	
}

string File::getName(){
}

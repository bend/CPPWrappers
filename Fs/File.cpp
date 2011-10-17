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
	FILE* file;
	if(file = fopen(m_path.c_str(), "r")){
		fclose(file);
		return true;
	}
	fclose(file);
	return false;
}

int File::remove(){
	return ::remove(m_path.c_str());
}

int File::close(){
	return fclose(f);
}

long File::getSize(){
	struct stat file_status;
	if (stat(m_path.c_str(), &file_status) < 0) {
		return -1;
	}
	return file_status.st_size;	
}

FileMode* File::getMode(){
	struct stat file_status;
	if (stat(m_path.c_str(), &file_status) < 0) {
		return new FileMode(-1);
	}
	return new FileMode(file_status.st_mode);
}


vector<string> File::getList(){
	vector<string> vect;
	DIR *dir = opendir(m_path.c_str());
	struct dirent *ent;
	if (dir == NULL)
		return vect;
	while ((ent = readdir (dir)) != NULL) {
		string t;
		t = string(ent->d_name);
		vect.push_back(t);	
	}
	return vect;
}

string File::getAbsolutePath(){
	char thePath[256];
	string res;
	getcwd(thePath, 255);
	res = string(thePath);
	res.append("/");
	res.append(m_path);
	return res;
}

string File::getName(){

}

bool File::isFile(){

}

bool File::isDirectory(){

}

int File::mkdir(){

}

int File::renameTo(string name){

}

int File::copyTo(string name){

}

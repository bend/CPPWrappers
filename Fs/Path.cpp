/**
 *
 *       @file  Path.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/17/2011 17:23:
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/Path.h>

Path::Path(string path):
	m_path(path)
{

}

Path Path::getAbsolutePath(){
	char thePath[256];
	string temp = m_path;
	string res;
	getcwd(thePath, 255);
	int level = 0;
	int i = 0;
	while(temp[0] == '.'){
		if(temp[1] == '.'){
			temp = temp.substr(2);
			if(temp[0] == '/')
				temp = temp.substr(1);
		level++;
		}else{
		   	temp = temp.substr(1);
			if(temp[0] == '/')
				temp = temp.substr(1);
		}
	}
	cout<<"Level : "<<level<<endl;	
	cout<<"?? "<<temp<<endl;

	while(level != 0 && i<=level){
		if(temp[0] == '/')
			temp = temp.substr(1);
		string::size_type loc = temp.find("/");
		if(loc != string::npos)
			temp = temp.substr(loc+1);
		i++;
	}
	res = string(thePath);
	res.append("/");
	res.append(temp);
	return  Path(res);
}

string Path::getName(){
	if(m_path[m_path.length()-1] == '/')
		m_path = m_path.substr(0,m_path.length()-2);
	string::size_type loc = m_path.find_last_of("/");
	if(loc == string::npos)
		return m_path;

	return m_path.substr(loc+1);
}

Path Path::getParent(){
	if(m_path[m_path.length()-1] == '/')
		m_path = m_path.substr(0,m_path.length()-2);
	string::size_type loc = m_path.find_last_of("/");
	if(loc == string::npos)
		return m_path;
	return m_path.substr(0,loc);
}

string Path::toString(){
	return m_path;
}

Path::operator const char*(){
	return m_path.c_str();
}

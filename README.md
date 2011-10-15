## A C++ wrapper for the thread, semaphore and socket library

### Overview 

This library is a C++ wrapper for BSD sockets, pthread and semaphore.
I've test it on MacOS, but it should be working on Linux
Therer are 2 Libraries:

- System, that contains the Thread class, Semaphore class and Mutex class
- Socket, that contains the TcpSocket and TcpServer class

### Install

#### Dependencies

You need cmake in order to compile and install the libraries

#### Install instructions

You can either install the 2 libraries or install them one by one. Each library is independant and does not require the other one to run
- To install the 2 libraries at once, go to the project directory and create a build direcory and type:
 
	cd build
  	cmake ../
  	sudo make && make install

- To install one of the 2 libraries go the the library folder (System or Socket) create a build directory and type:
	
	cd build
  	cmake ../
  	sudo make && make install

### Examples

Small examples are located in the Tests folder. Basicaly the libraries are easy to use, notice that for the Thread class you need to subclass it and override the run() method

### TODO
Add an error logger, Udp sockets, http requests ...

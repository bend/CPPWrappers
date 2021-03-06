## A C++ wrapper for the thread, semaphore and socket library etc..

### Overview 

This library is a C++ wrapper for BSD sockets, pthread and semaphore.
It has been tested on MacOS, but it should work on Linux

#### System

contains the Thread class, Semaphore class and Mutex class, Time class, PRNG class and Prime number generator class

####Net

contains the TcpSocket, TcpServer, UdpSocket, HtmlRequest classes.

####Fs

contains methods for using the file system: File, BufferedInput BufferedOutput, ...

####Parser 

contains an HtmlParser (not fully implemete but should but should be sufficient for accessing values between tags)

### Documentation 

Online documentation can be found [here](http://bend.github.com/CPPWrappers/Doc/html/index.html) 

### Install

#### Dependencies

You need cmake in order to compile and install the libraries

#### Install instructions

To install the library go to the project directory and type de following:
		
		mkdir build
		cd build
  		cmake ../
  		sudo make && make install

### Examples

Small examples are located in the Tests folder. Basicaly the libraries are easy to use, notice that for the Thread class you need to subclass it and override the run() method


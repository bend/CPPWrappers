## A C++ wrapper for the thread, semaphore and socket library

### Overview 

This library is a C++ wrapper for BSD sockets, pthread and semaphore.
I've test it on MacOS, but it should be working on Linux
Therer are 2 Libraries:

- System, that contains the Thread class, Semaphore class and Mutex class
- Socket, that contains the TcpSocket and TcpServer class

### Install

To compile and install the library go to the folder System or Socket and type 
  make
  sudo make install
You need to do this for both folders

### Examples

Small examples are located in the Tests folder. Basicaly the libraries are easy to use, notice that for the Thread class you need to subclass it and override the run() method

### TODO
Add an error logger, Udp sockets, http requests ...

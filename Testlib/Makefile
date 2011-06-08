CFLAGS+= -Wall -pedantic -Werror
LDFLAGS+=
EXEC=test
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libthread.so
CC=g++


tests:
	$(CC) -fPIC -c ../Semaphore.cpp
	$(CC) -fPIC -c ../Thread.cpp
	$(CC) -shared Thread.o Semaphore.o -o $(LIB)
	$(CC) Test.cpp -o $(EXEC) $(LIB)


.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(EXEC)
	@rm $(LIB)


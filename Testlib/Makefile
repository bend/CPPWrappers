CFLAGS+= -Wall -pedantic -Werror
LDFLAGS+=
EXEC=test
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libthread.so
CC=g++
SHAREFLAG+=-fPIC


tests:
	$(CC) $(SHAREFLAG) -c ../Semaphore.cpp
	$(CC) $(SHAREFLAG) -c ../Thread.cpp
	$(CC) -shared Thread.o Semaphore.o  -o $(LIB)
	$(CC) Test.cpp -o $(EXEC) $(LIB)


.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(EXEC)
	@rm $(LIB)


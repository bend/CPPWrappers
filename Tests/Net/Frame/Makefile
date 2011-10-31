CFLAGS+= -Wall -pedantic -Werror -lcppwrappers
LDFLAGS+=
EXEC=test
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
SHAREFLAG+=-fPIC
CLIENT=client
SERVER=server


all: test

debug: CFLAGS+=-g
debug: all

test:
	$(CC) Test.cpp $(CFLAGS) -o $(CLIENT)


.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(CLIENT) $(SERVER)


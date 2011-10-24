CFLAGS+= -Wall -pedantic -Werror -lcppwrappers
LDFLAGS+=
EXEC=test
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
SHAREFLAG+=-fPIC
CLIENT=client
SERVER=server


all: client

debug: CFLAGS+=-g
debug: all

client:
	$(CC) Client.cpp $(CFLAGS) -o $(CLIENT)


.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(CLIENT) $(SERVER)


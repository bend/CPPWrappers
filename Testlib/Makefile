CFLAGS+= -Wall -pedantic -Werror -lsystemcpp
LDFLAGS+=
EXEC=test
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
SHAREFLAG+=-fPIC


tests:
	$(CC) Test.cpp $(CFLAGS) -o $(EXEC)


.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(EXEC)
	@rm $(LIB)


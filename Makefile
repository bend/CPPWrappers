CFLAGS+= -Wall -pedantic -Werror
LDFLAGS+=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libthread.so
CC=g++
SHAREFLAG+=-fPIC

lib: $(LIB)

$(LIB):
	@echo "Building objects file";
	@for f in $(SOURCES:.cpp=) ; \
		do \
		$(CC) $(SHAREFLAG) -c $$f.cpp $(CFLAGS) ;\
		done
	@echo "Building library";
		@$(CC) -shared $(OBJECTS) -o $(LIB)
	@echo "Done!"
.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(LIB)


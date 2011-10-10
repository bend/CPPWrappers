CFLAGS+= -Wall -pedantic -Werror -I../Include
LDFLAGS+= 
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libsystemcpp.dylib
CC=g++
SHAREFLAG+=-fPIC
INSTALL_INCLUDE=/usr/include
INSTALL_LIB=/usr/lib
INSTALL_SUBDIR=System
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
install:
	@echo "Copying headers to $(INSTALL_INCLUDE)"
	@cp -r ../Include/$(INSTALL_SUBDIR) $(INSTALL_INCLUDE)
	@echo "Copying $(LIB) to $(INSTALL_LIB)"
	@cp -r $(LIB) $(INSTALL_LIB)/$(LIB)
	@echo "Done!"
uninstall:
	@echo "Removing headers from $(INSTALL_INCLUDE)"
	@rm -rf $(INSTALL_INCLUDE)/$(INSTALL_SUBDIR)
	@echo "Removing library from $(INSTALL_LIB)"
	@rm -rf $(INSTALL_LIB)/$(LIB)
.PHONY: clean mrproper
clean:
	@rm $(OBJECTS)

mrproper:
	@rm $(LIB)


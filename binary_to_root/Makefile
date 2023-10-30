
CC=g++	
CFLAGS=`root-config --cflags`
LDFLAGS=`root-config --glibs`
SOURCES=main.cxx binary_to_root.cxx
OBJECTS=$(SOURCES:.cxx=.o)
HEADERS=binary_to_root.h
EXECUTABLE=bin2root


all:
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(CFLAGS) $(LDFLAGS)
	
clean:
	-rm *.o
	
release:
	-rm *.o
	-rm $(EXECUTABLE)

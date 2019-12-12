
CC=g++	
CFLAGS=`root-config --cflags`
LDFLAGS=`root-config --glibs`
SOURCES=main.cxx txt_to_root.cxx
OBJECTS=$(SOURCES:.cxx=.o)
HEADERS=txt_to_root.h
EXECUTABLE=txt2root


all:
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(CFLAGS) $(LDFLAGS)
	
clean:
	-rm *.o
	
release:
	-rm *.o
	-rm $(EXECUTABLE)

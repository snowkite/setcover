CXXFLAGS =	-c -O2 -g -Wall -fmessage-length=0

SRC =		src/main.cc src/setcover.h src/setcover.tcc

OBJS = 		build/main.o

EXECUTABLE = 	setcover

LIBS =


main: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

build/main.o:	$(SRC)
	$(CXX) $(CXXFLAGS) src/main.cc -o build/main.o

all:	main

clean:
	rm -f $(OBJS) $(EXECUTABLE)

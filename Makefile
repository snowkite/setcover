CXXFLAGS =	-c -O2 -g -Wall -fmessage-length=0

SRC =		src/main.cc src/setcover.h src/setcover.tcc

TEST =		test/setcover_test.cpp src/setcover.h src/setcover.tcc

TOBJS =		build/setcover_test.o

TEXEC =		test_sc

OBJS = 		build/main.o

EXECUTABLE = 	setcover

LIBS =


main: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

build/main.o:	$(SRC)
	$(CXX) $(CXXFLAGS) src/main.cc -o build/main.o

all:	main test_sc

clean:
	rm -f $(OBJS) $(EXECUTABLE) $(TEXEC)

test_sc: $(TOBJS)
	$(CXX) $(LDFLAGS) $(TOBJS) -o $(TEXEC)

build/setcover_test.o:	$(TEST)
	$(CXX) -I./src $(CXXFLAGS) test/setcover_test.cpp -o $(TOBJS)

test: $(TEXEC)
	./$(TEXEC)	

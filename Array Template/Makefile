CXX = g++
CXXFLAGS = -c

all: array

array: main.o
	$(CXX) main.o -o array

main.o: main.cpp Array.hpp
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm *.o array

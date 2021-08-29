CXX = g++
CXXFLAGS = -c

all: polynomial

polynomial: main.o Polynomial.o
	$(CXX) main.o Polynomial.o -o polynomial

main.o: main.cpp Polynomial.h
	$(CXX) $(CXXFLAGS) main.cpp

Polynomial.o: Polynomial.cpp Polynomial.h
	$(CXX) $(CXXFLAGS) Polynomial.cpp

clean:
	rm *.o polynomial


CXX = g++
CXXFLAGS = -c

all: package

package: Package.o TwoDayPackage.o OvernightPackage.o main.o
	$(CXX) Package.o TwoDayPackage.o OvernightPackage.o main.o -o package

main.o: main.cpp TwoDayPackage.h OvernightPackage.h
	$(CXX) $(CXXFLAGS) main.cpp

TwoDayPackage.o: TwoDayPackage.cpp TwoDayPackage.h Package.h
	$(CXX) $(CXXFLAGS) TwoDayPackage.cpp

OvernightPackage.o: OvernightPackage.cpp OvernightPackage.h Package.h
	$(CXX) $(CXXFLAGS) OvernightPackage.cpp

Package.o: Package.cpp Package.h
	$(CXX) $(CXXFLAGS) Package.cpp

clean:
	rm *.o package


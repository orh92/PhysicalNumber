#!make -f

all: test
	./$<

demo: PhysicalNumberDemo.o PhysicalNumber.o
	g++ -std=c++1z $^ -o demo

test: PhysicalNumberTest.o PhysicalNumber.o
	g++ -std=c++1z $^ -o test

%.o: %.cpp
	g++ -std=c++1z -c $< -o $@

PhysicalNumber.o: PhysicalNumber.h Unit.h

PhysicalNumberDemo.o: PhysicalNumber.h Unit.h

PhysicalNumberTest.o: PhysicalNumber.h Unit.h badkan.hpp

clean:
	rm -f *.o demo test

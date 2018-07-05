p1: matrix.o p1.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o p1 matrix.o p1.o

matrix.o: matrix.cpp matrix.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c matrix.cpp

p1.o: p1.cpp matrix.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c p1.cpp

run: p1
	./p1

clean:
	rm -rf p1
	rm -rf *.o



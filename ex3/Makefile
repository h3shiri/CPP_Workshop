CC=g++
flags=-Wextra -Wall -Wvla -pthread -std=c++11

default: clean GenericMatrixDriver

main.o: main.cpp Matrix.hpp
	$(CC) $(flags) -c main.cpp -o main

main: main.o Matrix.o
	$(CC) $(flags) Matrix.o main.o -o main
	./main

GenericMatrixDriver: GenericMatrixDriver.o Complex.o
	$(CC) $(flags) GenericMatrixDriver.o Complex.o -o GenericMatrixDriver

Matrix: Matrix.hpp Complex.h
	$(CC) $(flags) -c Matrix.hpp

GenericMatrixDriver.o: GenericMatrixDriver.cpp
	$(CC) $(flags) -c GenericMatrixDriver.cpp -o GenericMatrixDriver.o

Complex.o: Complex.cpp Complex.h
	$(CC) $(flags) -c Complex.cpp -o Complex.o

tar: Makefile Matrix.hpp
	tar cvf ex3.tar Makefile Matrix.hpp 

clean:
	rm -f *.o GenericMatrixDriver main Matrix ex3.tar *.gch
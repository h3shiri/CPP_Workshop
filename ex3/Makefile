CC=g++
flags=-Wextra -Wall -Wvla -pthread -std=c++11

default: clean GenericMatrixDriver

main.o: main.cpp Matrix.hpp
	$(CC) $(flags) -c main.cpp -o main.o

main:
	./main

GenericMatrixDriver: GenericMatrixDriver.o Matrix.o
	$(CC) $(flags) Matrix.o GenericMatrixDriver.o -o GenericMatrixDriver

GenericMatrixDriver.o: GenericMatrixDriver.cpp Matrix.hpp
	$(CC) $(flags) -c GenericMatrixDriver.cpp -o GenericMatrixDriver.o

Matrix.hpp.gch: Matrix.hpp
	$(CC) $(flags) -c Matrix.hpp -o Matrix.hpp.gch

Matrix.o: Matrix.hpp.gch
	$(CC) $(flags) -c Matrix.hpp.gch -o Matrix.o

tar: Makefile README $(all_headers) $(all_cpp)
	tar cvf ex3.tar Makefile Matrix.hpp 

clean:
	rm -f *.o GenericMatrixDriver ex3.tar *.gch
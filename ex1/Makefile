CC=g++
flags=-Wextra -Wall -Wvla -pthread -std=c++11

all: ConvexHull PointSetBinaryOperations
	./PointSetBinaryOperations
Point.o: Point.cpp Point.h
	$(CC) $(flags) -c Point.cpp -o Point.o 
PointSet.o: PointSet.cpp PointSet.h
	$(CC) $(flags) -c PointSet.cpp -o PointSet.o 
ConvexHull.o: ConvexHull.cpp
	$(CC) $(flags) -c ConvexHull.cpp -o ConvexHull.o 
ConvexHull: ConvexHull.o PointSet.o Point.o
	$(CC) $(flags) Point.o PointSet.o ConvexHull.o -o ConvexHull
PointSetBinaryOperations: PointSetBinaryOperations.o PointSet.o Point.o
	$(CC) $(flags) Point.o PointSet.o PointSetBinaryOperations.o -o PointSetBinaryOperations
PointSetBinaryOperations.o: PointSetBinaryOperations.cpp
	$(CC) $(flags) -c PointSetBinaryOperations.cpp -o PointSetBinaryOperations.o
tar: ConvexHull.cpp PointSet.cpp Point.h PointSet.h Makefile README PointSetBinaryOperations.cpp
	tar cvf ex1.tar ConvexHull.cpp Point.cpp PointSet.cpp Point.h PointSet.h Makefile README PointSetBinaryOperations.cpp
clean:
	rm -f Point.o PointSet.o ConvexHull.o ex1.tar ConvexHull PointSetBinaryOperations PointSetBinaryOperations.o

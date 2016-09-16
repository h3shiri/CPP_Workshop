CC=g++
flags=-Wextra -Wall -Wvla -pthread -std=c++11
all_headers=Defs.h Edge.h Point.h Polygon.h PrintOuts.h ShapeAlgorithms.h SimpleTrapez.h  Triangle.h
all_cpp=Edge.cpp Point.cpp Polygon.cpp PrintOuts.cpp ShapeAlgorithms.cpp Shapes.cpp SimpleTrapez.cpp Triangle.cpp 

default: clean Shapes

Point.o: Point.cpp Point.h Defs.h
	$(CC) $(flags) -c Point.cpp -o Point.o

Edge.o: Edge.cpp Edge.h 
	$(CC) $(flags) -c Edge.cpp -o Edge.o

Polygon.o: Polygon.cpp Polygon.h ShapeAlgorithms.h PrintOuts.h
	$(CC) $(flags) -c Polygon.cpp -o Polygon.o

ShapeAlgorithms.o: ShapeAlgorithms.cpp ShapeAlgorithms.h Point.h Edge.h
	$(CC) $(flags) -c ShapeAlgorithms.cpp -o ShapeAlgorithms.o

PrintOuts.o: PrintOuts.cpp PrintOuts.h
	$(CC) $(flags) -c PrintOuts.cpp -o PrintOuts.o

SimpleTrapez.o: SimpleTrapez.cpp SimpleTrapez.h Polygon.h
	$(CC) $(flags) -c SimpleTrapez.cpp -o SimpleTrapez.o

Triangle.o: Triangle.cpp Triangle.h Polygon.h
	$(CC) $(flags) -c Triangle.cpp -o Triangle.o

Shapes.o: Shapes.cpp Triangle.h SimpleTrapez.h
	$(CC) $(flags) -c Shapes.cpp -o Shapes.o

Shapes: Point.o Edge.o Polygon.o ShapeAlgorithms.o PrintOuts.o SimpleTrapez.o Triangle.o Shapes.o
	$(CC) $(flags) Shapes.o Point.o Edge.o Polygon.o ShapeAlgorithms.o PrintOuts.o SimpleTrapez.o Triangle.o -o Shapes

tar: Makefile README $(all_headers) $(all_cpp)
	tar cvf ex2.tar Makefile README $(all_headers) $(all_cpp)

clean:
	rm -f *.o Shapes ex2.tar

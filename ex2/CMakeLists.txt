cmake_minimum_required(VERSION 3.3)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Defs.h
    PrintOuts.cpp
    PrintOuts.h Polygon.cpp Polygon.h Edge.cpp Edge.h Point.cpp Point.h ShapeAlgorithms.cpp ShapeAlgorithms.h Triangle.cpp Triangle.h Shapes.cpp SimpleTrapez.cpp SimpleTrapez.h)

add_executable(ex2 ${SOURCE_FILES})
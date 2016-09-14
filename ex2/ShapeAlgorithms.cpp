#include <iostream>
#include "Point.h"

/**
 * A useful function calculating the directed area of a given triangle.
 * @param A - the first point.
 * @param B - the second point.
 * @param C - the third point.
 * @return - the appropriate value.
 */
double directedTriangleArea(const Point A, const Point B, const Point C){
    return (0.5 * (((B.getX() * C.getY()) - (C.getX() * B.getY())) - ((A.getX() * C.getY()) - (C.getX() * A.getY())) +
            ((A.getX() * B.getY()) - (A.getY() * B.getX()))));
}

//TODO: remove silly main
//int main()
//{
//    Point p_A = Point();
//    CordType X = 5;
//    CordType Y = 0;
//    Point p_B = Point(X,Y);
//    Point p_C = Point(3,3);
//
//    std::cout << directedTriangleArea(p_B, p_A, p_C) << "\n";
//    return 0;
//}
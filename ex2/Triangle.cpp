
#include "Triangle.h"

/**
 * The default constructor for the triangle class
 * @param A - the first point.
 * @param B -  the second point.
 * @param C - the third point.
 */
Triangle::Triangle(const Point A = Point(), const Point B = Point (), const Point C = Point())
{
    Edge AB = Edge(A, B);
    Edge BC = Edge(B, C);
    Edge CA = Edge(C, A);
    addEdge(AB);
    addEdge(BC);
    addEdge(CA);
    addPoint(A);
    addPoint(B);
    addPoint(C);
}

bool Triangle::checkValidity() const
{

}



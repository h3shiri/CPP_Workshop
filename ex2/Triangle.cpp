
#include "Triangle.h"

/**
 * The default constructor for the triangle class
 * @param A - the first point.
 * @param B -  the second point.
 * @param C - the third point.
 */
Triangle::Triangle(const Point A, const Point B, const Point C)
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

/**
 * An important function checking dor the validity of this triangle.
 * @return - true iff this triangle is valid.
 */
bool Triangle::checkValidity() const
{
    Point A = (getPoints()[0]);
    Point B = (getPoints()[1]);
    Point C = (getPoints()[2]);

    /* first check all the points are distinct */
    if((A == B) || (B == C) || (A == C))
    {
        return false;
    }

    /* in case the triangle has no area */
    double k = directedTriangleArea(A, B, C);
    if (( -EPSILON < k) && (k < EPSILON))
    {
        return false;
    }
    /* passed all validity conditions */
    return true;
}

/**
 * A simple function returning the number of sides
 * @return - the appropriate number of sides.
 */
int Triangle::getNumberOfSides() const
{
    return _numOfSizes;
}


/**
 * An important function that returns the polygon's area.
 * @return - the appropriate value.
 */
CordType Triangle::totalArea() const
{
    Point A = getPoints()[0];
    Point B = getPoints()[1];
    Point C = getPoints()[2];
    return fabs(directedTriangleArea(A, B, C));
}

/**
 * an important function returning shape's type.
 * @return - the appropriate string.
 */
std::string Triangle::getName() const
{
    return _name;
}


/**
 * A utility function for printing this triangle.
 */
void Triangle::printShape() const
{
    Point A = getPoints()[0];
    Point B = getPoints()[1];
    Point C = getPoints()[2];
    printTrig(A.getX(), A.getY(), B.getX(), B.getY(), C.getX(), C.getY());
}

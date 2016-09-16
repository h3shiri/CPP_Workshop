

#include "SimpleTrapez.h"

/**
 * The default constructor for the triangle class
 * @param A - the first point.
 * @param B -  the second point.
 * @param C - the third point.
 * @param D - the forth point.
 */
SimpleTrapez::SimpleTrapez(const Point A, const Point B, const Point C, const Point D)
{
    Edge AB = Edge(A, B);
    Edge Bc = Edge(B, C);
    Edge CD = Edge(C, D);
    Edge DA = Edge(D, A);
    addEdge(AB);
    addEdge(Bc);
    addEdge(CD);
    addEdge(DA);
    addPoint(A);
    addPoint(B);
    addPoint(C);
    addPoint(D);
}

/**
 * An important function checking dor the validity of this simple trapeze.
 * @return - true iff this triangle is valid.
 */
bool SimpleTrapez::checkValidity() const
{
    Point A = getPoints()[0];
    Point B = getPoints()[1];
    Point C = getPoints()[2];
    Point D = getPoints()[3];

    /* test all the points are distinct */
    for (int i = 0; i < (getNumberOfSides() - 1); ++i)
    {
        for (int j = i + 1; j < getNumberOfSides(); ++j)
        {
            if (getPoints()[i] == getPoints()[j])
            {
                return false;
            }
        }
    }

    /* test that the base sides are parallel to the X-axis */
    if ((A.getY() != B.getY()) || (C.getY() != D.getY()))
    {
        return false;
    }

    /* passed all the validity tests */
    return true;
}

/**
 * A simple function returning the number of sides
 * @return - the appropriate number of sides.
 */
int SimpleTrapez::getNumberOfSides() const
{
    return _numOfSizes;
}

/**
 * An important function that returns the polygon's area.
 * @return - the appropriate value.
 */
CordType SimpleTrapez::totalArea() const
{
    Point A = getPoints()[0];
    Point B = getPoints()[1];
    Point C = getPoints()[2];
    Point D = getPoints()[3];
    /* Calculating by breaking it up to two triangles along the diagonal */
    return ((fabs(directedTriangleArea(A, B, C))) + (fabs(directedTriangleArea(A, C, D))));
}

/**
 * an important function returning shape's type.
 * @return - the appropriate string.
 */
std::string SimpleTrapez::getName() const
{
    return _name;
}

/**
 * A utility function for printing this trapezium.
 */
void SimpleTrapez::printShape() const
{
    Point A = getPoints()[0];
    Point B = getPoints()[1];
    Point C = getPoints()[2];
    Point D = getPoints()[3];
    printTrapez(A.getX(), A.getY(), B.getX(), B.getY(), C.getX(), C.getY(), D.getX(), D.getY());
}

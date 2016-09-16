#include <iostream>
#include "Polygon.h"

/**
 * A useful function calculating the directed area of a given triangle.
 * @param A - the first point.
 * @param B - the second point.
 * @param C - the third point.
 * @return - the appropriate value.
 */
double directedTriangleArea(const Point A, const Point B, const Point C)
{
    return (0.5 * (((B.getX() * C.getY()) - (C.getX() * B.getY())) - ((A.getX() * C.getY()) - (C.getX() * A.getY())) +
            ((A.getX() * B.getY()) - (A.getY() * B.getX()))));
}

/**
 * A useful function for checking the intersection of two shapes.
 * @param shape1 - the first shape to consider.
 * @param shape2 - the second shape to consider.
 * @return - true iff the shapes intersect.
 */
bool twoShapesIntersectionCheck(Polygon * shape1, Polygon * shape2)
{
    /* testing for edges intersection */
    int i = shape1->getNumberOfSides();
    int j = shape2->getNumberOfSides();
    for (int k = 0; k < i; ++k)
    {
        Edge temp_shape1 = shape1->getEdges()[k];
        for (int l = 0; l < j; ++l)
        {
            Edge temp_shape2 = shape2->getEdges()[l];
            if(temp_shape1.intersection(temp_shape2))
            {
                return true;
            }
        }
    }
    /* testing for internal containment */
    Point A = shape1->getPoints()[0];
    Point B = shape2->getPoints()[0];

    if ((shape1->checkPointIsInside(B)) || (shape2->checkPointIsInside(A)))
    {
        return true;
    }


    return false;
}
//
// Created by h3shiri on 9/14/16.
//

#ifndef EX2_SHAPEALGORITHMS_H
#define EX2_SHAPEALGORITHMS_H

#include <iostream>
#include "Point.h"
#include "Edge.h"

class Polygon;
/**
 * A useful function calculating the directed area of a given triangle.
 * @param A - the first point.
 * @param B - the second point.
 * @param C - the third point.
 * @return - the appropriate value.
 */
double directedTriangleArea(const Point A, const Point B, const Point C);

/**
 * A useful function for checking the intersection of two shapes.
 * @param shape1 - the first shape to consider.
 * @param shape2 - the second shape to consider.
 * @return - true iff the shapes intersect.
 */
bool twoShapesIntersectionCheck(Polygon * shape1, Polygon * shape2);

#endif //EX2_SHAPEALGORITHMS_H

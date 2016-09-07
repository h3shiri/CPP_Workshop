//
// Created by Shiri on 9/7/16.
//

#ifndef EX1_CONVEXHULL_H
#define EX1_CONVEXHULL_H


#include "PointSet.h"
class ConvexHull {

};
class Vec{
private:
    int x_coordinate;
    int y_coordinate;

public:
    Vec(int x_value = 0, int y_value = 0);
    Vec(Point pointA, Point pointB);
    int dotProduct(const Vec& rhs);
    int crossProduct(const Vec& rhs);

    int getX_coordinate() const;
    int getY_coordinate() const;

};


#endif //EX1_CONVEXHULL_H

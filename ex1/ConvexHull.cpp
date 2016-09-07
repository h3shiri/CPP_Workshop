//
// Created by Shiri on 9/7/16.
//
#include "PointSet.h"
#include "ConvexHull.h"
#include <math.h>

/**
 * A default constructor
 * @param x_value
 * @param y_value
 * @return
 */
Vec::Vec(int x_val, int y_val){
    x_cor = x_val;
    y_cor = y_val;
}

/**
 * A secondary constructor made from 2 points
 * @param pointA - first point
 * @param pointB - second point
 * @return - the relevant 2D vector.
 */
Vec::Vec(Point pointA, Point pointB){
    x_cor = (pointB.getX() - pointA.getX());
    y_cor = (pointB.getY() - pointA.getY());
}

/**
 * A simple dot product.
 * @param rhs - the right hand side argument.
 * @return - the resulting dot product.
 */
double Vec::dotProduct(const Vec& rhs) const {
    return ((getX_coordinate()*rhs.getX_coordinate()) + (getY_coordinate()*rhs.getY_coordinate()));
}

/**
 * A vector cross product value.
 * @param rhs - the second vector argument.
 * @return - the appropriate cross value.
 */
int Vec::crossProduct(const Vec& rhs) const{
    return ((getX_coordinate()*rhs.getY_coordinate()) - (rhs.getX_coordinate()*getY_coordinate()));
}

/**
 * Returns the norm of the vector.
 * @return - the appropriate value.
 */
double Vec::norm() const {
    return sqrt(getX_coordinate()*getX_coordinate() + getY_coordinate()*getY_coordinate());
}

/**
 * Calculating the angle between two vectors.
 * @param rhs - the target argument.
 * @return - the appropriate value for cosine in Radians.
 */
double Vec::getAngle(const Vec& rhs){
    return (dotProduct(rhs)/(norm()*rhs.norm()));
}

/**
 * A getter function for the y coordinate.
 * @return - the appropriate y value of the vector.
 */
int Vec::getX_coordinate() const {
    return x_cor;
}
/**
 * A getter function for the x-coordinate
 * @return - the appropriate x value
 */
int Vec::getY_coordinate() const {
    return y_cor;
}





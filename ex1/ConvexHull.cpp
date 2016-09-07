//
// Created by Shiri on 9/7/16.
//

#include "ConvexHull.h"

/**
 * A default constructor
 * @param x_value
 * @param y_value
 * @return
 */
Vec::Vec(int x_value = 0, int y_value = 0){
    x_coordinate = x_value;
    y_coordinate = y_value;
}

Vec::Vec(Point pointA, Point pointB){
    x_coordinate = (pointB.getX() - pointA.getX());
    y_coordinate = (pointB.getY() - pointA.getY());
}

/**
 * A simple dot product.
 * @param rhs - the right hand side argument.
 * @return - the resulting dot product.
 */
int Vec::dotProduct(const Vec& rhs){
    return ((getX_coordinate()*rhs.getX_coordinate()) + (getY_coordinate()*rhs.getY_coordinate()));
}

/**
 * A vector cross product value.
 * @param rhs - the second vector argument.
 * @return - the appropriate cross value.
 */
int Vec::crossProduct(const Vec& rhs){
    return ((getX_coordinate()*rhs.getY_coordinate()) - (rhs.getX_coordinate()*getY_coordinate()));
}

/**
 * A getter function for the y coordinate.
 * @return - the appropriate y value of the vector.
 */
int Vec::getX_coordinate() const {
    return x_coordinate;
}
/**
 * A getter function for the x-coordinate
 * @return - the appropriate x value
 */
int Vec::getY_coordinate() const {
    return y_coordinate;
}





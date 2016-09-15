

#ifndef EX2_SIMPLETRAPEZ_H
#define EX2_SIMPLETRAPEZ_H

#include "Polygon.h"

/**
 * SimpleTrapeze a general representation of a trapez.
 */
class SimpleTrapez : public Polygon
{
public:
    /**
     * The default constructor for the triangle class
     * @param A - the first point.
     * @param B -  the second point.
     * @param C - the third point.
     * @param D - the forth point.
     */
    SimpleTrapez(const Point A = Point(), const Point B = Point (), const Point C = Point(), const Point D = Point());

    /**
     * An important function checking dor the validity of this simple trapeze.
     * @return - true iff this triangle is valid.
     */
    bool checkValidity() const;

    /**
     * A simple function returning the number of sides
     * @return - the appropriate number of sides.
     */
    int getNumberOfSides() const;

    /**
     * An important function that returns the polygon's area.
     * @return - the appropriate value.
     */
    CordType totalArea() const;

    /**
     * an important function returning shape's type.
     * @return - the appropriate string.
     */
    std::string getName() const;

    /**
     * A utility function for printing this trapezium.
     */
    void printShape() const;

private:
    const int _numOfSizes = 4;
    const std::string _name = "SimpleTrapez";
};


#endif //EX2_SIMPLETRAPEZ_H

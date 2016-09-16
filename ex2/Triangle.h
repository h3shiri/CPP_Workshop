
#ifndef EX2_TRIANGLE_H
#define EX2_TRIANGLE_H


#include "Polygon.h"

/**
 * @brief triangle three vertexes three edges, A classic representation of 
 * the holy triangle.
 */
class Triangle : public Polygon
{
public:
    /**
     * The default constructor for the triangle class
     * @param A - the first point.
     * @param B -  the second point.
     * @param C - the third point.
     */
    Triangle(const Point A = Point(), const Point B = Point (), const Point C = Point());

    /**
     * An important function checking dor the validity of this triangle.
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
     * A utility function for printing this triangle.
     */
    void printShape() const;

private:
    const int _numOfSizes = 3;
    const std::string _name = "Triangle";
};


#endif //EX2_TRIANGLE_H

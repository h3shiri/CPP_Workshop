
#ifndef EX2_TRIANGLE_H
#define EX2_TRIANGLE_H


#include "Polygon.h"

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


    bool checkValidity() const;
private:
};


#endif //EX2_TRIANGLE_H

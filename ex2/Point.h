

#ifndef EX2_POINT_H
#define EX2_POINT_H

#include "Defs.h"

class Point {
public:
    /**
     * The default constructor for the point class.
     */
    Point(CordType x_value = 0.0, CordType y_value = 0.0);

    /**
     * A getter function for the X value.
     * return - the appropriate  X-value.
     */
    const CordType getX() const ;

    /**
     * A getter function for the Y value.
     * return - the appropriate  Y-value.
     */
    const CordType getY() const ;

    /**
     * A setter function for the internal coordinates.
     * @param x_value - the relevant data for the X coordinate.
     * @param y_value - the relevant data for the Y coordinate.
     */
    void setCoordinates(CordType x_value, CordType y_value);

private:
    CordType _Xvalue;
    CordType _Yvalue;
};


#endif //EX2_POINT_H
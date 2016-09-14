
#include "Point.h"

/**
 * The default constructor for the point class.
 */
Point::Point(CordType x_value, CordType y_value)
{
    _Xvalue = x_value;
    _Yvalue = y_value;
}

/**
 * A getter function for the X value.
 * return - the appropriate  X-value.
 */
const CordType Point::getX() const
{
    return _Xvalue;
}

/**
 * A getter function for the Y value.
 * return - the appropriate  Y-value.
 */
const CordType Point::getY() const
{
    return _Yvalue;
}

/**
 * A setter function for the internal coordinates.
 * @param x_value - the relevant data for the X coordinate.
 * @param y_value - the relevant data for the Y coordinate.
 */
void Point::setCoordinates(CordType x_value, CordType y_value)
{
    this->_Xvalue = x_value;
    this->_Yvalue = y_value;
}

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
CordType Point::getX() const
{
    return _Xvalue;
}

/**
 * A getter function for the Y value.
 * return - the appropriate  Y-value.
 */
CordType Point::getY() const
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

/**
 * A copy assignment for the equal operator.
 * @param rhs - the element to be copied from.
 * @return - the relevant element after copying.
 */
Point& Point::operator=(const Point& rhs)
{
    this->setCoordinates(rhs.getX(), rhs.getY());
    return *this;
}

/**
 * Overloading the equality operator with epsilon error.
 * @param rhs - the target point to be compared with.
 * return true - iff the points are equal up to epsilon error.
 */
bool Point::operator==(const Point& rhs)
{
    double diffX = std::fabs((getX() - rhs.getX()));
    double diffY = std::fabs((getY() - rhs.getY()));
    double totalDiff = (diffX + diffY);
    return (totalDiff < EPSILON);
}
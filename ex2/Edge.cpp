
#include "Edge.h"
#define POSITIVE 1
#define NEGATIVE -1
#define ZERO 0

/**
 * The default constructor for the edge class.
 */
Edge::Edge(const Point pointA, const Point pointB)
{
    _pointA = pointA;
    _pointB = pointB;
}

/**
 * A getter function for the first point.
 * @return - the appropriate value.
 */
Point Edge::getFirstPoint () const
{
    return _pointA;
}


/**
 * A getter function for the second point.
 * @return - the appropriate value.
 */
Point Edge::getSecondPoint() const
{
    return _pointB;
}

/**
 * A utility function checking whether the target point is on the right hand side
 * or the left hand side.
 * @param target - the given point to be compared with.
 * return - positive if the given point is on the left hand side, negative in case its on the right
 * and zero in case its on this edge.
 */
int Edge::checkSide(const Point target) const
{
    double swag = directedTriangleArea(getFirstPoint(), getSecondPoint(), target);
    /* error checking for epsilon */
    if ((-EPSILON < swag) && (swag < EPSILON)){
        swag = ZERO;
    }

    if (swag < ZERO)
    {
        return POSITIVE;
    }
    else if (swag > ZERO)
    {
        return NEGATIVE;
    }
    else
    {
        return ZERO;
    }
}


/**
 * An important function checking for an intersection with another edge.
 */
bool Edge::intersection(const Edge rhs)
{
    bool check1 = ((checkSide(rhs.getFirstPoint()) * checkSide(rhs.getSecondPoint())) == NEGATIVE);
    bool check2 = ((rhs.checkSide(getFirstPoint()) * rhs.checkSide(getSecondPoint())) == NEGATIVE);

    return (check1 && check2);
}


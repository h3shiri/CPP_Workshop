
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

// TODO: remove redundant main..

int main()
{
    Point p_A = Point();
    CordType X = 5;
    CordType Y = 0;
    Point p_B = Point(X,Y);
    Point p_C = Point(3,3);
    Point p_D = Point(2,-2);
    Edge e1 = Edge(p_A, p_B);
    Edge e2 = Edge(p_C, p_D);

    std::cout << "check intersection: ";
    std::cout << e1.intersection(e2) << "\n";

    return 0;
}
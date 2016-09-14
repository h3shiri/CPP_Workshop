
#ifndef EX2_EDGE_H
#define EX2_EDGE_H

#include "ShapeAlgorithms.h"
#include "Point.h"

class Edge
{
public:
    /**
     * The default constructor for the edge class.
     */
    Edge(const Point pointA = Point(), const Point pointB = Point());

    /**
     * A getter function for the first point.
     * @return - the appropriate value.
     */
    Point getFirstPoint() const;

    /**
     * A getter function for the second point.
     * @return - the appropriate value.
     */
    Point getSecondPoint() const;

    /**
     * An important function checking for an intersection with another edge.
     */
    bool intersection(const Edge rhs);

    /**
     * A utility function checking whether the target point is on the right hand side
     * or the left hand side.
     * @param target - the given point to be compared with.
     * return - positive if the given point is on the left hand side, negative in case its on the right
     * and zero in case its on this edge.
     */
    int checkSide(const Point target) const;


private:
    Point _pointA;
    Point _pointB;
};


#endif //EX2_EDGE_H



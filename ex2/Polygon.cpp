#include "Polygon.h"

/**
 * The default constructor.
 */
Polygon::Polygon()
{
    return;
}

/**
 * A simple function adding an edge into the polygon edges.
 * @param edge - the new edge that shall be appended.
 */
void Polygon::addEdge(const Edge edge)
{
    _sides.push_back(edge);
}

/**
 * A simple function adding a point into the polygon points.
 * @param edge - the new edge that shall be appended.
 */
void Polygon::addPoint(const Point point)
{
    _points.push_back(point);
}

/**
 * A getter function for the edges vector.
 * @return - the appropriate vector of edges
 */
std::vector<Edge> Polygon::getEdges()
{
    return _sides;
}

/**
 * A getter function for the points vector.
 * @return - the appropriate vector of points.
 */
std::vector<Point> Polygon::getPoints() const
{
    return _points;
}


/**
 * A simple destructor no memory to release.
 */
Polygon::~Polygon()
{
    return;
}
/**
 * A utility function checking whether a given point is inside the shape.
 * @param target - the given point o be checked.
 * @return - true iff the point in inside the shape.
 */
bool Polygon::checkPointIsInside(const Point& target)
{
    bool res = true;
    int side = getEdges()[0].checkSide(target);
    for (int i = 0; i < getNumberOfSides(); ++i)
    {
        if(side != getEdges()[i].checkSide(target))
        {
            res = false;
        }
    }
    return res;
}

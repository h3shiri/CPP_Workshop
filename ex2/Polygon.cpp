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
std::vector<Point> Polygon::getPoints()
{
    return _points;
}


/**
 * A simple destructor.
 */
Polygon::~Polygon()
{
    return;
}
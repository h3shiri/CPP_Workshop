

#ifndef EX2_POLYGON_H
#define EX2_POLYGON_H


#include <vector>
#include "Edge.h"

class Polygon {
public:
    virtual Polygon() = delete;

    /**
     * A simple function adding an edge into the polygon edges.
     * @param edge - the new edge that shall be appended.
     */
    virtual void AddEdge(const Edge edge);

    /**
     * A simple function adding a point into the polygon points.
     * @param edge - the new edge that shall be appended.
     */
    virtual void AddPoint(const Point point);

    /**
     * A getter function for the edges vector.
     * @return - the appropriate vector of edges
     */
    std::vector<Edge> getEdges();

    /**
     * A getter function for the points vector.
     * @return - the appropriate vector of points.
     */
    std::vector<Point> getPoints();

private:
    std::vector<Edge> _sides;
    std::vector<Point> _points;
};


#endif //EX2_POLYGON_H

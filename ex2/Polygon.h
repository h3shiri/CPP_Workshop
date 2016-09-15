

#ifndef EX2_POLYGON_H
#define EX2_POLYGON_H


#include <vector>
#include "Edge.h"

class Polygon
{
public:
    /**
     * The default constructor.
     */
    Polygon();

    /**
     * A simple destructor.
     */
    virtual ~Polygon();

    /**
     * A simple function adding an edge into the polygon edges.
     * @param edge - the new edge that shall be appended.
     */
    virtual void addEdge(const Edge edge);

    /**
     * A simple function adding a point into the polygon points.
     * @param edge - the new edge that shall be appended.
     */
    virtual void addPoint(const Point point);

    /**
     * A getter function for the edges vector.
     * @return - the appropriate vector of edges
     */
    std::vector<Edge> getEdges();

    /**
     * A getter function for the points vector.
     * @return - the appropriate vector of points.
     */
    std::vector<Point> getPoints() const;

    /**
     * A simple function returning the number of sides
     * @return - the appropriate number of sides.
     */
    virtual int getNumberOfSides() const = 0;

    /**
     * A utility function checking whether a given point is inside the shape.
     * @param target - the given point o be checked.
     * @return - true iff the point in inside the shape.
     */
    bool checkPointIsInside(const Point& target);

    /**
     * An important function that returns the polygon's area.
     * @return - the appropriate value.
     */
    virtual CordType totalArea() const = 0;

    /**
     * An important function checking dor the validity of this shape.
     * @return - true iff this shape is valid.
     */
    virtual bool checkValidity() const = 0;

    /**
     * an important function returning shape's type.
     * @return - the appropriate string.
     */
    virtual std::string getName() const = 0;

private:
    std::vector<Edge> _sides;
    std::vector<Point> _points;
};


#endif //EX2_POLYGON_H


#ifndef EX1_POINT_H
#define EX1_POINT_H


#include <string>
#include <iostream>

/**
 * A point class representing a Point in a two dimensional array.
 */
class Point 
{
/** data members */
private:
    int x_coordinate;
    int y_coordinate;

public:
    /**
     * The class constructor
     * @param x_coordinate - the x coordinate value.
     * @param y_coordinate - the y coordinate value.
     * @return
     */
    Point(int x_coordinate = 0, int y_coordinate = 0);
    
    /**
     * No memory to free so nothing to destruct.
     */
    ~Point();

    /**
     * A getter function for the x coordiante.
     * @return - the appropriate value.
     */
    int getX() const;

    /**
     * A getter function for the y coordinate.
     * @return the appropriate value.
     */
    int getY() const;

    /**
     * A setter function for a different set of coordinates.
     * @param x_value - the adjusted x value.
     * @param y_value - the adjusted y value.
     */
    void set(const int x_value , const int y_value);

    /**
     * A toString function that outputs a point as a string
     * @return A string in the format: x_coordinate , y_coordinate.
     */
    std::string toString() const;

    /**
     * Overloading the == operator for Points.
     * @param rhs - the element to be checked whether its equal.
     * @return true iff the x-value and y-value are matching.
     */
    bool operator==(const Point& rhs);

    /**
     * A copy assingment for the equal operator.
     * @param rhs - the element to be copied from.
     * @return - the relevant element after copying.
     */
    Point &operator=(const Point& rhs);

    /**
     * An overloading of the smaller then operator (weak ordering)
     * @param rhs - the given node target to be compared with.
     * @return true - iff the element's data is strictly less then the target node's data.
     */
    bool operator<(const Point& rhs);

    /**
     * A utillity function checking whether the points are arranged in a counter clockwise
     * with prespective to p1 as base.
     * @param p1 - the first point.
     * @param p2 - the second point.
     * @param p3 - the third point.
     * @return - positive if the point are arraged in a counter clockwise turn, zero if alinged and negative otherwise.
     */
    static int counterClockWise(const Point& p1, const Point& p2, const Point& p3);

    /**
     * A simple dot product.
     * @param rhs - the right hand side argument.
     * @return - the resulting dot product.
     */
    int dotProduct(const Point& rhs) const;
};

/**
 * A class representing a Node which contains data and a pointer to another
 * possible node.
 */
class Node
{
/** data members */
private:
    Point data;
    Node *next;
public:
    /**
     * A default constructor.
     * @return
     */
    Node();

    /**
     * A copy constructor.
     * @param node - the node to copy from
     * @return
     */    
    Node(const Node& node);

    /**
     * A constructor from a given point.
     * @param point
     * @return
     */
    Node(const Point& point);

    /**
     * A setter function for the next node parameter.
     * @param next - A pointer to the next node to be set.
     */
    void setNext(Node *next);

     /**
      * A setter function for the node's point data.
      * @param data - the new point data.
      */
    void setData(const Point &data);

    /**
     * A getter function for the node's pointer to the next element.
     * @return - pointer to the next node.
     */
    Node *getNext() const;

    /**
     * A getter function for the node's data
     * @return - the relevant point data.
     */    
    Point getData() const;

    /**
     * An overloading of the equal operator between two nodes.
     * @param rhs - the node to be compared to.
     * @return true - iff the nodes have the same data.
     */
    bool operator==(const Node& rhs);

    /**
     * A destructor function for the node.
     */
    ~Node();
};


#endif //EX1_POINT_H

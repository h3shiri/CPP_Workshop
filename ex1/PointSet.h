//
// Created by Shiri on 9/4/16.
//

#ifndef EX1_POINTSET_H
#define EX1_POINTSET_H

#include "Point.h"

/**
 * The pointSet class, stands for a mathematical set contining points
 */
class PointSet 
{
private:
    int numOfElements;
    Node *head;
    Node *tail;

public:

    /**
     * A default constructor of an empty set.
     * @return
     */
    PointSet();

    /**
     * A copy constructor from an existing pointSet.
     * @param size - the size of the array.
     * @param array - the relevant array.
     * @return
     */
    PointSet(const PointSet &sourceSet);

    /**
     * A destructor for the pointSet Class.
     */
    ~PointSet();

    /**
     * A getter function for the array size.
     * @return - the relevant size.
     */
    int size() const;

    /**
     * A getter function for the array pointer.
     * @return - the pointer to the array.
     */
    Node *getHead() const;

    /**
     * A getter function for the last element aka the tail.
     * @return - returns the last element in the list.
     */
    Node *getTail() const;
   
    /**
     * A to string operator for the pointSet class
     * @return - the appropriate set representation as a string
     */
    std::string toString();

    /**
     * Adding a new element into the set.
     * @param element - the new element.
     * @return true iff the lement was successfuly added to the set.
     */
    bool add(const Point &element);

    /**
     * A remove function which take out the target point element.
     * @param point - the target element.
     * @return - true iff the function successfuly took out the target element.
     */
    bool remove(Point &element);

    /**
     * checks whether the set contians an element.
     * @param element - the given target.
     * @return true - iff the element is within the set.
     */
    bool contains(Node &element) const;

    /**
     * A given function that prints out the set in the requierd format
     * @return - the appropriate string corresponding to the set of points sorted lexicographically.
     */
    std::string sortingPrintOut();

    /**
     * A tracking function for resolving the leftmost coordinate.
     * @return - the relevant point.
     */
    Point traceBase();

    /**
     * An overraide of the equal comparison operator.
     * @param rhs - the target set of poits
     * @return - true iff the sets contain the same points.
     */
    bool operator==(const PointSet &rhs);

    /**
     * An override of the not equl operator.
     * @param rhs - the target to be compared with.
     * @return - true iff the sets contain different points.
     */
    bool operator!=(const PointSet &rhs);

    /**
     * This is an override of the substruction operator.
     * @param rhs - the sbstruction set of elements.
     * @return - a new point set without the substruction set.
     */
    PointSet operator-(const PointSet &rhs);

    /**
     * An override to the the and operator.
     * @param rhs - the target point set to be intersected with.
     * @return - A new point set containing only the common elements.
     */
    PointSet operator&(const PointSet &rhs);


};
#endif //EX1_POINTSET_H

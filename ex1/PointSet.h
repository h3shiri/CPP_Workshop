//
// Created by Shiri on 9/4/16.
//

#ifndef EX1_POINTSET_H
#define EX1_POINTSET_H

#include "Point.h"

class PointSet {
private:
    int numOfElements;
    Node *head;
    Node *tail;

public:
    PointSet();

    PointSet(const PointSet &sourceSet);

    ~PointSet();

    int size() const;

    Node *getHead() const;

    Node *getTail() const;

    std::string toString();

    bool add(const Point &element);

    bool remove(Point &element);

    bool contains(Node &element) const;

    std::string sortingPrintOut();

    Point traceBase();


    bool operator==(const PointSet &rhs);

    bool operator!=(const PointSet &rhs);

    PointSet operator-(const PointSet &rhs);

    PointSet operator&(const PointSet &rhs);


};
#endif //EX1_POINTSET_H

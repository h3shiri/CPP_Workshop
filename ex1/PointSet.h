//
// Created by Shiri on 9/4/16.
//

#ifndef EX1_POINTSET_H
#define EX1_POINTSET_H

#include "Point.h"

class PointSet {
private:
    int size;
    Node *head;
    Node *tail;

public:
    PointSet();
    PointSet(const PointSet& sourceSet);

    int getSize() const;
    Node *getHead() const;

    Node *getTail() const;

    bool add(Node& element);

    bool contains(Node& element);
};


#endif //EX1_POINTSET_H

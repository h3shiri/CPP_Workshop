//
// Created by Shiri on 9/4/16.
//

#ifndef EX1_POINTSET_H
#define EX1_POINTSET_H

#include "Point.h"

class PointSet {
private:
    int size;
    Point *array;

public:
    PointSet();
    PointSet(const PointSet& sourceSet);

    int getSize() const;
    Point *getArray() const;

    bool add(const Point element);
};


#endif //EX1_POINTSET_H

//
// Created by Shiri on 9/4/16.
//

#include "PointSet.h"

//TODO: test the copy constructor..etc
/**
 * A copy constructor from an existing pointSet.
 * @param size - the size of the array.
 * @param array - the relevant array.
 * @return
 */
PointSet::PointSet(const PointSet& sourceSet){
    this->size = sourceSet.getSize();
    this->array = new Point[size];
    Point* source = sourceSet.getArray();
    for (int i = 0; i <size ; ++i) {
        this->array[i] = source[i];
    }
}

/**
 * A default constructor of an empty set.
 * @return
 */
PointSet::PointSet() {
    size = 0;
    array = nullptr;
}

/**
 * A getter function for the array size.
 * @return - the relevant size.
 */
int PointSet::getSize() const {
    return size;
}

/**
 * A getter function for the array pointer.
 * @return - the pointer to the array.
 */
Point *PointSet::getArray() const {
    return array;
}

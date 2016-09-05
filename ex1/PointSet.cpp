//
// Created by Shiri on 9/4/16.
//

#include "PointSet.h"
#define ONE 1
//TODO: test this class functionality.
//TODO: add remove/delete functions.
/**
 * A copy constructor from an existing pointSet.
 * @param size - the size of the array.
 * @param array - the relevant array.
 * @return
 */
PointSet::PointSet(const PointSet& sourceSet){
    this->size = sourceSet.getSize();
    const Node *temp = sourceSet.getHead();
    while (temp->getNext() != nullptr){
        Node freshNode = Node(temp->getData());
        this->add(freshNode);
        temp = temp->getNext();
    }
}

/**
 * A default constructor of an empty set.
 * @return
 */
PointSet::PointSet() {
    size = 0;
    head = nullptr;
    tail = nullptr;
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
Node *PointSet::getHead() const {
    return head;
}

/**
 * A getter function for the last element aka the tail.
 * @return - returns the last element in the list.
 */
Node *PointSet::getTail() const {
    return tail;
}

/**
 * checks whether the set contians an element.
 * @param element - the given target.
 * @return true - iff the element is within the set.
 */
bool PointSet::contains(Node& element){
    bool res = true;
    if (size == 0){
        return res;
    } else{
        Node * curr = head;
        while(curr->getNext() != nullptr){
            if(*curr == element){
                return !res;
            } else{
                curr = curr->getNext();
            }
        }
        return res;
    }
}

/**
 * Adding a new element into the set.
 * @param element - the new element.
 * @return true iff the lement was successfuly added to the set.
 */
bool PointSet::add(Node& element){
    bool res = false;
    Node toInsert = *new Node(element);
    /* In case there are no elements */
    if(head == nullptr){
        head = &toInsert;
        tail = &toInsert;
        size++;
        res = true;

    /* Only one element or more in the array */
    } else if (size == ONE){
        if (!(this->contains(element))){
            tail->setNext(&toInsert);
            tail = &toInsert;
            res = true;
        } else{
            res = false;
        }
    }
    return res;
}

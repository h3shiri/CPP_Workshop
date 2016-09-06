//
// Created by Shiri on 9/4/16.
//

#include "PointSet.h"
//TODO: test this class functionality.
//TODO: add remove/delete functions.
/**
 * A copy constructor from an existing pointSet.
 * @param size - the size of the array.
 * @param array - the relevant array.
 * @return
 */
PointSet::PointSet(const PointSet& sourceSet){
    this->numOfElements = sourceSet.size();
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
    numOfElements = 0;
    head = nullptr;
    tail = nullptr;
}

/**
 * A getter function for the array size.
 * @return - the relevant size.
 */
int PointSet::size() const {
    return numOfElements;
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
 * A to string operator for the pointSet class
 * @return - the appropriate set.
 */
std::string PointSet::toString() {
    std::string res = "";
    Node * temp = getHead();
    for(int i = 0;i<size();i++){
        std::string tempStr = temp->getData().toString();
        res = (res + tempStr + '\n');
        temp = temp->getNext();
    }
    return res;
}


/**
 * checks whether the set contians an element.
 * @param element - the given target.
 * @return true - iff the element is within the set.
 */
bool PointSet::contains(Node& element){
    bool res = true;
    if (numOfElements == 0){
        return !res;
    } else{
        Node * curr = head;
        while(curr->getNext() != nullptr){
            if(*curr == element){
                return res;
            } else{
                curr = curr->getNext();
            }
        }
        return !res;
    }
}

/**
 * Adding a new element into the set.
 * @param element - the new element.
 * @return true iff the lement was successfuly added to the set.
 */
bool PointSet::add(Node& element){
    bool res = false;
    Node * toInsert = new Node(element);
    /* In case there are no elements */
    if(size() == 0){
        toInsert->setNext(tail);
        head = toInsert;
        tail = toInsert;
        numOfElements++;
        res = true;

    /* Only one element or more in the array */
    } else if (numOfElements == 1){
        if (!(this->contains(element))){
            tail->setNext(toInsert);
            tail = toInsert;
            numOfElements++;
            res = true;
        } else{
            res = false;
        }
    }
    return res;
}


//TODO: remove silly main
int main(){
    Point p1 = Point(1,1);
    Point p2 = Point(2,2);

    PointSet testSet = PointSet();
    Node * n1 = new Node(p1);
    testSet.add(*n1);
    Node * n2 = new Node(p2);
    testSet.add(*n2);

    Point t3 = Point(1,1);
    Node * n3 = new Node(t3);
    testSet.add(*n3);
    std::cout << "head:  " + testSet.getHead()->getData().toString()+'\n';
    std::cout << "tail:  " + (testSet.getTail()->getData().toString()+"\n");
    std::cout << "number of elements:  " + std::to_string(testSet.size())+'\n';
    std::cout << "set of points:\n" + testSet.toString();

    return 0;
};

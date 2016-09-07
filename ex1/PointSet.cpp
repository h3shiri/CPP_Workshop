//
// Created by Shiri on 9/4/16.
//
#include <array>
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
 * A destructor for the pointSet Class.
 */
PointSet::~PointSet() {
    Node * curr = head;
    while (head){
        head = head->getNext();
        delete(curr);
        curr = head;
    }
    tail = nullptr;
    numOfElements = 0;
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
        while(curr){
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

bool PointSet::remove(Node& element){
    bool res = false;
    if(contains(element)){
        Node * temp = getHead();
        Node * next = temp->getNext();
        if (size() == 1){
            free(head);
            head = nullptr;
            tail = nullptr;
            numOfElements--;
            return !res;
        /* In case we remove the head */
        } else if(temp->getData() == element.getData()){
            free(temp);
            head = next;
            numOfElements--;
            return !res;
        } else{
            while(next){
                if (next->getData() == element.getData()){
                    if (next->getData() == getTail()->getData()){
                        tail = temp;
                    }
                    temp->setNext(next->getNext());
                    free(next);
                    numOfElements--;
                    return !res;
                }
                temp = next;
                next = next->getNext();
            }
        }
    }else{
        return res;
    }
}

/**
 * A given function that prints out the set in the requierd format
 * @return - the appropriate string corresponding to the set of points sorted lexicographically.
 */
std::string PointSet::sortingPrintOut(){
    std::string res = "result\n";
    int const length  = size();
    Point *ar = new Point[length];
    Node * temp = getHead();
    for(int i = 0; i<length; i++){
        Point tempPoint = temp->getData();
        ar[i].set(tempPoint.getX(), tempPoint.getY());
        temp = temp->getNext();
    }
    /* Sorting the elements with simple bubble sort */
    Point swap = Point();
    for (int i = 0 ; i < length; i++){
        for (int j = 0 ; j < length - 1; j++){
            if (!(ar[j] < ar[j+1])){
                swap = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = swap;
            }
        }
    }
    /* arranging the printout */
    for (int i=0; i<length; i++) {
        Point a = ar[i];
        res = (res + a.toString()+ "\n");
    }
    res = (res + '\n');
    delete[] ar;
    return res;
}


//TODO: remove silly main
int main(){
    Point p1 = Point(3,3);
    Point p2 = Point(2,2);

    PointSet testSet = PointSet();
    Node * n1 = new Node(p1);
    testSet.add(*n1);
    Node * n2 = new Node(p2);
    testSet.add(*n2);

    PointSet testSet2 = PointSet();
    testSet.remove(*n2);
    Point t3 = Point(1,1);
    Node * n3 = new Node(t3);
    testSet.add(*n3);
//    std::cout << "head:  " + testSet.getHead()->getData().toString()+'\n';
//    std::cout << "tail:  " + (testSet.getTail()->getData().toString()+"\n");
//    std::cout << "number of elements:  " + std::to_string(testSet.size())+'\n';
    std::cout << "set of points:\n" + testSet.toString();
//    std::cout << (std::to_string(p1<p2)+'\n');
//    std::cout << "set of points:\n" + testSet2.toString();

    std::cout << testSet.sortingPrintOut();
    testSet2.~PointSet();
    testSet.~PointSet();
    std::cout << "check memory\n";
    return 0;
};

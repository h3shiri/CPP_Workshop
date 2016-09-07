//
// Created by Shiri on 9/4/16.
//

#include "Point.h"
using namespace std;

/**
 * The class constructor
 * @param x_coordinate - the x coordinate value.
 * @param y_coordinate - the y coordinate value.
 * @return
 */
Point::Point(int x_coordinate, int y_coordinate) {
    this->x_coordinate = x_coordinate;
    this->y_coordinate = y_coordinate;
}

/**
 * A getter function for the x coordiante.
 * @return - the appropriate value.
 */
int Point::getX() const { return x_coordinate;}

/**
 * A getter function for the y coordinate.
 * @return the appropriate value.
 */
int Point::getY() const { return y_coordinate;}

/**
 * A setter function for a different set of coordinates.
 * @param x_value - the adjusted x value.
 * @param y_value - the adjusted y value.
 */
void Point::set(const int x_value, const int y_value) {
    this->x_coordinate = x_value;
    this->y_coordinate = y_value;
}

/**
 * A toString function that outputs a point as a string
 * @return A string in the format: x_coordinate , y_coordinate.
 */
string Point::toString() const {
    string s_x = to_string(this->x_coordinate);
    string s_y = to_string(this->y_coordinate);
    return s_x+","+s_y;
}

/**
 * Overloading the == operator for Points.
 * @param rhs - the element to be checked whether its equal.
 * @return true iff the x-value and y-value are matching.
 */
bool Point::operator==(const Point& rhs) {
    if ((this->getX() == rhs.getX()) and (this->getY() == rhs.getY())){
        return true;
    }
    else{
        return false;
    }
}

/**
 * An overloading of the smaller then operator (weak ordering)
 * @param rhs - the given node target to be compared with.
 * @return true - iff the element's data is strictly less then the target node's data.
 */
bool Point::operator<(const Point& rhs){
    Point lhs = *this;
    if(lhs.getX() < rhs.getX()) {
        return true;
    /* in case they have equal X-value, check Y-Values comparison */
    }else if(lhs.getX() == rhs.getX()){
        if(lhs.getY() < rhs.getY()){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

/**
 * A copy assingment for the equal operator.
 * @param rhs - the element to be copied from.
 * @return - the relevant element after copying.
 */
Point& Point::operator=(const Point& rhs){
    this->set(rhs.getX(), rhs.getY());
    return *this;
}
/**
 * No memory to free so nothing to destruct.
 */
Point::~Point() { return;}


/**
 * A default constructor.
 * @return
 */
Node::Node() {
    this->next = nullptr;
    this->data = Point();
}

/**
 * A copy constructor.
 * @param node - the node to copy from
 * @return
 */
Node::Node(const Node& node){
    this->next = nullptr;
    this->setData(node.getData());
}

/**
 * A constructor from a given point.
 * @param point
 * @return
 */
Node::Node(const Point& point){
    this->setData(point);
    this->next = nullptr;
}

/**
 * A destructor function for the node.
 */
Node::~Node() { return;}

/**
 * A getter function for the node's data
 * @return - the relevant point data.
 */
Point Node::getData() const {
    return data;
}

/**
 * A getter function for the node's pointer to the next element.
 * @return - pointer to the next node.
 */
Node* Node::getNext() const {
    return next;
}
 /**
  * A setter function for the node's point data.
  * @param data - the new point data.
  */
void Node::setData(const Point &data) {
    Node::data = data;
}

/**
 * A setter function for the next node parameter.
 * @param next - A pointer to the next node to be set.
 */
void Node::setNext(Node *next) {
    Node::next = next;
}

//TODO: test error in this operator or possibly just remove.
/**
 * An overloading of the equal operator between two nodes.
 * @param rhs - the node to be compared to.
 * @return true - iff the nodes have the same data.
 */
bool Node::operator==(const Node& rhs){
    return (this->getData() == rhs.getData());
}

/**
 * A utillity function checking whether the points are arranged in a
 * @param p1
 * @param p2
 * @param p3
 * @return
 */
int Point::counterClockWise(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.getX()- p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

// TODO: remove tester main eventually.
//int main(){
//    Point p1 = Point(1,3);
//    Point p2 = Point();
//    Point p3 = Point();
//    p3.set(2,2);
//    p2 = p1;
//    Node * n1 = new Node(p3);
//    n1->setNext(new Node(p2));
//    cout << (*n1->getNext()).getData().toString();
//    return 0;
//}


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
string Point::toString() {
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

// TODO: remove tester main eventually.
int main(){
    Point p1 = Point(2,2);
    Point p2 = Point();
    Point p3 = Point();
    p3.set(2,2);
    p2 = p1;
    cout << (p1.toString()) << "\n";
    cout << p2.toString() << "\n";
    return 0;
}
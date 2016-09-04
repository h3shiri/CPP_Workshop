//
// Created by Shiri on 9/4/16.
//

#ifndef EX1_POINT_H
#define EX1_POINT_H


#include <string>
#include <iostream>

class Point {
/** data members */
private:
    int x_coordinate;
    int y_coordinate;

public:
    Point(int x_coordinate = 0, int y_coordinate = 0);
    ~Point();
    int getX() const;
    int getY() const;
    void set(const int x_value , const int y_value);
    std::string toString();
    bool operator==(const Point& rhs);

};


#endif //EX1_POINT_H

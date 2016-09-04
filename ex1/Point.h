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
    int getX();
    int getY();
    void set(int x_value, int y_value);
    std::string toString();
};


#endif //EX1_POINT_H

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
    std::string toString() const;
    bool operator==(const Point& rhs);
    Point &operator=(const Point& rhs);
};

class Node{
/** data memebers */
private:
    Point data;
    Node *next;
public:
    Node();
    Node(const Node& node);
    Node(const Point& point);

    void setNext(Node *next);

    void setData(const Point &data);

    Node *getNext() const;
    Point getData() const;
    bool operator==(const Node& rhs);

    bool operator< (const Node& rhs);

    ~Node();
};


#endif //EX1_POINT_H

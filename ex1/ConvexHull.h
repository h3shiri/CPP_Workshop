//
// Created by Shiri on 9/7/16.
//

#ifndef EX1_CONVEXHULL_H
#define EX1_CONVEXHULL_H


class ConvexHull {
public:
    static Point * sortByAngle(const Point& base, Point * array, int & numOfElements);
    static void removeRedundantPointsOnLine(Point * array, int & numOfElements, int &realLength, Point * res);
};


class Vec{
private:
    int x_cor;
    int y_cor;

public:
    Vec(int x_val = 0, int y_val = 0);
    Vec(Point pointA, Point pointB);
    int getX_coordinate() const;
    int getY_coordinate() const;

    double dotProduct(const Vec& rhs) const;
    int crossProduct(const Vec& rhs) const;
    double norm() const;
    double getAngle(const Vec& rhs);

};


#endif //EX1_CONVEXHULL_H

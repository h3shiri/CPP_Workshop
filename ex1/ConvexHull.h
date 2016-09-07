//
// Created by Shiri on 9/7/16.
//

#ifndef EX1_CONVEXHULL_H
#define EX1_CONVEXHULL_H


class ConvexHull {

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

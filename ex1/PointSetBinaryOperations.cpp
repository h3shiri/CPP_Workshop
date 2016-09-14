//
// Created by h3shiri on 9/11/16.
//

#include "PointSet.h"

/**
 * simulating some of the Point set binary operations.
 */
int main()
{
    PointSet testSet1 = PointSet();
    Point p1 = Point(3, 3);
    Point p2 = Point(2, 2);
    testSet1.add(p1);
    testSet1.add(p2);
    PointSet testSet2 = PointSet();
    testSet2.add(Point(4, 4));

    std::cout << "testing the inequality operator: ";
    if(testSet1 != testSet2)
    {
        std::cout << "Pass\n";
    }
    else
    {
        std::cout << "Fail\n";
    }

    PointSet testSet3 = PointSet();
    std::cout << "testing the logical and operator: ";
    testSet3 = (testSet1 & testSet2);
    if (testSet3.size() == 0)
    {
        std::cout << "Pass\n";
    }
    else
    {
        std::cout << "Fail\n";
    }
    testSet3.add(Point(2, 2));
    testSet3.add(Point(3, 3));
    std::cout << "testing the equality operator: ";
    if(testSet1 == testSet3)
    {
        std::cout << "Pass\n";
    }
    else
    {
        std::cout << "Fail\n";
    }

    return 0;
};

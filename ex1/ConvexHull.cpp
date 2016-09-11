//
// Created by Shiri on 9/7/16.
//
#include "PointSet.h"
#include "ConvexHull.h"
#include <math.h>



#define TRIVIAL_SET_HULL 3
#define BP_INDEX 0
#define NBP_INDEX 1
#define NNBP_INDEX 2
#define LAST_INDEX -1
#define SECLAST_INDEX -2
#define NEWLINE '\n'

/**
 * A default constructor
 * @param x_value
 * @param y_value
 * @return
 */
Vec::Vec(int x_val, int y_val){
    x_cor = x_val;
    y_cor = y_val;
}

/**
 * A secondary constructor made from 2 points
 * @param pointA - first point
 * @param pointB - second point
 * @return - the relevant 2D vector.
 */
Vec::Vec(Point pointA, Point pointB){
    x_cor = (pointB.getX() - pointA.getX());
    y_cor = (pointB.getY() - pointA.getY());
}

/**
 * A simple dot product.
 * @param rhs - the right hand side argument.
 * @return - the resulting dot product.
 */
double Vec::dotProduct(const Vec& rhs) const {
    return ((getX_coordinate()*rhs.getX_coordinate()) + (getY_coordinate()*rhs.getY_coordinate()));
}

/**
 * A vector cross product value.
 * @param rhs - the second vector argument.
 * @return - the appropriate cross value.
 */
int Vec::crossProduct(const Vec& rhs) const{
    return ((getX_coordinate()*rhs.getY_coordinate()) - (rhs.getX_coordinate()*getY_coordinate()));
}

/**
 * Returns the norm of the vector.
 * @return - the appropriate value.
 */
double Vec::norm() const {
    return sqrt(getX_coordinate()*getX_coordinate() + getY_coordinate()*getY_coordinate());
}

/**
 * Calculating the angle between two vectors.
 * @param rhs - the target argument.
 * @return - the appropriate value for cosine in Radians.
 */
double Vec::getAngle(const Vec& rhs){
    return (dotProduct(rhs)/(norm()*rhs.norm()));
}

/**
 * A getter function for the y coordinate.
 * @return - the appropriate y value of the vector.
 */
int Vec::getX_coordinate() const {
    return x_cor;
}
/**
 * A getter function for the x-coordinate
 * @return - the appropriate x value
 */
int Vec::getY_coordinate() const {
    return y_cor;
}


/**
 * sorting an array by angle to relative fixed point.
 * @param base - the base point to filter
 * @param array - the relative array.
 * @return - the sorted array by angle.
 */
Point * ConvexHull::sortByAngle(const Point& base, Point * array, int & numOfElements){
    Point swap = Point();
    for (int i = 0; i < numOfElements; ++i) {
        for (int j = 0; j < numOfElements-1; ++j) {
            if ((Point::counterClockWise(base, array[j], array[j+1])) > 0){
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    return array;
}

void kickMiddle(const Point * pointsOnLine, int nPointsOnLine, Point * edges);

//TODO: test this one extensively.
void ConvexHull::removeRedundantPointsOnLine(Point * array, int & numOfElements,  int &realLength, Point * res)
    {
    if (numOfElements < 3)
    {
        realLength = 3;
        return;
    }
    int finalLength = numOfElements;
    Point  * nonLinearPoints = new Point[numOfElements];
    Point * p1 = &array[0];
    Point * p2 = &array[1];
    Point * p3 = &array[2];
    Point line[3];
    Point edge[2];
    nonLinearPoints[0] = array[0];
    nonLinearPoints[1] = array[1];
    int i = 2;
    for(int j = 0; j < numOfElements - 1 && i < numOfElements;)
    {
        p1 = &nonLinearPoints[j];
        p2 = &nonLinearPoints[j + 1];
        while(i < numOfElements)
        {
            p3 = &array[i];
            if ((Point::counterClockWise(*p1, *p2, *p3)) == 0)
            {
                line[0] = *p1;
                line[1] = *p2;
                line[2] = *p3;
                kickMiddle(line, 3, edge);
                nonLinearPoints[j] = edge[0];
                nonLinearPoints[j + 1] = edge[1];
                finalLength--;
                i++;
            }
            else
            {
                if((j + 2) < numOfElements)
                {
                    nonLinearPoints[j + 2] = array[i];
                    j++;
                    i++;
                    break;
                }
            }
        }
    }
    realLength = finalLength;
        /* inserting the points into the res */
        for (int k = 0; k < realLength; k++) {
            res[k] = nonLinearPoints[k];
        }
        delete[] nonLinearPoints;
}

void push(Point * & stack, const Point & point)
{
    *stack = point;
    stack += 1;
    return;
}

Point pop(Point * & stack)
{
    stack -= 1;
    return *stack;
}

void raiseTheHull(const Point * sortedSet, int nPoints, PointSet & hull, int & nHullElements)
{
    Point * theHolyHull = new Point[nPoints];
    Point * topPtr = theHolyHull;
    int nextPointToCheck = 0;

    if (sortedSet == nullptr)
    {
        return;
    }

    push(topPtr, sortedSet[BP_INDEX]);
    push(topPtr, sortedSet[NBP_INDEX]);

    for (nextPointToCheck = NBP_INDEX + 1; nextPointToCheck < nPoints; nextPointToCheck++)
    {
        if (Point::counterClockWise(topPtr[SECLAST_INDEX],
                                    topPtr[LAST_INDEX],
                                    sortedSet[nextPointToCheck]) <= 0)
        {
            push(topPtr, sortedSet[nextPointToCheck]);
        }
        else
        {
            pop(topPtr);
            nextPointToCheck--;
        }
    }

    nHullElements = topPtr - theHolyHull;

    while (theHolyHull != topPtr)
    {
        hull.add(pop(topPtr));
    }

    delete[] theHolyHull;
    return;
}

void kickMiddle(const Point * pointsOnLine, int nPointsOnLine, Point * edges)
{
    Point greatest(*pointsOnLine);
    Point lowest(*pointsOnLine);
    int index = NBP_INDEX;
    int greatestIndex = 0;
    int lowestIndex = 0;

    if (pointsOnLine[0].getX() == pointsOnLine[1].getX())
    {
        for (index = NBP_INDEX; index < nPointsOnLine; ++index)
        {
            if (pointsOnLine[lowestIndex].getY() >= pointsOnLine[index].getY())
            {
                lowestIndex = index;
            }

            if (pointsOnLine[greatestIndex].getY() <= pointsOnLine[index].getY())
            {
                greatestIndex = index;
            }
        }

        if (greatestIndex < lowestIndex)
        {
            edges[0] = pointsOnLine[greatestIndex];
            edges[1] = pointsOnLine[lowestIndex];
        }
        else
        {
            edges[0] = pointsOnLine[lowestIndex];
            edges[1] = pointsOnLine[greatestIndex];
        }

        return;

    }

    for (index = NBP_INDEX; index < nPointsOnLine; ++index)
    {
        if (pointsOnLine[lowestIndex].getX() >= pointsOnLine[index].getX())
        {
            lowestIndex = index;
        }

        if (pointsOnLine[greatestIndex].getX() <= pointsOnLine[index].getX())
        {
            greatestIndex = index;
        }
    }

    if (greatestIndex < lowestIndex)
    {
        edges[0] = pointsOnLine[greatestIndex];
        edges[1] = pointsOnLine[lowestIndex];
    }
    else
    {
        edges[0] = pointsOnLine[lowestIndex];
        edges[1] = pointsOnLine[greatestIndex];
    }

    return;
}

void findHullForPointSet(const Point * sortedSet, int nPoints, PointSet & hull, int & nHullElements)
{

    if (nPoints <= TRIVIAL_SET_HULL)
    {
        hull.add(sortedSet[BP_INDEX]);
        hull.add(sortedSet[NBP_INDEX]);
        hull.add(sortedSet[NNBP_INDEX]);
    }
    else
    {
        raiseTheHull(sortedSet, nPoints, hull, nHullElements);
    }

}

/**
 * running the convexhull algorithm.
 * firstly requesting user input.
 */
int main(){
    int x;
    char c;
    int y;
    int hullSetSize;
    PointSet hullSet;
    PointSet set = PointSet();
    while(!std::cin.eof())
    {
        std::cin>>x>>c>>y;
//        TODO:remove debug line
        if(c == 'X'){
            break;
        }
        Point freshPoint = Point(x,y);
        set.add(freshPoint);
    }
    std::cout << "checking input reception\n";
    std::cout << set.toString();

    if (set.size() == 0)
    {
        return NEWLINE;
    }
    int length = set.size();
    Point * array = new Point[length];
    Point base = set.traceBase();
    set.remove(base);

    /* setting the base as first element */
    array[0] = base;
    Node * curr = set.getHead();
    for (int i = 0; i < set.size(); i++) {
        array[i+1] = curr->getData();
        curr = curr->getNext();
    }
    array = ConvexHull::sortByAngle(base, array, length);
    /* array has now been sorted by angle */

    PointSet test = PointSet();
    for (int j = 0; j < length; ++j) {
        test.add(array[j]);
    }
    std::cout << "checking the sorting angle sorting\n";
    std::cout << test.toString();

    int realLength = length;
    Point * filteredArray = new Point[length];
    ConvexHull::removeRedundantPointsOnLine(array, length, realLength, filteredArray);
    findHullForPointSet(filteredArray, realLength, hullSet, hullSetSize);
    std::cout << "printing the resulting hullset points\n";
    std::cout << hullSet.toString();
    std::cout << hullSet.sortingPrintOut();

    return 0;
};

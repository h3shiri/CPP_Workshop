//
// Created by Shiri on 9/7/16.
//
#include "PointSet.h"



#define TRIVIAL_SET_HULL 3
#define BP_INDEX 0
#define NBP_INDEX 1
#define NNBP_INDEX 2
#define LAST_INDEX -1
#define SECLAST_INDEX -2
#define NEWLINE '\n'

/**
 * sorting an array by angle to relative fixed point.
 * @param base - the base point to filter
 * @param array - the relative array.
 * @return - the sorted array by angle.
 */
Point * sortByAngle(const Point& base, Point * array, int & numOfElements)
{
    Point swap = Point();
    for (int i = 0; i < numOfElements; ++i) 
    {
        for (int j = 0; j < numOfElements - 1; ++j) 
        {
            if ((Point::counterClockWise(base, array[j], array[j + 1])) > 0)
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
    return array;
}

void kickMiddle(const Point * pointsOnLine, int nPointsOnLine, Point * edges);

void removeRedundantPointsOnLine(Point * array, int & numOfElements,  int &realLength, Point * res)
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
    for(int j = 0; (j < numOfElements - 1) && (i < numOfElements); )
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
        for (int k = 0; k < realLength; k++) 
        {
            res[k] = nonLinearPoints[k];
        }
        delete[] nonLinearPoints;
}

/**
 * The appropriate push function for the stack.
 */
void push(Point * & stack, const Point & point)
{
    *stack = point;
    stack += 1;
    return;
}

/**
 * The appropriate pop function for the stack.
 */
Point pop(Point * & stack)
{
    stack -= 1;
    return *stack;
}

/**
 * The appropriate function that raises the hull.
 */
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
int main()
{
    int x;
    char c;
    int y;
    int hullSetSize;
    PointSet hullSet;
    PointSet set = PointSet();
    while(!std::cin.eof())
    {
        std::cin >> x >> c >> y;
        Point freshPoint = Point(x, y);
        set.add(freshPoint);
    }

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
    for (int i = 0; i < set.size(); i++) 
    {
        array[i + 1] = curr->getData();
        curr = curr->getNext();
    }
    array = sortByAngle(base, array, length);
    /* array has now been sorted by angle */

    int realLength = length;
    Point * filteredArray = new Point[length];
    removeRedundantPointsOnLine(array, length, realLength, filteredArray);
    findHullForPointSet(filteredArray, realLength, hullSet, hullSetSize);
    delete [] filteredArray;
    delete [] array;
    std::cout << hullSet.sortingPrintOut();

    return 0;
}

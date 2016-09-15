#include <iostream>
#include "PrintOuts.h"

static void printPoint(CordType x, CordType y);
/**
* 
**/
void printTrapez(CordType x1, CordType y1, CordType x2, CordType y2, 
                 CordType x3, CordType y3, CordType x4, CordType y4)
{
	std::cout << "Trapez: ";
    printPoint(x1, y1);
    printPoint(x2, y2);
    printPoint(x3, y3);
    printPoint(x4, y4);
    std::cout << std::endl;
}
/**
* 
**/
void printTrig(CordType x1, CordType y1, CordType x2,  CordType y2, CordType x3, CordType y3)
{
    std::cout << "Trig: ";
    printPoint(x1, y1);
    printPoint(x2, y2);
    printPoint(x3, y3);
    std::cout << std::endl;
}
/**
* 
**/
void reportDrawIntersect()
{
    std::cout << "The two draws intersect" << std::endl;
}
/**
* 
**/
void printArea(CordType totalArea)
{
    std::cout << "Total draws areas:" << totalArea << std::endl;
}

/**
* 
**/
void printPoint(CordType x, CordType y)
{
    std::cout << "(" << x << ", " << y << ")  ";
}

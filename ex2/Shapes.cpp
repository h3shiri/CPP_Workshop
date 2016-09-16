#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Triangle.h"
#include "SimpleTrapez.h"

#define TRISIDES 3
#define TRAPEZSIDES 4
#define FAIL -1
#define BUILDERROR "Non valid parameters for building this shape"
#define WRONGPARAMS "Non valid amount of parameters"
#define TRIANGLE 'T'
#define TRAPEZ 't'



/* forward declarations */
Polygon * parseLine(std::string);
void buildTriangle(Polygon * &shape, std::vector<std::string> rawData);
void buildTrapez(Polygon * &shape, std::vector<std::string> rawData);
bool testIntersection(std::vector<Polygon*> array);
void printTotalArea(std::vector<Polygon*> array);

/**
 * main function of the program Shapes.
 */
int main(int argc, char * argv[])
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    /* checking we inserted the right amount of parameters */
    if ((argc != 2) && (argc != 3))
    {
        std::cerr << WRONGPARAMS;
        return FAIL;
    }
    std::streambuf * original_cout = std::cout.rdbuf();
    if (argc == 3)
    {
        static std::ofstream s_outFile(argv[2]);
        std::cout.rdbuf(s_outFile.rdbuf());
    }
    typedef std::vector<Polygon*> Shapes;
    static std::ifstream s_inFile(argv[1]);
    std::streambuf * original_cin =  std::cin.rdbuf();
    std::cin.rdbuf(s_inFile.rdbuf());
    char line[256];
    Shapes array;
    while(std::cin.getline(line, 256))
    {
        Polygon * nextShape = parseLine(std::string(line));
        if (!nextShape->checkValidity())
        {
            std::cerr << BUILDERROR;
            return FAIL;
        }
        array.push_back(nextShape);
    }

    if(testIntersection(array))
    {
        return 0;
    }
    /* In case all the shapes are non intersecting we print the total area */
    printTotalArea(array);

    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);
    return 0;
}

void split(const std::string &source, char delim, std::vector<std::string> & elements);

/**
 * @brief This function parses a line in
 *        the input file.
 * @param line The line to parse.
 * @returns The polygon.
 */
Polygon * parseLine(std::string line)
{
    std::vector<std::string> rawData;
    split(line, '\t', rawData);
    Polygon * res;
    /* break into the shape various cases */
    if(rawData[0][0] == TRIANGLE)
    {
        buildTriangle(res, rawData);
    }
    else if(rawData[0][0] == TRAPEZ)
    {
        buildTrapez(res, rawData);
    }
    return res;
}
using namespace std;

/**
 * @brief The function splits a string in a delimiter and
 *        puts output in vector of string.
 */
void split(const string &source, char delim, vector<string> & elements)
{
    stringstream ss;
    ss.str(source);
    string item;
    while (getline(ss, item, delim))
    {
        elements.push_back(item);
    }
}


/**
 * Autitlity function for building a triangle object from input.
 *@param shape - the pointer that shall contain the new shape.
 *@param rawData - A vector cotaining all the necessary raw data.
 */
void buildTriangle(Polygon * &shape, std::vector<string> rawData)
{
    int j = 0;
    Point coordinates[TRISIDES];
    for (unsigned int i = 1; i < ((2 * TRISIDES) + 1); i = (i + 2))
    {
        CordType X_value = atof(rawData[i].c_str());
        CordType Y_value = atof(rawData[i + 1].c_str());
        Point nextPoint = Point(X_value, Y_value);
        coordinates[j] = nextPoint;
        ++j;
    }
    Triangle * tri = new Triangle(coordinates[0], coordinates[1], coordinates[2]);
    shape = tri;
}

/**
 * Autitlity function for building a simpleTrapez object from input.
 *@param shape - the pointer that shall contain the new shape.
 *@param rawData - A vector cotaining all the necessary raw data.
 */
void buildTrapez(Polygon * &shape, std::vector<string> rawData)
{
    int j = 0;
    Point coordinates[TRAPEZSIDES];
    for (unsigned int i = 1; i < ((2 * TRAPEZSIDES) + 1); i = (i + 2))
    {
        CordType X_value = atof(rawData[i].c_str());
        CordType Y_value = atof(rawData[i + 1].c_str());
        Point nextPoint = Point(X_value, Y_value);
        coordinates[j] = nextPoint;
        ++j;
    }
    SimpleTrapez * tra = new SimpleTrapez(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
    shape = tra;
}

/**
 * An important function testing for shapes intersections and printing appropriate messages.
 * @param array - vector of shapes containing all the relevant shapes.
 */
bool testIntersection(std::vector<Polygon*> array)
{
    for(unsigned int i = 0; i < array.size(); ++i)
    {
        Polygon * shape1 = array[i];
        for (unsigned int j = (i + 1); j < array.size(); ++j)
        {
            Polygon * shape2 = array[j];
            if(twoShapesIntersectionCheck(shape1, shape2))
            {
                shape1->printShape();
                shape2->printShape();
                reportDrawIntersect();
                return true;
            }
        }
    }
    return false;
}

/**
 * A utility function for printing the total area.
 * @param array - vector of shapes containing all the relevant shapes.
 */
void printTotalArea(std::vector<Polygon*> array)
{
    CordType res = 0;
    for (unsigned int i = 0; i < array.size(); ++i)
    {
        res += array[i]->totalArea();
    }
    printArea(res);
}
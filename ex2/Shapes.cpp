#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Triangle.h"
#include <string>
#include "SimpleTrapez.h"

#define TRISIDES 3
#define TRAPEZSIDES 4
#define FAIL -1
#define BUILDERROR "Non valid parameters for building this shape"

/* forward declarations */
Polygon * parseLine(std::string);
void buildTriangle(Polygon * &shape, std::vector<std::string> rawData);
void buildTrapez(Polygon * &shape, std::vector<std::string> rawData);


int main(int argc, char * argv[])
{
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


    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);

    //    TODO: remove tests inside the main
    std::cout << (array[1]->totalArea() + array[0]->totalArea());
    return 0;
}

void split(const std::string &source, char delim, std::vector<std::string> & elements);

Polygon * parseLine(std::string line)
{
    std::vector<std::string> rawData;
    split(line, '\t', rawData);
    Polygon * res;
    /* break into the shape various cases */
    if(rawData[0][0] == 'T')
    {
        buildTriangle(res, rawData);
    }
    else if(rawData[0][0] == 't')
    {
        buildTrapez(res, rawData);
    }
    return res;
}
using namespace std;

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


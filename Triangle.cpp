#include "Triangle.h"

Triangle::Triangle(Position *pPos, int numPositions, std::string type)     //Triangle constructor
{
    this->type = type;
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Triangle::~Triangle()           //Triangle destructor
{
    delete[] posPtr;
}
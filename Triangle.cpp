#include "Triangle.h"

Triangle::Triangle(Position *pPos, int numPositions)     //Triangle constructor
{
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Triangle::~Triangle()
{
    delete[] posPtr;
}
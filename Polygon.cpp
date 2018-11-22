#include "Polygon.h"

Polygon::Polygon(Position *pPos, int numPositions)      //Polygon constructor
{
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Polygon::~Polygon()             //Polygon destructor
{
    delete[] posPtr;
}
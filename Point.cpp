#include "Point.h"

Point::Point(Position *pPos, int numPositions)      //Point constructor
{
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Point::~Point()         //Point destructor
{
    delete[] posPtr;
}
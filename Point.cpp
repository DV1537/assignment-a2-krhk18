#include "Point.h"

Point::Point(Position *pPos, int numPositions, std::string type)
{
    this->type = type;
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Point::~Point()
{
    delete[] posPtr;
    posPtr = nullptr;
}
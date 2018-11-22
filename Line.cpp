#include "Line.h"

Line::Line(Position *pPos, int numPositions, std::string type)      //Line constructor
{
    this->type = type;
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Line::~Line()       //Line destructor
{
    delete[] posPtr;
    posPtr = nullptr;
}

double Line::circumreference()
{
    double circumference = 0.0;
    for(int i = 0; i < nrOfPositions - 1; i++)
    {
        circumference += sqrt(pow((posPtr[i].xCoord - posPtr[i + 1].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[i + 1].yCoord), 2));
    }
    return circumference;
}
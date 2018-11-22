#include "Polygon.h"

Polygon::Polygon(Position *pPos, int numPositions, std::string type)
{
    this->type = type;
    nrOfPositions = numPositions;
    posPtr = new Position[numPositions];
    for(int i = 0; i < numPositions; i++)
    {
        posPtr[i] = pPos[i];
    }
}

Polygon::~Polygon()
{
    delete[] posPtr;
}

double Polygon::area()
{
    double area = 0.0; 
    int j = nrOfPositions - 1; 
    for (int i = 0; i < nrOfPositions; i++)
    { 
        area += (posPtr[j].xCoord + posPtr[i].xCoord) * (posPtr[j].yCoord - posPtr[i].yCoord); 
        j = i;
    } 
    area = abs(area / 2.0);
    return area;
}

double Polygon::circumreference()
{
    double circumference = 0.0;
    int j = nrOfPositions - 1;
    for(int i = 0; i < nrOfPositions; i++)
    {
        circumference += sqrt(pow((posPtr[i].xCoord - posPtr[j].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[j].yCoord), 2));
        j = i;
    }
    return circumference;
}
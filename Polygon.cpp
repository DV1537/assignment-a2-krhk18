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
    posPtr = nullptr;
}

double Polygon::area()
{
    double area = 0.0;
    if(this->isConvex())    //-1 if the shape is concave
    {
        int j = nrOfPositions - 1; 
        for (int i = 0; i < nrOfPositions; i++)
        { 
            area += (posPtr[j].xCoord + posPtr[i].xCoord) * (posPtr[j].yCoord - posPtr[i].yCoord); 
            j = i;
        } 
        area = fabs(area / 2.0);
    }
    else
    {
        area = -1;
    }

    if(area == 0)   //-1 if doesn't have an area
    {
        area = -1;
    }
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
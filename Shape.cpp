#include "Shape.h"

Position Shape::position()
{
    Position midPosition;
    midPosition.xCoord = 0.0;
    midPosition.yCoord = 0.0;
    for(int i = 0; i < nrOfPositions ; i++)
    {
        midPosition.xCoord += posPtr[i].xCoord;
        midPosition.yCoord += posPtr[i].yCoord;
    }
    midPosition.xCoord /= nrOfPositions;
    midPosition.yCoord /= nrOfPositions;

    return midPosition;
}


bool Shape::isConvex()
{
    bool isConvex = true;
    bool sign = true;
    bool first = true;

    for(int i = 0; i < nrOfPositions; i++)
    {
        double v1x = posPtr[i].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
        double v1y = posPtr[i].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
        double v2x = posPtr[(i + 2) % nrOfPositions].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
        double v2y = posPtr[(i + 2) % nrOfPositions].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
        double dotProduct = ((v2x * v1y) - v2y * v1x);

        if(dotProduct != 0)
        {
            if(first)
            {
                if(dotProduct > 0)
                {
                    sign = false;
                    first = false;
                }
            }
            else
            {
                if(std::signbit(dotProduct) != sign)
                {
                    isConvex = false;
                }
            }
        }
    }
    return isConvex;
}

double Shape::distance(Shape *sPtr)
{
    double x1Mid = this->position().xCoord;
    double y1Mid = this->position().yCoord;
    double x2Mid = sPtr->position().xCoord;
    double y2Mid = sPtr->position().yCoord;

    double distance = sqrt(pow((x1Mid - x2Mid), 2) + pow((y1Mid - y2Mid), 2));

    return distance;
}
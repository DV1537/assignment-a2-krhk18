#ifndef POLYGON_H
#define POLYGON_H
#include <string>

class Polygon : public Shape
{
    private:
    public:
        Polygon(Position *pPos, int numPositions)
        {
            nrOfPositions = numPositions;
            pos = new Position[numPositions];
            for(int i = 0; i < numPositions; i++)
            {
                pos[i] = pPos[i];
            }
        }

        virtual std::string getType() const
        {
            return "Polygon";
        }
};

#endif
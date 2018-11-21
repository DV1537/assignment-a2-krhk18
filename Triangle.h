#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>

class Triangle : public Shape
{
    private:
    public:
        Triangle(Position *pPos, int numPositions)
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
            return "Triangle";
        }
};

#endif
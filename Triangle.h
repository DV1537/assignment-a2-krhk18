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
            posPtr = new Position[numPositions];
            for(int i = 0; i < numPositions; i++)
            {
                posPtr[i] = pPos[i];
            }
        }
        //~Triangle();
        std::string getType() const override
        {
            return "Triangle";
        }
};

#endif
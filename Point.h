#ifndef POINT_H
#define POINT_H
#include <string>

class Point : public Shape
{
    private:
    public:
        Point(Position *pPos, int numPositions)
        {
            nrOfPositions = numPositions;
            for(int i = 0; i < numPositions; i++)
            {
                pos[i] = pPos[i];
            }
        }
        
        virtual std::string getType() const
        {
            return "Point";
        }
/*         virtual double area()
        {
            return -1;
        } */
};

#endif
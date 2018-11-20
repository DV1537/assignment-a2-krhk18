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
        
        virtual double area()           
        {
            double area = -1;
            return area;
        }

        virtual double circumreference()       //returns circumreference of the object
        {
            double circumference = -1;
            return circumference;
        }
};

#endif
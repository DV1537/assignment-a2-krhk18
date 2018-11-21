#ifndef LINE_H
#define LINE_H
#include <string>

class Line : public Shape
{
    private:
        std::string type = "line";
    public:

        Line(Position *pPos, int numPositions)
        {
            nrOfPositions = numPositions;
            posPtr = new Position[numPositions];
            for(int i = 0; i < numPositions; i++)
            {
                posPtr[i] = pPos[i];
            }
        }

        virtual std::string getType() const
        {
            return type;
        }

        virtual double area()           
        {
            double area = -1;
            return area;
        }

        virtual double circumreference()       //returns circumreference of the object
        {
            double circumference = 0.0;
            for(int i = 0; i < nrOfPositions - 1; i++)
            {
                circumference += sqrt(pow((posPtr[i].xCoord - posPtr[i + 1].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[i + 1].yCoord), 2));
            }
            return circumference;
        }
};

#endif
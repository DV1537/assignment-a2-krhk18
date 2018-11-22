#ifndef LINE_H
#define LINE_H
#include <string>

class Line : public Shape
{
    private:
    public:
        Line(Position *pPos, int numPositions, std::string type);      //Line constructor

        ~Line();        //Line destructor

        double area()      //returns area of the object     
        {
            return -1;
        }

        double circumreference();       //returns circumreference of the object
/*         {
            double circumference = 0.0;
            for(int i = 0; i < nrOfPositions - 1; i++)
            {
                circumference += sqrt(pow((posPtr[i].xCoord - posPtr[i + 1].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[i + 1].yCoord), 2));
            }
            return circumference;
        } */
};

#endif
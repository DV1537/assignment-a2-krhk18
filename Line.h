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
};

#endif
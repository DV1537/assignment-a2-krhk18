#ifndef POINT_H
#define POINT_H
#include <string>

class Point : public Shape
{
    private:
    public:
        Point(Position *pPos, int numPositions, std::string type);     //Point constructor

        ~Point();                                  //Point destructor

        virtual double area()           
        {
            return -1;
        }

        virtual double circumreference()       //returns circumreference of the object
        {
            return -1;
        }
};

#endif
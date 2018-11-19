#ifndef POINT_H
#define POINT_H
#include <string>

class Point : public Shape
{
    private:
    public:
        virtual std::string getType() const
        {
            return "Point";
        }
        virtual double area(Coordinate *pCoord, int n)
        {
            return -1;
        }
};

#endif
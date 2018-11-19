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
        virtual double area()
        {
            return -1;
        }
};

#endif
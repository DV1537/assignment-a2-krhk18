#ifndef POLYGON_H
#define POLYGON_H
#include <string>

class Polygon : public Shape
{
    private:
    public:
        Polygon(Position *pPos, int numPositions, std::string type);      //Polygon constructor

        ~Polygon();     //Polygon destructor

        double area();

        double circumreference();
};

#endif
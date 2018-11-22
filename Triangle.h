#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>

class Triangle : public Shape
{
    private:
    public:
        Triangle(Position *pPos, int numPositions, std::string type);     //Triangle constructor
     
        ~Triangle();                                                      //Triangle destructor

        double area();

        double circumreference();
};

#endif
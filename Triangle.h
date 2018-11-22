#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>

class Triangle : public Shape
{
    private:
    public:
        Triangle(Position *pPos, int numPositions);     //Triangle constructor
     
        ~Triangle();                                    //Triangle destructor
       
        std::string getType() const override
        {
            return "Triangle";
        }
};

#endif
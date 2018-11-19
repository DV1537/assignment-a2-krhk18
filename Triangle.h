#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>

class Triangle : public Shape
{
    private:
    public:
        virtual std::string getType() const
        {
            return "Triangle";
        }
};

#endif
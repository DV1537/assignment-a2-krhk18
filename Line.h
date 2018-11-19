#ifndef LINE_H
#define LINE_H
#include <string>

class Line : public Shape
{
    private:
        std::string type = "line";
    public:
        virtual std::string getType() const
        {
            return type;
        }
        virtual double area(Coordinate *pCoord, int n)
        {
            return 2;
        }
};

#endif
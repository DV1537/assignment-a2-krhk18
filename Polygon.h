#ifndef POLYGON_H
#define POLYGON_H
#include <string>

class Polygon : public Shape
{
    private:
    public:
        virtual std::string getType() const
        {
            return "Triangle";
        }
};

#endif
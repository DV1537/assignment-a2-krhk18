#ifndef POLYGON_H
#define POLYGON_H
#include <string>

class Polygon : public Shape
{
    private:
    public:
        Polygon(Position *pPos, int numPositions);      //Polygon constructor

        ~Polygon();
  

        virtual std::string getType() const
        {
            return "Polygon";
        }
};

#endif
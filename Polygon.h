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

        virtual double area()
        {
            double area = 0.0; 
            int j = 3 - 1; 
            for (int i = 0; i < 3; i++) 
            { 
                area += (pos[j].xCoord + pos[i].xCoord) * (pos[j].yCoord - pos[i].yCoord); 
                j = i;
            } 
            area = abs(area / 2.0);
            return area;
        }
};

#endif
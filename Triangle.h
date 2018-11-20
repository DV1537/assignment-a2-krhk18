#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>

class Triangle : public Shape
{
    private:
    public:
 
        Triangle(Position *pPos)
        {
            for(int i = 0; i < 3; i++)
            {
                pos[i] = pPos[i];
            }
        }
 
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
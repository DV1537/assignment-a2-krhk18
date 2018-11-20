#ifndef LINE_H
#define LINE_H
#include <string>

class Line : public Shape
{
    private:
        std::string type = "line";
    public:

        Line(Position *pPos, int numPositions)
        {
            nrOfPositions = numPositions;
            for(int i = 0; i < numPositions; i++)
            {
                pos[i] = pPos[i];
            }
        }

        virtual std::string getType() const
        {
            return type;
        }
/*         virtual double area()
        {
            return 2;
        } */
};

#endif
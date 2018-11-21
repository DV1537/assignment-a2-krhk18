#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <cmath>

/* Instructions:
- Implement an abstract class Shape with methods:
	- getType() returns a string denoting type of a shape (point, line, polygon ..)
	- area() returns area of the object, or -1 if the shape is concave, intersecting, or does not have an area
	- circumreference() returns circumreference of the object
	- position() returns center coordinates of the object
	- isConvex() returns true if shape is convex
	- distance(Shape s) returns distance to the center of another shape
- Extend the Object classe into Point, Line, Triangle, and Polygon. Overload the inherited methods. Constructors of these classes take vertices coordinates as an input.

- The program should load a shape from a file and output its surface area. The input file contains a series of real numbers indicating coordinates of vertices. Example:
```
1 2 3 4 5 6.43  // Denotes a triange with vsertices at (1, 2) (3, 4) (5, 6.43) 
```
There should not be a limitation of how many points the program can load. */

class Shape
{
    protected:
        int nrOfPositions;
        Position *posPtr;
        //std::string type;
    public:
        //Shape();
        //virtual ~Shape();
        virtual std::string getType() const = 0;     //returns a string denoting type of a shape (point, line, polygon ..)

        virtual double area()                       //returns area of the object, or -1 if the shape is concave, intersecting, or does not have an area
        {
            double area = 0.0; 
            int j = nrOfPositions - 1; 
            for (int i = 0; i < nrOfPositions; i++)
            { 
                area += (posPtr[j].xCoord + posPtr[i].xCoord) * (posPtr[j].yCoord - posPtr[i].yCoord); 
                j = i;
            } 
            area = abs(area / 2.0);
            return area;
        }

        virtual double circumreference()       //returns circumreference of the object
        {
            double circumference = 0.0;
            int j = nrOfPositions - 1;
            for(int i = 0; i < nrOfPositions; i++)
            {
                circumference += sqrt(pow((posPtr[i].xCoord - posPtr[j].xCoord), 2) + pow((posPtr[i].yCoord - posPtr[j].yCoord), 2));
                j = i;
            }
            return circumference;
        }

        Position position()                   //returns center coordinates of the object
        {
            Position midPosition;
            midPosition.xCoord = 0.0;
            midPosition.yCoord = 0.0;
            for(int i = 0; i < nrOfPositions ; i++)
            {
                midPosition.xCoord += posPtr[i].xCoord;
                midPosition.yCoord += posPtr[i].yCoord;
            }
            midPosition.xCoord /= nrOfPositions;
            midPosition.yCoord /= nrOfPositions;

            return midPosition;
        }

        bool isConvex()                //returns true if shape is convex
        {
            bool isConvex = true;
            bool sign = false;

            for(int i = 0; i < nrOfPositions; i++)
            {
                double v1x = posPtr[i].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
                double v1y = posPtr[i].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
                double v2x = posPtr[(i + 2) % nrOfPositions].xCoord - posPtr[(i + 1) % nrOfPositions].xCoord;
                double v2y = posPtr[(i + 2) % nrOfPositions].yCoord - posPtr[(i + 1) % nrOfPositions].yCoord;
                double dotProduct = ((v1x * v2x) + v1y * v2y);

                if(i == 0)
                {
                    if(dotProduct > 0)
                    {
                        sign = true;
                    }
                }
                else
                {
                    if((dotProduct > 0) != sign)
                    {
                        isConvex = false;
                    }
                }
            }
            return isConvex;
        }

/*         double distance(Shape s);       //returns distance to the center of another shape
        {
            
        } */
        
};

#endif
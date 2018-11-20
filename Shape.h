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
        Position pos[10];
    public:
        virtual std::string getType() const = 0;     //returns a string denoting type of a shape (point, line, polygon ..)

        virtual double area()           //returns area of the object, or -1 if the shape is concave, intersecting, or does not have an area
        {
            double area = -1;
            return area;
        }

        double circumreference()       //returns circumreference of the object
        {
            double circumference = 0.0;
            int j = nrOfPositions - 1;
            for(int i = 0; i < nrOfPositions; i++)
            {
                circumference += sqrt(pos[i].xCoord * pos[i].xCoord + pos[j].yCoord * pos[j].yCoord);
                j = i;
            }
            return circumference;
        }

        Position position()                   //returns center coordinates of the object
        {
            Position midPosition;
            for(int i = 0; i < nrOfPositions ; i++)
            {
                midPosition.xCoord += pos[i].xCoord;
                midPosition.yCoord += pos[i].yCoord;
            }
            midPosition.xCoord /= nrOfPositions;
            midPosition.yCoord /= nrOfPositions;

            return midPosition;
        }

        bool isConvex();                //returns true if shape is convex

        //double distance(Shape s);       //returns distance to the center of another shape
        
};

#endif
#include <iostream>
#include <fstream>
#include "Coordinate.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

int main(int argc, const char * argv[])
{
    int size = 1;
    Coordinate *coordinatePtr = new Coordinate[size];
    Shape *shapePtr = nullptr;
    int count = 0;
    std::ifstream inputFile;
    inputFile.open("input.in");

    if(!inputFile)      //Checks if read in successfully
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        do
        {
            inputFile >> coordinatePtr[count].xCoord;
            inputFile >> coordinatePtr[count].yCoord;
            count++;

            if(count >= size)                       //If full: expand
            {
                size += 1;                          //increase size
                Coordinate *tempPtr = new Coordinate[size];      //Create new (bigger)
                                
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = coordinatePtr[i];
                }

                delete []coordinatePtr;                //delete old content
                coordinatePtr = tempPtr;               //make pointer point to new array
                tempPtr = nullptr;                  //make xTempPtr point to null
            }
            
        }while(!inputFile.eof());
/* 
        if(count < 2)
        {
            std::cout << "There has to be AT LEAST TWO values in the file\n";
        }
        else if(count % 2 == 1)
        {
            std::cout << "There has to be an EVEN amount of values in the file\n";
        } */
        if(count == 1)
        {
            shapePtr = new Point;    //Create point object
        }
        else if(count == 2)
        {
            shapePtr = new Line;       //Create line object
        }
        else if(count == 3)
        {
            shapePtr = new Triangle;   //Create triangle object   //???Om punkter på rad??
        }
        else if(count >= 4)
        {
            shapePtr = new Polygon;    //Create polygon object
        }

        std::cout << shapePtr->getType() << std::endl;
        {
            std::cout << "The area is: " << shapePtr->area(coordinatePtr, count) << std::endl;
        }
    }
    
    for(int i = 0; i < count; i++)
            std::cout << "X: " << coordinatePtr[i].xCoord << ", Y: " << coordinatePtr[i].yCoord << std::endl;
}
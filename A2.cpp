#include <iostream>
#include <fstream>
#include "Position.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

int main(int argc, const char * argv[])
{
    int size = 1;
    Position *PositionPtr = new Position[size];
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
            inputFile >> PositionPtr[count].xCoord;
            inputFile >> PositionPtr[count].yCoord;
            count++;

            if(count >= size)                       //If full: expand
            {
                size += 1;                          //increase size
                Position *tempPtr = new Position[size];      //Create new (bigger)
                                
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = PositionPtr[i];
                }

                delete []PositionPtr;                //delete old content
                PositionPtr = tempPtr;               //make pointer point to new array
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
            shapePtr = new Point(PositionPtr, count);    //Create point object
        }
        else if(count == 2)
        {
            shapePtr = new Line(PositionPtr, count);       //Create line object
        }
        else if(count == 3)
        {
            shapePtr = new Triangle(PositionPtr, count);   //Create triangle object   //???Om punkter på rad??
        }
        else if(count >= 4)
        {
            shapePtr = new Polygon(PositionPtr, count);    //Create polygon object
        }

        std::cout << "Shape: " << shapePtr->getType() << std::endl;
        std::cout << "Area: " << shapePtr->area() << std::endl;
        std::cout << "Midposition, x: " << shapePtr->position().xCoord << " , y: " << shapePtr->position().yCoord << std::endl;
    }
    
    for(int i = 0; i < count; i++)
            std::cout << "X: " << PositionPtr[i].xCoord << ", Y: " << PositionPtr[i].yCoord << std::endl;
}
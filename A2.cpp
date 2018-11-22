#include <iostream>
#include <fstream>
#include "Position.h"
#include "Position.cpp"
#include "Shape.h"
#include "Shape.cpp"
#include "Point.h"
#include "Point.cpp"
#include "Line.h"
#include "Line.cpp"
#include "Triangle.h"
#include "Triangle.cpp"
#include "Polygon.h"
#include "Polygon.cpp"

int main(int argc, const char * argv[])
{
    int size = 1;
    double *numbersPtr = new double[size];
    Position *positionPtr = nullptr;
    Shape *shapePtr = nullptr;
    int numbers = 0;
    int count = 0;
    std::string type = "";
    std::ifstream inputFile;
    inputFile.open("input.in");

    if(!inputFile)      //Checks if read in successfully
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        while(inputFile >> numbersPtr[numbers])           //Read in and store
        {           

            numbers++;
            if(numbers >= size)       //If full: expand
            {
                size += 1;
                double *tempPtr = new double[size];  //Create new, bigger
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = numbersPtr[i];
                }
                delete []numbersPtr;                //delete old content
                numbersPtr = tempPtr;               //make pointer point to new array
                tempPtr = nullptr;
            }
        }
        if(numbers == 0 || !inputFile.eof())
        {
            std::cout << "File is empty or contains non-numerical values\n";
        }
        else if(numbers % 2 == 1)
        {
            std::cout << "File contains an odd number of values\n";
        }
        else
        {
            count = numbers / 2;
            positionPtr = new Position[count];
            for(int i = 0; i < count; i++)
            {
                positionPtr[i].xCoord = numbersPtr[2 * i];
                positionPtr[i].yCoord = numbersPtr[2 * i + 1];
            }

        if(numbers % 2 == 0 && numbers != 0)
        {
            if(count == 1)
            {
                type = "Point";
                shapePtr = new Point(positionPtr, count, type);    //Create point object
            }
            else if(count == 2)
            {
                type = "Line";
                shapePtr = new Line(positionPtr, count, type);       //Create line object
            }
            else if(count == 3)
            {
                type = "Triangle";
                shapePtr = new Triangle(positionPtr, count, type);   //Create triangle object   //???Om punkter på rad??
            }
            else if(count >= 4)
            {
                type = "Polygon";
                shapePtr = new Polygon(positionPtr, count, type);    //Create polygon object
            }

            std::cout << "Shape: " << shapePtr->getType() << std::endl;
            std::cout << "Area: " << shapePtr->area() << std::endl;
            std::cout << "Midposition, x: " << shapePtr->position().xCoord << " , y: " << shapePtr->position().yCoord << std::endl;
            std::cout << "Circumference: " << shapePtr->circumreference() << std::endl;
            std::string convex = "";
            if(shapePtr->isConvex())
            {
                convex = "Yes";
            }
            else
            {
                convex = "No";
            }
            std::cout << "Is convex: " << convex << std::endl;

            Shape *anotherShapePtr = nullptr;
            Position posOne;
            posOne.xCoord = 5;
            posOne.yCoord = 5;
            Position posTwo;
            posTwo.xCoord = 7;
            posTwo.yCoord = 5;
            Position posThree;
            posThree.xCoord = 7;
            posThree.yCoord = 9;
            Position posFour;
            posFour.xCoord = 5;
            posFour.yCoord = 9;
            Position *anotherPositionPointer = new Position[4];
            anotherPositionPointer[0] = posOne;
            anotherPositionPointer[1] = posTwo;
            anotherPositionPointer[2] = posThree;
            anotherPositionPointer[3] = posFour;
            anotherShapePtr = new Polygon(anotherPositionPointer, 4, "Polygon");
            shapePtr = new Polygon(positionPtr, 4, "Polygon");
            std::cout << "Distance: " << shapePtr->distance(anotherShapePtr) << std::endl;

            for(int i = 0; i < count; i++)
            {
                std::cout << "X: " << positionPtr[i].xCoord << ", Y: " << positionPtr[i].yCoord << std::endl;
            }
        }        
    }

    delete []positionPtr;
    positionPtr = nullptr;
    }
}
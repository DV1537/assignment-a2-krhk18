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
    inputFile.open(argv[1]);

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

            delete []numbersPtr;
            numbersPtr = nullptr;

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
                shapePtr = new Triangle(positionPtr, count, type);   //Create triangle object
            }
            else if(count >= 4)
            {
                type = "Polygon";
                shapePtr = new Polygon(positionPtr, count, type);    //Create polygon object
            }

            double area = shapePtr->area();         //Print area with 3 decimal digits
            area = round(area * 1000) / 1000;
            std::cout << area << std::endl;        
        }
    }
    delete []positionPtr;
    positionPtr = nullptr;

    delete shapePtr;
    shapePtr = nullptr;

    std::getchar();
}
#include <iostream>
#include <fstream>
#include "Position.cpp"
#include "Shape.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Triangle.cpp"
#include "Polygon.cpp"

int main(int argc, const char * argv[])
{
    int size = 1;
    Position *positionPtr = new Position[size];
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
            inputFile >> positionPtr[count].xCoord;
            inputFile >> positionPtr[count].yCoord;
            count++;

            if(count >= size)                       //If full: expand
            {
                size += 1;                          //increase size
                Position *tempPtr = new Position[size];      //Create new (bigger)
                                
                for(int i = 0; i < size - 1; i++)      //move
                {
                    tempPtr[i] = positionPtr[i];
                }

                delete []positionPtr;                //delete old content
                positionPtr = tempPtr;               //make pointer point to new array
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
            shapePtr = new Point(positionPtr, count);    //Create point object
        }
        else if(count == 2)
        {
            shapePtr = new Line(positionPtr, count);       //Create line object
        }
        else if(count == 3)
        {
            shapePtr = new Triangle(positionPtr, count);   //Create triangle object   //???Om punkter på rad??
        }
        else if(count >= 4)
        {
            shapePtr = new Polygon(positionPtr, count);    //Create polygon object
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
    }
    
    for(int i = 0; i < count; i++)
    {
            std::cout << "X: " << positionPtr[i].xCoord << ", Y: " << positionPtr[i].yCoord << std::endl;
    }
    

    //Test how signbit works - remove when done
    bool isNegative = std::signbit(-1);
    if(isNegative)
    {
        std::cout << "Negative" << std::endl;
    }
    else
        std::cout << "Positive" << std::endl;
}

//Remember delete positionPtr!!!
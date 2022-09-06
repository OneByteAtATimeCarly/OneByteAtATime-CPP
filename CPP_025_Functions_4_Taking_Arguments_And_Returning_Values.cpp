//Functions 4 - Taking Arguments and Returning Values - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
int ComputeArea(int length, int width = 25, int height = 1);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int length = 100;
    int width = 50;
    int height = 2;
    int area;

    area = ComputeArea(length, width, height);

    cout << "First area equals: " << area << "\n";
    area = ComputeArea(length, width);
    cout << "Second time area equals: " << area << "\n";
    area = ComputeArea(length);
    cout << "Third time area equals: " << area << "\n";

    return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
ComputeArea(int length, int width, int height)
{
         return (length * width * height);
}

//---------------------------------------------------------------------------------------------------------------------------



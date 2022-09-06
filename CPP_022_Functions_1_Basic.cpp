//Functions 1 - Basic - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
int ComputeArea(int length, int width); //1. function prototype

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
  int GardenLength;
  int GardenWidth;
  int GardenArea;
  cout << "\nHow wide is your garden? ";
  cin >> GardenWidth;
  cout << "\nHow long is your garden? ";
  cin >> GardenLength;

  GardenArea = ComputeArea(GardenLength,GardenWidth); //2. calling function

  cout << "\nYour garden is ";
  cout << GardenArea;
  cout << " square feet.\n\n";

  return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
int ComputeArea(int l, int w) //3. DEFINITION of function
{
    return l * w;
}

//---------------------------------------------------------------------------------------------------------------------------


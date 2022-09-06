//Functions 2 - Passing Parameters and Arguments - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
void SwapIntegers(int x, int y);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 5, y = 10;
    cout << "Main. Before SwapIntegers, x: " << x << " y: " << y << "\n";
 
    //2. Function call
    SwapIntegers(x,y);

    cout << "Main. After SwapIntegers, x: " << x << " y: " << y << "\n";

    return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
void SwapIntegers(int x, int y)
{
     int temp;

     cout << "SwapIntegers. Before SwapIntegers, x: " << x << " y: " << y << "\n";

     temp = x;
     x = y;
     y = temp;

     cout << "SwapIntegers. After SwapIntegers, x: " << x << " y: " << y << "\n";
}

//---------------------------------------------------------------------------------------------------------------------------


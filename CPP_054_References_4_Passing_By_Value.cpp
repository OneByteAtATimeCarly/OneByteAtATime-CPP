//References - 4 - Passing Functions arguments By Reference - 2004 C. S. Germany

//References can not be reassigned and are always aliases for their target.  References have entirely different behavior patterns than pointers.
//What may appear to be a reassignment will turn out to be the assignment of a new value to the target.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
void swap(int x, int y);

//---------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 5, y = 10;

    cout << "Main. Before swap, x: " << x << " y: " << y << "\n";
   
    swap(x,y);
   
    cout << "Main. After swap, x: " << x << " y: " << y << "\n";
  
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------

//Function definition
void swap (int x, int y)
{
     int temp;

     cout << "Swap. Before swap, x: " << x << " y: " << y << "\n";

     temp = x;
     x = y;
     y = temp;

     cout << "Swap. After swap, x: " << x << " y: " << y << "\n";

}
//---------------------------------------------------------------------------------------------------------------------------



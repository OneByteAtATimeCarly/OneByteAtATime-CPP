//References - 5 - Passing Function Arguments By Reference Using References - 2004 C. S. Germany

//There are 2 problems with passing by reference using pointers:
//1) The repeated need to dereference the pointers within the swap() function makes it error-prone and hard to read.
//2) The need to pass the address of the variables in the calling function makes the inner workings of swap() overly apparent to its users.
//Passing by reference using references is more "transparent" than passing pointers.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
void swap(int &x, int &y);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 5, y = 10;
    cout << "Main. Before swap, x: " << x << " y: " << y << "\n";

    swap(x,y);
 
    cout << "Main. After swap, x: " << x << " y: " << y << "\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
void swap (int &rx, int &ry)
{
     int temp;
     cout << "Swap. Before swap, rx: ";
     cout << rx << " ry: " << ry << "\n";

     temp = rx;
     rx = ry;
     ry = temp;

     cout << "Swap. After swap, rx: ";
     cout << rx << " ry: " << ry << "\n";
}

//---------------------------------------------------------------------------------------------------------------------------





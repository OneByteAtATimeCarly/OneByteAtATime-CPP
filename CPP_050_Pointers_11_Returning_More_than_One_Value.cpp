//Pointers - 11 - Returnign More than One Value by reference Using Pointers - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned long ULONG;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
long Factor(ULONG, ULONG*, ULONG*);  //notice that no variable names are in the prototype!

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ULONG number, squared, cubed;
    bool error;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    error = Factor(number, &squared, &cubed);    //address passed in

    if(!error)
    {
       cout << "number: " << number << "\n";
       cout << "square: " << squared << "\n";
       cout << "cubed: " << cubed << "\n";
    }
   
    else
       cout << "Error encountered!!\n";

       return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
long Factor(ULONG n, ULONG *pSquared, ULONG *pCubed)
{
     bool error = false;

     if(n > 20) {
        error = true; }

     else {
           *pSquared = n*n;
           *pCubed = n*n*n;
           error = false;
     }

     return error;
}

//---------------------------------------------------------------------------------------------------------------------------







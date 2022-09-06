//Pointers - 1 - The Address Of Operator - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

// The address of operator and addresses of local variables
#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    unsigned short ShortVariable=5;
    unsigned long LongVariable=65535;
    long SignedVariable = -65535;

    cout << "ShortVariable:\t" << ShortVariable;
    cout << "Address of ShortVariable:\t" << &ShortVariable << "\n";
 
    cout << "LongVariable:\t" << LongVariable;
    cout << " Address of LongVariable:\t" << &LongVariable << "\n";
 
    cout << "SignedVariable:\t" << SignedVariable
         << " Address of SignedVariable:\t"
         << &SignedVariable << "\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
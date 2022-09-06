//References - 2 - Using with AddressOf Operator - 2004 C. S. Germany

//Unlike a pointer, using the address of operator "&" on references returns the address of its target.  References are aliases for their target.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int intOne;
    int &AReference = intOne;

    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "AReference: " << AReference << endl;

    cout << "&intOne: " << &intOne << endl;
    cout << "&AReference: " << &AReference << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


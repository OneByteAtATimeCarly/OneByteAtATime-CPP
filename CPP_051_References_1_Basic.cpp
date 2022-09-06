//References - 1 - 2004 C. S. Germany

//A reference is an alias.  It operates and manipulates memory much the same as a pointer, yet its behavior differs. 
//When you create a reference you initialize it with the name of another object, the "target". The reference acts as an
//alternative name for the target.  Anything you do to the reference is really done to the target.  Basically, much of what
//you do with a pointer can be done with a reference, only without the need of the address of operator and dereferencing.

//To create a reference: Write the type of the target object followed by the reference operator "&" followed by the name of the reference.
//If you have an int variable named AnInteger, you can make a reference to it by writing:  int &AReference = AnInteger;

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

    AReference = 7;
    cout << "intOne: " << intOne << endl;
    cout << "AReference: " << AReference << endl;
 
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


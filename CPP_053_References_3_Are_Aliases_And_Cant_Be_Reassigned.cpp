//References - 3 - references are ALIASES and Can't be Reassigned - 2004 C. S. Germany

//References can not be reassigned and are always aliases for their target.  References have entirely different behavior patterns than pointers.
//What may appear to be a reassignment will turn out to be the assignment of a new value to the target.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int intOne;
    int &AReference = intOne;

    intOne = 5;
    cout << "intOne:\t" << intOne << endl;
    cout << "AReference:\t" << AReference << endl;
    cout << "&intOne:\t" << &intOne << endl;
    cout << "&AReference:\t" << &AReference << endl;

    int intTwo = 8;

    AReference = intTwo;          //not what you think!

    cout << "\nintOne:\t" << intOne << endl;
    cout << "intTwo:\t" << intTwo << endl;
    cout << "AReference:\t" << AReference << endl;
    cout << "&intOne:\t" << &intOne << endl;
    cout << "&intTwo:\t" << &intTwo << endl;
    cout << "&AReference:\t" << &AReference << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



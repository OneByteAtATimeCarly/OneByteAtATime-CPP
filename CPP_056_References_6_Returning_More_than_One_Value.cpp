//References - 6 - Using References to Return More than One Value by Reference - 2004 C. S. Germany

//By default functions only return 1 value.  You can return multiple values by passing 2 objects into a function by reference.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned long ULONG;
enum ERR_CODE { SUCCESS, ERROR };  //acts like a user-defined boolean

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
ERR_CODE Factor(ULONG, ULONG&, ULONG&);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ULONG number, squared, cubed;
    ERR_CODE result;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    result = Factor(number, squared, cubed);  //when calling the function, no &

    if(result == SUCCESS)
    {
        cout << "number: " << number << "\n";
        cout << "square: " << squared << "\n";
        cout << "cubed: " << cubed << "\n";
    }
    else {
        cout << "Error encountered!!\n";  }

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
ERR_CODE Factor(ULONG n, ULONG &rSquared, ULONG &rCubed)
{
    if(n > 20) {
        return ERROR;  }   // simple error code

    else
    {
        rSquared = n*n;
        rCubed = n*n*n;
        return SUCCESS;
    }
}

//---------------------------------------------------------------------------------------------------------------------------







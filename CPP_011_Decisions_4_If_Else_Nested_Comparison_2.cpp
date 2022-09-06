//Decisions - 4 - If and Else - Nested - Comparison - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x;
    cout << "Enter a number less than 10 or greater than 100: ";
    cin >> x;
    cout << "\n";
   
    if(x > 10)
    {
       if(x > 100)
           { cout << "More than 100, Thanks!\n"; }
       else
           { cout << "Less than 100 but more than 10."; }
    }
    else                            //now in braces - it's fixed!
       { cout << "Less than 10, Thanks!\n"; }

    return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------


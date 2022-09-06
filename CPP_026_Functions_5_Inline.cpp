//Functions 5 - Inline Functions - 2004 C. S. Germany

//Inline functions are not real functions, the compiler reads the code of inline function each time into the program. 
//This can slightly increase a program's speed by not causing the program to stop executing, find the function and then resume. 
//However, the tradeoff is that it will greatly increase the executable's size.
//Small function's are candidates for inline functions, but WHEN IN DOUBT LEAVE IT OUT.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
inline int Quadrupler(int);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int target;
    cout << "Enter a number to work with:";
    cin >> target;
    cout << "\n";

    target = Quadrupler(target);

    cout << "Target: " << target << endl;

    target = Quadrupler(target);

    cout << "Target: " << target << endl; 
    target = Quadrupler(target);
    cout << "Target: " << target << endl; 
 
    return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
int Quadrupler (int target)
{
    return 4 * target;
}

//---------------------------------------------------------------------------------------------------------------------------




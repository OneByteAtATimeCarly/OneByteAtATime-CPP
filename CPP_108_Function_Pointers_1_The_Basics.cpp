//Function Pointers 1 - 2004 C. S. Germany

//Pointers may also be declared to point to functions.  It is interesting to note that function names are constant pointers
//to the function itself.  You can declare a pointer variable that points to a function.  The function can then be invoked
//by using that pointer.  This allows programs to dynamically decide which functions to invoke based upon user input. 
//When using function pointers, you must be clear about the type of object pointed to - so watch your data types and
//return types!.  A pointer to a function must point to a function of the appropriate return type and signature.  
//Example: long (* funcPtr) (int);

//In the example above, "funcPtr" is declared to be a pointer that points to a function that takes an int parameter and returns a long.
//Parentheses are necessary around "*funcPtr" because the parentheses around "int" bind tighter and have a higher precedence than the
//indirection operator "*".  Without the first set of parenthesis, the previous statement would declare a function, rather than a pointer
//to a function, that takes and integer and returns a pointer to a long.  Declaration of a function pointer always includes the return
//type and parentheses, indicating the type of parameters.

//Below, 4 functions are declared in this example with same return type and signature, returning void and taking 2 references to integers.
//Next, "AFunctionPointer" is declared to be pointer to a function that returns void and takes 2 integer reference parameters.  Any of the
//previous functions can be pointed to by AFunctionPointer, since they all take two int references and return void.  Remember that they must
//agree in both their argument types and return type in order for the function pointer to work properly. 

//The user is offered the choice about which functions to invoke, and "AFunctionPointer" is assigned accordingly to a function.  This has the effect
//of invoking the function that AFunctionPointer points to the next time we use this pointer as a function call.  In the PrintVal function, the current
//value of two int's is printed, the currently assigned function is invoked, and then the values are printed again.  In this case, we are dealing with
//memory addresses rather than values, so pointers to functions do not need to be dereferenced.  If "AFunctionPointer" is a pointer to a function,
//taking an integer and returning a variable of type long, and you then assign AFunctionPointer to a matching function, you can invoke it 2 ways:

//   AFunctionPointer(x); -          shorthand version, not dereferenced
//   (*AFunctionPointer)(x); -   long version, dereferenced.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL { FALSE, TRUE };

//---------------------------------------------------------------------------------------------------------------------------

//Function prototypes
void Square (int&,int&);
void Cube (int&, int&);
void Swap (int&, int &);
void GetVals(int&, int&);
void PrintVals(int, int);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    void (* AFunctionPointer) (int &, int &);

    BOOL fQuit = FALSE;

    int valOne=1, valTwo=2;
    int choice;

    while(fQuit == FALSE)
    {
       cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4)Swap: ";
       cin >> choice;
           switch(choice)
           {
             case 1: AFunctionPointer = GetVals; break;
             case 2: AFunctionPointer = Square;  break;
             case 3: AFunctionPointer = Cube;    break;
             case 4: AFunctionPointer = Swap;    break;
             default : fQuit = TRUE;  break;
           }

       if(fQuit)
          break;

       PrintVals(valOne, valTwo);

       AFunctionPointer(valOne, valTwo);

       PrintVals(valOne, valTwo);
    }  //close while true loop

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

void PrintVals(int x, int y)
{ cout << "x: " << x << " y: " << y << endl; }

void Square(int & rX, int & rY)
{
     rX *= rX;
     rY *= rY;
}

//---------------------------------------------------------------------------------------------------------------------------

void Cube(int & rX, int & rY)
{
     //Could replace with rx = rx * rx * rx.
     int tmp;
     tmp = rX;
     rX *= rX;
     rX = rX * tmp;

     tmp = rY;
     rY *= rY;
     rY = rY * tmp;
}

//---------------------------------------------------------------------------------------------------------------------------

void Swap(int & rX, int & rY)
{
     int temp;
     temp = rX;
     rX = rY;
     rY = temp;
}

//---------------------------------------------------------------------------------------------------------------------------

void GetVals(int & rValOne, int & rValTwo)
{
     cout << "New value for ValOne: ";
     cin >> rValOne;
     cout << "New value for ValTwo: ";
     cin >> rValTwo;
}

//---------------------------------------------------------------------------------------------------------------------------





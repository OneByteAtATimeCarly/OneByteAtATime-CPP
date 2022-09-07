//Function Pointers 4 - Function Pointers With typedef - 2004 C. S. Germany

//The expression " void (*)(int&, int&) " is cumbersome. We can use typedef to simplify things.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL { FALSE, TRUE };

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void Square (int&,int&);
void Cube (int&, int&);
void Swap (int&, int &);
void GetVals(int&, int&);

//Set up FUNC as a pointer to a function that takes two references as arguments.
typedef void (*FUNC) (int &, int&);

void PrintVals(FUNC, int&, int&);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int valOne=1, valTwo=2;
    int choice;
    BOOL fQuit = FALSE;

    FUNC FunctionPointer;

    while(fQuit == FALSE)
    {
        cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4)Swap: ";
        cin >> choice;

           switch(choice)
           {
             case 1: FunctionPointer = GetVals; break;
             case 2: FunctionPointer = Square;  break;
             case 3: FunctionPointer = Cube;    break;
             case 4: FunctionPointer = Swap;    break;
             default: fQuit = TRUE;   break;
           }

        if(fQuit == TRUE)
           break;

        PrintVals(FunctionPointer, valOne, valTwo);
    } //close while true

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

void PrintVals(FUNC FunctionPointer, int & x, int & y)
{
     cout << "x: " << x << " y: " << y << endl;
     FunctionPointer(x,y);
     cout << "x: " << x << " y: " << y << endl;
}

//---------------------------------------------------------------------------------------------------------------------------

void Square(int & rX, int & rY)
{
     rX *= rX;
     rY *= rY;
}

//---------------------------------------------------------------------------------------------------------------------------

void Cube(int & rX, int & rY)
{
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

void GetVals (int & rValOne, int & rValTwo)
{
     cout << "New value for ValOne: ";
     cin >> rValOne;
     cout << "New value for ValTwo: ";
     cin >> rValTwo;
}

//---------------------------------------------------------------------------------------------------------------------------






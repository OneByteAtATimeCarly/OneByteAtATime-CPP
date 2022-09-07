//Function Pointers 2 - Arrays of pointers to functions - 2004 C. S. Germany

//You can declare arrays of pointers to functions for returning specific value types and signatures.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL { FALSE, TRUE };

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void Square (int&,int&);
void Cube (int&, int&);
void Swap (int&, int &);
void GetVals(int&, int&);
void PrintVals(int, int);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int valOne=1, valTwo=2;
    int choice, i;
    const MaxArray = 5;

    void (*FunctionPointerArray[MaxArray])(int &, int &);

    for(i=0;i<MaxArray;i++)
    {
       cout << "(1)Change Values (2)Square (3)Cube (4)Swap: ";
       cin >> choice;
 
           switch(choice)
           {
             case 1: FunctionPointerArray[i] = GetVals; break;
             case 2: FunctionPointerArray[i] = Square;  break;
             case 3: FunctionPointerArray[i] = Cube;    break;
             case 4: FunctionPointerArray[i] = Swap;    break;
             default: FunctionPointerArray[i] = 0;
           }
    } //close for loop

    for(i=0;i<MaxArray; i++)
    {
        FunctionPointerArray[i](valOne,valTwo);
        PrintVals(valOne,valTwo);
    }

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





//Overloading 2 - Overloading a Function Using Default Values - 2004 C. S. Germany

//Member functions of a class can be defined with default values that when used, achieve function overloading as well
//Using a default value replaces the overloaded DrawAShape() function in the previous example with a single function with default parameters. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short int USHORT;
enum BOOL { FALSE, TRUE};

//---------------------------------------------------------------------------------------------------------------------------

class Rectangle
{
      public:
      Rectangle(USHORT width, USHORT height);
      ~Rectangle(){}

      void DrawAShape(USHORT aWidth, USHORT aHeight, BOOL UseCurrentVals = FALSE) const;

      private:
      USHORT itsWidth;
      USHORT itsHeight;
};

//---------------------------------------------------------------------------------------------------------------------------

//Constructor implementation outside class, values assigned shorthand
Rectangle::Rectangle(USHORT width, USHORT height):
itsWidth(width), itsHeight(height) {}

//---------------------------------------------------------------------------------------------------------------------------

//Default values used for third parameter
void Rectangle::DrawAShape(USHORT width, USHORT height, BOOL UseCurrentValue) const
{
     int printWidth;
     int printHeight;

     if(UseCurrentValue == TRUE)
     {
         printWidth = itsWidth;      //use current class values assigned when object instantiated
         printHeight = itsHeight;
     }
     else
     {
         printWidth = width;       //use parameter values passed in as arguments
         printHeight = height;
     }


     for(int i = 0; i<printHeight; i++)
     {
          for(int j = 0; j< printWidth; j++)
          {
              cout << "*";
          }
       cout << "\n";
     }
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
     //Initialize a rectangle to 10,20, call the constructor
   Rectangle ARectangle(30,5);

   cout << "DrawAShape(0,0,TRUE)...\n";

   ARectangle.DrawAShape(0,0,TRUE);    //call function passing in all 3 parameters

   cout <<"DrawAShape(40,2)...\n";

   ARectangle.DrawAShape(40,2);       //call function passing in 2 parameters, use default parameter for 3rd

   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




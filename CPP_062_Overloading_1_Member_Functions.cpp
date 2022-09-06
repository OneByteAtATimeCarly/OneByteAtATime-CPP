//Overloading 1 - Member Functions - 2004 C. S. Germany

//Overloaded member functions are part of function polymorphism, writing two or more functions with the same NAME, but different parameters, arguments and return types.

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

      //overloaded class function DrawAShape
      void DrawAShape() const;
      void DrawAShape(USHORT aWidth, USHORT aHeight) const;

      private:
      USHORT itsWidth;
      USHORT itsHeight;
};

//---------------------------------------------------------------------------------------------------------------------------

//Constructor implementation outside class
Rectangle::Rectangle(USHORT width, USHORT height)
{
     itsWidth = width;
     itsHeight = height;
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded DrawAShape - takes no values. Draws based on current class member values
void Rectangle::DrawAShape() const
{
     DrawAShape( itsWidth, itsHeight);
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded DrawAShape - takes two values and draws shape based on the parameters
void Rectangle::DrawAShape(USHORT width, USHORT height) const
{
     for(USHORT i = 0; i<height; i++)
     {
         for(USHORT j = 0; j< width; j++)
         {   cout << "*";  }
    
     cout << "\n";
     } //end first for loop
}// close function

//----------------------------------------------------------------------------------------------------------------

int main()
{
    Rectangle ARectangle(30,5);

    cout << "DrawAShape(): \n";

    ARectangle.DrawAShape();       //calls overloaded function with no parameters

    cout << "\nDrawAShape(40,2): \n";

    ARectangle.DrawAShape(40,2);   //calls overloaded function that takes 2 parameters

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


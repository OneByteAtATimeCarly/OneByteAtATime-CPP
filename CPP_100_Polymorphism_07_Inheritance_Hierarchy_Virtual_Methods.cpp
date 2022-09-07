//Polymorphism 7 - hierarchy of classes - 2004 C. S. Germany

//Hierarchy of classes

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL { FALSE, TRUE };  //defining our own BOOL, instead of bool

//---------------------------------------------------------------------------------------------------------------------------

class Shape
{
      public:
      Shape(){}
      ~Shape(){}

      //Virtual methods to be overridden in each derived class
      virtual long GetArea() { return -1; }   //Error, it's virtual, base class method never meant to be used
      virtual long GetPerim() { return -1; }
      virtual void Draw() {}
      private:
};

//---------------------------------------------------------------------------------------------------------------------

class Circle : public Shape
{
      public:
      Circle(int radius):itsRadius(radius){}
      ~Circle(){}

      long GetArea() { return 3 * itsRadius * itsRadius; }
      long GetPerim() { return 9 * itsRadius; }
 
      void Draw();

      private:
      int itsRadius;
      int itsCircumference;
};

//---------------------------------------------------------------------------------------------------------------------------

//Draw() method defined outside class
void Circle::Draw()
{ cout << "Circle drawing routine here!\n"; }

//---------------------------------------------------------------------------------------------------------------------------

class Rectangle : public Shape
{
      public:
      Rectangle(int len, int width):itsLength(len), itsWidth(width){}
      ~Rectangle(){}

      virtual long GetArea() { return itsLength * itsWidth; }
      virtual long GetPerim() {return 2*itsLength + 2*itsWidth; }
      virtual int GetLength() { return itsLength; }
      virtual int GetWidth() { return itsWidth; }
      virtual void Draw();

      private:
      int itsWidth;
      int itsLength;
};

//---------------------------------------------------------------------------------------------------------------------------

//Draw() method defined outside class
void Rectangle::Draw()
{
     for(int i = 0; i<itsLength; i++)
     {
          for(int j = 0; j<itsWidth; j++) {
              cout << "x "; }

          cout << "\n";
     }
}

//---------------------------------------------------------------------------------------------------------------------------

class Square : public Rectangle
{
      public:
      Square(int len);
      Square(int len, int width);
      ~Square(){}

      long GetPerim() { return 4 * GetLength(); }
};

//---------------------------------------------------------------------------------------------------------------------------
//Define outside of class the overloaded constructor that takes one parameter
Square::Square(int len):Rectangle(len,len) { }

//---------------------------------------------------------------------------------------------------------------------------

//Define outside of class the overloaded constructor that takes two parameters
Square::Square(int len, int width):Rectangle(len,width)
{
        if(GetLength() != GetWidth())
            cout << "Error, not a square... a Rectangle??\n";
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int choice;
    BOOL fQuit = FALSE;
    Shape *sp;

    while(1)
    {
       cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
       cin >> choice;

       switch(choice)
       {
          case 1: sp = new Circle(5);
                  break;
          case 2: sp = new Rectangle(4,6);
                  break;
          case 3: sp = new Square(5);
                  break;
          default: fQuit = TRUE;
                   break;
       }

    if (fQuit)
         break;

    sp->Draw();

    cout << "\n";

    } //close while true loop

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








//Polymorphism 8 - Pure Virtual Methods - 2004 C. S. Germany

//ADT - Abstract Data Type.  An ADT, or Abstract Data Type, represents an ambiguous or vague concept like Shape, rather than an object of physical reality like Circle.
//ADT's are always base classes to other classes.  You can not make an instance of a class that is an ADT.  You declare a class to be an ADT by including 1 or more pure
//virtual functions in the class declaration.

//Pure Virtual Functions - Pure virtual functions are used to create ADT's.  Virtual functions are made pure by initializing them with 0.
//Example: virtual void Draw() = 0;  Once a class contains a pure virtual method, we can assume certain implications:

//The pure virtual method will NEVER be used, and it must ALWAYS be overridden in each derived class.
//The class that contains it is an ADT, and the base class for derived classes.
//Since the class is an ADT, there will NEVER be an instance or object of that class, only of derived classes.

//Any class deriving from an ADT inherits the pure virtual function as pure and so must override every pure virtual function in order to instantiate objects.
//If Rectangle inherits from Shape, and Shape has 3 pure virtual functions, then Rectangle must override all 3 of those pure virtual functions, else it will
//be an ADT itself.

//Typically pure virtual functions are never implemented, no objects are created that use them, and the ADT works purely as the definition of an interface to objects
//that derive from it.   The ADT never created objects of itself, only its derived classes have instances.  In this way it functions more as an organizational tool of
//the "Is-A/Has-A" relationship than an actual, working class structure.  You can provide an implementation to a pure virtual function, so that it can be called by
//objects derived from the ADT.  You might do this to provide common functionality to all of the overridden functions.  Below Shape is an ADT, the Circle class
//overrides Draw(), and then chains up to the base class function for additional functionality.

//The Shape class has now become an ADT.  If only one function is declared pure virtual, the class is an ADT.  Circle and Rectangle override Draw(),
//but chain up to the base method to take advantage of shared functionality.  You can derive ADTs from other ADTs.  In the code below, no Animal objects
//or Mammal objects can be instantiated because they are both base classes and both are ADTs.  However, all Mammals may inherit the Reproduce() method
//without overriding it.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL { FALSE, TRUE };  //defining our own BOOL, instead of bool

//---------------------------------------------------------------------------------------------------------------------------

class Shape
{
      public:
      Shape(){}
      ~Shape(){}

      //Pure virtual methods - each will HAVE to be overridden in derived classes.  This makes Shape an ADT.
      virtual long GetArea() = 0;     //Error unless overridden in each derived class.
      virtual long GetPerim()= 0;
      virtual void Draw() = 0;

      private:
};

//---------------------------------------------------------------------------------------------------------------------------

void Shape::Draw()
{ cout << "Abstract drawing mechanism!  Never used.\n"; }

//---------------------------------------------------------------------------------------------------------------------

class Circle : public Shape
{
      public:
      Circle(int radius):itsRadius(radius){}
      ~Circle(){}

      //We MUST override the 3 functions below since they were declared pure in the base class.
      long GetArea() { return 3 * itsRadius * itsRadius; }
      long GetPerim() { return 9 * itsRadius; }
      void Draw();

      private:
      int itsRadius;
      int itsCircumference;
};

//---------------------------------------------------------------------------------------------------------------------------

void Circle::Draw()
{
     cout << "Circle drawing routine here!\n";
     Shape::Draw();
}

//---------------------------------------------------------------------------------------------------------------------

class Rectangle : public Shape
{
      public:
      Rectangle(int len, int width):itsLength(len), itsWidth(width){}
      ~Rectangle(){}

      long GetArea() { return itsLength * itsWidth; }
      long GetPerim() {return 2*itsLength + 2*itsWidth; }


      virtual int GetLength() { return itsLength; }
      virtual int GetWidth() { return itsWidth; }
      void Draw();

      private:
      int itsWidth;
      int itsLength;
};

//---------------------------------------------------------------------------------------------------------------------------

void Rectangle::Draw()
{
     for (int i = 0; i<itsLength; i++)
     {
         for (int j = 0; j<itsWidth; j++) {
              cout << "x "; }
         cout << "\n";
     }

     Shape::Draw();
}

//---------------------------------------------------------------------------------------------------------------------

class Square : public Rectangle
{
      public:
      //2 overloaded constructors
      Square(int len);
      Square(int len, int width);
      ~Square(){}

      long GetPerim() { return 4 * GetLength(); }
};

//---------------------------------------------------------------------------------------------------------------------------

Square::Square(int len):Rectangle(len,len) { }

//---------------------------------------------------------------------------------------------------------------------------

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








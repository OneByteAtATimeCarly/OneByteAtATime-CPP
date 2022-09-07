//Function Pointers 5 - Pointers to class member functions - 2004 C. S. Germany

//Pointers to member functions - Unlike pointers to functions, pointers to member functions REQUIRE an object of the class on which to invoke them.
//There must be an instance.  Use same syntax as a pointer to a function, but INCLUDE the class name and the scoping operator (::).  For example:
//if FunctionPointer points to a member function of the class Shape which takes two integers and returns void, we would write the expression:
// void (Shape::*FunctionPointer) (int, int);

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL {FALSE, TRUE};

//---------------------------------------------------------------------------------------------------------------------------

class Mammal
{
      public:
      Mammal():itsAge(1) { }
      ~Mammal() { }
 
      virtual void Speak() const = 0;
      virtual void Move() const = 0;

      protected:
      int itsAge;
};

//---------------------------------------------------------------------------------------------------------------------------

class Dog : public Mammal
{
      public:
      void Speak() const { cout << "Woof!\n"; }
      void Move() const { cout << "Walking to heel...\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Cat : public Mammal
{
      public:
      void Speak() const { cout << "Meow!\n"; }
      void Move() const { cout << "slinking...\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Horse : public Mammal
{
      public:
      void Speak() const { cout << "Winnie!\n"; }
      void Move() const { cout << "Galloping...\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    //FunctionPointer points to a Mammal function.
    void (Mammal::*FunctionPointer)() const = 0;

    Mammal * ptr = 0;
    int Animal;
    int Method;
    BOOL fQuit = FALSE;

    while(fQuit == FALSE)
    {
       cout << "(0)Quit (1)dog (2)cat (3)horse: ";
       cin >> Animal;

           switch(Animal)
           {
              case 1: ptr = new Dog;   break;
              case 2: ptr = new Cat;   break;
              case 3: ptr = new Horse; break;
              default: fQuit = TRUE;   break;
           }

       if(fQuit)
          break;

       cout << "(1)Speak (2)Move: ";
       cin >> Method;

       switch(Method)
       {
          case 1: FunctionPointer = Mammal::Speak; break;
          default: FunctionPointer = Mammal::Move; break;
       }

       (ptr->*FunctionPointer)();

       delete ptr;
    } //close while true loop

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------







//Polymorphism 1 - Virtual Methods - 2004 C. S. Germany

//Virtual methods - Virtual methods are pointers to base classes that are assigned to derived class objects.  For example, if we wanted to use a pointer
//to access base class methods in Mammal, and yet create a Cat object on the free store, virtual methods would allow the Mammal methods that are overridden
//in Cat to call the correct functions in Cat, even though the pointer points to a base class Mammal object.  The functions in Mammal that would allow this
//would be marked with the keyword "virtual".  This allows us to dynamically allocate memory for Mammal objects when the derived Cat objects don't yet exist,
//and then later have their correct derived class methods called.

//In this example, Mammal is provided the VIRTUAL method "speak()".  Speak() is virtual, Move() is not.  This indicates this class expects to eventually be
//another class's base type.  This also signifies that the derived class will probably want to override this function.  A pointer to Mammal object is created,
//pSquirrel.  It is assigned the address of a new Squirrel object.  Squirrel is a Mammal - it derived from Mammal, so this is legal.  The pointer is then used
//to call the Move() function.  The compiler knows pSquirrel only to be a Mammal, and so looks to the Mammal object to find the Move() method.  This pointer
//is then used to call the "Speak()" method.  Because the Speak() method is virtual, the Speak() method in Squirrel is invoked, overriding the Mammal method's
//Speak().

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Mammal
{
      public:
      Mammal():itsAge(1) { cout << "Mammal constructor...\n"; }
      ~Mammal() { cout << "Mammal destructor...\n"; }

      void Move() const { cout << "Mammal move one step\n"; }
      virtual void Speak() const { cout << "Mammal making sound!\n"; } //virtual method

      protected:
      int itsAge;
};

//---------------------------------------------------------------------------------------------------------------------------

class Squirrel : public Mammal
{
      public:
      Squirrel() { cout << "Squirrel constructor...\n"; }
      ~Squirrel() { cout << "Squirrel destructor...\n"; }

      void SwishTail() { cout << "Swishing Tail...\n"; }
      void Speak()const { cout << "Squeak!\n"; }
      void Move()const { cout << "Squirrel moves 5 steps...\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{

    Mammal *MammalPointer = new Squirrel;
    MammalPointer->Move();
    MammalPointer->Speak();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



//Overriding 1 - The Basics - 2004 C. S. Germany

//Overriding functions involves changing the implementation of a base class function in a derived class within the class inheritance hierarchy. When you make an object of
//the derived class, the correct function is called, specific to the type of the child object rather than the parent object it inherits from.  

//Overriding in other words is when a derived class creates a function with the same return type and signature as a member in its base class, but with a new implementation.
//It is "overriding" that base-class or ADT method. When you override a function, it must agree in return type and signature with the function in the base class. 

//Function Signature - is a function prototype other than the return type - the name, the parameter list, and the keyword "const" if used.
//The signature of a function is its name and the # and type of its parameters.  The signature does not include the return type. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

enum BREED { RussianBlue, Persian, Siamese, Tabby, TortoiseShell, Himilayan };

//---------------------------------------------------------------------------------------------------------------------------

class Mammal
{
      public:
      //constructors
      Mammal() { cout << "Mammal constructor...\n"; }
      ~Mammal() { cout << "Mammal destructor...\n"; }

      //Other methods
      void Speak()const { cout << "Mammal sound!\n"; }
      void Sleep()const { cout << "Sleeping.\n"; }

      protected:
      int itsAge;
      int itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

class Cat : public Mammal
{
      public:
      //Constructors
      Cat(){ cout << "Cat constructor...\n"; }
      ~Cat(){ cout << "Cat destructor...\n"; }

      //Other methods
      void SwishTail() { cout << "Cat is angry...\n"; }
      void ChaseMice() { cout << "Chasing mice...\n"; }

      //Overriding the base class Mammal Speak method with one more specific to derived class Cat
      void Speak()const { cout << "Meow!\n"; }

      private:
      BREED itsBreed;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Mammal SmallAnimal;
    Cat Felix;
    SmallAnimal.Speak();
    Felix.Speak();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


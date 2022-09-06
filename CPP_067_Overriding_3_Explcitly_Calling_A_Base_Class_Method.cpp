//Overriding 3 - Explcitly Calling a Base Class Method to Un-hide IT - 2004 C. S. Germany

//You can use the scope operator :: to bypass the default behavior of an overriden function and EXPLICITLY call a base class method.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

enum BREED { RussianBlue, Persian, Siamese, Tabby, TortoiseShell, Himilayan };

//---------------------------------------------------------------------------------------------------------------------------

class Mammal
{
      public:
      //Constructor and destructor
      Mammal() { cout << "Mammal constructor...\n"; }
      ~Mammal() { cout << "Mammal destructor...\n"; }

      //Overloaded Move() methods
      void Move() const { cout << "Mammal move one step\n"; }

      void Move(int distance) const 
      { cout << "Mammal move " << distance <<" _steps.\n"; }

      void Move(int distance, char Direction) const
      { cout << "Mammal moving to the " << Direction << ".";}

      protected:
      int itsAge;
      int itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

class Cat : public Mammal
{
      public:
      //Constructor and Destructor
      Cat(){ cout << "Cat constructor...\n"; }
      ~Cat(){ cout << "Cat destructor...\n"; }
       
        //Other methods
      void SwishTail() { cout << "Cat is angry...\n"; }
      void ChaseMice() { cout << "Chasing mice...\n"; }
      void Speak()const { cout << "Meow!\n"; }

      //You may receive a compiler warning that you are hiding a function!
      //Because you are OVERRIDING the base class Move() function, which itself is OVERLOADED
      //CAT will not be able to access the other overloaded base class methods.
      //The base class Move() methods have been effectively HIDDEN from the Cat class.
      void Move() const { cout << "Cat move 5 steps.\n"; }

      private:
      BREED itsBreed;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
       Mammal SmallAnimal;

       Cat Morris;

       //Call Mammal's Move() methods
       SmallAnimal.Move();
       SmallAnimal.Move(2);

       //Call the Cat class Move() method that overrides the Mammal class Move() with no parameters
       Morris.Move();

       //EXPLICITLY call Mammal base class Move() method instead of overriding Cat derived class Move() method
       Morris.Mammal::Move(10);

       return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






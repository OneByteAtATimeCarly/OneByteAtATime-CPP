//Classes : Inheritance - 3 - Passing Arguments to Base Class Constructors in a Hierarchy - 2004 C. S. Germany
//Overloading constructors in derived classes

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

enum BREED { RussianBlue, Persian, Siamese, Tabby, TortoiseShell, Himilayan };

//---------------------------------------------------------------------------------------------------------------------------

class Mammal
{
      public:
      //2 overloaded constructors
      Mammal();
      Mammal(int age);
      ~Mammal();

      //Accessors
      int GetAge() const { return itsAge; }
      void SetAge(int age) { itsAge = age; }
      int GetWeight() const { return itsWeight; }
      void SetWeight(int weight) { itsWeight = weight; }

      //Other methods
      void Speak() const { cout << "Mammal noise.\n"; }
      void Sleep() const { cout << "Sleeping.\n"; }

      protected:
      int itsAge;
      int itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

//Define 2 overloaded Mammal Class constructors
Mammal::Mammal():
itsAge(1),
itsWeight(5)
{ cout << "Mammal constructor...\n"; }


Mammal::Mammal(int age):
itsAge(age),
itsWeight(5) { cout << "Mammal(int) constructor...\n"; }


Mammal::~Mammal()
{ cout << "Mammal destructor...\n"; }

//--------------------------------------------------------------------------------------------------------------------

//Class Cat is a child of Parent ADT Mammal
class Cat : public Mammal
{
      public:
      //Overloaded Constructors
      Cat();
      Cat(int age);
      Cat(int age, int weight);
      Cat(int age, BREED breed);
      Cat(int age, int weight, BREED breed);
      ~Cat();

      //Accessors
      BREED GetBreed() const { return itsBreed; }
      void SetBreed(BREED breed) { itsBreed = breed; }

      //Other methods
      void ChaseMice() { cout << "Here mousie mousie ... \n"; }
      void ScratchFavoriteChair() { cout << "Destroying expensive furniture ...\n"; }

      private:
      BREED itsBreed;
};

//---------------------------------------------------------------------------------------------------------------------------

//Define 5 overloaded Cat class constructors
Cat::Cat():
Mammal(),
itsBreed(RussianBlue)
{ cout << "Cat constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

Cat::Cat(int age):
Mammal(age),
itsBreed(RussianBlue)
{ cout << "Cat(int) constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

Cat::Cat(int age, int weight):
Mammal(age),
itsBreed(RussianBlue)
{
    itsWeight = weight;
    cout << "Cat(int, int) constructor...\n";
}

//---------------------------------------------------------------------------------------------------------------------------

Cat::Cat(int age, BREED breed):
Mammal(age),
itsBreed(breed)
{
    cout << "Cat(int, BREED) constructor...\n";
}

//---------------------------------------------------------------------------------------------------------------------------

Cat::Cat(int age, int weight, BREED breed):
Mammal(age),
itsBreed(breed)
{
    itsWeight = weight;
    cout << "Cat(int, int, BREED) constructor...\n";
}

//---------------------------------------------------------------------------------------------------------------------------

Cat::~Cat()
{ cout << "Cat destructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Cat Felix;
    Cat Tiger(5);
    Cat Feebie(6,8);
    Cat Princess (7,Persian);
    Cat Killah (4,42,Siamese);

    Felix.Speak();
    Tiger.ChaseMice();

    cout << "Princess is " << Princess.GetAge() << " years old\n";
    cout << "Killah weighs " << Killah.GetWeight() << " pounds\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








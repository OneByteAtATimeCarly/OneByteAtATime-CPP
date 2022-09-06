//Advanced Indirection 3 - Passing by Reference Using Constant Pointers and References - 2004 C. S. Germany

//We can combine the protection of passing by value, where a copy of the object is altered rather than the original, and the efficiency of passing by reference
//(not creating extra copies and consuming more memory) if we use constant pointers.  Passing a constant pointer prevents calling any non-constant method on
//Monster and protects the object from change.

//References may be used as an alternative. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster();
      Monster(Monster&);
      ~Monster();

      //Accessor methods
      int GetStrength() const { return itsStrength; }
      void SetStrength(int Strength) { itsStrength = Strength; }

      private:
      int itsStrength;
};

//---------------------------------------------------------------------------------------------------------------------------

//Monster Constructor
Monster::Monster()
{
    cout << "Monster Constructor...\n";
    itsStrength = 300;
}

//Monster Copy Constructor
Monster::Monster(Monster&)
{
    cout << "Monster Copy Constructor...\n";
}

//Monster Destructor
Monster::~Monster()
{
    cout << "Monster Destructor...\n";
}

//----------------------------------------------------------------------------------------------------------------

//Prototype - function returns a const reference to a const monster object
const Monster &PassMonsterByReference (const Monster &theMonster);

//----------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Making a Monster...\n";

    Monster Mothra;

    cout << "Mothra is of strength " << Mothra.GetStrength() << ".\n";

    int Strength = 700;

    Mothra.SetStrength(Strength);

    cout << "Mothra is of strength " << Mothra.GetStrength() << ".\n";
    cout << "Calling PassMonsterByReference...\n";
   
    //No need for address of operator since using references
    PassMonsterByReference(Mothra);

    cout << "Mothra is of strength " << Mothra.GetStrength() << ".";
   
    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//PassMonsterByReference passes a const reference to a const object
const Monster &PassMonsterByReference (const Monster &theMonster)
{
      cout << "Function Two. Returning...\n";
      cout << "Mothra is now of strength " << theMonster.GetStrength();
      cout << ".";
     
      //theMonster.SetStrength(8); Could not do this - members are constant!

      return theMonster;
}

//---------------------------------------------------------------------------------------------------------------------------




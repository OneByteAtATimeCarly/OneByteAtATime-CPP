//Advanced Indirection 2 - Combining the Protection of Passing By Value and the Efficiency of Passing by Reference Using Constant Pointers - 2004 C. S. Germany

//We can combine the protection of passing by value, where a copy of the object is altered rather than the original, and the efficiency of passing by reference
//(not creating extra copies and consuming more memory) if we use constant pointers.  Passing a constant pointer prevents calling any non-constant method on
//Monster and protects the object from change.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster();
      Monster(Monster&);
      ~Monster();

      //Accesor Methods
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
    itsStrength = 200;
}

//---------------------------------------------------------------------------------------------------------------------------

//Monster Copy Constructor
Monster::Monster(Monster&)
{
    cout << "Monster Copy Constructor...\n";
}

//---------------------------------------------------------------------------------------------------------------------------

//Monster Destructor
Monster::~Monster()
{
    cout << "Monster Destructor...\n";
}

//----------------------------------------------------------------------------------------------------------------

//Prototype - return a const pointer to a const Monster and also take one as an argument
const Monster *const PassMonsterByPointer(const Monster *const theMonster);

//----------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Making a monster...\n";

    Monster JollyGreenGiant;
   
    cout << "JollyGreenGiant is ";
    cout << "of strength " << JollyGreenGiant.GetStrength() << ".\n";

    int Strength = 500;

    JollyGreenGiant.SetStrength(Strength);
    cout << "JollyGreenGiant is ";
    cout << "of strength " << JollyGreenGiant.GetStrength() << ".\n";

    cout << "Calling PassMonsterByPointer...\n";

    //Must use address of operator when passing object since function uses a pointer
     //At this point, we don't have to catch the return value since it is just an alias of what is passed in
    PassMonsterByPointer(&JollyGreenGiant);

    cout << "JollyGreenGiant is of strength ";
    cout << JollyGreenGiant.GetStrength() << ".\n";

    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//PassMonsterByPointer, passes and returns a const pointer so its members can not be changed
const Monster *const PassMonsterByPointer(const Monster *const theMonster) {
 
      cout << "Function Two. Returning...\n";
      cout << "JollyGreenGiant is now of strength " << theMonster->GetStrength();
      cout << ".";
     
      //theMonster->SetStrength(8);  //Could not do this - members are constant and can't change!

      return theMonster;
}

//---------------------------------------------------------------------------------------------------------------------------




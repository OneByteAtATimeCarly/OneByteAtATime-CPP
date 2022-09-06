
//Advanced Indirection 1 - Copy Constructor, Copy Destructor - 2004 C. S. Germany

//copy constructor - called each time a temporary copy of an object is put on the stack. 
//copy destructor - if an object is returned by value, a copy of the object must be made and destroyed as well. 

//The copy constructor looks like the constructor - it has the same name as the class.  It is a reference or alias to the class.
//Note that, in large objects constructor and destructor calls are expensive in speed and memory.  

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster ();                //constructor
      Monster(Monster&);         //copy constructor
      ~Monster();                //destructor
     
      private:
      bool Hungry;
      int Strength; 
};

//---------------------------------------------------------------------------------------------------------------------------

//Monster constructor defined outside class
Monster::Monster() {
       cout << "Monster Constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

//Monster copy constructor defined outside class
Monster::Monster(Monster&) {
cout << "Monster Copy Constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

//Monster destructor defined outside class
Monster::~Monster(){
cout << "Monster Destructor...\n"; }

//----------------------------------------------------------------------------------------------------------------

//Declare (prototype) 2 functions with a return type of Monster
Monster PassMonsterByValue(Monster theMonster);
Monster *PassMonsterByPointer(Monster *theMonster);

//----------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Making a monster...\n";

    Monster KingKong;

    cout << "Calling PassMonsterByValue...\n";

    PassMonsterByValue(KingKong);      //passes by value, copy made, copy constructer used

    cout << "Calling PassMonsterByPointer...\n";

    PassMonsterByPointer(&KingKong);    //passes by reference, no copy made, copy constructer not used

    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//PassMonsterByValue, passes by value
Monster PassMonsterByValue(Monster theMonster)
{
        cout << "Function One. Returning...\n";
        return theMonster;
}

//---------------------------------------------------------------------------------------------------------------------------

//PassMonsterByPointer, passes by reference using a pointer
Monster *PassMonsterByPointer (Monster *theMonster)
{
        cout << "Function Two. Returning...\n";
        return theMonster;
}

//---------------------------------------------------------------------------------------------------------------------------




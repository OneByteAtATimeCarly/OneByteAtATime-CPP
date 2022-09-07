//Polymorphism 3 - Virtual Methods don't work when passing by value - 2004 C. S. Germany

//Virtual Methods don't work when passing by value. They only operate on pointers and references.
//v-table - virtual function table, keeps track of virtual functions
//vptr - (v-pointer) virtual table pointer, points to v-table.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Invoking virtual methods when passing by value?
#include <iostream.h>

//--------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster():itsAge(1) { }
      ~Monster() { }

      virtual void Speak() const { cout << "Monster speaking!\n"; }   

      protected:
      int itsAge;
};

//--------------------------------------------------------------------------------------------------------------------

class Giant : public Monster
{
      public:
      void Speak()const { cout << "Fee! Fi! Fo! Fum!\n"; }
};

//--------------------------------------------------------------------------------------------------------------------

class Ogre : public Monster
{
      public:
      void Speak()const { cout << "Grrrrrrrrrrrr!\n"; }
};

//--------------------------------------------------------------------------------------------------------------------

class Troll : public Monster
{
      public:
      void Speak()const { cout << "I hate you!\n"; }
};

//--------------------------------------------------------------------------------------------------------------------

class Dragon : public Monster
{
      public:
      void Speak()const { cout << "Hiss!\n"; }
};

//--------------------------------------------------------------------------------------------------------------------

//Function prototypes
void ValueFunction(Monster);           //attempting to pass mammal by value parameter
void PointerFunction(Monster*);        //pointer declared to Mammal parameter
void ReferenceFunction(Monster&);      //reference declared to Mammal parameter

//--------------------------------------------------------------------------------------------------------------------

int main()
{
    Monster *MonsterPointer=0;
    int choice;

    while(1)
    {
        bool fQuit = false;
        cout << "(1)Giant (2)Ogre (3)Troll (4)Dragon (0)Quit: ";
        cin >> choice;

        switch(choice)
        {
           case 0: fQuit = true;
                   break;
           case 1: MonsterPointer = new Giant;
                   break;
           case 2: MonsterPointer = new Ogre;
                   break;
           case 3: MonsterPointer = new Troll;
                   break;
           case 4: MonsterPointer = new Dragon;
                   break;
           default: MonsterPointer = new Monster;
                    break;
        }

    if(fQuit)
        break;  //Break out of the while true loop

    ValueFunction(*MonsterPointer);
    PointerFunction(MonsterPointer);
    ReferenceFunction(*MonsterPointer);

    } //end while true loop

    return 0;

} //close main()

//--------------------------------------------------------------------------------------------------------------------

void ValueFunction(Monster MonsterValue)             //attempting to pass Monster by value
{  MonsterValue.Speak();  }



void PointerFunction(Monster *pMonster)           //pointer declared to Monster
{  pMonster->Speak();  }



void ReferenceFunction(Monster &rMonster)            //reference declared to Monster
{  rMonster.Speak();  }

//---------------------------------------------------------------------------------------------------------------------------






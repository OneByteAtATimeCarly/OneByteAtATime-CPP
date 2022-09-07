//Polymorphism 2 - Virtual Methods - 2004 C. S. Germany

//Multiple virtual member functions called in turn

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster():itsAge(1) { }
      ~Monster() { }

      virtual void Speak() const { cout << "Monster speaking!\n"; }   

      protected:
      int itsAge;
};

//---------------------------------------------------------------------------------------------------------------------------

class Giant : public Monster
{
      public:
      void Speak()const { cout << "Fee! Fi! Fo! Fum!\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Ogre : public Monster
{
      public:
      void Speak()const { cout << "Grrrrrrrrrrrr!\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Troll : public Monster
{
      public:
      void Speak()const { cout << "I hate you!\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Dragon : public Monster
{
      public:
      void Speak()const { cout << "Hiss!\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Monster *ArrayOfMonsterPointers[5];
    Monster *SingleMonsterPointer;
    int choice, i;

    for(i = 0; i<5; i++)
    {
         cout << "(1)Giant (2)Ogre (3)Troll (4)Dragon: ";
         cin >> choice;

         switch(choice)
         {
          case 1: SingleMonsterPointer = new Giant;
                  break;
          case 2: SingleMonsterPointer = new Ogre;
                  break;
          case 3: SingleMonsterPointer = new Troll;
                  break;
          case 4: SingleMonsterPointer = new Dragon;
                  break;
          default: SingleMonsterPointer = new Monster;
                   break;
         }

      ArrayOfMonsterPointers[i] = SingleMonsterPointer;
    }

    for(i = 0;i < 5; i++)
        ArrayOfMonsterPointers[i]->Speak();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------





//Static Data 1 - 2004 C. S. Germany

//Static Member Data - Static member data is shared among all instances of a class.  In other words, if there were a
//Monster class, and if "int Count" were declared to be static, and there were 20 Monster objects, there would be only
//one instance of the integer Count among all 20 Monster objects.  Static member data is a compromise between global
//data (available throughout program) and member data (available only to each object.  

//A static data member belongs to the class rather than the object - they exist one per class throughout the class.
//Static members can be accessed without having an object if they have been declared in the class and they are public.
//They can be used as counters across instances of a class.  Since they are not part of an object, their declaration does not allocate memory.
//They must be defined and initialized outside the declaration of the class, though their prototype may be declared inside the class. 

//The declaration of "HowManyMonsters" does not define an integer - unlike non-static members, no storage space is set aside.
//The variable must be declared and defined outside since, it is not in the object instance.  It is a common mistake to forget
//to define static member variables of classes outside the class.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster(int strength = 1):itsStrength(strength)
      {  //Every time a Monster object is created, we will increment the static data member in the constructor.
        HowManyMonsters++; }
      virtual ~Monster() { HowManyMonsters--; }

      //Accessor Methods
      virtual int GetStrength() { return itsStrength; }
      virtual void SetStrength(int strength) { itsStrength = strength; }

      //Static data member, so it must be initialized OUTSIDE the class
      static int HowManyMonsters;

      private:
      int itsStrength;
};

//---------------------------------------------------------------------------------------------------------------------------

//Static member data, must be initialized OUTSIDE the class.  Only one for all Monster objects.
int Monster::HowManyMonsters = 0;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{  
    int i;
    const int MaxMonsters = 5;
    //MonsterHouse is an array of 5 Monster pointers
    Monster *MonsterHouse[MaxMonsters];

    for(i = 0; i<MaxMonsters; i++)
        //Create a new Monster on the heap and have this element point to it.
        MonsterHouse[i] = new Monster(i*100); 

    for(i = 0; i<MaxMonsters; i++)
    {
         cout << "There are ";
         cout << Monster::HowManyMonsters;
         cout << " Monsters left!\n";
         cout << "Deleting the one which has strength ";
         cout << MonsterHouse[i]->GetStrength();
         cout << ".\n";

         //Delete Monster object to clean up.  Initialize it to 0 to avoid accidents.
         delete MonsterHouse[i];
         MonsterHouse[i] = 0;
    }

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




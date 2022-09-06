//Arrays 5 - Declaring Objects on FreeStore and Storing Pointers to Those Objects in an Array - 2004 C. S. Germany

//When we declare an array, the compiler sets aside memory for all its objects, even if you never use them.  This isn't a problem when you know how many objects you need,
//but when you don't, you must use more advanced data structures such as pointers and references to create objects on the heap (free store).  By declaring objects on the
//free store and storing only a pointer to the object in an array, you can leave the limited constraint of stack memory and use free store memory which is far larger.
//This greatly reduces amount of stack memory used. It also increases efficiency because you can iterate, search and recurse indexed memory locations rather than entire objects.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster() { itsAge = 1; itsWeight=5; }
      ~Monster() {}

      //Accessor methods
      int GetAge() const { return itsAge; }
      int GetWeight() const { return itsWeight; }
      void SetAge(int age) { itsAge = age; }

      private:
      int itsAge;
      int itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    //Create an array of 500 pointers to Monster objects on FreeStore. MUCH faster and MUCH less memory than 500 actual objects. 
    Monster *ArmyOfDarkness[500];
   
    int x;
   
    //Create a pointer to a Monster object
    Monster *MonsterPointer;
 
    for(x = 0; x < 500; x++)
    {
         //Create a new Monster object on the heap and point to it with MonsterPointer
        MonsterPointer = new Monster;
        MonsterPointer->SetAge(2*x + x);

        //Copy the object pointed to by MonsterPointer to the corresponding pointer element of the array
        ArmyOfDarkness[x] = MonsterPointer;
    }

    for(x = 0; x < 500; x++)
        cout << "Monster #" << x+1 << ": " << ArmyOfDarkness[x]->GetAge() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






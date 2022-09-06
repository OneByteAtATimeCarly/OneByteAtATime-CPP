//Arrays 6 - Declaring An Array of Objects on the FreeStore (Heap) - 2004 C. S. Germany

//We can also create an array declaring arrays on the free store - you can place an entire array on the free store(heap). To do this, call "new" and use the subscript operator.
//The result is a pointer to an area on the free store that holds the array.  In the first example, we had an array of 500 pointers to Monster objects on the heap.
//In this next example, we will create a single pointer to an array of 500 Monster objects on the heap.

//Monster *MotleyCrew = new Monster[500];          //Instantiate 500 Monsters on the Heap (FreeStore)
//Monster *MonsterPointer = MotleyCrew;            //MonsterPointer points to MotleyCrew[0]
//MonsterPointer ->SetAge(10);                     //set MotleyCrew[0] to 10
//MonsterPointer++;                                //advance to element MotleyCrew[1]
//MonsterPointer->SetAge(20);                      //set MotleyCrew[1] to 20

//A pointer to an array versus an array of pointers - Observe the differences:
//1) Monster MonsterMashOne[500];                                              //this is an array of 500 Monsters on the free store.
//2) Monster *MonsterMashTwo[500];                                             //this is an array of 500 pointers to Monsters. 
//3) Monster *MonsterMashThree = new Monster[500];                             //this is a single pointer to an array of 500 Monsters on the heap. 

//An array name is a const pointer to the first element of the array.  In the declaration Monster MotleyCrew[50]; , MotleyCrew is a pointer to  &MotleyCrew[0].  It is legal to
//use array names as const pointers and vice versa, so MotleyCrew + 4 is a legitimate way of accessing the data at MotleyCrew[4] . The compiler does all the math when adding, //incrementing and decrementing pointers. The address accessed when writing Monster+4 isn't 4 bytes past the address of Family, it is 4 objects.  If each object is 4 bytes long,
//then Monster+4 is 16 bytes. Below is an example of declaring and using an array on the free store:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster() { itsAge = 1; itsWeight=5; }
      ~Monster();

      //Accessor methods
      int GetAge() const { return itsAge; }
      int GetWeight() const { return itsWeight; }
      void SetAge(int age) { itsAge = age; }

      private:
      int itsAge;
      int itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

Monster :: ~Monster()
{
   cout << "Destructor called!\n";
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Monster *CookieMonster = new Monster[500];

    int i;

    Monster *MonsterPointer;

    for(i = 0; i < 500; i++)
    {
        MonsterPointer = new Monster;

        MonsterPointer->SetAge(2*i +1);
        CookieMonster[i] = *MonsterPointer;

        delete MonsterPointer;
    }


   for(i = 0; i < 500; i++)
       cout << "CookieMonster #" << i+1 << ": " << CookieMonster[i].GetAge() << endl;

   delete [] CookieMonster;

   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








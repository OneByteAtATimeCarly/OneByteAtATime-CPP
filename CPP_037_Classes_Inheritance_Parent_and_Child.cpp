//Classes : Inheritance - 1 - ADTs, Parent and Child classes - 2004 C. S. Germany
//Simple inheritance : The "Is-a" Relationship

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

enum BREED { JollyGreen, Friendly, Mean, Cannibalistic, Vegetarian, Mutant };

//--------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster();
      ~Monster();

       //Accessor methods
      int GetStrength()const;
      void SetStrength(int str);
      int GetWeight() const;
      void SetWeight(int wgt);

      //Other methods
      void Speak();
      void Attack();

      protected:
      int Strength;
      int Weight;
};

//--------------------------------------------------------------------------------------------------------------------

class Giant : public Monster
{
      public:

      //Constructors
      Giant();
      ~Giant();

     //Accessors
     BREED GetBreed() const;
     void SetBreed(BREED thebreed);

   //Other methods
   FeFiFoFum();
   FallDownTheBeanStalk();

   protected:
   BREED itsBreed;
};

//--------------------------------------------------------------------------------------------------------------------

void main() {   }

//---------------------------------------------------------------------------------------------------------------------------




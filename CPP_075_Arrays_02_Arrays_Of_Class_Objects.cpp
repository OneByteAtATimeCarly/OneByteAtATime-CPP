//Arrays 2 - Arrays of Class Objects - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster() { itsAge = 1; itsWeight=5; }    //default constructor
      ~Monster() {}                             //destructor

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
    //Create an array of Monster objects.
    Monster MotleyCrew[5];

    int i;

    //The following will count up on odd numbers
    for(i = 0; i < 5; i++)
        MotleyCrew[i].SetAge(2*i + 1);

    for(i = 0; i < 5; i++)
        cout << "Monster #" << i+1<< ": " << MotleyCrew[i].GetAge() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


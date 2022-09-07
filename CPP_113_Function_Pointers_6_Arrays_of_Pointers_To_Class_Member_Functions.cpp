//Function Pointers 6 - array of pointers to class member functions - 2004 C. S. Germany

//Pointers to class member functions can be stored in an array.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum BOOL {FALSE, TRUE};

//---------------------------------------------------------------------------------------------------------------------------

class Dog
{
      public:
      void Speak() const { cout << "Woof!\n"; }
      void Move() const { cout << "Walking to heel...\n"; }
      void Eat() const { cout << "Gobbling food...\n"; }
      void Growl() const { cout << "Grrrrr\n"; }
      void Whimper() const { cout << "Whining noises...\n"; }
      void RollOver() const { cout << "Rolling over...\n"; }

      void PlayDead() const 
      { cout << "Is this the end of Little Caeser?\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

//Sets up PDF to be a pointer to a Dog function.
typedef void (Dog::*PDF)()const ;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    const int MaxFuncs = 7;

    //Create an array of pointers to Dog class functions.
    PDF DogFunctions[MaxFuncs] =
    { Dog::Speak,
      Dog::Move,
      Dog::Eat,
      Dog::Growl,
      Dog::Whimper,
      Dog::RollOver,
      Dog::PlayDead  };

      //Create a pointer to a dog object.
      Dog * pDog = 0;
      int Method;
      BOOL fQuit = FALSE;

     while (!fQuit)
     {
        cout << "(0)Quit (1)Speak (2)Move (3)Eat (4)Growl";
        cout << " (5)Whimper (6)Roll Over (7)Play Dead: ";
        cin >> Method;

        if (Method == 0) {
            fQuit = TRUE;
            break;
        }
        else {
               pDog = new Dog;   //Create a new Dog on the heap.  Point to it.
               (pDog->*DogFunctions[Method-1])();
               delete pDog;
        }
     }  //close while true loop

     return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






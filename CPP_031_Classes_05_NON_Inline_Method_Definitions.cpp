//Classes - 05 - NON-Inline Method Definitions, Constructors and Destructors, Custom vs. Default - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>  

//---------------------------------------------------------------------------------------------------------------------------

//Define the class
class Cat  {

        public:

        Cat(int initialAge);         //constructor
        ~Cat();                      //destructor

        int GetAge();                //accessor function
        void SetAge(int age);        //accessor function
        void Meow();

        private:
        int itsAge;                  //member variable
};


//---------------------------------------------------------------------------------------------------------------------------

//constructor of Cat defined outside of class (needs ::)
Cat::Cat(int initialAge)
{  itsAge = initialAge;  }

//---------------------------------------------------------------------------------------------------------------------------

//destructor defined outside class, takes no action
Cat::~Cat()
{   }

//---------------------------------------------------------------------------------------------------------------------------

//Accessor method defined outside class
int Cat::GetAge()
{ return itsAge; }

//---------------------------------------------------------------------------------------------------------------------------

void Cat::SetAge(int age)
{ itsAge = age; }

//---------------------------------------------------------------------------------------------------------------------------

void Cat::Meow()
{ cout << "Meow.\n"; }

//------------------------------------------------------------------------------------------------------------------- 

int main() {

    Cat Felix(5);
    Felix.Meow();

    cout << "Felix is a cat who is " ;
    cout << Felix.GetAge() << " years old.\n";

    Felix.Meow();
    Felix.SetAge(7);
 
    cout << "Now Felix is " ;
    cout << Felix.GetAge() << " years old.\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






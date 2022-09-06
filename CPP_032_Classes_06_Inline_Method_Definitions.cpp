//Classes - 06 - Inline Method Definitions - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>  

//---------------------------------------------------------------------------------------------------------------------------

//Define the class
class Cat
{
public:
Cat (int initialAge);
~Cat();

int GetAge() { return itsAge;}             //automatically inline!
void SetAge (int age) { itsAge = age;}     //automatically inline!

void Meow() { cout << "Meow.\n";}          //automatically inline!

private:
int itsAge;
};


//---------------------------------------------------------------------------------------------------------------------------

Cat::Cat(int initialAge)         //constructor defined outside class
{  itsAge = initialAge;  }

//---------------------------------------------------------------------------------------------------------------------------

Cat::~Cat()                      //destructor defined outside class          
{  } 

//---------------------------------------------------------------------------------------------------------------------------

int main() {

    Cat Felix(5);
    Felix.Meow();

    cout << "Felix is a cat who is " ;
    cout << Felix.GetAge() << " years old. \n";
   
    Felix.Meow();
    Felix.SetAge(7);

    cout << "Now Felix is " ;
    cout << Felix.getAge() << " years old. \n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






//Classes - 03 - Defining Class Functions NOT Inline - 2004 C. S. Germany

//Defining a class's functions and methods within its specification makes them inline.  In cases where this is inefficient or uncalled for, 
//or where a class's methods or data may be static or friend functions, the declaration of a method is within a class and the definition
//(implementation) of that method is outside the class.  When so doing it is necessary to use scope resolution ::

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>  

//---------------------------------------------------------------------------------------------------------------------------

//Define the class
class Cat
{
       public:
       int GetAge();
       void SetAge (int age);
       void Meow();

       private:
       int itsAge;
};

//---------------------------------------------------------------------------------------------------------------------------
 
//Since we are defining the functions outside the class, we must use the class name and "::".

//---------------------------------------------------------------------------------------------------------------------------

int Cat::GetAge()
{
     return itsAge;
}

//---------------------------------------------------------------------------------------------------------------------------
 
void Cat::SetAge(int age)
{
       itsAge = age;
}

//---------------------------------------------------------------------------------------------------------------------------

void Cat::Meow()
{
       cout << "Meow.\n";
}

//------------------------------------------------------------------------------------------------------------------- 

int main()
{
    Cat Felix;
    Felix.SetAge(5);
    Felix.Meow();

    cout << "Felix is a cat who is " ;
    cout << Felix.GetAge() << " years old.\n";
    Felix.Meow();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




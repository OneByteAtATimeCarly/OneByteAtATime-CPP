//Advanced Indirection 4 - Don't Reutrn References to Objects Outside Scope - 2004 C. S. Germany

//Don't return a reference to an object that isn't in scope - don't overdo referencing.  We must ask, "What is the object I am aliasing, and will it
//still exist every time it is used?".  Here is an example of the danger of returning a reference to an object that no longer exists:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
        public:
        Employee(int age, int SSN);
       ~Employee() {}

       //Accessor methods
       int GetAge() { return itsAge; }
       int GetSSN() { return itsSSN; }

       private:
       int itsAge;
       int itsSSN;
};

//---------------------------------------------------------------------------------------------------------------------------

//Define constructor, shorthand way of assigning values through accesors
Employee::Employee(int age, int SSN):
itsAge(age), itsSSN(SSN) {}


//---------------------------------------------------------------------------------------------------------------------------

//Returns a reference to an employee
Employee &GoingNowhere();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee &RefToEmployee = GoingNowhere();
    int age = RefToEmployee.GetAge();
    cout << "RefToEmployee is " << age << " years old!\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

Employee &GoingNowhere()
{
     Employee DrewBarrymore(5,9);
     return DrewBarrymore;
}

//---------------------------------------------------------------------------------------------------------------------------





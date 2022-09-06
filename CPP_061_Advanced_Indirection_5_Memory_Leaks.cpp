//Advanced Indirection 5 - Memory Leaks - 2004 C. S. Germany

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

      //Accesor methods
      int GetAge() { return itsAge; }
      int GetSSN() { return itsSSN; }

      private:
      int itsAge;
      int itsSSN;
};

//---------------------------------------------------------------------------------------------------------------------------

//Define constructor, shorthand way of assigning values through accesors
Employee::Employee(int age, int SSN):itsAge(age), itsSSN(SSN) {   }

//---------------------------------------------------------------------------------------------------------------------------

Employee &MemoryLeak();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee &RefToEmployee = MemoryLeak();

    int age = RefToEmployee.GetAge();
   
    cout << "RefToEmployee is " << age << " years old!\n";
    cout << "Address of &RefToEmployee: " << &RefToEmployee << endl;

   //How do you get rid of that memory?

   Employee *CarlySalaliGermany = &RefToEmployee;
   delete CarlySalaliGermany;
  
   //Uh oh, RefToEmployee now refers to what?  NULL?

   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//This function creates an employee object on the heap aliased by a reference
Employee &MemoryLeak()
{
         //Since CarlySalaliGermany is a pointer, using it without dereferencing
         //it will render a memory address rather than a value!
         Employee *CarlySalaliGermany = new Employee(34,250);
         cout << "Address of CarlySalaliGermany: " << CarlySalaliGermany << endl;
         return *CarlySalaliGermany;
}

//---------------------------------------------------------------------------------------------------------------------------







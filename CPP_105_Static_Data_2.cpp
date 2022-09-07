//Static Data 2 - 2004 C. S. Germany

//Static member functions - Static member functions, like static member data, exists not in the instance of the object but in scope of class.
//They can be called without having an object instance of the class.  They exist outside the class and are singly shared by all objects of the class.
//Static member functions have no "this" pointer, and so they can not be declared "const".  It is important to note that, static member functions
//cannot access any non-static member variables.  This is because a class's member data variables are accessed via member functions using the "this" pointer.
//The example below serves as an illustration of a static member function.

//The EmployeeCount() function can access the public static accessor, even though it has no access to an instance of an Employee object.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
      public:
      Employee(int age = 1):itsAge(age){HowManyEmployees++; }
      virtual ~Employee() { HowManyEmployees--; }

      virtual int GetAge() { return itsAge; }
      virtual void SetAge(int age) { itsAge = age; }

      //Public accessor method for private data.  Return type must also include static.
      static int GetHowMany() { return HowManyEmployees; }

      private:
      int itsAge;
      //HowManyEmployees is private, so it must be accessed via a public accessor method this time.
      static int HowManyEmployees;
};

//---------------------------------------------------------------------------------------------------------------------------

int Employee::HowManyEmployees = 0;

//---------------------------------------------------------------------------------------------------------------------------

//Declare/Prototype EmployeeCount function
void EmployeeCount();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int i;
    const int MaxEmployees = 6;
    Employee *EmployeeGroup[MaxEmployees];

    for (i = 0; i<MaxEmployees; i++)
    {
        EmployeeGroup[i] = new Employee(i);
        EmployeeCount();
    }

    for ( i = 0; i<MaxEmployees; i++)
    {
         delete EmployeeGroup[i];
         EmployeeGroup[i] = 0;
         EmployeeCount();
    }

    return 0;

}

//---------------------------------------------------------------------------------------------------------------------------

void EmployeeCount()
{
     cout << "There are " << Employee::GetHowMany() << " Employees alive!\n";
}

//---------------------------------------------------------------------------------------------------------------------------





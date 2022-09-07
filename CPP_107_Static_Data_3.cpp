//Static Data 3 - 2004 C. S. Germany

//Includes header file

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_106_Static_Data_3.h"

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
      public:
      //Overloaded constructors
      Employee();
      Employee(char *, char *, char *, long);
      //Destructor
      ~Employee();

      //Copy constructor
      Employee(const Employee&);

      Employee & operator= (const Employee &);

      //Accessor methods
      const String & GetFirstName() const { return itsFirstName; }
      void SetFirstName(const String & fName) { itsFirstName = fName; }

      const String & GetLastName() const { return itsLastName; }
      void SetLastName(const String & lName) { itsLastName = lName; }

      const String & GetAddress() const { return itsAddress; }
      void SetAddress(const String & address) { itsAddress = address; }

      void SetSalary(long salary) { itsSalary = salary; }
      long GetSalary() const { return itsSalary; }

      private:
      String itsFirstName;
      String itsLastName;
      String itsAddress;
      long itsSalary;
};

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded constructor definitions
Employee::Employee():
itsFirstName(""),
itsLastName(""),
itsAddress(""),
itsSalary(0)
{}

//---------------------------------------------------------------------------------------------------------------------------

Employee::Employee(char * firstName, char * lastName,
char * address, long salary):
itsFirstName(firstName),
itsLastName(lastName),
itsAddress(address),
itsSalary(salary)
{}

//---------------------------------------------------------------------------------------------------------------------------

//Copy constructor definition
Employee::Employee(const Employee & rhs):
itsFirstName(rhs.GetFirstName()),
itsLastName(rhs.GetLastName()),
itsAddress(rhs.GetAddress()),
itsSalary(rhs.GetSalary())
{}

//---------------------------------------------------------------------------------------------------------------------------

//Destructor definition
Employee::~Employee() {}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded assignment operator =. Copies all class's data members to object passed in.
Employee & Employee::operator= (const Employee & rhs)
{
        if(this == &rhs)
           return *this;

        itsFirstName = rhs.GetFirstName();
        itsLastName = rhs.GetLastName();
        itsAddress = rhs.GetAddress();
        itsSalary = rhs.GetSalary();

        return *this;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee Carly("Carly","Germany","44 Alamanda Drive", 20000);
    Carly.SetSalary(50000);

    String LastName("Gaines");

    Carly.SetLastName(LastName);
    Carly.SetFirstName("Robert");

    cout << endl << endl;
    cout << "Name: ";
    cout << Carly.GetFirstName().GetString();
    cout << " " << Carly.GetLastName().GetString();
    cout << ".\nAddress: ";
    cout << Carly.GetAddress().GetString();
    cout << ".\nSalary: " ;
    cout << Carly.GetSalary();
    cout << endl << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------





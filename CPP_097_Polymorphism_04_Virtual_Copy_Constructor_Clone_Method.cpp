//Polymorphism 4 -  - 2004 C. S. Germany

//Virtual copy constructor - Clone Method

//Virtual destructors and Clone Methods - When a pointer to a derived object is deleted, the derived class's destructor is called automatically, invoking the base class's destructor. 
//If any functions in the class are virtual, the destructor should be as well.  It is important to note that NO constructor can be virtual! What if you want to pass in a pointer to
//a base object, and have a copy of the correct derived object that is created?  A solution is to create a clone method in the base class and make the method virtual.  Clone methods
//create a new copy of the current object and then return that object using the "this" pointer.  Because each derived class overrides the clone method, a copy of the entire derived
//class is created. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
      public:
      Employee():SSN(1) { cout << "Employee constructor.\n"; }
      ~Employee() { cout << "Employee destructor.\n"; }
      Employee (const Employee & rhs);

      //Accessor methods
      double GetSSN() const { return SSN; }
      void SetSSN(double social) { SSN = social; }
      float GetPayRate() const { return PayRate; }
      void SetPayRate(float pay) { PayRate = pay; }
     

      //Virtual methods
      virtual void IdentifySelf() const { cout << "I am a generic Employee.\n"; }
      virtual Employee *Clone() { return new Employee(*this); }   

      protected:
      double SSN;
      float PayRate;
};

//Employee Copy Constructor defined outside the employee class.
Employee::Employee (const Employee & rhs):SSN(rhs.GetSSN())
{ cout << "Employee Copy Constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

class EmpManager : public Employee
{
      public:
      EmpManager() { cout << "EmpManager constructor...\n"; }
      ~EmpManager() { cout << "EmpManager destructor...\n"; }
      EmpManager (const EmpManager & rhs);

      void IdentifySelf()const { cout << "I am an manager.\n"; }

      virtual Employee *Clone() { return new EmpManager(*this); }

      //Accessor methods
      void SetManagerLevel(int level) {ManagerLevel = level;}
      int GetManagerLevel() { return ManagerLevel; }
      void SetPayBonus(float bonus) {PayBonus = bonus;}
      float GetPayBonus() { return PayBonus; }

      private:
      int ManagerLevel;
      float PayBonus;

};

//---------------------------------------------------------------------------------------------------------------------------

//Manager copy constructor defined outside class
EmpManager::EmpManager(const EmpManager & rhs):
Employee(rhs)
{ cout << "EmpManager copy constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

class EmpClerk : public Employee
{
      public:
      EmpClerk() { cout << "EmpClerk constructor...\n";
                   PerfectAttendence = false;
                   EmployeeOfTheMonth = false;  }

      ~EmpClerk() { cout << "EmpClerk destructor...\n"; }

      EmpClerk (const EmpClerk &);

      void IdentifySelf()const { cout << "I am a clerk.\n"; }

      virtual Employee *Clone() { return new EmpClerk(*this); }

      void IfEmployeeOfTheMonth() {
           if(EmployeeOfTheMonth == true){
              cout << "\nEmployee wins Employee Of The Month status."
                   << "\nUpgrade employee\'s parking place."; }
           else { cout << "Sorry.  This employee does not meet the requirements."; }
      } //close function
 
      private:
      bool PerfectAttendence;
      bool EmployeeOfTheMonth;
};

//---------------------------------------------------------------------------------------------------------------------------

//Clerk copy constructor defined outside class
EmpClerk::EmpClerk(const EmpClerk & rhs):
Employee(rhs)
{ cout << "EmpClerk copy constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

enum EmployeeType{GenericEmployee, Manager, Clerk};
const int NumEmployeeTypes = 3;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee *EmployeePointerArray[NumEmployeeTypes];
    Employee *SingleEmployeePointer;

    int choice;
    int i;

    for(i = 0; i<NumEmployeeTypes; i++)
    {
        cout << "(1)Manager (2)Clerk (3)Employee: ";
        cin >> choice;

            switch(choice)
            {
               case Manager: SingleEmployeePointer = new EmpManager;
                             break;
               case Clerk: SingleEmployeePointer = new EmpClerk;
                           break;
               default: SingleEmployeePointer = new Employee;
                        break;
            }

        EmployeePointerArray[i] = SingleEmployeePointer;
    }  //close for loop


    Employee *AnotherEmpPointerArray[NumEmployeeTypes];

    for(i=0; i<NumEmployeeTypes; i++)
    {
         //Calling IdentifySelf() on a generic Employee pointer works since it's virtual and overridden in each derived class.
         EmployeePointerArray[i]->IdentifySelf();

         AnotherEmpPointerArray[i] = EmployeePointerArray[i]->Clone();
    }

    for(i=0; i<NumEmployeeTypes; i++) {
           //Calling IdentifySelf() on a generic Employee pointer works since it's virtual and overridden in each derived class.
        AnotherEmpPointerArray[i]->IdentifySelf(); }

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






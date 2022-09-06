//Classes : Inheritance - 2 - Public, Protected and Private Data - 2004 C. S. Germany
//Example of protected

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

enum EmpType { LevelOne, LevelTwo, LevelThree };

//---------------------------------------------------------------------------------------------------------------------------

class Employee{
      public:
      //Constructor and destructor
      Employee():PayRate(6.55), SSN(000000000) {
                 cout << "\nAn Employee has been created!\n"; }
      ~Employee() {cout << "Employee object being destroyed."; }

     //Accessor methods
     float GetPayRate()const { return PayRate; }
     void SetPayRate(float pay) { PayRate = pay; }
     long GetSSN() const { return SSN; }
     void SetSSN(long social) { SSN = social; }

     //Other methods
     void Promote()const { cout << "Give them a pay raise!\n";
                           cout << "Employee moved up one level in the food chain!\n"; }
     void Demote()const { cout << "Bump them down a level.\n"; }

     protected:
     long SSN;
     float PayRate;
};

//---------------------------------------------------------------------------------------------------------------------------

class Manager : public Employee {
      public:
      //Constructor sets EmpType to LevelOne as default
      Manager():itsEmpType(LevelOne){
                cout << "A Manager that derives from an Employee has been created!\n";}
      ~Manager(){ cout << "Manager object being destroyed."; }

      //Accessors
      EmpType GetEmpType() const { return itsEmpType; }
      void SetEmpType(EmpType EType) { itsEmpType = EType; }

      //Other methods
      void Hire() { cout << "It's your lucky day!\n"; }
      void Fire() { cout << "Don\'t let the door hit you on the way out.\n"; }

      private:
      EmpType itsEmpType;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee CharlesGermany;

    cout << "Employee CharlesGermany makes $" << CharlesGermany.GetPayRate()
         << " per hour!\n";

    CharlesGermany.SetSSN(345768976);

    cout << "CharlesGermany\'s social is: " << CharlesGermany.GetSSN() << ".\n\n";


    Manager MyWonderfulBoss;

    MyWonderfulBoss.Hire();
    MyWonderfulBoss.Promote();

    MyWonderfulBoss.SetSSN(265235687);

    cout << "MyWonderfulBoss\'s social: " << MyWonderfulBoss.GetSSN() << ".\n";

    MyWonderfulBoss.SetPayRate(65.25);

    cout << "Manager MyWonderfulBoss makes $" << MyWonderfulBoss.GetPayRate()
         << " per hour!\n\n\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






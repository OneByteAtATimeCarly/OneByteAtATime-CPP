//Project - Database1 - 01 - Classes - 2004 C. S. Germany
//File 1 of 3 - Database1 Classes - ©2004 C. S. Germany
//Header file

//---------------------------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function prototypes
bool VerifyPassword();

//---------------------------------------------------------------------------------------------------------------------------

class Employee 
{
   public: 

   static int PrimaryKey;

        //Overloaded constructors
	Employee()  
        { 
	          Initialize();

                  PrimaryKey++;
                  EmpID = PrimaryKey;

                  cout << "\nA New Employee object was created.";  
        } 


	Employee(int EID, int DID, float sal, long social, long hd, long rd, 
                 char * first, char * last, char * job) 
        {
                EmpID = EID;
                DeptID = DID;
		salary = sal;
		SSN = social;
		HireDate = hd;
		ReviewDate = rd;
                FirstName[20] = first[20];
                LastName[20] = last[20];
		JobDescription[40] = job[40];

                EmpID = ++PrimaryKey;
	}
	
        //Our destructor will clean up our heap objects created in the EditEmployee function
	~Employee() 
        { 
               cout << "\nEmployee object deleted.\n"; 
        }

	//Accesor methods
	int GetEmpID() { return EmpID; } 
	void SetEmpID(int eid) { EmpID = eid; } 
        
	int GetDeptID() { return DeptID; } 
        void SetDeptID(int ID) { DeptID = ID; }

	float GetSalary() { return salary; } 
        void SetSalary(float sal) { salary = sal; }

	long GetSSN() { return SSN; } 
        void SetSSN(long social) { SSN = social; }

	long GetHireDate() { return HireDate; } 
        void SetHireDate(long hire) { HireDate = hire; }

	long GetReviewDate() { return ReviewDate; } 
        void SetReviewDate(long review) { ReviewDate = review; }
	char * GetFirstName() { return FirstName; }
	void SetFirstName(char first[20]) { FirstName[20] = first[20]; }
	char * GetLastName() { return LastName; }
	void SetLastName(char last[20]) { LastName[20] = last[20]; }

	char * GetJobDescription() { return JobDescription; }
	void SetJobDescription(char description[40]) { JobDescription[40] = description[40]; }
    

	//Other methods
	void EditEmployee() {
        
             //Create character arrays on the heap so they will persist when the function ends and not go out of scope   
	     char First[20]; 
	     char Last[20];
	     char Desc[40];
             bool LegitimatePass;
	     int x = 0;
             //Check to make sure it's a manager and they have the correct password
             LegitimatePass = VerifyPassword();
             if(LegitimatePass == false) 
	     { 
	          cout << "   Sorry.  You do not have permission to access this feature.\n\n"; 
	     }
             else 
	     {
       	          cout.flush();
		  system("CLS");
	          cout << "\n   Welcome!  You may edit employee information below for";
	          cout << " employee # " << GetEmpID() << ".\n\n";
                  cout << "************ Edit Employee Information *************\n";
                  cout << "\n\nEmployee ID: " << GetEmpID() << endl;
   		  cout << "\nEnter Department ID: ";
		  cin >> DeptID;
		  cout << "\nEnter First Name: ";
		  cin >> First;		  
		  cout << "\nEnter Last Name: ";
		  cin >> Last;		  
		  cout << "\nEnter Job Description: ";
		  cin >> Desc;		  
		  cout << "\nEnter employee salary: ";
		  cin >> salary;
		  cout << "\nEnter employee SSN: ";
		  cin >> SSN;
		  cout << "Enter employee hire date (mmddyyyy): ";
		  cin >> HireDate;
		  cout << "Enter employee\'s last review date: ";
		  cin >> ReviewDate;

                  //This is how we can copy a char array (string) without strcpy
                  for(int x = 0; x <20; x++) {
                      FirstName[x] = First[x]; 
                      LastName[x] = Last[x];
                  }
                  //For the last value to be copied we'll use strcpy
                  strcpy(JobDescription, Desc);

	     } //close else
	} //close function

        void DisplayEmployee() {

	     cout << endl;
	     cout << "**************************************************\n";
             cout << "* Information for employee " << GetEmpID() 
                  << ":                    *\n";
	     cout << "**************************************************\n";
	     cout << endl << endl;
	     cout << "Employee ID: " << GetEmpID() << endl;
             cout << "Department ID: " << GetDeptID() << endl;
             cout << "First Name: " << GetFirstName() << endl;
             cout << "Last Name: " << GetLastName() << endl;
             cout << "Job Description: " << GetJobDescription() << endl;
             cout << "Salary: " << GetSalary() << endl;
             cout << "SSN: " << GetSSN() << endl;
             cout << "Hire Date: " << GetHireDate() << endl;
             cout << "Review Date: " << GetReviewDate() << endl;
             cout << endl << endl;

	} //close function


        void Initialize() 
        {
             DeptID = 0; 
             salary = 0.0;
             SSN = 000000000;
             HireDate = 00000000;
             ReviewDate = 00000000;
             strcpy(FirstName, "No First Name Yet");
             strcpy(LastName, "No Last Name Yet");
             strcpy(JobDescription, "No Job Description Yet");
        }

    //Data members
    private:

       int EmpID;
       int DeptID;
       float salary;
       long SSN;
       long HireDate;
       long ReviewDate;
       char FirstName[20];
       char LastName[20];
       char JobDescription[40];

};  //close base class specification

//---------------------------------------------------------------------------------------------------------------------------

//Static member data must be defined outside the class specification
int Employee::PrimaryKey = 0;

//---------------------------------------------------------------------------------------------------------------------------

class Manager : public Employee 
{
   public:

       Manager() { cout << "\nNew Manager object created."; }
       ~Manager() { cout << "\nManager deleted"; }
   
        //Accessor methods
      int GetManID() { return ManID; }
      void SetManID(int ID) { ManID = ID; }

      double GetLogInTime() { return LogInTime; }
      void SetLogInTime(double logtime) { LogInTime = logtime; }
      char * GetPassWord() { return PassWord; }
      void SetPassWord(char * pass) { PassWord = pass; }

      char * GetResponsibilities() { return Responsibilities; }
      void SetResponsibilities(char * response) { Responsibilities = response; }
   
      void setDesc(char * des) { Desc = des; }
      char * getDesc() { return Desc; }
   //Data members
   private:

      int ManID;
      double LogInTime;
      char * PassWord;
      char * Responsibilities;
      char * Desc;
};

//---------------------------------------------------------------------------------------------------------------------------

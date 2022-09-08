//Sequential File Access  2 - Using ignore to sort data from a sequential access file - 2004 C. S. Germany

//Using ignore to sort data from a sequential access file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class EmpCodes
{
      public:
	EmpCodes()
	{
	    code   = ' ';
	    salary = 0;
	} 
	void readRecord(ifstream & InputFile)
	{
	     InputFile >> code;
	     InputFile.ignore(1);  //ignore the #, could have also set the delimiter
	     InputFile >> salary;
	     InputFile.ignore(1);  //ignore the endl or "\n"
	} 
	char getCode()  { return code; } 
	int getSalary() { return salary; }
       private:
	char code;
	int salary;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    EmpCodes codeSalary;
    char salaryCode = ' ';
    ifstream InputFil;
    InputFil.open("SalesData.txt", ios::in);
    if(InputFil.is_open())
	{
       cout << "Enter the code: ";
       cin >> salaryCode;
       codeSalary.readRecord(InputFil);
       while(!InputFil.eof() && toupper(salaryCode) != toupper(codeSalary.getCode()))
	   { 
		   codeSalary.readRecord(InputFil); 
	   }
       if(!InputFil.eof())
           cout << "Salary: " << codeSalary.getSalary() << endl;
       else
           cout << "Invalid code" << endl;
       InputFil.close();
    } //close if
    else
	 cout << "File was not opened." << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









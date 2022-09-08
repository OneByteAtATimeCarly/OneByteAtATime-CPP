//Vectors 2 - Example 2 - 2004 C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
      public:
         //Two overloaded constructors
	 Employee();
	 Employee(const string & name, const int SSN);
	 Employee(const Employee & rhs);  //Copy constructor
	 ~Employee();
	 void	SetName(const string & name);
	 string	GetName()	const;
	 void	SetSSN(const int SSN);
	 int	GetSSN() const;
         //Overloaded assignment operator  
	 Employee & operator=(const Employee & rhs);
      private:
	 string EmpName;
	 long SocialSecNum;
};

//---------------------------------------------------------------------------------------------------------------------------

//Two overloaded Employee constructor implementations
Employee::Employee()
: EmpName("New Employee"), SocialSecNum(666666666)
{ }

//---------------------------------------------------------------------------------------------------------------------------

Employee::Employee(const string & name, const int SSN)
: EmpName(name), SocialSecNum(SSN)
{ }

//---------------------------------------------------------------------------------------------------------------------------

//Copy constructor implementation
Employee::Employee(const Employee & rhs)
: EmpName(rhs.GetName()), SocialSecNum(rhs.GetSSN())
{}

//---------------------------------------------------------------------------------------------------------------------------

//Destructor implementation
Employee::~Employee()
{}


//---------------------------------------------------------------------------------------------------------------------------

//Accessor method definitions

//---------------------------------------------------------------------------------------------------------------------------

void Employee::SetName(const string & name)
{  EmpName = name;  }

//---------------------------------------------------------------------------------------------------------------------------

string Employee::GetName() const
{  return EmpName;  }

//---------------------------------------------------------------------------------------------------------------------------

void Employee::SetSSN(const int SSN)
{  SocialSecNum = SSN;  }

//---------------------------------------------------------------------------------------------------------------------------

int Employee::GetSSN() const
{  return SocialSecNum;  }

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded assignment operator definition
Employee & Employee::operator=(const Employee & rhs)
{
	EmpName = rhs.GetName();
	SocialSecNum = rhs.GetSSN();
	return *this;
}

//---------------------------------------------------------------------------------------------------------------------------

//Overload the ostream operator so that using it with an Employee object will display the object's SocialSecNum data member

ostream & operator<<(ostream & os, const Employee & rhs)
{
	os << rhs.GetName() << " has the social security number: " << rhs.GetSSN() << ".";
	return os;
}

//---------------------------------------------------------------------------------------------------------------------------

template<class T>
//Prototype for display vector properties function, needs to be a template since STL containers are implemented as such
void ShowVector(const vector<T>& v);    

//---------------------------------------------------------------------------------------------------------------------------

//Setup "TheCompany" to be a vector container of Employee objects
typedef vector<Employee> TheCompany;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
        //Create instances of Employee objects
	Employee GeorgeW("George W. Bush", 213459648);
	Employee JenniferLopez("Jennifer Lopez", 256489789);
	Employee MariahC("Mariah Carrey", 321569846);
	Employee DavidDuchovny("David Duchovny", 217985364);
        //Create an indefinite vector container of Employee objects called "SmallBusiness"
	TheCompany SmallBusiness;
	cout << "SmallBusiness:\n";
	ShowVector(SmallBusiness);
           //Create a vector container of Employee objects called "ACorporation" with 3 elements	
        TheCompany ACorporation(3);
	cout << "ACorporation(3):\n";
	ShowVector(ACorporation);
        //Store(Assign) the Employee objects to the vector container elements 
	ACorporation[0] = GeorgeW;
	ACorporation[1] = JenniferLopez;
	ACorporation[2] = MariahC;
	cout << "ACorporation(3) after assigning Employees:\n";
	ShowVector(ACorporation);
        //Though "ACorporation" was declared to have only 3 elements, we can use push_back to add a 4th
	ACorporation.push_back(DavidDuchovny);
	cout << "ACorporation() after added 4th Employee:\n";
	ShowVector(ACorporation);
        //Call accessor methods of the template class Employee object stored in vector element
	ACorporation[0].SetName("Bill Clinton");
	ACorporation[0].SetSSN(219645897);
	cout << "ACorporation() after Set\n:";
	ShowVector(ACorporation);
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

// Display vector properties

template<class T>
void ShowVector(const vector<T>& v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t" << (v.empty()? "empty": "not empty");
	cout << "\n";
	for(int i = 0; i < v.size(); ++i)
        {
            //Remember, we overloaded the << operator to display the SocialSecNum data member of an Employee object
	    cout << v[i] << "\n";
        }
	cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------------







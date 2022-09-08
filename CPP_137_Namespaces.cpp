//Namespaces - 2004 C. S. Germany

//Namespaces can be a useful tool in C++.  The provide additional scope to a program.  They help programmers avoid
//conflicts when incorporating more than one library into their projects.  Items declared within a namespace are "owned"
//by that namespace.  Once placed inside a namespace declaration, all items within the scope of that namespace have
//public visibility to each other.  Anything outside the namespace is not visible and must be fully qualified using scope
//resolution and the namespace's name.  Namespaces can partition the global namespace and reduce conflicts.

//The compiler can not check for name clashes across translation units such as object files, so the linker performs this
//function.  The linker will render the error message "Identifier" + namespace item,  when the same name has been defined
//in the same scope within translation units.  In other words, if we have two source files in a project, and we inadvertently
//define int Myinteger in both files, we will get an error when linking, since as the two files are merged, there can be only
//ONE definition of MyInteger, not two.  Other examples:

//          Two definitions in global scope
//          int MyInteger = 0;

//          int main() 
//          {
//              int MyInteger;
//              ::MyInteger = 10;  //scopes out of main() to global
//              return 0;
//          }


//Any name that has internal linkage can only be referred to within the translation unit (source or header file) in which it is declared.
//Any name that has external linkage can be referred by other translation units (other files).  Anything that is const has internal linkage
//by default.  Other variables are external by default.  You can explicitly declare a file to be externally linked by using the keyword
//extern.  Example:

//          Explicit external linkage
//          extern int MyInteger = 0;

//          int main() 
//          {
//              int MyInteger;
//              MyInteger = 10; 
//              return 0;
//          }	//Implicit external linkage

//          int MyInteger = 0;

//          int main() 
//          {
//              int MyInteger;
//              MyInteger = 10; 
//              return 0;
//          }


//We have explicitly called cout from the standard ANSI library using scope resolution: std::cout << "Explicit scope namespace call.";  
//the keyword static used to be used to limit variable scope, but namespaces are the preferred way of doing this now.

//To create a namespace, we use the keyword namespace followed by the namespace's name and enclose the scope/block of code referenced
//by that namespace with { }.  The following would place two blocks of code from two separate files into the same namespace, so that
//essentially, after they were linked, it would be as if they were written into one single block of code in one file:

//          int main() 
//          {
//             namespace MyFavoriteInteger
//             {
//                 int MyInteger;
//             }
//          
//             return 0;
//          }	

//-----------------------------------------------------------------------------

//          int main() 
//          {
//              namespace MyFavoriteInteger
//             {
//                 MyInteger = 10;
//             } 
//             return 0;
//          }

//It is preferred that we define namespace functions outside the namespace body.  To do this, we will have to resolve scope by "scoping into"
//the functions with "::".  We would use the name of the namespace we defined and placed the function prototype in, the scope resolution
//operator, "::", and then the function name.

//Namespaces can be nested within each other. All new members must be declared and prototypes inside the namespace, not outside.  Once they
//are, we can manipulate them with scope resolution.   Example:

//          namespace MonsterWorld 
//          {
//              //Function prototype/declaration
//              void MonsterFunction(Monster * Mpointer);
//          }	
//
//          void MonsterWorld::MonsterFunction(Monster * Mpointer)
//          {
//               Mpointer->Talk();
//               Mpointer->AttackPlayer;
//          }


//using directive - The using directive exposes all names declared in a namespace to be in the current scope.  They can be referred to without
//being qualified. Example:  using namespace EmployeeInfo;  This would bring all of the members of EmployeeInfo into scope.

//          namespace EmployeeInfo 
//          {
//              long SSN;
//              int EmpId;
//              char FirstName[20];
//          }	
//
//          void FunctionOne()
//          {
//               using namespace EmployeeInfo;
//               SSN = 756986359;      //o.k. - this is in scope
//               FirstName = "Carly";  //o.k. - this is in scope
//          }
//
//          EmpID = 11;  //error - this is OUTSIDE the SCOPE

//using declaration - The using declaration declares a specific member from a namespace to be in the current scope.  This provides a finer level
//of control.  The other members remain out of scope.  Example:

//          namespace EmployeeInfo 
//          {
//               long SSN;
//               int EmpId;
//               char FirstName[20];
//          }
//	
//          void FunctionOne() 
//          {
//               using EmployeeInfo::SSN;
//    
//               SSN = 756986359;  //o.k. - this is in scope
//               EmpID = 11;  //error - this is OUTSIDE the SCOPE
//          }

//In the example above, in order for EmpID to be accessed, it would have to be brought into scope with: using EmployeeInfo::EmpID; 
//We can also assign an alias to namespaces using the keyword namespace and the assignment operator.  Example:

//          namespace EI = EmployeeInfo;
//          EI::SSN = 256349875;

//Namespaces can be unnamed.  This might be done to protect and separate global data in one source file from global data in another. Example:

//          namespace
//          {
//              int MyAge = 34;
//          }

//STL - The STL is enclosed within the namespace "std".  Example:
//          using directive = using namespace std;
//          using declaration = using std::cout

//---------------------------------------------------------------------------------------------------------------------------

//Let's look at a namespace example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>

//---------------------------------------------------------------------------------------------------------------------------

namespace EmployeeData
{
    int Age = 34;
    int EmpID = 11;

    class Employee
    {
        public:
            Employee() ;
            ~Employee() ;
            void Validate();
            void DisplayEmpInfo();
	    long GetSSN() { return SSN; }
            float GetPayRate() { return payrate; }
			 
        private:
            static int Counter ;
            long SSN;
            double payrate;
    } ;
}

//---------------------------------------------------------------------------------------------------------------------------

//Must use namespace scope and class scope since its static
int EmployeeData::Employee::Counter = 0 ;

//---------------------------------------------------------------------------------------------------------------------------

//Define constructor and destuctor using namespace scope
EmployeeData::Employee::Employee() : SSN(256389456), payrate(7.52) { }
EmployeeData::Employee::~Employee() { }

//---------------------------------------------------------------------------------------------------------------------------

//Define functions using namespace scope
void EmployeeData::Employee::Validate()
{
    if(GetSSN() < 111111111)
		std::cout << "Invalid social." << std::endl;
    if(GetPayRate() < 6.55 || payrate > 21.555)
       std::cout << "Invalid pay rate." << std::endl;
}

//---------------------------------------------------------------------------------------------------------------------------

void EmployeeData::Employee::DisplayEmpInfo()
{
    std::cout << " SSN " << Employee::SSN ;
    std::cout << " Pay Rate: " << Employee::payrate << std::endl ;
}

//---------------------------------------------------------------------------------------------------------------------------

int main( )
{
    //Instantiate object using namespace scope
    EmployeeData::Employee TempEmp;
    TempEmp.Validate();
    TempEmp.DisplayEmpInfo();
    return 0 ;
}

//---------------------------------------------------------------------------------------------------------------------------










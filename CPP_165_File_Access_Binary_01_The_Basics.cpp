//Binary File Access  1 - The Basics - 2004 C. S. Germany

//Binary files - allow you to write an entire object with all of its data members to a file via pointers. We could do this with
//sequential files, provided our data could be stored in ASCII, but it would be a lot more work.  Instead of using the
//parameters ios::app or ios::in, we need to use ios::binary when opening a binary file for read or write
//operations.  The ios parameters can also be "or'd" together using ||, thus combining them.  Thus, we could open a
//binary file for appending with:  

//       ios::app||ios::binary  

//Rather than using the stream operators with binary files, we will use:

//write() - writes all the data at once of an entire data structure or object.  Syntax:  write((char*)&TheObject, sizeof TheObject);
//read()-  reads all the data at once of an entire data structure or object.    Syntax:  read((char*)&TheObject, sizeof TheObject));

//Both of the functions above take a pointer to a char for the first argument, and the number of chars to write for the second argument.
//This can be determined using the sizeof() function.  Since the first argument is a pointer to a char, the address of the object must
//be passed in by using the addressOf operator, &.   I created the Employee class below for some of my database projects. Let's see how
//an entire instance of the Employee class can be written to a file at once.

//In the code below, all we have to do is code some accessor methods and something to display the values of Employee data members.
//We could have placed the code for displaying all the data members into a member function, call it DisplayEmployeeInfo(), and
//simply called DisplayEmployeeInfo() each time we needed to view the contents of an object.  

//       1. Now it's time to get creative. To make the below program more useful, modify and enhance it by these criteria:
//       2. Put the whole program into a loop so it will keep running until it encounters a sentinel value
//       3. Create a dynamic array of Employee objects, so the program can search through them
//       4. Create search routines and methods to iterate through the Employee arrays and find data members
//       5. Allow the user to save multiple employee objects.
//       6. Instead of allowing the user to name each file, assign a primary, unique key to each object file.


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
   public:
      //Overloaded Constructors
      Employee() { cout << "Employee object with no parameters created.\n"; }

      Employee(int ID, long social, double rate, int ag, long ph, string first, string last):
      EmpID(ID),
      SSN(social),
      HourlyRate(rate),
      age(ag),
      Phone(ph),
      FirstName(first),
      LastName(last)
   
      {  cout << "Employee with parameters created!\n";  }

      ~Employee() { cout << "Employee object destroyed.\n"; }

      int GetEmpID() const { return EmpID; }
      void SetEmpID(int ID) { EmpID = ID; }

      long GetSSN()const { return SSN; }
      void SetSSN(long social) { SSN = social; }

      double GetRate() { return HourlyRate; }
      void SetRate(double rate) { HourlyRate = rate; }

      int GetAge() { return age; }
      void SetAge(int ag) { age = ag; }

      long GetPhone() { return Phone; }
      void SetPhone(long ph) { Phone = ph; }

      string GetFirst() { return FirstName; }
      void SetFirst(string first) { FirstName = first; }

      string GetLast() { return LastName; }
      void SetLast(string last) { LastName = last; }
     
   private:
      int EmpID;
      long SSN;
      double HourlyRate;
      int age;
      long Phone;
      string FirstName;
      string LastName;

};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    char FileName[80];
    cout << "Please enter the file name: ";
    cin >> FileName;
    //Open filename user typed for binary write
    ofstream OutputFile(FileName, ios::binary);
    if(!OutputFile)
    {
         cout << "Unable to open " << FileName << " for writing.\n";
         return(1);  //returning one means an error occurred and ends the program
    }

    Employee CGermany(11, 725652145, 12.55, 34, 7544312, "Carly", "Germany");
    OutputFile.write((char*) &CGermany, sizeof CGermany);
    OutputFile.close();

      //Open filename user typed for binary read
    ifstream InputFile(FileName, ios::binary);
    if(!InputFile)
    {
        cout << "Unable to open " << FileName << " for reading.\n";
        return(1);
    }

    Employee EmpObject;
    InputFile.read((char*) &EmpObject, sizeof EmpObject);
    cout << endl << endl;
    cout << "Employee ID: " << EmpObject.GetEmpID() << endl;
    cout << "First Name: " << EmpObject.GetFirst() << endl;
    cout << "Last Name: " << EmpObject.GetLast() << endl;
    cout << "Social Sec #: " << EmpObject.GetSSN() << endl;
    cout << "Age: " << EmpObject.GetAge() << endl;
    cout << "Hourly Rate: " << EmpObject.GetRate() << endl;
    cout << "Phone: " << EmpObject.GetPhone() << endl;
    cout << endl << endl;
    InputFile.close();
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









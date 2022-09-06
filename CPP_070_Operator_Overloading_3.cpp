//Operator Overloading - 3 - 2004 C. S. Germany
//Example 3

//Here we will start by writing the function Add().  It takes a Counter as its argument, adds the values, then returns a Counter object with the result.
//We might provide the default value 0 to the constructor declared here.  The Add() function is declared.  It takes a const Counter reference which is the
//number to add to the current object.  Since varOne and varTwo need to be initialized to a non-zero value, another constructor is created.  The default
//constructor initializes itsVal to 0.  The Add() function returns a Counter object which is the result to be assigned to the left side of the assignment
//statement.  At present, varOne is the object, varTwo is the parameter to the Add() function, and the result is assigned to varThree. To create varThree
//without having to initialize a value for it, the default constructor is required.


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short USHORT;

//---------------------------------------------------------------------------------------------------------------------------

class Counter
{
      public:
      Counter();
      Counter(USHORT initialValue);
      ~Counter(){}

      USHORT GetItsVal()const { return itsVal; }
      void SetItsVal(USHORT x) {itsVal = x; }
     
      //Takes a reference to a constant Counter object
      Counter Add(const Counter &);

      private:
      USHORT itsVal;
};

//---------------------------------------------------------------------------------------------------------------------------

//Counter constructor can take an argument
Counter::Counter(USHORT initialValue):itsVal(initialValue)
{ }

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter():itsVal(0)
{ }

//---------------------------------------------------------------------------------------------------------------------------

//Define the Add function
Counter Counter::Add(const Counter & rhs)
{
        return Counter(itsVal+ rhs.GetItsVal());
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Counter varOne(2), varTwo(4), varThree;

    varThree = varOne.Add(varTwo);

    cout << "varOne: " << varOne.GetItsVal()<< endl;
    cout << "varTwo: " << varTwo.GetItsVal() << endl;
    cout << "varThree: " << varThree.GetItsVal() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






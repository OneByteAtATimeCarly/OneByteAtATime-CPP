//Operator Overloading - 4 - 2004 C. S. Germany
//Example 4

//The Add() function in the previous example works, but its use is unnatural and cludgy. 
//Overloading the operator + would make for a more natural use of the Counter class.

//In this example, the overloaded operator + is declared.  The syntax is different in this case - it is more natural to say varThree = varOne + varTwo;
//than it is to say varThree = varOne.Add(varTwo);.  By overloading the "+" operator, we can add objects together as well as integers and floats.

//Operators on built-in types, like int, cannot be overloaded.   Only operators on user-defined types.  The precedence and the "arity" of the operator cannot be changed.
//The "arity" refers to whether it is "unary" or "binary".  Unfortunately, you cannot make new operators, so you cannot declare ** to be the "power of" operator.  Operator
//overloading is very abused and misused in C++ programming.  It can be dangerous to use "+" to concatenate a series of letters, or to use / to split a string.
//Operator overloading is a powerful tool, but it should be used cautiously.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short USHORT;

//---------------------------------------------------------------------------------------------------------------------------

class Counter
{
      public:
      Counter();
      Counter(ULONG initialValue);
      ~Counter(){}

      ULONG GetItsVal()const { return itsVal; }
      void SetItsVal(ULONG x) {itsVal = x; }

     
      Counter operator+ (const Counter &);

      private:
      ULONG itsVal;
};

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter(ULONG initialValue):
itsVal(initialValue)
{}

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter():
itsVal(0)
{}

//---------------------------------------------------------------------------------------------------------------------------

//Define overloaded addition operator
//Adds the "itsVal" data member of the object passed in to the other "itsVal" data member
Counter Counter::operator+ (const Counter & rhs)
{
        return Counter(itsVal + rhs.GetItsVal());
}

//-------------------------------------------------------------------------------------------------------------------

int main()
{
    Counter varOne(2), varTwo(4), varThree;

    //Add 2 objects together and assign it to the third object
    varThree = varOne + varTwo;     //looks like plain math but really operator overloading!

    cout << "varOne: " << varOne.GetItsVal()<< endl;
    cout << "varTwo: " << varTwo.GetItsVal() << endl;
    cout << "varThree: " << varThree.GetItsVal() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






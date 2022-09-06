//Operator Overloading - 6 - Dereferencing the THIS Pointer - 2004 C. S. Germany
//Example 6

//Another way is to check this is to dereference the "this" pointer and see if the 2 objects are the same, possessing the same address.
//Example: if (*this == rhs). The equality operator (==) can be overloaded, allowing you to determine for yourself what it means for your objects to be equal.
//Now that is power and freedom!  Let's pose a question: What happens if you try to assign a variable of a built in type (such as int or unsigned short)
//to an object of a user defined class?

//This implements an important change, the constructor is overloaded to take an int.  This effectively creates a Counter object out of an int.  The compiler is able to
//call the constructor that takes an int as its argument.  If you try to reverse it, however, you will get a compile time error.  The compiler knows how to create a
//Counter out of an int, but it does not know how to reverse the process and create an int out of a Counter. 

//For this, C++ provides conversion operators that can be added to your class.  They allow your class to specify how to do implicit conversions to built-in types.
//Conversion operators do not specify a return value, even though they do return a "converted" value. 

//In this example, a conversion operator is declared by overloading the second constructor - It has no return value.  The compiler has no idea how to add the user-defined data type //"Counter" to other Counter objects.  So, operator "+" is overloaded, so that when it is used to add Counter objects, it will in fact add the values of their "itsVal" data members //together.  We may now return the value of itsVal, a data member of a Counter object,  converted to an int.  Now, relatively speaking, the compiler can turn int's into Counter objects //and Counter objects into int's.  They can be assigned to each other freely.  This is because the overloaded operator + allows us to add the right and left objects together by adding //their integer data members together.  The conversion operator then allows us to assign the integer result of the addition to the third object's int data member.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned long ULONG;

//---------------------------------------------------------------------------------------------------------------------------

class Counter
{
      public:
      //2 overloaded constructors.  The second is our conversion operator.
      Counter();
      Counter(ULONG initialValue);
      ~Counter(){}

      //Accessor methods
      ULONG GetItsVal()const { return itsVal; }
      void SetItsVal(ULONG x) {itsVal = x; }

        //Overload operator + - takes a reference to a const Counter object
      Counter operator+ (const Counter &);

      private:
      ULONG itsVal;
};

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter():itsVal(0)
{ }

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter(ULONG initialValue):itsVal(initialValue)
{ }

//---------------------------------------------------------------------------------------------------------------------------

//Overload operator + to add "itsVal" data member when adding objects
Counter Counter::operator+ (const Counter & rhs)
{
        return Counter(itsVal + rhs.GetItsVal());
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Counter CounterOne(2), CounterTwo(4), CounterThree;

    //The statement below uses both our overloaded operator + and our conversion operator.
    //The overloaded operator + allows us to add the right and left objects together by adding their data members.
    //The conversion operator allows us to assign that integer result to the third object's int data member.
    CounterThree = CounterOne + CounterTwo;

    cout << "CounterOne: " << CounterOne.GetItsVal()<< endl;
    cout << "CounterTwo: " << CounterTwo.GetItsVal() << endl;
    cout << "CounterThree: " << CounterThree.GetItsVal() << endl;

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------










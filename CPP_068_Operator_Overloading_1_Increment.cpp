//Operator Overloading - 1 - Basics - Overloading C++'s INCREMENT Operator - 2004 C. S. Germany
//Example 1

//Operator overloading - C++'s built in types (int, real, char, etc.) and built in operators (multiplication, addition, etc.) can be added to your own classes
//and overloaded to do what you want. You use the keyword "operator" when doing this.

//Example: A "Counter" object will be created and used in loops, incrementing, decrementing, and tracking.
//This counter object can not be incremented or manipulated unless you use operator overloading to define this functionality.

//In the example below, we will overload C++'s INCREMENT operator to increment our own classes of objects rather than numbers

//The value returned is a Counter reference, avoiding the creation of an extra temporary object.  It is a const reference because the value should not be changed by
//the function using Counter.  If the Counter allocated memory, it would be important to override the copy constructor, but in this case the default copy constructor
//works fine.  When overloading these operators, remember the subtleties between postfix vs. prefix:

//Prefix - increment and then fetch the value.

//Postfix - fetch and then increment the value (returns value that existed BEFORE it was incremented). 
//You must create a temporary object to hold the old value while you increment it to the new value.  You return the temporary, old value because
//the postfix operator asks for the original value, not the incremented one.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short USHORT;

//---------------------------------------------------------------------------------------------------------------------------

class Counter
{
      public:
      Counter();
      ~Counter(){}

      USHORT GetItsVal()const { return itsVal; }

      void SetItsVal(USHORT x) {itsVal = x; }
      void Increment() { ++itsVal; }
      const Counter &operator++();    //overloads the increment operator

      private:
      USHORT itsVal;
};

//---------------------------------------------------------------------------------------------------------------------------

//Defines constructor outside of class
Counter::Counter():
itsVal(0)
{};

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded increment operator - we teach it to increment objects. It returns a reference
//to a const Counter object. REFERENCE used to avoid creation of extra temporary object.
const Counter &Counter::operator++()
{
      ++itsVal;
      return *this;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Counter SomeCounterObject;
    cout << "The value of SomeCounterObject is "
         << SomeCounterObject.GetItsVal() << endl;

    SomeCounterObject.Increment();

    cout << "The value of SomeCounterObject is "
         << SomeCounterObject.GetItsVal() << endl;

    ++SomeCounterObject;

    cout << "The value of SomeCounterObject is "
         << SomeCounterObject.GetItsVal() << endl;

    Counter AnotherCounterObject = ++SomeCounterObject;

    cout << "The value of AnotherCounterObject: "
         << AnotherCounterObject.GetItsVal();

    cout << " and SomeCounterObject: "
         << SomeCounterObject.GetItsVal() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


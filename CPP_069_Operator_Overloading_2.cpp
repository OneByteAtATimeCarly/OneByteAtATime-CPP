//Operator Overloading - 2 - 2004 C. S. Germany
//Example 2

//If x is an object, and we seek to overload the postfix increment operator, we must teach the compiler how to do this.  We would need to code our function stash away the
//original value "5" in a temporary object, increment x's value to "6", and then return the temporary object to assign its value to a.  Because the temporary object is being
//returned, it must be returned by value and not reference. This is because the temporary will go out of scope as soon as the function returns and if there were a reference,
//it would be left aliasing nothing.

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

      const Counter &operator++();      //prefix
      const Counter operator++(int);    //postfix

      private:
      USHORT itsVal;
};

//---------------------------------------------------------------------------------------------------------------------------

Counter::Counter():itsVal(0)
{}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded prefix operator
const Counter &Counter::operator++()
{
     ++itsVal;
     return *this;
}
//---------------------------------------------------------------------------------------------------------------------------

//Overloaded postfix operator
const Counter Counter::operator++(int)
{
       //Create a Counter object that takes a pointer to the object itself calling this function
     Counter temp(*this);   
     ++itsVal;
     return temp;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Counter ACounterObject;

    cout << "The value of ACounterObject is "
         << ACounterObject.GetItsVal() << endl;

    ACounterObject++;     //calls overloaded postfix increment operator

    cout << "The value of ACounterObject is "
         << ACounterObject.GetItsVal() << endl;

    ++ACounterObject;     //calls overloaded prefix increment operator

    cout << "The value of ACounterObject is "
         << ACounterObject.GetItsVal() << endl;

    Counter AnotherCounterObject = ++ACounterObject;

    cout << "The value of AnotherCounterObject: "
         << AnotherCounterObject.GetItsVal();

    cout << " and ACounterObject: "
         << ACounterObject.GetItsVal() << endl;

    AnotherCounterObject = ACounterObject++;

    cout << "The value of AnotherCounterObject: "
         << AnotherCounterObject.GetItsVal();

    cout << " and ACounterObject: "
         << ACounterObject.GetItsVal() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




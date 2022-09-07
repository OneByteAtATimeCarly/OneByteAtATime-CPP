//Exceptions 1 - The Basics - 2004 C. S. Germany

//Exceptions are used for handling errors in C++.  An exception consists of a block of code that is being tested or "tried",
//and a subsequent block of code to handle the situation if the previous block of code fails the test.  Testing code is
//known as "trying" it.  Sending a message to the "catch" block of code when the code being tried fails the test is known
//as "throwing an exception".  When the "catch" block receives the error message for processing, it is referred to as
//"catching the exception".  We can not anticipate every user error and unusual circumstance, but we should try to anticipate as many as possible.
//This is known as "bulletproofing" code.  

//Bulletproofing attempts to create a program that can handle almost anything that comes up at runtime, from bizarre user input to running out of memory or hacks.
//It involves a lot of validation and checking user input, and using a few try and catch blocks.  Before using deciding where to place our try and catch blocks,
//we should identify some of the most common errors we may encounter.  Discrete bugs to look out for

//   Poor logic - The program does what you ask, but you didn't think through algorithms properly.
//   Syntactic errors - You used wrong idioms, keywords, functions, or structures are used.
//   Logic errors - The program will compile an run, but it does not behave as expected.
//   Subtle bugs - Bugs don't show up at first, but arise later in uses of the program.
//   Unnecessary fragility - The program works fine if user enters what is expected, but crashes if user does not.
//   It does not fail gracefully - Data is lost or unfriendly error message are displayed.
//   Hardware problems - The program may crash if it runs out of memory, or media disconnects or ninternet service interrupted.

//Exception - An exception is an object used to transmit information about a problem. The object that is passed from the area of code
//where problem occurs to part of code that is going to handle the problem.  The basic logic behind throwing exceptions is:

//The allocation of resources (such as memory or locking of a file) is done at a very low level in the program.

//The logic of what to do when an operation fails (memory cannot be allocated, file cannot be locked) is situated at a higher level in
//the program with the code for interacting with the user.

//Exceptions then provide an express path from the low level code that allocates resources to the high level code that can handle the error condition.

//Try blocks - A block of code where an exception is thrown, set of statements that begin with keyword "try", are followed by an opening brace and
//end with a closing brace.  They surround areas of code that have problems. 

//Catch blocks - A block where exceptions are handled, set of statements that begin with keyword "catch" followed by exception type in parentheses,
//followed by opening brace and ending with closing brace. They handle the exceptions thrown by try blocks. 

//Handling errors - When an exception is thrown (raised), control transfers from the try block to the catch block immediately following it.

//In the example below, an Array class object is created with 10 passed in as the parameter.  This value, passed in to the constructor will create a
//new array of integers on the heap consisting of 10 elements.  Later in main(), as the loop iterates, an exception is thrown when the Array object
//exceeds its bounds.  The int array created on the heap only has 10 elements, and yet the loop wants to iterate 1000 times.  After this error triggers
//the exception to be thrown, the exception is caught by the catch block.  The offset operators throw the class instance of YouHaveExceededArrayBoundaries
//when the client of the class attempts to access data outside the boundaries of the array.   The error class itself can be merely an empty class.  When
//trying to determine try block locations, look to where you allocate memory or use resources. Other things to look for are out of bounds errors, illegal
//input, and so forth. 

//How catching exceptions works - When an exception is thrown, the call stack is examined.  The call stack is a list of function calls created when one
//part of the program invokes another function. The exception is passed up the call stack to each enclosing block.  As the stack is unwound, the destructors
//are invoked and the objects are destroyed one by one.  Unless specified by a class name when being thrown, the catch block directly after a try block will
//be executed when an exception is thrown.  You can declare an empty class for your exceptions.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
const int DefaultSize = 10;

//---------------------------------------------------------------------------------------------------------------------------

class Array
{
      public:
      //Constructors
      Array(int itsSize = DefaultSize);
      Array(const Array & rhs);
      ~Array() { delete [] pType;}

      //Overloaded C++ operators
      Array& operator=(const Array &);
      int & operator[](int offSet);
      const int & operator[](int offSet) const;

      //Accessors
      int GetitsSize() const { return itsSize; }

      //Friend function - MUST be defined outside class.  Overloads DataStream operator.
      friend ostream & operator<<(ostream&, const Array&);

      private:
      int *pType;
      int itsSize;
};

//---------------------------------------------------------------------------------------------------------------------------

Array::Array(int size):itsSize(size)
{
      pType = new int[size];

      for(int i = 0; i<size; i++)
          pType[i] = 0;
}

//---------------------------------------------------------------------------------------------------------------------------

Array & Array::operator=(const Array & rhs)
{
        if(this == &rhs)
           return *this;

        delete [] pType;

        itsSize = rhs.GetitsSize();
        pType = new int[itsSize];

        for(int i = 0; i<itsSize; i++)
        pType[i] = rhs[i];
        return *this;
}

//---------------------------------------------------------------------------------------------------------------------------

Array::Array(const Array & rhs)
{
       itsSize = rhs.GetitsSize();
       pType = new int[itsSize];
       for(int i = 0; i<itsSize; i++)
       pType[i] = rhs[i];
}

//---------------------------------------------------------------------------------------------------------------------------

int & Array::operator[](int offSet)
{
     int size = GetitsSize();

     if(offSet >= 0 && offSet < GetitsSize())
        return pType[offSet];

     throw YouHaveExceededArrayBoundaries();

     return pType[offSet];
}

//---------------------------------------------------------------------------------------------------------------------------

const int & Array::operator[](int offSet) const
{
      int mysize = GetitsSize();

      if(offSet >= 0 && offSet < GetitsSize())
         return pType[offSet];

      throw YouHaveExceededArrayBoundaries();

      return pType[offSet];
}

//---------------------------------------------------------------------------------------------------------------------------

ostream & operator<<(ostream & output, const Array & theArray)
{
        for(int i = 0; i<theArray.GetitsSize(); i++)
             output << "[" << i << "] " << theArray[i] << endl;

        return output;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Array intArray(10);

    try
    {
        for(int j = 0; j < 1000; j++)
        {
            intArray[j] = j;
            cout << "intArray[" << j << "] okay..." << endl;
        }
    }


    catch(YouHaveExceededArrayBoundaries)
    {
       cout << "Unable to process your input!\n";
    }

    cout << "Done.\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








//Exceptions 2 - Declaring and Defining multiple exception classes for throwing and catching different kinds of errors - 2004 C. S. Germany

//Declaring and Defining multiple exception classes for throwing and catching different kinds of errors

//Here begin to see the power of try and catch blocks.  Throwing Exceptions can help us "bulletproof" our code.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
const int DefaultSize = 10;

//---------------------------------------------------------------------------------------------------------------------------

/Define the exception classes
class YouHaveExceededArrayBoundaries {  };  //Empty class

//Base error class
class SubScriptSize
{
      public:
      SubScriptSize(int size):itsSize(size) {}
      ~SubScriptSize(){}

      virtual int GetSize() { return itsSize; }
      virtual void PrintError() 
      { cout << "Size error. Received: " << itsSize << endl; }

      protected:
      int itsSize;
};

//---------------------------------------------------------------------------------------------------------------------------

class SubTooBig : public SubScriptSize
{
      public:
      SubTooBig(int size):SubScriptSize(size){}

      virtual void PrintError() 
      { cout << "Too big! Received: ";
        cout << SubScriptSize::itsSize << endl; }
};

//---------------------------------------------------------------------------------------------------------------------------

class SubTooSmall : public SubScriptSize
{
      public:
      SubTooSmall(int size):SubScriptSize(size){}

      virtual void PrintError() 
      { cout << "Too small! Received: ";
        cout << SubScriptSize::itsSize << endl; }
};

//---------------------------------------------------------------------------------------------------------------------------

class SubZero : public SubTooSmall
{
      public:
      SubZero(int size):SubTooSmall(size){}

      virtual void PrintError() 
      { cout << "Zero!!. Received: ";
        cout << SubScriptSize::itsSize << endl; }
      };

//---------------------------------------------------------------------------------------------------------------------------

class SubNegative : public SubScriptSize
{
      public:
      SubNegative(int size):SubScriptSize(size){}

      virtual void PrintError() 
      { cout << "Negative! Received: ";
        cout << SubScriptSize::itsSize << endl; }
};

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
    try
    {
       int choice;
       cout << "Enter the array size: ";
       cin >> choice;

       Array intArray(choice);
      
       for(int j = 0; j< 100; j++)
       {
           intArray[j] = j;
           cout << "intArray[" << j << "] okay..." << endl;
       }
    }

    catch(YouHaveExceededArrayBoundaries)
    {
        cout << "Unable to process your input!\n";
    }

    catch(SubScriptSize& theException)
    {
       theException.PrintError();
    }

    catch(...)
    {
       cout << "Oh dear, something is terribly wrong!" << endl;
    }

    cout << "Done.\n";

    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------








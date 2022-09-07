//Static Data 3 - 2004 C. S. Germany

//Containment - Containment refers to the member data of one class that includes within it the objects of another class.
//The outer class is said to  CONTAIN the inner class, hence the name.  An employee class might contain string objects,
//and these would be instance of another class, the String class.

//---------------------------------------------------------------------------------------------------------------------------

//Containment, Operator overloading and a peek inside the string class
#include <iostream.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------------------------

class String
{
      public:
      //3 overloaded constructors
      String();
      String(const char *const);
      String(const String &);

      //Destructor
      ~String();

      //Overloaded C++ operators
      char & operator[](int offset);
      char operator[](int offset) const;
      String operator+(const String&);
      void operator+=(const String&);
      String & operator= (const String &);

        //Here we overload the datastream operator (<<) to work with cout. It returns an ostream object.
        //We must use a friend function declared outside the class.
      friend ostream & operator<<(ostream & theStream, String & theString);


      //General accessors
      int GetLen()const { return itsLen; }
      const char * GetString() const { return itsString; }
     
        //Static member data - must be defined outside the class.
      static int ConstructorCount;

      private:
      String (int); // private constructor
      char * itsString;
      int itsLen;
};

//---------------------------------------------------------------------------------------------------------------------------

//1st overloaded constructor definition. This default constructor creates string of 0 bytes.
String::String()
{
        itsString = new char[1];
        itsString[0] = '\0';
        itsLen=0;

           cout << "\tDefault string constructor.\n";
        ConstructorCount++;
}

//---------------------------------------------------------------------------------------------------------------------------

//2nd overloaded constructor. It is a private (helper) constructor, used only by class methods
//for creating a newstring of the required size. It is null filled.
String::String(int len)
{
        itsString = new char[len+1];
        int i;

        for(i = 0; i<=len; i++)
            itsString[i] = '\0';

        itsLen=len;

          cout << "\tString(int) constructor\n";
        ConstructorCount++;
}

//---------------------------------------------------------------------------------------------------------------------------

//3rd Overloaded Constructor
String::String(const char * const cString)
{
        itsLen = strlen(cString);
        itsString = new char[itsLen+1];
        int i;

        for(i = 0; i<itsLen; i++)
            itsString[i] = cString[i];

        itsString[itsLen]='\0';

               cout << "\tString(char*) constructor\n";
        ConstructorCount++;
}

//---------------------------------------------------------------------------------------------------------------------------

//Copy constructor
String::String (const String & rhs)
{
        itsLen=rhs.GetLen();
        itsString = new char[itsLen+1];
        int i;

        //Copy the char's one by one from one array to the next.
        for( i = 0; i<itsLen;i++)
             itsString[i] = rhs[i];

        itsString[itsLen] = '\0';
          
        cout << "\tString(String&) constructor\n";
        ConstructorCount++;
}

//---------------------------------------------------------------------------------------------------------------------------

//Destructor
String::~String ()
{
        delete [] itsString;  //delete the entire array of char
        itsLen = 0;
       
        cout << "\tString destructor\n";
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator equals, frees existing memory, then copies string and size.
String & String::operator=(const String & rhs)
{
         if(this == &rhs)
            return *this;

         delete [] itsString;

         itsLen=rhs.GetLen();
         itsString = new char[itsLen+1];
         int i;

         for(i = 0; i<itsLen;i++)
             itsString[i] = rhs[i];

         itsString[itsLen] = '\0';

         return *this;

         cout << "\tString operator=\n";
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator non-constant offset, returns a reference to a character so it can be changed.
char & String::operator[](int offset)
{
       if (offset > itsLen)
           return itsString[itsLen-1];
       else
           return itsString[offset];
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator constant offset, for use with const objects. (see copy constructor)
char String::operator[](int offset) const
{
     if(offset > itsLen)
         return itsString[itsLen-1];
     else
         return itsString[offset];
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator +, creates a new string by adding current string to rhs.
String String::operator+(const String & rhs)
{
       int totalLen = itsLen + rhs.GetLen();
       int i,j;
       String temp(totalLen);

       for(i = 0; i<itsLen; i++)
           temp[i] = itsString[i];

       for(j = 0; j<rhs.GetLen(); j++, i++)
           temp[i] = rhs[j];

       temp[totalLen]='\0';

       return temp;
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator +=,changes current string, returns nothing.
void String::operator+=(const String& rhs)
{
     int rhsLen = rhs.GetLen();
     int totalLen = itsLen + rhsLen;
     int i,j;

     String temp(totalLen);

     for(i = 0; i<itsLen; i++)
         temp[i] = itsString[i];

     for(j = 0; j<rhs.GetLen(); j++, i++)
         temp[i] = rhs[i-itsLen];

     temp[totalLen]='\0';

     *this = temp;
}

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded C++ operator << - declared as a friend function above inside the class.
//Returns an object of type ostream.
ostream & operator<< ( ostream & theStream, String & theString)
{
          theStream << theString.itsString;
          return theStream;
}

//---------------------------------------------------------------------------------------------------------------------------

//ConstructorCount is static, so it must be defined here outside the class.
int String::ConstructorCount = 0;

//---------------------------------------------------------------------------------------------------------------------------

void main()  
{

     String string1;
     String string2;

     string1 = "Those slick NSA G-men. They\'re always watching us!";

     string2 = string1;

     cout << endl << endl;
     cout << "The contents of string1 are:\n" << string1;
     cout << endl << endl;
     cout << "The contents of string2 are:\n" << string2;
     cout << endl << endl;

}

//---------------------------------------------------------------------------------------------------------------------------





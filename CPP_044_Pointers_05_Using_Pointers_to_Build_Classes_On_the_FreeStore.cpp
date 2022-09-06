//Pointers - 5 - Using the NEW Operator and Pointers to build Class Objects on the Free Store - 2004 C. S. Germany

//You can create a pointer to any object. Pointers work for classes and user-defined data types as well as they work for built-in data types.
//If you declare an object of type Cat, you can declare a pointer to that class and instantiate a Cat object on the free store just as you
//can make one on the stack.   Syntax:    Cat  *KittyPointer  =  new Cat;

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Cat  { 

        public: 
        Cat(); 
        ~Cat(); 

       private: 
       int itsAge; 
}; 
  
//---------------------------------------------------------------------------------------------------------------------------

//Define Cat constructor
Cat::Cat() 
{ 
       cout << "Constructor called. A kitty is created!\n"; 
       itsAge = 1; 
} 

//---------------------------------------------------------------------------------------------------------------------------

//Define Cat destructor  
Cat::~Cat() 
{ 
       cout << "Destructor called.  Alas, poor kitty . . .\n"; 
} 
  
//-----------------------------------------------------------------------------------------------------------

int main()  {
 
     cout << "Creating a local stack Cat, calling him Felix...\n";
 
     Cat Felix; 

     cout << "\n\nCreating a Cat on the heap and pointing to it with:\n";
     cout << "Cat *KittyPointer = new Cat...\n"; 

     Cat *KittyPointer = new Cat; 

     cout << "\n\ndelete KittyPointer...\n"; 

     delete KittyPointer;

     //Assign to NULL to be safe
     KittyPointer = 0; 

     cout << "\n\nExiting, observe Felix's untimely demise...\n";

     return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------




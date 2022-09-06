//Pointers - 8 - The THIS Pointer - 2004 C. S. Germany

//The "this" pointer - Every class member function has a hidden parameter. The "this" pointer points to the individual object.  In each call for SetAge() and GetAge(),
//the "this" pointer for the object is included as a hidden parameter.  It points to the individual object whose method has been invoked. Usually "this" is not needed.
//Occasionally you need to access the object itself (perhaps to return a pointer to the current object).  You don't need to use "this" to access member variables of an
//object from within methods of that object. You may explicitly call it.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//-----------------------------------------------------------------------------------------------------------

class Square  { 

        public: 
        Square(); 
        ~Square(); 

       void SetLength(int length) { this->itsLength = length; } 
       int GetLength() const { return this->itsLength; } 
  
       void SetWidth(int width) { itsWidth = width; } 
       int GetWidth() const { return itsWidth; } 
  
       private: 
       int itsLength; 
       int itsWidth; 
}; 
  
//--------------------------------------------------------------------------------------------------------------------

//Define constructor outside of class specification
Square::Square() { 
            
        itsWidth = 100; 
        itsLength = 100; 
} 

//--------------------------------------------------------------------------------------------------------------------

//Define destructor
Square::~Square() 
{} 

//--------------------------------------------------------------------------------------------------------------------
   
int main()  { 
  
     Square ASquare; 
     cout << "ASquare is " << ASquare.GetLength() << " feet long.\n"; 
     cout << "ASquare is " << ASquare.GetWidth() << " feet wide.\n"; 
     
     ASquare.SetLength(200); 
     ASquare.SetWidth(200); 

     cout << "ASquare is " << ASquare.GetLength()<< " feet long.\n"; 
     cout << "ASquare is " << ASquare.GetWidth()<< " feet wide.\n"; 
     
    return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------





//Pointers - 9 - Pointers to Constant Objects - 2004 C. S. Germany

//When a function is declared as constant the compiler flags as an error any attempt to change data in the object from within that function.
//If you declare a pointer to be a const object, the only methods you can call with that pointer are const methods.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//-----------------------------------------------------------------------------------------------------------

class Rectangle { 

       public: 
       Rectangle(); 
       ~Rectangle(); 
   
       void SetLength(int length) { itsLength = length; } 
       int GetLength() const { return itsLength; } 
  
       void SetWidth(int width) { itsWidth = width; } 
       int GetWidth() const { return itsWidth; } 
  
       private: 
       int itsLength; 
       int itsWidth; 
}; 

//-----------------------------------------------------------------------------------------------------------
  
Rectangle::Rectangle():itsWidth(5),itsLength(10) 
{ }
 
//-----------------------------------------------------------------------------------------------------------
  
Rectangle::~Rectangle() 
{} 

//--------------------------------------------------------------------------------------------------------------------
     
int main() 
{ 
     Rectangle *RectanglePointer = new Rectangle;
 
     //Points to a constant rectangle - can't change value
     const Rectangle *ConstantRectangle = new Rectangle;
 
       //Pointer is constant, can't reassign
     Rectangle * const ConstantPointer = new Rectangle; 
  

     cout << "RectanglePointer width: " << RectanglePointer->GetWidth() << " feet\n"; 
     cout << "ConstantRectangle width: " ; 

     cout << ConstantRectangle->GetWidth() << " feet\n"; 
     cout << "ConstantPointer width: " << ConstantPointer->GetWidth() << " feet\n"; 
  
     RectanglePointer->SetWidth(10); 
     // ConstantRectangle->SetWidth(10);  would be an error

     ConstantPointer->SetWidth(10); 
  
     cout << "RectanglePointer width: " << RectanglePointer->GetWidth() << " feet\n";
 
     cout << "ConstantRectangle width: "; 
     cout << ConstantRectangle->GetWidth() << " feet\n";
 
     cout << "ConstantPointer width: " << ConstantPointer->GetWidth() << " feet\n"; 
     
     return 0; 
} 

//-----------------------------------------------------------------------------------------------------------







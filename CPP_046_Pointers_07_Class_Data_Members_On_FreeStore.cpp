//Pointers - 7 - Declaring Class Data Members on the Free Store - 2004 C. S. Germany

//One or more of the data members of a class can be a pointer to an object on the free store.  The memory can be allocated in the class constructor or in one of
//its methods and it can be deleted in its destructor.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//-----------------------------------------------------------------------------------------------------------

class Monster  { 

       public: 
       Monster(); 
      ~Monster();
 
      int GetStrength() const { return *itsStrength; } 
      void SetStrength(int strength) { *itsStrength = strength; } 
  
      int GetWeight() const { return *itsWeight; } 
      void SetWeight (int weight) { *itsWeight = weight; } 
  
      private: 
      int *itsStrength; 
      int *itsWeight; 
}; 
  
//--------------------------------------------------------------------------------------------------------------------

//Define Monster constructor outside of class
Monster::Monster() 
{ 
      itsStrength = new int(200);   //create new int on heap with value of 200, then point to it
      itsWeight = new int(5000);    //create new int on heap with value of 5000, then point to it
} 

//--------------------------------------------------------------------------------------------------------------------
  
//Let destructor clean up the heap memory we allocated for the object's data member pointers
Monster::~Monster() 
{ 
      delete itsStrength; 
      delete itsWeight; 
} 

//--------------------------------------------------------------------------------------------------------------------
 
int main()  {
 
     Monster *Godzilla = new Monster; 
     cout << "Godzilla is of strength: " << Godzilla->GetStrength() << ".\n"; 

     Godzilla->SetStrength(500); 

     cout << "Godzilla weighs " << Godzilla->GetWeight() << " kilograms!\n"; 
     cout << "Godzilla is eating Tokyo!\n";

    Godzilla->SetWeight(50000);
    cout << "He now weighs " << Godzilla->GetWeight() << "kilograms!"; 
    
    delete Godzilla; 

    return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------





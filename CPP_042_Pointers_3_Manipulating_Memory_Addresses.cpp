//Pointers - 3 - Manipulating Memory Addresses - 2004 C. S. Germany

//Pointers enable you to manipulate addresses without ever knowing their real values.
//When you assign the address of a variable to a pointer it has the address of that variable as its value:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short int USHORT; 

//---------------------------------------------------------------------------------------------------------------------------

int main() 
{ 
     unsigned short int MyAge = 34;
     unsigned short int YourAge = 21;

      //Declare pointer and assign it to address of MyAge 
     unsigned short int *AgePointer = &MyAge;  
  
     cout << "MyAge:\t" << MyAge << "\tYourAge:\t" << YourAge << "\n"; 
     cout << "&MyAge:\t" << &MyAge << "\t&YourAge:\t" << &YourAge <<"\n"; 
  
     cout << "AgePointer:\t" << AgePointer << "\n"; 
     cout << "*AgePointer:\t" << *AgePointer << "\n"; 
  
     //Reassign the pointer to another variable's address 
     AgePointer = &YourAge;   
  
     cout << "MyAge:\t" << MyAge << "\tYourAge:\t" << YourAge << "\n"; 
     cout << "&MyAge:\t" << &MyAge << "\t&YourAge:\t" << &YourAge <<"\n"; 
  
     cout << "AgePointer:\t" << AgePointer << "\n"; 
     cout << "*AgePointer:\t" << *AgePointer << "\n"; 
  
     cout << "&AgePointer:\t" << &AgePointer << "\n"; 

     return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------


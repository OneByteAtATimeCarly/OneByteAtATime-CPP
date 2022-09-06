//Pointers - 2 - Declaring and Dereferencing - 2004 C. S. Germany

//To declare a pointer, place an * before the variable name.   Example:   int *AgePointer = 0;
//The indirection operator "*" means "the value stored at"
//It is also called the dereference operator when it is used the second time.
//Pointers enable you to manipulate addresses without ever knowing their real values.
//When you assign the address of a variable to a pointer it has the address of that variable as its value:
//Indirection - Indirection refers to accessing the value at the address held by a pointer,  the pointer provides an indirect way to get a value held at an address.
//This allows passing by reference rather than value.  We can avoid making an extra copy of the object.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short int USHORT; 

//---------------------------------------------------------------------------------------------------------------------------

void Some_Examples()
{
     unsigned short int HerAge = 25;            //make variable
     unsigned short int *AgePointer = 0;        //make pointer 
     AgePointer = &HerAge;                      //assign AgePointer's address to HerAge 
     unsigned short int *AgePointer = &HerAge;  //make pointer and assign in same step

     unsigned short int HerAge = 25;           //make variable
     unsigned short int *AgePointer = 0;       //make pointer
     AgePointer = &HerAge;                     //assigns pointer to point to address of HerAge variable

     unsigned short int YourAge;
     YourAge = *AgePointer;                //copies value of HerAge to YourAge
}

//---------------------------------------------------------------------------------------------------------------------------

int main()   { 

     USHORT MyAge;                            //a variable 
     USHORT * AgePointer = 0;                 //a pointer   
     MyAge = 5; 
     
     cout << "MyAge: " << MyAge << "\n"; 

     AgePointer = &MyAge;                     //assign address of MyAge to AgePointer 

     cout << "*AgePointer: " << *AgePointer << "\n\n";    //dereference the pointer
     cout << "*AgePointer = 7\n"; 

     *AgePointer = 7;                         //sets MyAge to 7 

     cout << "*AgePointer: " << *AgePointer << "\n"; 
     cout << "MyAge: " << MyAge << "\n\n"; 
     cout << "MyAge = 9\n"; 

     MyAge = 9; 

     cout << "MyAge: " << MyAge << "\n"; 
     cout << "*AgePointer: " << *AgePointer << "\n"; 

     return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------


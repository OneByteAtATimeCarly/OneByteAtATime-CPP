//Pointers - 4 - The NEW Operator and the Free Store - 2004 C. S. Germany

//new - This keyword allocates memory on the free store (heap).  Followed by the type of object you want to allocate so the compiler knows how much memory is required.
//The return value from new is a memory address and must be assigned to a pointer.

//delete - returns memory to the free store. When you delete a pointer, you should set it to null(0).  Calling delete on a null pointer is guaranteed to be safe.

//Free store - The free store is a massive section of memory where thousands of tiny cubby holes lie waiting for data.  You can't label them as you can with the stack.
//You must ask for the address of the cubby hole that you reserve and then stash that address address away in a pointer. The pointer gives you access to your data without
//bothering you with the details.  The stack is cleaned automatically when a function returns and local variables go out of scope.
//The free store is not cleaned until your program ends. 

//On the free store, you must free any memory you have reserved when you are done with it. The advantage of the free store is that the memory you reserve remains available until you //explicitly free it.  If you reserve memory on the free store while in a function the memory is still available when the function returns.  This is better than using global variables //because only functions with access to the pointer have access to the data.  This provides a tightly controlled interface to the data and prevents a renegade function from changing
//and manipulating the data in unexpected ways.  For this to work you have to create a pointer to an area on the free store and pass that pointer among functions.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

typedef unsigned short int USHORT; 

//---------------------------------------------------------------------------------------------------------------------------

void Example()
{
     Animal *pDog = new Animal;
     delete pDog;                      //frees the memory
     pDog = 0;                         //sets pointer to null
     delete pDog;                      //now harmless
}

//---------------------------------------------------------------------------------------------------------------------------

int main()  { 

     int LocalStackVariable = 5; 
     int *StackPointer= &LocalStackVariable; 
     int *HeapPointer = new int;         //HeapPointer set up and points to new int on heap

     if(HeapPointer == NULL)  { 
        cout << "Error! No memory for HeapPointer!!"; 
        return 1;  }
 
     *HeapPointer = 7;
 
     cout << "LocalStackVariable: " << LocalStackVariable << "\n"; 
     cout << "*StackPointer: " << *StackPointer << "\n"; 
     cout << "*HeapPointer: " << *HeapPointer << "\n"; 

    delete HeapPointer; 
   
    HeapPointer = new int; 

    if(HeapPointer == NULL) { 
       cout << "Error! No memory for HeapPointer!!"; 
       return 1;  }
  
    *HeapPointer = 9; 
    cout << "*HeapPointer: " << *HeapPointer << "\n"; 

    delete HeapPointer; 

    return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------



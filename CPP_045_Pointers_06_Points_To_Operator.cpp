//Pointers - 6 - Using the NEW Operator to build Class Objects on the Free Store - 2004 C. S. Germany

//When creating objects on the stack, we must access data members and functions by using the dot operator "."  In the instance of the Cat class, this would apply to all Cat objects //created locally.  To access the Cat objects on the free store(heap), you also use the dot operator but you must dereference the pointer when you call the dot operator "."  on the
//object pointed to by the pointer.  To access the GetAge member function of an object on the heap (free store), you would write:
// (*KittyPointer).GetAge();

//Parenthesis are used to ensure that KittyPointer is dereferenced before the GetAge() member method is accessed.  One can also use the "points-to operator" - "->",
//a shorthand operator for indirect access. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//-----------------------------------------------------------------------------------------------------------

class Cat  { 

        public: 
        Cat() {itsAge = 2; } 
        ~Cat() {} 

        int GetAge() const { return itsAge; } 
        void SetAge(int age) { itsAge = age; } 
  
        private: 
        int itsAge; 
}; 
  
//-----------------------------------------------------------------------------------------------------------

int main()  {
 
     Cat *Sunshine = new Cat;
     Cat *Tiger = new Cat;
  
     cout << "Sunshine is " << Sunshine->GetAge() << " years old\n"; 
     Sunshine->SetAge(7); 

     Tiger->SetAge(5);
     cout << "Tiger is " << Tiger->GetAge() << " years old\n"; 

     delete Sunshine;
     delete Tiger;

     return 0; 
} 

//---------------------------------------------------------------------------------------------------------------------------




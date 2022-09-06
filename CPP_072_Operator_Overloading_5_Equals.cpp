//Operator Overloading - 5 - Overloading = - 2004 C. S. Germany
//Example 5

//It is also possible to overload operator = .  The compiler provides a default constructor, destructor, copy constructor and an assignment operator "=", if one is not declared.
//The default assignment operator is called whenever you assign to an object.  Example: CAT catTwo(3,4) - catTwo is created and assigned values 3 and 4.  A quick review:

//Shallow copy - Just copies members, both objects point to same area on free store.  Two pointers end up pointing to same memory location.
//Deep copy - Allocates necessary memory to NEW locations.  Pointers pointers point to different locations.

//In the expression, CAT catTwo(3,4), the object, catTwo, already exists and already has memory allocated.  That memory must be deleted to avoid a memory leak.
//The first thing to do is delete memory assigned to its pointers.  But what if you assign catTwo to itself, like catTwo = catTwo; ?  It is possible for this to
//happen by accident when referenced and dereferenced pointers hide the fact that the object's assignment is to itself.  The object catTwo could delete its memory
//allocation, and when it tried to copy memory from the right-hand assignment, the memory would be gone.  To protect against this, the assignment operator should
//check to see if the right-hand side of the assignment operator is the object itself by examining the "this" pointer to reveal whether or not they have the same
//address. 

//In this example, the current Platypus object being assigned to is tested to see whether it is the same as the Platypus being assigned.  This is done  by checking whether the
//address of "rhs" is the same as the address stored in the "this" pointer.  Remember it is common to refer to the parameter of a copy constructor as "rhs", which stands for
//"right hand side", signifying that which is on the right side of the assignment operator. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Platypus
{
      public:
      Platypus();         //default constructor
    
      //Accessor methods
      int GetAge() const { return *itsAge; }
      int GetWeight() const { return *itsWeight; }
      void SetAge(int age) { *itsAge = age; }

      //Overloaded assignment operator
      Platypus operator=(const Platypus &);

      private:
      int *itsAge;
      int *itsWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

//Platypus constructor assigns default values
Platypus::Platypus()
{
     itsAge = new int;
     itsWeight = new int;
     *itsAge = 5;
     *itsWeight = 9;
}

//---------------------------------------------------------------------------------------------------------------------------

//By overloading the assignment operator, we can use it to copy one object's data member to another
//Overloaded assignment operator checks to make sure address of object being passed in is not the same as object itself
Platypus Platypus::operator=(const Platypus & rhs)
{
     if (this == &rhs)
     return *this;
    
     delete itsAge;
     delete itsWeight;

     itsAge = new int;
     itsWeight = new int;
     *itsAge = rhs.GetAge();
     *itsWeight = rhs.GetWeight();

     return *this;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Platypus Joe;

    cout << "Joe's age: " << Joe.GetAge() << endl;
    cout << "Setting Joe to 6...\n";

    Joe.SetAge(6);

    Platypus Bill;

    cout << "Bill's age: " << Bill.GetAge() << endl;
    cout << "copying Joe to Bill...\n";

    Bill = Joe;   //calls the overloaded assignment operator

    cout << "Bill' age: " << Bill.GetAge() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








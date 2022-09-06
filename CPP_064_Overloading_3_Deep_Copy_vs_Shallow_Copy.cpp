//Overloading 3 - Deep Copy vs. Shallow Copy - 2004 C. S. Germany

//Copy constructor - The compiler provides a default copy constructor.  When you pass an object by value, a temporary copy of the object is made.  If the object is user-defined,
//the class's copy constructor is called.  All copy constructors take one parameter - a reference to an object of the same class.  Make it const so the constructor will not alter the //object passed in.  The default copy constructor copies the object passed in as a parameter to the member variables of the new object.  This is a member-wise or "shallow" copy.

//Shallow Copy - copies the exact values of one object's member variables into another object. 
//Pointers in both objects end up pointing to the same memory. (also called a "member-wise" copy).
//Problem:  The CAT class includes a member variable, KittyAge, that points to an integer created on the free store (heap).  The default copy constructor will copy the //KittyAge 
//member variable passed in from CAT to the new CAT's KittyAge member variable.  The two objects will then point to the same memory.  This will lead to disaster if either CAT
//goes out of scope.  When the object goes out of scope, the destructor is called and will attempt to clean up the allocated memory.  A copy will be left still pointing to that 
//memory, and if it tries to access the memory, it will crash the program. 

//Deep copy - copies the values allocated on the heap to newly allocated memory. 
//Solution: DEEP COPY. That is, define your own copy constructor and allocate the memory as required.  Once the memory is allocated, the old values can be copied into the new memory. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class CAT
{
      public:
      CAT();
      CAT (const CAT &);    //copy constructor
      ~CAT();               //destructor

      //Accessor methods
      int GetAge() const { return *KittyAge; }
      int GetWeight() const { return *KittyWeight; }
      void SetAge(int age) { *KittyAge = age; }

      private:
      int *KittyAge;
      int *KittyWeight;
};

//---------------------------------------------------------------------------------------------------------------------------

//Constructor supplies default values, creates int objects on heap
CAT::CAT()
{
    KittyAge = new int;       //have address point to new int on heap
    KittyWeight = new int;
    *KittyAge = 2;            //dereference to assign a value
    *KittyWeight = 10;
}

//---------------------------------------------------------------------------------------------------------------------------

//Define our own copy constructor for a deep copy.  "rhs" = right hand side.
//Copies all data members from one CAT object to another and creates new variables on the heap
CAT::CAT(const CAT & rhs)
{
    KittyAge = new int;
    KittyWeight = new int;
    *KittyAge = rhs.GetAge();
    *KittyWeight = rhs.GetWeight();
}

//---------------------------------------------------------------------------------------------------------------------------

//Need to add code to our destructor to clean up heap objects crated with constructor
CAT::~CAT()
{
    delete KittyAge;
    KittyAge = 0;        //for safety, initialize pointer to null after delete

    delete KittyWeight;
    KittyWeight = 0;     //for safety, initialize pointer to null after delete
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    CAT Tiger;

    cout << "Tiger's age: " << Tiger.GetAge() << endl;
    cout << "Setting Tiger to 9...\n";

    Tiger.SetAge(9);

    cout << "Creating Casey from Tiger\n";
   
    CAT Casey(Tiger);

    cout << "Tiger's age: " << Tiger.GetAge() << endl;
    cout << "Casey's age: " << Casey.GetAge() << endl;
    cout << "Setting Tiger to 3...\n";

    Tiger.SetAge(3);

    cout << "Tiger's age: " << Tiger.GetAge() << endl;
    cout << "Casey's age: " << Casey.GetAge() << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






//Polymorphism 5 - Pointers just do the right thing - 2004 C. S. Germany

//Pointers just do the right thing

//If a base class has a method "Speak()", and that method is overridden in it's derived class, a pointer to a base object that is assigned
//to a derived object will simply "do the right thing"

//dynamic_cast operator - The dynamic_cast operator ensures casting safely, but it is considered by many to be passé and unpredictable. The purpose of virtual functions is
//to allow the virtual table, rather than the programmer, to determine the runtime type of the object.  This helps you quickly find places in your code where you have used
//this feature and remove them.  If you have a pointer to a base class, such as Monster, and you assign to it a pointer to a derived class, such as Giant, you can use the
//Monster pointer polymorphically.  If you then need to get at the Giant object to call the SquashLittlePeopleLikeABug() method, you create a Giant pointer and use the
//dynamic_cast operator to make the conversion.

//At runtime the base pointer is examined.  If the conversion is proper, the new Giant pointer is fine, if not, or if you don't have a Giant object, the new pointer will be NULL.
//The dynamic_cast is complemented by the static_cast operator and functions like so:

//dynamic_cast<type-id>( expression ) - It converts the operand (expression) to the object of type <type-id>. The <type-id> must be a pointer or a reference to a pre-defined class. 

//static_cast<type-id>( expression ) -  It converts the operand (expression) to the object of type <type-id> without checking to make sure the conversion is safe.
//It is useful for converting a pointer to a base class object into a pointer to a derived class object.  It can also convert enums to ints and ints to floats. 

//In this example there are two loops.  In the first, the user is asked to add a Cat or Dog object to the array of Mammal pointers in a loop that iterates three times.
//This first loop calls the Mammal, Dog and Cat constructors as each object is chosen by the user and entered into an array.  The second loop uses an array to call the
//appropriate Speak() method from Dog and Cat that overrides the one in Mammal.  A pointer to Cat is created, "pRealCat".  It is initialized to 0 and dynamic_cast is
//used to make sure that the object the Purr() method is called on is a Cat and not something else for each element of Zoo[i].  If the object is a Cat, the pointer will
//not be NULL, and will pass the test and cout << "rrrrrrrrr".  If the object is not a Cat, the pointer will be NULL, and so it will fail the test and
//cout << "Uh oh, not a cat!\n".

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class B {  };

//---------------------------------------------------------------------------------------------------------------------------

class C : public B {  };

//---------------------------------------------------------------------------------------------------------------------------

class D : public C {  };

//---------------------------------------------------------------------------------------------------------------------------
 
void f(D *pd)
{
     C *pc = dynamic_cast<C*>(pd);         // ok: C is a direct base class
                                           // pc points to C subobject of pd
     B *pb = dynamic_cast<B*>(pd);         // ok: B is an indirect base class
                                           // pb points to B subobject of pd
}

//---------------------------------------------------------------------------------------------------------------------
void main() 
{ 
     D DObject;
     f(&DObject);
}

//---------------------------------------------------------------------------------------------------------------------------








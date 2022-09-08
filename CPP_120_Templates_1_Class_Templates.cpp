//Templates - 1 - Class Templates - The Basics - 2004 C. S. Germany

//Templates allow you to build type-safe collections.  Templates are sometimes considered superior to linked lists
//because linked lists can only handle the particular data objects they were created to work with.  You couldn't place a
//different object into a linked list without modifying it.  Templates allow you to teach the compiler how to make a list
//of any type of thing, rather than creating a set of type-specific lists.  The type of the thing in the list becomes a
//parameter to the definition of the class.  The Template class concepts we will deal with are the same as the concepts
//that cover our standard classes.  So therefore, template instantiation is the act of creating a specific type from a
//template, and template instances are marked by the individual class data types using the template.

//Templates allow you to create a GENERAL CLASS and pass "types" as parameters to that class to build specific instances.
//Therefore we can say that a Template is a class that is a parameterized List object.  Are we thoroughly confused now?
//Fear not, brave one, this too shall pass. :)  You declare a template by writing:

//          template <class T>
//          class List
//          {
//                public:
//                List();
//                //full class declaration here
//          };

//The keyword "template" must be used at the beginning of every declaration AND definition of a template class.  The parameters of the template
//are written after it - they are the items that will change with each instance.  In the expression "template <class T>", the keyword "class"
//indicates that this is a parameter type and that the identifier, "T", is used throughout the rest of the template definition to refer to the
//parameterized type (the class).  One instance of this class will substitute "int" wherever "T" appears, another instance will substitute
//"Monster".  To declare an "int" and "Monster" instance, we would write:

//          List<int> IntList;            //would create a List of int objects
//          List<Monster> MonsterList;    //would create a List of Monster objects

//The trick to template design is to get your template working on a single object/class type, then parameterize it, generalizing the template
//to handle any type of object.

//In the example below, we set up a template class to allow us to create an array of whatever type of objects we pass into it.  In main(), 
//6 different objects and class instances are created.  The first five objects are instantiated from built-in types.  The last object is
//created from our own user-defined class, Monster.  In effect, it is as if we had created six different classes, though we did it with one
//declared template class, the GenericArrayOfObjectsTemplate.  

//Also notice that  template <class T> has to come just before the template class itself.  Position and placement of the template declaration
//keyword matters when declaring and defining template classes.  We made the function, Intrude(), a friend function so that it could be accessed
//by objects that were not of the class itself.  Remember that a friend function, in addition to using the keyword "friend", must be defined
//outside the class.  This enables them to circumnavigate restrictions on data members that would otherwise be private or inaccessible to objects
//that were not of that class or that did not derive from it.


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster 
{     
        public:
 
            Monster() {}
            Monster(int sz) { cout << "Monster created.\n"; }
            ~Monster() { cout << "Monster destroyed.\n"; }

            int GetSize() { return itsSize; }
            void SetSize(int str) { itsSize = str; }

        private:
            int itsSize;
};

//---------------------------------------------------------------------------------------------------------------------------

template <class T>       // Declare the template and the generic parameter, "T".  T represents
                         // whatever object we will pass in to the template. Functions like a typedef
                         // for multiple classes. This must come directly BEFORE the template class below

//---------------------------------------------------------------------------------------------------------------------------

class GenericArrayOfObjectsTemplate            //The class being parameterized
{
public:
	//Constructor For some "odd" reason, Monsters come in sets of 3
	//Remember what the songs says - "3 is a magic number"... :)
	GenericArrayOfObjectsTemplate(int size = 3) { 
            
           itsSize = size;

              //Below we are saying that pType will become a pointer of whatever type of object
              //we pass in to the template and will point to an array of whatever type
              //of object we pass in to the template.  T is declared a pointer in the private member data.

	   pType = new T[size];

	   for (int i = 0; i < size; i++) {
	        pType[i] = 0; }
	} //close constructor
	//Copy constructor
	GenericArrayOfObjectsTemplate(const GenericArrayOfObjectsTemplate & rhs) {
	       
               itsSize = rhs.GetSize();
	       pType = new T[itsSize];

	       for(int i = 0; i < itsSize; i++) {
	       pType[i] = rhs[i]; }
        } //close copy constructor
	//Destructor
	~GenericArrayOfObjectsTemplate() { delete [] pType; }

	// Overloaded Operator =
	GenericArrayOfObjectsTemplate& operator=(const GenericArrayOfObjectsTemplate &) { 
               
               //Just make sure it's not the object itself trying to copy itself
               if (this == & rhs)
	       return *this;

	       delete [] pType;
	       itsSize = rhs.GetSize();
	       pType = new T[itsSize];

	       for (int i = 0; i < itsSize; i++)
	            pType[i] = rhs[i];

               return *this;
         } //close function
	//2 Overloaded Operator [], one constant and one not
	T & operator[](int offSet) 
            { return pType[offSet]; }

	const T & operator[](int offSet) const
	          { return pType[offSet]; }
	//Accessors
	int GetSize() const { return itsSize; }
	//friend function prototype/declaration. Remember that a friend
	//function must be defined outside the class specification.

	friend void Intrude(GenericArrayOfObjectsTemplate<int>);
private:
        //T represents what this will be a class of - the template
	T *pType;
	int  itsSize;
};

//---------------------------------------------------------------------------------------------------------------------------

// Friend Function - Intrude  Declared type <int>, can only be used
// with int arrays!   No OTHER data type.  Intrudes into private data.

void Intrude(GenericArrayOfObjectsTemplate<int> theGenericArrayOfObjectsTemplate) {

	cout << "\n*** Intrude <int> Template***\n";

	for(int i = 0; i < theGenericArrayOfObjectsTemplate.itsSize; i++) {
	    cout << "i: " <<    theGenericArrayOfObjectsTemplate.pType[i] << endl;  }

	cout << "\n";
     }

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     GenericArrayOfObjectsTemplate<int>     Test1;
     GenericArrayOfObjectsTemplate<float>   Test2;
     GenericArrayOfObjectsTemplate<long>    Test3;
     GenericArrayOfObjectsTemplate<double>  Test4;
     GenericArrayOfObjectsTemplate<char>    Test5;
     GenericArrayOfObjectsTemplate<Monster> Test6;

     //Can only be used with "int" instances of the template
     Intrude(Test1);
}

//---------------------------------------------------------------------------------------------------------------------------



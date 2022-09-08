//Vectors 1 - The Basics - 2004 C. S. Germany

//The Standard Template Library (STL) is a general library  of algorithms and data structures.  All of the STL's
//objects and classes follow the structure convention of C++ templates.  Some of the most useful objects and
//methods from the STL are:

//     vector -  resembles a C++ array, holds objects of the same type, each object can be accessed by index.
//     sort - algorithm that orders a STL container's contents in ascending order.
//     list - STL container class comprised of a linked list type data structure by using iterators.
//     iterator - functions like a pointer in STL containers.
//     find - searches a subrange of elements in a container looking for an element that matches a specified value.


//VECTORS - resemble a C++ array in that it holds objects of the same type, and that each of these objects
//can be accessed individually. Vector containers are optimized to provide fast access to their elements by an index. 
//(Be sure to study the requirements for objects that are stored in STL containers.) The vector container is defined as
//a template class, meaning that it can be customized to hold objects of any type.  A vector is great for accessing
//objects in sequence, but it does not provide an efficient method of accessing objects randomly, outside of sequence. 
//For random access, use some type of a map, multimap, set, or multiset container.

//There are 2 arguments that go with a vector container.  One is class T, and as with all templates, this represent the type of objects  being stored in the elements of the vector.  The //other argument is class A, the allocator class.  Allocators are memory managers responsible for memory allocation and deallocation of elements for containers.  Here's how we define //vectors:

//     vector<int>  VectorOfInts;
//     vector<floats>  VectorOfFloats;

//The vector class includes a constructor that accepts the number of elements in the vector as a parameter.  So to set up a vector of 100 monsters,
//you would declare:   vector<Monster>  MonsterMash(100);    Vectors include the size() method, to return the vector's number of elements.  That
//would be MonsterMash.size();  .  To assign objects to vectors, you would use the subscript operator just as you would with arrays:
//MonsterMash[3] = Godzilla;  Accessor method access is also the same as with arrays:  MonsterMash[3].GetStrength();

//You will most probably need to create the following items for any class you use with a vector:

//     1. A default constructor
//     2. A copy constructor
//     3. An overloaded assignment operator

//Vector Member Methods:

//     maxsize() - maximum number of elements allowed in a vector.
//     capacity() - tells how many elements a vector can hold.
//     size() - returns the number of items currently stored in the vector.
//     empty() - returns true if the number of elements is 0.
//     push_back -  returns an iterator that references a position just past the end of the vector.  For this method to work, the object class must define a copy constructor, 
//     begin() - returns an iterator that references the beginning of the vector.
//     end() - returns an iterator that references a position just past the end of the vector.
//     erase() - remove specified elements from a vector.
//     clear() - erases (removes) all elements from a vector.

//Vectors can grow automatically when more elements are added to them than they can handle. Below is an example:


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <vector>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Define a vector of integers. The template name is "vector".  The type of object
//it contains is "int". The fully specified container data type is "vector<int>".

void main() {

     vector<int> vec_one;

     int a = 10;   
     int b = 20;

     vec_one.push_back(a);  //Add items at end of vector
     vec_one.push_back(15);
     vec_one.push_back(b);

     // vec_one now contains three int values: 2, 10, -5

     unsigned int indx;

     //Display int objects stored in the vector
     for(indx = 0; indx < vec_one.size(); indx++)
     {
         cout << vec_one[indx] << " ";
     }
     cout << endl;

} // close main()

//---------------------------------------------------------------------------------------------------------------------------





//Iterators 1 - The Basics - 2004 C. S. Germany

//The Standard Template Library (STL) is a general library  of algorithms and data structures.  All of the STL's
//objects and classes follow the structure convention of C++ templates.  Some of the most useful objects and
//methods from the STL are:

//     vector -  resembles a C++ array, holds objects of the same type, each object can be accessed by index.
//     sort - algorithm that orders a STL container's contents in ascending order.
//     list - STL container class comprised of a linked list type data structure by using iterators.
//     iterator - functions like a pointer in STL containers.
//     find - searches a subrange of elements in a container looking for an element that matches a specified value.


//ITERATORS - STL objects that represent the positions of elements in various STL containers. They serve a function
//similar to that of a subscript in a C++ array, permitting the programmer to access a particular element, and to
//"iterate" through the container.  An iterator object is always associated with one specific type of container object. 
//Therefore, its type depends on the type of the container.  Example:

//       #include <list>
//       #include <vector>
//       using namespace std;

//       list<int> nums;
//       list<int>::iterator nums_iter;
//       vector<double> values;
//       vector<double>::iterator values_iter;
//       vector<double>::const_iterator const_values_iter;


//Types of iterators:
//Forward - specifies the position of a single element in a container.  Moves in one direction from element to element.
//Bidirectional - like a forward iterator, but moves in two directions, forward and reverse, from element to element.
//Random Access - like a bidirectional iterator, but can also move in larger steps, skipping multiple elements.

//Iterator operators:
//Overloaded iterator operators are:  ==,  !=,  *,  ++,  --,  +=,  -=,  +,  -,  <,  >,  <=,  >= 

//Below, after creating a list of integers and adding some elements, we initialize the iterator nums_iter to specify the first list position,
//nums.begin(). The loop runs until we reach the iterator value that represents the position just beyond the last list element, nums.end().
//Each list element is accessed by the "*" operator, which returns a reference to the element.  The increment operator (++) moves the iterator
//to the next position in the list.  In this case, we are using the iterator to modify the list elements.  If this were not so, the iterator
//could have been declared constant, like:   list<int>::const_iterator nums_iter; 


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <list>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{

  list<int> nums;

  //Declare an iterator
  list<int>::iterator nums_iter;

  nums.push_back(100);
  nums.push_back(200);
  nums.push_front(300);

  cout << endl << "List 'nums' now becomes:" << endl;

  for(nums_iter = nums.begin(); nums_iter != nums.end(); nums_iter++)
  {
    //We must dereference the iterator since we are modifying object values rather than addresses
    *nums_iter = *nums_iter + 3;
    cout << (*nums_iter) << endl;
  }

  cout << endl;
} //close main()

//---------------------------------------------------------------------------------------------------------------------------










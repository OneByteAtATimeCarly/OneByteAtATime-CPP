//STL - The Find Method - 2004 C. S. Germany

//find() method - searches a subrange of elements in a container looking for an element that matches a specified
//value.  The equality operator (==) must be defined (overloaded) for the data type of the container's elements.  The
//find() algorithm searches the specified subrange of the container's elements and stops when it finds the first element
//equal to the specified value, as defined by the equality (==) operator as it applies to the container's elements.  The
//search value is the third argument to the find function.  It must be of the same type as the elements stored in the
//container, or of a type that the compiler can automatically convert.  For this reason, at times, it is necessary to create
//and initialize a temporary data object.

//The return value of the find function is an iterator specifying the position of the first matching element.
//If no matching element is found, the return value is equal to the iterator specifying the end of the element subrange.
//In the example below, this is the end of the list:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>           // vector class library
#include <list>             // list class library
#include <algorithm>     // STL algorithms class library
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     list<int> nums;
     list<int>::iterator nums_iter;

     nums.push_back (900);
     nums.push_back (950);
     nums.push_front (1000);

     nums_iter = find(nums.begin(), nums.end(), 900);    // Search the list.

     if(nums_iter != nums.end())
     {
          cout << "Number " << (*nums_iter) << " found." << endl; // 3
     }
     else
     {
         cout << "Number not found." << endl;
     }

     //If we found the element, erase it from the list.
     if(nums_iter != nums.end())
         nums.erase(nums_iter);

      //The List now contains: 10 7

} //close main()

//---------------------------------------------------------------------------------------------------------------------------











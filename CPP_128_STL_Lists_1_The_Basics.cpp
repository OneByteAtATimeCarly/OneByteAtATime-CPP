//Lists 1 - The Basics - 2004 C. S. Germany

//The Standard Template Library (STL) is a general library  of algorithms and data structures.  All of the STL's
//objects and classes follow the structure convention of C++ templates.  Some of the most useful objects and
//methods from the STL are:

//     vector -  resembles a C++ array, holds objects of the same type, each object can be accessed by index.
//     sort - algorithm that orders a STL container's contents in ascending order.
//     list - STL container class comprised of a linked list type data structure by using iterators.
//     iterator - functions like a pointer in STL containers.
//     find - searches a subrange of elements in a container looking for an element that matches a specified value.


//LISTS - The List container class is comprised of a linked list type data structure.  The objects in the list class can not be
//accessed directly, they follow the usual indirect access method that we find via pointers and references in typical
//linked lists.  The List class is defined as a template, so it can hold object of any data type.   List containers are
//designed for optimal efficiency when inserting and deleting objects frequently.  The List class has al the member
//functions of the vector class.  Linked lists are implemented with pointers, but STL List containers are implemented
//with iterators.  An iterator is a generalization of a pointer.  When you dereference an iterator, you can retrieve the
//node it points to.  Example:




//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>          // vector class library
#include <list>	           // list class library
#include <algorithm>	   // STL algorithms class library
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     list<int> IntList;

     //Remember that iterators function like pointers, so this is like declaring a pointer
     list<int>::iterator NumberIterator;
     IntList.push_back(100);
     IntList.push_back(200);
     IntList.push_front(300);
     NumberIterator = find(IntList.begin(), IntList.end(), 300);    //Search the list.
     if(NumberIterator != IntList.end())
     {
          //Notice that NumberIterator gets dereferenced like a pointer
          cout << "Number " << (*NumberIterator) << " found." << endl; // 3
     }

     else
     {
         cout << "Number not found." << endl;
     }
     //If we found the element, erase it from the list.
     if(NumberIterator != IntList.end())
        IntList.erase(NumberIterator);
     //The List now contains: 10 7 
}

//---------------------------------------------------------------------------------------------------------------------------










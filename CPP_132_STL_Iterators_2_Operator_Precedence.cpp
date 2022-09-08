//Iterators 2 - Operator Precedence - 2004 C. S. Germany

//When the elements stored in an STL container are objects of a class type, we may want to invoke member functions of the object referenced
//by an iterator. If doing so, we must bear in mind operator precedence.

//In the example below,the parentheses around "*words_iter" are required when we invoke the "length()" member function.  Without them,
//the compiler would think that the "length()" function is a member of the iterator class, rather than the string class, since the "."
//operator would be evaluated before the unary "*" operator.  As you might expect, the parentheses would also be required if we wish to
//access a data member of an object referenced by an iterator.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{

  list<string> words;

  //Declare iterator
  list<string>::iterator words_iter;

  unsigned int total_length = 0;

  for(words_iter = words.begin(); words_iter != words.end(); words_iter++)
  {
    //We must dereference the iterator to get at the value first
    total_length += (*words_iter).length();      // correct

    // total_length += *words_iter.length();    // incorrect !!
  }

  cout << "Total length is " << total_length << endl;

} // close main()

//---------------------------------------------------------------------------------------------------------------------------











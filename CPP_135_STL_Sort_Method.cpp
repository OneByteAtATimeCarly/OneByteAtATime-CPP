//STL - The Sort Method - 2004 C. S. Germany

//sort() method - a function that can be applied to many STL containers (with the notable exception of the list container).
//For now, we will consider its use only with the vector container class template.  The sort
//algorithm orders the container's contents in ascending order, as defined by the "less than" (<) operator as applied to
//the vector elements. If this operator is defined for a programmer-defined type (as is the case with the string class),
//then the programmer-defined type can be sorted just as easily as a built-in type. Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{

     vector<int> vect;
     vect.push_back (500);
     vect.push_back (600);
     vect.push_back (700);

     sort(vect.begin(), vect.end());

} //close main()

//---------------------------------------------------------------------------------------------------------------------------











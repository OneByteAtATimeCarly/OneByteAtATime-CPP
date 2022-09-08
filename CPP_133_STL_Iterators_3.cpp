//Iterators 3 - Iterator Arguments - 2004 C. S. Germany

//Some STL functions (algorithms and container member functions) require iterator arguments. For example:

//     The sort algorithm, when applied to a vector container.
//     The erase member function, specifying one element or a range of elements, with vector and list containers.
//     The find algorithm, when applied to a list container.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>      
#include <list>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     vector<int> vect1;

     int num1 = 10;
     int num2 = 5;

     vect1.push_back(num1);
     vect1.push_back(num2);
     vect1.push_back(20);
     vect1.push_back(15);

     vector<int>::iterator IntIterator;

//---------------------------------------------------------------------------------------------------------------------------

     //Before sort
     cout << "Here\'s the contents of the vector before sort:\n";
     for(IntIterator = vect1.begin(); IntIterator != vect1.end(); IntIterator++)
     {
         cout << (*IntIterator) << endl;
     }
     cout << endl;

//---------------------------------------------------------------------------------------------------------------------------

       //After sort
     cout << "Here\'s the contents of the vector after sort:\n";
     sort(vect1.begin(), vect1.end());
     for(IntIterator = vect1.begin(); IntIterator != vect1.end(); IntIterator++)
     {
         cout << (*IntIterator) << endl;
     }
     cout << endl;

//---------------------------------------------------------------------------------------------------------------------------

     //Using find(), searching for 15
     cout << "Callling find(). Searcing for 15." << endl;
     IntIterator = find(vect1.begin(), vect1.end(), 15);
     if(IntIterator != vect1.end())
     {
        cout << "Number " << (*IntIterator) << " was found." << endl;
     }
     else { cout << "Number not found." << endl; }
     cout << endl;

//---------------------------------------------------------------------------------------------------------------------------

       //Using find(), searching for 100
     cout << "Callling find(). Searcing for 100." << endl;
     IntIterator = find(vect1.begin(), vect1.end(), 100);
     if(IntIterator != vect1.end())
     {
        cout << "Number " << (*IntIterator) << " was found." << endl;
     }
     else { cout << "Number not found." << endl; }
     cout << endl;

//---------------------------------------------------------------------------------------------------------------------------

       //Calling erase()
     cout << "Here\'s the contents of the vector after erase():\n";
     vect1.erase(vect1.begin(),vect1.end());
     for(IntIterator = vect1.begin(); IntIterator != vect1.end(); IntIterator++)
     {
         cout << (*IntIterator) << endl;
     }
     cout << endl;

//---------------------------------------------------------------------------------------------------------------------------

} //close main()

//---------------------------------------------------------------------------------------------------------------------------











//Lists 2 - Example 2 - 2004 C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <list>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

typedef list<int> IntegerList;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	IntegerList ListOfInts;

	for(int i = 1; i <= 10; ++i)
	    ListOfInts.push_back(i * 10);

        //Remember that declaring an iterator is like declaring a pointer
        IntegerList::const_iterator ConstIter;

	for(ConstIter = ListOfInts.begin(); ConstIter != ListOfInts.end(); ++ConstIter)
            //Again, notice that we dereference the iterator as we would a pointer
	    cout << *ConstIter << " ";

	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------











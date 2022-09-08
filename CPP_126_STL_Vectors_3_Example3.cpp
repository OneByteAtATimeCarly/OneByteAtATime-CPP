//Vectors 3 - Example 3 - 2004 C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

template<class T>
//---------------------------------------------------------------------------------------------------------------------------

//The class "PrintMe" is a template class as declared above

class PrintMe
{
      public:
         //Overload () operator to display t
	 void operator()(const T & t)
	 {
		cout << t << " ";
	 }
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
        int NumberOfItems = 10;

	PrintMe<int>  DisplayInt;
	vector<int>   VectorOfInts(NumberOfItems);
	for(int i = 0; i < NumberOfItems; ++i)
	    VectorOfInts[i] = i * 2;
	cout << "Using the for_each() method:  ";

	for_each(VectorOfInts.begin(), VectorOfInts.end(), DisplayInt);

	cout << "\n";
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------








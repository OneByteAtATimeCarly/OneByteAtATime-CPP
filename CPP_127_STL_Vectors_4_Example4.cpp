//Vectors 4 - Example 4 - 2004 C. S. Germany


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
        int NumberOfItems = 14;
        int Half = NumberOfItems / 2;
 
	PrintMe<int>	PrintInts;
	vector<int>	VectorOfInts(NumberOfItems);
	fill(VectorOfInts.begin(), VectorOfInts.begin() + Half, 1);
	fill(VectorOfInts.begin() + Half, VectorOfInts.end(), 2);
	for_each(VectorOfInts.begin(), VectorOfInts.end(), PrintInts);

	cout << "\n\n";
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------










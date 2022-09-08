//Non-mutating Algorithms - 2004 C. S. Germany

//Non-mutating sequence operations perform operations that don't change the elements in a sequence.  
//Example: for_each(), search(), find(), and count().

//The for_each() function going through each element in a vector displays but does not change them in the example below:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

template<class T>

//---------------------------------------------------------------------------------------------------------------------------

class PrintMe
{
public:
	void operator()(const T & t)
	{
		cout << t << " ";
	}
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	PrintMe<int>	PrintThis;
	vector<int>	vInt(5);
	for(int i = 0; i < 5; ++i)
	    vInt[i] = i * 3;
	cout << "for_each()\n";

	for_each(vInt.begin(), vInt.end(), PrintThis);
	cout << "\n";
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------










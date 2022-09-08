//Function Objects - 2004 C. S. Germany

//A function object is an instance of a class that defines the overloaded operator (). In this way, it can be used to call a
//function. In the example below, it is used with a template function to display output for whatever is passed to it by reference.

//Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

template<class T>

//---------------------------------------------------------------------------------------------------------------------------

class PrintMe    {
public:
    void operator()(const T & t)
    {
	 cout << t << " ";
    }
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{

    //We'll create a function that works like the old C printf() fucntion 
    PrintMe<int> PrintThis;
    for(int i = 0; i < 5; ++i)
	PrintThis(i);

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------










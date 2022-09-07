//Arrays - 19 - Initializing an array of char pointers - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

//Using sizeof() to compute the number of elements in an array
int NumElements = ( sizeof(pstr) )  / ( sizeof(pstr[0]) );

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
   const char* pstr[] = { "Robert Redford",      // Initializing a pointer array
                    "Hopalong Cassidy",
                    "Lassie",
                    "Slim Pickens",
                    "Boris Karloff",
                    "Oliver Hardy"
                  };  
   char* pstart = "Your lucky star is ";
   int count = (sizeof pstr)/(sizeof pstr[0]); // Number of array elements
   int dice = 0;
   cout << endl
        << " Pick a lucky star!"
        << " Enter a number between 1 and " << count << ": ";
   cin >> dice;
   cout << endl;
   if(dice >= 1 && dice <= count)                     // Check input validity
      cout << pstart << pstr[dice-1];                  // Output star name
   else
      cout << "Sorry, you haven't got a lucky star."; // Invalid input
   cout << endl;
   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



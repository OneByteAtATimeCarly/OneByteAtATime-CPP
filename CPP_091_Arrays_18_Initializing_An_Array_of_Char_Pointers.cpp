//Arrays - 18 - Initializing an array of char pointers - 2004 C. S. Germany

//Initializing an array of char pointers

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
   char * pstr[] =  { "Robert Redford",  
                     "Hopalong Cassidy",
                     "Lassie",
                     "Slim Pickens",
                     "Boris Karloff",
                     "Oliver Hardy"
                   };
   char* pstart = "Your lucky star is ";
   int dice = 0;
   cout << endl
        << " Pick a lucky star!"
        << " Enter a number between 1 and 6: ";
   cin >> dice;
   cout << endl;
   if(dice >= 1 && dice <= 6)                      // Check input validity
      cout << pstart << pstr[dice-1];               // Output star name
   else
      cout << "Sorry, you haven't got a lucky star."; // Invalid input
   cout << endl;
   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



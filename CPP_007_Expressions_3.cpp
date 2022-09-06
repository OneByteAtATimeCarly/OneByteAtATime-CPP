//Expressions 3 - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
  int myAge = 39;      // initialize two integers
  int yourAge = 39;

  cout << "I am:\t" << myAge << "\tyears old.\n";
  cout << "You are:\t" << yourAge << "\tyears old\n";

  myAge++;         // postfix increment
  ++yourAge;       // prefix increment

  cout << "One year passes...\n";
  cout << "I am:\t" << myAge << "\tyears old.\n";
  cout << "You are:\t" << yourAge << "\tyears old\n";

  cout << "Another year passes\n";
  cout << "I am:\t" << myAge++ << "\tyears old.\n";  //post-fix increment
  cout << "You are:\t" << ++yourAge << "\tyears old\n";  //pre-fix increment
 
  cout << "Let's print it again.\n";
  cout << "I am:\t" << myAge << "\tyears old.\n";
  cout << "You are:\t" << yourAge << "\tyears old\n";

  return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



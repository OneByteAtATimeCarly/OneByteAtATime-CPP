//Decisions - 5 - Switch Statements - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

void main() {

     cout << "\nEnter your choice(1-7):\t";
     cin >> choice;
     switch(choice) 
     {
             case 0 : RunProgram = 0;
                      break;
             case 1 : cout << "You chose 1";
	              break;
             case 2 : cout << "You chose 2";
	              break;
             case 3 : cout << "You chose 3";
	              break;
             case 4 : cout << "You chose 4";
	              break;
             case 5 : cout << "You chose 5";
	              break;
             case 6 : cout << "You chose 6";
	              break;
             case 7 : cout << "You chose 7";
	              break;
             default : cout << "Sorry, invalid choice.";
	               break;
     } //close switch statement
} //end main()

//---------------------------------------------------------------------------------------------------------------------------


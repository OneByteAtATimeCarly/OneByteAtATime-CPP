//Exceptions 3 - Try and Catch With Number Game - 2004 C. S. Germany

// Let's use the simple number guessing game we created a long time ago.  We ask the user for integer input.
//However, if the user types a character other than a numeral, our program will crash. This is because the
//size of the data type we are asking for, an integer, and therefore the memory set aside for an integer,
//is different form a char or an array of char's. 

//A way to get around this is to accept the user's input as string data, that is a char array.  This data type is
//the most versatile and therefore more forgiving of user mistakes.  We can then test to see if what the user entered
//is in fact integer material using the isdigit() method from the <cctype.h> file.  This needs to be used with the
//standard namespace.  The isdigit() function will return true or false based on whether or not the string data is a digit. 

//Also, since strings are composed of array elements that each have an ASCII code, we can use that relationship to convert
//each ASCII code char into its corresponding integer.  We can achieve this by subtracting 48 from each character to arrive
//at its integer equivalent.  Since we must do this one char element at a time, we must loop through the array and
//progressively multiply by 10 for each iteration of the loop.  Each time we multiply by 10, will move the decimal to the
//right one place, and so cover the one's, ten's, hundred's, and thousand's places and so on.


//Catching exceptions during user input

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cctype> 
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class ErrorHere { };
int main()
{
    const int MAX = 10;
    int x = 0;
    const int MyNum = 5;
    int NumGuessed = 0;
    char expression[MAX];

    int ArraySize = ( sizeof(expression) )  / ( sizeof(expression[0]) ); 
    cout << "Size of array is: " << ArraySize << endl;
    try {
         cout << "Please guess a number between 1 and 10:\t";
         cin >> expression;
         x = 0;
         while(isdigit(expression[x]))       
	 {
             NumGuessed = 10 * NumGuessed + (expression[x] - 48);
	     x++;
	 }
         if(!isdigit(expression[x-1]))    //offset for fencepost - x was incremented 1 past
	    throw ErrorHere();
         cout << "You guessed the number " << NumGuessed << ".\n";
         if(NumGuessed == MyNum)
	 {
	    cout << "That\'s it! You guessed my number!\n";
	    cout << "You win!\n\n";
	 }
    
         else 
	 { cout << "I\'m sorry, you did not guess my number."; }
	 return 0;
    } //close try
    catch(ErrorHere)
    { 
	cout << "Hey!  That is NOT a number!" << endl << endl;  
    }
} // close main

//---------------------------------------------------------------------------------------------------------------------------






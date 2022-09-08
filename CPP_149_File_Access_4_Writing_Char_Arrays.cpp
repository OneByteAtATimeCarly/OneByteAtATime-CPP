//File Access 4 - Forgoing Strings and Writing Char Arrays to a File - 2004 C. S. Germany

//Forgoing Strings and Writing Char Arrays to a File

//Let's expound on ignore(). Remember, ignore() ignores a specified number of characters.  It is useful for cleaning out the input
//stream of terminating Nulls and line returns, and for searching/parsing data in the input stream.  When using the getline() function,
//you will need to use ignore() a lot to keep your code from being buggy.  You will recall that several examples ago we used getline()
//in a letter guessing game.  This code was buggy without the appropriate use of ignore.  This is because getline() waits until the
//user hits return before passing the input data to the stream.  It then removes the line return "\n", and leaves it in the stream.
//This can cause getline() to skip lines of input, assigning the wrong value to variables, or not even asking the user for input at all.

//The ignore() function can be used to clean out the stream and remedy this situation.  It takes two arguments: 

//       1 - the number of chars to ignore
//       2 - the deLimiter character.  

//The ignore() function will ignore to the specified number of chars or until it reaches what you specify as the delimiter.
//If it reaches the delimiter first, it will stop.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     char TheFile[20] = "";
     char FileName[10] = "";
     char Detect;

     cout << "Enter a name for the file followed by a (*): ";
     cin >> FileName;

     cin.ignore(1);
     for(int x = 0; x<=10 ; x++)
		  TheFile[x] = FileName[x];
	 
     for(int z = 0; z<=20 ; z++) 
	 {
	     Detect = TheFile[z];
		 if(Detect == '*')
		 {	
			 TheFile[z] =    '.';
			 TheFile[z+1] =  't';
                         TheFile[z+2] =  'x';
			 TheFile[z+3] =  't';
			 z = 100;  //Or break; - whatever ...
		 }
	 }
	  	 
     ofstream OutputFile;
     OutputFile.open(TheFile, ios::app);
     string GiantLizard = "Godzilla ";
     string ModernCity = " Tokyo";
     string Action = "";
     cout << "Give me an action verb: ";
     cin >> Action;
     OutputFile << GiantLizard << Action << ModernCity << "." << endl;
     OutputFile.close();

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









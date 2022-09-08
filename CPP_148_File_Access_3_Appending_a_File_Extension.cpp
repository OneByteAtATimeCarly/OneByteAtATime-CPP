//File Access 3 - Appending a File Extension - 2004 C. S. Germany

//Appending a File Extension  

//In the example below, we used the overloaded + operator of the string class to concatenate what the user types in with the file's extension, ".txt".
//We had to use the c_str() method to convert the string object "FileName" to a char pointer, because we can not feed a string into the first argument
//for open() directly.  We can, however, feed a pointer to a char.  

//We could have forgone the strings and used used plain old char arrays for the filename, but we would have had to cycle through the elements one by
//one via a loop in order to add the file extension to the end of the char array.   How's that, you say?   Just check for an ASCII value, then append
//the text char by char, element by element.  It's what the string class is doing for us all the time anyway, behind the scenes.   Yes, we can do what
//we are about to do below, but the string/c_str way is a lot smoother.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     string FileName = "";
     string Extension = ".txt";
     cout << "Enter a name for the file: ";
     cin >> FileName;
    
     FileName = FileName + Extension;

     //Here, we have to convert the sting into a char pointer in order to pass it to open()
     const char * TheFile = FileName.c_str();

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









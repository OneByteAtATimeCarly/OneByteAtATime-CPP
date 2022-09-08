//File Access 2 - Writing Strings to a File - 2004 C. S. Germany

//Writing Strings to a File

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     ofstream OutputFile;
     OutputFile.open("GoodMovie.txt",ios::app);
    
     string GiantLizard = "Godzilla ";
     string ModernCity = " Tokyo";
     string Action = "";
    
     cout << "Give me an action verb: ";
     cin >> Action;
    
     OutputFile << GiantLizard << Action << ModernCity << "." << endl;
    
     OutputFile.close();

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









//File Access 5 - Reading Using the Stream Operator - 2004 C. S. Germany

//Input from a file using the stream operator, a loop and strings

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     ifstream InputFile;
     InputFile.open("GoodMovie.txt",ios::in);

     string FileContents1 = "";
     string FileContents2 = "";

     while(!InputFile.eof())
     {
          InputFile >> FileContents1;
          FileContents2 = FileContents2 + " " + FileContents1;
     } 

     cout << FileContents2 << endl << endl;

     InputFile.close();

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









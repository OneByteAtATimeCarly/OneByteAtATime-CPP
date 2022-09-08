//Sequential File Access  1 - The Basics - Saving to File Using get() - 2004 C. S. Germany

//Sequential Access files - access the contents of a file in sequence - hence the name.  A files access pointer will start at
//the first character in the file and proceed until the last eof().  The advantage of this method of file access is that it is
//relatively simple.  It is convenient for storing logs, trace files, and ASCII data.  The disadvantage is that, if you want
//to store data that is more complex than ASCII text, you are limited.  For many purposes, sequential access files are
//fine.

//Saving to File Using get()

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
	char FileName[80];
	char buffer[255];
	cout << "Please re-enter the file name: ";
	cin >> FileName;
	ifstream InputFile(FileName);
	if(InputFile)                         //Does the file exist?
	{
		cout << "Current file contents:\n";
		char ch;

		while(InputFile.get(ch)) 
                {		  
                      cout << ch;  //Get each char in the file one by one
                }

		cout << "\n***End of file contents.***\n";
	}

	InputFile.close();
	cout << "\nOpening " << FileName << " in append mode...\n";
	ofstream OutputFile(FileName,ios::app);
	if (!OutputFile)
	{
		cout << "Unable to open " << FileName << " for appending.\n";
		return(-1);   //Return -1 on error
	}
	cout << "\nEnter text for the file: ";

	cin.ignore(1,'\n');
	cin.getline(buffer,255);

	OutputFile << buffer << "\n";
	OutputFile.close();
	InputFile.open(FileName);  

	if(!InputFile)
	{
		cout << "Unable to open " << FileName << " for reading.\n";
		return(1);
	}

	cout << "\nHere's the contents of the file:\n";

	char ch;

	while(InputFile.get(ch))
        {
		cout << ch;
        }
	cout << "\n***End of file contents.***\n";

	InputFile.close();

	return 0;

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









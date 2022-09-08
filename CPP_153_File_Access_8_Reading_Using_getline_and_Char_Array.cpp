//File Access 8 - Reading Using getline() and a Char Array - 2004 C. S. Germany

//Reading Using getline() and a Char Array 

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









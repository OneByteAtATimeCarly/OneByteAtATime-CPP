//File Access 7 - Reading Using a While True Loop - 2004 C. S. Germany

//Reading Using a While True Loop, the stream operator and char arrays 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
	char FileName[80];
	char buffer[255];    
	cout << "File name: ";
	cin >> FileName;
	ofstream OutputFile(FileName);  
	OutputFile << "This line written directly to file...\n";
	cout << "Enter text for the file: ";

	cin.ignore(1,'\n');    //Consume the newline "\n" after the file name

	cin.getline(buffer,255);   
	OutputFile << buffer << "\n";   
	OutputFile.close();            
	ifstream InputFile(FileName);
	cout << "Here's the contents of the file:\n";
	char ch;

	while(InputFile.get(ch))   //get(ch) will fetch the chars in the file one by one till the end
        {	      
            cout << ch;            //chars displayed one by one
        }
	cout << "\n\nThat\'s the whole file.\n\n";
	InputFile.close();
            
	return 0;

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









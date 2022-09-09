//AddressBook 1 - Sequential File Access - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

//©2004 C. Germany - Addressbook 1.0 - Sequential file access. 
//This is a simple project to teach sequential file access and file searching.
//As such, it does not incorporate class structure or indirection.

//Note:  Microsoft's implementation of getline() was broken.
//They offer a workaraound, changing I.rdbuf()->snextc(); in the string header file
//to _I.rdbuf()->sbumpc();.  Ofcourse, it doesn't work!  

//This version uses a patch developed by another programmer that actually fixes this bug.
//You must include the "GetLinePatch.h" file in your project, as above, and then you must call 
//cin.seekg( 0, ios::end ); and then FIXGETLINE BEFORE you use getline();
//Many, many thanks to Garth B. Santor who wrote the fix when Microsoft's response
//to this 6.0 problem was simply "Go out and buy .NET". 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include "GetLinePatch.h"
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function prototypes
void EnterAddresses();
void DisplayAllEntries();
void SearchEntries();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    char GoOn = 'y';
    while(tolower(GoOn) != 'n')
    {
          cout << endl << endl;
          cout << "\t***************** Address Book Menu ******************\n";
	  cout << "\t*                                                    *\n";
	  cout << "\t*                 E(x)it the program                  *\n";
	  cout << "\t*                (A)dd contact information           *\n";
	  cout << "\t*                (D)isplay All Entries               *\n";
	  cout << "\t*                (S)earch for a contact              *\n";
	  cout << "\t*                                                    *\n";
	  cout << "\t******************************************************\n";
    	  cout << endl << endl ;
          cin >> GoOn;
	  switch(tolower(GoOn)) 
	  {
	         case 'x' : GoOn = 'n';
		  	    break;

                 case 'a' : EnterAddresses();
		            break;

	         case 'd' : DisplayAllEntries();
			    break;

		 case 's' : SearchEntries();
                            break;

		 default : cout << "Invalid choice.";
		           break;
		  
          } //close switch statement
    } //close while true loop 
    return 0;

} //close main() function

//---------------------------------------------------------------------------------------------------------------------------

void EnterAddresses()
{
     char KeepGoing = 'y';

     string LastName = "";
     string FirstName = "";
     string Address = "";
     string City = "";
     string State = "";
     string ZipCode = "";
     string HomePhone = "";
     string WorkPhone = "";
     string CellPhone = "";
     string Email = "";
     string Website = "";
     ofstream OutputFile;
     OutputFile.open("addresses.dat", ios::app);
     if(OutputFile.is_open())
     {
	cout << "\n\nYou may add new records to the file.  Enter \"q\" to quit. \n\n";
       
        while(tolower(KeepGoing) != 'n')
        {
             cout << "Enter last name: ";
             cin >> LastName;
             cout << "Enter first name: ";
             cin >> FirstName;
             cout << "Enter address: ";
             cin.seekg( 0, ios::end );
	     FIXGETLINE; //these two lines are used with the getline() fix
             getline(cin, Address);
             cout << "Enter city: ";
             cin.seekg( 0, ios::end );
	     FIXGETLINE;
             getline(cin, City);
             cout << "Enter state: ";
             cin >> State;
             cout << "Enter zipcode: ";
             cin >> ZipCode;
             cout << "Enter phone (home): ";
             cin >> HomePhone;
             cout << "Enter phone (work): ";
             cin >> WorkPhone;
             cout << "Enter phone (cell): ";
             cin >> CellPhone;
             cout << "Enter email address: ";
             cin >> Email;
             cout << "Enter website: ";
             cin >> Website;
             //Now that we have all the information to write, write it to the file
             OutputFile << LastName << "#" << FirstName << "#"
		        << Address << "#" << City << "#"
			<< State << "#" << ZipCode << "#"
			<< HomePhone << "#" << WorkPhone << "#"
			<< CellPhone << "#" << Email << "#"
			<< Website << endl;

             cout << "\n\nWant to add another entry? (y/n): ";
             cin >> KeepGoing;

	   } //close while true loop
    OutputFile.close();
    }
    else 
          cout << "Error opening file." << endl;
} //close function()

//---------------------------------------------------------------------------------------------------------------------------

void DisplayAllEntries()
{
     string DETECT = "";
     int Counter = 1;

     string LastName = "";
     string FirstName = "";
     string Address = "";
     string City = "";
     string State = "";
     string ZipCode = "";
     string HomePhone = "";
     string WorkPhone = "";
     string CellPhone = "";
     string Email = "";
     string Website = "";
     ifstream InputFile;
     InputFile.open("addresses.dat", ios::in);  
     //Check to see if the file exists
     if(InputFile.is_open()) 
     {
        InputFile >> DETECT;
	//Reset file pointer back to beginning of file
        InputFile.seekg(0);
	//Check to make sure the file is not empty
        if(DETECT != "") 
	{
           //Go through the file until reaching the end
	   while(!InputFile.eof()) 
	   {
                 getline(InputFile, LastName, '#'); 
		 getline(InputFile, FirstName, '#');
                 getline(InputFile, Address, '#');
		 getline(InputFile, City, '#');
                 getline(InputFile, State, '#');
		 getline(InputFile, ZipCode, '#');
                 getline(InputFile, HomePhone, '#');
		 getline(InputFile, WorkPhone, '#');
                 getline(InputFile, CellPhone, '#');
		 getline(InputFile, Email, '#');
                 getline(InputFile, Website);
                 //Keep the output from repeating/printing an empty record if at end of file  
		 if(!InputFile.eof()) 
		 {
                     cout << "\n\n-----------------Address Record "
		          << Counter << "-------------------\n";
		     cout << "First Name: " << FirstName << endl;
                     cout << "Last Name: " << LastName << endl;
	             cout << "Address: " << Address << endl;
	             cout << "City: " << City << endl;
		     cout << "State: " << State << endl;
		     cout << "Zip Code: " << ZipCode << endl;
		     cout << "Phone (home): " << HomePhone << endl;
		     cout << "Phone (work): " << WorkPhone << endl;
		     cout << "Phone (cell): " << CellPhone << endl;
		     cout << "Email: " << Email << endl;
		     cout << "Website: " << Website << endl;
                     cout << "---------------------End of Record----------------------\n\n";
					  //cout.flush();
		 } //close 3rd if
		 Counter++;
	   } // close while true loop
           cout << "End of records.";
       } //close 2nd if
       else
       {
	     cout << "\n\nThere are no records to display.";
       }
       InputFile.close();
        
    } //close 1st if
    else
    {
         cout << "Could not open the address book file." << endl;
    }
} //close function

//---------------------------------------------------------------------------------------------------------------------------

void SearchEntries()
{
    bool ShowIt = false;
    int Counter = 1;
    char MenuChoice;

    string SearchItem;
    string DETECT = "";
    string LastName = "";
    string FirstName = "";
    string Address = "";
    string City = "";
    string State = "";
    string ZipCode = "";
    string HomePhone = "";
    string WorkPhone = "";
    string CellPhone = "";
    string Email = "";
    string Website = "";
    cout << endl << endl;
    cout << "What category would you like to search under? \n";
    cout << "\t\t****************************\n";
    cout << "\t\t*                          *\n";
    cout << "\t\t*       (L)ast Name        *\n";
    cout << "\t\t*       (F)irst Name       *\n";
    cout << "\t\t*       (A)ddress          *\n";
    cout << "\t\t*       (C)ity             *\n";
    cout << "\t\t*       (S)tate            *\n";
    cout << "\t\t*       (Z)ipcode          *\n";
    cout << "\t\t*       (E)mail            *\n";
    cout << "\t\t*                          *\n";
    cout << "\t\t****************************\n";
    cin >> MenuChoice;
    //Validate the user's input to make sure it is a valid choice
    if(tolower(MenuChoice) !='l' && tolower(MenuChoice)!='f' && tolower(MenuChoice)!='e'
	                         && tolower(MenuChoice)!='a'&& tolower(MenuChoice)!='c' 
	                         && tolower(MenuChoice)!='s' && tolower(MenuChoice)!='z')
    {
	   cout << "\n\nInvalid choice.\n\n";
	   return;
    }
    cout << "\nWhat would you like to search for? ";
    cin >> SearchItem;
    ifstream InputFile;
    InputFile.open("addresses.dat", ios::in);
    //Check to see if the file exists
    if(InputFile.is_open()) 
    {
        InputFile >> DETECT;
	//Reset file pointer back to beginning of file
        InputFile.seekg(0);
	//Check to make sure the file is not empty
        if(DETECT != "") 
		{
                     //Go through the file until reaching the end
		  while(!InputFile.eof()) 
		  {                  
                          getline(InputFile, LastName, '#'); 
		          getline(InputFile, FirstName, '#');
                          getline(InputFile, Address, '#');
		          getline(InputFile, City, '#');
                          getline(InputFile, State, '#');
		          getline(InputFile, ZipCode, '#');
                          getline(InputFile, HomePhone, '#');
		          getline(InputFile, WorkPhone, '#');
                          getline(InputFile, CellPhone, '#');
		          getline(InputFile, Email, '#');
                          getline(InputFile, Website);
        
                          switch(tolower(MenuChoice))
			  {
	                       case 'l' : if(SearchItem == LastName)
				          { ShowIt = true;  break; }
	                       case 'f' : if(SearchItem == FirstName)
				          { ShowIt = true;  break; }
	                       case 'a' : if(SearchItem == Address)
				      { ShowIt = true;  break; }
	                       case 'c' : if(SearchItem == City)
				          { ShowIt = true;  break; }
	                       case 's' : if(SearchItem == State)
				      {     ShowIt = true;  break; }
                               case 'z' : if(SearchItem == ZipCode)
				  {     ShowIt = true;  break; }
       	                       case 'e' : if(SearchItem == Email)
				  {     ShowIt = true;  break; }
			  } //close switch statement
                             //Keep the output from repeating/printing an empty record if at end of file  
			  if(!InputFile.eof()) 
			  {
			       //If and only if the record holds a category that matches, show it
			       if(ShowIt == true) 
			       {
                                   cout << "\n\n-----------------Address Record "
				        << Counter << "-------------------\n";
				   cout << "First Name: " << FirstName << endl;  
                                   cout << "Last Name: " << LastName << endl;	                  
			           cout << "Address: " << Address << endl;
	                           cout << "City: " << City << endl;
		                   cout << "State: " << State << endl;
		                   cout << "Zip Code: " << ZipCode << endl;
		                   cout << "Phone (home): " << HomePhone << endl;
		                   cout << "Phone (work): " << WorkPhone << endl;
		                   cout << "Phone (cell): " << CellPhone << endl;
		                   cout << "Email: " << Email << endl;
		                   cout << "Website: " << Website << endl;
                                   cout << "---------------------End of Record---"
                                        << "-------------------\n\n";
				   Counter++;
			           ShowIt = false;  //set back to false until another match is found

			       } //close 4th "ShowIt" if
			  } //close 3rd "Do not print empty record" if
		  } // close while true loop
                  cout << "End of records.";
	} //close 2nd "if file is not empty" if
	else
	{
	     cout << "\n\nThere are no records to display.";
	}
	InputFile.close();
        
    } //close 1st "if file can be found" if
    else
    {
        cout << "Could not open the address book file." << endl;
    }
} //close function

//---------------------------------------------------------------------------------------------------------------------------






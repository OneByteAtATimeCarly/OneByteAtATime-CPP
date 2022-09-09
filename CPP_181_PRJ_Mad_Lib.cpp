//PRJ - MadLib - 2004 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
int SaveTheStory(string * StuffToWrite);
int LoadTheStory(string * StuffToRead);
void MakeTheStory(string * TheStory);
void MainMenu(char & choice, string * Story);

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     //The Globals 
     char KeepGoing = 'y';
     string Story;
     //Launch the menu
     while(KeepGoing != 'n')
     {
           MainMenu(KeepGoing, &Story);
     }
     cout << "\nClosing the program - exiting main().\n\n";
} //close main() function

void main() {
     //The Globals 
     char KeepGoing = 'y';
     string Story;
     //Launch the menu
     while(KeepGoing != 'n')
     {
           MainMenu(KeepGoing, &Story);
     }
     cout << "\nClosing the program - exiting main().\n\n";

} //close main() function

//---------------------------------------------------------------------------------------------------------------------------

void MainMenu(char & choice, string * AStory)
{
     cout << endl;
     cout << "\t********************************************************\n";
     cout << "\t*    MAD LIB 1.0  -  Main Menu  - 2004 C. Germany      *\n";
     cout << "\t********************************************************\n";
     cout << "\t*                                                      *\n";
     cout << "\t*     (Q)uit the Game                                  *\n";
     cout << "\t*     (P)lay Mad Lib                                   *\n";
     cout << "\t*     (S)ave your Mad Lib                              *\n";
     cout << "\t*     (V)iew a Mad Lib previously created              *\n";
     cout << "\t*                                                      *\n";
     cout << "\t********************************************************\n";
     cout << endl;

     cout << "\tWhat would you like to do? ";
     cin >> choice;

     switch(tolower(choice)) 
     {
	    case 'q': cout << "\nExiting menu system ...";
		      choice = 'n';
		      break;
            case 'p': cout << "Starting the game!";
		      MakeTheStory(AStory);
		      break;
	    case 's': cout << "Saving the Mad Lib.";
		      SaveTheStory(AStory);			         
		      break;
	    case 'v': cout << "Loading the Mad Lib.";
		      LoadTheStory(AStory);
		      break;
            default: cout << "Invalid input.";
		     break;

	} //close switch

} //close MainMenu() function

//---------------------------------------------------------------------------------------------------------------------------

void MakeTheStory(string * TheStory) 
{   
     int x = 0;
     const int NumWords = 7;
     string UserSays[NumWords];
     string ComputerSays[NumWords] = {

                             "One day, ", 
                             " was tip-toing through the \ntulips when she saw a ",
                             ".  This was because the folks \nat Microsoft were ",
                             " into the sky again and \nagain. The ",
                             " jumped off of a cliff \nbecause the ",
                             " couldn\'t pat its head and rub its \ntummy at the same time. The ",
                             " ran \noff holding hands with "
                             };
     string Hints[NumWords] = {
	                         "A female person's name: ",
			         "An object: ",
			         "An infinitive verb: ",
				 "An object or animal: ",
				 "An object: ",
				 "An object: ",
				 "A male person's name: "
                              };
						  
     //Clear the screen
     system("CLS");
     cout.flush();
     //Get the user to input some appropriate words
     for(x = 0; x < NumWords; x++)
     {
         cout << Hints[x];
	 cin >> UserSays[x];
	 cout << endl;
     }
     //Concatenate the arrays of strings with an accumulator
     for(x = 0; x < NumWords; x++)
     {
         *TheStory = *TheStory + ComputerSays[x] + UserSays[x];        
     }
     
     //Now end the story with a period!
     *TheStory = *TheStory + ".\n\n";  
     
     //Display it to the screen
     cout << endl << endl << *TheStory << endl << endl;

} //close PlayTheGame() function

//---------------------------------------------------------------------------------------------------------------------------

int SaveTheStory(string * StuffToWrite)
{	 
    //Write the story to a file
    string FileName = "";
    string Extension = ".txt";
    system("CLS");
    cout.flush();
    cout << endl << "Enter name of file to save: ";
    cin >> FileName;
    FileName = FileName + Extension;
    const char * TheFile = FileName.c_str();
    ofstream OutputFile;
    OutputFile.open(TheFile, ios::out);
    if(!OutputFile)
    {
       cout << "Unable to open the file for writing.\n";
       return(1);
    }
    OutputFile << *StuffToWrite;
    OutputFile.close();
    return 0;

} //close SaveTheStory() function

//---------------------------------------------------------------------------------------------------------------------------

int LoadTheStory(string * StuffToRead)
{
    char OneLetterAtATime;
    string FileName = "";
    string Extension = ".txt";
    system("CLS");
    cout.flush();
    cout << endl << "Enter name of file to load: ";
    cin >> FileName;
    FileName = FileName + Extension;
    const char * TheFile = FileName.c_str();
    ifstream InputFile;
    InputFile.open(TheFile, ios::in);
 
    if(!InputFile)
    {
        cout << "Unable to open the file for reading.\n";
        return(1);
    }

    cout << "\n*************Here's the contents of the file:*************\n\n";
    while(InputFile.get(OneLetterAtATime))
    {
	  cout << OneLetterAtATime;
    }

    cout << "\n*************End of file contents.*************\n";
    InputFile.close();
    return 0;

} //close ReadFile() function

//---------------------------------------------------------------------------------------------------------------------------

void MainMenu(char & choice, string * AStory)
{
     cout << endl;
     cout << "\t********************************************************\n";
     cout << "\t*    MAD LIB 1.0  -  Main Menu  - 2004 C. Germany      *\n";
     cout << "\t********************************************************\n";
     cout << "\t*                                                      *\n";
     cout << "\t*     (Q)uit the Game                                  *\n";
     cout << "\t*     (P)lay Mad Lib                                   *\n";
     cout << "\t*     (S)ave your Mad Lib                              *\n";
     cout << "\t*     (V)iew a Mad Lib previously created              *\n";
     cout << "\t*                                                      *\n";
     cout << "\t********************************************************\n";
     cout << endl;

     cout << "\tWhat would you like to do? ";
     cin >> choice;

     switch(tolower(choice)) 
     {
	    case 'q': cout << "\nExiting menu system ...";
		      choice = 'n';
		      break;
            case 'p': cout << "Starting the game!";
		      MakeTheStory(AStory);
		      break;
	    case 's': cout << "Saving the Mad Lib.";
		      SaveTheStory(AStory);			         
		      break;
	    case 'v': cout << "Loading the Mad Lib.";
		      LoadTheStory(AStory);
		      break;
            default: cout << "Invalid input.";
		     break;

	} //close switch

} //close MainMenu() function

//---------------------------------------------------------------------------------------------------------------------------

void MakeTheStory(string * TheStory) 
{   
     int x = 0;
     const int NumWords = 7;
     string UserSays[NumWords];
     string ComputerSays[NumWords] = {

                             "One day, ", 
                             " was tip-toing through the \ntulips when she saw a ",
                             ".  This was because the folks \nat Microsoft were ",
                             " into the sky again and \nagain. The ",
                             " jumped off of a cliff \nbecause the ",
                             " couldn\'t pat its head and rub its \ntummy at the same time. The ",
                             " ran \noff holding hands with "
                             };
     string Hints[NumWords] = {
	                         "A female person's name: ",
			         "An object: ",
			         "An infinitive verb: ",
				 "An object or animal: ",
				 "An object: ",
				 "An object: ",
				 "A male person's name: "
                              };
						  
     //Clear the screen
     system("CLS");
     cout.flush();
     //Get the user to input some appropriate words
     for(x = 0; x < NumWords; x++)
     {
         cout << Hints[x];
	 cin >> UserSays[x];
	 cout << endl;
     }
     //Concatenate the arrays of strings with an accumulator
     for(x = 0; x < NumWords; x++)
     {
         *TheStory = *TheStory + ComputerSays[x] + UserSays[x];        
     }
     
     //Now end the story with a period!
     *TheStory = *TheStory + ".\n\n";  
     
     //Display it to the screen
     cout << endl << endl << *TheStory << endl << endl;

} //close PlayTheGame() function

//---------------------------------------------------------------------------------------------------------------------------

int SaveTheStory(string * StuffToWrite)
{	 
    //Write the story to a file
    string FileName = "";
    string Extension = ".txt";
    system("CLS");
    cout.flush();
    cout << endl << "Enter name of file to save: ";
    cin >> FileName;
    FileName = FileName + Extension;
    const char * TheFile = FileName.c_str();
    ofstream OutputFile;
    OutputFile.open(TheFile, ios::out);
    if(!OutputFile)
    {
       cout << "Unable to open the file for writing.\n";
       return(1);
    }
    OutputFile << *StuffToWrite;
    OutputFile.close();
    return 0;

} //close SaveTheStory() function

//---------------------------------------------------------------------------------------------------------------------------

int LoadTheStory(string * StuffToRead)
{
    char OneLetterAtATime;
    string FileName = "";
    string Extension = ".txt";
    system("CLS");
    cout.flush();
    cout << endl << "Enter name of file to load: ";
    cin >> FileName;
    FileName = FileName + Extension;
    const char * TheFile = FileName.c_str();
    ifstream InputFile;
    InputFile.open(TheFile, ios::in);
 
    if(!InputFile)
    {
        cout << "Unable to open the file for reading.\n";
        return(1);
    }

    cout << "\n*************Here's the contents of the file:*************\n\n";
    while(InputFile.get(OneLetterAtATime))
    {
	  cout << OneLetterAtATime;
    }

    cout << "\n*************End of file contents.*************\n";
    InputFile.close();
    return 0;

} //close ReadFile() function

//---------------------------------------------------------------------------------------------------------------------------






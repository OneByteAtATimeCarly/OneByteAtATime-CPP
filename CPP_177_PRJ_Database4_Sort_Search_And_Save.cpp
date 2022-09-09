//Database 3 - 2008 .Net Console App - C. S. Germany

//01/16/2010 C. S. Germany - Visual Studio 2008 .Net ASCII File Access
/*
    Notes: 1. Select "File" -> "New" -> "Project" -> "Visual C++".
           2. Select"Win32" -> "Win32 Console Project".
	       3. Rt-click project, select "properties, 
	          select "Common Language Runtime support",
	          select "Common Language Runtime Support (/clr)"
	          to incorporate the .Net runtime instead of MFC.
    Some functions are prototyped to take array arguments but
	defined to take pointers to illustrate that a pointer to
	the first element of an array can be used to access the
	entire array.
*/

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#using <mscorlib.dll>
using namespace System;
using namespace System::IO

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void PAUSE();
void LoadData();
void SaveData();
void DisplayMenu();
void DisplayTotal(double r[]);
void DisplayAverage(double r[]);
void DisplayHigh(double r[]);
void DisplayLow(double r[]);

//---------------------------------------------------------------------------------------------------------------------------

const int MAXSIZE = 12;
int RecordCount = 0;
int sub = 0;
double * Array_Of_Doubles = new double[MAXSIZE];

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	//Fill array with Array_Of_Doubles amounts from text file
	LoadData();
    PAUSE();
    DisplayMenu();
	
	Console::WriteLine("\n\n\tExiting program.");
	PAUSE();
	return 0;	
}

//---------------------------------------------------------------------------------------------------------------------------

void PAUSE()
{
	Console::WriteLine("\tPAUSED: Press ENTER to continue.");
	Console::ReadLine();
	System::Console::Beep();
	System::Console::Clear();
}

//---------------------------------------------------------------------------------------------------------------------------

void SaveData()
{
    StreamWriter ^ OutputFile;
	bool CreatedIt = false;
    String ^ DATA = "NOTHING";
	sub = 0;
	//try opening the file
	try
	{
		OutputFile = gcnew StreamWriter("Number_DATA.txt");
		Console::WriteLine("\nMade it!");
		CreatedIt = true;
	}
	catch(IOException ^ ex)
	{
		Console::WriteLine("\nCouldn't create file...");
		Console::WriteLine(ex->Message);
		CreatedIt = false;
	}
	//only if the file was opened successfully
	if (CreatedIt == true)
	{      
	   Console::WriteLine("\n----------Enter Values to Store----------");
	   Console::WriteLine("                 Q = QUIT");
	   while(DATA[0] != 'q')
	   {				    
			Console::Write("\nEnter value for record {0} ", Convert::ToString(sub+1));
            DATA = Console::ReadLine();
            DATA = DATA->ToLower();
			if(DATA[0] != 'q') 
			{ 
				//See if 1st character is a number
				if(System::Char::IsNumber(DATA[0])) 
				{  
				   OutputFile->WriteLine(DATA);  
				   sub = sub + 1;
				}
				else 
				{ 
				   Console::WriteLine("\n\tNon numerical values are not allowed!"); 
				}
			}
			
		}//end while
		OutputFile->Close();
        Console::WriteLine("\n\n----------Closing file.----------\n\n");
	}//close if
}

//---------------------------------------------------------------------------------------------------------------------------

//Can take a pointer to a double to accept entire array of doubles

void LoadData()
{
    StreamReader ^ InputFile;
	bool FoundIt = false;
    sub = 0;
	RecordCount = 0;  //reset each time
	//try opening the file
	try
	{
		InputFile = gcnew StreamReader("Number_DATA.txt");
		Console::WriteLine("\nFound it!");
		FoundIt = true;
	}
	catch(IOException ^ ex)
	{
		Console::WriteLine("\nWe have a situation here...");
		Console::WriteLine(ex->Message);
		FoundIt = false;
	}
	//only if the file was opened successfully
	if (FoundIt == true)
	{      
	   Console::WriteLine("\n----------Opening file and reading.----------");
       while(InputFile->Peek() != -1 && sub < MAXSIZE)
	   {		
			//assign the number to the array		    
			Array_Of_Doubles[sub] = Convert::ToDouble(InputFile->ReadLine());
			Console::Write("\nValue of subscript {0} ", Convert::ToString(sub));
			Console::Write(" = {0}", Convert::ToString(Array_Of_Doubles[sub]));
			//update accumulator and access Array subscript to obtain sentinel value
			sub = sub + 1;
			RecordCount++;
			
		}//end while
		InputFile->Close();
        Console::WriteLine("\n\n----------Closing file.----------\n\n");
	}//close if
}//close function

//---------------------------------------------------------------------------------------------------------------------------

void DisplayMenu()
{
     String ^ ANSWER = "GO";
	 while(ANSWER[0] != 'q')
	 {
	    Console::WriteLine("\n\t---------------Main Menu---------------");
	    Console::WriteLine("\t(T)otal of All Values");
	    Console::WriteLine("\t(A)verage of All Values");
	    Console::WriteLine("\t(H)ighest of All Values");
	    Console::WriteLine("\t(L)owest of All Values");
		Console::WriteLine("\t(S)ave Data");
        Console::WriteLine("\t(D)isplay Loaded Data");
        Console::WriteLine("\t(Q)uit");
        Console::WriteLine("\t---------------------------------------");
		Console::Write("\n\t");
	    ANSWER = Console::ReadLine();
		ANSWER = ANSWER->ToLower();
					
		switch(ANSWER[0])
	    {
            case 't' : DisplayTotal(Array_Of_Doubles);
		 	           break;
		    case 'h' : DisplayHigh(Array_Of_Doubles);
				       break;
		    case 'l' : DisplayLow(Array_Of_Doubles);
				       break;
		    case 'a' : DisplayAverage(Array_Of_Doubles);
				       break;
			case 's' : SaveData();
				       break;
            case 'd' : LoadData();
				       break;
			case 'q' : break;
		    default :  Console::WriteLine("\n\tGet REAL!");
			           break;
	    }//close switch
	}//close loop
}//close function

//---------------------------------------------------------------------------------------------------------------------------

void DisplayTotal(double * r)
{
	//declare accumulator variable
	double total = 0.0;
	//accumulate Array_Of_Doubles amounts, then display total
	for (int x = 0; x < RecordCount; x = x + 1)
	{ 
		total = total + r[x];
	}
	Console::WriteLine("\n\tTotal of all numbers = {0}.", 
		               Convert::ToString(total));
	Console::WriteLine();
}
//For you to complete on your own.

//---------------------------------------------------------------------------------------------------------------------------

void DisplayAverage(double * r)
{
	 //declare accumulator variable
	 double AVG = 0.0;
	 //accumulate Array_Of_Doubles amounts, then display total
	 for (int x = 0; x < RecordCount; x = x + 1)
	 { 
 		AVG = AVG + r[x];
	 }
     AVG = AVG / RecordCount;
	 Console::WriteLine("\n\tAverage of all numbers = {0}.", 
		                Convert::ToString(AVG));
	 Console::WriteLine();      
}

//---------------------------------------------------------------------------------------------------------------------------

void DisplayHigh(double * r)
{
	 //declare accumulator variable
	 double HIGH = 0.0;
	 //accumulate Array_Of_Doubles amounts, then display total
	 for (int x = 0; x < RecordCount; x = x + 1)
	 { 
		if(HIGH < r[x])
		{
			Console::Write("\nValue for number {0}=", Convert::ToString(x+1));
			Console::Write("{0} ", Convert::ToString(r[x]));
			Console::Write("and IS HIGHER than HIGH which is {0}.",
				           Convert::ToString(HIGH));
			HIGH = r[x];
		}
		else
		{
			Console::Write("\nValue for number {0}=", Convert::ToString(x+1));
			Console::Write("{0} ", Convert::ToString(r[x]));
			Console::Write("and is NOT HIGHER than HIGH which is {0}.",
				           Convert::ToString(HIGH));
		}
	 }
	 Console::WriteLine("\n\n\tHighest number = {0}.", 
		                Convert::ToString(HIGH));
	 Console::WriteLine(); 
}

//---------------------------------------------------------------------------------------------------------------------------

void DisplayLow(double * r)
{
	 //declare accumulator variable
	 double LOW = r[0];
	 //accumulate Array_Of_Doubles amounts, then display total
	 for (int x = 0; x < RecordCount; x = x + 1)
	 { 
	 	if(r[x] > LOW)
	 	{
            Console::Write("\nValue for number {0}=", Convert::ToString(x+1));
			Console::Write("{0} ", Convert::ToString(r[x]));
			Console::Write("and is NOT LOWER than LOW which is {0}.",
				           Convert::ToString(LOW));
		}
		else
		{	
		   	Console::Write("\nValue for number {0}=", Convert::ToString(x+1));
			Console::Write("{0} ", Convert::ToString(r[x]));
			Console::Write("and IS LOWER than LOW which is {0}.",
				           Convert::ToString(LOW));
			LOW = r[x];
		}
	 }
	 Console::WriteLine("\n\n\tLowest number = {0}.", 
		                Convert::ToString(LOW));
	 Console::WriteLine();  
}

//---------------------------------------------------------------------------------------------------------------------------






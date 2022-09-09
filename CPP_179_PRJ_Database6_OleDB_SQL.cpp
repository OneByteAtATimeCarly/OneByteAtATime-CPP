//Database 5 - 2008 OleDB SQL Database - C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

/*
    Notes: 1. Select "File" -> "New" -> "Project" -> "Visual C++".
           2. Select"Win32" -> "Win32 Console Application".
	       3. Rt-click project, select "properties, 
	          select "Common Language Runtime support",
	          select "Common Language Runtime Support (/clr)"
	          to incorporate the .Net runtime instead of MFC. 
           4. This project uses SQL. SQL is an acronym that stands for:
	          "Structured Query Language". It is a simple database language.
	       5. This project uses OleDb to access an Access database file that
	          you will create. OleDb = Object Linking and Embedding Database.
		      Access database files have an extension of ".mdb".	    
*/

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#using <mscorlib.dll>
#using <System.dll>
#using <System.data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void PAUSE();
void DisplayMenu(OleDbConnection ^ DB);
void DisplayDatabase(OleDbConnection ^ DB, String ^ SQL);
void BasicRead(OleDbConnection ^ DB);
void Sort(OleDbConnection ^ DB);
void Find(OleDbConnection ^ DB);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	
    OleDbConnection ^ Database_Connection = gcnew OleDbConnection();
    Database_Connection->ConnectionString = 
	"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=inventory.mdb";
    DisplayMenu(Database_Connection);
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

void DisplayMenu(OleDbConnection ^ DB)
{
     String ^ ANSWER = "GO";
	 while(ANSWER[0] != 'q')
	 {
	    Console::WriteLine("\n\t---------------Main Menu---------------");
        Console::Write("\n\t(B)asic Read Operation");
        Console::Write("\n\t(S)ort Operation");
        Console::Write("\n\t(F)ind Operation");
		Console::Write("\n\t(Q)uit\n\n");
        Console::WriteLine("\t---------------------------------------");
		Console::Write("\n\t");
	    ANSWER = Console::ReadLine();
		ANSWER = ANSWER->ToLower();
					
		switch(ANSWER[0])
	    {
		    case 'b' : BasicRead(DB); break;
		    case 's' : Sort(DB); break;
            case 'f' : Find(DB); break;
			case 'q' : break;
		    default :  Console::WriteLine("\n\tGet REAL!");
			           break;
	    }//close switch
	}//close loop
}//close function

//---------------------------------------------------------------------------------------------------------------------------

void DisplayDatabase(OleDbConnection ^ DB, String ^ SQL)
{
	 try
	 {
         DB->Open();
		 //Create Command object to get information from database via SQL
		 OleDbCommand ^ Command_Inventory = gcnew OleDbCommand(SQL,DB);
         //Create Reader object to get records and display them
		 OleDbDataReader ^ Read_Inventory = Command_Inventory->ExecuteReader();
         int COUNTER = 1;
		 while(Read_Inventory->Read() == true)
		 {
			Console::Write("\t-------------------------------------------");
			Console::Write("\n\tReading RECORD # ");
			Console::Write(Convert::ToString(COUNTER));
			Console::Write(":\n");
			//ID
			Console::Write("\n\tField Type = ");
			Console::Write(Read_Inventory->GetFieldType(0));
            Console::Write("\n\tField Name = ");
			Console::Write(Read_Inventory->GetName(0));
            Console::Write("\n\tField Value = ");
			Console::Write(Read_Inventory->GetInt32(0));
			
			//Name
			Console::Write("\n\n\tField Type = ");
			Console::Write(Read_Inventory->GetFieldType(1));
			Console::Write("\n\tField Name = ");
			Console::Write(Read_Inventory->GetName(1));
			Console::Write("\n\tValue = ");
			Console::Write(Read_Inventory->GetString(1));
			//Quantity
			Console::Write("\n\n\tField Type = ");
			Console::Write(Read_Inventory->GetFieldType(2));
			Console::Write("\n\tField Name = ");
			Console::Write(Read_Inventory->GetName(2));
			Console::Write("\n\tValue = ");
            Console::Write(Read_Inventory->GetInt32(2));
			//Price
			Console::Write("\n\n\tField Type = ");
			Console::Write(Read_Inventory->GetFieldType(3));
			Console::Write("\n\tField Name = ");
			Console::Write(Read_Inventory->GetName(3));
            Console::Write("\n\tValue = $");
			Console::Write(Read_Inventory->GetDecimal(3));
			Console::WriteLine("\n\t-------------------------------------------\n\n");
			COUNTER++;
		}
        Read_Inventory->Close();
        DB->Close();
		
	}
	catch(OleDbException ^ A_PROBLEM)
	{
		Console::WriteLine(A_PROBLEM->Message);
	}
	
}

//---------------------------------------------------------------------------------------------------------------------------

void BasicRead(OleDbConnection ^ DB)
{
     Console::WriteLine("\n\n\t----------BASIC READ FUNCTION----------");
     String ^ ACTION = "SELECT ID, Name, Quantity, Price FROM Inventory";
     DisplayDatabase(DB,ACTION);
}

//---------------------------------------------------------------------------------------------------------------------------

void Sort(OleDbConnection ^ DB)
{
	 //Note: By default SQL commands sort in ASCENDING order (least to greatest)
	 //Use the keyword "DESC" to sort in DESCENDING order. Example:
	 //SQL = "SELECT ID, Name, Quantity, Price FROM Inventory ORDER BY ID DESC"
	 String ^ ACTION = " ";
     String ^ CHOICE = " ";
	 Console::WriteLine("\n\n\t----------DATABASE SORT FUNCTION----------");
	
     while(CHOICE[0] != 'x')
	 {
		Console::Write("\n\t----------SORT MENU: How Do You Want Records Sorted?----------\n");
        Console::Write("\n\t(I)D of Product");
        Console::Write("\n\t(N)ame of Product");
        Console::Write("\n\t(Q)uantity of Product");
		Console::Write("\n\t(P)rice of Product");
        Console::Write("\n\tE(x)it Search Function\n\n\t");
		CHOICE = Console::ReadLine();
		CHOICE = CHOICE->ToLower();
        switch(CHOICE[0])
		{
		     case 'i' : ACTION = "SELECT ID, Name, Quantity, Price FROM Inventory ORDER BY ID";
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
		     case 'n' : ACTION = "SELECT ID, Name, Quantity, Price FROM Inventory ORDER BY Name";
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
             case 'q' : ACTION = "SELECT ID, Name, Quantity, Price FROM Inventory ORDER BY Quantity";
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
		     case 'p' : ACTION = "SELECT ID, Name, Quantity, Price FROM Inventory ORDER BY Price";
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
             case 'x' : break;
			 default: Console::WriteLine("\n\tInvalid option."); break;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------

void Find(OleDbConnection ^ DB)
{
	 String ^ ACTION = " ";
     String ^ CHOICE = " ";
     Console::WriteLine("\n\n\t----------FIND FUNCTION----------");
	
     while(CHOICE[0] != 'x')
	 {
		 Console::Write("\n\t----------SEARCH MENU: What Are You Looking For?----------\n");
         Console::Write("\n\t(I)D of Product");
         Console::Write("\n\t(N)ame of Product");
         Console::Write("\n\t(Q)uantity of Product");
		 Console::Write("\n\t(P)rice of Product");
         Console::Write("\n\tE(x)it Search Function\n\n\t");
		 CHOICE = Console::ReadLine();
		 CHOICE = CHOICE->ToLower();
        switch(CHOICE[0])
		{
		     case 'i' : Console::Write("\n\tEnter the product ID you are looking for: ");
			            CHOICE = Console::ReadLine();
						ACTION = String::Concat("SELECT ID, Name, Quantity, Price FROM Inventory WHERE ID = ",CHOICE);
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
		     case 'n' : Console::Write("\n\tEnter the product NAME you are looking for: ");
			            CHOICE = Console::ReadLine();
				        ACTION = String::Concat("SELECT ID, Name, Quantity, Price FROM Inventory WHERE Name = '",CHOICE);
				        ACTION = String::Concat(ACTION,"'");
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
             case 'q' : Console::Write("\n\tEnter the product QUANTITY you are looking for: ");
			            CHOICE = Console::ReadLine();
				        ACTION = String::Concat("SELECT ID, Name, Quantity, Price FROM Inventory WHERE Quantity = ",CHOICE);
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
		     case 'p' : Console::Write("\n\tEnter the product PRICE you are looking for: ");
			            CHOICE = Console::ReadLine();
				        ACTION = String::Concat("SELECT ID, Name, Quantity, Price FROM Inventory WHERE Price = ",CHOICE);
                        DisplayDatabase(DB,ACTION);
				        CHOICE = "~";  //Invalidate CHOICE
				        break;
             case 'x' : break;
			 default: Console::WriteLine("\n\tInvalid option."); break;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------





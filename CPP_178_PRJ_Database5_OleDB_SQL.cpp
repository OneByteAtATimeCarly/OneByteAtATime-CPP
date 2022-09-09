//Database 4 - 2008 OleDB SQL Database - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

//01/16/2010 C. S. Germany - Visual Studio 2008 OleDB Database 1
/*
    Notes: 1. Select "File" -> "New" -> "Project" -> "Visual C++".
           2. Select"Win32" -> "Win32 Console Application".
	       3. Rt-click project, select "properties, 
	          select "Common Language Runtime support",
	          select "Common Language Runtime Support (/clr)"
	          to incorporate the .Net runtime instead of MFC. 
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

int main()
{
	OleDbConnection ^ Database_Connection = gcnew OleDbConnection();
	//Example 1: ABSOLUTE path Connection String
	//Database_Connection->ConnectionString = 
	//"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=d:\\2008_Projects\\DOT_NET_Console_Apps\\
        //Database_MDB_1\\DATABASE1\\DATABASE1\\Inventory.mdb";
    //Example 2: RELATIVE path Connection String
    Database_Connection->ConnectionString = 
	"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=Inventory.mdb";
	try
	{
         Database_Connection->Open();
		 //Create Command object to get information from database via SQL
		 String ^ sql = "SELECT ID, Name, Quantity, Price FROM Inventory";
		 OleDbCommand ^ Command_Inventory = gcnew OleDbCommand(sql,Database_Connection);
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
        Database_Connection->Close();
	}//close try
	catch(OleDbException ^ A_PROBLEM)
	{
		Console::WriteLine(A_PROBLEM->Message);
	}
    
	Console::WriteLine("\n\n\t");
    Console::WriteLine("Press ENTER to continue.");
	Console::ReadLine();
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------






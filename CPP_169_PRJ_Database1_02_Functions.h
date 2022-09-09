//Project - Database1 - 02 - Functions - 2004 C. S. Germany
//File 2 of 3 - Database1 Functions - ©2004 C. S. Germany
//Header file


//---------------------------------------------------------------------------------------------------------------------------

void ListEmployeeIDs(Employee * Comp, int & Num) {
	   //List The Employee IDs Available:
	   cout << "\n\n------------------------------------------\n";
	   cout << "Valid employee IDs are: \n\n";

           for(int x = 0;x < Num; x++)
	   { 
	          //Need to offset for the fencepost by adding 1
	        cout << (Comp[x].GetEmpID()) << " ";
	   }

           cout << "\n------------------------------------------\n\n";
}

//---------------------------------------------------------------------------------------------------------------------------

bool VerifyPassword() {
     cout.flush();
     system("CLS");
     int ManagerID;
     string Password;
     cout << "\n   To add employees to this database, you must be a department manager\n"
          << "   with a valid password and manager ID.";
     cout << "\n\n   Please enter your manager ID: ";
     cin >> ManagerID;
     if(ManagerID > 99 && ManagerID < 105) 
     {
         cout << "\n\n   Please enter your password (case sensitive): ";
         cin >> Password;
	 cout << "\n\n   You entered: " << Password << ".\n";
         switch(ManagerID) {
               case 100: if(Password == "blue") 
                         {
		            cout << "\n   Ok., manager " << ManagerID 
		                 << ", your password is valid!\n";
		            return true; 
                         }
	                 break;

               case 101: if(Password == "red") 
                         {
                            cout << "\n   Ok., manager " << ManagerID 
                                 << ", your password is valid!\n"; 
         		    return true; 
                         }
			 break;

	       case 102: if(Password == "green") 
                         {
                            cout << "\n   Ok., manager " << ManagerID 
			         << ", your password is valid!\n";
			    return true; 
                         }
			 break;

	       case 103: if(Password == "yellow") 
                         {
			    cout << "\n   Ok., manager " << ManagerID 
			         << ", your password is valid!\n";
			    return true; 
                         }
			 break; 

	       case 104: if(Password == "white") 
                         {
			    cout << "\n   Ok., manager " << ManagerID 
			         << ", your password is valid!\n";
			    return true; 
                         }
			 break;

	       default: cout << "Invalid.\n\n";
			break;
		 } //close switch
	 } //close if
	 else { cout << "   Invalid Manager ID!\n\n"; }

	 return false;

} //close function

//---------------------------------------------------------------------------------------------------------------------------

void EditEmployeeInformation(Employee * ACompany, int & NumEmployees) {
     int key = 0;  
     cout << "\n   Welcome!  You may enter new Employee information below:" << endl;
     ListEmployeeIDs(ACompany, NumEmployees);
     cout << "Which employee would you like to edit?  Enter the key value: ";
     cin >> key;
     //Check for valid ID, grater than 0 and one less than NumEmp because of fencepost
     if(key > 0 && key <= NumEmployees) 
	{  ACompany[key-1].EditEmployee(); }
     else { cout << "\nI am sorry, that is an invalid eployee ID.\n\n"; }
} // close function

//---------------------------------------------------------------------------------------------------------------------------

void DisplayEmployeeInformation(Employee * ACompany, int & NumEmployees) {
   
     int key = 0;

     cout << "\n   Welcome!  You may display information for"
          << "the employees listed below:" << endl;
     ListEmployeeIDs(ACompany, NumEmployees);
     cout << "Which employee would you like to view?  Enter the key value: ";
     cin >> key;
     //Check for valid ID, grater than 0 and one less than NumEmp because of fencepost
     if(key > 0 && key <= NumEmployees)
	{  ACompany[key-1].DisplayEmployee(); }
     else { cout << "\nI am sorry, that is an invalid eployee ID.\n\n"; }
} // close function

//---------------------------------------------------------------------------------------------------------------------------

void DeleteEmployee(Employee * ACompany, int & NumEmployees) {

     int key = 0; 
     cout << "\n Warning! You are about to delete an employee record!" << endl;

     ListEmployeeIDs(ACompany, NumEmployees);

     cout << "Which employee record would you like to delete? Enter the key value: ";
     cin >> key;

     //Check for valid ID, grater than 0 and one less than NumEmp because of fencepost
     if(key > 0 && key <= NumEmployees) 
     { 
           ACompany[key-1].Initialize(); 
     }

     else { cout << "\nI am sorry, that is an invalid eployee ID.\n\n"; }

} // close function

//---------------------------------------------------------------------------------------------------------------------------

void MainMenu(char & Continue, Employee * Company, int & NumEmp) {
     char MenuChoice;
     cout << "\n\n";
     cout << "\t*************************************************\n"
          << "\t*                Database Menu                  *\n" 
          << "\t*************************************************\n"
          << "\t*                                               *\n"
          << "\t*      E = Edit Employee Information            *\n"
          << "\t*      D = Display Employee Information         *\n"
          << "\t*      R = Erase Employee Information           *\n"
          << "\t*      A = Add Employee to Database             *\n"
          << "\t*      P = Populate Database (new district)     *\n"
          << "\t*      X = Exit Menu Function                   *\n"
          << "\t*                                               *\n"
          << "\t*************************************************\n";
     cout << "\n\nEnter a selection: ";
     cin >> MenuChoice;
     //Below, "tolower" transfroms a char to lowercase.  
     switch(tolower(MenuChoice)) 
     {
          case 'e' : cout << "\nEdit Employee Information.\n";
		     EditEmployeeInformation(Company, NumEmp);
	             break;
          case 'd' : cout << "\nDisplay Employee Information\n";
		     DisplayEmployeeInformation(Company, NumEmp);			        
	             break;

          case 'r' : cout << "Remove Employee.";
                     DeleteEmployee(Company, NumEmp);
	 	     break;
          case 'p' : cout << "Populating database for a new district.";
 		     break;
          case 'x' : cout << "Exiting database menu...\n\n";
		     Continue = 'q';
 	             break;
          default :  cout << "Invalid response...\n\n";
    		     break;

     } //close switch statement
} //close function

//---------------------------------------------------------------------------------------------------------------------------

//This stuff below is just junk for demonstrations and debugging tutorials.
void TestStuff() {
     char MoveOn;
     //Object test
     Employee Newbie;
     Newbie.SetFirstName("Charles");
     cout << "\n" << Newbie.GetFirstName() << "\n";
     Manager Buffy;
     Buffy.SetFirstName("Buffy");
     cout << "\nManager object named: " << Buffy.GetFirstName() << "\n";
     Buffy.setDesc("Vampire Slayer");
     cout << "Buffy Description: " << Buffy.getDesc() << endl;
     cout << "\n\n\nType C followed by return to continue.  ";
     cin >> MoveOn;

}

//---------------------------------------------------------------------------------------------------------------------------

//The function below is no longer used.  It was a precursor introduction to static member data.
//We are now implementing inline in our constructor what this function used to do.
void AssignUniqueIDs(Employee * ACompany, int & NumEmployees) {
     //Note: This should only get called ONCE, unless there is a new database.
     int key = 1;
     for(int x = 0; x < NumEmployees; x++)
     {	
                ACompany[x].SetEmpID(key);
		ACompany[x].SetFirstName("NewEmployeeFirst");
		ACompany[x].SetLastName("NewEmployeeLast");
		ACompany[x].SetJobDescription("NewEmployeeDescription");
                key = key + 1;
     }    
}

//---------------------------------------------------------------------------------------------------------------------------





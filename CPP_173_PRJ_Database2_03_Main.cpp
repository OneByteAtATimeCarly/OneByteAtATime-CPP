//Project - Database2 - 03 - Main File - 2004 C. S. Germany
//File 3 of 3 - Database2 - 03 - Main File - ©2004 C. S. Germany


//-------------------------------------------------------------------------------------------------------------------------------

#include "CPP_171_PRJ_Database2_01_Classes.h"
#include "CPP_172_PRJ_Database2_02_Functions.h"

//-------------------------------------------------------------------------------------------------------------------------------

void main()
{
     int NumEmps = 0;
      //Set sentinel value 
     char Continue = 'z';
     //Stuff to happen only once
     cout << "Enter the number of employees in your company: ";
     cin >> NumEmps;
     //We need to make sure they enter something valid 
     if(NumEmps > 0 && NumEmps < 500) 
     {
           Employee * TheCompany = new Employee[NumEmps];

               //Stuff to keep happening until user selects exit
           while(Continue != 'q') 
           {
                 MainMenu(Continue, TheCompany, NumEmps);

           } //end while true loop

           //Now that we're done, let's clean up our array of Employee objects on the heap.
           delete [] TheCompany;
           TheCompany = 0;
     }

     else 
     { 
        cout << "Sorry, you must enter a whole number integer value for your database."; 
     }

     cout << "\nExiting program...\n\n";

}  //close main()

//---------------------------------------------------------------------------------------------------------------------------





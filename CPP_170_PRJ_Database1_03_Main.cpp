//Project - Database1 - 03 - Main File - 2004 C. S. Germany
//File 3 of 3 - Database1 Main File - ©2004 C. S. Germany
//CPP file


//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_168_PRJ_Database1_01_Classes.h"
#include "CPP_169_PRJ_Database1_02_Functions.h"

//-------------------------------------------------------------------------------------------------------------------------------
void main()
{
     int NumEmps = 0;
      //Set sentinel value 
     char Continue = 'z';
     //Stuff to happen only once
     cout << "Enter the number of employees in your company: ";
     cin >> NumEmps;
     Employee * TheCompany = new Employee[NumEmps];

       //Stuff to keep happening until user selects exit
     while(Continue != 'q') 
     {
           MainMenu(Continue, TheCompany, NumEmps);

     } //end while true loop

     cout << "\nExiting program...\n\n";

     //Now that we're done, let's clean up our array of Employee objects on the heap.
     delete [] TheCompany;
     TheCompany = 0;

}  //close main()

//---------------------------------------------------------------------------------------------------------------------------







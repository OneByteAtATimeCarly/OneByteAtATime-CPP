//PRJ - Database - Binary File Storage and Access - MFC GUI App - 2004 - C. S. Germany
//File 3 of 4: Main GUI

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_244_PRJ_MFC_Database_Binary_02_CLASSES.h"
#include "CPP_243_PRJ_MFC_Database_Binary_01_IDs.h"

//---------------------------------------------------------------------------------------------------------------------------

//Globals
const int MAX = 100;
int RecNum = 0;
Contact * ContactRecord = new Contact[MAX];
int Contact::Counter = 0;

//---------------------------------------------------------------------------------------------------------------------------

//Global Pointers to Dialog Objects
CEdit * pRECORDNUMBER;
CEdit * pFIRST;
CEdit * pLAST;
CEdit * pADDRESS;
CEdit * pEMAIL;
CEdit * pPHONE;
CEdit * pSEARCH;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void OnPrevious();
void OnNext();

//---------------------------------------------------------------------------------------------------------------------------

//Constructor definition for class derived from CDialog.
AddressBook::AddressBook( char * AddressBookString )       
   : CDialog( AddressBookString ) 
{      } 

//---------------------------------------------------------------------------------------------------------------------------

BOOL AddressBook::OnInitDialog()
{
	CDialog::OnInitDialog();
        //Assign Global Pointers to Dialog Objects
        pRECORDNUMBER = (CEdit *) (GetDlgItem(IDC_RECORDNUMBER));
        pFIRST = (CEdit *) (GetDlgItem(IDC_FIRST));
        pLAST = (CEdit *) (GetDlgItem(IDC_LAST));
        pADDRESS = (CEdit *) (GetDlgItem(IDC_ADDRESS));
        pEMAIL = (CEdit *) (GetDlgItem(IDC_EMAIL));
        pPHONE = (CEdit *) (GetDlgItem(IDC_PHONE));
        pSEARCH = (CEdit *) (GetDlgItem(IDC_SEARCHFIELD));

	//If Contacts.dat file exists, open it, if not, display message box
        OnFileOpen();
	return true;
}

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnSearch()
{
    //This is a simple linear search routine to iterate through each object in our array.
    char SEARCH[60];
    pSEARCH->GetWindowText(SEARCH, 60); //Get the text string to search for.
    //Get the selected category (data member) to search for.
    int category = GetCheckedRadioButton(IDC_RADIO_FIRST, IDC_RADIO_LAST);
    
    int same;
    for(int x = 0; x < MAX; x++)
    {
        //Switch uses strncmp() to see if strings are the same.  Only checks first 4 characters.
        switch(category)
        {	       
            case IDC_RADIO_FIRST : same = strncmp(SEARCH, ContactRecord[x].GetFirst(), 4);
			           break;
            case IDC_RADIO_LAST :  same = strncmp(SEARCH, ContactRecord[x].GetLast(), 4); 
			           break;
            default :              same = strncmp(SEARCH, ContactRecord[x].GetEmail(), 4); 
			           break;
        } //close switch
		 
        //If same evaluates to 0, then the string are the same and we have a match. 
	if(same == 0)
	{
           MessageBox("I found a matching record!", "A Match Was Found!");
           break;  //stop the loop
	}
    } //close the for loop
    //If we couldn't find a match, let the user know.
    if(same != 0)
    {
       MessageBox("Sorry, your search item was not found.", "Item not Found.");
    }
    else             //Else we did find a match so let's display the corresponding record.
    {
       
         RecNum = x;   //Change the current record number to the subscript index value x.
         //Convert the array index number variable to a string so we can display it in a CEdit box. 
         char RecordNumber[4] = "200";
         itoa(ContactRecord[RecNum].GetID(), RecordNumber, 10);
         //Send the record information to the CEdit controls via the pointers and accessor methods.
	 pRECORDNUMBER->SetWindowText(RecordNumber);
         pFIRST->SetWindowText(ContactRecord[x].GetFirst());
	 pLAST->SetWindowText(ContactRecord[x].GetLast());
         pADDRESS->SetWindowText(ContactRecord[x].GetAddress());
         pEMAIL->SetWindowText(ContactRecord[x].GetEmail());
         pPHONE->SetWindowText(ContactRecord[x].GetPhone());

    } //end else

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnOpen()
{
    char RecordNumber[4] = "200";
    itoa(ContactRecord[0].GetID(), RecordNumber, 10);

    //Load the very first record
    pRECORDNUMBER->SetWindowText(RecordNumber);
    pFIRST->SetWindowText(ContactRecord[0].GetFirst());
    pLAST->SetWindowText(ContactRecord[0].GetLast());
    pADDRESS->SetWindowText(ContactRecord[0].GetAddress());
    pEMAIL->SetWindowText(ContactRecord[0].GetEmail());
    pPHONE->SetWindowText(ContactRecord[0].GetPhone());

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnFileOpen()
{
    ifstream InputData("Contacts.dat", ios::binary);
    if(!InputData)
    {      

	char OhNooo[11][60] = { "It appears that one of several things has happened:", 
                                "\n\n1. This is the first time you have run this program ",
                                "\n and therefore you need to type in some records",
                                "\n and click \"SAVE\" under \"File Operations\" (not the", 
                                "\n \"SAVE\" under \"Record Operations\") to create the", 
                                "\n \"Contacts.dat\" file which this program needs to load",
                                "\n each time it starts.",
                                "\n\n2. You have inadvertently deleted or moved the required",
                                "\n \"Contacts.dat\" to some other folder. If this is the",
                                "\n case, you must move it back, undelete it, or recreate",
                                "\n it." };

        char Message[600] = "";

        for(int z = 0; z<11; z++){ strncat(Message, OhNooo[z], 60); }

        MessageBox(Message, "INSTRUCTIONS:");
    }

    else 
    {
	 for(int x = 0; x < MAX; x++)
	 {
             InputData.read((char*) &ContactRecord[x], sizeof ContactRecord[x]);
	 }
         InputData.close();
	 OnOpen();
    } //close else

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnSave()
{
      //This function saves a record to an array object in memory.  
      //It does NOT save the info to a file.  That is the responsibility of OnFileSave().
    char FIRST[20];
    char LAST[20];
    char ADDRESS[60];
    char PHONE[20];
    char EMAIL[60];
    pFIRST->GetWindowText(FIRST, 20);
    pLAST->GetWindowText(LAST, 20);
    pADDRESS->GetWindowText(ADDRESS, 60);
    pPHONE->GetWindowText(PHONE, 20);
    pEMAIL->GetWindowText(EMAIL, 60);
    ContactRecord[RecNum].SetFirst(FIRST);
    ContactRecord[RecNum].SetLast(LAST);
    ContactRecord[RecNum].SetAddress(ADDRESS);
    ContactRecord[RecNum].SetPhone(PHONE);
    ContactRecord[RecNum].SetEmail(EMAIL);

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnFileSave()
{
        ofstream OutputData("Contacts.dat", ios::binary);
	for(int x = 0; x < MAX; x++)
	{
            OutputData.write((char*) &ContactRecord[x], sizeof ContactRecord[x]);
	}
        OutputData.close();  
   
} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnExit()
{
        OnFileSave();
        EndDialog(IDOK);   //Close the program
}

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnFileExit()
{
     //Just call the Window closing message handler above.
     OnExit();
}

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnNextContact()
{ 
    OnSave(); //Save the record before advancing to next record.

    //Validate - Let's validate that it's an actual record and stop if it's not.  Subtract one for fencepost.
    if(RecNum < MAX-1)
    { 
       RecNum++; 
    }

    else
    {
 	RecNum = MAX-1;
    }
    //We need to convert the integer to a string.
    char RecordNumber[4] = "200";
    itoa(ContactRecord[RecNum].GetID(), RecordNumber, 10);
    pRECORDNUMBER->SetWindowText(RecordNumber);
    pFIRST->SetWindowText(ContactRecord[RecNum].GetFirst());
    pLAST->SetWindowText(ContactRecord[RecNum].GetLast());
    pADDRESS->SetWindowText(ContactRecord[RecNum].GetAddress());
    pEMAIL->SetWindowText(ContactRecord[RecNum].GetEmail());
    pPHONE->SetWindowText(ContactRecord[RecNum].GetPhone());

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnPreviousContact()
{
    OnSave(); //Save the record before advancing to next record.

    //Validate - Let's validate that it's an actual record and stop if it's not.
    if(RecNum > 0)
    { 
       RecNum--; 
    }

    else
    {
 	RecNum = 0;
    }
    //We need to convert the integer to a string and add 1 to offset the fencepost
    char RecordNumber[4] = "200";
    itoa(ContactRecord[RecNum].GetID(), RecordNumber, 10);

    pRECORDNUMBER->SetWindowText(RecordNumber);
    pFIRST->SetWindowText(ContactRecord[RecNum].GetFirst());
    pLAST->SetWindowText(ContactRecord[RecNum].GetLast());
    pADDRESS->SetWindowText(ContactRecord[RecNum].GetAddress());
    pEMAIL->SetWindowText(ContactRecord[RecNum].GetEmail());
    pPHONE->SetWindowText(ContactRecord[RecNum].GetPhone());

}  //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnFirst() 
{
    RecNum = 0;   //Set to first record

     //We need to onvert the integer to a string and add 1 to offset the fencepost
   char RecordNumber[4] = "200";
   itoa(ContactRecord[RecNum].GetID(), RecordNumber, 10);

   pRECORDNUMBER->SetWindowText(RecordNumber);
   pFIRST->SetWindowText(ContactRecord[RecNum].GetFirst());
   pLAST->SetWindowText(ContactRecord[RecNum].GetLast());
   pADDRESS->SetWindowText(ContactRecord[RecNum].GetAddress());
   pEMAIL->SetWindowText(ContactRecord[RecNum].GetEmail());
   pPHONE->SetWindowText(ContactRecord[RecNum].GetPhone());

} //close function

//---------------------------------------------------------------------------------------------------------------------------

afx_msg void AddressBook::OnLast() 
{
    RecNum = MAX-1;   //Set to first record

     //We need to convert the integer to a string and add 1 to offset the fencepost
   char RecordNumber[4] = "200";
   itoa(ContactRecord[RecNum].GetID(), RecordNumber, 10);

   pRECORDNUMBER->SetWindowText(RecordNumber);
   pFIRST->SetWindowText(ContactRecord[RecNum].GetFirst());
   pLAST->SetWindowText(ContactRecord[RecNum].GetLast());
   pADDRESS->SetWindowText(ContactRecord[RecNum].GetAddress());
   pEMAIL->SetWindowText(ContactRecord[RecNum].GetEmail());
   pPHONE->SetWindowText(ContactRecord[RecNum].GetPhone());

} //close function

//---------------------------------------------------------------------------------------------------------------------------

//IMPORTANT NOTE: The text below has been placed in multiple lines so that it would fit neatly within 
//this HTML table.  However, when you paste it into your compiler it needs to be on the same line.

afx_msg void AddressBook::OnAboutInformation()
{
	char About[5][50] = { "This is version 1.0 of a simple MFC database.\n",
                              "It is an address book for keeping contact \n", 
                              "information. It was created as a template \n",
                              "for C++ II students.\n\n",
                              "2006 - C. Germany" };

        char Message[400] = "";

        for(int z = 0; z<5; z++){ strncat(Message, About[z], 50); }

        MessageBox(Message, "http://www.networkingprogramming.com");
}

//---------------------------------------------------------------------------------------------------------------------------

//IMPORTANT NOTE: The text below has been placed in multiple lines so that it would fit neatly within 
//this HTML table.  However, when you paste it into your compiler it needs to be on the same line.

afx_msg void AddressBook::OnHelpInstructions()
{
	char Inst[12][55] = { "Instructions? Well, to start, press\"OPEN\" in ", 
                              "the File Operations group. Then, type in some ",
                              "records. You may then click \"NEXT\" or \"PREV\" ",
                              "to navigate through records. When you want to ", 
                              "save a record, click \"SAVE\" under the Record ",
                              "Operations section.\n\nWhen you are finally ",
                              "ready to write everything to a file, click \"SAVE\" ",
                              "under the File Operations Section. You may also ",
                              "search for records via the \"Search\" group. ",
                              "Simply type in your search string and select one ",
                              "of the search category radio buttons.\n\n ",
                              "http://www.networkingprogramming.com" };

        char Message[600] = "";

        for(int z = 0; z<12; z++){ strncat(Message, Inst[z], 50); }

        MessageBox(Message, "INSTRUCTIONS:");
}

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP( AddressBook, CDialog )
      ON_COMMAND(IDC_OPEN, OnOpen)
      ON_COMMAND(IDC_OPENFILE, OnFileOpen)
      ON_COMMAND(IDC_FILE_OPEN, OnFileOpen)
      ON_COMMAND(IDC_SAVE, OnSave)
      ON_COMMAND(IDC_SAVEFILE, OnFileSave)
      ON_COMMAND(IDC_FILE_SAVE, OnFileSave)
      ON_COMMAND(IDC_EXIT, OnExit)
      ON_COMMAND(IDC_FILE_EXIT, OnFileExit)
      ON_COMMAND(IDC_NEXT, OnNextContact)
      ON_COMMAND(IDC_PREVIOUS, OnPreviousContact)
      ON_COMMAND(IDC_SEARCH, OnSearch)

      ON_COMMAND(IDC_FIRSTRECORD, OnFirst)
      ON_COMMAND(IDC_LASTRECORD, OnLast)

      ON_COMMAND(ID_ABOUT_INFORMATION, OnAboutInformation)
      ON_COMMAND(ID_HELP_INSTRUCTIONS, OnHelpInstructions)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

// Launch the database - Derive an instance of CWinApp and call InitInstance()

class CreateAddressBook : public CWinApp {
public:
   BOOL InitInstance()
   {
         //Note - HERE is where we specify the .rc file name, create instance of AddressBook class
        AddressBook MyAddBook( "ADDRESS" );  
        MyAddBook.DoModal();
        return FALSE;                 
   }
};

//---------------------------------------------------------------------------------------------------------------------------

CreateAddressBook  MakeIt;

//---------------------------------------------------------------------------------------------------------------------------





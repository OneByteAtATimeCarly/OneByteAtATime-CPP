//PRJ - Database - Binary File Storage and Access - MFC GUI App - 2004 - C. S. Germany
//File 2 of 4: CLASSES

//---------------------------------------------------------------------------------------------------------------------------

#include <afxwin.h>
#include <strstream>
#include <fstream>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------

class Contact
{
public:
	Contact()  {   Initialize();   }
	~Contact() { }

        //Accessor Methods - Need to use strcpy for set methods.
	void SetID(int IDtag) { ID = IDtag; }   //Primary key for records
        int GetID() { return ID; }
        void SetFirst(char Fir[20]) { strcpy(First, Fir); }
	char * GetFirst() { return First; }
	void SetLast(char Las[20]) { strcpy(Last, Las); }
	char * GetLast() { return Last; }
	void SetAddress(char Adr[60]) { strcpy(Address, Adr); }
	char * GetAddress() { return Address; }
	void SetPhone(char Pho[20]) { strcpy(Phone, Pho); }
	char * GetPhone() { return Phone; }
	void SetEmail(char Ema[60]) { strcpy(Email, Ema); } 
	char * GetEmail() { return Email; }
           //Initialize values when constructor called
	void Initialize() 
	{
	     Counter++;  //Give each record a unique primary key ID.
             ID = Counter;
             strcpy(First, "No First");
	     strcpy(Last, "No Last");
	     strcpy(Address, "No Address");
	     strcpy(Phone, "No Phone");
	     strcpy(Email, "No Email");
	}
private:
	static int Counter;  //Needs to be static, initialized outside of class

        int ID;
	char First[20];
	char Last[20];
	char Address[60];
	char Phone[20];
	char Email[60];
};

//----------------------------------------------------------------------------------------------------------------------------

class AddressBook : public CDialog 
{
      public:
         AddressBook( char * AddressBookString );
         BOOL OnInitDialog();
         //Message Handlers
         afx_msg void OnOpen();
         afx_msg void OnFileOpen();

         afx_msg void OnSave();
         afx_msg void OnFileSave();

         afx_msg void OnPreviousContact();
         afx_msg void OnNextContact();

         afx_msg void OnExit();
         afx_msg void OnFileExit();

         afx_msg void OnSearch();

	 afx_msg void OnFirst();
         afx_msg void OnLast();

	 afx_msg void OnAboutInformation();
         afx_msg void OnHelpInstructions();
      private:

      DECLARE_MESSAGE_MAP()
};

//----------------------------------------------------------------------------------------------------------------------------





Project Scope: C++ Win 32 / MFC Project:  OLE-DB, ODBC and DAO Databases
Project Type: MFC Database Project using OLE-DB, ODBC and DAO Connectivity
File: 1 of 20

Objective: 

This project uses the MFC application wizard.  This tutorial will walk through the basic steps of creating a DAO file-based database using the MFC Application wizard and Visual C++.  This project will create a simple address book and contact information organizer using DAO and a ".mdb" file. 

Introduction:

For database access within Visual C++'s MFC, there are basically three options:

1. DAO - (VS 6.0 MFC) stands for Data Access Objects.  DAO involves accessing a file directly using the Jet database engine to manipulate data within the tables of the ".mdb" file using SQL strings and commands.  DAO uses objects for database access.  For databases that are DAO-based, you can create a DSNless connection. Slowly being replaced with OLE DB.

2. ODBC - (2003.NET MFC) stands for the Open Database Connectivity interface.  It only connects to relational databases. ODBC is more flexible in that is allows you to interface with any database format for which you have the appropriate driver.  These could be Access, Oracle, dBase5, Btrieve 6.0, and FoxPro 2.6.  ODBC is a system independent interface - you only need the DLL that contains the driver for the database's format.  For ODBC databases, you must create a Data Source Name (DSN), which is a string that maps a relative path to the absolute path on a system where a database is located.  You can set up DSNs in Control Panel or in 2003 .NET. They may be system based or file-based (more portable). 

3. OLE DB - (2003.NET MFC) Microsoft's preferred new method of connecting to a database, as it can connect to relational and non-relational databases.

Instructions:

Use the MFC Application Wizard in 2003 .Net

 A. Use Access to create a .mdb database file with the usual filed information for personal Contacts:
      Last name, First Name, Phone Number, Address, and Email. You may add additional fields as required.

 B. Visual Studio .Net Activity

  1. Launch your Visual C++ compiler.
  2. Select  File->New->Blank Solution.
  3. Select "Visual C++ Projects" and then select "MFC Application" from the list of available options.
  3. When the wizards runs, type a name for your project and click "OK".
  4. Under "Application Type", select "Single Document".
  5.  Make sure "Document/View" Architecture Support" is checked.
  6. Click "Database Support" and select "Database View Without File Support".
  7. Click the "OLE DB" and "DYNASET" radio button and then click the "Data Source" button.
  8. Select the "Microsoft Jet 4.0 OLE DB Provider" option. Click "NEXT".
  9. Select or enter the the .mdb database  file name (i.e. "Contact.mdb") and click "OPEN".
10. Type "Admin" for user name and check "Blank Password".
11. Click "Test Connection" to verify your connection string.
12. Click "OK" and then select the database table object to bind to the form.
      In our case, this will be the "ContactDetails" table from the "Contact.mdb" file. 
13. Click "Next, then "Next", then "Next" accepting the defaults and then finally "Finish".
14. Click "OK" when you see the warning about plain text passwords.
15. At this point, you must comment out the line that says:

              "#error Security Issue: The connection string may contain a password"

              Otherwise your application will not compile. Add two "//'s" to change it to:

              "//#error Security Issue: The connection string may contain a password"

Alternatively, you may create a ODBC database connection as described above:

1. Select "ODBC" and click the "Data Source" button.
2. Select the "File Data Source" tab and click "New".
3. Select "Microsoft Access Driver" and click "Next".
4. Click "Browse", select "All Files", select your .mdb file and click "SAVE".
5. Click "NEXT" and "FINISH".
6. Click the "SELECT" button and select the *.mdb file in the box on the left.
7. Click "OK" and then "OK". Select the DSN file you just created and click OK.
8. Click "OK" and "OK" and then select the tables you want to include in the database.
9. Finally, click "FINISH". You will have to comment our or delete the #error Security Issue:
    just as you would with OLE DB database projects.

At last: After commenting this line out, your application will compile linked to the database file. .NET 2003 will add a ton of bloated functions, classes and auto-generated code to your project corresponding to their Document vs. View philosophy.

C. Modify the Wizard Generated Code

.NET will add some basic record commands and a toolbar. You just need to change a few things:

1.  The wizard will create a "YourProjectNameSet.h" file. Here lies the declaration for the "DoFieldExchange()" function which enables the transfer of values between the MFC CRecordset class and the database file. It's implementation will be in "YourProjectNameSet.cpp". Open "YourProjectNameSet.h" and go to where the field data members are declared for the *.mdb file. Change every instance of "CStringW" to "CString". Here's what mine looks like after I changed it for the "contacts.mdb":


long m_ContactDetailsInfoID;
long m_ContactDetailsContactID;
CString m_ContactDetailsBirthday;
CString m_ContactDetailsAnniversary;
CString m_ContactDetailsLikes;
CString m_ContactDetailsDislikes;
CString m_ContactDetailsNotes;
long m_ContactInfoContactID;
CString m_ContactInfoFirst;
CString m_ContactInfoLast;
CString m_ContactInfoEmail;
CString m_ContactInfoStreet;
CString m_ContactInfoCity;
CString m_ContactInfoState;
CString m_ContactInfoZip;
CString m_ContactInfoCountry;
CString m_ContactInfoHomePhone;
CString m_ContactInfoCellPhone;
CString m_ContactInfoWorkPhone;
CString m_ContactInfoWebsite;

The "GetDefaultSQL()" function created by the wizard can be modified to sort records by different fields. My default function connects to two tables and looks like:

        CString CDatabase1Set::GetDefaultSQL()
       {
              return _T("[ContactDetails],[ContactInfo]");
        } 
You will also see pre-built SQL queries generated by the wizard beneath this.

2. Open up the visual form editor and create CEdit controls for all of the fields in the *.mdb database file. Carefully label the IDs of the CEdit controls the same as the field names in the database so they will be easy to remember. Add labels as needed.

3. Open "MyProjectView.cpp" and find the "DoDataExchange()" function. You need to add code to associate the dialog controls with the database fileds. Here's what my database code looks like:

void CDatabase1View::DoDataExchange(CDataExchange * pDX)
{
       CRecordView::DoDataExchange(pDX);
       DDX_FieldText(pDX, IDC_ID, m_pSet->m_ContactInfoContactID, m_pSet);
       DDX_FieldText(pDX, IDC_FIRST, m_pSet->m_ContactInfoFirst, m_pSet);
       DDX_FieldText(pDX, IDC_LAST, m_pSet->m_ContactInfoLast, m_pSet);
       DDX_FieldText(pDX, IDC_EMAIL, m_pSet->m_ContactInfoEmail, m_pSet);
       DDX_FieldText(pDX, IDC_STREET, m_pSet->m_ContactInfoStreet, m_pSet);
       DDX_FieldText(pDX, IDC_CITY, m_pSet->m_ContactInfoCity, m_pSet);
       DDX_FieldText(pDX, IDC_STATE, m_pSet->m_ContactInfoState, m_pSet);
       DDX_FieldText(pDX, IDC_ZIP, m_pSet->m_ContactInfoZip, m_pSet);
       DDX_FieldText(pDX, IDC_COUNTRY, m_pSet->m_ContactInfoCountry, m_pSet);
       DDX_FieldText(pDX, IDC_HOMEPHONE, m_pSet->m_ContactInfoHomePhone, m_pSet);
       DDX_FieldText(pDX, IDC_CELLPHONE, m_pSet->m_ContactInfoCellPhone, m_pSet);
       DDX_FieldText(pDX, IDC_WORKPHONE, m_pSet->m_ContactInfoWorkPhone, m_pSet);
       DDX_FieldText(pDX, IDC_WEBSITE, m_pSet->m_ContactInfoWebsite, m_pSet);
}

 4. At this point you can build the database project and view its records. Below I have listed some source files:


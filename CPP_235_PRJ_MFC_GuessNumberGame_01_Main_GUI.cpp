//PRJ - Guess My Number - MFC GUI Game - 2006 - C. S. Germany
//File 1 of 3: Main File - MFC GUI

//---------------------------------------------------------------------------------------------------------------------------

/*
01/16/2010 C. Germany
2008 Notes:
--------------------------------------------------------------------------	
To create a scaled down 2008 template project:
   1. Create an EMPTY Win32 project. Click -> "File" -> -> "New"
	  -> "Project" -> "Win32" -> "Win32 Project".
   2. Name is and select a directory.
   3. Select "Application Settings" -> "Empty Project" then click "Finish".
   4. Rt-click project, select "Properties" -> "Configuration Properties"
      -> "General" -> "Use of MFC" and change it to 
      "Use MFC in a Static Library". This will give you MFC components.
   5. Disable Incremental Linking. Rt-click project, select "Properties" 
	  -> "Configuration Properties" -> "Linker" -> "General" ->
      "Enable Incremental Linking" and set it to "NO".
   6. Add a resources file. Rt-click resources and add a DIALOG object.
   7. Change the enumerated constant in the CDialog class to match the
	  Dialog object ID in the resource file.
--------------------------------------------------------------------------
To remove 2008 warnings (you can ignore them if you choose):
   1.Rt-click PROJECT and select -> "Properties" -> "Configuration Properties"
     -> "C/C++" -> "General" -> "Debug Information Formant" and 
     -> "Program Database for Edit and Continue /ZI". Set it to "Disabled".
   2.Rt-click PROJECT and select -> "Properties" -> "Configuration Properties"
     -> "C/C++" -> "Code Generation" -> "Enable Minimal Rebuild" and 
     -> "Yes (/Gm)". Set it to "No".
   3.Use "_atoi_s()" instead of "itoa()" to avoid deprecation warning.
--------------------------------------------------------------------------
Significant changes needed for going from 2003 to 2008 are:
   1. When calling SetWindowText() in 2008 the string passed in must be
      cast/converted to unicode by prefixing it with "L".
   2. You must use CStrings with SetWindowText() and MessageBox.
   3. You must convert from CString to char array and char array to CString
      when using atoi and itoa with GetWindowText() and SetWindowText().
--------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------------------------------------------------------

#include <afxwin.h>     // MFC core and standard components
#include "CPP_236_PRJ_MFC_GuessNumberGame_02_Resources.h"   // main symbols
//Globals 
CStatic * pOUTPUT;
CStatic * pNUMGUESSES;
CEdit * pInput;
CStatic * pNumberBeingGuessed;
CStatic * pSCORE;
CButton * pButtonGuess;
CButton * pButtonStart;
int TheNumber = 0;
int Counter = 0;
int NumBeingGuessed = 1;
int score = 0;
CString TEMP;
CString message;

//---------------------------------------------------------------------------------------------------------------------------

class GuessNumber : public CDialog
{
    public:
    GuessNumber(CWnd* pParent = NULL): CDialog(GuessNumber::IDD, pParent)
    {    }
    // Dialog Data, name of dialog form
    enum{IDD = IDD_Interface};
    protected:
    virtual void DoDataExchange(CDataExchange* pDX) { CDialog::DoDataExchange(pDX); }
//---------------------------------------------------------------
	
	virtual BOOL OnInitDialog() 
    { 
            CDialog::OnInitDialog();
            
		    pOUTPUT = (CStatic *) GetDlgItem(IDC_OUTPUT);
            pNUMGUESSES = (CStatic *) GetDlgItem(IDC_GUESSES);
            pInput = (CEdit *) GetDlgItem(IDC_INPUT);
			pButtonGuess = (CButton *) GetDlgItem(IDC_BUTTON_GUESS);
            pButtonStart = (CButton *) GetDlgItem(IDC_START);
            pNumberBeingGuessed = (CStatic *) GetDlgItem(CS_NumBeingGuessed);
			pSCORE = (CStatic *) GetDlgItem(CS_SCORE);
			score = 0;
			pButtonGuess->ShowWindow(false);
			//Cast time_t to unsigned int to avoid a warning
			srand((unsigned int)time(NULL));
		
            return true; 
    }

//---------------------------------------------------------------
public:
afx_msg void start()
{
	    pButtonGuess->ShowWindow(true);
        pButtonGuess->EnableWindow(true);
        pOUTPUT->SetWindowText(L"\n\rGuess a number from 1 and 10.");
		TheNumber = (rand()%10) + 1;
		pButtonStart->ShowWindow(false);
        char N[10];
		_itoa_s(NumBeingGuessed,N,10);
        TEMP = CString(N);
		pNumberBeingGuessed->SetWindowText(TEMP);
		pInput->SetFocus();
}

//---------------------------------------------------------------
afx_msg void guess()
{
	    char N[10];
	    _itoa_s(NumBeingGuessed,N,10);
		TEMP = N;
		pNumberBeingGuessed->SetWindowText(TEMP);
	
	    if(NumBeingGuessed <= 3)
		{ Guess1Number(); }
		else
		{ MessageBox(L"Game Over!"); }
		pInput->SetFocus();
}

//---------------------------------------------------------------
void Guess1Number()
{
	    Counter++;
		char NumGuesses[10];
        _itoa_s(Counter,NumGuesses,10);
        TEMP = NumGuesses;
        pNUMGUESSES->SetWindowText(TEMP);
	    char TheGuess[10];
        pInput->GetWindowText(TEMP);
		//Convert CString to char array, cast to char to avoid warning
        for(int x = 0; x < TEMP.GetLength(); x++) 
		{ TheGuess[x] = (char) TEMP[x]; }
		int NumGuessed = atoi(TheGuess);
        
        _itoa_s(TheNumber,TheGuess,10); 
        TEMP = TheGuess;
		if(NumGuessed == TheNumber)
		{ 
              GuessedIt();
		}
		else if(Counter < 3)
		{
		    if(NumGuessed > TheNumber)
		    { message = "\n\rThe number is smaller."; }
		    else
		    { message = "\n\rThe number is larger."; }
		}
		else
		{
             DidNotGuessIt();
		}
		pOUTPUT->SetWindowText(message);
		pInput->SetWindowText(L"");
		
}

//---------------------------------------------------------------
void GuessedIt()
{
	 message = "\n\rYou got it right! You win.";
	 message = message + "\n\rThe number was: " + TEMP;
	 if(NumBeingGuessed < 3)
	 {
        message = message + "\n\r\n\rClick \"START\" to guess"
			    + " the next number.";
	    Counter = 0;		
	    pButtonGuess->EnableWindow(false);
	    pButtonStart->ShowWindow(true);
	    score++;
	    char COUNT[20];
	    _itoa_s(score,COUNT,10);
	    TEMP = COUNT;
        pSCORE->SetWindowText(TEMP);
	    NumBeingGuessed++;
	 }
	 else
	 {
         message = message + "\n\r\n\rThree numbers = Game Over.";
	 }
}

//---------------------------------------------------------------
void DidNotGuessIt()
{
	 message = "\n\rSorry you didn't guess it in 3 guesses.";
     message = message + "\n\rThe number was: " + TEMP + ".";
     if(NumBeingGuessed < 3)
	 {	 
        message = message + "\n\r\n\rClick \"START\" to guess"
			    + " the next number.";
        Counter = 0;
	    pButtonGuess->EnableWindow(false);
	    pButtonStart->ShowWindow(true);
        NumBeingGuessed++;
	 }
	 else
	 {
        message = message + "\n\r\n\rThree numbers = Game Over.";
	 }
}

//---------------------------------------------------------------
DECLARE_MESSAGE_MAP()

};

//---------------------------------------------------------------------------------------------------------------------------

class TheProgram : public CWinApp
{
public:
TheProgram() {  }
virtual BOOL InitInstance()
{
        CWinApp::InitInstance();
        GuessNumber dlg;
        m_pMainWnd = &dlg;
        INT_PTR nResponse = dlg.DoModal();
        return FALSE;
} //close function
};

//---------------------------------------------------------------------------------------------------------------------------

//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(GuessNumber, CDialog)
      ON_COMMAND(IDC_START,start)
      ON_COMMAND(IDC_BUTTON_GUESS,guess)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

TheProgram BANANA;  //Starts the Application

//---------------------------------------------------------------------------------------------------------------------------



















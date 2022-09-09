//PRJ - MegaPet3 - MFC GUI Game - 2006 - C. S. Germany
//File 5 of 7: Main File - MFC GUI

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
   4.Use "sprintf_s()" instead of "sprintf()" to avoid deprecation warning.
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

//The Windows interface for the game.
#include <afxwin.h>                                     // MFC core and standard components
#include <afxcmn.h>	                                // MFC components
#include "CPP_232_PRJ_MFC_MegaPet3_06_Resources.h"      // main symbols
#include "Afxext.h"                                     // CBitmapButtons
#include "CPP_227_PRJ_MFC_MegaPet3_01_GLOBALS.h"    
#include "CPP_228_PRJ_MFC_MegaPet3_02_CLASSES.h"
#include "CPP_229_PRJ_MFC_MegaPet3_03_FUNCTIONS.h"

//---------------------------------------------------------------------------------------------------------------------------

class MegaPet_FORM : public CDialog
{
      public:
      MegaPet_FORM (CWnd* pParent = NULL): CDialog(MegaPet_FORM ::IDD, pParent)
      {  }
//-----------------------------------------------------------------
      enum{IDD = IDD_Interface};
//-----------------------------------------------------------------
      protected:
      virtual void DoDataExchange(CDataExchange* pDX)
      { CDialog::DoDataExchange(pDX); }
//-----------------------------------------------------------------
      virtual BOOL OnInitDialog()
      { 
	          CDialog::OnInitDialog();
              SetUpInterface();
			  Initialize_Interface();
                
			  PlaySound(L"Audio/MusicClips/Pokemon.wav",NULL,SND_FILENAME|SND_ASYNC);
              PetBrush_WHITE.CreateSolidBrush(RGB(255, 255, 255));
			  PetBrush_BLACK.CreateSolidBrush(RGB(0, 0, 0));
              PetBrush_RED.CreateSolidBrush(RGB(255, 0, 0));
			  PetBrush_BLUE.CreateSolidBrush(RGB(0, 0, 255));
              MainOutput->SetWindowText(L"\r\n       Click the \"START\"\r\n       button to begin.");
			  Input->SetFocus();
			  return true; 
}
//-----------------------------------------------------------------
void SetUpInterface()
{
	 //Setup pointers to Dialog Interface objects	  
	 //Generic Interface Objects
	 Button_Start = (CBitmapButton *) GetDlgItem(B_START);
	 Button_Start = new CBitmapButton;
     Button_Start->Create(NULL, WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, 
	 CRect(329,272,0,0), this, B_START);
	 Button_Start->LoadBitmaps(IDB_START);
	 Button_Start->SizeToContent();
     Button_Exit = (CBitmapButton *) GetDlgItem(B_QUIT);
	 Button_Exit = new CBitmapButton;
     Button_Exit->Create(NULL, WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, 
	 CRect(423,275,0,0), this, B_QUIT);
	 Button_Exit->LoadBitmaps(IDB_QUIT);
	 Button_Exit->SizeToContent();         
			  //CBB_QUIT = new CBitmapButton;
		      MainOutput = (CEdit *) GetDlgItem(CE_MainOutput);
			  Input = (CEdit *) GetDlgItem(CE_INPUT);
              Button_Begin_T = (CButton *) GetDlgItem(B_BEGIN_TOURNAMENT);
              Button_End_T = (CButton *) GetDlgItem(B_END_TOURNAMENT);
              Button_Help = (CButton *) GetDlgItem(B_HELP);
			  Button_Enter = (CButton *) GetDlgItem(B_ENTER);
              //Pet1 Interface Objects
			  Pet1_HealthMeter = (CSliderCtrl *) GetDlgItem(SC_PET1);
			  Pet1_HealthBar = (CProgressCtrl *) GetDlgItem(PB_Pet1Life);
              Pet1_Status = (CEdit *) GetDlgItem(CE_PET1_STATUS);
			  Pet1View = (CStatic *) GetDlgItem(PC_PET_1); 
              Pet1_Box_Name = (CStatic *) GetDlgItem(CS_PET1_BOX_NAME);
			  Pet1_Box_Species = (CStatic *) GetDlgItem(CS_PET1_BOX_SPECIES);
              Pet1_Box_Health = (CStatic *) GetDlgItem(CS_PET1_BOX_HEALTH);
			  Pet1_Box_Speed = (CStatic *) GetDlgItem(CS_PET1_BOX_SPEED);
			  Pet1_Box_Strength = (CStatic *) GetDlgItem(CS_PET1_BOX_STRENGTH);
			  Pet1_Box_Attack = (CStatic *) GetDlgItem(CS_PET1_BOX_ATK);
			  Pet1_Box_Defense = (CStatic *) GetDlgItem(CS_PET1_BOX_DEF);
			  Pet1_Box_SpecialDefense = (CStatic *) GetDlgItem(CS_PET1_BOX_SPCDEF);
			  Pet1_Box_SpecialAttack = (CStatic *) GetDlgItem(CS_PET1_BOX_SPCATK);
			  Pet1_Box_SpecAbilEnergy = (CStatic *) GetDlgItem(CS_PET1_BOX_SPCABILENERGY);
			  Pet1_Button_LOAD = (CButton *) GetDlgItem(B_PET1_LOAD);
			  Pet1_Button_SAVE = (CButton *) GetDlgItem(B_PET1_SAVE);
			  Pet1_Button_NEW = (CButton *) GetDlgItem(B_PET1_NEW);
			  Pet1_Button_TRAIN = (CButton *) GetDlgItem(B_PET1_TRAIN);
			  Pet1_Button_FEED = (CButton *) GetDlgItem(B_PET1_FEED);
			  Pet1_Button_PLAY = (CButton *) GetDlgItem(B_PET1_PLAY);
			  Pet1_Button_TALK = (CButton *) GetDlgItem(B_PET1_TALK);
			  Pet1_Button_SLEEP = (CButton *) GetDlgItem(B_PET1_SLEEP);
			  Pet1_Button_KICK = (CButton *) GetDlgItem(B_PET1_KICK);
			  Pet1_Button_ATTACK = (CButton *) GetDlgItem(B_PET1_ATTACK);
			  Pet1_Button_DEFEND = (CButton *) GetDlgItem(B_PET1_DEFEND);
			  Pet1_Button_SPECATTACK = (CButton *) GetDlgItem(B_PET1_SPEC_ATTACK);
			  Pet1_Button_SPECDEFEND = (CButton *) GetDlgItem(B_PET1_SPEC_DEFEND);
              //Pet2 Interface Objects
			  Pet2_HealthMeter = (CSliderCtrl *) GetDlgItem(SC_PET2);
			  Pet2_HealthBar = (CProgressCtrl *) GetDlgItem(PB_Pet2Life);
              Pet2_Status = (CEdit *) GetDlgItem(CE_PET2_STATUS);
			  Pet2View = (CStatic *) GetDlgItem(PC_PET_2); 
              Pet2_Box_Name = (CStatic *) GetDlgItem(CS_PET2_BOX_NAME);
			  Pet2_Box_Species = (CStatic *) GetDlgItem(CS_PET2_BOX_SPECIES);
              Pet2_Box_Health = (CStatic *) GetDlgItem(CS_PET2_BOX_HEALTH);
			  Pet2_Box_Speed = (CStatic *) GetDlgItem(CS_PET2_BOX_SPEED);
			  Pet2_Box_Strength = (CStatic *) GetDlgItem(CS_PET2_BOX_STRENGTH);
			  Pet2_Box_Attack = (CStatic *) GetDlgItem(CS_PET2_BOX_ATK);
			  Pet2_Box_Defense = (CStatic *) GetDlgItem(CS_PET2_BOX_DEF);
			  Pet2_Box_SpecialDefense = (CStatic *) GetDlgItem(CS_PET2_BOX_SPCDEF);
			  Pet2_Box_SpecialAttack = (CStatic *) GetDlgItem(CS_PET2_BOX_SPCATK);
			  Pet2_Box_SpecAbilEnergy = (CStatic *) GetDlgItem(CS_PET2_BOX_SPCABILENERGY);
			  Pet2_Button_LOAD = (CButton *) GetDlgItem(B_PET2_LOAD);
			  Pet2_Button_SAVE = (CButton *) GetDlgItem(B_PET2_SAVE);
			  Pet2_Button_NEW = (CButton *) GetDlgItem(B_PET2_NEW);
			  Pet2_Button_TRAIN = (CButton *) GetDlgItem(B_PET2_TRAIN);
			  Pet2_Button_FEED = (CButton *) GetDlgItem(B_PET2_FEED);
			  Pet2_Button_PLAY = (CButton *) GetDlgItem(B_PET2_PLAY);
			  Pet2_Button_TALK = (CButton *) GetDlgItem(B_PET2_TALK);
			  Pet2_Button_SLEEP = (CButton *) GetDlgItem(B_PET2_SLEEP);
			  Pet2_Button_KICK = (CButton *) GetDlgItem(B_PET2_KICK);
			  Pet2_Button_ATTACK = (CButton *) GetDlgItem(B_PET2_ATTACK);
			  Pet2_Button_DEFEND = (CButton *) GetDlgItem(B_PET2_DEFEND);
			  Pet2_Button_SPECATTACK = (CButton *) GetDlgItem(B_PET2_SPEC_ATTACK);
			  Pet2_Button_SPECDEFEND = (CButton *) GetDlgItem(B_PET2_SPEC_DEFEND);
              //Setup Fonts
			  PetFont1.CreatePointFont(75,L"Arial");
			  PetFont2.CreatePointFont(100,L"Comic Sans MS");
			  CFont * BoxFont = &PetFont1;
			  CFont * StatusFont = &PetFont2;
			  MainOutput->SetFont(StatusFont);
              Pet1_Status->SetFont(StatusFont);
              Pet1_Box_Name->SetFont(BoxFont);
			  Pet1_Box_Species->SetFont(BoxFont);
              Pet1_Box_Health->SetFont(BoxFont);
			  Pet1_Box_Speed->SetFont(BoxFont);
			  Pet1_Box_Strength->SetFont(BoxFont);
			  Pet1_Box_Attack->SetFont(BoxFont);
			  Pet1_Box_Defense->SetFont(BoxFont);
			  Pet1_Box_SpecialDefense->SetFont(BoxFont);
			  Pet1_Box_SpecialAttack->SetFont(BoxFont);
			  Pet1_Box_SpecAbilEnergy->SetFont(BoxFont);
			  Pet2_Status->SetFont(StatusFont);
              Pet2_Box_Name->SetFont(BoxFont);
			  Pet2_Box_Species->SetFont(BoxFont);
              Pet2_Box_Health->SetFont(BoxFont);
			  Pet2_Box_Speed->SetFont(BoxFont);
			  Pet2_Box_Strength->SetFont(BoxFont);
			  Pet2_Box_Attack->SetFont(BoxFont);
			  Pet2_Box_Defense->SetFont(BoxFont);
			  Pet2_Box_SpecialDefense->SetFont(BoxFont);
			  Pet2_Box_SpecialAttack->SetFont(BoxFont);
			  Pet2_Box_SpecAbilEnergy->SetFont(BoxFont);
			  
}
//------------------------------------------------------------------
//Add Code to color interface with the global CBrush object
//Remember to add "ON_WM_CTLCOLOR()" to the MessageMap below.
HBRUSH MegaPet_FORM::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
       HBRUSH The_Active_Paint_Brush = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	   //Color the main CDialog window background
       if(nCtlColor == CTLCOLOR_DLG)
       {
            pDC->SetTextColor(RGB(0, 0, 0));
            The_Active_Paint_Brush = PetBrush_WHITE;
	        return The_Active_Paint_Brush;
       }
       //Color the main output CEdit box
       else if(pWnd->GetDlgCtrlID() == CE_MainOutput)
       {
            pDC->SetTextColor(RGB(0, 0, 255));
            pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_WHITE;
	        return The_Active_Paint_Brush;
       }
       //Color the Pet1 status CEdit box
       else if(pWnd->GetDlgCtrlID() == CE_PET1_STATUS)
       {
            pDC->SetTextColor(RGB(255, 255, 255));
            pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_BLACK;
	        return The_Active_Paint_Brush;
       }
       //Color the Pet2 status CEdit box
       else if(pWnd->GetDlgCtrlID() == CE_PET2_STATUS)
       {
            pDC->SetTextColor(RGB(255, 255, 255));
            pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_BLACK;
	        return The_Active_Paint_Brush;
       }
       //Color the input CEdit box
       else if(pWnd->GetDlgCtrlID() == CE_INPUT)
       {
            pDC->SetTextColor(RGB(255, 255, 255));
            pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_BLACK;
	        return The_Active_Paint_Brush;
       }
	   else if(pWnd->GetDlgCtrlID() == CS_PET1_BOX_NAME ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_SPECIES ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_HEALTH ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_SPEED ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_STRENGTH ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_ATK ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_DEF ||
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_SPCATK ||
          pWnd->GetDlgCtrlID() == CS_PET1_BOX_SPCDEF || 
		  pWnd->GetDlgCtrlID() == CS_PET1_BOX_SPCABILENERGY ||
          pWnd->GetDlgCtrlID() == CS_PET2_BOX_NAME ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_SPECIES ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_HEALTH ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_SPEED ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_STRENGTH ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_ATK ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_DEF ||
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_SPCATK ||
          pWnd->GetDlgCtrlID() == CS_PET2_BOX_SPCDEF || 
		  pWnd->GetDlgCtrlID() == CS_PET2_BOX_SPCABILENERGY)
	   {
	         pDC->SetTextColor(RGB(255, 0, 0));
		     pDC->SetBkMode(TRANSPARENT);
             The_Active_Paint_Brush = PetBrush_WHITE;
	         return The_Active_Paint_Brush;
	   }
       //Color all other generic CStatic text boxes
       else if(nCtlColor == CTLCOLOR_STATIC)
       {
            pDC->SetTextColor(RGB(0, 0, 0));
		    pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_WHITE;
	        return The_Active_Paint_Brush;
       }
       //Color all other generic buttons
       else if(nCtlColor == CTLCOLOR_BTN)
       {
            pDC->SetTextColor(RGB(255, 255, 255));
		    //pDC->SetBkMode(TRANSPARENT);
            The_Active_Paint_Brush = PetBrush_RED;
	        return The_Active_Paint_Brush;
       }
	   else
	   {
            return The_Active_Paint_Brush;
	   }
/*
Note: To color groups of objects by default use: 
        if(nCtlColor ==) and one of constants like:
        CTLCOLOR_EDIT
        CTLCOLOR_STATIC
        CTLCOLOR_DLG
		CTLCOLOR_BTN
		CTLCOLOR_LISTBOX
		CTLCOLOR_MSGBOX
		CTLCOLOR_SCROLLBAR
		CTLCOLOR_STATIC
*/
}
//------------------------------------------------------------------
      afx_msg void START() 
      {  
              TEMP = "\r\n  Welcome to MegaPet 2.0!\r\n\r\n";
			  TEMP = TEMP +	"\r\n  To begin, you must create "
					  + "\r\n  Pet objects.\r\n"
                      + "\r\n  Begin by creating a Pet1"
                      + "\r\n  object by clicking the"
					  + "\r\n  \"NEW\" button for Pet1.";
					  
	          MainOutput->SetWindowText(TEMP);
			  Pet1_Button_NEW->EnableWindow(true);
			  Button_Start->EnableWindow(false);
			  Button_Start->ShowWindow(false);
      }
//------------------------------------------------------------------
//Message Handlers
//------------------------------------------------------------------
	  afx_msg void QUIT() { EndDialog(IDOK); }
//------------------------------------------------------------------
	  afx_msg void ENTER() 
	  {  
            if(NeedToCreatePets)
			  { CreatePet(); }
			  else
			  {   
	              TEMP = "\r\n  Pets have now been created.";
				  TEMP = TEMP + "\r\n\r\n  You may click \"BEGIN T\""
					   + "\r\n  to begin a TOURNAMENT with"
					   + "\r\n  your new PETs or save them.";
				  MainOutput->SetWindowText(TEMP);
				  Button_Begin_T->EnableWindow(true);
				  Pet1_Button_SAVE->EnableWindow(true);
				  Pet2_Button_SAVE->EnableWindow(true);
			  }
	  }
//------------------------------------------------------------------
	  afx_msg void NewPet1() 
	  {  
	          CreatePet();
			  Pet1_Button_NEW->EnableWindow(false);
	  }
//------------------------------------------------------------------
	  afx_msg void NewPet2() 
	  {  
	          CreatePet();
			  Pet2_Button_NEW->EnableWindow(false);
	  }
//------------------------------------------------------------------
	  afx_msg void BeginTournament() 
	  {  
	          Button_Begin_T->EnableWindow(false);
			  Button_Enter->EnableWindow(false);
			  Combat();
	  }
//------------------------------------------------------------------
      afx_msg void Pet1Save() 
	  { 
		      SavePet(PET1);  
	  }
//------------------------------------------------------------------
      afx_msg void Pet2Save() 
	  { 
		      SavePet(PET2); 
	  }
//------------------------------------------------------------------
      afx_msg void Pet1Load() 
	  { 
		  TEMP = "";
		  if(LoadToggle)
		  {
		     LoadPet(1);
			 Input->SetWindowText(L"");
		     Button_Begin_T->EnableWindow(true);
			 LoadToggle = false;
		  }
		  else
		  {
		     TEMP = TEMP + "\r\n Enter the name of the Pet"
				     + "\r\n you desire to load into the"
					 + "\r\n INPUT field below and click"
					 + "\r\n the \"LOAD\" button for PET1"
					 + "\r\n to continue.";
			 MainOutput->SetWindowText(TEMP);
			 Input->SetFocus();
             LoadToggle = true;
		  }  
	  }
//------------------------------------------------------------------
      afx_msg void Pet2Load() 
	  { 
		  TEMP = "";
		  if(LoadToggle)
		  {
		     LoadPet(2);
			 Input->SetWindowText(L"");
		     Button_Begin_T->EnableWindow(true);
			 LoadToggle = false;
		  }
		  else
		  {
		     TEMP = TEMP + "\r\n Enter the name of the Pet"
				     + "\r\n you desire to load into the"
					 + "\r\n INPUT field below and click"
					 + "\r\n the \"LOAD\" button for PET2"
					 + "\r\n to continue.";
			 MainOutput->SetWindowText(TEMP);
			 Input->SetFocus();
             LoadToggle = true;
		  }	 
	  }
//------------------------------------------------------------------
	  DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(MegaPet_FORM, CDialog)
	  //ON_WM_TIMER()
      ON_WM_CTLCOLOR()
	  ON_COMMAND(B_QUIT, QUIT)
      ON_COMMAND(B_START, START)
	  ON_COMMAND(B_ENTER, ENTER)
      ON_COMMAND(B_PET1_NEW, NewPet1)
	  ON_COMMAND(B_PET2_NEW, NewPet2)
	  ON_COMMAND(B_BEGIN_TOURNAMENT,BeginTournament)
      ON_COMMAND(B_PET1_SAVE,Pet1Save)
      ON_COMMAND(B_PET2_SAVE,Pet2Save)
	  ON_COMMAND(B_PET1_LOAD,Pet1Load)
      ON_COMMAND(B_PET2_LOAD,Pet2Load)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class MegaPet_Window : public CWinApp
{
public:
MegaPet_Window() {  }
public:
virtual BOOL InitInstance()
{
   CWinApp::InitInstance();
   SetRegistryKey(_T("MegaPet2"));
   MegaPet_FORM MegaPetDialog;
   m_pMainWnd = &MegaPetDialog;
   INT_PTR nResponse = MegaPetDialog.DoModal();
   return FALSE;
} //close function
};

//---------------------------------------------------------------------------------------------------------------------------

MegaPet_Window LetErrRip;  //This starts the ball rolling


//---------------------------------------------------------------------------------------------------------------------------



















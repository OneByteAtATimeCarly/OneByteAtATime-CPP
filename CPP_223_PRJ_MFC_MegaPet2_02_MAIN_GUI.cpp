//PRJ - MegaPet2 - MFC GUI Game - 2006 - C. S. Germany
//File 2 of 4: Main File

//---------------------------------------------------------------------------------------------------------------------------

#include <afxwin.h> // MFC core and standard components
#include <afxcmn.h> // 
#include "resource.h" // main symbols
#include <mmsystem.h>
#include "CPP_222_PRJ_MFC_MegaPet2_01_CLASSES_and_Member_Methods.h" 

//---------------------------------------------------------------------------------------------------------------------------

//A Note: For sound, you must do three things:
//1. Go to project properties, then under Linker, find Input. 
//In the box labelled Aditional Dependancies add "winmm.lib".
//2. Include the file: #include <mmsystem.h> .
//3. Use command: PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC);
//Options: SYNC = ends with function, async = keep playing
//SND_LOOP = loop it, must be stopped then with "StopSound()".
//PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);

//---------------------------------------------------------------------------------------------------------------------------

class MegaPet_FORM : public CDialog
{
public:
MegaPet_FORM (CWnd* pParent = NULL): CDialog(MegaPet_FORM ::IDD, pParent)
{ }

// Dialog Data
enum{IDD = IDD_MegaPet};

protected:
virtual void DoDataExchange(CDataExchange* pDX)
{ CDialog::DoDataExchange(pDX); }

CBrush MegaPetBrush;
CFont PetFont;
HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor) 
{
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(255,0,255));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255,0,255));
case CTLCOLOR_DLG: return MegaPetBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

//Message Map Handlers
virtual BOOL OnInitDialog()
{ 
CDialog::OnInitDialog();
MegaPetBrush.CreateSolidBrush(RGB(255, 255, 255));
pInput = (CEdit *) GetDlgItem(IDC_INPUT);
pOutput = (CEdit *) GetDlgItem(IDC_OUTPUT);
pName = (CEdit *) GetDlgItem(IDC_NAME);
pPetView = (CStatic *) GetDlgItem(IDC_VIEW);
pLife = (CStatic *) GetDlgItem(IDC_LIFE);
pEmotiveState = (CStatic *) GetDlgItem(IDC_EMOTIVESTATE);
pDays = (CStatic *) GetDlgItem(IDC_DAYS);
pGO = (CButton *) GetDlgItem(IDC_GO);
RAGEoMETER = (CSliderCtrl *) GetDlgItem(IDC_RAGEMETER);
pComboBox = (CComboBox *) GetDlgItem(IDC_ComboBoxExample);
pComboBoxButton = (CButton *) GetDlgItem(IDC_ComboBoxButton);
pListBox = (CListBox *) GetDlgItem(IDC_ListBoxExample);
pListBoxButton = (CButton *) GetDlgItem(IDC_ListBoxButton);
Started = false; NeedName = true;
srand(time(NULL));

PetFont.CreatePointFont(150,"Comic Sans MS");
CFont * TheFont = &PetFont;
pOutput->SetFont(TheFont); 
pName->SetFont(TheFont);
pLife->SetFont(TheFont);
pDays->SetFont(TheFont);

//ComboBox
pComboBox->SetWindowText("Various Pet Toys");
pComboBox->AddString("Napalm");
pComboBox->AddString("C4 Explosives");
pComboBox->AddString("Rat Poison");
pComboBox->AddString("Sulfuric Acid");
pComboBox->AddString("Iron Maiden");
pComboBox->AddString("Whip");
pComboBox->AddString("Flailer");

//ListBox
pListBox->SetWindowText("Various Pet Toys");
pListBox->AddString("Napalm");
pListBox->AddString("C4 Explosives");
pListBox->AddString("Rat Poison");
pListBox->AddString("Sulfuric Acid");
pListBox->AddString("Iron Maiden");
pListBox->AddString("Whip");
pListBox->AddString("Flailer");

//Invalidate();
//UpdateWindow();
//Create timer to subtract 1 life point every 10 seconds
return true; 
}

//------------------------------------------------------------

afx_msg void HandleComboBox()
{
int index = pComboBox->GetCurSel();

switch(index)
{ 
case 0 : MessageBox("0"); break;
case 1 : MessageBox("1"); break;
case 2 : MessageBox("2"); break;
case 3 : MessageBox("3"); break;
case 4 : MessageBox("4"); break;
case 5 : MessageBox("5"); break;
case 6 : MessageBox("6"); break;
}

CString TEMP;
pComboBox->GetWindowText(TEMP);
MessageBox(TEMP);

}

//------------------------------------------------------------

afx_msg void HandleListBox()
{
int index = pListBox->GetCurSel();

switch(index)
{ 
case 0 : MessageBox("0"); break;
case 1 : MessageBox("1"); break;
case 2 : MessageBox("2"); break;
case 3 : MessageBox("3"); break;
case 4 : MessageBox("4"); break;
case 5 : MessageBox("5"); break;
case 6 : MessageBox("6"); break;
} 

CString TEMP;
pComboBox->GetWindowText(TEMP);
MessageBox(TEMP);
}

//------------------------------------------------------------

void OnTimer(UINT nIDEvent) 
{ 
Pet->setDays((Pet->getDays() + 1)); 
Pet->setLife((Pet->getLife() - 1));
Pet->View();
strncpy(DISPLAY,"",2000);
Pet->Talk();

if(Pet->getLife() <= 0)
{
KillTimer(1);
pOutput->SetWindowText("\r\n\r\nGame Over.Your pet has died of starvation.");
}

}

//------------------------------------------------------------------
afx_msg void KICK() { if(Started) { Pet->Kick(); } }
//------------------------------------------------------------------
afx_msg void PET() { if(Started) { Pet->Pet(); } }
//------------------------------------------------------------------
afx_msg void TALK() { if(Started) { Pet->Talk(); } }
//------------------------------------------------------------------
afx_msg void SLEEP() { if(Started) { Pet->Sleep(); } }
//------------------------------------------------------------------
afx_msg void FEED() { if(Started) { Pet->Feed(); } }
//------------------------------------------------------------------
afx_msg void PLAY() { if(Started) { Pet->Play(); } }
//------------------------------------------------------------------
afx_msg void GO() 
{
if(Started) 
{ 
if(NeedName) { Pet->SetName(); } 
WRITEME.seekp(0); strncpy(DISPLAY, "", 2000);

Pet->View();

WRITEME << "\r\n" 
<< Pet->getPetName() << " begins its new life with"
<< " you, happy and content...\r\n";

pOutput->SetWindowText(DISPLAY);
SetTimer(1, 8000, 0);
pInput->ShowWindow(false);
pGO->ShowWindow(false);

}
else { MessageBox("You must click \"START\" first.", "So Sorry"); }
}
//------------------------------------------------------------------
afx_msg void START() 
{ 
WRITEME.seekp(0); strncpy(DISPLAY,"",2000);

WRITEME << "\r\nWelcome to MegaPet 2.0.\r\n\r\nTo begin, you must "
<< "a MegaPet.\r\n\r\nGive your new MegaPet a name by typing"
<< " it in the input box above the \"Actions\" buttons."
<< "\r\n\r\nThen when you are ready, click \"GO\" to "
<< "continue.\r\n\r\n";

Pet = new MegaPet;
pEmotiveState->SetWindowText("Loading...");
pName->SetWindowText("Loading...");
pDays->SetWindowText("Loading...");
pLife->SetWindowText("Wait...");
pOutput->SetWindowText(DISPLAY);
Started = true;
}
//------------------------------------------------------------------
afx_msg void QUIT() { EndDialog(IDOK); }
//------------------------------------------------------------------


DECLARE_MESSAGE_MAP()

};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(MegaPet_FORM, CDialog)

    ON_WM_TIMER()
    ON_WM_CTLCOLOR()
    ON_COMMAND(IDC_ComboBoxButton, HandleComboBox)
    ON_COMMAND(IDC_ListBoxButton, HandleListBox)
    ON_COMMAND(IDC_KICK, KICK)
    ON_COMMAND(IDC_PET, PET)
    ON_COMMAND(IDC_TALK, TALK)
    ON_COMMAND(IDC_SLEEP, SLEEP)
    ON_COMMAND(IDC_FEED, FEED)
    ON_COMMAND(IDC_PLAY, PLAY)
    ON_COMMAND(IDC_GO, GO)
    ON_COMMAND(IDC_START, START)
    ON_COMMAND(IDC_QUIT, QUIT)

END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class MegaPet_Window : public CWinApp
{
public:
MegaPet_Window() { }

public:
virtual BOOL InitInstance()
{
CWinApp::InitInstance();
SetRegistryKey(_T("MegaPet"));
MegaPet_FORM MegaPetDialog;
m_pMainWnd = &MegaPetDialog;
INT_PTR nResponse = MegaPetDialog.DoModal();
return FALSE;
} //close function

DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(MegaPet_Window, CWinApp)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

MegaPet_Window LetErrRip; //This starts the ball rolling

//---------------------------------------------------------------------------------------------------------------------------













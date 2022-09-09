//PRJ - RPG Hills of Darkness - MFC GUI Game - 2006 - C. S. Germany
//File 5 of 7: Main File

//---------------------------------------------------------------------------------------------------------------------------

//#include <afxwin.h>                     //MFC core and standard components
//#include "INTERFACE_MAIN_resources.h"   //main symbols

#include "Functions.h"

//---------------------------------------------------------------------------------------------------------------------------

class ShamanMessage : public CDialog
{
public:
ShamanMessage(CWnd* pParent = NULL):
CDialog(ShamanMessage::IDD, pParent) { }

enum{IDD = IDD_SHAMAN};

//Need to create CBrush and use OnCtlColor to change dialog and text color
CBrush ShamanMessageBrush;

HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor)
{
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(255,0,0));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255, 0, 0));
case CTLCOLOR_DLG: return ShamanMessageBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

protected:
virtual void DoDataExchange(CDataExchange* pDX)
{CDialog::DoDataExchange(pDX);}

virtual BOOL OnInitDialog()
{
CDialog::OnInitDialog();
ShamanMessageBrush.CreateSolidBrush(RGB(255, 255, 255));
//Create a Timer to self-destruct the dialog window
SetTimer(1, 3000, 0);
return true;
}

void OnTimer(UINT nIDEvent) { EndDialog(IDOK); }

DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(ShamanMessage, CDialog)
    ON_WM_TIMER()
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class DragonImage : public CDialog
{
public:
DragonImage(CWnd* pParent = NULL): CDialog(DragonImage::IDD, pParent)
{ }

enum{IDD = IDD_DRAGON};

CBrush DragonImageBrush;

HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor)
{
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(255,0,0));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255, 0, 0));
case CTLCOLOR_DLG: return DragonImageBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

protected:
virtual void DoDataExchange(CDataExchange* pDX)
{CDialog::DoDataExchange(pDX);}

virtual BOOL OnInitDialog()
{
CDialog::OnInitDialog();
DragonImageBrush.CreateSolidBrush(RGB(255, 255, 255));
//Create Timer to self-destruct the dialog window
SetTimer(1, 3000, 0);
return true;
}

void OnTimer(UINT nIDEvent) { EndDialog(IDOK); }

DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(DragonImage, CDialog)
    ON_WM_TIMER()
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class SaveChar : public CDialog
{
public:
SaveChar(CWnd* pParent = NULL): CDialog(SaveChar::IDD, pParent)
{ }

enum{IDD = IDD_SAVE};

CBrush SaveBrush;

HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor)
{
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(255,255,255));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255, 255, 255));
pDC->SetBkMode(TRANSPARENT);
case CTLCOLOR_DLG: return SaveBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

afx_msg void SaveIt()
{
pSaveName = ( CEdit * ) GetDlgItem( IDC_SaveName );
pSavePassword = ( CEdit * ) GetDlgItem( IDC_SavePassword );
bool success;
success = SaveCharacter();
if(success)
{
MessageBox(L"Your character was saved successfully!",
L"Character Saved Successfully!");
}
else
{
MessageBox(L"Your character could not be saved, for some reason.",
L"Error! Character Could Not Be Saved.");
}
}

protected:
virtual void DoDataExchange(CDataExchange* pDX)
{CDialog::DoDataExchange(pDX);}

virtual BOOL OnInitDialog()
{
CDialog::OnInitDialog();
SaveBrush.CreateSolidBrush(RGB(0, 0, 255));
return true;
}

DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(SaveChar, CDialog)
    ON_WM_CTLCOLOR()
    ON_COMMAND(IDSAVEOK, SaveIt)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class LoadChar : public CDialog
{
public:
LoadChar(CWnd* pParent = NULL): CDialog(LoadChar::IDD, pParent)
{ }

enum{IDD = IDD_LOAD};

CBrush LoadBrush;

HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor)
{
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(255,255,255));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255, 255, 255));
pDC->SetBkMode(TRANSPARENT);
case CTLCOLOR_DLG: return LoadBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

afx_msg void LoadIt()
{
pLoadName = ( CEdit * ) GetDlgItem( IDC_LoadName );
pLoadPassword = ( CEdit * ) GetDlgItem( IDC_LoadPassword );
bool success; CString problem;

success = LoadCharacter(problem);
if(success)
{
MessageBox(L"Your character was loaded successfully!",
L"Character Loaded Successfully!");
}
else
{
MessageBox(problem, L"Error! Character Could Not Be Loaded.");
}
}

afx_msg void ExitLoad() { EndDialog(IDOK); }

protected:
virtual void DoDataExchange(CDataExchange* pDX)
{CDialog::DoDataExchange(pDX);}

virtual BOOL OnInitDialog()
{
CDialog::OnInitDialog();
LoadBrush.CreateSolidBrush(RGB(0, 0, 255));
return true;
}

DECLARE_MESSAGE_MAP()
};

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(LoadChar, CDialog)
    ON_WM_CTLCOLOR()
    ON_COMMAND(IDLOADOK, LoadIt)
    ON_COMMAND(IDLOADCANCEL, ExitLoad)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------


//The Main Dialog

class HOD_Main_Window : public CDialog
{
public:
HOD_Main_Window(CWnd* pParent = NULL): CDialog(HOD_Main_Window::IDD, pParent)
{

}

// Dialog Data
enum{IDD = HillsOfDark};

protected:
//------------------------------------------------------------------
virtual void DoDataExchange(CDataExchange* pDX)
{ CDialog::DoDataExchange(pDX); }
//------------------------------------------------------------------

CBrush MainDialogBrush; //Need for coloring dialog
CFont AFont; //Ned for setting font

//------------------------------------------------------------------
//Set Colors of Dialog
HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
switch (nCtlColor)
{
case CTLCOLOR_BTN:
case CTLCOLOR_LISTBOX:
case CTLCOLOR_MSGBOX:
case CTLCOLOR_SCROLLBAR:
case CTLCOLOR_EDIT: pDC->SetTextColor(RGB(0,0,255));
case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(0, 0, 255));
//pDC->SetBkColor(RGB(255, 255, 255));
//pDC->SetBkMode(TRANSPARENT);
case CTLCOLOR_DLG: return MainDialogBrush;
default: return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
}

//------------------------------------------------------------------
//Message Map Handlers, assign global pointers to the Dialog controls
virtual BOOL OnInitDialog()
{
CDialog::OnInitDialog();

MainDialogBrush.CreateSolidBrush(RGB(255, 255, 255));
AFont.CreatePointFont(110,L"Comic Sans MS");

pInput = ( CEdit * ) GetDlgItem(IDC_INPUT);
pOutput = ( CEdit * ) GetDlgItem(IDC_OUTPUT);
pScore = ( CStatic * ) GetDlgItem( IDC_SCORE );
pInventory = ( CEdit * ) GetDlgItem( IDC_INVENTORY );
pHitpoints = ( CStatic * ) GetDlgItem( IDC_HITPOINTS );
pAttack = ( CStatic * ) GetDlgItem( IDC_ATTACK );
pDefense = ( CStatic * ) GetDlgItem( IDC_DEFENSE );
pConquests = ( CEdit * ) GetDlgItem( IDC_CONQUESTS );
pName = ( CStatic * ) GetDlgItem( IDC_NAME );
pView = ( CStatic * ) GetDlgItem( IDC_VIEW );

pDagger = ( CButton * ) GetDlgItem( IDC_RADIODAGGER );
pSword = ( CButton * ) GetDlgItem( IDC_RADIOSWORD );
pLongBow = ( CButton * ) GetDlgItem( IDC_RADIOBOW );
pHand = ( CButton * ) GetDlgItem( IDC_RADIOHAND );

pN = ( CButton * ) GetDlgItem( IDC_NORTH );
pS = ( CButton * ) GetDlgItem( IDC_SOUTH );
pE = ( CButton * ) GetDlgItem( IDC_EAST );
pW = ( CButton * ) GetDlgItem( IDC_WEST );
pSCORES = ( CButton * ) GetDlgItem( IDCHISCORES );
pSAVE = ( CButton * ) GetDlgItem( IDCSAVE );
pLOAD = ( CButton * ) GetDlgItem( IDCLOAD );
pSTART = ( CButton * ) GetDlgItem( IDCSTART );
pGO = ( CButton * ) GetDlgItem( IDGO );
pACTION = ( CButton * ) GetDlgItem( IDCACTION );
pHEAL = ( CButton * ) GetDlgItem( IDD_HEAL );

InitializeGlobals();
pOutput->SetWindowText(L"\r\nClick the \"START\" button to begin.");

return true;
}//close OnInitDialog() function



public:
//Functions for Messages

afx_msg void QuitTheGame()
{
if(StartedGame)
{
bool successful;
successful = SaveHighScores();

if(successful)
{
MESSAGE = MESSAGE + "\r\nScore saved to \"highscores.txt\".\r\n";
}
else
{
MESSAGE = MESSAGE + "\r\nScore saved to \"highscores.txt\".\r\n";
}

MESSAGE = MESSAGE + "\r\nScore saved to \"highscores.txt\".\r\n"; "\r\nExiting Hills of Darkness 2.0\r\n";

delete CurrentPlayer;
delete WiseWoman;
CurrentPlayer = 0;
WiseWoman = 0;
pOutput->SetWindowText(MESSAGE);
}

EndDialog(IDOK);
}
//------------------------------------------------------------------

afx_msg void GO()
{

if(StartedGame)
{
if(NeedName)
{
CString n;
pInput->GetWindowText(n);
CurrentPlayer->setName(n);
pName->SetWindowText(n);
NeedName = false;
}

if(Continue)
{
WEAPONS();

if(!LOCK)
{
choice[0] = '#';

switch(location)
{
case INTRO : location = Introduction(); break;
case N1 : location = NORTH1(); break;
case S1 : location = SOUTH1(); break;
case E1 : location = EAST1(); break;
case W1 : location = WEST1(); break;
case CENTER1 : location = CENTER(); break;
case N2 : location = NORTH2(); break;
case S2 : location = SOUTH2(); break;
case E2 : location = EAST2(); break;
case W2 : location = WEST2(); break;
case UNDERGRND : location = UnderGroundPassage(); break;
case GATE : location = GateWay(); break;
case SHAMAN : location = SHAMANHUT(); break;
case DRAGONFIGHT : location = DragonFight(); break;
case GIANTFIGHT : location = GiantFight(); break;
case GIANTCAMP : location = GiantCamp(); break;
case GAMEOVER : location = GameOver(); break;
case YOUWIN : location = YouWin(); break;
case QUIT : Continue = false; break;
default : MESSAGE = MESSAGE + "\r\nNot an NAV option.\r\n"; break;
}//close switch

CurrentPlayer->DisplayStats();
CurrentPlayer->Inventory();

}//close if for "LOCK = false" (Unlocked)

else
{
//Begin else for "LOCK = true" (Locked)
CString TEMP;
pInput->GetWindowText(TEMP);
choice[0] = (char)TEMP[0];
choice[0] = tolower(choice[0]);
pInput->SetWindowText(L"");
pInput->SetFocus();

MESSAGE = "";

switch(location)
{
case INTRO : location = Introduction(); break;
case N1 : location = NORTH1(); break;
case S1 : location = SOUTH1(); break;
case E1 : location = EAST1(); break;
case W1 : location = WEST1(); break;
case CENTER1 : location = CENTER(); break;
case N2 : location = NORTH2(); break;
case S2 : location = SOUTH2(); break;
case E2 : location = EAST2(); break;
case W2 : location = WEST2(); break;
case UNDERGRND : location = UnderGroundPassage(); break;
case GATE : location = GateWay(); break;
case SHAMAN : location = SHAMANHUT(); break;
case DRAGONFIGHT : location = DragonFight(); break;
case GIANTFIGHT : location = GiantFight(); break;
case GIANTCAMP : location = GiantCamp(); break;
case GAMEOVER : location = GameOver(); break;
case YOUWIN : location = YouWin(); break;
case QUIT : Continue = false; break;
default : MESSAGE = MESSAGE
+ "\r\nNot a NAV option.\r\n"; break;
}//close switch

//If choice is valid, recursively call GO() to proceed to next function
if(choice[0] == 'n' || choice[0] == 's' ||
choice[0] == 'e' || choice[0] == 'w' ||
choice[0] == 't' || choice[0] == 'r' ||
choice[0] == 'l' || choice[0] == 'g')
{
GO();
}

}//close else for "LOCK"

}//close if for "Continue = true"

else
{ //If "Continue = false"
QuitTheGame();
}

} //close if for "StartedGame = true", if not started, handle click, don't crash

else
{
MESSAGE = "";
MESSAGE = MESSAGE +
"\r\nSorry, you can not press the \"GO\" button yet."
+ "\r\nYou need to click on the \"START\" button\r\nto "
+ "begin the game!";
pOutput->SetWindowText(MESSAGE);
}
}//close the GO button function

//------------------------------------------------------------------

afx_msg void START()
{
//Start new unless in middle of a game, else confirm player really wants to start over

if(!StartedGame)
{
AFunctionPointer1 = ShowShamanMessage;
AFunctionPointer2 = ShowDragon;

InitializeGlobals(); LockButtons(false);
pHand->SetCheck(1); //Default check

MESSAGE = "";

//To set the font on an object you must create a CFont instance.
CFont * TheFont = &AFont;
pOutput->SetFont(TheFont);
pName->SetFont(TheFont);

pInput->SetWindowText(L"Enter your name HERE.");
pInput->SetFocus(); //Changes Focus
pInput->SetSel(0, -1, false); //selects Text to conveniently delete when user types

CString MESSAGE = "";
MESSAGE = MESSAGE +
"\r\nWelcome to Hills of Darkness 3.0. You need to create "
+ "a character and select a name. The object of this game "
+ "is to collect enough items and gain enough experience to "
+ "operate the dimensional gateway and return home. You will "
+ "also need to find a key to activate this mechanism. You "
+ "may ask the village shaman for help and useful advice on "
+ "our journey. \r\n\r\n\r\nType your name in the box to the "
+ "right.\r\nThen begin he game by pressing the \"GO\" button."
+ "\r\n\r\n\r\n";

srand((int)time(NULL)); //seed for random numbers

pOutput->SetWindowText(MESSAGE);
pConquests->SetWindowText(L"Loading...");

CurrentPlayer = new Player;
WiseWoman = new Shaman;
WEAPONS();
StartedGame = true;

}//close if for "StartedGame=false"

else
{
NagMe = MessageBox(L"You are in the middle of a game. Are you sure?",
L"Start Over?", MB_YESNOCANCEL|MB_ICONINFORMATION);

if(NagMe == IDYES)
{
InitializeGlobals(); //If user clicks again, initialize
START();
}

}

}//close START() function

//------------------------------------------------------------------

afx_msg void LOAD()
{
if(StartedGame)
{
//Code Necessary to Open the Save Character Dialog
LoadChar LOAD_EM;
LOAD_EM.DoModal();
StartedGame = true;
LOCK = true; GO();
}
else
{
MessageBox(L"Click the START button first, then load your character.",
L"Click the START button first!");
}
}
//------------------------------------------------------------------

afx_msg void SAVE()
{
if(StartedGame)
{
//Code Necessary to Open the Save Character Dialog
CurrentPlayer->setLocation(location);
SaveChar SAVE_EM;
SAVE_EM.DoModal();
StartedGame = true;
}
else
{
MessageBox(L"You can't save a character when a it does not exist!",
L"Mindless Error!!!");
}
}

//------------------------------------------------------------------

afx_msg void DISPLAYSCORES()
{
if(!HiScoresToggle && StartedGame) { GO(); HiScoresToggle = true; }
else { DisplayHighScores(); HiScoresToggle = false; }
}

//------------------------------------------------------------------

afx_msg void HEAL() {if(StartedGame) {CurrentPlayer->UseHealingPotion();}}

//------------------------------------------------------------------

afx_msg void NORTH()
{
if(StartedGame)
{ pInput->SetWindowText(L"n"); LOCK = true; GO(); }
}
//------------------------------------------------------------------

afx_msg void SOUTH()
{
if(StartedGame)
{ pInput->SetWindowText(L"s"); LOCK = true; GO(); }
}
//------------------------------------------------------------------

afx_msg void EAST()
{
if(StartedGame)
{ pInput->SetWindowText(L"e"); LOCK = true; GO(); }
}
//------------------------------------------------------------------

afx_msg void WEST()
{
if(StartedGame)
{ pInput->SetWindowText(L"w"); LOCK = true; GO(); }
}
//------------------------------------------------------------------

afx_msg void ABOUT()
{
MessageBox(L"Hills of Darkness 3.0 - C. Germany 2006",
L"Hills of Darkness 3.0");
}
//------------------------------------------------------------------

afx_msg void HELP()
{
char HELPTEXT[15][55] = {
"The object of this game is to collect enough",
" items\nand gain enough experience to operate",
" the\ndimensional gateway and return home.",
" You will\nalso need to find a key to activate",
" the gate\nmechanism. You may ask the village ",
"shaman\nfor help and useful advice on your journey.",
"\n\nFor every three opponents you defeat, \"1\" will",
"\nbe added to your Attack and Defense capabilities.",
"\nThis represents the natural skill you acquire as",
"\na result of combat, and is independent of and in",
"\naddition to any defense or attack capabilities",
"\nyou gain through the use of armor and weapons. In",
"\naddition to your attack/defense skills acquired",
"\nthrough experience, if you find armor and weapons,",
"\nthey will also add to your abilities." };

char Message[800] = "";

for(int z = 0; z < 15; z++)
{ strncat_s(Message, HELPTEXT[z], 55); }

MessageBox((LPCTSTR)Message, L"Hills of Darkness 3.0 - HELP");

}
//------------------------------------------------------------------

afx_msg void WEAPONS()
{
//Moved here so player can change weapons while in combat
if(Continue && StartedGame)
{
//Disable Radio Buttons if Player Doesn't Have the Weapon
if(CurrentPlayer->getDagger())
{ pDagger->EnableWindow(1); }
else
{ pDagger->EnableWindow(0); }

if(CurrentPlayer->getSword())
{ pSword->EnableWindow(1); }
else
{ pSword->EnableWindow(0); }

if(CurrentPlayer->getLongBow())
{ pLongBow->EnableWindow(1); }
else
{ pLongBow->EnableWindow(0); }

int weapon = GetCheckedRadioButton(IDC_RADIOHAND, IDC_RADIOBOW);

switch(weapon)
{
case IDC_RADIOHAND: CurrentPlayer->setUseDagger(false);
CurrentPlayer->setUseSword(false);
CurrentPlayer->setUseLongBow(false);
break;
case IDC_RADIODAGGER: if(CurrentPlayer->getDagger())
{
CurrentPlayer->setUseDagger(true);
CurrentPlayer->setUseSword(false);
CurrentPlayer->setUseLongBow(false);
}
break;
case IDC_RADIOSWORD: if(CurrentPlayer->getSword())
{
CurrentPlayer->setUseSword(true);
CurrentPlayer->setUseDagger(false);
CurrentPlayer->setUseLongBow(false);
}
break;
case IDC_RADIOBOW: if(CurrentPlayer->getLongBow())
{
CurrentPlayer->setUseLongBow(true);
CurrentPlayer->setUseDagger(false);
CurrentPlayer->setUseSword(false);
}
break;
default: CurrentPlayer->setUseDagger(false);
CurrentPlayer->setUseSword(false);
CurrentPlayer->setUseLongBow(false);
break;
}//close switch

}//close if

}//close function
//------------------------------------------------------------------

//Must be defined as static - they both use function pointers
static void ShowDragon() { DragonImage m; m.DoModal(); }
//------------------------------------------------------------------

static void ShowShamanMessage() { ShamanMessage m; m.DoModal(); }
//------------------------------------------------------------------

afx_msg void ACTION() { /*Empty, for later use*/ }
//------------------------------------------------------------------

DECLARE_MESSAGE_MAP()
};

//Main Dialog Message Map-------------------------------------------
BEGIN_MESSAGE_MAP(HOD_Main_Window, CDialog)

ON_COMMAND(IDCQUIT, QuitTheGame)
ON_COMMAND(IDGO, GO)
ON_COMMAND(IDCACTION, ACTION)
ON_COMMAND(IDCSTART, START)
ON_COMMAND(IDCSAVE, SAVE)
ON_COMMAND(IDCLOAD, LOAD)
ON_COMMAND(IDCHISCORES, DISPLAYSCORES)
ON_COMMAND(IDD_HEAL, HEAL)
ON_COMMAND(IDC_NORTH, NORTH)
ON_COMMAND(IDC_SOUTH, SOUTH)
ON_COMMAND(IDC_EAST, EAST)
ON_COMMAND(IDC_WEST, WEST)
ON_COMMAND(ID_FILE_SAVEGAME, SAVE)
ON_COMMAND(ID_FILE_LOADGAME, LOAD)
ON_COMMAND(ID_OTHER_HELP, HELP)
ON_COMMAND(ID_OTHER_ABOUT, ABOUT)
ON_COMMAND(ID_FILE_EXIT, QuitTheGame)
ON_COMMAND(IDCHELP, HELP)
ON_COMMAND(IDC_RADIOHAND, WEAPONS)
ON_COMMAND(IDC_RADIODAGGER, WEAPONS)
ON_COMMAND(IDC_RADIOSWORD, WEAPONS)
ON_COMMAND(IDC_RADIOBOW, WEAPONS)
ON_WM_CTLCOLOR()

END_MESSAGE_MAP()

//------------------------------------------------------------------------------

class TheGame : public CWinApp
{
public:
TheGame() { }

public:
virtual BOOL InitInstance()
{
CWinApp::InitInstance();
SetRegistryKey(_T("Charles Germany"));
HOD_Main_Window dlg;
m_pMainWnd = &dlg;
INT_PTR nResponse = dlg.DoModal();
return FALSE;
}//close function
};
//------------------------------------------------------------------------------

TheGame theApp;

//---------------------------------------------------------------------------------------------------------------------------











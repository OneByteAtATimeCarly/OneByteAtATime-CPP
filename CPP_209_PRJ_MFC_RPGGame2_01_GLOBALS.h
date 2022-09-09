//PRJ - RPG Hills of Darkness - MFC GUI Game - 2006 - C. S. Germany
//File 1 of 7: GLOBALS

//Globals, Prototypes and Game State Variables

//---------------------------------------------------------------------------------------------------------------------------

#include <afxwin.h> // MFC core and standard components
#include "INTERFACE_MAIN_resources.h" // main symbols
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <mmsystem.h>
#include "MFCsleep.h"   //Multi-threading, necessary for pauses
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Enumerated Constant for Player Location
enum EVENTS {INTRO, QUIT, GAMEOVER, YOUWIN, SHAMAN, GATE, UNDERGRND, GIANTCAMP,
GIANTFIGHT, DRAGONFIGHT, CENTER1, N1, S1, E1, W1, N2, S2, E2, W2};

//---------------------------------------------------------------------------------------------------------------------------

//Track dialog behavior
bool LOCK;
bool NeedName;
bool Continue;
bool HiScoresToggle;
char choice[1];
int ConqueredDragons;
int ConqueredGiants;

//---------------------------------------------------------------------------------------------------------------------------

//Track various game events
bool W1GiantAlive;
bool E1DragonAlive;
bool S2MotleyCrewAlive;
bool FirstTimeInShamanHut;
bool CENTERFirstTime;
bool UNDERDragonPairAlive;
bool FoundHP_West2;
bool FoundHP_Shaman;


//---------------------------------------------------------------------------------------------------------------------------

//Game State
bool StartedGame;
int GoEvent;
int NagMe;
int location; //Note: Now location must be global since event-based input


//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype Used in Classes
int Randy(int n);


//---------------------------------------------------------------------------------------------------------------------------

//2 Function Pointers for Dialog Popups
void (* AFunctionPointer1)();
void (* AFunctionPointer2)();

//---------------------------------------------------------------------------------------------------------------------------

//Class Prototypes
class Monster;
class Character;
class Player;
class Dragon;
class Giant;
class Shaman;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void InitializeGlobals();
int Introduction();
int Combat(Dragon * m, EVENTS CurrentLocation);
int Combat(Giant * m, EVENTS CurrentLocation);
int CENTER();
int NORTH1();
int SOUTH1();
int EAST1();
int WEST1();
int NORTH2();
int SOUTH2();
int EAST2();
int WEST2();
int SHAMANUT();
int GateWay();
int UnderGroundPassage();
int GiantCamp();
int DragonFight();
int GiantFight();
void Conquests();
void LockButtons(bool x);
int GameOver();
int YouWin();
bool SaveCharacter();
bool LoadCharacter(CString & problem);
bool SaveHighScores();
void DisplayHighScores();

//---------------------------------------------------------------------------------------------------------------------------

//Global Pointers to Keep Character and Shaman on Heap
Character * CurrentPlayer;
Shaman * WiseWoman;

//---------------------------------------------------------------------------------------------------------------------------

//Dialog Globals for MFC Window and Controls
CString MESSAGE;
CString INVENTORY;
CString CONQUESTS;

//---------------------------------------------------------------------------------------------------------------------------

//Interface Globals (MFC)
CEdit * pInput;
CEdit * pOutput;
CStatic * pScore;
CEdit * pInventory;
CStatic * pHitpoints;
CStatic * pAttack;
CStatic * pDefense;
CStatic * pName;
CEdit * pConquests;
CStatic * pView;

CEdit * pSaveName;
CEdit * pSavePassword;
CEdit * pLoadName;
CEdit * pLoadPassword;

CButton * pDagger;
CButton * pSword;
CButton * pLongBow;
CButton * pHand;

CButton * pN;
CButton * pS;
CButton * pE;
CButton * pW;
CButton * pSCORES;
CButton * pSAVE;
CButton * pLOAD;
CButton * pSTART;
CButton * pGO;
CButton * pACTION;
CButton * pHEAL;

//---------------------------------------------------------------------------------------------------------------------------











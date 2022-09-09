//PRJ - MegaPet3 - MFC GUI Game - 2006 - C. S. Germany
//File 1 of 7: GLOBALS

//---------------------------------------------------------------------------------------------------------------------------

#include <string>
#include <windows.h>
#include <strstream>
#include <mmsystem.h>
#include <fstream>
#include "CPP_230_PRJ_MFC_MegaPet3_04_MFCSleep_Multithreading.h"
using namespace std;

//Create MFC streaming text like console's cout <<

//---------------------------------------------------------------------------------------------------------------------------

CString TEMP;
CString Pet1TEMP;
CString Pet2TEMP;

//---------------------------------------------------------------------------------------------------------------------------

//Colors and Fonts
CBrush PetBrush_BLACK;
CBrush PetBrush_WHITE;
CBrush PetBrush_RED;
CBrush PetBrush_BLUE;
CFont PetFont1;
CFont PetFont2;

//---------------------------------------------------------------------------------------------------------------------------

//CBitmapButtons
CBitmapButton * Button_Start;
CBitmapButton * Button_Exit;

//---------------------------------------------------------------------------------------------------------------------------

//Generic Interface Pointers
CEdit * MainOutput;
CEdit * Input;
CButton * Button_Begin_T;
CButton * Button_End_T;
CButton * Button_Help;
CButton * Button_Enter;
//Pet1 Interface Pointers
CSliderCtrl * Pet1_HealthMeter;
CProgressCtrl * Pet1_HealthBar;
CEdit * Pet1_Status;
CStatic * Pet1View;
CStatic * Pet1_Box_Name;
CStatic * Pet1_Box_Species;
CStatic * Pet1_Box_Health;
CStatic * Pet1_Box_Speed;
CStatic * Pet1_Box_Strength;
CStatic * Pet1_Box_Attack;
CStatic * Pet1_Box_Defense;
CStatic * Pet1_Box_SpecialDefense;
CStatic * Pet1_Box_SpecialAttack;
CStatic * Pet1_Box_SpecAbilEnergy;
CButton * Pet1_Button_LOAD;
CButton * Pet1_Button_SAVE;
CButton * Pet1_Button_NEW;
CButton * Pet1_Button_TRAIN;
CButton * Pet1_Button_FEED;
CButton * Pet1_Button_PLAY;
CButton * Pet1_Button_TALK;
CButton * Pet1_Button_SLEEP;
CButton * Pet1_Button_KICK;
CButton * Pet1_Button_ATTACK;
CButton * Pet1_Button_DEFEND;
CButton * Pet1_Button_SPECATTACK;
CButton * Pet1_Button_SPECDEFEND;
//Pet2 Interface Pointers
CSliderCtrl * Pet2_HealthMeter;
CProgressCtrl * Pet2_HealthBar;
CEdit * Pet2_Status;
CStatic * Pet2View;
CStatic * Pet2_Box_Name;
CStatic * Pet2_Box_Species;
CStatic * Pet2_Box_Health;
CStatic * Pet2_Box_Speed;
CStatic * Pet2_Box_Strength;
CStatic * Pet2_Box_Attack;
CStatic * Pet2_Box_Defense;
CStatic * Pet2_Box_SpecialDefense;
CStatic * Pet2_Box_SpecialAttack;
CStatic * Pet2_Box_SpecAbilEnergy;
CButton * Pet2_Button_LOAD;
CButton * Pet2_Button_SAVE;
CButton * Pet2_Button_NEW;
CButton * Pet2_Button_TRAIN;
CButton * Pet2_Button_FEED;
CButton * Pet2_Button_PLAY;
CButton * Pet2_Button_TALK;
CButton * Pet2_Button_SLEEP;
CButton * Pet2_Button_KICK;
CButton * Pet2_Button_ATTACK;
CButton * Pet2_Button_DEFEND;
CButton * Pet2_Button_SPECATTACK;
CButton * Pet2_Button_SPECDEFEND;

//---------------------------------------------------------------------------------------------------------------------------

//Class Prototypes
class Pet;
class Animal;
class Plant;
class Mammal;
class Reptile;
class Amphibian;
class HYBRID;
class SNAKE;
class RABBIT;
class SNABBIT;
class LIGER;
class FRANTHER;
class JONKEY;
class CROG;
class SQUEEL;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
CString CONVERT(string X);
char * CS_To_CharArray(CString CS);
void CS_To_CharArray(CString CS, char * SimpleString);
int CS_To_Number(CString CS);
CString Number_To_CS(int NUM);
void Initialize_Interface();
void CreatePet();
void SavePet(Pet * PLAYER);
void LoadPet(int ThePet);
void Combat();
//Universal Globals
Pet * PET1;
Pet * PET2;
bool NeedToCreatePets;
bool LoadToggle;
int CreatePetSequence;
//Directories for Media Files
CString PetImageDirectory;
CString PetAudioMusicDirectory;
CString PetAudioSoundEffectsDirectory;
int Max_Damage;

//---------------------------------------------------------------------------------------------------------------------------


/*

Notes: Using CBitmap buttons.
1. Create or find the bitmaps for your buttons.
2. Add them to the resource ".rc" file using resource tab and "add resource".
3. Make your CBitmapButton pointers.
4. Add CButtons to the resource file.
5. Set the type of the button to "bitmap".
4. Set the pointers up on the interface sith GetDlgItem().
5. Build instances of the buttons on the heap with "new".
6. Call the following functions (x,y,width,height):
Button_Start->Create(NULL, WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, 
		      CRect(10,10,10,10), this, IDC_ResourceNameOfButton);
Button_Start->LoadBitmaps(IDB_BitmapName);
Button_Start->SizeToContent();
7. Add the "IDC_ResourceNameOfButton" as an entry to the resource.h file
   unless Visual Studio added for you in the resource editor.
8. Map it in the message map tags.
9. Create a message handler function.
//------------------------------------------------------------------
Notes: Using SOUND.
        //A Note: For sound, you must do three things:
        //1. Go to project properties, then under Linker, find Input. 
        //In the box labelled Aditional Dependancies add "winmm.lib".
        //2. Include the file: #include <mmsystem.h> .
        //3. Use command: PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC);
        //Options: SYNC = ends with function, async = keep playing
        //SND_LOOP = loop it, must be stopped then with "StopSound()".
        //PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
//------------------------------------------------------------------
//Example of Timer inside CDialog class 
void OnTimer(UINT nIDEvent) 
{ 
	Pet->setDays((Pet->getDays() + 1));	
	Pet->setLife((Pet->getLife() - 1));
	Pet->View();
	strncpy(DISPLAY,"",2000);
	Pet->Talk();
	if(Pet->getLife()  <= 0)
    {
	  KillTimer(1);
	  pOutput->SetWindowText("\r\n\r\nGame Over.Your pet has died of starvation.");
    }
}

*/

//---------------------------------------------------------------------------------------------------------------------------















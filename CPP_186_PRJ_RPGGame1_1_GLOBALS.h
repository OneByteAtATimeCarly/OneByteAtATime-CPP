//PRJ - RPGGame1 - Globals - 2006 - C. S. Germany
//Hills of Darkness (HOD) C. S. Germany, March 16, 2007
//File 1 of 4


//---------------------------------------------------------------------------------------------------------------------------

//Globals
const int CombatPause = 3000;

const int MaxDamage = 25;
const int DaggerDamage = 2;
const int StaffDamage = 3;
const int LongBowDamage = 4;
const int CrossBowDamage = 6;
const int BroadSwordDamage = 10;

const int Magic_FireDamage = 10;
const int Magic_Fire_Cost = 10;
const int Magic_IceDamage = 10;
const int Magic_Ice_Cost = 10;
const int Magic_LightningDamage = 15;
const int Magic_LightningDamage_Cost = 15;
const int Magic_TelekineticDamage = 20;
const int Magic_TelekineticDamage_Cost = 20;
const int Magic_InvisibilityDefense = 1;
const int Magic_InvisibilityDefense_Cost = 30;
const int Magic_HealAmount = 20;
const int Magic_HealAmount_Cost = 30;

const int HP_Restore_Amt = 40;

//               0     1   2  3  4  5  6
enum LOCATIONS{QUIT,INTRO,C1,N1,S1,E1,W1,GATE,SHAMANS_HUT,N2,S2,E2,W2,UNDERGRND};
enum ENTITY_CLASSES{DRAGON,GIANT,SHAMAN,WARRIOR,MAGE,FIGHTER,ELF};
enum WEAPONS{nothing,broadsword,dagger,crossbow,longbow,staff};
enum MAGIC{nomagic,fire,ice,lightning,telekinetic_force,invisibility,healing};
enum ARMOR{NO_ARMOR,CHAIN_MAIL,PLATE_MAIL};

int location;

//Booleans for Inventory Items
bool CENTERFirstTime;
bool FoundHealingPotion;
bool S1DragonAlive;
bool E1DragonAlive;
bool W1GiantAlive;
bool FirstTimeInShamanHut;
bool FoundHP_Shaman;
bool UNDERDragonPairAlive;
bool S2MotleyCrewAlive;
bool FoundHP_West2;

//Class ProtoTypes
class ENTITY;
class Monster;
class Character;
class Player;
class Shaman;
class Giant;
class Dragon;
class Warrior;
class Mage;
class Fighter;
class Elf;

//Function ProtoTypes
void SwitchBoard();
void INTRODUCTION();
void CENTER1();
void NORTH1();
void SOUTH1();
void EAST1();
void WEST1();
void NORTH2();
void SOUTH2();
void EAST2();
void WEST2();
void GATES();
void Shamans_Hut();
void UnderGroundPassage();
void OPTIONS();
void COMBAT(ENTITY * x, ENTITY * y);
void SaveCharacter();
bool LoadCharacter();
void SaveHighScores(); 
void DisplayHighScores(); //Bubble Sort
void Setup_Character();
void RoleHelp();
void PAUSE();

//Character and Monster Objects
Character * The_Player;
Dragon * A_Dragon;
Giant * A_Giant;
Shaman * Wise_Woman;

//---------------------------------------------------------------------------------------------------------------------------



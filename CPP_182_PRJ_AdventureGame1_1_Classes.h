//PRJ - AdventureGame1 - Classes - 2004 - C. S. Germany
//File 1 of 3

//---------------------------------------------------------------------------------------------------------------------------

//Includes you need to compile with .Net Visual Studio or VS 6.0
//#include <ctime>
//#include <string>
//#include <windows.h>
//#include <iostream>
//#include <iomanip>
//#include <fstream>

//Includes you need to compile with BloodShed 5.0
#include <cstdlib>
#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Globals - An Enumerated Constant to Store Player Location
enum EVENTS{QUIT, SHAMAN, GATE, UNDERGRND, CENTER1, N1, S1, E1, W1, N2, S2, E2, W2};
bool Continue;

//Globals to track various game events
bool W1GiantAlive;
bool E1DragonAlive;
bool S2MotleyCrewAlive;
bool FirstTimeInShamanHut;
bool CENTERFirstTime;
bool UNDERDragonPairAlive;
bool FoundHP_West2;
bool FoundHP_Shaman;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype Used in Classes
int Randy(int n);

//---------------------------------------------------------------------------------------------------------------------------

//A Base class

class Monster
{
   public:
   Monster(int hp=20, int atk = 1, int def=1)
   { 
     cout << "\n\tCreating a BASE class monster.";
     hitpoints = hp; atak = atk; defense = def; 
   }
   ~Monster()
   { cout << "\n\tDestroying BASE class monster."; }

   
   //Accessor Methods
   void setHit(int hp) { hitpoints = hp; }
   void setAttack(int atk)  { atak = atk; }
   void setDefense(int def) { defense = def; }
   void setName(char * nm) { name = nm; }
   int getHit() { return hitpoints; }
   int getAttack()  { return atak; }
   int getDefense() { return defense; } 
   char * getName() { return name; }  
          
   private: 
   int hitpoints;
   int atak;
   int defense;
   char * name;               
      
};

//---------------------------------------------------------------------------------------------------------------------------

//Base Class for Characters and Players. Would allow player
//to travel with companions and interact if expanded further

class Character
{
   public:
   Character(int Hp = 25, int Atk = 1, int Def = 1, string nm = "Character")
   { 
     cout << "\tCreating a Character.\n";
     hitpoints = Hp; atak = Atk; defense = Def; CharName = nm; level = 0;
     InitializeInventory();
     setScore(0);
   }
   ~Character()
   { cout << "\tDestroying a Character.\n";  } 
   
   void DisplayStats()
   {
       cout << "\n\t*********************** Stats ***********************\n"
            << "\t" << CharName << ":    " << "Hit: " << hitpoints 
            << "    " << "Attack: " << atak << "    "
            << "Defense: " << defense << "\n"
            << "\t*****************************************************";         
   }
   
   void InitializeInventory()
   {   
        dagger = false;
        sword = false;
        longbow = false;
        chainmail= false;
        fullbodyarmor= false;               
        healingpotion = 0;
        FishKey = false;      
   }
   
   void Inventory()
   {
      cout << "\n\n\t\t\t***********************************\n"
           << "\t\t\t*        Current Inventory:       *\n"
           << "\t\t\t***********************************\n";
      cout << "\t\t\t*                                 *\n"; 
      if(dagger) { cout << "\t\t\t*  Dagger (+ 2 Attack)            *\n"; }
      if(sword) { cout << "\t\t\t*  Sword (+ 4 Attack)             *\n"; }
      if(longbow) { cout << "\t\t\t*  Long Bow (+2 over Distance)    *\n"; }
      if(chainmail) { cout << "\t\t\t*  Chain Mail (+ 2 Defense)       *\n"; }
      if(fullbodyarmor) { cout << "\t\t\t*  Full Body Armor (+4 Defense)   *\n"; }
      if(healingpotion > 0) 
	  { 
		  cout << "\t\t\t*  Healing Potion (+20HP)  Amt: " 
	           << healingpotion << " *\n"; 
	  }
      if(FishKey) { cout << "\t\t\t*  Fish Key (Access to Objects)   *\n"; }
      if(!dagger && !sword && !longbow && !chainmail && !fullbodyarmor && !healingpotion && ! FishKey)
      { cout << "\t\t\t*   How sad, absolute nothing!    *\n"; }
      cout << "\t\t\t*                                 *\n"; 
      cout << "\t\t\t***********************************\n"; 
      cout << "\n";    
   }   

   void Attack(Monster * Opponent)
   {
      int damage;      
      
      damage = Randy(10) + atak;
      
      if(dagger && UseDagger) 
      { cout << "\n\t" << CharName << " stabs with the dagger!\n"; damage = damage + 2; }
      else if(sword && UseSword) 
      { cout << "\n\t" << CharName << " swings the sword!\n"; damage = damage + 4; }
      else if(longbow && UseLongBow) 
      { cout << "\n\t" << CharName << " releasees the string of the longbow!"; damage = damage + 2; }
      else { cout << "\n\t" << CharName << " engages the oponent in brutal hand to hand combat!\n"; }
           
      cout << "\n\n\t***************** " << CharName << " Attacks! *****************\n"
           << "\tBefore Attack:    " << CharName << " Hit = " << hitpoints  << "   "  
           << "    Opponent Hit = " << Opponent->getHit() 
           << "\n";             
      
      if(damage - Opponent->getDefense() > 0)
      { damage = damage - Opponent->getDefense(); }
      else { damage = 0; }

      //Prevent negative values. Check that oponent is still alive.      
      if((Opponent->getHit() - damage) > 0) 
        { Opponent->setHit((Opponent->getHit() - damage)); }
      else 
        { Opponent->setHit(0); }  
 
      cout << "\tAfter Attack:     " << CharName << " Hit = " << hitpoints  << "   "  
           << "    Opponent Hit = " << Opponent->getHit() 
           << "\n";   
      
      Sleep(3000);                      
   }

   void AskName()
   {
      string n;
      
      cout << "\n\n\n\n\n\n\tWhat will be your true name, player?\t";
      getline(cin, CharName);
   
      cout << "\n\tFrom henceforth, you shall be called: " 
           << CharName << " !!!\n\n\n\n\n\n\t"; 
           
      system("PAUSE");   
   }
   
   void Cheat()
   {
        setDagger(true); setSword(true);
        setLongBow(true); setChainMail(true);
        setFullBodyArmor(true); setHealingPotion(7);
        setFishKey(true);          
   }

   void UseHealingPotion()
   {
         if(healingpotion > 0)
         { hitpoints = hitpoints + 20; DisplayStats(); healingpotion--; }
         else { cout << "\n\tWishful thinking. You don't have any healing potions.\n"; }     
   }       

   //Inventory Accessor Methods
   bool getDagger() { return dagger; }
   bool getSword() { return sword; }
   bool getLongBow() { return longbow; }
   bool getChainMail() { return chainmail; }
   bool getFullBodyArmor() { return fullbodyarmor; }
   int getHealingPotion() { return healingpotion; }
   bool getFishKey() { return FishKey; }
   void setDagger(bool x) { dagger = x; }
   void setSword(bool x) { sword = x; }
   void setLongBow(bool x) { longbow = x; }
   void setChainMail(bool x) { chainmail = x; }
   void setFullBodyArmor(bool x) { fullbodyarmor = x; }
   void setHealingPotion(int x) { healingpotion = healingpotion + x; }
   void setFishKey(bool x) { FishKey = x; } 
   void setUseDagger(bool x) { UseDagger = x; }
   void setUseSword(bool x) { UseSword = x; }
   void setUseLongBow(bool x) { UseLongBow = x; }   


   //Character Attribute Accessor Methods
   void setHit(int hp) { hitpoints = hp; }
   void setAttack(int atk)  { atak = atk; }
   void setDefense(int def) { defense = def; }
   void setLevel(int lvl) { level = lvl; }
   void setLocation(int loki) { location = loki; }   
   void setName(string nm) { CharName = nm; }
   void setScore(int sc)  { score = sc; }    
   int getHit() { return hitpoints; }
   int getAttack()  { return atak; }
   int getDefense() { return defense; }
   int getLevel() { return level; }
   int getLocation() { return location; }
   int getScore() { return score; }       
   string getName() { return CharName; } 
   
   private: 
   //Character Attribute Items
   int hitpoints;
   int atak;
   int defense;
   int level;
   int location;
   string CharName; 
   int score;
   
   //Character Inventory Items
   bool dagger;
   bool sword;
   bool longbow;
   bool UseDagger;
   bool UseSword;
   bool UseLongBow;
   bool chainmail;
   bool fullbodyarmor;              
   int healingpotion;
   bool FishKey;          
          
};

//---------------------------------------------------------------------------------------------------------------------------

//Derives from Character

class Player : public Character
{
   public:
   Player() { cout << "\tCreating a Player.\n"; }
   ~Player(){ cout << "\tDestroying a Player.\n";  }

   //Accessor Methods
   private:   

};

//---------------------------------------------------------------------------------------------------------------------------

//Derives from Monster

class Dragon : public Monster
{ 
   public:
   Dragon() { cout << "\n\tCreating a DERIVED class Dragon."; }
   ~Dragon() { cout << "\n\tDestroying a DERIVED class Dragon."; }

  void Attack(Character * Opponent)
  {  
      //Since we are calling members of the base class, we use the "this" pointer.   
      int damage;           
      cout << "\n\n\t***************** Dragon Attacks! *****************\n"
           << "\tBefore Attack:    Dragon Hit = " << this->getHit() << "      " 
           << Opponent->getName() <<  " Hit = "  << Opponent->getHit()
           << "\n";             

      damage = Randy(10) + this->getAttack();
      if(damage > Opponent->getDefense())
         { damage = damage - Opponent->getDefense(); }
      else { damage = 0; }   
      if(Opponent->getFullBodyArmor()) 
      { if(damage > 4) { damage = damage - 4; } }
      if(Opponent->getChainMail()) 
      { if(damage > 2) { damage = damage - 2; }  }
      
      //Prevent negative values. Check that oponent is still alive.      
      if((Opponent->getHit() - damage) > 0) 
        { Opponent->setHit((Opponent->getHit() - damage)); }
      else 
        { Opponent->setHit(0); }  
 
      cout << "\tAfter Attack:     Dragon Hit = " << this->getHit() << "      "   
           << Opponent->getName() << " Hit = " << Opponent->getHit() 
           << "\n\n";   
         
      Sleep(3000);                  
  } 
          
   void BreatheFire()
   { cout << "Breathing fire."; }
   
   //Accesor Methods
   void setCanFly(bool fly) { CanFly = fly; }
   bool getCanFly() { return CanFly; } 
          
   private:          
   bool CanFly;                  
          
};

//---------------------------------------------------------------------------------------------------------------------------

//Derives from Monster

class Giant : public Monster
{
  public:    
  Giant() { cout << "\n\tCreating a DERIVED class Giant."; }  
  ~Giant() { cout << "\n\tDestroying a DERIVED class Giant."; }
  
  void Stomp() { cout << "Stomping on object."; }   
  void SwingClub() { cout << "Swing club."; }
  
  void Attack(Character * Opponent)
  {  
      //Since we are calling members of the base class, we use the "this" pointer.   
      int damage;           
      cout << "\n\n\t***************** Giant Attacks! *****************\n"
           << "\tBefore Attack:    Giant Hit = " << this->getHit() << "      " 
           << Opponent->getName() <<  " Hit = "  << Opponent->getHit()
           << "\n";             

      damage = Randy(10) + this->getAttack();
      if(damage > Opponent->getDefense())
         { damage = damage - Opponent->getDefense(); }
      else { damage = 0; }   
      if(Opponent->getFullBodyArmor()) 
      { if(damage > 4) { damage = damage - 4; } }
      if(Opponent->getChainMail()) 
      { if(damage > 2) { damage = damage - 2; }  }
      
      //Prevent negative values. Check that oponent is still alive.      
      if((Opponent->getHit() - damage) > 0) 
        { Opponent->setHit((Opponent->getHit() - damage)); }
      else 
        { Opponent->setHit(0); }  
 
      cout << "\tAfter Attack:     Giant Hit = " << this->getHit() << "      "   
           << Opponent->getName() << " Hit = " << Opponent->getHit() 
           << "\n\n";   
         
      Sleep(3000);                  
  } 

  //Accesor Methods
  void setClub(bool club) { HasClub = club; }
  bool getClub() { return HasClub; }
  
  private:
  bool HasClub;        
      
};     

//---------------------------------------------------------------------------------------------------------------------------

class Shaman : public Character
{
      public:
      Shaman() { cout << "\tCreating a Shaman.\n"; }
      ~Shaman() { cout << "\tDestroying a Shaman.\n";  }
      
	  void Talk() 
      {
           int SayWhat;
           SayWhat = Randy(10);              

           cout << "\n\tThe Shaman looks at you from beneath her priestly\n"
                << "\tgarments and says,\n\n\t\""; 

           switch(SayWhat) 
           {
               case 1 : cout << "I like wild flowers. They are very beautiful, and\n"
                             << "\ttheir restorative powers are merely a fringe benefit";
		                break;
               case 2 : cout << "Do not look at the outward appearance of things,\n"
                             << "\tcharacter should be judged by what is on the inside.";
		                break;
	           case 3 : cout << "Good karma, bad karma, it's all the same.."; break;
	           case 4 : cout << "I have a secret to tell..."; break;
	           case 5 : cout << "To unlock the gate between worlds one needs a key"; break;
	           case 6 : cout << "You are not from this world, I see that now"; break;
	           case 7 : cout << "You did not yet know it traveler, but you must "
                             << "seek\nthe key of the fish god!"; break;
               case 8 : cout << "Sometimes I wish I'd never taken that vow of chastity"; break;
               case 9 : cout << "Do you think I'm pretty? Don't judge a book by its cover!"; break;
               case 10 : cout << "Beware the edge of the forest. Giants are afoot"; break;              
	           default : cout << "Uh oh, this should never happen.."; break;
            } //closes switch
	        
            cout << "\".\n\n";
	
    } //close talk function
      
      private:
      bool staff;
      bool medicinebag;
};

//---------------------------------------------------------------------------------------------------------------------------








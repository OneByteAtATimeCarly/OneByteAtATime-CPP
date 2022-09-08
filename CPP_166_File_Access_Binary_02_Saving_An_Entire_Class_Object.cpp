//Binary File Access  2 - Saving An Entire Class Object - 2004 C. S. Germany

//Saving An Entire Class Object

//Below, the Player class is listed, which I wrote for one of my game projects to handle character objects and NPCs. 
//Look at the functions SaveCharacter() and LoadCharacter().  An instance of the Player class has many, many data
//members associated with it.  Saving this information in a sequetial file would be tedious. Yet by saving a Player
//object to a binary file, all of the data members that correspoond to a Player object can be saved at once.

//Take a look at the process:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Player
{
public:

        // Constructor
	Player() { 
	           name = "NewPlayerNow";
	           InitializeItems();
                   cout << "Player object created.\n";  }
        
        // Destructor 
	~Player() { cout << "\nPlayer character destroyed.\n"; }

	//Accessor Methods
        void setLevel(int lev) { level = lev; }
	int getLevel() { return level; }

	void setStrength(int str) { strength = str; }
	int getStrength() { return strength; }

	void setIntelligence(int intel) { intelligence = intel; }
	int getIntelligence() { return intelligence; }

	void setCharisma(int chrs) { charisma = chrs; }
	int getCharisma() { return charisma; }

	void setDexterity(int dex) { dexterity = dex; }
	int getDexterity() { return dexterity; }

	void setName(char na[15]) { 
		     name = new char[15];
		     strcpy(name, na);
	             cout << "\nCharacter name set to " << name << "."; }
	char * getName() { return name; }


        //Inventory Item Accessors
	void setSword(bool swd) { sword = swd; }
	bool getSword() { return sword; } 

	void setBow(bool lng) { longbow = lng; }
	bool getBow() { return longbow; }

	void setStaff(bool stf) { staff = stf; }
	bool getStaff() { return staff; }

	void setShield(bool shl) { shield = shl; } 
	bool getShield() { return shield; }

	void setArmor(bool arm) { armor = arm; }
	bool getArmor() { return armor; }

        void DisplayInventory() {
             cout << "You have the following items:\n";
             if(sword) { cout << " sword, "; }
             if(longbow) { cout << " longbow, "; }
             if(staff) { cout << " staff, "; }
             if(shield) { cout << " shield, "; }
             if(armor) { cout << " armor, "; }
             if(!sword && !longbow && !staff && !shield && !armor) { 
                cout << "\nIt appears that you have NOTHING!"
                cout << "\nAbsolutely nothing!\nHow sad..."; 
             }

        } //close DisplayInventory function
        //Game Cheat - gives all items
        void AllItems() {        
             sword = true;
             longbow = true;
             staff = true;
             shield = true;
             armor = true;
        }
        //Initialize Items
        void InitializeItems() {
             level = 1;
             strength = 10;
             intelligence = 18;
             charisma = 17;
             dexterity = 16;
             sword = false;
             longbow = false;
             staff = false;
             shield = false;
             armor = false;
        }

        //Save Character
        void SaveCharacter() {
	     char CharacterName[80];
	     cout << "Please enter a name for your character to save: ";
	     cin >> CharacterName;

             ofstream fout(CharacterName,ios::trunc||ios::binary);

	          if(!fout) { 
		     cout << "Unable to create " << CharacterName 
		          << " for writing.\n";
	          }  //close if

	     fout.write((char*) &*this,sizeof(*this));

	     fout.close();
        } //close save character function


        //Load Character
        void LoadCharacter() {
	     char CharacterName[80];
	     cout << "Please enter the name of your character to load: ";
	     cin >> CharacterName;
	     ifstream fin(CharacterName,ios::trunc||ios::binary);

	     if (!fin) {
		 cout << "Unable to find " << CharacterName << " for reading.\n";
	     }
	     fin.read((char*) &*this, sizeof(this));

	     fin.close();
	     cout << "Loaded player name is: " << name << ".\n";
	     cout << "Loaded player strength is: " << strength << ".\n";
             cout << "Loaded player level is: " << level << ".\n";
	     cout << "Loaded player intelligence is: " << intelligence << ".\n";
             cout << "Loaded player charisma is: " << charisma << ".\n";
	     cout << "Loaded player dexterity is: " << dexterity << ".\n";
	     DisplayInventory();
        } //close load character function

        // DisplayCharacter
        void DisplayCharacter() {
	     cout << "Player name is: " << name << ".\n";
	     cout << "Player strength is: " << strength << ".\n";
             cout << "Player level is: " << level << ".\n";
	     cout << "Player intelligence is: " << intelligence << ".\n";
             cout << "Player charisma is: " << charisma << ".\n";
	     cout << "Player dexterity is: " << dexterity << ".\n";
	     DisplayInventory();
        }

        // Display Menu
        void DisplayMenu() {
             bool quit = false;
             char choice;
             cout << "\nChoose an option:\n";
             cout << "***********MENU***********\n";
             cout << "*                        *\n";
             cout << "* L = Load player        *\n";
             cout << "* S = Save player        *\n";
             cout << "* D = Display player     *\n";
             cout << "* C = Change attributes  *\n";
             cout << "* I = Inventory          *\n";
             cout << "* A = All Items Cheat    *\n";
             cout << "* Q = Quit               *\n";
             cout << "*                        *\n";
             cout << "**************************\n";
             while(!quit) {
                   DisplayMenu();
                   cin >> choice;
                   
                   switch(choice) {
                        case 'l' : LoadCharacter(); break;
                        case 'L' : LoadCharacter(); break;
	                case 'd' : DisplayCharacter(); break; 
	                case 'D' : DisplayCharacter(); break;
	                case 's' : SaveCharacter(); break;
	                case 'S' : SaveCharacter(); break;
	                case 'c' : SetPlayerAttributesCheat(this); break;
	                case 'C' : SetPlayerAttributesCheat(this); break;
                        case 'i' : DisplayInventory(); break;
	                case 'I' : DisplayInventory(); break;
	                case 'a' : AllItems(); break;
	                case 'A' : AllItems(); break;
	                case 'q' : quit = true; break;
	                case 'Q' : quit = true; break;
                        default : cout << "Please choose either c, l, s, or d."
                                       << " (LSD - get it?) haha";
                   } //close switch statement

             } // close while true
        } //close function

    // Data Members
    private:
    int level;
    int strength;
    int intelligence;
    int charisma;
    int dexterity;
    char * name;
    //Items
    bool sword;
    bool longbow;
    bool staff;
    bool shield;
    bool armor;

}; 

//---------------------------------------------------------------------------------------------------------------------------









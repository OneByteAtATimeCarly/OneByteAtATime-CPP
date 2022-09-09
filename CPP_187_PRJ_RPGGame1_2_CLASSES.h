//PRJ - RPGGame1 - Classes - 2006 - C. S. Germany
//Hills of Darkness (HOD) C. S. Germany, March 16, 2007
//File 2 of 4

//Classes

//---------------------------------------------------------------------------------------------------------------------------

//ADTs

//Supreme BASE class

//---------------------------------------------------------------------------------------------------------------------------

class ENTITY
{
      public:
             
      ENTITY() 
      { 
                cout << "\n\tCreating ENTITY object."; 
                InitializeStats();
      }
      
      ~ENTITY() { cout << "\n\tDestroying ENTITY Object."; }
      
      void InitializeStats()
      {
           HP = 50;
           ATK = 1;
           DEF = 1;
           EXP = 0;
           score = 0;
           NAME = "No_Name_Yet"; 
           WeaponChoice = nothing;
           MagicChoice = nomagic;
           ArmorChoice = NO_ARMOR;
           INV_count = 0;
           MagicEnergy = 20;           
      }
      
 //------------------------------------------------------------------------

      void DisplayStats() 
      { 
           char x[10];
           string STATS = 
"\n\n     -------------------------------STATS--------------------------------\n";
           STATS = STATS + "      PLAYER: " + NAME; 
           STATS = STATS + " SEX:" + gender; 
           itoa(HP,x,10);
           STATS = STATS + " HP:" + x;
           itoa(ATK,x,10);
           STATS = STATS + " ATK:" + x;
           itoa(DEF,x,10);
           
           STATS = STATS + " DEF:" + x;
           itoa(EXP,x,10);
           STATS = STATS + " EXP:" + x;
           itoa(score,x,10);
           STATS = STATS + " SCR:" + x;
           STATS = STATS + " CLS:";

           switch(ENTITY_CLASS)
           {
               case DRAGON : STATS = STATS + "Dragon"; break;
               case GIANT : STATS = STATS + "Giant"; break;
               case SHAMAN : STATS = STATS + "Shaman"; break;
               case WARRIOR : STATS = STATS + "Warrior"; break;
               case MAGE : STATS = STATS + "Mage"; break;
               case FIGHTER : STATS = STATS + "Fighter"; break;
               case ELF : STATS = STATS + "Elf"; break;
               default : cout << "\n     Error. Bad input!";                         
           }
           
           STATS = STATS + "\n      WEAPON:";
           
           switch(WeaponChoice)
           {
                case nothing : STATS = STATS + "Nothing but ";
                               if(gender == "Male") 
                               { STATS = STATS + "his"; }
                               else
                               { STATS = STATS + "her"; }
                               STATS = STATS + " fists!"; 
                               break;
                case broadsword : STATS = STATS + "BroadSword"; break;
                case dagger : STATS = STATS + "Dagger"; break;
                case staff : STATS = STATS + "Staff"; break;
                case crossbow : STATS = STATS + "CrossBow"; break;
                case longbow : STATS = STATS + "LongBow"; break;
                default : cout << "\n     Bad Input!"; break;                    
           }   

           STATS = STATS + " ARMOR:";
           
           switch(ArmorChoice)
           {
                case NO_ARMOR : STATS = STATS + " Nothing"; break;
                case CHAIN_MAIL : STATS = STATS + "Chain"; break;
                case PLATE_MAIL : STATS = STATS + "Plate"; break;
                default : cout << "\n     Bad Input!"; break;                    
           }   
           
           STATS = STATS + " MAGIC:";
           
           switch(MagicChoice)
           {
                    case nomagic : STATS = STATS + 
                                   "None";
                                   break;
                    case fire : STATS = STATS + 
                                "Fire";
                                break;
                    case ice : STATS = STATS + 
                               "Ice";
                               break;
                    case lightning : STATS = STATS + 
                                     "Lightning";
                                     break;
                    case telekinetic_force : STATS = STATS + 
                                             "Telekinesis";
                                             break;
                    case invisibility :  STATS = STATS + 
                                         "Invisibility";
                                         break;
                    case healing : STATS = STATS + 
                                   "Healing";
                                   break;               
                    default : STATS = STATS + "\n     Invalid input.\n"; break;      
           }   
           itoa(MagicEnergy,x,10);
           STATS = STATS + "  ME:" + x;
                   
           STATS = STATS + 
           "\n     --------------------------------------------------------------------\n";
           
           cout << STATS;     
      }

//------------------------------------------------------------------------

      void Attack(ENTITY * opponent)
      {
           char x[10];
           string OUTPUT = "";
           DisplayStats();  
           OUTPUT = OUTPUT + 
                    "\n\n\t-------------------- Attack for " + NAME + " --------------------"
                    + "\n\t" + opponent->GetNAME() + "'s hitpoints BEFORE " 
                    + NAME + "'s attack: ";

           itoa(opponent->GetHP(),x,10);
           OUTPUT = OUTPUT +  x + "\t\n";
          
           int damage = ((rand()%MaxDamage) + 1);
           
           //Note: Need to write separate behavior and if clause for each
           //character class, for now just using same for all 4.
           if(ENTITY_CLASS == WARRIOR ||
              ENTITY_CLASS == MAGE ||
              ENTITY_CLASS == FIGHTER ||
              ENTITY_CLASS == ELF ||
              ENTITY_CLASS == SHAMAN)
           {
              OUTPUT = OUTPUT + "\n\tWeapon Attack: " + NAME;
           
              switch(WeaponChoice)
              {
                  case nothing : OUTPUT = OUTPUT + " fights with bare fists of fury!\n\t"; 
                                 break;
                  case dagger : damage = damage + DaggerDamage;
                                OUTPUT = OUTPUT + " stabs with the dagger!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(DaggerDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10); 
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;
                  case staff : damage = damage + StaffDamage;
                                OUTPUT = OUTPUT + " twirls the bo staff. Crack!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(StaffDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10); 
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;                                 
                 case longbow : damage = damage + LongBowDamage;
                                OUTPUT = OUTPUT + " fires an arrow from the long bow!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(LongBowDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10);
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;                                
                  case crossbow : damage = damage + CrossBowDamage;
                                  OUTPUT = OUTPUT + " fires a bolt from the crossbow!\n\t" 
                                  + "This weapon increases ";
                                  if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                  else { OUTPUT = OUTPUT + "her"; }
                                  OUTPUT = OUTPUT + " attack by ";
                                  itoa(CrossBowDamage,x,10); 
                                  OUTPUT = OUTPUT + x + 
                                  " for a total of\n\t";
                                  itoa(damage,x,10);
                                  OUTPUT = OUTPUT + x + " damage.\n";
                                  break;            
                  case broadsword : damage = damage + BroadSwordDamage;
                                    OUTPUT = OUTPUT + " swings the mighty broadsword!\n\t" 
                                    + "This weapon increases ";
                                    if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                    else { OUTPUT = OUTPUT + "her"; }
                                    OUTPUT = OUTPUT + " attack by ";
                                    itoa(BroadSwordDamage,x,10); 
                                    OUTPUT = OUTPUT + x + 
                                    " for a total of\n\t";
                                    itoa(damage,x,10); 
                                    OUTPUT = OUTPUT + x + " damage.\n";
                                    break;
                  default : cout << "Invalid Input!"; break;                    
              } 
           }  
           
           if(ENTITY_CLASS == MAGE ||
              ENTITY_CLASS == SHAMAN ||
              ENTITY_CLASS == ELF) 
           {
                switch(MagicChoice)
                {
                    case nomagic : OUTPUT = OUTPUT + 
                                   "\n\tNo magic is being used now.\n";
                                   break;
                    case fire : damage = damage + Magic_FireDamage;
                                OUTPUT = OUTPUT + 
                                "\n\tMagic Attack: " + NAME + 
                                " blasts a fire ball at ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + 
                                " opponent \n\t"
                                "burning ";
                                itoa(Magic_FireDamage,x,10); 
                                OUTPUT = OUTPUT + x +
                                " points of damage into them!\n";
                                MagicChoice = nomagic;
                                break;
                    case ice : damage = damage + Magic_IceDamage;
                               OUTPUT = OUTPUT + 
                               "\n\tMagic Attack: " + NAME + 
                               " lowers the ambient temperature of ";
                               if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                               else { OUTPUT = OUTPUT + "her"; }
                               OUTPUT = OUTPUT + 
                               " opponent \n\t"
                               "freezing them with ";
                               itoa(Magic_IceDamage,x,10); 
                               OUTPUT = OUTPUT + x +
                               " points of damage!\n";
                               MagicChoice = nomagic;
                               break;
                    case lightning : damage = damage + Magic_LightningDamage;
                                     OUTPUT = OUTPUT + 
                                     "\n\tMagic Attack: " + NAME + 
                                     " blasts the opponent with  ";
                                     if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                     else { OUTPUT = OUTPUT + "her"; }
                                     OUTPUT = OUTPUT + 
                                     " lightning bolt! \n\t"
                                     "This electrifies them, doing ";
                                     itoa(Magic_LightningDamage,x,10); 
                                     OUTPUT = OUTPUT + x +
                                     " points of damage!\n";
                                     MagicChoice = nomagic;
                                     break;
                    case telekinetic_force : damage = damage + Magic_TelekineticDamage;
                                             OUTPUT = OUTPUT + 
                                             "\n\tMagic Attack: " + NAME + 
                                             " telekinetically throws and object at\n\t";
                                             if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                             else { OUTPUT = OUTPUT + "her"; }
                                             OUTPUT = OUTPUT + 
                                             " opponent, doing a massive ";
                                             itoa(Magic_TelekineticDamage,x,10); 
                                             OUTPUT = OUTPUT + x +
                                             " points of damage!\n";
                                             MagicChoice = nomagic;
                                             break;
                    case invisibility :  //After 5 rounds, invisibility wears off and restores DEF
                                         if(INV_count == 0)
                                         {
                                                DEF = DEF + Magic_InvisibilityDefense;
                                                INV_count = 5;
                                         }  
                                         
                                         if(INV_count > 1)
                                         {
                                               INV_count--; 
                                               OUTPUT = OUTPUT + 
                                               "\n\tMagic Defense: " + NAME 
                                               + " employs invisibility, bending\n\t"
                                               + "the light around ";
                                               if(gender == "Male") { OUTPUT = OUTPUT + "him"; }
                                               else { OUTPUT = OUTPUT + "her"; }
                                               OUTPUT = OUTPUT + "self and increasing ";
                                               if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                               else { OUTPUT = OUTPUT + "her"; }
                                               OUTPUT = OUTPUT + 
                                               " defensive\n\tcapability by 1 for 5 rounds.\n\t";
                                               itoa(INV_count,x,10); 
                                               OUTPUT = OUTPUT + "\n\tThere are " + x + " round(s) of "
                                               + "invisibility left.\n";
                                               cout << "\n\n\tCOUNT = " << INV_count << "\n\n";
                                          }
                                          else
                                          { 
                                              INV_count = 0;
                                              DEF = DEF - Magic_InvisibilityDefense;
                                              MagicChoice = nomagic;
                                          }
                                        break;
                    case healing : break;               
                    default : OUTPUT = OUTPUT + "\n\tInvalid input.\n"; break;
                }                                       
           }                              

           if(damage > opponent->GetDEF())
           { damage = damage - opponent->GetDEF(); }
           else { damage = 0; }

           if(opponent->GetHP() - damage > 0)
           { opponent->SetHP(opponent->GetHP() - damage); }
           else { opponent->SetHP(0); }

           OUTPUT = OUTPUT + "\n\t" + opponent->GetNAME() + "'s hitpoints AFTER " 
                    + NAME + "'s attack: ";
           
           itoa(opponent->GetHP(),x,10);
           OUTPUT = OUTPUT +  x + "\t";
           
           OUTPUT = OUTPUT + "\n\t----------------------------------------------------------\n\n";
              
           cout << OUTPUT;
      }

 //------------------------------------------------------------------------
           
      //Accessor Methods
      void SetHP(int x) { HP = x; }
      void SetATK(int x) { ATK = x; }
      void SetDEF(int x) { DEF = x; }
      void SetEXP(int x) { EXP = x; }
      void SetScore(int x) { score = x; }
      void SetWeaponChoice(int x) { WeaponChoice = x; }      
      void SetMagicChoice(int x) { MagicChoice = x; }
      void SetArmorChoice(int x) { ArmorChoice = x; }
      void SetENTITY_CLASS(int x) { ENTITY_CLASS = x; }       
      void SetNAME(string x) { NAME = x; }
      void SetGender(string x) { gender = x; }
      void SetMagicEnergy(int x) { MagicEnergy = x; }    
      
      int GetHP() { return HP; }
      int GetATK() { return ATK; }
      int GetDEF() { return DEF; }
      int GetEXP() { return EXP; }
      int GetScore() { return score; } 
      int GetWeaponChoice() { return WeaponChoice; }
      int GetMagicChoice() { return MagicChoice; }
      int GetArmorChoice() { return ArmorChoice; }      
      int GetENTITY_CLASS() { return ENTITY_CLASS; }
      string GetNAME() { return NAME; }
      string GetGender() { return gender; }
      int GetMagicEnergy() { return MagicEnergy; }

      
      private:
      int HP;
      int ATK;
      int DEF;
      int EXP;
      int score;
      int WeaponChoice;
      int MagicChoice;
      int ArmorChoice;
      int ENTITY_CLASS;
      string NAME;
      string gender;
      int INV_count; 
      int MagicEnergy;          
};

//---------------------------------------------------------------------------------------------------------------------------

//Other ADTs

//---------------------------------------------------------------------------------------------------------------------------

class Monster : public ENTITY
{
      public:
      Monster() { cout << "\n\tCreating Monster object."; }
      ~Monster() { cout << "\n\tDestroying Monster Object."; }
      
      private:
      
};

//---------------------------------------------------------------------------------------------------------------------------

class Character : public ENTITY
{
      public:
      
      string INV;
      
      Character() 
      { 
          cout << "\n\tCreating Character object.";
          InitializeInventory();
      }
      
      ~Character() { cout << "\n\tDestroying Character Object."; }

//------------------------------------------------------------------------

      void InitializeInventory()
      {
           //Inventory Items
           BroadSword = false;
           Dagger = false;
           Staff = false;
           CrossBow = false;
           LongBow = false;
           Arrows = 0;
           ChainMail = false;
           PlateArmor = false;
           HealingPotion = 0;
           FishKey = false;
           
           //Magic Abilities
           Fire = false;
           Ice = false;
           Lightning = false;
           Telekinetic_Force = false;
           Invisibility = false;
           Healing = false;    
      }

//------------------------------------------------------------------------

     void cheat()
     {
           cout << "\n\tCheater! Hidden cheat function was activated.\n";
           BroadSword = true;
           Dagger = true;
           Staff = true;
           CrossBow = true;
           LongBow = true;
           Arrows = 100;
           ChainMail = true;
           PlateArmor = true;
           HealingPotion = 100;
           FishKey = true; 
           SetHP(1000);
           SetWeaponChoice(broadsword); 
           
           SetMagicEnergy(10000);
           Fire = true;
           Ice = true;
           Lightning = true;
           Telekinetic_Force = true;
           Invisibility = true; 
           Healing = true;
           
           DisplayInventory();                   
     }

//------------------------------------------------------------------------

      void DisplayInventory()
      {
           char x[10] = "";
           int count = 0;
           INV = "\n\t----------------------Inventory---------------------";

           if(BroadSword) 
           {    
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (B)roadsword";
           }
            
           if(Dagger) 
           { 
              ++count;
              itoa(count,x,10);                     
              INV = INV + "\n\t";
              INV = INV + x + ". (D)agger"; 
           }

           if(Staff) 
           { 
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (S)taff"; 
           
           }
 
           if(CrossBow) 
           { 
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (C)rossBow"; 
           
           }
 
            if(LongBow) 
           { 
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (L)ongBow"; 
           
           }
 
           if(Arrows > 0) 
           {   
               ++count;
               itoa(count,x,10);               
               INV = INV + "\n\t";
               INV = INV + x + ". (A)rrows: ";
               itoa(Arrows,x,10);
               INV = INV + x; 
           }
           
           if(ChainMail) 
           { 
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (M)ail Armor"; 
           }
           
           if(PlateArmor) 
           { 
                ++count;
                itoa(count,x,10);
                INV = INV + "\n\t";
                INV = INV + x + ". (P)late Armor"; 
           }           
           
           if(HealingPotion > 0)           
           {   
               ++count;
               itoa(count,x,10);
               INV = INV + "\n\t"; 
               INV = INV + x + ". (H)ealing Potion: "; 
               itoa(HealingPotion,x,10);
               INV = INV + x; 
           }
           
           if(FishKey) 
           { 
              ++count;
              itoa(count,x,10);              
              INV = INV + "\n\t";
              INV = INV + x + ". (F)ishKey"; 
           }
           
           if(!BroadSword && ! Dagger && !CrossBow && Arrows == 0 && 
              !ChainMail && HealingPotion == 0 && !FishKey) 
           {    
                INV = INV + "\n\t";
                INV = INV + "Nothing.";
           }
           
           INV = INV + "\n\t----------------------------------------------------";
           cout << INV;     
      }

//------------------------------------------------------------------------

       void UseItem()
      {
           string choice = "";
           DisplayInventory();
           cout << "\n\tWhich item do you wish to use?  (q = quit) ";
           cin >> choice;
           choice[0] = tolower(choice[0]); 
           
           switch(choice[0])
           {
               case 'h' : if(HealingPotion > 0)
                          { 
                             cout << "\n\tYou drink the healing elixir and feel much better!\n";
                             SetHP(GetHP() + HP_Restore_Amt);
                             SetHealingPotion(GetHealingPotion() - 1); 
                             DisplayStats();  
                          }
                          else
                          {
                             cout << "\n\tSorry, you have no healing potions.";    
                          }
                          break;
               case 'b' : if(BroadSword)
                          { 
                             cout << "\n\tShwing! You unsheath your mighty broad sword!";
                             SetWeaponChoice(broadsword); 
                             DisplayStats();  
                          }
                          else
                          {  cout << "\n\tSorry, you have no broadsword.";  }
                          break;
               case 'd' : if(Dagger)
                          { 
                             cout << "\n\tFfwpt! You take our your dagger!";
                             SetWeaponChoice(dagger); 
                             DisplayStats();  
                          }
                          else
                          {  cout << "\n\tSorry, you have no dagger.";  }
                          break; 
               case 's' : if(Staff)
                          { 
                             cout << "\n\tYou twirl your bo staff - it whips the air!";
                             SetWeaponChoice(staff); 
                             DisplayStats();  
                          }
                          else
                          {  cout << "\n\tSorry, you do not have a bo staff!";  }
                          break;
               case 'c' : if(CrossBow)
                          { 
                             cout << "\n\tYou pull out the crossbow";
                             if(Arrows > 0) 
                             { cout << " and load it with an arrow!"; }
                             else { cout << ". If only you had arrows..."; }
                             SetWeaponChoice(crossbow); 
                             DisplayStats();  
                          }
                          else
                          {  cout << "\n\tSorry, you have no crossbow.";  }
                          break;
               case 'l' : if(LongBow)
                          { 
                             cout << "\n\tYou pull your trusty long bow ";
                             if(Arrows > 0) 
                             { cout << " and load it with an arrow!"; }
                             else { cout << ". If only you had arrows..."; }
                             SetWeaponChoice(longbow); 
                             DisplayStats();  
                          }
                          else
                          {  cout << "\n\tSorry, you have no long bow.";  }
                          break;                                                    
                case 'm' : if(ChainMail)
                           { 
                              if(GetArmorChoice() != CHAIN_MAIL)
                              {
                                 if(GetArmorChoice() != PLATE_MAIL)
                                 {
                                     cout << "\n\tYou put on the chain mail!";
                                     SetArmorChoice(CHAIN_MAIL);
                                     SetDEF(GetDEF() + 1); 
                                 }
                                 else
                                 {
                                     cout << "\n\tYou take off the plate mail "
                                          << "you're currently wearing.";
                                     SetDEF(GetDEF() - 3);
                                     cout << "\n\tYou put on the chain mail!"; 
                                     SetDEF(GetDEF() + 1);
                                     SetArmorChoice(CHAIN_MAIL);
                                 } 
                              }
                              else
                              {  
                                 cout << "\n\tYou take off the chain mail.";
                                 SetArmorChoice(NO_ARMOR);
                                 SetDEF(GetDEF() - 1);     
                              }
                              
                              DisplayStats();
                          }
                          else
                          {  cout << "\n\tSorry, you do not have the chainmail.";  }
                          break; 
                case 'p' : if(PlateArmor)
                           { 
                              if(GetArmorChoice() != PLATE_MAIL)
                              {
                                 if(GetArmorChoice() != CHAIN_MAIL)
                                 {
                                     cout << "\n\tYou put on the plate mail!";
                                     SetArmorChoice(PLATE_MAIL);
                                     SetDEF(GetDEF() + 3); 
                                 }
                                 else
                                 {
                                     cout << "\n\tYou take off the chain mail "
                                          << "you're currently wearing.";
                                     SetDEF(GetDEF() - 1);
                                     cout << "\n\tYou put on the plate mail!";
                                     SetDEF(GetDEF() + 3);
                                     SetArmorChoice(PLATE_MAIL);
                                 }                 
                                                             
                              }
                              else
                              {  
                                 cout << "\n\tYou take off the plate mail.";
                                 SetDEF(GetDEF() - 3);
                                 SetArmorChoice(NO_ARMOR);    
                              }
                              
                              DisplayStats();
                           }
                           else
                           {  cout << "\n\tSorry, you do not have the plate armor.";  }
                           break; 
               case 'q' : break;  
               default : cout << "\n\tInvalid input!"; break;         
           }    
      }

 //------------------------------------------------------------------------
 
 void DisplayMagic()
 {
                int count = 0;
                char x[10] = "";
                
                INV = INV + "\n\n\t------------------Magic-Abilities-------------------\n";
                if(Fire) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (F)ire";
                }
                if(Ice) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (I)ce";
                } 
                if(Lightning) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (L)ightning";
                }
                if(Telekinetic_Force) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (T)elekinetic Force";
                } 
                if(Invisibility) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (V)isibility";
                }
                if(Healing) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (H)ealing";
                }

                if(!Fire && !Ice && !Lightning && !Telekinetic_Force && 
                   !Invisibility && !Healing) 
                {    
                    INV = INV + "\n\t";
                    INV = INV + "You have no magical abilities yet.";
                }
                                
                INV = INV + "\n\n\tMagic Energy: ";
                itoa(GetMagicEnergy(),x,10);
                INV = INV + x;    
                
                INV = INV + "   Currently Using: ";
                
                switch(GetMagicChoice())
                {
                       case fire : INV = INV + "Fire"; break;
                       case ice : INV = INV + "Ice"; break;
                       case lightning : INV = INV + "Lightning"; break;
                       case telekinetic_force : INV = INV + "Telekinetic Force"; break;
                       case invisibility : INV = INV + "Invisibility"; break;
                       case healing : INV = INV + "Healing"; break;
                       case nomagic : INV = INV + "No magic at all."; break;  
                }
                
                INV = INV + "\n\n"; 
}
 //------------------------------------------------------------------------
    
void UseMagic()
{
           string choice = "";
           INV = "";
           DisplayMagic();
           cout << INV;
           cout << "\n\tWhich magic ability do you wish to use? (q = quit) ";
           cin >> choice;
           choice[0] = tolower(choice[0]); 
           
           switch(choice[0])
           {
               case 'f' : if(The_Player->GetFire())
                          {
                              if(The_Player->GetMagicEnergy() > 10)
                              { 
                                 cout << "\n\tYou charge a plasma ball with "
                                      << "magic energy!\n";
                                 The_Player->SetMagicEnergy
                                 (The_Player->GetMagicEnergy() - Magic_Fire_Cost);
                                 The_Player->SetMagicChoice(fire);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " pyrotechnical capabilities, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use them.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet acquired the Fire ability!\n"; }    
                          break;
               case 'i' : if(The_Player->GetIce())
                          {
                              if(The_Player->GetMagicEnergy() > 10)
                              { 
                                 cout << "\n\tYou lower the ambient temperature "
                                      << "with magic energy!\n";
                                 The_Player->SetMagicEnergy
                                 (The_Player->GetMagicEnergy() - Magic_Ice_Cost);
                                 The_Player->SetMagicChoice(ice);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " Ice abilities, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use them.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet acquired the Ice ability!\n"; }    
                          break;
               case 'l' : if(The_Player->GetLightning())
                          {
                              if(The_Player->GetMagicEnergy() > 15)
                              { 
                                 cout << "\n\tThe air sparks as you build up an "
                                      << "enormous electrical charge\n\twith "
                                      << "a burst of magic energy!\n";
                                 The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() - 15);
                                 The_Player->SetMagicChoice(lightning);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " lightning, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use it.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet acquired the Lightning ability!\n"; }    
                          break;
               case 't' : if(The_Player->GetTelekineticForce())
                          {
                              if(The_Player->GetMagicEnergy() > 15)
                              { 
                                 cout << "\n\tVibrations fill the air around you "
                                      << "as you prepare to\n\temploy mind over matter.";
                                 The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() - 15);
                                 The_Player->SetMagicChoice(telekinetic_force);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " telekinetic capabilities, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use it.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet acquired Telekinetic capability.\n"; }
                          break;
               case 'v' : if(The_Player->GetInvisibility())
                          {
                              if(The_Player->GetMagicEnergy() > 15)
                              { 
                                 cout << "\n\tUsing 15 points of your magic energy,"
                                      << " you bend the light "
                                      << "\n\taround your body and reduce your"
                                      << " visibility to that of a\n\tfaint mirage!\n";
                                 The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() - 15);
                                 The_Player->SetMagicChoice(invisibility);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " Invisibility, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use it.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet learned the technique"
                                 << " of invisibility.\n"; 
                          }    
                          break;
               case 'h' : if(The_Player->GetHealing())
                          {
                              if(The_Player->GetMagicEnergy() > 10)
                              { 
                                 cout << "\n\tYou lay your hands upon"
                                      << " various injuries and summon "
                                      << "\n\tthe magic energy within you.";
                                 The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() - 10);
                                 The_Player->SetMagicChoice(healing);
                              }
                              else
                              {
                                 cout << "\n\tSorry, although you have acquired"
                                      << " Healing capabilities, you do not"
                                      << "\n\tyet possess enough magic energy to"
                                      << " use them.";    
                              }
                          }
                          else 
                          { cout << "\n\tYou have not yet learned Healing"
                                 << " through the laying on of hands.\n"; 
                          }    
                          break;
               case 'q' : break;
               default : cout << "\n\tInvalid input!"; break;         
           }          
}

//-------------------------------------------------------------------------      

      void ListPotions()
      {
                int count = 0;
                char x[10] = "";
                
                INV = "";
                INV = INV + "\n\n\t----------------------Potions-----------------------\n";
                if(HealingPotion > 0) 
                {    
                     ++count;
                     itoa(count,x,10);
                     INV = INV + "\n\t";
                     INV = INV + x + ". (H)ealing Elixir";
                }

                if(HealingPotion <= 0) 
                {    
                    INV = INV + "\n\t";
                    INV = INV + "You have no potions available at this moment.";
                }
                
                INV = INV + "\n\n";   
      }

//-------------------------------------------------------------------------      

      void UsePotions()
      {
           string choice = "";
           ListPotions();
           INV = INV + "\n\tWhich elixir or potion do you wish to use? (q = quit) ";
           cout << INV;
           
           cin >> choice;
           choice[0] = tolower(choice[0]); 
           
           switch(choice[0])
           {
               case 'h' : if(HealingPotion > 0)
                          {
                              cout << "\n\tAhhh! You drink the healing elixir "
                                   << "and it restores,\n\trenews and revives you."
                                   << " This adds " << HP_Restore_Amt << " hitpoints"
                                   << " back\n\tto your weak and waning life force.";
                                   
                              The_Player->SetHP(The_Player->GetHP() + HP_Restore_Amt);
                              The_Player->SetHealingPotion(The_Player->GetHealingPotion() - 1);
                          }    
                          else
                          {
                              cout << "\n\tSorry, you do not have any healing"
                                   << " potions or elixirs at this moment.";    
                          }    
                          break;
               case 'q' : break;
               default : cout << "\n\tInvalid input! Try again."; break;         
           }                     
      }
      
//-------------------------------------------------------------------------

      void ChooseWeapon()
      {
           int count = 0;
           char x[10] = "";
           string choice = "";
           
           string OUTPUT = "";
           
           OUTPUT = "\n\tYou are about to enter into combat. Weapons in your inventory are:\n";
            
           count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (F)ists of Fury (no weapon)";
           if(Dagger) 
           { count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (D)agger";}
           
           if(Staff) 
           { count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (S)taff";} 

           if(LongBow) 
           { count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (L)ongbow";}
           
           if(CrossBow) 
           { count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (C)rossbow";} 

           if(BroadSword) 
           { count++; itoa(count,x,10); OUTPUT = OUTPUT + "\n\t" + x + ". (B)roadsword";}
           
           OUTPUT = OUTPUT + "\n\n\tWhich weapon will you use?   ";
           cout << OUTPUT;
           
           cin >> choice;
           choice[0] = tolower(choice[0]); 
           
           switch(choice[0])
           {
               case 'f' : cout << "\n\tYou prepare to pummel your opponent with bare fists!";
                             SetWeaponChoice(nothing);   
                          break;                            
               case 'd' : if(Dagger)
                          { 
                             cout << "\n\tFfwpt! You take our your dagger!";
                             SetWeaponChoice(dagger);   
                          }
                          else
                          {  cout << "\n\tSorry, you have no dagger.";  }
                          break; 
               case 's' : if(Staff)
                          { 
                             cout << "\n\tYou twirl your bo staff - it whips the air!";
                             SetWeaponChoice(staff);   
                          }
                          else
                          {  cout << "\n\tSorry, you do not have a bo staff!";  }
                          break;
               case 'l' : if(LongBow)
                          { 
                             cout << "\n\tYou pull your trusty long bow.";
                             if(Arrows > 0) 
                             { cout << " and load it with an arrow!"; }
                             else { cout << ". If only you had arrows..."; }
                             SetWeaponChoice(longbow);  
                          }
                          else
                          {  cout << "\n\tSorry, you have no long bow.";  }
                          break;
               case 'c' : if(CrossBow)
                          { 
                             cout << "\n\tYou pull out the crossbow";
                             if(Arrows > 0) 
                             { cout << " and load it with an arrow!"; }
                             else { cout << ". If only you had arrows..."; }
                             SetWeaponChoice(crossbow);   
                          }
                          else
                          {  cout << "\n\tSorry, you have no crossbow.";  }
                          break;                          
               case 'b' : if(BroadSword)
                          { 
                             cout << "\n\tShwing! You unsheath your mighty broad sword!";
                             SetWeaponChoice(broadsword);   
                          }
                          else
                          {  cout << "\n\tSorry, you have no broadsword.";  }
                          break;             
               default : cout << "\n\tInvalid input! Using previously selected weapon."; 
                         break;         
           }
               
      }

//------------------------------------------------------------------------

      //Inventory Accessors
      void SetBroadSword(bool x) { BroadSword = x; }
      void SetDagger(bool x) { Dagger = x; }
      void SetStaff(bool x) { Staff = x; }      
      void SetCrossBow(bool x) { CrossBow = x; }
      void SetLongBow(bool x) { LongBow = x; }
      void SetArrows(int x) { Arrows = x; }
      void SetChainMail(bool x) { ChainMail = x; }
      void SetPlateArmor(bool x) { PlateArmor = x; }
      void SetHealingPotion(int x) { HealingPotion = x; }
      void SetFishKey(bool x) { FishKey = x; }      

      bool GetBroadSword() { return BroadSword; }
      bool GetDagger() { return Dagger; }
      bool GetStaff() { return Staff; }
      bool GetCrossBow() { return CrossBow; }
      bool GetLongBow() { return LongBow; }  
      int GetArrows() { return Arrows; }  
      bool GetChainMail() { return ChainMail; }  
      bool GetPlateArmor() { return PlateArmor; }
      int GetHealingPotion() { return HealingPotion; } 
      bool GetFishKey() { return FishKey; } 
      
      //Magic Accessors
      void SetFire(bool x) { Fire = x; }
      void SetIce(bool x) { Ice = x; }
      void SetLightning(bool x) { Lightning = x; }
      void SetTelekineticForce(bool x) { Telekinetic_Force = x; }
      void SetInvisibility(bool x) { Invisibility = x; }
      void SetHealing(bool x) { Healing = x; }
      
      bool GetFire() { return Fire; }
      bool GetIce() { return Ice; }
      bool GetLightning() { return Lightning; }
      bool GetTelekineticForce() { return Telekinetic_Force; }
      bool GetInvisibility() { return  Invisibility; }
      bool GetHealing() { return  Healing; } 

//------------------------------------------------------------------------

      private:   
      //Inventory Items
      bool BroadSword;
      bool Dagger;
      bool Staff;      
      bool CrossBow;
      bool LongBow;
      int Arrows;
      bool ChainMail;
      bool PlateArmor;
      int HealingPotion;
      bool FishKey;  
      
      //Magic
      bool Fire;
      bool Ice;
      bool Lightning;
      bool Telekinetic_Force;
      bool Invisibility;
      bool Healing;       
};

//---------------------------------------------------------------------------------------------------------------------------

//Derived Classes

//---------------------------------------------------------------------------------------------------------------------------

class Giant : public Monster
{
      public:
      
      Giant() 
      { 
           cout << "\n\tCreating Giant object.";
           SetENTITY_CLASS(GIANT);
           SetGender("Male"); 
      }
      ~Giant() { cout << "\n\tDestroying Giant Object."; }

      //Accessors
      void SetClub(bool x) { Club = x; }
      bool GetClub() { return Club; }

      private:
      bool Club;
};

//---------------------------------------------------------------------------------------------------------------------------

class Dragon : public Monster
{
      public:
      
      Dragon() 
      { 
           cout << "\n\tCreating Dragon object.";
           SetENTITY_CLASS(DRAGON); 
           SetGender("Female"); 
      }
      ~Dragon() { cout << "\n\tDestroying Dragon Object."; }

      //Functions
      void BreathAttack() { cout << "\n\tEmploying breath weapon..."; }

      //Accessors
      

      private:
      bool FIRE;
      bool ICE;
      bool ACID;
      bool treasure;
      int GoldPieces;
      int SilverPieces;
      int CopperPieces;
};

//---------------------------------------------------------------------------------------------------------------------------

class Shaman : public Character
{
      public:
      
      Shaman() 
      { 
           cout << "\n\tCreating Shaman object."; 
           SetENTITY_CLASS(SHAMAN);
      }
      ~Shaman() { cout << "\n\tDestroying Shaman Object."; }

      //Functions
      void Heal() { cout << "\n\tHealing person..."; }
      
	  void Talk() 
      {
           int SayWhat;
           SayWhat = ((rand()%10) + 1);             

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
	           case 3 : cout << "Good karma, bad karma, it's all the same.."; 
                        break;
	           case 4 : cout << "I have a secret to tell..."; 
                        break;
	           case 5 : cout << "To unlock the gate between worlds one needs a key"; 
                        break;
	           case 6 : cout << "You are not from this world, I see that now"; 
                        break;
	           case 7 : cout << "You did not yet know it traveler, but you must\n"
                             << "seek\nthe key of the fish god!"; 
                        break;
               case 8 : cout << "Sometimes I wish I'd never taken that vow of chastity"; 
                            break;
               case 9 : cout << "Do you think I'm pretty? Don't judge a book by its cover!"; 
                        break;
               case 10 : cout << "Beware the edge of the forest. Giants are afoot"; break;  
	           default : cout << "Uh oh, this should never happen.."; break;
           } //closes switch
	        
           cout << "\".\n\n";
	
    } //close talk function

      private:
      bool MedicineBag;
      bool Staff;
};

//---------------------------------------------------------------------------------------------------------------------------

class Warrior : public Character
{
      public:
      
      Warrior() 
      {   
          cout << "\n\tCreating Warrior object."; 
          SetENTITY_CLASS(WARRIOR);
      }
      ~Warrior()
      { cout << "\n\tDestroying Warrior Object."; }

      private:

};

//---------------------------------------------------------------------------------------------------------------------------

class Mage : public Character
{
      public:
      
      Mage() 
      {   
          cout << "\n\tCreating Mage object.";
          SetENTITY_CLASS(MAGE);
      }
      ~Mage()
      { cout << "\n\tDestroying Mage Object."; }

      private:

};

//---------------------------------------------------------------------------------------------------------------------------

class Fighter : public Character
{
      public:
      
      Fighter() 
      {   
          cout << "\n\tCreating Fighter object."; 
          SetENTITY_CLASS(FIGHTER);
      }
      ~Fighter()
      { cout << "\n\tDestroying Fighter Object."; }

      private:

};

//---------------------------------------------------------------------------------------------------------------------------

class Elf : public Character
{
      public:
      
      Elf() 
      {   
          cout << "\n\tCreating Elf object."; 
          SetENTITY_CLASS(ELF);
      }
      ~Elf()
      { cout << "\n\tDestroying Elf Object."; }

      private:

};

//---------------------------------------------------------------------------------------------------------------------------






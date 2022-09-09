//PRJ - RPG Hills of Darkness - MFC GUI Game - 2006 - C. S. Germany
//File 2 of 7: CLASSES

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_209_PRJ_MFC_RPGGame2_01_GLOBALS.h"

//---------------------------------------------------------------------------------------------------------------------------

//Base class ADT

class Monster
{
      public:
    //-----------------------------------------------------
      Monster(int hp=25, int atk = 1, int def=1)
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nCreating a BASE class monster.";
         pOutput->SetWindowText(MESSAGE);
      }
    //-----------------------------------------------------
      ~Monster()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a BASE class monster.";
         pOutput->SetWindowText(MESSAGE);
      }
    //-----------------------------------------------------

      //Accessor Methods
      void setHit(int hp) { hitpoints = hp; }
      void setAttack(int atk) { atak = atk; }
      void setDefense(int def) { defense = def; }
      void setName(char * nm) { name = nm; }
      int getHit() { return hitpoints; }
      int getAttack() { return atak; }
      int getDefense() { return defense; }
      char * getName() { return name; }
    //-----------------------------------------------------
      protected:
      int hitpoints;
      int atak;
      int defense;
      char * name;
};

//---------------------------------------------------------------------------------------------------------------------------

//Base Class ADT for Characters and Players. Would allow player
//to travel with companions and interact if expanded further

class Character
{
      public:
   //---------------------------------------------------------
      //Constructor
      Character(int Hp = 30, int Atk = 1, int Def = 1, CString nm = "Character")
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nCreating a BASE class Character.";
         pOutput->SetWindowText(MESSAGE);
         hitpoints = Hp; atak = Atk; defense = Def; CharName = nm; level = 0;
         InitializeInventory();
         score = 0;
      }
   //---------------------------------------------------------
      //Destructor
      ~Character()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a BASE class Character.";
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a BASE class Character.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void DisplayStats()
      {
           char NumberBuffer[10] = "";
           string TempString = "";
           CString TempCString = "";

           pName->SetWindowText(" " + CharName);

           _itoa_s(hitpoints, NumberBuffer, 10);
           TempString = NumberBuffer;
           TempCString = TempString.c_str();
           pHitpoints->SetWindowText(TempCString);

           _itoa_s(atak, NumberBuffer, 10);
           TempString = NumberBuffer;
           TempCString = TempString.c_str();
           pAttack->SetWindowText(TempCString);

           _itoa_s(defense, NumberBuffer, 10);
           TempString = NumberBuffer;
           TempCString = TempString.c_str();
           pDefense->SetWindowText(TempCString);

           _itoa_s(score, NumberBuffer, 10);
           TempString = NumberBuffer;
           TempCString = TempString.c_str();
           pScore->SetWindowText(TempCString);
      }
   //---------------------------------------------------------
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
   //---------------------------------------------------------
      void Inventory()
      {
           INVENTORY = "";
           char NumBuffer[10];
           int n = 0;

           INVENTORY = INVENTORY + "\r\n";

           if(dagger)
           {
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Dagger (+ 2 Atk)\r\n\r\n";

           }

           if(sword)
           {
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Sword (+ 4 Atk)\r\n\r\n";
           }

           if(longbow)
           {
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Long Bow (+2 Dist)\r\n\r\n";
           }

           if(chainmail)
           {
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Chain Mail (+ 2 Def)\r\n\r\n";
           }

           if(fullbodyarmor)
           {
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Armor (+4 Def)\r\n\r\n";
           }

           if(healingpotion > 0)
           {
               ++n;
               INVENTORY = INVENTORY + itoa(n,NumBuffer,10) +
               ". Healing Potion\r\n (+20HP)\r\n Quantity: " +
               _itoa(healingpotion,NumBuffer,10) + "\r\n\r\n";
           }

           if(FishKey)
           {
              
               ++n;
               INVENTORY = INVENTORY + _itoa(n,NumBuffer,10)
               + ". Fish Key\r\n (Object Access)\r\n";
           }

           if(!dagger && !sword && !longbow && !chainmail
                      && !fullbodyarmor && !healingpotion && ! FishKey)
           {
                INVENTORY = INVENTORY
                + "\r\n\r\nHow sad!\r\n\r\nAbsolute\r\nNothing!!!";
           }

           pInventory->SetWindowText(INVENTORY);
      }
   //---------------------------------------------------------
      void Attack(Monster * Opponent)
      {
           int damage = 0;
           char NumBuffer[10];
           damage = Randy(10) + atak;

           if(dagger && UseDagger)
           {
              MESSAGE = MESSAGE + CharName + " stabs with the dagger!\r\n";
              damage = damage + 2;
              PlaySound(L"media/knife.wav",NULL,SND_FILENAME|SND_ASYNC);
           }
           else if(sword && UseSword)
           {
              MESSAGE = MESSAGE + " swings the sword!\r\n";
              damage = damage + 4;
              PlaySound(L"media/sword.wav",NULL,SND_FILENAME|SND_ASYNC);
           }
           else if(longbow && UseLongBow)
           {
              MESSAGE = MESSAGE + CharName + " releases the string of the longbow!\r\n";
              damage = damage + 2;
              PlaySound(L"media/bow.wav",NULL,SND_FILENAME|SND_ASYNC);
           }
           else
           {
              MESSAGE = MESSAGE + CharName +
              " engages the oponent in brutal hand to hand combat!\r\n";
              PlaySound(L"media/hand.wav",NULL,SND_FILENAME|SND_ASYNC);
           }

           MESSAGE = MESSAGE + "\r\n********* " + CharName
           + " Attacks! *********\r\n" + "Before Attack:\r\n"
           + CharName + " Hitpoints = "
           + itoa(hitpoints,NumBuffer,10) + "\r\nOpponent Hitpoints = "
           + itoa(Opponent->getHit(),NumBuffer,10) + "\r\n";

           if(damage - Opponent->getDefense() > 0)
           { damage = damage - Opponent->getDefense(); }
           else { damage = 0; }

           //Prevent negative values. Check that oponent is still alive.
           if((Opponent->getHit() - damage) > 0)
           { Opponent->setHit((Opponent->getHit() - damage)); }
           else
           { Opponent->setHit(0); }

           MESSAGE = MESSAGE + "\r\nAfter Attack:\r\n" + CharName + " Hitpoints = "
           + itoa(hitpoints,NumBuffer,10) + "\r\nOpponent Hitpoints = "
           + itoa(Opponent->getHit() ,NumBuffer,10) + "\r\n";

           DisplayStats();

           pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void Cheat()
      {
           setDagger(true);
           setSword(true);
           setLongBow(true);
           setChainMail(true);
           setFullBodyArmor(true);
           setHealingPotion(7);
           setFishKey(true);
      }
   //---------------------------------------------------------
      void UseHealingPotion()
      {
           if(healingpotion > 0)
           {
               hitpoints += 20;
               --healingpotion;
               DisplayStats();
               Inventory();

               pOutput->GetWindowText(MESSAGE);
               MESSAGE = MESSAGE +
               "\r\n You drink the healing elixir and feel revived!";
           }
           else
           {
               pOutput->GetWindowText(MESSAGE);
               MESSAGE = MESSAGE +
               "\r\n Wishful thinking. You don't have any healing potions!";
           }

           pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------             
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
   //---------------------------------------------------------
      //Character Attribute Accessor Methods
      void setHit(int hp) { hitpoints = hp; }
      void setAttack(int atk) { atak = atk; }
      void setDefense(int def) { defense = def; }
      void setLevel(int lvl) { level = lvl; }
      void setLocation(int loki) { location = loki; }
      void setName(CString nm) { CharName = nm; }
      void setScore(int sc) { score = sc; }
      int getHit() { return hitpoints; }
      int getAttack() { return atak; }
      int getDefense() { return defense; }
      int getLevel() { return level; }
      int getLocation() { return location; }
      int getScore() { return score; }
      CString getName() { return CharName; }
   //---------------------------------------------------------
      private:
      //Character Attribute Items
      int hitpoints;
      int atak;
      int defense;
      int level;
      int location;
      int score;
      CString CharName;
   //---------------------------------------------------------
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
   //---------------------------------------------------------
      Player()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nCreating a DERIVED class Player.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      ~Player()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a DERIVED class Player.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      //Accessor Methods
      private:
};

//---------------------------------------------------------------------------------------------------------------------------

//Derives from Monster

class Dragon : public Monster
{
      public:

   //---------------------------------------------------------
      Dragon(int hp=25, int atk = 1, int def=1)
      {
         Monster::hitpoints = hp;
         Monster::atak = atk;
         Monster::defense = def;
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nCreating a Dragon.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      ~Dragon()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a Dragon.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void Attack(Character * Opponent)
      {
          //Since we are calling members of the base class, we use the "this" pointer.
          char NumBuffer[10];
          MESSAGE = "";
          MESSAGE = MESSAGE + "\r\n********** Dragon Attacks! **********\r\n" +
          "Before Attack:\r\nDragon Hitpoints = " +
          itoa(this->getHit(),NumBuffer,10) +
          "\r\n" + Opponent->getName() + " Hitpoints = " +
          itoa(Opponent->getHit(),NumBuffer,10) ;

          int damage = 0;
          damage = Randy(10) + this->getAttack();

          if(damage > Opponent->getDefense())
          { damage = damage - Opponent->getDefense(); }
          else
          { damage = 0; }

          if(Opponent->getFullBodyArmor())
          {
             if(damage > 4)
             { damage = damage - 4; }
          }

          if(Opponent->getChainMail())
          {
             if(damage > 2)
             { damage = damage - 2; }
          }

          //Prevent negative values. Check that oponent is still alive.
          if((Opponent->getHit() - damage) > 0)
          { Opponent->setHit((Opponent->getHit() - damage)); }
          else
          { Opponent->setHit(0); }

          MESSAGE = MESSAGE + "\r\n\r\nAfter Attack:\r\nDragon Hitpoints = " +
          itoa(this->getHit(),NumBuffer,10) + "\r\n" +
          Opponent->getName() + " Hitpoints = " +
          itoa(Opponent->getHit(),NumBuffer,10);

          pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void BreatheFire()
      {
           pOutput->GetWindowText(MESSAGE);
           MESSAGE = MESSAGE + "\r\nDragon breathing fire!";
           pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
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
   //---------------------------------------------------------
      Giant(int hp=20, int atk = 1, int def=1)
      {
          Monster::hitpoints = hp;
          Monster::atak = atk;
          Monster::defense = def;
          pOutput->GetWindowText(MESSAGE);
          MESSAGE = MESSAGE + "\r\nCreating a Giant.";
          pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      ~Giant()
      {
          pOutput->GetWindowText(MESSAGE);
          MESSAGE = MESSAGE + "\r\nDestroying a Giant.";
          pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void Stomp()
      {
           pOutput->GetWindowText(MESSAGE);
           MESSAGE = MESSAGE + "\r\nGiant stomping on object.";
           pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void SwingClub()
      {
           pOutput->GetWindowText(MESSAGE);
           MESSAGE = MESSAGE + "\r\nGiant swinging club.";
           pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void Attack(Character * Opponent)
      {
          //Since we are calling members of the base class, we use the "this" pointer.
          char NumBuffer[10];

          MESSAGE = MESSAGE + "\r\n********** Giant Attacks! **********\r\n" +
          "Before Attack:\r\nGiant Hitpoints = " +
          itoa(this->getHit(),NumBuffer,10) +
          + "\r\n" + Opponent->getName() + " Hitpints = " +
          itoa(Opponent->getHit(),NumBuffer,10);

          int damage = 0;
          damage = Randy(10) + this->getAttack();

          if(damage > Opponent->getDefense())
          { damage = damage - Opponent->getDefense(); }
          else { damage = 0; }

          if(Opponent->getFullBodyArmor())
          {
             if(damage > 4)
             { damage = damage - 4; }
          }

          if(Opponent->getChainMail())
          {
             if(damage > 2)
             { damage = damage - 2; }
          }

          //Prevent negative values. Check that oponent is still alive.
          if((Opponent->getHit() - damage) > 0)
          {
              Opponent->setHit((Opponent->getHit() - damage));
          }
          else
          { Opponent->setHit(0); }

          MESSAGE = MESSAGE + "\r\n\r\nAfter Attack:\r\nGiant Hitpoints = " +
          itoa(this->getHit(),NumBuffer,10) + "\r\n"
          + Opponent->getName() + " Hitpoints = "
          + itoa(Opponent->getHit(),NumBuffer,10);

          pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      //Accessor Methods
      void setClub(bool club) { HasClub = club; }
      bool getClub() { return HasClub; }

      private:
      bool HasClub;
};

//---------------------------------------------------------------------------------------------------------------------------

class Shaman : public Character
{
      public:
   //---------------------------------------------------------
      Shaman()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nCreating a DERIVED class Shaman.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      ~Shaman()
      {
         pOutput->GetWindowText(MESSAGE);
         MESSAGE = MESSAGE + "\r\nDestroying a Shaman.";
         pOutput->SetWindowText(MESSAGE);
      }
   //---------------------------------------------------------
      void Talk()
      {
           int SayWhat;
           SayWhat = Randy(10);

           MESSAGE = "";
           MESSAGE = MESSAGE + "\r\nThe Shaman looks at you from beneath her priestly "
           + "garments and says," + "\r\n\r\n\"";

           switch(SayWhat)
           {
               case 1 : MESSAGE = MESSAGE
                        + "I like wild flowers. They are very beautiful, and\r\n"
                        + "their restorative powers are merely a fringe benefit";
                        break;
               case 2 : MESSAGE = MESSAGE
                        + "Do not look at the outward appearance of things,\r\n"
                        + "character should be judged by what is on the inside.";
                        break;
               case 3 : MESSAGE = MESSAGE
                        + "Good karma, bad karma, it's all the same..";
                        break;
               case 4 : MESSAGE = MESSAGE + "I have a secret to tell...";
                        break;
               case 5 : MESSAGE = MESSAGE + "To unlock the gate between worlds one needs a key";
                        break;
               case 6 : MESSAGE = MESSAGE + "You are not from this world, I see that now";
                        break;
               case 7 : MESSAGE = MESSAGE
                        + "You did not yet know it traveler, but you must "
                        + "\r\nseek the key of the fish god!";
                        break;
               case 8 : MESSAGE = MESSAGE + "Sometimes I wish I'd never taken that vow of chastity";
                        break;
               case 9 : MESSAGE = MESSAGE + "Do you think I'm pretty? Don't judge a book by its cover!";
                        break;
               case 10 : MESSAGE = MESSAGE +"Beware the edge of the forest. Giants are afoot";
                         break;
               default : MESSAGE = MESSAGE + "Uh oh, this should never happen..";
                         break;
           }//closes switch

           MESSAGE = MESSAGE + "\".";

           pOutput->SetWindowText(MESSAGE);

      }//close talk function
   //---------------------------------------------------------
      private:
      bool staff;
      bool medicinebag;
};

//---------------------------------------------------------------------------------------------------------------------------












//PRJ - MegaPet3 - MFC GUI Game - 2006 - C. S. Germany
//File 2 of 7: CLASSES

//---------------------------------------------------------------------------------------------------------------------------

//Class Inheritance Hierarchy
//The Base Class ADT (Abstract Data Type)

class Pet
{
      public: 
	  Pet() 
	  {       
              TEMP = TEMP + "\r\n Creating a Pet object...";
	          MainOutput->SetWindowText(TEMP);
	  }
	  ~Pet() 
	  {  
              TEMP = TEMP + "\r\n Destroying a Pet object...";
			  MainOutput->SetWindowText(TEMP);	      
	  }
	  //-----------------------------------------------------------------
      void InitializePet()
	  {
	       PetName = "Anonymous";
		   CustomizePetSequence = 1;
		   PetInterface = 0;
           
		   //Set Up Media Files for Class
		   PetImageFile = PetImageDirectory + PetImageFile;
           PetAtkSoundFile = PetAudioSoundEffectsDirectory + PetAtkSoundFile;
           PetWinSoundFile = PetAudioMusicDirectory + PetWinSoundFile;
           PetLoseSoundFile = PetAudioMusicDirectory + PetLoseSoundFile;
           PetPICTURE = (HBITMAP) LoadImage(NULL,PetImageFile,
                         IMAGE_BITMAP,110,100,LR_LOADFROMFILE);
	  }
      //Functions
	  //-----------------------------------------------------------------
	  void Talk() { }
      //-----------------------------------------------------------------
	  void Taunt() { }
	  //-----------------------------------------------------------------
	  void Train() 
	  { }
	  //-----------------------------------------------------------------
      void Attack(Pet * opponent)
	  {
		   //Note: Not necessary to cast with srand, just to avoid warning
		   srand((unsigned int)time(0));
		   int AdjustDamage;
		   int DAMAGE = (rand() % Max_Damage) + 1;
           
		   TEMP = TEMP + "\r\n\r\n " + PetName + " attacks " + opponent->GetPetName()
			       + "\r\n for a total of " + Number_To_CS(DAMAGE) + " points"
				   + "\r\n of damage.";
		   MainOutput->SetWindowText(TEMP);
		   
           PlaySound(PetAtkSoundFile,NULL,SND_FILENAME|SND_ASYNC);
		   XSleep(3000);
           if(strength > 5)
		   {
               AdjustDamage = (rand() % 5) + 1;
			   DAMAGE = DAMAGE + AdjustDamage;
               TEMP = TEMP + "\r\n\r\n Due to " + PetName + "'s strength,"
			           + "\r\n an additional " + Number_To_CS(AdjustDamage) + " points"
					   + "\r\n of damage are generated."; 
			   MainOutput->SetWindowText(TEMP);
			   XSleep(4000);
		   }
           /*
		   if(speed > 5)
		   {  }
		   */
           if(opponent->GetDefense() > 5)
		   { 
			   AdjustDamage = (rand() % 3) + 1;
			   if(DAMAGE - AdjustDamage < 0)
			   { 
				   TEMP = TEMP +  "\r\n\r\n " + opponent->GetPetName()
				           + "'s defensive capabilities "
				           + "\r\n completely block all damage!";
				   DAMAGE = 0; 
			   }
			   else
			   { 
				   TEMP = TEMP +  "\r\n\r\n " + opponent->GetPetName()
				           + "'s defensive capabilities "
				           + "\r\n deflect " + Number_To_CS(AdjustDamage)
						   + " points of damage.";
				   DAMAGE = DAMAGE - AdjustDamage; 
			   }
			   MainOutput->SetWindowText(TEMP);
			   XSleep(4000);
		   }
           
           if(SpecialAbilityEnergy > 5)
		   {
              SpecialAbilityEnergy = SpecialAbilityEnergy - 10;
		   }
           TEMP = "";
           if(opponent->GetHealth() - DAMAGE > 0)
		   {
		      opponent->SetHealth(opponent->GetHealth() - DAMAGE);
			  TEMP = TEMP + "\r\n\r\n The END result is that " + PetName 
				      + " attacked \r\n " + opponent->GetPetName()
			          + " for a TOTAL of " + Number_To_CS(DAMAGE) + " points"
					  + "\r\n of damage.";
		   }
		   else 
		   { 
			   opponent->SetHealth(0);
               TEMP = TEMP + "\r\n\r\n The END result is that " + PetName 
				       + " attacked \r\n " + opponent->GetPetName()
			           + " and finished off what little life \r\n it"
					   + " had left...";
		   }
		   MainOutput->SetWindowText(TEMP);
		   MainOutput->SetScrollPos(MainOutput->GetLineCount(),0,true); //AUTOSCROLL it down
		   View();
		   PET1->View();
		   PET2->View();
		   XSleep(5000);
	  }
	  //-----------------------------------------------------------------
	  void Feed() 
	  { 
           TEMP = "";
           if(health < 50)
           {
               TEMP = TEMP + "\r\nYou feed your pet. This brings it "
			           + "happy contentment and adds 3 points to"
                       + " its Life.\r\n";
               health = health + 3;
           }
           else
           {
               TEMP = TEMP + "\r\nYour feed your pet, but it is just not"
			           + " hungry. As a result, it gets sick and vomits"
                       + " on your new carpet. This causes you to scold"
                       + " it, and it looses 1 life point.\r\n";
		       health = health - 1;
           }
	       View(); 
		   
		   MainOutput->SetWindowText(TEMP); 
		   //PlaySound("media/Feed_Sound.wav",NULL,SND_FILENAME|SND_ASYNC);	  
	  }
	  //-----------------------------------------------------------------
      void CustomizePet()
      {
	       switch(CustomizePetSequence)
		   {
                case 1 : TEMP = TEMP + "\r\n\r\n   Enter a name for Pet1"
							 + "\r\n   and click \"ENTER\" to continue.";
					     CustomizePetSequence++;
					     break;
				case 2:  Input->GetWindowText(TEMP);
					     Input->SetWindowText(L"");
                         PetName = TEMP;
						 View();
						 TEMP = TEMP + "\r\n\r\n   Now you must choose how to allocate"
							     + "\r\n    your Pet's attributes. There is an"
								 + "\r\n    element of strategy to this. You only"
								 + "\r\n    have 100 points to allocate. For"
								 + "\r\n    example, give your Pet more speed and"
								 + "\r\n    it gets more attacks per round. The"
								 + "\r\n    tradeoff is that there will be less"
								 + "\r\n    available for strength and so that while"
								 + "\r\n    the Pet will get more attacks it will do"
								 + "\r\n    less damage per attack."
								 + "\r\n    You have 100 points to allocate. How much"
								 + "\r\n    will you give your Pet for speed?";
					     CustomizePetSequence++;
					     break;
				default: break;
		   }    
		  
      }
	  //-----------------------------------------------------------------
	  void View()
	  {   
           char buffer[10];
		   
		   if(PetInterface == 1)
		   {
			   Pet1TEMP = "";
               Pet1_Box_Name->SetWindowText(PetName);
			   Pet1_Box_SpecialDefense->SetWindowText(spcdef);
               Pet1_Box_SpecialAttack->SetWindowText(spcatk);
			   Pet1_Box_Species->SetWindowText(Species);
			   _itoa_s(health, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_Health->SetWindowText(Pet1TEMP);
               _itoa_s(speed, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_Speed->SetWindowText(Pet1TEMP);
               _itoa_s(strength, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_Strength->SetWindowText(Pet1TEMP);
			   _itoa_s(attack, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_Attack->SetWindowText(Pet1TEMP);
			   _itoa_s(def, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_Defense->SetWindowText(Pet1TEMP);
			   _itoa_s(SpecialAbilityEnergy, buffer, 10);
			   Pet1TEMP = buffer;
               Pet1_Box_SpecAbilEnergy->SetWindowText(Pet1TEMP);
               Pet1_HealthMeter->SetPos(health);
			   Pet1_HealthBar->SetPos(health);
               Pet1TEMP = "";
     	       if(health > 80 && health <= 100) 
			   { Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is in\r\n   excellent health."; }
		       else if(health > 60 && health <= 80) 
			   { Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is\r\n   somewhat healthy."; }
			   else if(health > 40 && health <= 60) 
			   { Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is\r\n   in pain."; }
		       else if(health > 20 && health <= 40) 
			   { 
				   Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is mortally\r\n   wounded"
			                        + "\r\n   and in\r\n   terrible suffering."; 
			   }
		       else if(health > 0 && health <= 20) 
			   { 
				   Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is at the"
			                        + "\r\n   brink of death!"; 
			   }
		       else  { Pet1TEMP = Pet1TEMP + "\r\n   " + PetName + " is dead!"; }
			   Pet1_Status->SetWindowText(Pet1TEMP);
			   Pet1View->SetBitmap(PetPICTURE); 
		   }
		   if(PetInterface == 2)
		   {
               Pet2TEMP = "";
			   Pet2_Box_Name->SetWindowText(PetName);
			   Pet2_Box_SpecialDefense->SetWindowText(spcdef);
               Pet2_Box_SpecialAttack->SetWindowText(spcatk);
			   Pet2_Box_Species->SetWindowText(Species);
			   _itoa_s(health, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_Health->SetWindowText(Pet2TEMP);
               _itoa_s(speed, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_Speed->SetWindowText(Pet2TEMP);
               _itoa_s(strength, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_Strength->SetWindowText(Pet2TEMP);
			   _itoa_s(attack, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_Attack->SetWindowText(Pet2TEMP);
			   _itoa_s(def, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_Defense->SetWindowText(Pet2TEMP);
			   _itoa_s(SpecialAbilityEnergy, buffer, 10);
			   Pet2TEMP = buffer;
               Pet2_Box_SpecAbilEnergy->SetWindowText(Pet2TEMP);
               Pet2_HealthMeter->SetPos(health);
			   Pet2_HealthBar->SetPos(health);
               Pet2TEMP = "";
     	       if(health > 80 && health <= 100) 
			   { Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is in\r\n   excellent health."; }
		       else if(health > 60 && health <= 80) 
			   { Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is\r\n   somewhat healthy."; }
			   else if(health > 40 && health <= 60) 
			   { Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is\r\n   in pain."; }
		       else if(health > 20 && health <= 40) 
			   { 
				   Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is mortally\r\n   wounded"
			                        + "\r\n   and in\r\n   terrible suffering."; 
			   }
		       else if(health > 0 && health <= 20) 
			   { 
				   Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is at the"
			                        + "\r\n   brink of death!"; 
			   }
		       else  { Pet2TEMP = Pet2TEMP + "\r\n   " + PetName + " is dead!"; }
			   Pet2_Status->SetWindowText(Pet2TEMP);
			   Pet2View->SetBitmap(PetPICTURE); 
		   }
	      
}//close View function

     //-----------------------------------------------------------------
	  //Accessor Methods
	  void SetHealth(int X) { health = X; }
	  int GetHealth() { return health; }
	  void SetSpeed(int X) { speed = X; }
	  int GetSpeed() { return speed; }
	  void SetStrength(int X) { strength = X; }
	  int GetStrength() { return strength; }
	  void SetAttack(int X) { attack = X; }
	  int GetAttack() { return attack; }
	  void SetDefense(int X) { def = X; }
	  int GetDefense() { return def; }
	  void SetSpecialAbilityEnergy(int X) { SpecialAbilityEnergy = X; }
	  int GetSpecialAbilityEnergy() { return SpecialAbilityEnergy; }
	  void SetPetName(CString X) { PetName = X; }
	  CString GetPetName() { return PetName; }
	  void SetSpecies(CString X) { Species = X; }
	  CString GetSpecies() { return Species; }
	  void SetSpcAtk(CString X) { spcatk = X; }
	  CString GetSpcAtk() { return spcatk; }
	  void SetSpcDef(CString X) { spcdef = X; }
	  CString GetSpcDef() { return spcdef; }
	  void SetPetImageFile(CString X) { PetImageFile = X; }
	  CString GetPetImageFile() { return PetImageFile; }
      void SetPetAtkSoundFile(CString X) { PetAtkSoundFile = X; }
	  CString GetPetAtkSoundFile() { return PetAtkSoundFile; }
      void SetPetWinSoundFile(CString X) { PetWinSoundFile = X; }
	  CString GetPetWinSoundFile() { return PetWinSoundFile; }
      void SetPetLoseSoundFile(CString X) { PetLoseSoundFile = X; }
	  CString GetPetLoseSoundFile() { return PetLoseSoundFile; }
      void SetPetPICTURE(HBITMAP X) { PetPICTURE = X; }
	  HBITMAP GetPetPICTURE() { return PetPICTURE; }
	  void SetPetInterface(int X) { PetInterface = X; }
	  int GetPetInterface() { return PetInterface; }
	  void SetCustomizePetSequence(int X) { CustomizePetSequence = X; }
	  int GetCustomizePetSequence() { return CustomizePetSequence; }
      //-----------------------------------------------------------------
      //Private Data 
      private: 
	  int health;
	  int speed;
	  int strength;
	  int attack;
	  int def;
	  int SpecialAbilityEnergy;
	  CString PetName;
	  CString Species;
	  CString spcatk;
      CString spcdef;
	  CString PetImageFile;
	  CString PetAtkSoundFile;
      CString PetWinSoundFile;
      CString PetLoseSoundFile;
	  HBITMAP PetPICTURE;
	  CStatic * PetView;
      int PetInterface;
      int CustomizePetSequence;
};

//---------------------------------------------------------------------------------------------------------------------------

//Derived class from ADT Base class

class Animal : public Pet
{
      public: 
	  Animal() 
	  {  
              TEMP = TEMP + "\r\n Creating an Animal object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~Animal() 
	  {  
              TEMP = TEMP + "\r\n Destroying an Animal object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class Plant : public Pet
{
      public: 
	  Plant() 
	  {  
              TEMP = TEMP + "\r\n Creating a Plant object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~Plant() 
	  {  
              TEMP = TEMP + "\r\n Destroying a Plant object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class Mammal : public Animal
{
      public: 
	  Mammal() 
	  {  
              TEMP = TEMP + "\r\n Creating a Mammal object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~Mammal() 
	  {  
              TEMP = TEMP + "\r\n Destroying a Mammal object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class Reptile : public Animal
{
      public: 
	  Reptile() 
	  {  
              TEMP = TEMP + "\r\n Creating a Reptile object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~Reptile() 
	  {  
              TEMP = TEMP + "\r\n Destroying a Reptile object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class Amphibian : public Animal
{
      public: 
	  Amphibian() 
	  {  
              TEMP = TEMP + "\r\n Creating an Amphibian object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~Amphibian() 
	  {  
              TEMP = TEMP + "\r\n Destroying an Amphibian object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class HYBRID : public Animal
{
      public: 
	  HYBRID() 
	  {  
              TEMP = TEMP + "\r\n Creating a HYBRID object...";
	          
			  MainOutput->SetWindowText(TEMP);
	  }
	  ~HYBRID() 
	  {  
              TEMP = TEMP + "\r\n Destroying a HYBRID object...";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
      
     //Private Data 
     private:   
     string HybridAbility;
};

//---------------------------------------------------------------------------------------------------------------------------

class SNAKE : public Reptile
{
      public: 
	  SNAKE() 
	  {  
              TEMP = TEMP + "\r\n Creating a SNAKE.";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeSNAKE();
	  }
	  ~SNAKE() 
	  {  
              TEMP = TEMP + "\r\n Destroying a SNAKE.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeSNAKE()
	  {
	       SetSpecies("Snake");
		   SetPetImageFile("Snake1.bmp");
		   SetHealth(100);
	       SetSpeed(2);
	       SetStrength(8);
	       SetAttack(5);
	       SetDefense(5);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Venom");
           SetSpcDef("Scales");
		   InitializePet();
	  }
	  //Accessor Methods
     //Private Data 
     private: 
	 int Venom;
};

//---------------------------------------------------------------------------------------------------------------------------

class RABBIT : public Mammal
{
      public: 
	  RABBIT() 
	  {  
              TEMP = TEMP + "\r\n Creating a RABBIT.";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeRABBIT();
	  }
	  ~RABBIT() 
	  {  
              TEMP = TEMP + "\r\n Destroying a RABBIT.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeRABBIT()
	  {
	       SetSpecies("Rabbit");
		   SetPetImageFile("Rabbit1.bmp");
		   SetHealth(100);
	       SetSpeed(8);
	       SetStrength(2);
	       SetAttack(2);
	       SetDefense(8);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Thump");
           SetSpcDef("Jump");
		   InitializePet();
	  }	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class SNABBIT : public HYBRID
{
      public: 
	  SNABBIT() 
	  {  
              TEMP = TEMP + "\r\n Creating a SNABBIT (Snake + Rabbit).";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeSNABBIT();
	  }
	  ~SNABBIT() 
	  {  
              TEMP = TEMP + "\r\n Destroying a SNABBIT.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeSNABBIT()
	  {
	       SetSpecies("Snabbit");
		   SetPetImageFile("Snabbit1.bmp");
		   SetPetAtkSoundFile("Grind.wav");
           SetPetWinSoundFile("SucksToBeYou.wav");
           SetPetLoseSoundFile("Jeopardy.wav");
		   SetHealth(100);
	       SetSpeed(7);
	       SetStrength(3);
	       SetAttack(5);
	       SetDefense(5);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Venom");
           SetSpcDef("Thump Hop");
		   InitializePet();
	  }	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class LIGER : public HYBRID
{
      public: 
	  LIGER() 
	  {  
              TEMP = TEMP + "\r\n Creating a LIGER (Lion + Tiger).";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeLIGER();
	  }
	  ~LIGER() 
	  {  
              TEMP = TEMP + "\r\n Destroying a LIGER.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeLIGER()
	  {
	       SetSpecies("Liger");
		   SetPetImageFile("Liger1.bmp");
		   SetPetAtkSoundFile("Roar.wav");
           SetPetWinSoundFile("BadToTheBone.wav");
           SetPetLoseSoundFile("WelcomeToTheJungle.wav");
		   SetHealth(100);
	       SetSpeed(5);
	       SetStrength(5);
	       SetAttack(7);
	       SetDefense(3);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Scratch");
           SetSpcDef("Dodge");
		   InitializePet();
	  }	
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class FRANTHER : public HYBRID
{
      public: 
	  FRANTHER() 
	  {  
              TEMP = TEMP + "\r\n Creating a FRANTHER (Frog + Panther).";
	          
			  MainOutput->SetWindowText(TEMP);
              InitializeFRANTHER();
	  }
	  ~FRANTHER() 
	  {  
              TEMP = TEMP + "\r\n Destroying a FRANTHER.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeFRANTHER()
	  {
	       SetSpecies("Franther");
		   SetPetName("Anonymous");
		   SetPetImageFile("Panther1.bmp");
		   SetPetAtkSoundFile("Panther.wav");
           SetPetWinSoundFile("CantTouchThis.wav");
           SetPetLoseSoundFile("Jeopardy.wav");
		   SetHealth(100);
	       SetSpeed(5);
	       SetStrength(5);
	       SetAttack(6);
	       SetDefense(4);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Claw");
           SetSpcDef("Stealth");
		   InitializePet();
	  }		  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class JONKEY : public HYBRID
{
      public: 
	  JONKEY() 
	  {  
              TEMP = TEMP + "\r\n Creating a Jonkey (JellyFish + Monkey).";
	          
			  MainOutput->SetWindowText(TEMP);
              InitializeJONKEY();
	  }
	  ~JONKEY() 
	  {  
              TEMP = TEMP + "\r\n Destroying a Jonkey object.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
      void InitializeJONKEY()
	  {
	       SetSpecies("Jonkey");
		   SetPetImageFile("Monkey2.bmp");
		   SetPetAtkSoundFile("Sonic.wav");
           SetPetWinSoundFile("IceIceBaby.wav");
           SetPetLoseSoundFile("IWillSurvive.wav");
		   SetHealth(100);
	       SetSpeed(4);
	       SetStrength(6);
	       SetAttack(5);
	       SetDefense(5);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("ICE");
           SetSpcDef("Jelly Swing");
		   InitializePet();
	  }	  
	  //Accessor Methods
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class CROG : public HYBRID
{
      public: 
	  CROG() 
	  {  
              TEMP = TEMP + "\r\n Creating a CROG (Crocodile + Dog).";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeCROG();
	  }
	  ~CROG() 
	  {  
              TEMP = TEMP + "\r\n Destroying a CROG.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  
	  //Accessor Methods
	  void InitializeCROG()
	  {
	       SetSpecies("Crog");
		   SetPetImageFile("Croc1.bmp");
		   SetPetAtkSoundFile("Spook.wav");
           SetPetWinSoundFile("TheRock.wav");
           SetPetLoseSoundFile("MachoMan.wav");
		   SetHealth(100);
	       SetSpeed(4);
	       SetStrength(6);
	       SetAttack(5);
	       SetDefense(5);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Lash");
           SetSpcDef("Armor");
		   InitializePet();
	  }	
     //Private Data 
     private:      
};

//---------------------------------------------------------------------------------------------------------------------------

class SQUEEL : public HYBRID
{
      public: 
	  SQUEEL() 
	  {  
              TEMP = TEMP + "\r\n Creating a SQUEEL (Squirrel + Eel).";
	          
			  MainOutput->SetWindowText(TEMP);
			  InitializeSQUEEL();
	  }
	  ~SQUEEL() 
	  {  
              TEMP = TEMP + "\r\n Destroying a SQUEEL.";
	          
			  MainOutput->SetWindowText(TEMP);	      
	  }
      //Functions
	  void InitializeSQUEEL()
	  {
	       SetSpecies("Squeel");
		   SetPetImageFile("Squirrel1.bmp");
		   SetPetAtkSoundFile("Rip.wav");
           SetPetWinSoundFile("DiscoInferno.wav");
           SetPetLoseSoundFile("StayinAlive.wav");
		   SetHealth(100);
	       SetSpeed(8);
	       SetStrength(2);
	       SetAttack(2);
	       SetDefense(8);
	       SetSpecialAbilityEnergy(100);
	       SetSpcAtk("Gnash");
           SetSpcDef("Scurry");
		   InitializePet();
	  }	
	  //Accessor Methods
     //Private Data 
     private:      
};
//---------------------------------------------------------------------------------------------------------------------------















//PRJ - MegaPet3 - MFC GUI Game - 2006 - C. S. Germany
//File 3 of 7: FUNCTIONS

//---------------------------------------------------------------------------------------------------------------------------

//Game Functions

//---------------------------------------------------------------------------------------------------------------------------

CString CONVERT(string X)
{
	//Note: Have to cast to signed int to avoid warning when calling length()
    char TEMP[100] = "?";
	for(int a = 0; a < (int) X.length(); a++)  
	{ TEMP[a] = X[a]; }
	return TEMP;
}

//---------------------------------------------------------------------------------------------------------------------------

//Note: 2 overloaded conversion functions for CString to char array

char * CS_To_CharArray(CString CS)
{ 
	  char * INPUT = new char[100];
	  for(int x = 0; x < CS.GetLength(); x++)
	  { INPUT[x] = (char) CS[x]; }
	  return INPUT;
}

//---------------------------------------------------------------------------------------------------------------------------

void CS_To_CharArray(CString CS, char * SimpleString)
{ 
     for(int z = 0; z < CS.GetLength(); z++)
     { SimpleString[z] = (char) CS[z]; }
}

//---------------------------------------------------------------------------------------------------------------------------

int CS_To_Number(CString CS)
{ 
	  char INPUT[10] = "";
      
	  for(int x = 0; x < CS.GetLength(); x++)
	  { INPUT[x] = (char) CS[x]; }
	  int TheNumber = atoi(INPUT);
	  return TheNumber;
}

//---------------------------------------------------------------------------------------------------------------------------

CString Number_To_CS(int NUM)
{ 
	  char INPUT[10] = "";
	  _itoa_s(NUM,INPUT,10,10);
      CString CS = INPUT;
	  return CS;
}

//---------------------------------------------------------------------------------------------------------------------------

void Initialize_Interface()
{
	 Button_Start->EnableWindow(true);
     Button_Begin_T->EnableWindow(false);
     Button_End_T->EnableWindow(false);
     //Button_Exit->EnableWindow(false);
     Button_Help->EnableWindow(false);
	 Button_Enter->EnableWindow(false);
	 Pet1_Button_LOAD->EnableWindow(true);
	 Pet1_Button_SAVE->EnableWindow(false);
	 Pet1_Button_NEW->EnableWindow(false);
	 Pet1_Button_TRAIN->EnableWindow(false);
	 Pet1_Button_FEED->EnableWindow(false);
	 Pet1_Button_PLAY->EnableWindow(false);
	 Pet1_Button_TALK->EnableWindow(false);
	 Pet1_Button_SLEEP->EnableWindow(false);
	 Pet1_Button_KICK->EnableWindow(false);
	 Pet1_Button_ATTACK->EnableWindow(false);
	 Pet1_Button_DEFEND->EnableWindow(false);
	 Pet1_Button_SPECATTACK->EnableWindow(false);
	 Pet1_Button_SPECDEFEND->EnableWindow(false);
	 Pet2_Button_LOAD->EnableWindow(true);
	 Pet2_Button_SAVE->EnableWindow(false);
	 Pet2_Button_NEW->EnableWindow(false);
	 Pet2_Button_TRAIN->EnableWindow(false);
	 Pet2_Button_FEED->EnableWindow(false);
	 Pet2_Button_PLAY->EnableWindow(false);
	 Pet2_Button_TALK->EnableWindow(false);
	 Pet2_Button_SLEEP->EnableWindow(false);
	 Pet2_Button_KICK->EnableWindow(false);
	 Pet2_Button_ATTACK->EnableWindow(false);
	 Pet2_Button_DEFEND->EnableWindow(false);
	 Pet2_Button_SPECATTACK->EnableWindow(false);
	 Pet2_Button_SPECDEFEND->EnableWindow(false);
	 CreatePetSequence = 1;
	 NeedToCreatePets = true;
	 LoadToggle = false;
     PetImageDirectory = "Images/";
     PetAudioMusicDirectory = "Audio/MusicClips/";
     PetAudioSoundEffectsDirectory = "Audio/SoundEffects/";
	 Max_Damage = 50;
}

//---------------------------------------------------------------------------------------------------------------------------

void CreatePet()
{
	 int choice;
	
	 TEMP = "";
     switch(CreatePetSequence) 
	 {
		 case 1 : TEMP = TEMP + "Mad Science! Choose a type of Transgenic"
				  + "\r\nchimera to create for Pet1.  Options are:\r\n"
				  + "\r\n    1. Jonkey (JellyFish + Monkey)"
				  + "\r\n    2. Franther (Frog + Panther)"
				  + "\r\n    3. Snabbit (Snake + Rabbit)"
                  + "\r\n    4. Liger (Lion + Tiger)"
                  + "\r\n    5. Crog (Crocodile + Dog)"
				  + "\r\n    6. Squeel (Squirrel + Eel)"
				  + "\r\n\r\n Enter your choice in the Input box."
				  + "\r\n Click ENTER to continue.";
				  Button_Enter->EnableWindow(true);
				  Input->SetFocus();
                  CreatePetSequence++;
				  break;
		  
		 case 2:  Input->GetWindowText(TEMP);
                  Input->SetWindowText(L"");
                  choice = atoi(CS_To_CharArray(TEMP));
				  TEMP = "";
                          
                  if(choice > 0 && choice < 7)
				  {
                     switch(choice)
			         {
			              case 1 : PET1 = new JONKEY;
								   TEMP = TEMP + "\r\n\r\n    Jonkeys devestate with venom.";
								   break;
				          case 2 : PET1 = new FRANTHER;
								   TEMP = TEMP + "\r\n\r\n    A Franther? Nice maneuverability.";
								   break;
                          case 3 : PET1 = new SNABBIT;
								   TEMP = TEMP + "\r\n\r\n    Snabbits = dexterity + venom attack.";  
								   break;
				          case 4 : PET1 = new LIGER;
								   TEMP = TEMP + "\r\n\r\n    Ligers possess speed and strength.";
								   break;
                          case 5 : PET1 = new CROG;
								   TEMP = TEMP + "\r\n\r\n    A Crog? Very strong bite attack!";  
								   break;
                          case 6 : PET1 = new SQUEEL;
								   TEMP = TEMP + "\r\n\r\n    Squeels are dextrous and shocking!";  
								   break;
						  default: break;
					 }
				     CreatePetSequence++;
				     PET1->SetPetName("PET 1");
				     PET1->SetPetInterface(1);
				     PET1->View();
					 Pet1_Button_NEW->EnableWindow(false);
					 Pet1_Button_SAVE->EnableWindow(true);
					 Button_Enter->EnableWindow(true);
				     TEMP = TEMP + "\r\n    Click \"ENTER\" to continue.";
				 }
				 else
				 {
					 TEMP = "";
                     TEMP = TEMP + "\r\n\r\n    Sorry, that was simply"
                             + "\r\n    not an available option"
			  	 			 + "\r\n    for you. Your only options"
			 				 + "\r\n    consist of choices 1-6." 
							 + "\r\n\r\n    Ok?\r\n"
							 + "\r\n     Please click \"ENTER\" to continue.";
                     CreatePetSequence--;
				 }
				 break;
		 case 3 : TEMP = "";
			      TEMP = TEMP + "\r\n It's alive! It's alive!\r\n\r\n"
				  + " Now, give your new pet\r\n"
				  + " " + PET1->GetSpecies() + " a name.\r\n\r\n"
				  + " Type it into the \"INPUT\" box below.\r\n\r\n"
                  + " Click \"ENTER\" when you are ready to\r\n"
				  + " continue.";
				  Button_Enter->EnableWindow(true);
				  Input->SetFocus();
                  CreatePetSequence++;
				  break;
		 case 4 : Input->GetWindowText(TEMP);
			      if(TEMP != "")
				  { PET1->SetPetName(TEMP); }
				  else
				  { PET1->SetPetName(L"Anoymous"); }
                  TEMP = "";
                  TEMP = TEMP + "\r\n Pet now named\r\n"
					      + " " + PET1->GetPetName() + ".";
				  TEMP = TEMP + "\r\n\r\n    Now click the \"NEW\" button to\r\n" 
					      + "    give Frankensteinish life to Pet2.";
				  Pet2_Button_NEW->EnableWindow(true);
				  Button_Enter->EnableWindow(false);
				  Input->SetWindowText(L"");
				  Input->SetFocus();
				  PET1->View();
                  CreatePetSequence++;
				  break;
		 case 5 : TEMP = "";
			      TEMP = TEMP + "Mad Science! Choose a type of Transgenic"
				  + "\r\nchimera to create for Pet2.  Options are:\r\n"
				  + "\r\n    1. Jonkey (JellyFish + Monkey)"
				  + "\r\n    2. Franther (Frog + Panther)"
				  + "\r\n    3. Snabbit (Snake + Rabbit)"
                  + "\r\n    4. Liger (Lion + Tiger)"
                  + "\r\n    5. Crog (Crocodile + Dog)"
				  + "\r\n    6. Squeel (Squirrel + Eel)"
				  + "\r\n\r\n Enter your choice in the Input box."
				  + "\r\n Click ENTER to continue.";
				  Button_Enter->EnableWindow(true);
				  Input->SetWindowText(L"");
				  Input->SetFocus();
                  CreatePetSequence++;
				  break;
		  
		 case 6:  Input->GetWindowText(TEMP);
				  Input->SetWindowText(L"");
                  choice = atoi(CS_To_CharArray(TEMP));
				  TEMP = "";
                          
                  if(choice > 0 && choice < 7)
				  {
                     switch(choice)
			         {
			             case 1 : PET2 = new JONKEY;
								  TEMP = TEMP + "\r\n\r\n    Jonkeys devestate with venom.";
								  break;
				         case 2 : PET2 = new FRANTHER;
								  TEMP = TEMP + "\r\n\r\n    A Franther? Nice maneuverability.";
								  break;
                         case 3 : PET2 = new SNABBIT;
								  TEMP = TEMP + "\r\n\r\n    Snabbits = dexterity + venom attack.";  
								  break;
				         case 4 : PET2 = new LIGER;
								  TEMP = TEMP + "\r\n\r\n    Ligers possess speed and strength.";
								  break;
                         case 5 : PET2 = new CROG;
								  TEMP = TEMP + "\r\n\r\n    A Crog? Very strong bite attack!";  
								  break;
                         case 6 : PET2 = new SQUEEL;
								  TEMP = TEMP + "\r\n\r\n    Squeels are dextrous and shocking!";  
								  break;
						 default: break;
					 }
					 CreatePetSequence++;
                     PET2->SetPetName("PET 2");
					 PET2->SetPetInterface(2);
					 PET2->View();
					 Pet2_Button_NEW->EnableWindow(false);
					 Pet2_Button_SAVE->EnableWindow(true);
					 Button_Enter->EnableWindow(true);
					 TEMP = TEMP + "\r\n    Click \"ENTER\" to continue.";
				  }
				  else
				  {
					 TEMP = "";
                     TEMP = TEMP + "\r\n\r\n    Sorry, that was simply"
                             + "\r\n    not an available option"
							 + "\r\n    for you. Your only options"
							 + "\r\n    consist of choices 1-6." 
							 + "\r\n\r\n    Ok?\r\n"
							 + "\r\n     Please click \"ENTER\" to continue.";
                     CreatePetSequence--;
				  }
				  break;
		 case 7 : TEMP = "";
			      TEMP = TEMP + "\r\n It's alive! It's alive!\r\n\r\n"
				  + " Now, give your new pet\r\n"
				  + " " + PET2->GetSpecies() + " a name.\r\n\r\n"
				  + " Type it into the \"INPUT\" box below.\r\n\r\n"
                  + " Click \"ENTER\" when you are ready to\r\n"
				  + " continue.";
				  Button_Enter->EnableWindow(true);
				  Input->SetFocus();
                  CreatePetSequence++;
				  break;
		 case 8 : Input->GetWindowText(TEMP);
			      if(TEMP != "")
				  { PET2->SetPetName(TEMP); }
				  else
				  { PET2->SetPetName("Anoymous"); }
				  TEMP = "";
                  TEMP = TEMP + "\r\n Pet now named\r\n"
					      + " " + PET2->GetPetName() + ".";
				  TEMP = TEMP + "\r\n\r\n    Now click the \"ENTER\" button to\r\n" 
					      + "    continue with the game.";
				  Input->SetWindowText(L"");
				  Input->SetFocus();
				  PET2->View();
                  CreatePetSequence++;
				  break;
		 case 9 : TEMP = "";
                  TEMP = TEMP + "\r\n     Your transgenic chimera Pet objects"
						  + "\r\n     are now ready for action!"
						  + "\r\n\r\n     You MAD SCIENTIST, you..."
						  + "\r\n\r\n     ;-) "
                          + "\r\n\r\n\r\n     Please click \"ENTER\" to continue.";
				  NeedToCreatePets = false;
				  break;
				  default : break; 
	}//close outer switch
	
    MainOutput->SetWindowText(TEMP);
}//close Function

//---------------------------------------------------------------------------------------------------------------------------

void SavePet(Pet * PLAYER) 
{
     TEMP = "";
         CString TheFile = PLAYER->GetPetName() + ".pet";
         ofstream WriteStuff;
         WriteStuff.open(TheFile);
         if(!WriteStuff)
	     {  
		     TEMP = TEMP + "\r\n Houston - we have a problem!\r\n"
			         + "\r\n The file could not be saved";
	     }  
         else 
         {
		     //Save Pet attributes
			 char SimpleString1[50] = "";
			 CS_To_CharArray(PLAYER->GetPetName(),SimpleString1);
             WriteStuff << SimpleString1 << "\n";
			 char SimpleString2[50] = "";
             CS_To_CharArray(PLAYER->GetSpecies(),SimpleString2);
             WriteStuff << SimpleString2 << "\n";
			 char SimpleString3[50] = "";
			 CS_To_CharArray(PLAYER->GetPetImageFile(),SimpleString3);
             WriteStuff << SimpleString3 << "\n";
			 char SimpleString4[50] = "";
			 CS_To_CharArray(PLAYER->GetPetAtkSoundFile(),SimpleString4);
             WriteStuff << SimpleString4 << "\n";
			 char SimpleString5[50] = "";
			 CS_To_CharArray(PLAYER->GetPetWinSoundFile(),SimpleString5);
             WriteStuff << SimpleString5 << "\n";
			 char SimpleString6[50] = "";
             CS_To_CharArray(PLAYER->GetPetLoseSoundFile(),SimpleString6);
             WriteStuff << SimpleString6 << "\n";
			 char SimpleString7[50] = "";
			 CS_To_CharArray(PLAYER->GetSpcAtk(),SimpleString7);
             WriteStuff << SimpleString7 << "\n";
			 char SimpleString8[50] = "";
			 CS_To_CharArray(PLAYER->GetSpcDef(),SimpleString8);
             WriteStuff << SimpleString8 << "\n";
			 
             WriteStuff << PLAYER->GetHealth() << "\n";
             WriteStuff << PLAYER->GetSpeed() << "\n";
		     WriteStuff << PLAYER->GetStrength() << "\n";
		     WriteStuff << PLAYER->GetAttack() << "\n";
		     WriteStuff << PLAYER->GetDefense() << "\n";
		     WriteStuff << PLAYER->GetSpecialAbilityEnergy() << "\n";
	         WriteStuff.close();
             TEMP = TEMP + "\r\n The Pet has been successfully saved."
			         + "\r\n Click \"ENTER\" to continue...";
         }//close else for a successfully opened file
     Button_Enter->EnableWindow(true);
     MainOutput->SetWindowText(TEMP);
}//close function 

//---------------------------------------------------------------------------------------------------------------------------

void LoadPet(int ThePet) 
{
     TEMP = "";
	 string petname = "", species = "", specialattack = "", specialdefense = "",
		    petimagefile = "", petatksoundfile = "", petwinsoundfile = "", petlosesoundfile = "";
	 int health, speed, strength, attack, defense, specialabilityenergy;
     
     CString TheFile = "";
	 Input->GetWindowText(TheFile);
	 TheFile = TheFile + ".pet";
     ifstream ReadStuff;
     ReadStuff.open(TheFile);
     //Detect if successful or not to keep program from crashing on failed load              
     if(!ReadStuff) 
     { 
        TEMP = "";
		TEMP = TEMP + "\r\n\r\n Can not open or find a file using"
			    + "\r\n the name you typed in."
			    + "\r\n Try a different name?";
     }
     else
     {   
           //Read PLAYER attributes  
           getline(ReadStuff, petname);
		   getline(ReadStuff, species);
		   getline(ReadStuff, petimagefile);
           getline(ReadStuff, petatksoundfile);
           getline(ReadStuff, petwinsoundfile);
           getline(ReadStuff, petlosesoundfile);
           getline(ReadStuff, specialattack); 
		   getline(ReadStuff, specialdefense);
           ReadStuff >> health; 
		   ReadStuff >> speed;              
		   ReadStuff >> strength;
           ReadStuff >> attack;
           ReadStuff >> defense;
		   ReadStuff >> specialabilityenergy;
           
           ReadStuff.close();
		   if(ThePet == 1)
		   {
		       if(species == "Jonkey") { PET1 = new JONKEY; }
		       if(species == "Franther") { PET1 = new FRANTHER; }
               if(species == "Snabbit") { PET1 = new SNABBIT; }
		       if(species == "Liger") { PET1 = new LIGER; }
		       if(species == "Crog") { PET1 = new CROG; }
               if(species == "Squeel") { PET1 = new SQUEEL; }
           
		       PET1->SetPetName(CONVERT(petname));
		       PET1->SetSpecies(CONVERT(species));
		       PET1->SetPetImageFile(CONVERT(petimagefile));
		       PET1->SetPetAtkSoundFile(CONVERT(petatksoundfile)); 
		       PET1->SetPetWinSoundFile(CONVERT(petwinsoundfile));	   
		       PET1->SetPetLoseSoundFile(CONVERT(petlosesoundfile));
		       PET1->SetSpcAtk(CONVERT(specialattack));
               PET1->SetSpcDef(CONVERT(specialdefense));
               PET1->SetHealth(health);
		       PET1->SetSpeed(speed);
		       PET1->SetStrength(strength);
		       PET1->SetAttack(attack);
		       PET1->SetDefense(defense);
		       PET1->SetSpecialAbilityEnergy(specialabilityenergy);
               PET1->SetPetInterface(1);
	           PET1->View();
			   
		   }//close if 
		   if(ThePet == 2)
		   {
		       if(species == "Jonkey") { PET2 = new JONKEY; }
		       if(species == "Franther") { PET2 = new FRANTHER; }
               if(species == "Snabbit") { PET2 = new SNABBIT; }
		       if(species == "Liger") { PET2 = new LIGER; }
		       if(species == "Crog") { PET2 = new CROG; }
               if(species == "Squeel") { PET2 = new SQUEEL; }
           
		       PET2->SetPetName(CONVERT(petname));
		       PET2->SetSpecies(CONVERT(species));
		       PET2->SetPetImageFile(CONVERT(petimagefile));
		       PET2->SetPetAtkSoundFile(CONVERT(petatksoundfile)); 
		       PET2->SetPetWinSoundFile(CONVERT(petwinsoundfile));
		       PET2->SetPetLoseSoundFile(CONVERT(petlosesoundfile));
		       PET2->SetSpcAtk(CONVERT(specialattack));
               PET2->SetSpcDef(CONVERT(specialdefense));
               PET2->SetHealth(health);
		       PET2->SetSpeed(speed);
		       PET2->SetStrength(strength);
		       PET2->SetAttack(attack);
		       PET2->SetDefense(defense);
		       PET2->SetSpecialAbilityEnergy(specialabilityenergy);
               PET2->SetPetInterface(2);
	           PET2->View();
		   }//close if 
    TEMP = "\r\n\r\n The Pet was successfully loaded.";
    }//close else
    MainOutput->SetWindowText(TEMP);
}//close function  

//---------------------------------------------------------------------------------------------------------------------------

void Combat()
{
     int WhoGoesFirst = (rand() % 2) + 1;
     TEMP = "";
     if(WhoGoesFirst == 1)
	 {
         TEMP = TEMP + "\r\n  " + PET1->GetPetName() + " the " 
				 + PET1->GetSpecies()
				 + " gets\r\n"
				 + "  the luck of the draw with\r\n"
			     + "  the very FIRST ATTACK!\r\n";
		 MainOutput->SetWindowText(TEMP);
         XSleep(3000);
         while(PET1->GetHealth() > 0 && PET2->GetHealth() > 0)
	     {
	         TEMP = "";
             TEMP = TEMP + " " + PET1->GetPetName() + "'s ATTACK begins!\r\n"
				     + "---------------------------------------------";
			 MainOutput->SetWindowText(TEMP);
			 XSleep(4000);
			 PET1->Attack(PET2);
		     if(PET2->GetHealth() > 0) 
			 {
                TEMP = "";
                TEMP = TEMP + " " + PET2->GetPetName() + " makes a counter-attack!\r\n"
				     + "---------------------------------------------";
				MainOutput->SetWindowText(TEMP);
				XSleep(4000);
				PET2->Attack(PET1); 
			 }
	     }
	 }
	 else
	 {
         TEMP = TEMP + "\r\n  " + PET2->GetPetName() + " the " 
				 + PET2->GetSpecies()
				 + " gets\r\n"
				 + "  the luck of the draw with\r\n"
			     + "  the very FIRST ATTACK!\r\n";
		 MainOutput->SetWindowText(TEMP);
         XSleep(3000);
		 while(PET1->GetHealth() > 0 && PET2->GetHealth() > 0)
	     {
	         TEMP = "";
             TEMP = TEMP + " " + PET2->GetPetName() + "'s ATTACK begins!\r\n"
				     + "---------------------------------------------";
			 MainOutput->SetWindowText(TEMP);
			 XSleep(4000);
			 PET2->Attack(PET1);
          
		     if(PET1->GetHealth() > 0) 
			 {
                TEMP = "";
                TEMP = TEMP + " " + PET1->GetPetName() + " makes a counter-attack!\r\n"
				     + "---------------------------------------------";
				MainOutput->SetWindowText(TEMP);
                XSleep(4000);
				PET1->Attack(PET2);
			 }
	     }
	 }
     
	 TEMP = "";
     TEMP = TEMP + "\r\n\r\n Wait for it...";
	 MainOutput->SetWindowText(TEMP);
     XSleep(3000);
     //Declare winner
	 TEMP = "";
     if(PET1->GetHealth() > 0)
	 {    
		   TEMP = TEMP + "\r\n The " + PET1->GetSpecies() + " "
			       + PET1->GetPetName() + " wins\r\n"
				   + " the TOURNAMENT!";
		   MainOutput->SetWindowText(TEMP);
		   Pet1TEMP = "\r\n\r\n " + PET1->GetPetName()
			                + " was\r\n" + " VICTORIUS!";
           Pet1_Status->SetWindowText(Pet1TEMP);
		   PlaySound(PET1->GetPetWinSoundFile(),NULL,SND_FILENAME|SND_ASYNC);
           XSleep(8000);
           Pet2TEMP + "\r\n\r\n " + PET2->GetPetName()
			                + " was\r\n" + " DEFEATED!";
		   Pet2_Status->SetWindowText(Pet2TEMP);
		   PlaySound(PET2->GetPetLoseSoundFile(),NULL,SND_FILENAME|SND_ASYNC);
	 }
	 else
	 {
		   TEMP = TEMP + "\r\n The " + PET2->GetSpecies() + " "
			       + PET2->GetPetName() + " wins\r\n"
				   + " the TOURNAMENT!";
		   MainOutput->SetWindowText(TEMP);
		   Pet2TEMP = "\r\n\r\n " + PET2->GetPetName()
			                + " was\r\n" + " VICTORIUS!";
           Pet2_Status->SetWindowText(Pet2TEMP);
		   PlaySound(PET2->GetPetWinSoundFile(),NULL,SND_FILENAME|SND_ASYNC);
           XSleep(8000);
           Pet1TEMP + "\r\n\r\n " + PET1->GetPetName()
			                + " was\r\n" + " DEFEATED!";
		   Pet1_Status->SetWindowText(Pet1TEMP);
		   PlaySound(PET1->GetPetLoseSoundFile(),NULL,SND_FILENAME|SND_ASYNC);
	 }
    
}

//---------------------------------------------------------------------------------------------------------------------------

















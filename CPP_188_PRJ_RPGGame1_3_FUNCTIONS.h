//PRJ - RPGGame1 - Functions - 2006 - C. S. Germany
//Hills of Darkness (HOD) C. S. Germany, March 16, 2007
//File 3 of 4

//Functions

//---------------------------------------------------------------------------------------------------------------------------

void SwitchBoard()
{   
     switch(location)
     {
         case INTRO : INTRODUCTION(); break;
         case C1 : CENTER1(); break;
         case N1 : NORTH1(); break;
         case S1 : SOUTH1(); break;
         case E1 : EAST1(); break;
         case W1 : WEST1(); break;
         case GATE : GATES(); break;
         case SHAMANS_HUT : Shamans_Hut(); break;
         case N2 : NORTH2(); break;
         case S2 : SOUTH2(); break;
         case E2 : EAST2(); break;
         case W2 : WEST2(); break; 
         case UNDERGRND : UnderGroundPassage(); break;        
         case QUIT : break;
         default : cout << "Invalid value in switchboard."; break;        
     }
}

//---------------------------------------------------------------------------------------------------------------------------

void InitializeGlobals()
{
     FoundHealingPotion = false;
     S1DragonAlive = true;
     E1DragonAlive = true;
     CENTERFirstTime = true;
     W1GiantAlive = true; 
     FirstTimeInShamanHut = true;
     FoundHP_Shaman = false;
     UNDERDragonPairAlive = true;
     S2MotleyCrewAlive = true; 
     FoundHP_West2 = false;   
}

//---------------------------------------------------------------------------------------------------------------------------

void INTRODUCTION()
{
     InitializeGlobals();
     
     system("CLS"); 
     string OUTPUT;

     OUTPUT = OUTPUT + "\a\n\n\t\t\t   Hills of Darkness 3.0\n\n\n"
     + "\tYou awake from what appears to be a disturbing dream, knowing\n"
     + "\tneither where you've been nor how you got where you are now.\n"
     + "\tYou slowly rise to your feet, bewildered and almost oblivious\n"
     + "\tto the throbbing ache pulsating between your ringing ears.\n\n"
     + "\tYou find  yourself standing on a flowing grassy knoll amidst\n"
     + "\tthe dark green hills of medieval Scotland. In the skies above,\n"
     + "\tdark gray clouds are passing in billowing random patterns. It\n"
     + "\tappears a storm is approaching from the east. A few black ravens\n"
     + "\tfly over your head towards some unknown destination, a familiar\n"
     + "\tcaw, their cries echoing softly against the creeping shadows."
     + "\n\n\n\n\n\n\t";
          
     cout << OUTPUT;
     
     system("PAUSE");
     
     location = C1;  
}

//---------------------------------------------------------------------------------------------------------------------------

void CENTER1()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();     

     if(CENTERFirstTime)
     {    
         cout << "\n\t" << The_Player->GetNAME() 
              << ", confused, you try to get your bearings.\n\n"
              << "\tYou see nothing but large stone tablets and columns with\n"
              << "\twhat appear to be odd and archaic symbols engraved upon them.\n\n";         
     }  
     
     else
     {   
         cout << "\n\tYou return to the location where you first mysteriously appeared\n"
              << "\tin this strange medieval world. You notice that the large stone\n"
              << "\ttablets and columns have arranged themselves into arch and hinged\n"
              << "\tgates. The symbols are constantly changing, disappearing and re-\n"
              << "\tappearing at random intervals across the surface of the tablets.\n\n";
     }
     
     cout << "\tYou see that you can move to the north, south, east or west.\n"
          << "\tTo the north, you see the ruins of an ancient castle spread\n"
          << "\tout across the horizon. To the east, you see the lapping waves\n"
          << "\tof the ocean against a sandy shore. To the south, you see a\n"
          << "\tsmall village with gray cobblestone houses and smoldering\n"
          << "\tchimneys. To the west, you see an abandoned farm house.\n";     
     
     while(choice[0] != 'n' && 
           choice[0] != 's' && 
           choice[0] != 'e' && 
           choice[0] != 'w' &&
           choice[0] != 'l' &&
           location != QUIT)
     {
         cout << "\n\n\tWhere will you go (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
              if(!CENTERFirstTime) { cout << "(T)ry the gates   "; } 
                    
         cin >> choice; 
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
             case 'n' : location = N1; break;
             case 's' : location = S1; break;
             case 'e' : location = E1; break;
             case 'w' : location = W1; break;
             case 'o' : OPTIONS(); break;
             case 'l' : location = C1; break;
             case 't' : if(!CENTERFirstTime)
                        {  
                            location = GATE;
                            choice[0] = 'n';
                        }
                        else 
                        { cout << "\n\n\tThis way is currently COMPLETELY impassible!"; }
                        break;
             default : cout << "\n\tInvalid input"; break;
         }          
     }
     
     CENTERFirstTime = false;                         
}

//---------------------------------------------------------------------------------------------------------------------------

void GATES()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();  
         
     if(The_Player->GetFishKey())
     {
        cout << "\n\tFumbling around the gate, you find a slot to insert the\n"
             << "\tFish key. The tablets and columns begin to rumble and shake.\n"
             << "\tLarge stones rise, levitating off the ground, rearranging\n"
             << "\themselves to and fro in a pattern of sacred geometry.";
     }
     else
     {
        cout << "\n\n\tYou look around, trying every nook and crevice, but can not\n"
             << "\tseem to find the means to open the gate, nor alter anything\n"
             << "\telse around it. You see what appears to be a key hole to one\n"
             << "\tside of the ruins. If only you had a key...\n";
             
        location = C1;       
     }
    
     if(The_Player->GetFishKey() && The_Player->GetScore() < 300)
     {
        cout << "\n\n\tIt appears that, although you have the key, you lack enough\n"
             << "\texperience with the ways of this world to cause the gate to"
             << "\n\tfunction in any useful manner.\n\n\n";
             
        location = C1;
    }
    
    if(The_Player->GetFishKey() && The_Player->GetScore() >= 300)
    {
        cout << "\n\n\tWith the experience you have gained since entering this\n"
             << "\tstrange world, you manage to figure out the correct sequence of\n"
             << "\tactions to perform while turning the Fish key within the gate.\n"
             << "\tYou hear a loud hiss followed by a dull hum as cascading beams of\n"
             << "\tlight blind you from the opening dimensional portal.\n\n";
             
        cout << "\tYou feel as though you have won a series of battles in a\n"
             << "\tlong campaign, but that the war is far from being over.\n\n"
             << "\tHaving made several new friends and vanquished many foes as\n"
             << "\ta soujourner in a strange land, you step through the gates,\n"
             << "\tuncertain yet hopeful that this may bring you one step closer\n"
             << "\tto home...";
        
        cout << "\n\t"; 
        system("PAUSE");  
        cout << "\n\tYou win this campaign and end the game with:\n";     
        The_Player->DisplayStats(); 
        The_Player->DisplayInventory();
        cout << "\n\tCombat Experience Score: " 
             << The_Player->GetScore() << ".\n\n\n";
        location = QUIT;                                  
    }
    
    cout << "\n\t"; 
    system("PAUSE");
      
}

//---------------------------------------------------------------------------------------------------------------------------

void NORTH1()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();
     
     cout << "\n\tYou find yourself amidst the ruins of an ancient castle...\n\n";
     
     cout << "\tFurther to the north, you see the delapidated entrance to the\n"
          << "\tabandoned castle. It is adjoined by crumbling towers, one at\n"
          << "\teach corner of the foundation. The entrance to the castle is a\n"
          << "\tfrail wooden door, looking as though it had been abandoned for\n"
          << "\tover a hundred years. It probably would not be too difficult to\n"
          << "\tforce the door open...\n\n"
          << "\tAt this point, you may explore the castle ruins, or go back to\n"
          << "\tthe SOUTH. You are surrounded by impassible castle walls to\n"
          << "\tthe east and the west.\n";          
     
     while(choice[0] != 's' && 
           choice[0] != 'n' &&
           choice[0] != 'l' && 
           location != QUIT)
     {            
         cout << "\n\n\tWhere will you go (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : location = N2; break;
            case 's' : location = C1; break;
            case 'e' : cout << "\n\tYou fail to scale the east wall.\n";
                       break;
            case 'w' : cout << "\n\tYou press against cold, hard stone.\n";
                          if(!The_Player->GetChainMail())
                          {
                             cout << "\n\tYou find a suit of chain mail!\n";
                             The_Player->SetChainMail(true);
                             The_Player->DisplayInventory();                              
                          }
                          else 
                          { cout << "\n\tPreviously, you found the chain mail "
                                 << "at this location.\n"; 
                          } 
                          break;

            case 'o' : OPTIONS(); break;
            case 'l' : location = N1; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }      
}

//---------------------------------------------------------------------------------------------------------------------------

void SOUTH1()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\tYou stumble into the gates of a rustic village. You see what\n"
          << "\tappears to be a tavern to the north. Further south, you see a winding\n"
          << "\tdirt road that meanders towards the horizon. All around you are\n"
          << "\tpeasants buying and selling wares in an open market place. Near\n"
          << "\tthe center of the village several children are playing, and in the\n"
          << "\tmidst of them sits an elderly woman, looking very wise and thoughtful.\n\n";
  
     cout << "\tAt this point, you may only go back to the NORTH or further SOUTH.\n"
          << "\tif you so desire. You are surrounded by what seems impassible\n"
          << "\tterrain to the east and the west and several cottages. Towards the\n"
          << "\tcenter of the villiage, you notice a small though nicely maintained\n"
          << "\tShaman's lodge with smoke billowing from its roof.";
     
     while(choice[0] != 's' && 
           choice[0] != 'n' &&
           choice[0] != 'g' &&
           choice[0] != 'l' && 
           location != QUIT)
     {     
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?\n"
              << "\n\tOther choices: (O)ptions   (G)o into Shaman's Hut   "
              << "\n\t               (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 
         
         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : location = C1; break;
            case 's' : location = S2; break;
            case 'e' : cout << "\n\tYou see a window."; break;
            case 'w' : if(FoundHealingPotion == false)
                       { 
                          cout << "\n\tYou find a healing potion!";
                          The_Player->SetHealingPotion(The_Player->GetHealingPotion() + 1);
                          FoundHealingPotion = true;
                       }
                       else
                       {
                          cout << "\n\tYou see a wall. (previously you found hp here...)"; 
                       } 
                       break;
            case 'g' : location = SHAMANS_HUT; break;             
            case 'o' : OPTIONS(); break;
            case 'l' : location = S1; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }       
}

//---------------------------------------------------------------------------------------------------------------------------

void EAST1()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\n\tYou arrive at a sandy shore where green-blue translucent.\n"
          << "\twaves are crashing against rocky outcroppings. To the north,\n";
       
     if(E1DragonAlive)
     {     
        cout << "\ta magnificent red dragon folds its wings, smoke billowing\n"
             << "\tfrom its nostrils.";
     }
     else
     { cout << "\ta slain dragon is being devoured by ravens..."; }       
       
     cout << "\n\n\n\tAt this point, you may back to the WEST or\n"
          << "\tproceed EAST. You are surrounded by turbulent water\n"
          << "\tand razor sharp rocks to the east and the south.\n\n";

     
     while(choice[0] != 'w' &&
           choice[0] != 'e' &&
           choice[0] != 'l' &&
           location != QUIT)
     {
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                         
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : if(E1DragonAlive)
                       {
                           cout << "\n\tA dragon attacks!.";
                           A_Dragon = new Dragon();
                           A_Dragon->SetNAME("Deloria");
                           COMBAT(The_Player, A_Dragon); 
                           delete A_Dragon;
                           A_Dragon = 0;
                           if(The_Player->GetHP() > 0)
                           { 
                               if(The_Player->GetENTITY_CLASS() == MAGE ||
                                  The_Player->GetENTITY_CLASS() == SHAMAN ||
                                  The_Player->GetENTITY_CLASS() == ELF)
                               {
                                  cout << "\n\n\tYou absorb 30 points of magic energy. Beneath"
                                       << "\n\tthe giant you find a scroll! It teaches you a"
                                       << "\n\tmagic spell for creating Lightning.";
                                  The_Player->SetLightning(true);
                                  The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() + 30);
                                  The_Player->DisplayMagic();
                               }

                               E1DragonAlive = false;
                               The_Player->SetScore(The_Player->GetScore() + 100);
                           }
                           
                       }
                       else
                       {
                           cout << "\n\tYou see a dead dragon carcass.";     
                       }
                       break;
            case 's' : cout << "\n\tYou step on a jellyfish and it stings you with"
                               << " its tentacles!\n";
                          if(The_Player->GetHP() > 1)
                          { 
                             The_Player->SetHP((The_Player->GetHP() - 1));
                          }
                          else 
                          {     
                             The_Player->SetHP(0);
                             cout << "\tHow pathetic! Slain by a jellyfish!";
                             location = QUIT;
                             cout << "\n\n\t"; 
                             system("PAUSE");
                          }    
                          break;
            case 'e' : location = E2; break;
            case 'w' : location = C1; break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = E1; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }      
}

//---------------------------------------------------------------------------------------------------------------------------

void WEST1()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\tYou arrive at an abandoned farm house. You see a picket fence,\n"
          << "\ta rustic delapidated barn, and a decaying hovel that used to be \n"
          << "\tsomeone's residence. There are chickens walking around the.\n"
          << "\tpremesis. To the south, you see ";
         
     if(W1GiantAlive)
     {     
         cout << "a Giant wearing old, brown\n"
              << "\tsackcloth. He is taunting you with offensive "
              << "gestures and lewd \n\tcomments. You really don't want to "
              << "tangle with a giant, do you?";
     }
     else
     { cout << "barbed wire, blood, sackcloth\n\tand carnage..."; }
         
     cout << "\n\n";                   
     cout << "\tAt this point, you may go NORTH or back EAST.\n"
          << "\tYou see only thick undergrowth and brush\n"
          << "\tto the west. To the south is that brutish giant.\n"
          << "\twith a foul mouth and a nasty disposition.\n";

              
     while(choice[0] != 'e' &&
           choice[0] != 'w' &&
           choice[0] != 'l' && 
           location != QUIT)
     {
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : cout << "\n\tYou are attacked by a flock of vicious chickens!"
                            << "\n\tThey will not let you proceed further north.\n";
                           if(!The_Player->GetDagger())
                           {
                              cout << "\tBut lieing on the ground, you find a bronze dagger!\n";
                              The_Player->SetDagger(true);
                              The_Player->DisplayInventory();
                           }
                           else 
                           { cout << "\n\tPreviously, you found a dagger here.\n"; } 
                           break;
            case 's' : if(W1GiantAlive)
                       {
                           cout << "\n\tThe giant sees you walking in his direction and charges!.";
                           A_Giant = new Giant();
                           A_Giant->SetNAME("Grothem");
                           COMBAT(The_Player, A_Giant); 
                           delete A_Giant;
                           A_Giant = 0;
                           
                           if(The_Player->GetHP() > 0)
                           { 
                               cout << "\n\n\tYou defeated the giant! 100 was "
                                    << "added to your score!";
                               
                               if(The_Player->GetENTITY_CLASS() == MAGE ||
                                  The_Player->GetENTITY_CLASS() == SHAMAN ||
                                  The_Player->GetENTITY_CLASS() == ELF)
                               {
                                  cout << "\n\tYou absorb 30 points of magic energy. Beneath"
                                       << "\n\tthe giant you find a scroll! It teaches you a"
                                       << "\n\tmagic spell for creating Fireballs.";
                                  The_Player->SetFire(true);
                                  The_Player->SetMagicEnergy(The_Player->GetMagicEnergy() + 30);
                                  The_Player->DisplayMagic();
                               }
                               
                               W1GiantAlive = false;
                               The_Player->SetScore(The_Player->GetScore() + 100);
                           }
                           
                       }
                       else
                       {
                           cout << "\n\tYou see the corpse of the giant you recently dispatched.";     
                       }
                       break;
            case 'e' : location = C1; break;
            case 'w' : location = W2; break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = W1; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }      
}

//---------------------------------------------------------------------------------------------------------------------------
             
void NORTH2()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\tYou walk inside the castle. It is dark and musty, but\n";
     cout << "\tenough daylight is leaking through the cracks in between\n"
          << "\tstones and mortar that you can ascertain your surroundings\n"
          << "\tin a dim, colorless twilight. Against the wall to the east\n"
          << "\tyou see a long wooden box, about the size of a coffin. You\n"
          << "\tcan see a table, chairs and several candle stands to the west\n"
          << "\tof the room. To the north and the south the walls are adorned\n"
          << "\twith dusty, thread-bare tapestries. You notice stairs descending\n"
          << "\tdeep underground to some unknown passage to your right. ";
              
     while(choice[0] != 's' &&
           choice[0] != 'u' &
           choice[0] != 'l' &
           location != QUIT)
     {
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (U)nderground   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : cout << "\n\tHanging on the wall are beautiful tapestries,"
                            << "\n\twoven of fine silk and canvas. They appear "
                            << "\n\tto be elven artistry, though dry and dusty.\n"; 
                       break;
            case 's' : location = N1; break;
            case 'e' : cout << "\n\tYou approach the box and cautiously open it...\n"; 
                          if(!The_Player->GetPlateArmor())
                          {
                             cout << "\tYou find a well preserved suit of full body armor!\n";
                             The_Player->SetPlateArmor(true);
                             The_Player->DisplayInventory();                              
                          }
                          else { cout << "\n\tThe box is empty - you already took the armor.\n"; } 
                       break;
            case 'w' : cout << "\n\tYou press against the cold stone wall and grope"
                            << "\n\tits cracks and crevices, but find nothing of"
                            << "\n\tany interest or value.";
                       break;
            case 'u' : location = UNDERGRND; break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = N2; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }      
}

//---------------------------------------------------------------------------------------------------------------------------

void SOUTH2()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\tYou wander through the village further to the south.\n";
     cout << "\tYou notice several of the villagers are staring at you\n"
          << "\tstrangely as you walk by. You come to the southern gate\n"
          << "\tthat guards the entrance to the village and pass through its\n"
          << "\topen doors. You follow a meandering dirt path towards the\n"
          << "\tedge of a dense hardwood forest. As you walk along the road,\n"
          << "\tyou pass several merchants hauling their wares by horse and\n"
          << "\tcart. Continuing south, you see a group of three giants \n"
          << "\tresting with their backs against the trees.\n\n";
              
     while(choice[0] != 'n' &&
           choice[0] != 'l' && 
           location != QUIT)
     {
         cout << "\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : location = S1; break;
            case 's' : if(S2MotleyCrewAlive)
                          {  cout << "\n\tYou're either really brave or really stupid.";
                             cout << "\n\tAre you sure you want to fight 3 giants,"
                                  << "\n\t and all at the same time?   ";
                            
                             cin >> choice;
                            
                             if(tolower(choice[0]) == 'y')
                             {
                                 Giant * MotleyCrew = new Giant[3];
                                 cout << "\n\tAll three giants charge you at once!\n";
                                 for(int x = 0; x < 3; x++)
                                 {
                                    COMBAT(The_Player, &MotleyCrew[x]);     
                                 }
                                 //Clean up after MotleyCrew - no dangling pointers
                                 delete [] MotleyCrew; MotleyCrew = 0;
                                 S2MotleyCrewAlive = false;
                              }  
                               
                             else 
                             { cout << "\n\tIntelligently, you decide to walk away...\n"; }   
                       }
                       else { cout << "\tYou see three dead giants.\n"; }
                       break;
            case 'e' : cout << "\n\tYou see a lake, covered with lily pads and algae."
                            << "\n\tThe water glistens and ripples along the shore.\n";
                       break;
            case 'w' : cout << "\n\tYou see cat tails and dragon flies skimming across"
                            << " the water.\n";
                       break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = S2; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }      
}

//---------------------------------------------------------------------------------------------------------------------------

void EAST2()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\n\tYou swim out to the sand bars hundreds of feet beyond the shore.\n"
          << "\tIn every direction, you see dolphins and sharks swimming around you.\n\n";
              
     while(choice[0] != 'w' && 
           choice[0] != 'l' && 
           location != QUIT)
     {
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : cout << "\n\tYou see dolphins and sharks.\n";
                       break;
            case 's' : cout << "\n\tYou swim out amidst a pod of dolphins.\n";
                       if(!The_Player->GetFishKey())
                       {
                          cout << "\n\tYou notice something metalic shining in the sand\n"
                               << "\tbeneath your feet. You dig into the sand and find\n"
                               << "\ta bronze key with a Fish engraved upon it.";
                          The_Player->SetFishKey(true);       
                       }
                       else
                       { cout << "\n\tHey, this is the same place you found that Fish key!"; }
                       break;
            case 'e' : cout << "\n\tYou see beds of seaweed in blue and green patches.\n"; 
                       break;
            case 'w' : location = E1; break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = E2; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }           
}

//---------------------------------------------------------------------------------------------------------------------------

void WEST2()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();

     cout << "\n\n\tYou find yourself walking in golden fields of wheat.\n\n";
              
     while(choice[0] != 'e' &&
           choice[0] != 'l' &&
           location != QUIT)
     {
         cout << "\n\n\tPossible directions for you are: (N, S, E, W)?  "
              << "\n\tOther choices: (O)ptions   (L)ook around   ";
                          
         cin >> choice;
         choice[0] = tolower(choice[0]); 

         system("CLS");
         The_Player->DisplayStats();
         
         switch(choice[0])
         {
            case 'n' : if(!The_Player->GetLongBow())
                       {
                           cout << "\n\tYou find a well-strung long bow and arrows!\n";
                           The_Player->SetLongBow(true);
                           The_Player->DisplayInventory();                              
                       }
                       else { cout << "\n\tYou already found the long bow.\n"; }
                       break;
            case 's' : cout << "\n\tYou see... golden fields of WHEAT!\n"; 
                       if(!FoundHP_West2)
                       {
                           cout << "\tBuried under a mound among the wheat,\n"
                                << "\tyou find a healing potion!\n";
                           The_Player->SetHealingPotion(The_Player->GetHealingPotion()+1);
                           FoundHP_West2 = true;
                           The_Player->DisplayInventory();
                       }
                       else { cout << "\tYou already found the healing potion!\n"; }
                       break;
            case 'e' : location = W1; break;
            case 'w' : cout << "\n\tYou see staple crops planted in distinct rows."
                            << "\n\tCabbages, carrots, string beans and radishes.\n";
                       break;
            case 'o' : OPTIONS(); break;
            case 'l' : location = W2; break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     }            
}

//---------------------------------------------------------------------------------------------------------------------------

void Shamans_Hut()
{
     system("CLS");
     string choice = "";
     The_Player->DisplayStats();      
     
     if(FirstTimeInShamanHut)
     { 
         Wise_Woman = new Shaman;
         
         cout << "\n\n\tYou duck down and enter into the Shaman's hut. Towards the center\n"
              << "\tof the mud dwelling, beneath an overhanging shelf descending from the\n"
              << "\tthatched roof, sits an elderly priestess. Unphased by your presence,\n"
              << "\tshe continues to stare into the flames of a small fire burning within\n"
              << "\ta set of blackened stone rings in the center of the hut. Directly over\n"
              << "\ther head, an opening in the ceiling allows the smoke to escape. She\n" 
              << "\tgazes at you and cackles. \"Not expecting an old temple preistess, \n"
              << "\twere you? Well, in this village, I'm the \"Shaman\".\n\n";
           
         FirstTimeInShamanHut = false;
     }
     else
     { 
         cout << "\n\n\n\tYou re-enter the Shaman's hut. She turns her head in a peculiar\n"
              << "\tfashion and remarks, \"Back so soon, traveler?\" She offers you a cup\n"
              << "\tof freshly brewed tea, which you gladly accept to quench your thirst.\n\n";
           
         if(!FoundHP_Shaman)
         {
             cout << "\tShe opens her medicine bag and begins creating an acrid mixture of\n"
                  << "\therbs. She pours it into a vial and places it in your hand, saying\n"
                  << "\t\"Drink this if you become wounded, my friend. It may restore\n"
                  << "\tyou to a measure of your former health and constitution.\"\n\n\n\n\n";
                  
             The_Player->SetHealingPotion(The_Player->GetHealingPotion() + 1);
             FoundHP_Shaman = true;
             cout << "\t\t\t"; 
             system("PAUSE"); 
             The_Player->DisplayInventory();
             cout << "\t\t\t"; 
             system("PAUSE"); 
             system("CLS"); 
             cout << "\n\n";
         }
         else 
         { 
              cout << "\tYou feel a sense of debt and gratitiude towards this\n" 
                   << "\tkind old woman, remembering the healing elixir she gave\n"
                   << "\tyou on your last visit.\n\n";
         }     
     }         
  
     cout << "\tAt this point, you may (l)eave the Shaman's hut,\n"
          << "\t(t)alk with her if you so desire, or try to (s)teal\n"
          << "\ther medicine bag and staff for what wonders they may\n"
          << "\tcontain.\n\n";
          
     while(choice[0] != 'l' && 
           choice[0] != 's' && 
           choice[0] != 'o')
     {                
             cout << "\n\n\tYou choices: (L)eave  (T)alk  or (S)teal\n"
                  << "\tOther: (o)ptions  ";
                  
             cin >> choice;
             
             choice[0] = tolower(choice[0]);
             
             switch(choice[0])
             {
               case 'n' : cout << "\tYou run into a straw and mud wall. Yippee!\n"; break;
               case 'o' : OPTIONS(); break;
               case 'l' : location = S1; break;
               case 's' : system("CLS");
                          The_Player->DisplayStats();
                          cout << "\n\n\n\n\tYou get the uneasy feeling that you are going\n"
                               << "\tto reap serious bad karma for this unwise action.\n\n"; 
                          Sleep(3000); 
                          cout << "\tBellowing thunder cracks and the clouds darken as the deity\n"
                               << "\tof the temple preistess fills with indignation and anger!\n\n";
                          Sleep(3000);          
                          cout << "\tIn an instant, lighting from the heavens strikes you\n"
                               << "\tdown!\n\n";
                          Sleep(3000);     
                          cout << "\tYou go into the afterlife a loser, ashamed\n"
                               << "\tfor the despicable deeds you have done. The warriors\n"
                               << "\twho have gone on before you, the great warriors of\n"
                               << "\treknown and the kings of the past will ridicule you\n"
                               << "\tfor all of eternity for dieing without honor.\n\n";
                               Sleep(5000); cout << "\n\n\n\t\t\t"; system("PAUSE");
                          The_Player->SetHP(0); 
                          The_Player->DisplayStats();
                          location = QUIT; 
                          choice[0] = 'o';
                          break;
               case 't' : cout << "\tYou seek audience with the preistess.\n"; 
                          Wise_Woman->Talk(); break;
               case 'i' : The_Player->DisplayInventory(); break;
               case 'd' : The_Player->DisplayStats(); break;                            
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }                    
}
             
//---------------------------------------------------------------------------------------------------------------------------

void UnderGroundPassage() 
{  
     system("CLS");
     string choice = "";
     The_Player->DisplayStats(); 
     
     char nutz[10]; nutz[0] = 'z';
    
     cout << "\n\n\n\n\n\n\tYou descend into the darkness underground...\n";
    
     if(UNDERDragonPairAlive)
     {
        cout << "\tPeeking around a corner, you see a family of red dragons\n";
        cout << "\tbreathing fire! Think about whether you want to fight or flee.\n";
        cout << "\tAre you sure you want to fight 5 dragons at the same time? (y,n)   ";
        cin >> nutz;
      
        if(tolower(nutz[0]) == 'y')
        {
           Dragon * DragonFamily = new Dragon[5];
           for(int x = 0; x < 5; x++)
           {
               COMBAT(The_Player, &DragonFamily[x]);     
           }
           //Clean up DragonFamily objects on heap, set pointer to NULL
           delete [] DragonFamily; 
           DragonFamily = 0;
           UNDERDragonPairAlive = false;
        }   
        else 
        { 
          cout << "\tIntelligently, you decide to run back up the stairs...\n";
          location = N2;  
        }   
    }
    else { 
             cout << "\tYou see a family of dead red dragons and the carnal aftermath.\n"
                  << "\tof your last great battle with these fierce and worthy opponents.\n";
             location = N2; 
         }
    cout << "\n\n\n\t"; 
    system("PAUSE"); 
}

//---------------------------------------------------------------------------------------------------------------------------

void OPTIONS()
{
     system("CLS");
     string choice = "";
     
     while(choice[0] != 'x')
     {

         cout << "\n\n\n\t----- Options -----";
         cout << "\n\t(I)nventory List";
         cout << "\n\t(U)se An Inventory Item";
         cout << "\n\t(M)agic Abilities";
         cout << "\n\t(P)otions";
         cout << "\n\t(D)isplaystats";
         cout << "\n\t(L)oad Character";
         cout << "\n\t(S)ave Character";
         cout << "\n\t(H)igh Scores";        
         cout << "\n\t(Q)uit game";
         cout << "\n\tE(x)it menu\n\n\t";  
                   
         cin >> choice;
         choice[0] = tolower(choice[0]); 
         system("CLS");
         switch(choice[0])
         {

            case 'i' : The_Player->DisplayInventory(); break;
            case 'u' : The_Player->UseItem(); break;
            case 'm' : if(The_Player->GetENTITY_CLASS() == MAGE ||
                          The_Player->GetENTITY_CLASS() == SHAMAN ||
                          The_Player->GetENTITY_CLASS() == ELF)
                       {  The_Player->UseMagic(); }
                       else { cout << "\n\tYour character doesn't do magic!\n"; }
                       break;
            case 'p' : The_Player->UsePotions(); break;           
            case 'd' : The_Player->DisplayStats(); break;
            case 'l' : if(LoadCharacter())
                       {  
                          cout << "\n\tNew Character: "
                               << The_Player->GetNAME()
                               << "\n"; 
                          The_Player->DisplayStats();
                          The_Player->DisplayInventory();
                          cout << "\n\n";
                          system("PAUSE");
                          SwitchBoard();
                       }
                       else 
                       { cout << "\n\tSorry, could not load character.\n"; } 
                       break;
            case 's' : SaveCharacter(); break;
            case 'h' : DisplayHighScores(); break;
            case 'q' : location = QUIT; choice[0] = 'x'; break;
            case 'x' : break;
            case '~' : The_Player->cheat(); //secret cheat 
                       break;
            default : cout << "\n\tInvalid input"; break;     
         }          
     } 
     
     The_Player->DisplayStats();     
}

//---------------------------------------------------------------------------------------------------------------------------

void COMBAT(ENTITY * x, ENTITY * y)
{
              string OUTPUT = "\n\n\tENTITY attacks ENTITY!\n";
              cout << OUTPUT;

              The_Player->ChooseWeapon();

              //Randomize who attacks first
              int FirstAttack = (rand()%2) + 1;

              if(FirstAttack == 1)
              {
                  while(x->GetHP() > 0 && y->GetHP() > 0)
                  { 
                       if(x->GetHP() > 0) { x->Attack(y); }
                       Sleep(CombatPause);
                       if(y->GetHP() > 0) {y->Attack(x); }
                       Sleep(CombatPause);
                  }
              }

              if(FirstAttack == 2)
              {
                  while(x->GetHP() > 0 && y->GetHP() > 0)
                  { 
                       if(y->GetHP() > 0) {y->Attack(x); }
                       Sleep(CombatPause);
                       if(x->GetHP() > 0) { x->Attack(y); }
                       Sleep(CombatPause);
                  }
              }
        
              if(x->GetHP() > 0)
              { OUTPUT = OUTPUT + "\n\tThe player wins this match!\n"; }
              else
              { 
                 OUTPUT = OUTPUT + "\n\tSorry, you were killed.\n";
                 location = QUIT; //end game
              }

              cout << OUTPUT;
     
}

//---------------------------------------------------------------------------------------------------------------------------

void SaveCharacter() 
{                     
     char CharacterName[80];
     string passwd;
     cout << "\n\tEnter the file name to save as: ";
     cin >> CharacterName; 
     strcat(CharacterName, ".gam");
     cout << "\n\tEnter a password:   ";
     cin >> passwd;
     
     ofstream WriteStuff;
     WriteStuff.open(CharacterName);

     if(!WriteStuff) 
     { 
         cout << "\tError. Unable to create " << CharacterName << " for writing.\n";
     }  //close if

     else 
     {
         //Simple serialization of Character class 
         WriteStuff << passwd << "\n";                        
         WriteStuff << The_Player->GetNAME() << "\n";
         WriteStuff << The_Player->GetHP() << "\n";
         WriteStuff << The_Player->GetATK() << "\n"; 
         WriteStuff << The_Player->GetDEF() << "\n";                        
         WriteStuff << The_Player->GetEXP() << "\n";
         WriteStuff << The_Player->GetScore() << "\n";
         WriteStuff << The_Player->GetGender() << "\n";
         WriteStuff << The_Player->GetENTITY_CLASS() << "\n";
         WriteStuff << The_Player->GetMagicEnergy() << "\n";
         WriteStuff << The_Player->GetWeaponChoice() << "\n";
         WriteStuff << The_Player->GetMagicChoice() << "\n";
         WriteStuff << The_Player->GetArmorChoice() << "\n";
         WriteStuff << location << "\n";   
               
         WriteStuff << The_Player->GetDagger() << "\n";
         WriteStuff << The_Player->GetStaff() << "\n";
         WriteStuff << The_Player->GetLongBow() << "\n";          
         WriteStuff << The_Player->GetCrossBow() << "\n";          
         WriteStuff << The_Player->GetBroadSword() << "\n";
         
         WriteStuff << The_Player->GetChainMail() << "\n";               
         WriteStuff << The_Player->GetPlateArmor() << "\n";
         WriteStuff << The_Player->GetHealingPotion() << "\n";
         WriteStuff << The_Player->GetFishKey() << "\n";
         WriteStuff << The_Player->GetArrows() << "\n";
      
         WriteStuff << The_Player->GetFire() << "\n";
         WriteStuff << The_Player->GetIce() << "\n";
         WriteStuff << The_Player->GetLightning() << "\n";
         WriteStuff << The_Player->GetTelekineticForce() << "\n";
         WriteStuff << The_Player->GetInvisibility() << "\n";
         WriteStuff << The_Player->GetHealing() << "\n";
          
         WriteStuff << CENTERFirstTime << "\n";
         WriteStuff << FoundHealingPotion << "\n";
         WriteStuff << S1DragonAlive << "\n";
         WriteStuff << E1DragonAlive << "\n";
         WriteStuff << W1GiantAlive << "\n";
         WriteStuff << FirstTimeInShamanHut << "\n";
         WriteStuff << FoundHP_Shaman << "\n";
         WriteStuff << UNDERDragonPairAlive << "\n";
         WriteStuff << S2MotleyCrewAlive << "\n";
         WriteStuff << FoundHP_West2 << "\n";
           
         //Note: You could flush the buffer to write to the file and keep it open
         //using  WriteStuff << flush  , but we don't need to keep it open so:       
         WriteStuff.close();
     }
} 

//---------------------------------------------------------------------------------------------------------------------------

bool LoadCharacter() 
{
     bool successful;
     string nm, passwd, pass, Gender;
     int hp, atk, def, exp, scr, loc, arw, EntityClass, MagicEnergy, 
         WeaponChoice, MagicChoice, ArmorChoice;
     int dagger, stf, lbow, cbow, bsword, mail, armor, healing, key;
     int fre, ic, ltn, tks, inv, hel; 
     
     //Note: bool data type reads in VS 6.0 and .Net, but for BloodShed you 
     //must read all boolean values as integers 
     from the file   
     int center_first_time, found_healing_potion, s1_dragonalive, 
         e1_dragon_alive, w1_giant_alive, first_time_shaman_hut, 
         found_hp_shaman, undergrnd_dragon_alive, s2_motley_crew_alive,
         found_hp_west2;
           
     char CharacterName[80];
     cout << "\n\tPlease enter the name of character to load: ";
     cin >> CharacterName; strcat(CharacterName, ".gam");
	          
     ifstream ReadStuff;
     ReadStuff.open(CharacterName);

     //Need to detect if successful or not to keep program from crashing on failed load              
     if (!ReadStuff) 
     {
          cout << "\tUnable to find \"" << CharacterName << "\" for reading.\n";
          successful = false;
     }
     else
     {   
        cout << "\n\tEnter the password:   ";
        cin >> pass;
 
        getline(ReadStuff, passwd);
                
        if(pass == passwd)
        { 
           //Careful! serialization = you must read in exactly the same order as you wrote!
	       //Have to use getline for nm since name may have spaces in it
	       
	       //Character Attributes
	       getline(ReadStuff, nm);
           ReadStuff >> hp;
           ReadStuff >> atk; 
           ReadStuff >> def;                        
           ReadStuff >> exp;
           ReadStuff >> scr;
           ReadStuff >> Gender;
           ReadStuff >> EntityClass;
           ReadStuff >> MagicEnergy;
           ReadStuff >> WeaponChoice;
           ReadStuff >> MagicChoice;
           ReadStuff >> ArmorChoice;              
           ReadStuff >> loc;
                      
           //Inventory Items 
           ReadStuff >> dagger;
           ReadStuff >> stf;           
           ReadStuff >> lbow;           
           ReadStuff >> cbow;           
           ReadStuff >> bsword;         
           ReadStuff >> mail;
           ReadStuff >> armor;
           ReadStuff >> healing;
           ReadStuff >> key;
           ReadStuff >> arw;
           
           ReadStuff >> fre;
           ReadStuff >> ic;
           ReadStuff >> ltn;
           ReadStuff >> tks;
           ReadStuff >> inv;
           ReadStuff >> hel;
           
           //Game Events    
           ReadStuff >> center_first_time;
           ReadStuff >> found_healing_potion; 
           ReadStuff >> s1_dragonalive; 
           ReadStuff >> e1_dragon_alive;
           ReadStuff >> w1_giant_alive;
           ReadStuff >> first_time_shaman_hut; 
           ReadStuff >> found_hp_shaman;
           ReadStuff >> undergrnd_dragon_alive;
           ReadStuff >> s2_motley_crew_alive;
           ReadStuff >> found_hp_west2;       

	   //Note: In VS 6.0 and .Net Visul Studio, you can read these as booleans
	   //with no problem. The problem is with Bloodshed - they will all read in
	   //as false. To make it compatible with Bloodshed (therefore all 3
	   //compilers) you must read them as integers and they will be cast to bools
	   //in VS 6.0 and .Net Visual Studio. (It ain't easy getting these 3 to agree).      
       
       //Create a character object according to the player's class
       //Delete current player object if there is one
       delete The_Player;
       The_Player = 0;
       
           switch(EntityClass)
           {
                case WARRIOR : The_Player = new Warrior; break;
                case MAGE : The_Player = new Mage; break;
                case FIGHTER : The_Player = new Fighter; break;
                case ELF : The_Player = new Elf; break;
                case SHAMAN : The_Player = new Shaman; break;
                default : cout << "\n\tERROR! Invalid input!\n";                        
           }        
                
           The_Player->SetNAME(nm); 
           The_Player->SetHP(hp);
           The_Player->SetATK(atk); 
           The_Player->SetDEF(def);        
           The_Player->SetEXP(exp); 
           The_Player->SetScore(scr);
           The_Player->SetGender(Gender);
           The_Player->SetENTITY_CLASS(EntityClass);
           The_Player->SetMagicEnergy(MagicEnergy);
           The_Player->SetWeaponChoice(WeaponChoice);
           The_Player->SetMagicChoice(MagicChoice);
           The_Player->SetArmorChoice(ArmorChoice);              
           location = loc; 
           
           The_Player->SetDagger(dagger);
           The_Player->SetStaff(stf);           
           The_Player->SetLongBow(lbow);            
           The_Player->SetCrossBow(cbow);
           The_Player->SetBroadSword(bsword);            
           The_Player->SetChainMail(mail); 
           The_Player->SetPlateArmor(armor);
           The_Player->SetHealingPotion(healing);
           The_Player->SetFishKey(key); 
           The_Player->SetArrows(arw);
           
           The_Player->SetFire(fre);
           The_Player->SetIce(ic);
           The_Player->SetLightning(ltn);
           The_Player->SetTelekineticForce(tks);
           The_Player->SetInvisibility(inv);
           The_Player->SetHealing(hel);         

           CENTERFirstTime = center_first_time;
           FoundHealingPotion = found_healing_potion; 
           S1DragonAlive = s1_dragonalive; 
           E1DragonAlive = e1_dragon_alive;
           W1GiantAlive = w1_giant_alive;
           FirstTimeInShamanHut = first_time_shaman_hut; 
           FoundHP_Shaman = found_hp_shaman;
           UNDERDragonPairAlive = undergrnd_dragon_alive;
           S2MotleyCrewAlive = s2_motley_crew_alive;
           FoundHP_West2 =  found_hp_west2;       
 
           ReadStuff.close();  
           successful = true;
        }
        else 
        { 
             cout << "\n\tThat was not the correct password!!!";
             successful = false; 
        }

    }
    
    return successful;
} 

//---------------------------------------------------------------------------------------------------------------------------

//Function - SaveHighScores

void SaveHighScores() 
{
     ofstream highscores;
     highscores.open("highscores.txt", ios::app);
     
     if(!highscores)
     {
        cout << "\tError. Unable to create \"highscores\" for writing.\n";                  
     }
     else
     { 
         highscores << The_Player->GetNAME() << "\n"
                    << The_Player->GetScore() << "\n";
                
         highscores.close();
     } 
}  //close function

//---------------------------------------------------------------------------------------------------------------------------

//Function - DisplayHighScores

void DisplayHighScores() 
{
     system("CLS"); 
     cout << "\n\n\n";    
     string HoldMeString; 
     int HoldMeInt, z, x = 0;
     
     ifstream highscores("highscores.txt");

     if (!highscores) 
     {
          cout << "\tUnable to find \"highscores.txt\" for reading.\n";
     }

     else
     {   //Note: When using getline() in a for loop, you must use getline() again
         //right after reading the integer in to consume the '\n' left in the
         //data stream. We don't have to have this extra getline() in the 
         //LoadCharacter() function because getline() is not in a loop there. 
         while(!highscores.eof())
         {   getline(highscores, HoldMeString);
             highscores >> HoldMeInt;
             getline(highscores, HoldMeString); 
             x++;  //add one for every 2 lines (name and score pair)      
         }
      //cout << "\t" << x; system("PAUSE"); //Use to test the value of x  
      x = x - 1;   //Subtract 1 for the offset (one too many)

     //Declare 2 Parallel Arrays where # elements = # lines.
     //We could have also used only 1 array here with a structure containing 
     //a string and an integer component as a single object. Example:
         
     //NameAndScore { string n; int s; };  //defines structure, sort of like a class
     //NameAndScore HIGHSCORE[x]; //creates array of objects defined as "NameAndScore"
     // if(HIGHSCORE[r].s > HIGHSCORE[r - 1].s)
     //   { TempHIGHSCORE = HIGHSCORE[r]; HIGHSCORE[r] = HIGHSCORE[r - 1];
     
     //Note: If compiling this with Visual Studio .Net, it will flag the array
     //declarations below as an error. It does not allow dynamically sizing them
     //at run time as BloodShed does. So just change the 2 lines below:
     //from string NAMES[x]; to string NAMES[100];
     //from int SCORES[x]; to int SCORES[100];          
         string NAMES[x];
         int SCORES[x];
         
         //Reset stream and move pointer back to beginning of file
         highscores.clear();
         highscores.seekg(0, ios::beg);    
               
         //Put each line into 
         for(z = 0; z < x; z++)
         {
	     //Remember, need to use getline in case of spaces in name
             getline(highscores, NAMES[z]);
             highscores >> SCORES[z];
             getline(highscores, HoldMeString);              
         }
     
         highscores.close();
     
         //Could also use (sizeof SCORES /sizeof *SCORES) to get array size 
 
         //Bubble Sort for High Scores. Go through each Name and Score set
         for(int q = 0; q < x; q++)
         {
            //Compare the integer component to every other, move it if >
            //For descendind order, r starts at 1 to compare it to element 0
            for(int r = 1; r < x; r++)
            {
               if(SCORES[r] > SCORES[r - 1])
               {
                   HoldMeInt = SCORES[r]; HoldMeString = NAMES[r];
                   SCORES[r] = SCORES[r - 1]; NAMES[r] = NAMES[r - 1];
                   SCORES[r - 1] = HoldMeInt; NAMES[r - 1] = HoldMeString;           
               }
            }
         } 
        
        cout.setf(ios::fixed);
        cout << "\t\t***************** High Scores *****************\n\n";
        cout << "\t\t-----------------------------------------------\n"; 

		for(z = 0; z < x; z++)
        {
            cout << setw(16)<< (z+1) << ". Name: " << left << setw(28) << NAMES[z]  
                 << setw(5) << "Score: " << right << SCORES[z] << "\n";
            cout << "\t\t-----------------------------------------------\n";    
        }

		cout << "\n\t\t***********************************************\n";
        cout << "\n\n\t\t\t"; system("PAUSE");

	 }//close else 
}

//---------------------------------------------------------------------------------------------------------------------------

void Setup_Character()
{
     string NM = "";
     string gender = "";
     
     string choice = "";
     system("CLS");
     
     cout << "\n\tDecide which type of character you wish to create."
          << "\n\tChoose carefully - each type has its own strengths"
          << "\n\tand weaknesses.\n";
     
     
     while(choice[0] != 'q' && 
           choice[0] != 'w' && 
           choice[0] != 'm' &&
           choice[0] != 'f' && 
           choice[0] != 'e' &&
           choice[0] != 's')
     {
         cout << "\n\n\tChoose your character's class:\n"
              << "\n\t(W)arrior"
              << "\n\t(M)age"
              << "\n\t(F)ighter"
              << "\n\t(E)lf"
              << "\n\t(S)haman"
              << "\n\t(H)elp Me Choose a Character"
              << "\n\t(Q)uit\n\n\t";
          
         cin >> choice;
         choice[0] = tolower(choice[0]);
     
         switch(choice[0])
         {
             case 'w' : The_Player = new Warrior; break;
             case 'm' : The_Player = new Mage; break;
             case 'f' : The_Player = new Fighter; break;
             case 'e' : The_Player = new Elf; break;
             case 's' : The_Player = new Shaman; break;
             case 'h' : RoleHelp(); break;
             case 'q' : location = QUIT; break;
             default : cout << "\n\tInvalid input!\n";    
         }
         
   }//end while loop
   
   if(choice[0] != 'q') 
   { 
     cout << "\n\n\tEnter a name for your character: ";
     cin >> NM;
     The_Player->SetNAME(NM);
          
     while(gender[0] != 'f' && gender[0] != 'm')
     {
          cout << "\n\tWhat will be your players gender? (m/f) ";
          cin >> gender;
          gender[0] = tolower(gender[0]);
         
          switch(gender[0])
          {
               case 'm' : The_Player->SetGender("Male"); break;
               case 'f' : The_Player->SetGender("Female"); break;
               default : cout << "\n\tInvalid input!\n"; break;    
          }
     }
  }
  system("CLS");

}//close function

//---------------------------------------------------------------------------------------------------------------------------

void RoleHelp()
{
     system("CLS");
     cout << "\n\n\n\tCarefully choose your character's class. As you"
          << "\n\tchoose, remember that each class has its own "
          << "\n\tstrengths and weaknesses. Remember this:\n\n";
     PAUSE();
     system("CLS");     
     cout << "\n\n\n\t(W)arriors are strong and skilled with heavy"
          << "\n\tweapons. Also, they can wear heavy armor. But"
          << "\n\tthey are slower than other characters and less"
          << "\n\tadept at magic.\n\n";
     PAUSE();
     system("CLS");    
     cout << "\n\n\n\t(M)ages are intelligent and can skillfully use"
          << "\n\tall magic, but they are generally poor handlers"
          << "\n\tof heavy weapons and do not possess the strength"
          << "\n\tto field the heavier types of armor.\n\n";
     PAUSE();
     system("CLS");         
     cout << "\n\n\n\t(F)ighters are dextrous, fast and agile. They"
          << "\n\tdo not require heavy armor or weapons, as their"
          << "\n\tmartial arts skills give them multiple attack"
          << "\n\tand defense maneuvers in combat. They can weild"
          << "\n\tsome weapons when required, though not as much"
          << "\n\tas fighters, and use some magic, though not as"
          << "\n\twell as Mages.\n";
     PAUSE();
     system("CLS");    
     cout << "\n\n\n\t(E)lves make the most stealthy opponents - they"
          << "\n\tare swift and dextrous, nimble and light on their"
          << "\n\tfeet. They generally can communicate with animals"
          << "\n\tand can handle projectile weapons with great"
          << "\n\tprecision. They are not as strong as the other"
          << "\n\tclasses and therefore can not handle heavy weapons"
          << "\n\tor armor. On the other hand, elves may skillfully"
          << "\n\temploy magic, though not as well as Mages.\n";   
          
     PAUSE();
     system("CLS");    
     cout << "\n\n\n\t(S)hamans are excellent healers and skillful"
          << "\n\tin the use of magic. They are especially good at"
          << "\n\treading signs and ruins, and are gifted with"
          << "\n\twith a supernatural intuition that's very useful"
          << "\n\tfor helping them to avoid traps and danger.\n";   
          
     PAUSE();             
}

//---------------------------------------------------------------------------------------------------------------------------

void PAUSE()
{
     cout << "\n\tPress Enter to continue . . .\n\t";
     cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

//---------------------------------------------------------------------------------------------------------------------------


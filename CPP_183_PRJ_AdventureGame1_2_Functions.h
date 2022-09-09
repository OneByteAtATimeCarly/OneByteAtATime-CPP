//PRJ - AdventureGame1 - Functions - 2004 - C. S. Germany
//File 2 of 3

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void InitializeGlobals();
void Introduction();
int CENTER(Character * CurrentPlayer);
int NORTH1(Character * CurrentPlayer);
int SOUTH1(Character * CurrentPlayer);
int EAST1(Character * CurrentPlayer);
int WEST1(Character * CurrentPlayer);
int NORTH2(Character * CurrentPlayer);
int SOUTH2(Character * CurrentPlayer);
int EAST2(Character * CurrentPlayer);
int WEST2(Character * CurrentPlayer);
int SHAMANUT(Character * CurrentPlayer);
int GateWay(Character * CurrentPlayer);
int Combat(Character * p, Dragon * m, EVENTS CurrentLocation);
int Combat(Character * p, Giant * m, EVENTS CurrentLocation);
int Options(Character * CurrentPlayer, int location);
bool SaveCharacter(Character * CurrentPlayer);
bool LoadCharacter(Character * CurrentPlayer);
bool SaveHighScores(Character * CurrentPlayer);
bool DisplayHighScores();

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

void InitializeGlobals()
{
     cout << "\t*********  Hills of Darkness 2.0 - 2006 C. Germany *********\n\n";
     W1GiantAlive = true;
     E1DragonAlive = true;
     S2MotleyCrewAlive = true;
     FirstTimeInShamanHut = true;
     CENTERFirstTime = true;
     UNDERDragonPairAlive = true;
	 FoundHP_West2 = false;
     FoundHP_Shaman = false;
}

//---------------------------------------------------------------------------------------------------------------------------

void Introduction()
{
     system("CLS"); 
    
     cout << "\a\n\n\t\t\t   Hills of Darkness 2.0\n\n\n";
     
     cout << "\tYou awake from what appears to be a disturbing dream, knowing\n"
          << "\tneither where you've been nor how you got where you are now.\n"
          << "\tYou slowly rise to your feet, bewildered and almost oblivious\n"
          << "\tto the throbbing ache pulsating between your ringing ears.\n\n"
          << "\tYou find  yourself standing on a flowing grassy knoll amidst\n"
          << "\tthe dark green hills of medieval Scotland. In the skies above,\n"
          << "\tdark gray clouds are passing in billowing random patterns. It\n"
          << "\tappears a storm is approaching from the east. A few black ravens\n"
          << "\tfly over your head towards some unknown destination, a familiar\n"
          << "\tcaw, their cries echoing softly against the creeping shadows.";
          
     cout << "\n\n\n\n\n\n\t";
          
     system("PAUSE");
     system("CLS");           
}

//---------------------------------------------------------------------------------------------------------------------------

int CENTER(Character * CurrentPlayer)
{
     int location;
     char choice = 'z';
     
     if(CENTERFirstTime)
     {    
         cout << "\n\n\n"
              << "\t" << CurrentPlayer->getName() 
              << ", confused, you try to get your bearings.\n\n"
              << "\tYou see nothing but large stone tablets and columns with\n"
              << "\twhat appear to be odd and archaic symbols engraved upon them.\n\n";
              
         CENTERFirstTime = false;         
     }  
     else
     {
         cout << "\n\n\n"
              << "\tYou return to the location where you first mysteriously appeared\n"
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
              
          while( choice != 'n' && 
                 choice != 's' && 
                 choice != 'e' && 
                 choice != 'w' &&
                 choice != 'o' )
          {
             cout << "\n\n\tWhere will you go (n, s, e, w)?  Or will you (t)ry the gates?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             
             cin >> choice;
             
             choice = tolower(choice);
             
             switch(choice)
             {
               case 'n' : location = N1; break;
               case 's' : location = S1; break;
               case 'e' : location = E1; break;
               case 'w' : location = W1; break;
               case 'o' : location = Options(CurrentPlayer, CENTER1); break;
               case 't' : if(!CENTERFirstTime)
                          { location = GATE; choice = 'o'; break; }
                          else { cout << "\tThat was an invalid choice."; break; }
               case 'i' : CurrentPlayer->Inventory(); break;
               case '~' : CurrentPlayer->Cheat(); break;
               case '!' : CurrentPlayer->InitializeInventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;
               default : cout << "\tThat was an invalid choice."; break;              
             }
          }   
          system("CLS");
          return location;     
}

//---------------------------------------------------------------------------------------------------------------------------

int NORTH1(Character * CurrentPlayer)
{
  int location;
  char choice = 'z';
  
  cout << "\n\n\tYou find yourself amidst the ruins of an ancient castle...\n\n\n";
  cout << "\tFurther to the north, you see the delapidated entrance to the\n"
       << "\tabandoned castle. It is adjoined by crumbling towers, one at\n"
       << "\teach corner of the foundation. The entrance to the castle is a\n"
       << "\tfrail wooden door, looking as though it had been abandoned for\n"
       << "\tover a hundred years. It probably would not be too difficult to\n"
       << "\tforce the door open...\n\n\n"
       << "\tAt this point, you may explore the castle ruins, or go back to\n"
       << "\tthe SOUTH. You are surrounded by impassible castle walls to\n"
       << "\tthe east and the west.\n\n";
       
          while(choice != 's' && choice != 'o' && choice !='n')
          {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
                          
             switch(choice)
             {
               case 's' : location = CENTER1; break;
               case 'o' : location = Options(CurrentPlayer, N1); break;
               case 'n' : location = N2; break;
               case 'e' : cout << "\tYou fail to scale the east wall.\n"; 
                          break;
               case 'w' : cout << "\tYou press against hard, cold stone.\n";
                          if(!CurrentPlayer->getChainMail())
                          {
                             cout << "\tYou find a suit of chain mail!\n";
                             CurrentPlayer->setChainMail(true);
                             CurrentPlayer->Inventory();                              
                          }
                          else { cout << "\tYou already have the chain mail!\n"; } 
                          break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;           
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;      
}

//---------------------------------------------------------------------------------------------------------------------------

int SOUTH1(Character * CurrentPlayer)
{
  int location;
  char choice = 'z';
  
  cout << "\n\n\tYou stumble into the gates of a rustic village. You see what\n"
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
       
          while(choice != 'n' && choice != 's' && choice != 'o')
          {                
             cout << "\n\n\tChoices: (n,e,s,w)  (g)o into the Shaman's Hut\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;
             
             choice = tolower(choice);
             
             switch(choice)
             {
               case 'n' : location = CENTER1; break;
               case 'o' : location = Options(CurrentPlayer, S1); break;
               case 's' : location = S2; break;
               case 'e' : cout << "\tYou have no right to enter someone else's dwelling!\n"; 
                          break;
               case 'w' : if(!CurrentPlayer->getSword())
                          {  cout << "\nBonus!!!\n\n";
                             cout << "\tYou can not mange to ascend the gate in front of you.\n"
                                  << "\tbut you do find a broad sword at the base of the wall!";
                             CurrentPlayer->setSword(true);
                             CurrentPlayer->Inventory();
                          }
                          else {cout << "\tYou already took the sword!"; }       
                          break;
               case 'g' : location = SHAMAN; choice = 'o'; break;           
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;                            
               case 'h' : CurrentPlayer->UseHealingPotion(); break;
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;        
}

//---------------------------------------------------------------------------------------------------------------------------

int EAST1(Character * CurrentPlayer)
{
    int location;
    char choice = 'z';
    srand(time(NULL));  //seed for random numbers
  
    cout << "\n\n\tYou arrive at a sandy shore where green-blue translucent.\n"
         << "\twaves are crashing against rocky outcroppings. To the north,\n";
       
    if(E1DragonAlive)
    {     
         cout << "\ta magnificent red dragon folds its wings, smoke billowing\n"
              << "\tfrom its nostrils.";
    }
    else
    { cout << "\ta slain dragon is being devoured by ravens..."; }       
       
    cout << "\n\n\n\tAt this point, you may only go back to the WEST. You are\n"
         << "\tsurrounded by turbulent water and razor sharp rocks to the\n"
         << "\teast and the south.\n\n";
       
          while(choice != 'w' && choice != 'e' && choice != 'o')
          {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;
             
             choice = tolower(choice);
             
             switch(choice)
             {
               case 'w' : location = CENTER1; break;
               case 'o' : location = Options(CurrentPlayer, E1); break;
               case 'n' : if(E1DragonAlive)
                           {  cout << "\n\n\tYou creep towards the Dragon. Startled," 
                                   << " it climbs into the sky\n\tto defend itself!\n";
                              Dragon Prometheus; //Example of passing object on stack
                              location = Combat(CurrentPlayer, &Prometheus, E1);
                              E1DragonAlive = false;
                              //break out of while true, re-invoke EAST1 to display text
                              choice = 'o'; 
                              break;
                           }
                           else  
                           { 
                              cout << "\tYou see a noble red dragon, tragically and"
                                   << " yet recently slain...\n"; 
                              break;   
                           }
               case 'e' : cout << "\tYou jump into the water. It's freezing. You catch a cold.\n"; 
                          location = E2; break;
               case 's' : cout << "\n\tYou step on a jellyfish and it stings you with"
                               << " its tentacles!\n";
                          if(CurrentPlayer->getHit() > 1)
                          { 
                             CurrentPlayer->setHit((CurrentPlayer->getHit() - 1));
                             CurrentPlayer->DisplayStats();
                          }
                          else 
                          {     
                             CurrentPlayer->setHit(0);
                             cout << "\tHow pathetic! Slain by a jellyfish!";
                             Continue = false;
                             location = QUIT;
                             cout << "\n\n\t"; system("PAUSE");
                          }    
                          break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;                            
               case 'h' : CurrentPlayer->UseHealingPotion(); break;
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;         
}

//---------------------------------------------------------------------------------------------------------------------------

int WEST1(Character * CurrentPlayer)
{ 
    int location;
    char choice = 'z'; 
  
    cout << "\n\n\tYou arrive at an abandoned farm house. You see a picket fence,\n"
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
         
    cout << "\n\n\n";                   
    cout << "\tAt this point, you may go NORTH or back EAST.\n"
         << "\tYou see only thick undergrowth and brush\n"
         << "\tto the west. To the south is that brutish giant.\n"
         << "\twith a foul mouth and a nasty disposition.\n\n\n";
       
         while(choice != 'e' && choice != 'w' && choice != 'o')
         {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
             
             switch(choice)
             {
                case 'e' : location = CENTER1; break;
                case 'o' : location = Options(CurrentPlayer, W1); break;
                case 'n' : cout << "\tYou are attacked by a vicious chicken! You can not pass.\n";
                           if(!CurrentPlayer->getDagger())
                           {
                              cout << "\tBut lieing on the ground, you find a bronze dagger!";
                              CurrentPlayer->setDagger(true);
                              CurrentPlayer->Inventory();
                           }
                           else { cout << "\tYou already found the dagger!\n"; } 
                           break;
                case 's' : if(W1GiantAlive)
                           {  cout << "\n\n\tYou walk towards the Giant and he charges you!";
                              Giant Bubba; //Creating and passing object on stack
                              location = Combat(CurrentPlayer, &Bubba, W1);
                              //If player survives, make sure they don't fight giant
                              //by setting the global boolean to false
                              W1GiantAlive = false; 
                              //break out of while true, re-invoke WEST1 to display text
                              choice = 'o'; 
                           }
                           else  
                           { 
                              cout << "\tYou stumble over the corpse of a dead giant!\n";   
                           }
                           break; 
                case 'w' :  location = W2; break;
                case 'i' : CurrentPlayer->Inventory(); break;
                case 'd' : CurrentPlayer->DisplayStats(); break;                              
                case 'h' : CurrentPlayer->UseHealingPotion(); break;
                default : cout << "\tInvalid choice.\n"; break;              
             }
          }
     
     system("CLS"); 
     return location;             
}

//---------------------------------------------------------------------------------------------------------------------------

int NORTH2(Character * CurrentPlayer)
{
  int location;
  char choice = 'z'; system("CLS");
  
  cout << "\n\n\n\n\tYou walk inside the castle. It is dark and musty, but\n";
  cout << "\tenough daylight is leaking through the cracks in between\n"
       << "\tstones and mortar that you can ascertain your surroundings\n"
       << "\tin a dim, colorless twilight. Against the wall to the east\n"
       << "\tyou see a long wooden box, about the size of a coffin. You\n"
       << "\tcan see a table, chairs and several candle stands to the west\n"
       << "\tof the room. To the north and the south the walls are adorned\n"
       << "\twith dusty, thread-bare tapestries. You notice stairs descending\n"
       << "\tdeep underground to some unknown passage to your right. ";
       
          while(choice != 's' && choice != 'o')
          {                
             cout << "\n\n\tChoices: (n,s,e,w)   (u)nderground passage\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
                          
             switch(choice)
             {
               case 's' : location = N1; break;
               case 'o' : location = Options(CurrentPlayer, N2); break;
               case 'n' : cout << "\tThe tapestries look very dry and dusty.\n"; break;
               case 'e' : cout << "\tYou approach the box and cautiously open it...\n"; 
                          if(!CurrentPlayer->getFullBodyArmor())
                          {
                             cout << "\tYou find a well preserved suit of full body armor!\n";
                             CurrentPlayer->setFullBodyArmor(true);
                             CurrentPlayer->Inventory();                              
                          }
                          else { cout << "\tThe box is empty - you already took the armor.\n"; } 
                          break;
               case 'w' : cout << "\tYou press against the wall but find nothing.\n"; break;
               case 'u' : location = UNDERGRND; choice = 'o'; break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;           
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;      
}

//---------------------------------------------------------------------------------------------------------------------------

int SOUTH2(Character * CurrentPlayer)
{
  int location;
  char choice = 'z';
  char crazy;
  
  cout << "\n\n\tYou wander through the village further to the south.\n";
  cout << "\tYou notice several of the villagers are staring at you\n"
       << "\tstrangely as you walk by. You come to the southern gate\n"
       << "\tthat guards the entrance to the village and pass through its\n"
       << "\topen doors. You follow a meandering dirt path towards the\n"
       << "\tedge of a dense hardwood forest. As you walk along the road,\n"
       << "\tyou pass several merchants hauling their wares by horse and\n"
       << "\tcart. Continuing south, you see a group of three giants \n"
       << "\tresting with their backs against the trees.\n\n";
       
          while(choice != 'n' && choice != 'o')
          {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
                          
             switch(choice)
             {
               case 's' : if(S2MotleyCrewAlive)
                          { cout << "\tYou're either really brave or really stupid.\n";
                            cout << "\tAre you sure you want to fight 3 giants at the same time?   ";
                            cin >> crazy;
                            if(tolower(crazy) == 'y')
                            {
                               Giant * MotleyCrew = new Giant[3];
                               cout << "\tAll three giants charge you at once!\n";
                               for(int x = 0; x < 3; x++)
                               {
                                  location = Combat(CurrentPlayer, &MotleyCrew[x], S2);     
                               }
                               //Clean up after MotleyCrew - no dangling pointers
                               delete [] MotleyCrew; MotleyCrew = 0;
                               S2MotleyCrewAlive = false;
                            }   
                            else { cout << "\tIntelligently, you decide to walk away...\n"; }   
                          }
                          else { cout << "\tYou see three dead giants.\n"; }
                          break;
               case 'o' : location = Options(CurrentPlayer, S2); break;
               case 'n' : location = S1; break;
               case 'e' : cout << "\tYou see a lake, covered with lily pads and algae.\n"; break;
               case 'w' : cout << "\tYou see cat tails and dragon flies skimming across"
                               << " the water.\n"; break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;           
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;     
}

//---------------------------------------------------------------------------------------------------------------------------

int EAST2(Character * CurrentPlayer)
{
  int location;
  char choice = 'z';
  
  cout << "\n\n\tYou swim out to the sand bars hundreds of feet beyond the shore.\n"
       << "\tIn every direction, you see dolphins and sharks swimming around you.\n\n";
       
          while(choice != 'w' && choice != 'o')
          {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
                          
             switch(choice)
             {
               case 's' : cout << "\n\tYou see dolphins and sharks.\n";
                          if(!CurrentPlayer->getFishKey())
                          {
                            cout << "\n\tYou notice something metalic shining in the sand\n"
                                 << "\tbeneath your feet. You dig into the sand and find\n"
                                 << "\ta bronze key with a Fish engraved upon it.";
                            CurrentPlayer->setFishKey(true);       
                          }
                          else
                          { cout << "\n\tHey, this is the same place you found that Fish key!"; } 
                          break;
               case 'o' : location = Options(CurrentPlayer, E2); break;
               case 'n' : cout << "\n\tYou see dolphins and sharks.\n"; break;
               case 'e' : cout << "\n\tYou see dolphins and sharks.\n"; break;
               case 'w' : location = E1; break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;           
               default : cout << "\n\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;             
}

//---------------------------------------------------------------------------------------------------------------------------

int WEST2(Character * CurrentPlayer)
{
  int location;
  char choice = 'z';
  
  cout << "\n\n\tYou find yourself walking in golden fields of wheat.\n\n";
       
          while(choice != 'e' && choice != 'o')
          {                
             cout << "\n\n\tWhere will you go (n,s,e,w)?\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;

             choice = tolower(choice);
                          
             switch(choice)
             {
               case 's' : cout << "\tYou see... WHEAT!\n"; 
                          if(!FoundHP_West2)
                          {
                             cout << "\tBuried under a mound among the wheat, you\n"
                                  << "\tfind a healing potion!\n";
                             CurrentPlayer->setHealingPotion(1);
                             FoundHP_West2 = true;
                             CurrentPlayer->Inventory();
                          }
                          else { cout << "\tYou already found the healing potion!\n"; }
                          break;      
               case 'o' : location = Options(CurrentPlayer, W2); break;
               case 'n' : if(!CurrentPlayer->getLongBow())
                          {
                             cout << "\tYou find a well-stringed long bow and arrows!\n";
                             CurrentPlayer->setLongBow(true);
                             CurrentPlayer->Inventory();                              
                          }
                          else { cout << "\tYou already found the long bow.\n"; } 
                          break;
               case 'e' : location = W1; break;
               case 'w' : cout << "\tYou see various feed crops planted in rows.\n"; break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;
               case 'h' : CurrentPlayer->UseHealingPotion(); break;           
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;         
}

//---------------------------------------------------------------------------------------------------------------------------

int SHAMANHUT(Character * CurrentPlayer, Shaman * WiseWoman)
{
  int location;
  char choice = 'z';
  
  if(FirstTimeInShamanHut)
  { 
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
                             CurrentPlayer->setHealingPotion(1);
							 FoundHP_Shaman = true;
                             cout << "\t\t\t"; system("PAUSE"); 
							 CurrentPlayer->Inventory();
                             cout << "\t\t\t"; system("PAUSE"); system("CLS"); cout << "\n\n";
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
  
          while(choice != 'l' && choice != 's' && choice != 'o')
          {                
             cout << "\n\n\tYou may: (l)eave  (t)alk  or (s)teal things\n"
                  << "\tOther: (o)ptions  (i)nventory  (d)isplay stats  (h)ealing potion   ";
             cin >> choice;
             
             choice = tolower(choice);
             
             switch(choice)
             {
               case 'n' : cout << "\tYou run into a straw-mud wall.\n"; break;
               case 'o' : location = Options(CurrentPlayer, SHAMAN); break;
               case 'l' : location = S1; break;
               case 's' : system("CLS");
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
                          CurrentPlayer->setHit(0); CurrentPlayer->DisplayStats();
                          location = QUIT; choice = 'o';
                          break;
               case 't' : cout << "\tYou seek audience with the preistess.\n"; 
                          WiseWoman->Talk(); break;
               case 'i' : CurrentPlayer->Inventory(); break;
               case 'd' : CurrentPlayer->DisplayStats(); break;                            
               case 'h' : CurrentPlayer->UseHealingPotion(); break;
               default : cout << "\tThat was an invalid choice.\n"; break;              
             }
          }
     system("CLS"); 
     return location;            
}

//---------------------------------------------------------------------------------------------------------------------------

int GateWay(Character * CurrentPlayer)
{
    int location;
       
    if(CurrentPlayer->getFishKey())
    {
        cout << "\n\n\tFumbling around the gate, you find a slot to insert the\n"
             << "\tFish key. The tablets and columns begin to rumble and shake.\n"
             << "\tLarge stones rise, levitating off the ground, rearranging themselves.";
    }
    else
    {
        cout << "\n\n\tYou look around, trying every nook and crevice, but can not\n"
             << "\tseem to find the means to open the gate, nor alter anything else\n"
             << "\n\taround it. You see what appears to be a key hole to one side.\n\n";
             
        location = CENTER1;       
    }
    
    if(CurrentPlayer->getFishKey() && CurrentPlayer->getScore() < 50)
    {
        cout << "\n\n\tIt appears that, although you have the key, you lack enough\n"
             << "\texperience with the ways of this world to cause the gate to"
             << "\n\tfunction in any useful manner.\n\n\n";
             
        location = CENTER1;                                  
    }
    
    if(CurrentPlayer->getFishKey() && CurrentPlayer->getScore() >= 50)
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
        
        cout << "\n\t"; system("PAUSE");  
        cout << "\tYou win this campaign and end the game with:\n\n";     
        CurrentPlayer->DisplayStats(); CurrentPlayer->Inventory();
        cout << "\n\tCombat Experience Score: " << CurrentPlayer->getScore() << ".\n\n\n";
        location = QUIT;                                  
    }
    cout << "\n\t"; system("PAUSE"); system("CLS");
    return location;
}

//---------------------------------------------------------------------------------------------------------------------------

int UnderGroundPassage(Character * CurrentPlayer)
{
    int location;
    char nutz;
    
    cout << "\n\n\n\n\n\n\tYou descend into the darkness underground...\n";
    
    if(UNDERDragonPairAlive)
    {
      cout << "\tPeeking around a corner, you see a family of red dragons\n";
      cout << "\tbreathing fire! Think about whether you want to fight or flee.\n";
      cout << "\tAre you sure you want to fight 5 dragons at the same time? (y,n)   ";
      cin >> nutz;
      
        if(tolower(nutz) == 'y')
        {
           Dragon * DragonFamily = new Dragon[5];
           for(int x = 0; x < 5; x++)
           {
               location = Combat(CurrentPlayer, &DragonFamily[x], UNDERGRND);     
           }
           //Clean up DragonFamily objects on heap, set pointer to NULL
           delete [] DragonFamily; DragonFamily = 0;
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
    cout << "\n\n\n\t"; system("PAUSE"); system("CLS");
    return location;
}

//---------------------------------------------------------------------------------------------------------------------------

int Randy(int n) 
{
    int ResultRandom;
    ResultRandom = (rand()%n) + 1;
    return ResultRandom;
}  
//---------------------------------------------------------------------------------------------------------------------------

//Overloaded Combat Functions, one for Dragon and one for Giant.
//Takes the global enumerated constant "EVENTS" as one of its arguments

//---------------------------------------------------------------------------------------------------------------------------

int Combat(Character * p, Dragon * m, EVENTS CurrentLocation)
{
    char choice = 'z';
    p->setUseDagger(false); p->setUseSword(false); p->setUseLongBow(false);    
    cout << "\n\tMortal Combat!!!\n";
    
    while(choice != 'd' && choice != 's' && choice != 'l' && choice != 'h')
    {
        cout << "\tYou currently have:\n";
        p->Inventory();
        cout << "\tWhat weapon will you choose to wage this battle with?\n"
             << "\t(d)agger   (s)word   (l)ongbow   (h)and to hand combat   ";
        cin >> choice;
    
        switch(choice)
        {
           case 'd' : if(p->getDagger()) { p->setUseDagger(true); }
                      else { cout << "\n\tYou don't have the dagger!\n\n"; choice = 'z';} 
                      break;
           case 's' : if(p->getSword()) { p->setUseSword(true); }
                      else { cout << "\n\tYou don't have the sword!\n\n"; choice = 'z';} 
                      break;
           case 'l' : if(p->getLongBow()) { p->setUseLongBow(true); }
                      else { cout << "\n\tYou don't have the long bow!\n\n"; choice = 'z';} 
                      break;
           case 'h' : cout << "\n\tHand to hand it is...\n\n";
                           p->setUseDagger(false); p->setUseSword(false); 
                           p->setUseLongBow(false); break;
           default : cout << "\tThat was an invalid response.\n"; break;
        } //close switch
    } //close while true loop
    
    
    while(p->getHit() > 0 && m->getHit() > 0)
    {
       if(p->getHit() > 0) { p->Attack(m); }
       if(m->getHit() > 0) { m->Attack(p); }  
    }  
    
    if(p->getHit() <= 0)
    { 
          cout << "\tYou die, most tragically!\n\n";
          cout << "\tThe Dragon wins the battle, having " << m->getHit() 
               << " hitpoints left.\n";
          Continue = false;
          cout << "\t"; system("PAUSE");
          return QUIT;    
    }
    else
    { 
           cout << "\n\n\tYou vanquish your foe most valiantly!\n";
           cout << "\tThe Dragon died, now having " << m->getHit() << " hitpoints.\n";
           cout << "\t" << p->getName() << " has " << p->getHit() << " hitpoints left.\n\n";
           cout << "\tAdd 1 to your attack and 1 to your defense as a result of\n"
                << "\tcombat experience acquired defeating this foe.\n";
           p->setScore((p->getScore() + 10)); 
           cout << "\n\t" << p->getName() << "'s Current Score: " << p->getScore() << ".\n";
           p->setAttack((p->getAttack() + 1)); p->setDefense((p->getDefense() + 1)); 
           p->DisplayStats();             
           cout << "\n\n\t"; system("PAUSE"); system("CLS");
           return CurrentLocation;
    }
}

//---------------------------------------------------------------------------------------------------------------------------

int Combat(Character * p, Giant * m, EVENTS CurrentLocation)
{
    char choice = 'z';
    p->setUseDagger(false); p->setUseSword(false); p->setUseLongBow(false);    
    cout << "\n\tMortal Combat!!!\n";
    
    while(choice != 'd' && choice != 's' && choice != 'l' && choice != 'h')
    {
        cout << "\tYou currently have:\n";
        p->Inventory();
        cout << "\tWhat weapon will you choose to wage this battle with?\n"
             << "\t(d)agger   (s)word   (l)ongbow   (h)and to hand combat   ";
        cin >> choice;
    
        switch(choice)
        {
           case 'd' : if(p->getDagger()) { p->setUseDagger(true); }
                      else { cout << "\n\tYou don't have the dagger!\n\n"; choice = 'z';} 
                      break;
           case 's' : if(p->getSword()) { p->setUseSword(true); }
                      else { cout << "\n\tYou don't have the sword!\n\n"; choice = 'z';} 
                      break;
           case 'l' : if(p->getLongBow()) { p->setUseLongBow(true); }
                      else { cout << "\n\tYou don't have the long bow!\n\n"; choice = 'z';} 
                      break;
           case 'h' : cout << "\n\tHand to hand it is...\n\n";
                           p->setUseDagger(false); p->setUseSword(false); 
                           p->setUseLongBow(false); break;
           default : cout << "\n\tThat was an invalid response.\n"; break;
        } //close switch
    } //close while true loop
    
    while(p->getHit() > 0 && m->getHit() > 0)
    {
       if(p->getHit() > 0) { p->Attack(m); }
       if(m->getHit() > 0) { m->Attack(p); }  
    }  
    
    if(p->getHit() <= 0)
    { 
          cout << "\tYou die, most tragically!\n\n";
          cout << "\tThe Giant won the battle, having " << m->getHit() 
               << " hitpoints left.\n";
          Continue = false;     
          cout << "\t"; system("PAUSE");
          return QUIT;    
    }
    else
    { 
           cout << "\n\n\tYou vanquish your foe most valiantly!\n";
           cout << "\tThe Giant died, now having " << m->getHit() << " hitpoints.\n";
           cout << "\t" << p->getName() <<" has " << p->getHit() << " hitpoints left.\n\n";
           cout << "\tAdd 1 to your attack and 1 to your defense as a result of\n"
                << "\tcombat experience acquired defeating this foe.\n";
           p->setScore((p->getScore() + 10)); 
           cout << "\n\t" << p->getName() << "'s Current Score: " << p->getScore() << ".\n";
           p->setAttack((p->getAttack() + 1)); p->setDefense((p->getDefense() + 1)); 
           p->DisplayStats();      
           cout << "\n\n\t"; system("PAUSE"); system("CLS");
           return CurrentLocation;
    }
}

//---------------------------------------------------------------------------------------------------------------------------

int Options(Character * CurrentPlayer, int location)
{
    char choice; bool successful; system("CLS"); cout << "\n\n\n\n";

    while(choice != 's' && choice != 'l' && choice != 'h' && choice != 'q')
    {  
         cout << "\n\n\t\t\t********* OPTIONS *********\n"
              << "\t\t\t*                         *\n"
              << "\t\t\t*      (s)ave game        *\n"
              << "\t\t\t*      (l)oad game        *\n"
              << "\t\t\t*      (h)igh scores      *\n"
              << "\t\t\t*      (q)uit             *\n"
              << "\t\t\t*                         *\n"
              << "\t\t\t***************************\n\n\t\t\t";
          
        cin >> choice;
    
        switch(tolower(choice))
        {
           case 's' : CurrentPlayer->setLocation(location);
                      successful = SaveCharacter(CurrentPlayer);
                      if(successful)
                      {  
                          cout << "\n\tYour character was saved!\n\n\t";
                      }
                      else 
                      { 
                         cout << "\n\tYou character could not be saved!\n\n\t"; 
                      }
                      system("PAUSE"); break;
           case 'l' : successful = LoadCharacter(CurrentPlayer);
                      if(successful)
                      { 
                         location = CurrentPlayer->getLocation(); 
                         cout << "\n\tYour character was loaded!\n\n\t";
                      }
                      else 
                      { 
                           cout << "\n\tYou character could not be loaded!\n\n\t"; 
                      }
                      system("PAUSE"); break;
           case 'h' : successful = DisplayHighScores();
                      if(successful) { break; }
                      else { cout << "\n\tThere are no high scores to load!\n\n\t"; }
                      system("PAUSE");                     
                      break;
           case 'q' : location = QUIT; break;
           default : cout << "\n\t\t\tInvalid choice.\n"; break;
        } //close switch
    } //close while loop

   return location;   
}

//---------------------------------------------------------------------------------------------------------------------------

bool SaveCharacter(Character * CurrentPlayer) 
{                     
     bool successful;
     char CharacterName[80];
     string passwd;
     cout << "\n\tEnter the file name to save as: ";
     cin >> CharacterName; strcat(CharacterName, ".gam");
     cout << "\n\tEnter a password:   ";
     cin >> passwd;
     
     ofstream WriteStuff;
     WriteStuff.open(CharacterName);

     if(!WriteStuff) 
     { 
         cout << "\tError. Unable to create " << CharacterName << " for writing.\n";
         successful = false;
     }  //close if

     else 
     {
         //Simple serialization of Character class 
         WriteStuff << passwd << "\n";                        
         WriteStuff << CurrentPlayer->getName() << "\n";
         WriteStuff << CurrentPlayer->getHit() << "\n";
         WriteStuff << CurrentPlayer->getAttack() << "\n"; 
         WriteStuff << CurrentPlayer->getDefense() << "\n";                        
         WriteStuff << CurrentPlayer->getLevel() << "\n";
         WriteStuff << CurrentPlayer->getScore() << "\n";
         WriteStuff << CurrentPlayer->getLocation() << "\n";         

         WriteStuff << CurrentPlayer->getDagger() << "\n";
         WriteStuff << CurrentPlayer->getSword() << "\n";
         WriteStuff << CurrentPlayer->getLongBow() << "\n"; 
         WriteStuff << CurrentPlayer->getChainMail() << "\n";               
         WriteStuff << CurrentPlayer->getFullBodyArmor() << "\n";
         WriteStuff << CurrentPlayer->getHealingPotion() << "\n";
         WriteStuff << CurrentPlayer->getFishKey() << "\n";
          
         WriteStuff << W1GiantAlive << "\n";
         WriteStuff << E1DragonAlive << "\n"; 
         WriteStuff << S2MotleyCrewAlive << "\n";               
         WriteStuff << FirstTimeInShamanHut << "\n";
         WriteStuff << CENTERFirstTime << "\n";
         WriteStuff << UNDERDragonPairAlive << "\n";
         WriteStuff << FoundHP_West2 << "\n";
         WriteStuff << FoundHP_Shaman << "\n";         
              
         //Note: You could flush the buffer to write to the file and keep it open
         //using  WriteStuff << flush  , but we don't need to keep it open so:       
         WriteStuff.close();
         successful = true;
     }
     return successful;
} 

//---------------------------------------------------------------------------------------------------------------------------

bool LoadCharacter(Character * CurrentPlayer) 
{
     bool successful; string nm, passwd, pass;
     int hp, atk, def, lvl, scr, loc;
     //Note: bool data type reads in VS 6.0 and .Net, but for BloodShed you 
     //must read all boolean values as integers from the file
     int dagger, sword, bow, mail, armor, healing, fkey;
           
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
           getline(ReadStuff, nm); ReadStuff >> hp;
           ReadStuff >> atk; ReadStuff >> def;              
           ReadStuff >> lvl; ReadStuff >> scr;
           ReadStuff >> loc; 

           ReadStuff >> dagger;
           ReadStuff >> sword; ReadStuff >> bow;              
           ReadStuff >> mail; ReadStuff >> armor;
           ReadStuff >> healing; ReadStuff >> fkey;

	   //Note: In VS 6.0 and .Net Visul Studio, you can read these as booleans
	   //with no problem. The problem is with Bloodshed - they will all read in
	   //as false. To make it compatible with Bloodshed (therefore all 3
	   //compilers) you must read them as integers and they will be cast to bools
	   //in VS 6.0 and .Net Visual Studio. (It ain't easy getting these 3 to agree).
	   int giant, dragon, motley, shaman, center, under, HPwest2, HPshaman;

           ReadStuff >> giant; W1GiantAlive = giant;
           ReadStuff >> dragon; E1DragonAlive = dragon; 
           ReadStuff >> motley; S2MotleyCrewAlive = motley;               
           ReadStuff >> shaman; FirstTimeInShamanHut = shaman;
           ReadStuff >> center; CENTERFirstTime = center;
           ReadStuff >> under; UNDERDragonPairAlive = under;
           ReadStuff >> HPwest2; FoundHP_West2 = HPwest2;
           ReadStuff >> HPshaman; FoundHP_Shaman = HPshaman;              
                
           CurrentPlayer->setName(nm); CurrentPlayer->setHit(hp);
           CurrentPlayer->setAttack(atk); CurrentPlayer->setDefense(def);        
           CurrentPlayer->setLevel(lvl); CurrentPlayer->setScore(scr);
           CurrentPlayer->setLocation(loc); 
           CurrentPlayer->setDagger(dagger);
           CurrentPlayer->setSword(sword); CurrentPlayer->setLongBow(bow); 
           CurrentPlayer->setChainMail(mail); CurrentPlayer->setFullBodyArmor(armor);
           CurrentPlayer->setHealingPotion(healing); CurrentPlayer->setFishKey(fkey); 

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

bool SaveHighScores(Character * CurrentPlayer) 
{
     bool successful;
     ofstream highscores;
     highscores.open("highscores.txt", ios::app);
     
     if(!highscores)
     {
        cout << "\tError. Unable to create \"highscores\" for writing.\n";
        successful = false;                    
     }
     else
     { 
         highscores << CurrentPlayer->getName() << "\n"
                    << CurrentPlayer->getScore() << "\n";
                
         highscores.close();
         successful = true;
     } 
     return successful;
}  //close function


//---------------------------------------------------------------------------------------------------------------------------

//Function - DisplayHighScores

bool DisplayHighScores() 
{
     system("CLS"); cout << "\n\n\n"; bool successful;     
     string HoldMeString; int HoldMeInt, z, x = 0;
     
     ifstream highscores("highscores.txt");

     if (!highscores) 
     {
          cout << "\tUnable to find \"highscores.txt\" for reading.\n";
          successful = false;
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
        successful = true;
	 }//close else 
        return successful;
}

//---------------------------------------------------------------------------------------------------------------------------



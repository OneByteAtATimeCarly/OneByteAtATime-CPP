//PRJ - RPG Hills of Darkness - MFC GUI Game - 2006 - C. S. Germany
//File 3 of 7: FUNCTIONS

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_210_PRJ_MFC_RPGGame2_02_CLASSES.h"

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

void InitializeGlobals()
{
     LOCK = false;
     Continue = true;
     location = INTRO;

     W1GiantAlive = true;
     E1DragonAlive = true;
     S2MotleyCrewAlive = true;
     FirstTimeInShamanHut = true;
     CENTERFirstTime = true;
     UNDERDragonPairAlive = true;
     FoundHP_West2 = false;
     FoundHP_Shaman = false;

     StartedGame = false;
     NeedName = true;
     GoEvent = 1;
     NagMe = 0;
     HiScoresToggle = true;

     ConqueredDragons = 0;
     ConqueredGiants = 0;
}

//---------------------------------------------------------------------------------------------------------------------------

int Introduction()
{
     if(choice[0] == 'g')
     {
        location = CENTER1;
        LOCK = false;
        return location;
     }
     else
     {
        LOCK = true;
        MESSAGE = "";
        MESSAGE = MESSAGE + "\r\n "
        + "Hills of Darkness 3.0\r\n\r\n";

//Note: For sound, you must do three things:
//1. Go to project properties, then under Linker, find Input.
//In the box labelled Aditional Dependancies add "winmm.lib".
//2. Include the file: #include <mmsystem.h> .
//3. Use command: PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC);
//Options: SYNC = ends with function, async = keep playing
//SND_LOOP = loop it, must be stopped then with "StopSound()".
//PlaySound("west.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);

        MESSAGE = MESSAGE + "You awake from what appears to be a disturbing dream, "
        + "knowing neither where you've been nor how you got where "
        + "you are now. You slowly rise to your feet, bewildered "
        + " and almost oblivious to the throbbing ache pulsating "
        + "between your ringing ears.\r\n\r\nYou find yourself "
        + "standing on a flowing grassy knoll amidst the dark green "
        + "hills of medieval Scotland. In the skies above, dark gray "
        + "clouds are passing in billowing random patterns. It appears "
        + "a storm is approaching from the east. A few black ravens "
        + "fly over your head towards some unknown destination, a "
        + "familiar caw, their cries echoing softly against the "
        + "creeping shadows.";

        MESSAGE = MESSAGE + "\r\n\r\n\r\n"
        + "Type \"G\" in the command box and click the \"GO\" "
        + "button to continue...";

        HBITMAP IntroPix = (HBITMAP) LoadImage(NULL,L"media/hills.bmp",
        IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

        pView->SetBitmap(IntroPix);

        Conquests();

        pInput->SetWindowText(L"g");
        pOutput->SetWindowText(MESSAGE);

        return location;
     }//close else
}

//---------------------------------------------------------------------------------------------------------------------------

int CENTER()
{
    if(choice[0] == 'n' || choice[0] == 's' ||
    choice[0] == 'e' || choice[0] == 'w' ||
    choice[0] == 't' || choice[0] == '~' ||
    choice[0] == '!')
    {
       MESSAGE = "";

       switch(choice[0])
       {
          case 'n' : location = N1; break;
          case 's' : location = S1; break;
          case 'e' : location = E1; break;
          case 'w' : location = W1; break;
          case 't' : if(!CENTERFirstTime)
                     {
                        location = GATE;
                        break;
                     }
                     else
                     {
                        MESSAGE = MESSAGE + "\n That was an invalid choice.";
                        break;
                     }
          case '~' : CurrentPlayer->Cheat();
                     break;
          case '!' : CurrentPlayer->InitializeInventory();
                     break;
          default : MESSAGE = MESSAGE + "\n That was an invalid choice.";
          break;
       }

    pOutput->SetWindowText(MESSAGE);
    LOCK = false;

    return location;
    }//close if

    else
    {
       LOCK = true;
       MESSAGE = "";

       if(CENTERFirstTime)
       {
          MESSAGE = MESSAGE + "\r\n" + CurrentPlayer->getName()
          + ", confused, you try to get your bearings. "
          + "You see nothing but large stone tablets and columns with "
          + "what appear to be odd and archaic symbols engraved upon them.\r\n";

          CENTERFirstTime = false;
       }
       else
       {
          MESSAGE = MESSAGE + "\r\nYou return to the location where you first mysteriously appeared "
          + "in this strange medieval world. You notice that the large stone "
          + "tablets and columns have arranged themselves into an arch and hinged "
          + "gates. The symbols are constantly changing, disappearing and re-"
          + "appearing at random intervals across the surface of the tablets. ";
       }

        MESSAGE = MESSAGE + "\r\n\r\nYou see that you can move to the north, south, east or west. "
        + "To the north, you see the ruins of an ancient castle spread "
        + "out across the horizon. To the east, you see the lapping waves "
        + "of the ocean against a sandy shore. To the south, you see a "
        + "small village with gray cobblestone houses and smoldering "
        + "chimneys. To the west, you see an abandoned farm house. ";

        MESSAGE = MESSAGE + "\r\n\r\n\r\nWhere will you go (n, s, e, w)?\r\nOr will you "
        + "(t)ry the gates?\r\n";

        HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/center.bmp",IMAGE_BITMAP,
        0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

        pView->SetBitmap(CenterPix);

        pOutput->SetWindowText(MESSAGE);
        location = CENTER1;

        return location;

    }//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int NORTH1()
{
    if(choice[0] == 's' || choice[0] == 'n' ||
    choice[0] == 'e' || choice[0] == 'w')
    {
       MESSAGE = "";

       switch(choice[0])
       {
          case 's' : location = CENTER1; break;
          case 'n' : location = N2; break;
          case 'e' : MESSAGE = MESSAGE + "\r\nYou fail to scale the east wall and "
                     + "turn back...\r\n";
                     break;
          case 'w' : MESSAGE = MESSAGE + "\r\nYou press against hard, cold stone.\r\n";
                     if(!CurrentPlayer->getChainMail())
                     {
                        MESSAGE = MESSAGE + "You find a suit of chain mail!\r\n";
                        CurrentPlayer->setChainMail(true);
                        CurrentPlayer->Inventory();
                     }
                     else
                     { MESSAGE = MESSAGE + "You already have the chain mail!\r\n"; }
                     break;
          default : /*NADA*/ break;
      }

      pOutput->SetWindowText(MESSAGE);
      LOCK = false;
      return location;

    }//close if
    else
    {
       MESSAGE = "";
       LOCK = true;

       MESSAGE = MESSAGE
       + "\r\nYou find yourself amidst the ruins of an ancient castle...";

       MESSAGE = MESSAGE
       + "\r\n\r\nFurther to the north, you see the delapidated entrance "
       + "to the abandoned castle. It is adjoined by crumbling towers, one at "
       + "each corner of the foundation. The entrance to the castle is a "
       + "frail wooden door, looking as though it had been abandoned for "
       + "over a hundred years. It probably would not be too difficult to "
       + "force the door open...\r\n\r\n"
       + "At this point, you may explore the castle ruins, or go back to "
       + "the SOUTH. You are surrounded by impassible castle walls to "
       + "the east and the west.\r\n\r\n";

       MESSAGE = MESSAGE
       + "Where will you go (n,s,e,w)? ";

       HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/N1.bmp",IMAGE_BITMAP,
       0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

       pView->SetBitmap(CenterPix );

       pOutput->SetWindowText(MESSAGE);
       location = N1;

       return location;

    }//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int SOUTH1()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w' || choice[0] == 'g')
{
MESSAGE = "";

switch(choice[0])
{
case 'n' : location = CENTER1; break;
case 's' : location = S2; break;
case 'e' : MESSAGE = MESSAGE
+ "You have no right to enter someone "
+ "else's dwelling!\r\n";
break;
case 'w' : if(!CurrentPlayer->getSword())
{
MESSAGE = MESSAGE
+ "\r\nBonus!!!\r\n You can not manage to ascend the";
MESSAGE = MESSAGE
+ " gate in front of you, but you do find a broad "
+ "sword at the base of the wall!\r\n";
CurrentPlayer->setSword(true);
CurrentPlayer->Inventory();
}
else
{
MESSAGE = MESSAGE
+ "You already took the sword!\r\n";
}
break;
case 'g' : location = SHAMAN; break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n"; break;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou stumble into the gates of a rustic village. You see what "
+ "appears to be a tavern to the north. Further south, you see a "
+ "winding dirt road that meanders towards the horizon. All around "
+ "you are peasants buying and selling wares in an open market "
+ "place. Near the center of the village several children are "
+ "playing, and in the midst of them sits an elderly woman, "
+ "looking very wise and thoughtful.\r\n\r\n";

MESSAGE = MESSAGE
+ "At this point, you may only go back to the NORTH or further SOUTH, "
+ "if you so desire. You are surrounded by what seems impassible "
+ "terrain to the east and the west and several cottages.\r\n\r\n "
+ "Towards thecenter of the villiage, you notice a small though "
+ "nicely maintained Shaman's lodge with smoke billowing from its roof.";

MESSAGE = MESSAGE
+ "\r\n\r\nChoices: (n,e,s,w) (g)o into the Shaman's Hut ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/S1.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = S1;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int EAST1()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w')
{
MESSAGE = "";

switch(choice[0])
{
case 'w' : location = CENTER1; break;
case 'n' : if(E1DragonAlive)
{
MESSAGE = MESSAGE
+ "\r\nYou creep towards the Dragon. Startled, "
+ " it climbs into the sky\nto defend itself!\r\n";
Dragon Prometheus; //Example of passing object on stack
location = Combat(&Prometheus, E1);
E1DragonAlive = false;
PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);
//break out of while true, re-invoke EAST1 to display text
break;
}
else
{
MESSAGE = MESSAGE
+ "\r\nYou see a noble red dragon, tragically and"
+ " yet recently slain...\r\n";
break;
}
case 'e' : MESSAGE = MESSAGE
+ "\r\nYou jump into the water. It's freezing. "
+"You catch a cold.\r\n";
location = E2; break;
case 's' : MESSAGE = MESSAGE
+ "\r\nYou step on a jellyfish and it stings you with"
+ " its tentacles!\r\n";
if(CurrentPlayer->getHit() > 1)
{
CurrentPlayer->setHit((CurrentPlayer->getHit() - 1));
CurrentPlayer->DisplayStats();
}
else
{
CurrentPlayer->setHit(0);
MESSAGE = MESSAGE
+ "How pathetic! Slain by a jellyfish!\r\n";
Continue = false;
location = QUIT;
}
break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n"; break;
}
pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}//close if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou arrive at a sandy shore where green-blue translucent "
+ "waves are crashing against rocky outcroppings. "
+ "Overhead, seagulls are gathering, their cries echo against "
+ "an amphitheatre of sand and sea, intermingling with the sound of"
+ " the waves as they crash upon the beach.\r\n\r\nTo the north, ";

if(E1DragonAlive)
{
MESSAGE = MESSAGE
+ "a magnificent red dragon folds its wings, smoke billowing "
+ "from its nostrils.\r\n\r\n";
}

else
{ MESSAGE = MESSAGE
+ "a slain dragon is being devoured by ravens...\r\n\r\n"; }

MESSAGE = MESSAGE
+ "At this point, you may only go back to the WEST. You are "
+ "surrounded by turbulent water and razor sharp rocks to the "
+ "east and the south.\r\n";

MESSAGE = MESSAGE
+ "\r\nWhere will you go (n,s,e,w)? ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/E1.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = E1;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int WEST1()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w')
{
MESSAGE = "";
switch(choice[0])
{
case 'e' : location = CENTER1; break;
case 'n' : MESSAGE = MESSAGE
+ "\r\nYou are attacked by a vicious "
+ "chicken! You can not pass.\r\n";
if(!CurrentPlayer->getDagger())
{
MESSAGE = MESSAGE
+ "\r\nBut lieing on the ground, "
+ "you find a bronze dagger!\r\n";
CurrentPlayer->setDagger(true);
CurrentPlayer->Inventory();
}
else
{ MESSAGE = MESSAGE
+ "\r\nYou already found the dagger!\r\n";
}
break;
case 's' : if(W1GiantAlive)
{
MESSAGE = MESSAGE
+ "\r\nYou walk towards the Giant and he charges you!";
Giant OneGiant;
location = Combat(&OneGiant, W1);
//If player survives, make sure they don't fight giant
//by setting the global boolean to false
W1GiantAlive = false;
PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);
}
else
{
MESSAGE = MESSAGE
+ "\r\nYou stumble over the corpse of a dead giant!\r\n";
}
break;
case 'w' : location = W2; break;
default : MESSAGE = MESSAGE
+ "Invalid choice.\r\n"; break;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\n\r\nYou arrive at an abandoned farm house. You see a "
+ "picket fence, a rustic dilapidated barn, and a decaying "
+ "hovel that used to be someone's residence. There are "
+ "chickens walking around the premises.\r\n\r\nTo the south, you see ";

if(W1GiantAlive)
{
MESSAGE = MESSAGE
+ "a Giant wearing old, brown "
+ "sackcloth. He is taunting you with offensive "
+ "gestures and lewd comments.\r\n\r\nYou really don't want to "
+ "tangle with a giant, do you?";
}

else
{
MESSAGE = MESSAGE
+ "barbed wire, blood, sackcloth and carnage...";
}

MESSAGE = MESSAGE
+ "\r\n\r\n";
MESSAGE = MESSAGE
+ "At this point, you may go NORTH or back EAST. "
+ "You see only thick undergrowth and brush "
+ "to the west.\r\n";

MESSAGE = MESSAGE
+ "\r\nWhere will you go (n,s,e,w)? ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/W1.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = W1;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int NORTH2()
{
MESSAGE = "";

if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w' || choice[0] == 'g')
{
switch(choice[0])
{
case 's' : location = N1; break;
case 'n' : MESSAGE = MESSAGE
+ "The tapestries look very dry and dusty.\r\n"; break;
case 'e' : MESSAGE = MESSAGE
+ "You approach the box and cautiously open it...\r\n";
if(!CurrentPlayer->getFullBodyArmor())
{
MESSAGE = MESSAGE
+ "You find a well preserved suit of full body armor!\r\n";
CurrentPlayer->setFullBodyArmor(true);
CurrentPlayer->Inventory();
}
else
{
MESSAGE = MESSAGE
+ "The box is empty - you already took the armor.\r\n";
}
break;
case 'w' : MESSAGE = MESSAGE
+ "You press against the wall but find nothing.\r\n"; break;
case 'g' : location = UNDERGRND; break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n"; break;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou walk inside the castle. It is dark and musty, but ";
MESSAGE = MESSAGE
+ "enough daylight is leaking through the cracks in between "
+ "stones and mortar that you can ascertain your surroundings "
+ "in a dim, colorless twilight. Against the wall to the east "
+ "you see a long wooden box, about the size of a coffin. You "
+ "can see a table, chairs and several candle stands to the west "
+ "of the room.\r\n\r\nTo the north and the south the walls are "
+ " adorned with dusty, thread-bare tapestries.\r\n\r\nYou notice"
+ " stairs descending deep underground to some unknown passage to"
+ "your right. ";

MESSAGE = MESSAGE + "\r\n\r\nChoices: (n,s,e,w) or (g)o underground: ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/N2.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = N2;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int SOUTH2()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w')
{
MESSAGE = "";

switch(choice[0])
{
case 's' : location = GIANTCAMP; break;
case 'n' : location = S1; break;
case 'e' : MESSAGE = MESSAGE
+ "You see a lake, covered with lily pads and algae.\n";
break;
case 'w' : MESSAGE = MESSAGE
+ "You see cat tails and dragon flies skimming across"
+ " the water.\n"; break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n"; break;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou wander through the village further to the south. ";
MESSAGE = MESSAGE
+ "You notice several of the villagers are staring at you "
+ "strangely as you walk by. You come to the southern gate "
+ "that guards the entrance to the village and pass through its "
+ "open doors. You follow a meandering dirt path towards the "
+ "edge of a dense hardwood forest.\r\n\r\nAs you walk along the road, "
+ "you pass several merchants hauling their wares by horse and "
+ "cart. ";

if(S2MotleyCrewAlive)
{
MESSAGE = MESSAGE
+ "Continuing south, you see a group of three giants "
+ "resting with their backs against the trees.\r\n\r\n";
}

else
{
MESSAGE = MESSAGE
+ "Looking south, you see the destruction and carnage"
+ " of your bloody victory over the giants. Quickened"
+ " by the smell of carrion, vultures circle overhead...\r\n\r\n";
}

MESSAGE = MESSAGE
+ "Where will you go (n,s,e,w)? ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/S2.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = S2;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int EAST2()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w')
{
MESSAGE = "";

switch(choice[0])
{
case 's' : MESSAGE = MESSAGE
+ "\r\nYou see dolphins and sharks.\r\n";
if(!CurrentPlayer->getFishKey())
{
MESSAGE = MESSAGE
+ "\r\nYou notice something metalic shining in the sand "
+ "beneath your feet. You dig into the sand and find "
+ "a bronze key with a Fish engraved upon it.\r\n\r\n";
CurrentPlayer->setFishKey(true);
}
else
{
MESSAGE = MESSAGE
+ "\r\nHey, this is the same place"
+ "you found that Fish key!\r\n";
}
break;
case 'n' : MESSAGE = MESSAGE
+ "\r\nYou see dolphins and sharks.\r\n"; break;
case 'e' : MESSAGE = MESSAGE
+ "\r\nYou see dolphins and sharks.\r\n"; break;
case 'w' : location = E1; break;
default : MESSAGE = MESSAGE
+ "\r\nThat was an invalid choice.\r\n"; break;
}//close switch

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//end if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou swim out to the sand bars hundreds of feet beyond the shore. "
+ "Treading water until you are almost exhausted, you notice that the "
+ "water growing more and more shallow until at last, gasping for "
+ "breath, you find that your feet can touch the bottom. You continue "
+ "advancing up a steep slope, this time walking instead of "
+ "swimming, until the water is only ankle deep. You gather your "
+ "thoughts together and take in your surroundings...\r\n\r\n"
+ "In every direction, you see dolphins and sharks swimming around"
+ " you.\r\n\r\n";

MESSAGE = MESSAGE
+ "Where will you go (n,s,e,w)? ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/E2.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = E2;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int WEST2()
{
if(choice[0] == 's' || choice[0] == 'n' || choice[0] == 'e' ||
choice[0] == 'w')
{
MESSAGE = "";

switch(choice[0])
{
case 's' : MESSAGE = MESSAGE
+ "You see... WHEAT!\r\n";
if(!FoundHP_West2)
{
MESSAGE = MESSAGE
+ "\r\nBuried under a mound among the wheat, you "
+ "find a healing potion!\r\n";
CurrentPlayer->setHealingPotion(1);
FoundHP_West2 = true;
CurrentPlayer->Inventory();
}
else
{
MESSAGE = MESSAGE
+ "\r\nYou already found the healing potion!\r\n";
}
break;
case 'n' : if(!CurrentPlayer->getLongBow())
{
MESSAGE = MESSAGE
+ "\r\nYou find a well-stringed long bow and arrows!\r\n";
CurrentPlayer->setLongBow(true);
CurrentPlayer->Inventory();
}
else
{
MESSAGE = MESSAGE
+ "\r\nYou already found the long bow.\r\n";
}
break;
case 'e' : location = W1; break;
case 'w' : MESSAGE = MESSAGE
+ "\r\nYou see various feed crops planted in rows.\r\n"; break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n"; break;
}//close switch

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\nYou find yourself walking in golden fields of billowing "
+ "wheat. The wind is blowing briskly through the long, tall "
+ "stalks as they rustle in the autumn air. Particles of chaff "
+ "float through the air all around you and collect upon "
+ "your clothing.\r\n\r\n";

MESSAGE = MESSAGE
+ "Where will you go (n,s,e,w)? ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/W2.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = W2;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int SHAMANHUT()
{
if(choice[0] == 'n' || choice[0] == 'l' || choice[0] == 's' ||
choice[0] == 't')
{
MESSAGE = "";
switch(choice[0])
{
case 'n' : MESSAGE = MESSAGE
+ "You run into a straw-mud wall.\n"; break;
case 'l' : location = S1; break;
case 's' : LockButtons(true); pHEAL->EnableWindow(false);
AFunctionPointer1();
MESSAGE = MESSAGE
+ "\r\n\r\nYou get the uneasy feeling that you are going "
+ "to reap serious bad karma for this unwise action.\r\n";
pOutput->SetWindowText(MESSAGE);

XSleep(5000);

MESSAGE = MESSAGE
+ "\r\nBellowing thunder cracks and the clouds darken the "
+ " skies outside as the deity of the temple preistess fills"
+ " with indignation and anger!\r\n";
pOutput->SetWindowText(MESSAGE);

XSleep(5000);

MESSAGE = MESSAGE
+ "\r\nIn an instant, lighting from the heavens strikes you "
+ "down! All that remains of you are burning embers...\r\n";

PlaySound(L"media/thunder.wav",NULL,SND_FILENAME|SND_ASYNC);
pOutput->SetWindowText(MESSAGE);
CurrentPlayer->setHit(0);
CurrentPlayer->DisplayStats();

XSleep(6000);

MESSAGE = MESSAGE
+ "\r\nYou go into the afterlife a loser, ashamed "
+ "for the despicable deeds you have done. The warriors "
+ "who have gone on before you, the great warriors of "
+ "reknown and the kings of the past will ridicule you "
+ "for all of eternity for dieing without honor.\r\n";

pOutput->SetWindowText(MESSAGE);

XSleep(13000);

LockButtons(false);
location = GAMEOVER;
break;
case 't' : MESSAGE = MESSAGE
+ "You seek audience with the preistess.\r\n";
WiseWoman->Talk();
break;
default : MESSAGE = MESSAGE
+ "That was an invalid choice.\r\n";
break;
}//close switch

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
MESSAGE = "";
LOCK = true;

if(FirstTimeInShamanHut)
{
MESSAGE = MESSAGE
+ "\r\nYou duck down and enter into the Shaman's hut. Towards the center "
+ "of the mud dwelling, beneath an overhanging shelf descending from the "
+ "thatched roof, sits an elderly priestess. Unphased by your presence, "
+ "she continues to stare into the flames of a small fire burning within "
+ "a set of blackened stone rings in the center of the hut. Directly over "
+ "her head, an opening in the ceiling allows the smoke to escape.\r\n"
+ "\r\nShe gazes at you and cackles. \"Not expecting an old temple preistess, "
+ "were you, a woman, eh? Well, in this village, I'm the \"Shaman\".\r\n\r\n";

FirstTimeInShamanHut = false;
}

else
{
MESSAGE = MESSAGE
+ "\r\n\r\nYou re-enter the Shaman's hut. She turns her head in a peculiar "
+ "fashion and remarks, \"Back so soon, traveler?\" She offers you a cup "
+ "of freshly brewed tea, which you gladly accept to quench your thirst. ";

if(!FoundHP_Shaman)
{
MESSAGE = MESSAGE
+ "She opens her medicine bag and begins creating an acrid mixture of "
+ "herbs. She pours it into a vial and places it in your hand, saying "
+ "\"Drink this if you become wounded, my friend. It may restore "
+ "you to a measure of your former health and constitution.\"\r\n\r\n";
CurrentPlayer->setHealingPotion(1);
FoundHP_Shaman = true;
CurrentPlayer->Inventory();
}

else
{
MESSAGE = MESSAGE
+ "You feel a sense of debt and gratitude towards this "
+ "kind old woman, remembering the healing elixir she gave "
+ "you on your last visit.\r\n\r\n";
}
}//close else

MESSAGE = MESSAGE
+ "At this point, you may (l)eave the Shaman's hut, "
+ "(t)alk with her if you so desire, or try to (s)teal "
+ "her medicine bag and staff for what wonders they may "
+ "contain.\r\n";

MESSAGE = MESSAGE
+ "\r\n\r\nYou may: (l)eave (t)alk or (s)teal things ";

HBITMAP CenterPix = (HBITMAP) LoadImage(NULL,L"media/SHAMAN.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);

pView->SetBitmap(CenterPix );

pOutput->SetWindowText(MESSAGE);
location = SHAMAN;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int GateWay()
{
char NumberBuffer[10];

if(choice[0] == 'g')
{
pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}//end if

else
{
MESSAGE = "";
LOCK = true;

if(CurrentPlayer->getFishKey())
{
MESSAGE = MESSAGE
+ "\r\n\r\nFumbling around the gate, you find a slot to insert the "
+ "Fish key. The tablets and columns begin to rumble and shake. Large "
+ "stones rise, levitating off the ground, rearranging themselves.\r\n";
}

else
{
MESSAGE = MESSAGE
+ "\r\nYou look around, trying every nook and crevice, but can not "
+ "seem to find the means to open the gate, nor alter anything else "
+ "around it. You see what appears to be a key hole to one side. \r\n";
location = CENTER1;
}

if(CurrentPlayer->getFishKey() && CurrentPlayer->getScore() < 50)
{
MESSAGE = MESSAGE
+ "\r\nIt appears that, although you have the key, you lack enough "
+ "experience with the ways of this world to cause the gate to "
+ "function in any useful manner.\r\n";
location = CENTER1;
}

if(CurrentPlayer->getFishKey() && CurrentPlayer->getScore() >= 50)
{
MESSAGE = MESSAGE
+ "\r\nWith the experience you have gained since entering this "
+ "strange world, you manage to figure out the correct sequence of "
+ "actions to perform while turning the Fish key within the gate. "
+ "You hear a loud hiss followed by a dull hum as cascading beams of "
+ "light blind you from the opening dimensional portal.\r\n\r\n";

MESSAGE = MESSAGE
+ "You feel as though you have won a series of battles in a "
+ "long campaign, but that the war is far from being over. "
+ "Having made several new friends and vanquished many foes as "
+ "a soujourner in a strange land, you step through the gates, "
+ "uncertain yet hopeful that this may bring you one step closer "
+ "to home...";

MESSAGE = MESSAGE
+ "You win this campaign and end the game with:\r\n\r\n";

CurrentPlayer->DisplayStats();
CurrentPlayer->Inventory();

MESSAGE = MESSAGE
+ "\nCombat Experience Score: "
+ _itoa(CurrentPlayer->getScore(),NumberBuffer,10)
+ ".\r\n\r\n";

LOCK = false;
location = YOUWIN;
}

MESSAGE = MESSAGE
+ "\r\n\r\nType \"G\" and click \"GO\" to continue...\r\n\r\n";

pInput->SetWindowText(L"g");
pOutput->SetWindowText(MESSAGE);

return location;

}//end else

}//end function

//---------------------------------------------------------------------------------------------------------------------------

int UnderGroundPassage()
{
if(choice[0] == 'r' || choice[0] == 'l')
{
if(choice[0] == 'l') { location = DRAGONFIGHT; }
if(choice[0] == 'r') { location = N2; }

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}//end if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\n\r\nYou descend into the darkness underground...\r\n\r\n";

if(UNDERDragonPairAlive)
{
MESSAGE = MESSAGE
+ "Peeking around a corner, you see a large subterranean cavern. ";
MESSAGE = MESSAGE
+ "Scattered around its rocky walls are piles of bones from "
+ "both animals and men.\r\n";

MESSAGE = MESSAGE
+ "\r\n\r\nDo you want to (r)eturn to the castle above or "
+ "(l)ook for what created this macabre chamber of remains?\r\n\r\n";
}

else
{
MESSAGE = MESSAGE
+ "\r\nYou see a family of dead red dragons and the carnal "
+ "aftermath of your last great battle with these fierce and"
+ " worthy opponents.\r\n\r\nEnter \"r\" and click \"GO\" to"
+ " return up the stairs to the castle.";

pInput->SetWindowText(L"r");
}

pOutput->SetWindowText(MESSAGE);
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int DragonFight()
{
char NumberBuffer[10];

if(choice[0] == 'y' || choice[0] == 'n')
{
if(choice[0] == 'y')
{
Dragon * DragonFamily = new Dragon[5];

for(int x = 0; x < 5 && CurrentPlayer->getHit() > 0; x++)
{
MESSAGE = "";

MESSAGE = MESSAGE
+ "Dragon " + _itoa((x+1),NumberBuffer,10) + " of 5 attacks you!";

pOutput->SetWindowText(MESSAGE);

XSleep(3000);

location = Combat(&DragonFamily[x], UNDERGRND);
}

//Clean up DragonFamily objects on heap, set pointer to NULL
delete [] DragonFamily;
DragonFamily = 0;
UNDERDragonPairAlive = false;

MESSAGE = MESSAGE
+ "\r\n\r\nType \"G\" and click \"GO\" to continue...\r\n\r\n";

pInput->SetWindowText(L"g");

pOutput->SetWindowText(MESSAGE);

PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);
}

else
{
MESSAGE = MESSAGE
+ "\r\nIntelligently, you decide to run back up the stairs...\r\n";
location = N2;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
LOCK = true;
MESSAGE = MESSAGE
+ "\r\nYou see a family of 5 dragons. Stop and think about this a minute. "
+ "Are you sure you want to take on 5 dragons simultaneously? (y,n)";

AFunctionPointer2();
pOutput->SetWindowText(MESSAGE);
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int GiantFight()
{
char NumberBuffer[10];

if(choice[0] == 'y' || choice[0] == 'n')
{
if(choice[0] == 'y')
{
Giant * MotleyCrew = new Giant[3];
MESSAGE = MESSAGE
+ "All three giants charge you at once!\r\n\r\n";
for(int x = 0; x < 3 && CurrentPlayer->getHit() > 0; x++)
{
MESSAGE = "";
MESSAGE = MESSAGE
+ "Giant " + _itoa((x+1),NumberBuffer,10) + " of 3 attacks you!";

pOutput->SetWindowText(MESSAGE);

XSleep(3000);

location = Combat(&MotleyCrew[x], S2);
}
//Clean up after MotleyCrew - no dangling pointers
delete [] MotleyCrew; MotleyCrew = 0;
S2MotleyCrewAlive = false;

MESSAGE = MESSAGE
+ "\r\n\r\nType \"G\" and click \"GO\" to continue...\r\n\r\n";

pInput->SetWindowText(L"g");

pOutput->SetWindowText(MESSAGE);
PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);
}

else
{
MESSAGE = MESSAGE
+ "\r\nIntelligently, you decide to walk away...\r\n";
location = S2;
}

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;

}//close if

else
{
LOCK = true;
MESSAGE = MESSAGE
+ "Stop and think a moment. Are you really prepared "
+ "to fight 3 giants at the same time? (y,n)";

pOutput->SetWindowText(MESSAGE);
return location;
}

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int GiantCamp()
{
if(choice[0] == 'r' || choice[0] == 'l')
{
if(choice[0] == 'l' && S2MotleyCrewAlive) { location = GIANTFIGHT; }
if(choice[0] == 'r') { location = S2; }

pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}//end if

else
{
LOCK = true;
location = GIANTCAMP;
MESSAGE = "";

MESSAGE = MESSAGE
+ "\r\nYou approach the giant's camp at the edge "
+ "of the forest.\r\n\r\n";

if(S2MotleyCrewAlive)
{
MESSAGE = MESSAGE
+ "Through a clearing among the trees, you see ";
MESSAGE = MESSAGE
+ "3 giants dining upon what can only be human remains.\r\n";
}
else
{
MESSAGE = MESSAGE
+ "You stumble over the corpses of three dead giants.\r\n";
}

if(S2MotleyCrewAlive)
{
MESSAGE = MESSAGE
+ "\r\n\r\nDo you want to (r)eturn to the forest edge or "
+ "(l)ook for giants?\r\n\r\n";
}
else
{
MESSAGE = MESSAGE
+ "\r\n\r\nType \"r\" and click \"GO\" or click"
+ " on any direction button (N, S, E, W) to RETURN."
+ "\r\n\r\nThere is nothing here but death!\r\n\r\n";

pInput->SetWindowText(L"r");
}

pOutput->SetWindowText(MESSAGE);
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int Randy(int n)
{
int ResultRandom;
ResultRandom = (rand()%n) + 1;
return ResultRandom;
}
//---------------------------------------------------------------------------------------------------------------------------

int GameOver()
{
if(choice[0] == 'g')
{
if(StartedGame) { delete CurrentPlayer; CurrentPlayer = 0; }
StartedGame = false;
pSTART->EnableWindow(true);
pOutput->SetWindowText(MESSAGE);
LOCK = false;
Continue = false;
return location;
}//close if

else
{
MESSAGE = "";
LOCK = true;
pGO->EnableWindow(true);

MESSAGE = MESSAGE
+ "\r\n\r\nGame Over...\r\n\r\nEnter \"g\" and then click"
+ " \"GO\".\r\n\r\nYou may then press \"QUIT\" to exit the"
+ " game or \"START\" to begin a new game.";

PlaySound(L"media/mighty3.wav",NULL,SND_FILENAME|SND_ASYNC);

pInput->SetWindowText(L"g");

pOutput->SetWindowText(MESSAGE);
location = GAMEOVER;
return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded Combat Functions, one for Dragon and one for Giant.
//Takes the global enumerated constant "EVENTS" as one of its arguments.

int Combat(Dragon * m, EVENTS CurrentLocation)
{
char NumberBuffer[10];
LOCK = true;
LockButtons(true);

MESSAGE = MESSAGE
+ "\r\nMortal Combat!!!\r\n";

HBITMAP GiantPix = (HBITMAP) LoadImage(NULL,L"media/dragon.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
pView->SetBitmap(GiantPix);

while(CurrentPlayer->getHit() > 0 && m->getHit() > 0)
{
MESSAGE = "";

if(CurrentPlayer->getHit() > 0)
{
CurrentPlayer->Attack(m);
XSleep(3000);
}

if(m->getHit() > 0)
{
PlaySound(L"media/dragon.wav",NULL,SND_FILENAME|SND_ASYNC);
m->Attack(CurrentPlayer);
XSleep(3500);
}

CurrentPlayer->DisplayStats();
}

if(CurrentPlayer->getHit() <= 0)
{
MESSAGE = MESSAGE
+ "\r\n\r\nYou die, most tragically!\r\n";
MESSAGE = MESSAGE
+ "The Dragon wins the battle, having "
+ _itoa(m->getHit(),NumberBuffer,10) + " hitpoints left.\r\n";

LOCK = false;
LockButtons(false);
return GAMEOVER;
}

else
{
MESSAGE = MESSAGE
+ "\r\nYou vanquish your foe most valiantly!\r\n";
MESSAGE = MESSAGE
+ "The Dragon died, now having " + _itoa(m->getHit(),NumberBuffer,10)
+ " hitpoints.\r\n" + CurrentPlayer->getName() + " has "
+ _itoa(CurrentPlayer->getHit(),NumberBuffer,10)
+ " hitpoints left.\r\n\r\n";

//Every three opponents, increase player's attack and defense for experience
if( (ConqueredGiants + ConqueredDragons) == 3 ||
(ConqueredGiants + ConqueredDragons) == 6 ||
(ConqueredGiants + ConqueredDragons) == 9 ||
(ConqueredGiants + ConqueredDragons) == 11)
{
MESSAGE = MESSAGE
+ "Add 1 to your attack and 1 to your defense as a result of combat"
+ " experience acquired defeating your last three opponents.\r\n";

CurrentPlayer->setAttack((CurrentPlayer->getAttack() + 1));
CurrentPlayer->setDefense((CurrentPlayer->getDefense() + 1));
}

CurrentPlayer->setScore((CurrentPlayer->getScore() + 10));

MESSAGE = MESSAGE
+ "\r\n" + CurrentPlayer->getName() + "'s Current Score: "
+ _itoa(CurrentPlayer->getScore(),NumberBuffer,10)
+ ".\r\n";

CurrentPlayer->DisplayStats();
ConqueredDragons++;
Conquests();

MESSAGE = MESSAGE
+ "\r\n";

pOutput->SetWindowText(MESSAGE);
LOCK = false;
LockButtons(false);
return CurrentLocation;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int Combat(Giant * m, EVENTS CurrentLocation)
{
char NumberBuffer[10];
LOCK = true;
LockButtons(true);
MESSAGE = "";

MESSAGE = MESSAGE + "\r\nMortal Combat!!!\r\n";

HBITMAP GiantPix = (HBITMAP) LoadImage(NULL,L"media/giant.bmp",IMAGE_BITMAP,
0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
pView->SetBitmap(GiantPix);

while(CurrentPlayer->getHit() > 0 && m->getHit() > 0)
{
MESSAGE = "";

if(CurrentPlayer->getHit() > 0)
{
CurrentPlayer->Attack(m);
XSleep(3000);
}

if(m->getHit() > 0)
{
PlaySound(L"media/dragon.wav",NULL,SND_FILENAME|SND_ASYNC);
m->Attack(CurrentPlayer);
XSleep(3500);
}

CurrentPlayer->DisplayStats();
Conquests();

}

if(CurrentPlayer->getHit() <= 0)
{
MESSAGE = MESSAGE + "\r\n\r\nYou die, most tragically!\r\n";
MESSAGE = MESSAGE + "The Giant won the battle, having "
+ _itoa(m->getHit(),NumberBuffer,10)
+ " hitpoints left.\r\n";

LOCK = false;
LockButtons(false);
return GAMEOVER;
}

else
{
MESSAGE = MESSAGE + "\r\nYou vanquish your foe most valiantly!\r\n";

MESSAGE = MESSAGE + "The Giant died, now having "
+ _itoa(m->getHit(),NumberBuffer,10);

MESSAGE = MESSAGE + " hitpoints.\r\n" + CurrentPlayer->getName()
+ " has " + _itoa(CurrentPlayer->getHit(),NumberBuffer,10)
+ " hitpoints left.\r\n";

//Every three opponents, increase player's attack and defense for experience
if( (ConqueredGiants + ConqueredDragons) == 3 ||
(ConqueredGiants + ConqueredDragons) == 6 ||
(ConqueredGiants + ConqueredDragons) == 9 ||
(ConqueredGiants + ConqueredDragons) == 11)
{
MESSAGE = MESSAGE
+ "Add 1 to your attack and 1 to your defense as a result of combat"
+ " experience acquired defeating your last three opponents.\r\n";

CurrentPlayer->setAttack((CurrentPlayer->getAttack() + 1));
CurrentPlayer->setDefense((CurrentPlayer->getDefense() + 1));
}

CurrentPlayer->setScore((CurrentPlayer->getScore() + 10));

MESSAGE = MESSAGE
+ "\r\n" + CurrentPlayer->getName() + "'s Current Score: "
+ _itoa(CurrentPlayer->getScore(),NumberBuffer,10)
+ ".\r\n";

CurrentPlayer->DisplayStats();
ConqueredGiants++;
Conquests();

LOCK = false;
LockButtons(false);

return CurrentLocation;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

bool SaveCharacter()
{
CString CharacterName;
CString password;

pSaveName->GetWindowText(CharacterName);
CharacterName = CharacterName + ".gam";

pSavePassword->GetWindowText(password);

ofstream WriteStuff;
WriteStuff.open(CharacterName);

if(!WriteStuff)
{ return false; } //close if

else
{
//NOTE: We need to convert the CStrings to strings to write the data.
char PASSWORD[100] = " ";
for(int y = 0; y < password.GetLength(); y++)
{ PASSWORD[y] = password[y]; }

CString CHARACTERNAME = CurrentPlayer->getName();
char CHARNAME[100] = " ";
for(int z = 0; z < CHARACTERNAME.GetLength(); z++)
{ CHARNAME[z] = CHARACTERNAME[z]; }

//Simple serialization of Character class
WriteStuff << PASSWORD << "\n";
WriteStuff << CHARNAME << "\n";
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
WriteStuff << ConqueredDragons << "\n";
WriteStuff << ConqueredGiants << "\n";

WriteStuff.close();

return true;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

bool LoadCharacter(CString & problem)
{
string passwd;
string nm;
int hp, atk, def, lvl, scr, loc;
CString CharacterName;
CString pass;
bool dagger, sword, bow, mail, armor, healing, fkey;

pLoadName->GetWindowText(CharacterName);
CharacterName = CharacterName + ".gam";

ifstream ReadStuff;
ReadStuff.open(CharacterName);

//Detect if successful or not to keep program from crashing on failed load
if(!ReadStuff)
{
problem = "Can not find the file you typed in. Try a different name?";
return false;
}

else
{
pLoadPassword->GetWindowText(pass);
getline(ReadStuff, passwd);

//Need to convert the string to CString with .c_str()
if(pass == passwd.c_str())
{
//Careful! serialization = you must read in exactly the same order as you wrote!
//Have to use getline for nm since name may have spaces in it
getline(ReadStuff, nm); ReadStuff >> hp;
ReadStuff >> atk; ReadStuff >> def;
ReadStuff >> lvl; ReadStuff >> scr;
ReadStuff >> loc; location = loc;

ReadStuff >> dagger;
ReadStuff >> sword; ReadStuff >> bow;
ReadStuff >> mail; ReadStuff >> armor;
ReadStuff >> healing; ReadStuff >> fkey;

//Note: In VS 6.0 and .Net Visul Studio, you can read these as booleans
//with no problem. The problem is with Bloodshed - they will all read in
//as false. To make it compatible with Bloodshed (therefore all 3
//compilers) you must read them as integers and they will be cast to bools
//in VS 6.0 and .Net Visual Studio. (It ain't easy getting these 3 to agree).
bool giant, dragon, motley, shaman, center, under, HPwest2, HPshaman;
int CD, CG;

ReadStuff >> giant; W1GiantAlive = giant;
ReadStuff >> dragon; E1DragonAlive = dragon;
ReadStuff >> motley; S2MotleyCrewAlive = motley;
ReadStuff >> shaman; FirstTimeInShamanHut = shaman;
ReadStuff >> center; CENTERFirstTime = center;
ReadStuff >> under; UNDERDragonPairAlive = under;
ReadStuff >> HPwest2; FoundHP_West2 = HPwest2;
ReadStuff >> HPshaman; FoundHP_Shaman = HPshaman;
ReadStuff >> CD; ConqueredDragons = CD;
ReadStuff >> CG; ConqueredGiants = CG;

//Example: Memberwise copy of string to character array for CString
//char x[25] = "Weeeeee";
//for(int a = 0; a < nm.length(); a++) { x[a] = nm[a]; }
//OR just use .c_str()

CurrentPlayer->setName(nm.c_str());
CurrentPlayer->setHit(hp);
CurrentPlayer->setAttack(atk);
CurrentPlayer->setDefense(def);
CurrentPlayer->setLevel(lvl);
CurrentPlayer->setScore(scr);
CurrentPlayer->setDagger(dagger);
CurrentPlayer->setSword(sword);
CurrentPlayer->setLongBow(bow);
CurrentPlayer->setChainMail(mail);
CurrentPlayer->setFullBodyArmor(armor);
CurrentPlayer->setHealingPotion(healing);
CurrentPlayer->setFishKey(fkey);

ReadStuff.close();
CurrentPlayer->Inventory();
CurrentPlayer->DisplayStats();
NeedName = false;
Conquests();
pName->SetWindowText(CurrentPlayer->getName());
PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);

return true;

}//close if

else
{
problem = "An incorrect password was entered. Re-enter it please.";
return false;
}

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

bool SaveHighScores()
{
bool successful;

//Open highscores if is exists and count the # scores
ofstream highscores("highscores.txt", ios::app);

CString CHARACTERNAME = CurrentPlayer->getName();
char CHARNAME[100] = " ";
for(int z = 0; z < CHARACTERNAME.GetLength(); z++)
{ CHARNAME[z] = CHARACTERNAME[z]; }

highscores << CHARNAME << "\n";
highscores << CurrentPlayer->getScore() << "\n";

highscores.close();

return successful;

}//close function

//---------------------------------------------------------------------------------------------------------------------------

void DisplayHighScores()
{
char NumberBuffer[10];
MESSAGE = "";
pOutput->SetWindowText(MESSAGE);

string HoldMeString; int HoldMeInt, z, x = 0;

ifstream highscores("highscores.txt");

if (!highscores)
{
MESSAGE = MESSAGE + "Unable to find \"highscores.txt\" for reading.\r\n";
pOutput->SetWindowText(MESSAGE);
}

else
{ //Note: When using getline() in a for loop, you must use getline() again
//right after reading the integer in to consume the '\n' left in the
//data stream. We don't have to have this extra getline() in the
//LoadCharacter() function because getline() is not in a loop there.
while(!highscores.eof())
{
getline(highscores, HoldMeString);
highscores >> HoldMeInt;
getline(highscores, HoldMeString);
x++; //add one for every 2 lines (name and score pair)
}

x = x - 1; //Subtract 1 for the offset (one too many)

//Declare 2 Parallel Arrays where # elements = # lines. We could
// have also used only 1 array here with a structure containing
//a string and an integer component as a single object. Example:

//NameAndScore { string n; int s; }; //defines structure, sort of like a class
//NameAndScore HIGHSCORE[x]; //creates array of objects defined as "NameAndScore"
//if(HIGHSCORE[r].s > HIGHSCORE[r - 1].s)
//{ TempHIGHSCORE = HIGHSCORE[r]; HIGHSCORE[r] = HIGHSCORE[r - 1];

//Note: If compiling this with Visual Studio .Net, it will flag the array
//declarations below as an error. It does not allow dynamically sizing them
//at run time as BloodShed does. So just change the 2 lines below:
//from string NAMES[x]; to string NAMES[100];
//from int SCORES[x]; to int SCORES[100];
string NAMES[100];
int SCORES[100];

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
//0 = 100
//1 = 75
//2 = 50
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

MESSAGE = MESSAGE
+ " *************** High Scores **************\r\n";
MESSAGE = MESSAGE
+ " -------------------------------------------"
+ "-----------------\r\n";

for(z = 0; z < x; z++)
{
MESSAGE = MESSAGE
+ " "
+ _itoa((z+1),NumberBuffer,10)
+ ". Name: " + NAMES[z].c_str()
+ " " + "Score: " + _itoa(SCORES[z],NumberBuffer,10)
+ "\r\n";

MESSAGE = MESSAGE
+ " -------------------------------------------"
+ "-----------------\r\n";
}

MESSAGE = MESSAGE
+ " *****************************************\r\n";
MESSAGE = MESSAGE
+ "\r\n";
MESSAGE = MESSAGE
+ " Click HighScores again to return to the game and\r\n"
+ " continue playing.";

pOutput->SetWindowText(MESSAGE);

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

void Conquests()
{
char NumBuffer[10];
CONQUESTS = "";

if(ConqueredGiants == 0 && ConqueredDragons == 0)
{
CONQUESTS = CONQUESTS
+ "You're special. You haven't fought anything at all. "
+ "Beware! Treacherous paths unwind before you...";
}

if(ConqueredGiants > 0)
{
if(ConqueredGiants == 1)
{
CONQUESTS = CONQUESTS
+ "You have defeated a single, lone Giant.\r\n";
}
else
{
CONQUESTS = CONQUESTS
+ "You have defeated " + _itoa(ConqueredGiants,NumBuffer,10)
+ " Giants in battle.\r\n";
}
}


if(ConqueredDragons > 0)
{
if(ConqueredDragons == 1)
{
CONQUESTS = CONQUESTS
+ "You have defeated a single, lone Dragon.\r\n";
}
else
{
CONQUESTS = CONQUESTS
+ "You have defeated " + _itoa(ConqueredDragons,NumBuffer,10)
+ " Dragons in battle.\r\n";
}
}

if(ConqueredDragons == 0)
{
CONQUESTS = CONQUESTS
+ "You have not battled any Dragons yet.\r\n";
}


if(ConqueredGiants == 0)
{
CONQUESTS = CONQUESTS
+ "You have not battled any Giants yet.\r\n";
}

pConquests->SetWindowText(CONQUESTS);

}//close function

//---------------------------------------------------------------------------------------------------------------------------

int YouWin()
{
if(choice[0] == 'g')
{
location = QUIT;
pOutput->SetWindowText(MESSAGE);
LOCK = false;
return location;
}//close if

else
{
MESSAGE = "";
LOCK = true;

MESSAGE = MESSAGE
+ "\r\n\r\nGood fortune is yours this day, and you stand "
+ "over fallen foes, victorious and triumphant!";
MESSAGE = MESSAGE
+ "\r\n\r\nYou have fought well and finished the game!\r\n\r\n"
+ "Enter \"g\" and click \"GO\"\r\n"
+ "or click \"QUIT\" to exit the program.";

PlaySound(L"media/mighty3.wav",NULL,SND_FILENAME|SND_ASYNC);

pOutput->SetWindowText(MESSAGE);
location = YOUWIN;

return location;

}//close else

}//close function

//---------------------------------------------------------------------------------------------------------------------------

void LockButtons(bool x)
{
//Safety lock all command buttons during combat except
//for the radio buttons being used in combat
if(x == true)
{
pN->EnableWindow(false);
pS->EnableWindow(false);
pE->EnableWindow(false);
pW->EnableWindow(false);
pSCORES->EnableWindow(false);
pSAVE->EnableWindow(false);
pLOAD->EnableWindow(false);
pSTART->EnableWindow(false);
pGO->EnableWindow(false);
pACTION->EnableWindow(false);
}

else
{
pN->EnableWindow(true);
pS->EnableWindow(true);
pE->EnableWindow(true);
pW->EnableWindow(true);
pSCORES->EnableWindow(true);
pSAVE->EnableWindow(true);
pLOAD->EnableWindow(true);
pSTART->EnableWindow(true);
pGO->EnableWindow(true);
pACTION->EnableWindow(true);
}
}

//---------------------------------------------------------------------------------------------------------------------------













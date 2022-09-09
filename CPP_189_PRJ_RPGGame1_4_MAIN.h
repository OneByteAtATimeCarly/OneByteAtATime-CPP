//PRJ - RPGGame1 - Main File - 2006 - C. S. Germany
//Hills of Darkness (HOD) C. S. Germany, March 16, 2007
//File 4 of 4


//---------------------------------------------------------------------------------------------------------------------------

//Main File


//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_186_PRJ_RPGGame1_1_GLOBALS.h"
#include "CPP_187_PRJ_RPGGame1_2_CLASSES.h"
#include "CPP_188_PRJ_RPGGame1_3_FUNCTIONS.h"

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    srand(time(NULL));
    location = INTRO;

    string choice = "";
    
    cout << "\n\tHills of Darkness 2.0 - 2006 C. Germany";
    
    while(choice[0] != 'q')
    {
        cout << "\n\n\n\n\t----------Main Menu----------\n"
             << "\n\t(N)ew Game"
             << "\n\t(L)oad Game"
             << "\n\t(Q)uit\n\n\t";
             
        cin >> choice;
        choice[0] = tolower(choice[0]);
        
        switch(choice[0])
        {
            case 'n' : Setup_Character(); 
                       while(location != QUIT)
                       {
                           SwitchBoard();       
                       }
                       cout << "\n\tEnding game...";
                       //Don't save HighScores unless they created a player
                       if(The_Player) { SaveHighScores(); }
                       delete The_Player;
                       The_Player = 0;
                       location = INTRO;   //reset location for next game
                       break;
            case 'l' : LoadCharacter();

                       if(The_Player)
                       {
                            while(location != QUIT)
                            {
                               SwitchBoard();       
                            }
                       }
                       else
                       { cout << "\n\tCould not find that character object!"; }
                       break;
            case 'q' : break;
            default : cout << "\n\tInvalid input!";        
        }                    
    }
    

    cout << "\n\tClosing program...";
    cout << "\n\n\n\t";
    PAUSE();
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



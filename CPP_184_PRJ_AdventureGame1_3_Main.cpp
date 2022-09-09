//PRJ - AdventureGame1 - Main File - 2004 - C. S. Germany
//File 3 of 3

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_182_PRJ_AdventureGame1_1_Classes.h"
#include "CPP_183_PRJ_AdventureGame1_2_Functions.h"

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int location;
    Continue = true; 
    InitializeGlobals();
    bool successful;
    
    //Create a new Player object on the heap
    Character * CurrentPlayer = new Character();
    CurrentPlayer->AskName();
    
    //Create a Shaman on the heap, in main on heap for continuance
    Shaman * WiseWoman = new Shaman;
    
    Introduction();
    location = CENTER(CurrentPlayer);
    
    while(Continue)
    {          
        switch(location)
        {
           case N1 : location = NORTH1(CurrentPlayer); break;
           case S1 : location = SOUTH1(CurrentPlayer); break;
           case E1 : location = EAST1(CurrentPlayer); break;
           case W1 : location = WEST1(CurrentPlayer); break;
           case CENTER1 : location = CENTER(CurrentPlayer); break;
           case N2 : location = NORTH2(CurrentPlayer); break;
           case S2 : location = SOUTH2(CurrentPlayer); break;
           case E2 : location = EAST2(CurrentPlayer); break;
           case W2 : location = WEST2(CurrentPlayer); break;
           case UNDERGRND : location = UnderGroundPassage(CurrentPlayer); break;
           case GATE : location = GateWay(CurrentPlayer); break;             
           case SHAMAN : location = SHAMANHUT(CurrentPlayer, WiseWoman); break;          
           case QUIT : Continue = false; break;
           default : cout << "Not an option."; break;                       
        }   
    }  
    
    //Clean Up After Player Object And Save HighScore
    successful = SaveHighScores(CurrentPlayer);
    if(successful)
    {  
       cout << "\n\tScore saved to \"highscores.txt\".\n\n";
    }
    else 
    { 
       cout << "\n\tError. Score could not be saved!\n\n"; 
    }
    
    delete CurrentPlayer; CurrentPlayer = 0;
    delete WiseWoman, WiseWoman = 0;
    
    cout << "\n\tExiting Hills of Darkness 2.0\n\n\n";    
    cout<< "\t"; system("PAUSE");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



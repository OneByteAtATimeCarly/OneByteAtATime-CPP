//PRJ - MegaPet1 - Main File - 2006 - C. S. Germany
//File 3 of 3


//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_191_PRJ_MegaPet1_1_CLASSES.h"

Pet * ThePet;       //Need pointer to MegaPet object on heap to pass to functions and class member methods

#include "CPP_192_PRJ_MegaPet1_2_FUNCTIONS.h"

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    srand(time(NULL));
    GlobalX = 0;
    Hours = 1;
    CreatedPet = false;
    
    cout << "\n\n\n\n\n\n\t\tWelcome to MegaPet 1.0!"
         << "\n\t\t   C. Germany - 2007\n\n\n\n\n\n\n\n\t\t";  
    system("PAUSE");
    
    Information();   
 
    char choice[10];
    
    while(choice[0] != 'q')
    {
        cout << "\n\n\t\t\t******* MegaPet Menu *******"
             << "\n\t\t\t*                          *"
             << "\n\t\t\t*    (C)reate a Pet        *"
             << "\n\t\t\t*    (L)oad a Pet          *"
             << "\n\t\t\t*    (S)ave a Pet          *"
             << "\n\t\t\t*    (I)nteract with Pet   *"
             << "\n\t\t\t*    (Q)uit                *"
             << "\n\t\t\t*                          *"
             << "\n\t\t\t****************************\n\n\t\t\t"; 
             
        cin >> choice;
        choice[0] = tolower(choice[0]);
        system("CLS");
        
        switch(choice[0])
        {
            case 'c' : if(!CreatedPet) { CreatePet(); } 
                       else { cout << "\n\t\tYou already created a pet!"; } break; 
            case 'l' : LoadPet(); break; 
            case 's' : SavePet(); break; 
            case 'i' : if(CreatedPet) { Interact(); }
                       else { cout << "\n\t\tYou need to create a pet first!"; }
                       break; 
            case 'q' : cout << "\n\t\tQuitter!"; break; 
            default : cout << "\nSorry, that was not an option.\n";   
        }  
        
        if(CreatedPet)
        {
            if(ThePet->GetHealth() == 0) 
            { break; }
        }                
    }
    
    if(CreatedPet)
    {
         if(ThePet->GetHealth() == 0)
         {
             cout << "\n\n\t\tYour pet has died!";
             
             if(ThePet->GetHunger() >= 3) 
             { cout << "\n\n\t\tIt was starving to death due to your neglect!"; }
             
             if(ThePet->GetEnergyLevel() < 4) 
             { cout << "\n\n\t\tIt was completely exhausted and needed rest!"; }
             
             if(ThePet->GetHunger() >= 3 && ThePet->GetEnergyLevel() < 4)
             { 
                 cout << "\n\n\t\tYou are especially cruel and despicable!"; 
                 cout << "\n\t\tYou were not worthy of a MegaPet, you fiend!";
             }
                                    
         }
                  
         delete ThePet;
         ThePet = 0;
    }
    
    cout << "\n\t\tExiting MegaPet 1.0 ...\n\n\t\t";  
      
    cout << "\n\t\t"; system("PAUSE");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


//PRJ - Checkers Game Console - 2006 - C. S. Germany
//File 4 of 4: Main File

//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_205_PRJ_Checkers_1_GLOBALS.h"
#include "CPP_206_PRJ_Checkers_2_CLASSES.h"
#include "CPP_207_PRJ_Checkers_3_FUNCTIONS.h"

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    CONTINUE = true;
    
    cout << "\n\n Welcome to Checkers 1.0... \n";
    
    while(CONTINUE != false)
    {
        MainMenu();    
    }    
    
    cout << "\n\n Exiting Checkers 1.0... \n\n  ";
    system("PAUSE");

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------











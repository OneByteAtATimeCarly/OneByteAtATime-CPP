//PRJ - Checkers Game Console - 2006 - C. S. Germany
//File 3 of 4: FUNCTIONS

//---------------------------------------------------------------------------------------------------------------------------

void MainMenu()
{
     string INPUT = " ";
     
     while(INPUT[0] != 'b' &&
           INPUT[0] != 'h' &&
           INPUT[0] != 's' &&
           INPUT[0] != 'l' &&
           INPUT[0] != 'e')
     {
     
         cout << "\n\n   ----------Checkers Main Menu----------" 
              << "\n   |                                    |"
              << "\n   |         (P)lay New Game            |"
              << "\n   |         (H)elp                     |"
              << "\n   |         (S)ave a Game              |" 
              << "\n   |         (L)oad a Game              |"
              << "\n   |         (E)xit Game                |"
              << "\n   |                                    |"
              << "\n   --------------------------------------\n\n   "; 
         
         cin >> INPUT;
     
         INPUT[0] = tolower(INPUT[0]);
     
         switch(INPUT[0])
         {
              case 'h' : break;
              case 's' : break;
              case 'l' : break;
              case 'p' : PlayGame(); break;
              case 'e' : CONTINUE = false; 
                         break;
              default: cout << "\n\n  Invalid response!\n"; 
                       break;     
         }
     
     }
}

//---------------------------------------------------------------------------------------------------------------------------

void Begin()
{ 
     string GameType = "";
     string NAME = "Anonymous";
     string ColorChoice = " ";    
     
     PLAYA_ONE = new Player();
     PLAYA_TWO = new Player();
     
     CreateBoard();

     Sleep(1000);
     
     system("CLS");
     
     while(GameType[0] != 'p' &&  GameType[0] != 'c')
     {
           cout << "\n\n\n     Who you wish to play? "
                << "\n\n     (C)omputer\n"
                << "\n     (P)layer\n\n     ";
           
           cin >> GameType;
           
           GameType[0] = tolower(GameType[0]);
           
           system("CLS");
           
           switch(GameType[0])
           {
               case 'c' : cout << "\n\n\n   What is your name, player?   ";
                          cin >> NAME;
                          PLAYA_ONE->SetPlayerName(NAME);
                          PLAYA_TWO->SetPlayerName("Computer");
                          
                          ColorChoice = " ";
     
                          while(ColorChoice[0] != 'r' &&  ColorChoice[0] != 'b')
                          {
                             cout << "\n\n   Do you want to be RED or BLACK?  ";
                             cin >> ColorChoice;
          
                             ColorChoice[0] = tolower(ColorChoice[0]);
          
                             switch(ColorChoice[0])
                             {
                                 case 'r' : cout << "\n\n\n   " << NAME 
                                                 << " chooses RED. Therefore the Computer is BLACK."; 
                                            PLAYA_ONE->SetPlayerColor(RED);
                                            PLAYA_TWO->SetPlayerColor(BLACK);
                                            break;
                                 case 'b' : cout << "\n\n\n   "<<  NAME 
                                                 << " chooses BLACK. Therefore the Computer is RED."; 
                                            PLAYA_ONE->SetPlayerColor(BLACK);
                                            PLAYA_TWO->SetPlayerColor(RED);
                                            break;  
                                 default : cout << "\n\n   Invalid response. Choose RED or BLACK.\n";
                                            break;             
                             }
                          }
                          
                          break;
//---------------------------------------------------------------------------------------                          
               case 'p' : cout << "\n\n   Player 1, what is your name?   ";
                          cin >> NAME;
                          PLAYA_ONE->SetPlayerName(NAME);
                          
                          cout << "\n\n   Player 2, what is your name?   ";
                          cin >> NAME;
                          PLAYA_TWO->SetPlayerName(NAME);
                          
                          ColorChoice = " ";
     
                          while(ColorChoice[0] != 'r' &&  ColorChoice[0] != 'b')
                          {
                             cout << "\n\n   " << PLAYA_ONE->GetPlayerName() 
                                  << ", do you want to be RED or BLACK?  ";
                                  
                             cin >> ColorChoice;
          
                             ColorChoice[0] = tolower(ColorChoice[0]);
          
                             switch(ColorChoice[0])
                             {
                                 case 'r' : cout << "\n\n\n   " << PLAYA_ONE->GetPlayerName() 
                                                 << " chooses RED. " 
                                                 << PLAYA_TWO->GetPlayerName() 
                                                 << " is therefore BLACK."; 
                                            PLAYA_ONE->SetPlayerColor(RED);
                                            PLAYA_TWO->SetPlayerColor(BLACK);
                                            break;
                                 case 'b' : cout << "\n\n\n   " << PLAYA_ONE->GetPlayerName() 
                                                 << " chooses BLACK. " 
                                                 << PLAYA_TWO->GetPlayerName() 
                                                 << " is therefore RED."; 
                                            PLAYA_ONE->SetPlayerColor(BLACK);
                                            PLAYA_TWO->SetPlayerColor(RED);
                                            break;  
                                 default : cout << "\n   Invalid response. Choose RED or BLACK.\n";
                                            break;             
                             }
                          }
                          break;
               default : cout << "\n   Invalid response!\n";
                         break;    
           }//close switch   
             
     }//close while true loop

     Sleep(2000);

}//close function

//---------------------------------------------------------------------------------------------------------------------------

void CreateBoard()
{
     bool blank = false;
     
         //X = Horizontal Rows moving across
         //Y = Vertical Rows moving down
         
         //Create first three rows (RED)
         for(int ROWS = 0; ROWS < 3; ROWS++)
         {
             for(int x = 0; x < 8; x++)
             {
                if(!blank)
                { 
                   CheckerBoard[ROWS][x] = new Checker(RED);
                   blank = true;  
                }
                else
                {
                   CheckerBoard[ROWS][x] = new Checker(BLANK);
                   blank = false; 
                }  
             }
             
             if(!blank) { blank = true; }
             else { blank = false; }                 
         }
             
         //Create next two rows of blanks
         for(int ROWS = 3; ROWS < 5; ROWS++)
         {
             for(int x = 0; x < 8; x++)
             {             
                 CheckerBoard[ROWS][x] = new Checker(BLANK);
             }    
         }
         
         //Create last three rows
         blank = true;
         
         for(int ROWS = 5; ROWS < 8; ROWS++)
         {
             for(int x = 0; x < 8; x++)
             {
                if(!blank)
                { 
                   CheckerBoard[ROWS][x] = new Checker(BLACK);
                   blank = true;  
                }
                else
                {
                   CheckerBoard[ROWS][x] = new Checker(BLANK);
                   blank = false; 
                }  
             }
             
             if(!blank) { blank = true; }
             else { blank = false; }                 
         }                     
}

//---------------------------------------------------------------------------------------------------------------------------

void DisplayBoard()
{ 
      system("CLS");
      string PLAYER;
      
      cout << "\n\n\n                     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |"
           << "\n                  ------------------------------------"
           << "\n                    ";
           
      //Rows
      for(int ROW = 0; ROW < 8; ROW++)
      {
          cout << (ROW+1);
          //Columns
          for(int COLUMN = 0; COLUMN < 8; COLUMN++)
          { 
              cout << "|" << CheckerBoard[ROW][COLUMN]->TYPE(); 
          }
          
          cout << "|\n                   ";
          cout << "--|-------------------------------|";
          cout << "\n                    ";
      }    
      
      cout.setf(ios::fixed);
      
      PLAYER = PLAYA_ONE->GetPlayerName() + ":";
      
      switch(PLAYA_ONE->GetPlayerColor())
      {
            case RED : PLAYER = PLAYER + "RED"; break;
            case BLACK : PLAYER = PLAYER +  "BLACK"; break; 
      } 
      
      cout  << left << setw(15) << PLAYER
            << "          Score:" << PLAYA_ONE->GetPlayerScore();
      
      //---------------------------------------------------------
      
      cout << "\n                    ";
      
      PLAYER = PLAYA_TWO->GetPlayerName() + ":";
      
      switch(PLAYA_TWO->GetPlayerColor())
      {
            case RED : PLAYER = PLAYER + "RED"; break;
            case BLACK : PLAYER = PLAYER +  "BLACK"; break; 
      } 
      
      cout  << left << setw(15) << PLAYER
            << "          Score:" << PLAYA_TWO->GetPlayerScore();     

}

//---------------------------------------------------------------------------------------------------------------------------

void PlayGame()
{
     KeepPlaying = true;
     string choice = "";
     
     Begin();
     
     DisplayBoard();     

     while(KeepPlaying)
     {
         SelectChecker(PLAYA_ONE->GetPlayerColor(),PLAYA_ONE->GetPlayerName());
         cout << "\n\n   " << PLAYA_ONE->GetPlayerName() 
              << "'s move has been completed.";
              
         Sleep(1000);     
         
         if(KeepPlaying)
         {
            SelectChecker(PLAYA_TWO->GetPlayerColor(),PLAYA_TWO->GetPlayerName());
            cout << "\n\n   " << PLAYA_TWO->GetPlayerName() 
                 << "'s move has been completed.";        

         }
         
         Sleep(1000);  
         
     }//close outer while   

}

//---------------------------------------------------------------------------------------------------------------------------

void SelectChecker(int COLOR, string NAME)
{    
     string INPUT = "";
     char NUM;
     char * pNUM;
     pNUM = &NUM;
     int CurrentPosition[2];  //COL, ROW
     
     while(CurrentPosition[0] < 1 || CurrentPosition[0] > 8 ||
           CurrentPosition[1] < 1 || CurrentPosition[1] > 8)
     {
         DisplayBoard();
         
         cout << "\n\n  " << NAME << ", which CHECKER do you wish to move? (\"q\"=quit)"
              << "\n   Example: 11 = (COLUMN 1 ROW 1):   ";
          
         cin >> INPUT;
         
         if(INPUT[0]=='q') 
         { 
            KeepPlaying = false; 
            return;
         }
     
         NUM = INPUT[0];
         CurrentPosition[0] = atoi(pNUM);
         NUM = INPUT[1];
         CurrentPosition[1] = atoi(pNUM);

         if(CurrentPosition[0] < 1 || CurrentPosition[0] > 8 ||
            CurrentPosition[1] < 1 || CurrentPosition[1] > 8)
         {
            cout << "\n   That was an invalid choice! Outside available range.";
            Sleep(2000);   
         }
         else
         {
              if(CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->GetColor() == BLANK) 
              {
                  cout << "\n   There is no checker at that location!";
                  Sleep(2000);
                  CurrentPosition[0] = 0;                                                                  
              }
              else
              {
                   if(COLOR == RED)
                   {  
                       if(CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->GetColor() == BLACK)
                       {
                           cout << "\n   Can't move your opponent's black CHECKER, move your own cheater!";
                           Sleep(2000);
                           CurrentPosition[0] = 0;                                                                     
                       }
                       else
                       {  
                           if(CurrentPosition[1] < 2)
                           {
                                  if(CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLANK &&
                                     CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLACK)
                                  {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                                  }
                                  else
                                  {
                                     cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                         << " COL=" << CurrentPosition[1];
                                     Sleep(1000);
                                     CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                     DisplayBoard();
                                                                            
                                  }                                                        
                           }
                           else if(CurrentPosition[1] > 7)
                           {
                                  if(CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLANK &&
                                     CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLACK)
                                  {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                                  }
                                  else
                                  {
                                     cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                          << " COL=" << CurrentPosition[1];
                                     Sleep(1000);
                                     CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                     DisplayBoard();
                                                                           
                                  }                                                        
                           }                                                     
                           else
                           {
                               if(CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLANK &&
                                  CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLANK &&
                                  CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLACK &&
                                  CheckerBoard[(CurrentPosition[0]-1) + 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLACK)
                               {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                               }
                               else
                               {
                                   cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                        << " COL=" << CurrentPosition[1];
                                   Sleep(1000);
                                   CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                   DisplayBoard();
                                                                   
                               }//close else inner
                               
                           }//close else MIDDLE 
                       }
                   }       
                                                         
                   else if(COLOR == BLACK)
                   {
                       if(CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->GetColor() == RED)
                       {
                           cout << "\n   Can't move your opponent's red CHECKER, move your own cheater!";
                           Sleep(2000);
                           CurrentPosition[0] = 0;                                                                     
                       }
                       else
                       {
                           if(CurrentPosition[1] < 2)
                           {
                                  if(CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLANK &&
                                     CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) + 1]->GetColor() != RED )
                                  {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                                  }
                                  else
                                  {
                                     cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                         << " COL=" << CurrentPosition[1];
                                     Sleep(1000);
                                     CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                     DisplayBoard();
                                                                            
                                  }                                                        
                           }
                           else if(CurrentPosition[1] > 7)
                           {
                                  if(CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLANK &&
                                     CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) - 1]->GetColor() != RED)
                                  {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                                  }
                                  else
                                  {
                                     cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                          << " COL=" << CurrentPosition[1];
                                     Sleep(1000);
                                     CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                     DisplayBoard();
                                                                           
                                  }                                                        
                           }                                                     
                           else
                           {
                               if(CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) + 1]->GetColor() != BLANK &&
                                  CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) - 1]->GetColor() != BLANK &&
                                  CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) + 1]->GetColor() != RED &&
                                  CheckerBoard[(CurrentPosition[0]-1) - 1][(CurrentPosition[1]-1) - 1]->GetColor() != RED)
                               {
                                       cout << "\n  Blocked!"
                                            << "\n  If you selected this piece you would be trapped!";
                                       Sleep(2000);
                                       CurrentPosition[0] = 0;
                               }
                               else
                               {
                                   cout << "\n\n\n   You select:  ROW=" << CurrentPosition[0] 
                                        << " COL=" << CurrentPosition[1];
                                   Sleep(1000);
                                   CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(true);
                                   DisplayBoard();
                                                                   
                               }//close else inner
                               
                           }//close else MIDDLE  
                                                                        
                     }//close outer else  
                     
                   }//close if for COLOR BLACK             
                                                                                                       
              }//close if not blank
         }//close if not outside range       
     }//close while true loop       
     
   //----------------------------------------------   
  
     INPUT = "";    
     bool CanYaJump;
     
     while(INPUT[0] != 'm' && INPUT[0] != 'a')
     {
         cout << "\n\n   Now that you have selected a checker,\n"
              << "   what do you want to do with it?\n\n"
              << "   (M)ove Checker to Another Location\n"
              << "   (A)ttempt to Jump Your Opponent's Checker\n\n   ";
          
         cin >> INPUT;
         INPUT[0] = tolower(INPUT[0]);
     
         switch(INPUT[0])
         {
            case 'm' : MoveChecker(CurrentPosition, COLOR, NAME); break;
            case 'a' : CanYaJump = JumpChecker(CurrentPosition, COLOR, NAME);
                       if(!CanYaJump)
                       { 
                           MoveChecker(CurrentPosition, COLOR, NAME); 
                       }
                       else
                       { 
                           cout << "\n\n   Finshed JUMP!"; 
                       }
                       break;
            default: cout << "\n\n   Invalid response."; break;          
         }     
     }
     
}//close function

//---------------------------------------------------------------------------------------------------------------------------

void MoveChecker(int CurrentPosition[2], int COLOR, string NAME)
{
     string INPUT = "";
     char NUM;
     char * pNUM;
     pNUM = &NUM;     
     int DestinationPosition[2]; //COL, ROW

     while(DestinationPosition[0] < 1 || DestinationPosition[0] > 8 ||
           DestinationPosition[1] < 1 || DestinationPosition[1] > 8)
     {
          
     DisplayBoard();
  
     cout << "\n\n  " << NAME << ", where do you wish to move it?  ";
          
     cin >> INPUT;
     
     NUM = INPUT[0];
     DestinationPosition[0] = atoi(pNUM);
     NUM = INPUT[1];
     DestinationPosition[1] = atoi(pNUM);

     if(DestinationPosition[0] < 1 || DestinationPosition[0] > 8 ||
        DestinationPosition[1] < 1 || DestinationPosition[1] > 8)
     {
            cout << "\n   That was an invalid choice! Outside available range.";
            Sleep(2000);   
     }
     else
     {
            
            if(CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->GetColor() != BLANK)
            {
                 cout << "\n\n   You cannot move there. A CHECKER is already there!";
                 DestinationPosition[0] = 0;
                 Sleep(2000);  
            }
            else
            {
                 if(DestinationPosition[0] == CurrentPosition[0])
                 {
                     cout << "\n   You cannot move sideways!";
                     DestinationPosition[0] = 0;
                     Sleep(2000);  
                 }
                 else
                 { 
                   if(COLOR == RED)
                   {
                     
                     if(DestinationPosition[0] < CurrentPosition[0])
                     {
                         cout << "\n   You cannot move the CHECKER backwards!"; 
                         DestinationPosition[0] = 0;
                         Sleep(2000);                        
                     }
                     else
                     {
                         if(DestinationPosition[0] > CurrentPosition[0]+1)
                         {
                             cout << "\n   You can not move more than ONE row forward!";
                             DestinationPosition[0] = 0;
                             Sleep(2000);   
                         }
                         else
                         {
                             if(CurrentPosition[1] % 2 == 0)
                             {
                                 cout << "\n   Current Position is an EVEN number!";
                             
                                 if(DestinationPosition[1] % 2 == 0)
                                 {
                                     cout << "\n   Invalid move. Must be diagonal!";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000);                           
                                 }
                                 else
                                 {
                                    cout << "\n   That is an ACCEPTABLE and LEGAL move!";
                                    cout << "\n\n   Moving TO:  COL=" << DestinationPosition[0] 
                                         << " ROW=" << DestinationPosition[1];
                                         Sleep(1000);  
                                      
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(false);
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);
                                      
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(true);
                                      Sleep(1500);
                                      DisplayBoard();
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(false);                                        
                                 }

                             }
                             else
                             {    
                                  cout << "\n   Current Position is an ODD number!";
                              
                                  if(DestinationPosition[1] % 2 != 0)
                                  {
                                       cout << "\n   Invalid move. Must be diagonal!";
                                       DestinationPosition[0] = 0; 
                                       Sleep(2000);                          
                                  }
                                  else
                                  {
                                      cout << "\n   That is an ACCEPTABLE and LEGAL move!";
                                      cout << "\n\n   Moving TO:  COL=" << DestinationPosition[0] 
                                           << " ROW=" << DestinationPosition[1];
                                      Sleep(1000);  
                                           
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(false);
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);
                                      
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(true);
                                      Sleep(1500);
                                      DisplayBoard();
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(false); 
                                  }                              
                              
                             }//close if moving diagonal
                             
                         }//close if more than one row forward    
                         
                     }//close if CHECKER moving backwards 
                     
                   }//close if CHECKER RED
                   
                   //-------------------------------------------------------
                   
                   else if(COLOR == BLACK)
                   {
                     
                     if(DestinationPosition[0] > CurrentPosition[0])
                     {
                         cout << "\n   You cannot move the CHECKER backwards!"; 
                         DestinationPosition[0] = 0;
                         Sleep(2000);                        
                     }
                     else
                     {
                         if(DestinationPosition[0] < CurrentPosition[0]-1)
                         {
                             cout << "\n   You can not move more than ONE row forward!";
                             DestinationPosition[0] = 0;
                             Sleep(2000);   
                         }
                         else
                         {
                             if(CurrentPosition[1] % 2 == 0)
                             {
                                 cout << "\n   Current Position is an EVEN number!";
                             
                                 if(DestinationPosition[1] % 2 == 0)
                                 {
                                     cout << "\n   Invalid move. Must be diagonal!";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000);                           
                                 }
                                 else
                                 {
                                    cout << "\n   That is an ACCEPTABLE and LEGAL move!";
                                    cout << "\n\n   Moving TO:  COL=" << DestinationPosition[0] 
                                         << " ROW=" << DestinationPosition[1];
                                    Sleep(1000);  
                                      
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);
                                      
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(true);
                                      Sleep(1500);
                                      DisplayBoard();
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(false);                                        
                                 }

                             }
                             else
                             {    
                                  cout << "\n   Current Position is an ODD number!";
                              
                                  if(DestinationPosition[1] % 2 != 0)
                                  {
                                       cout << "\n   Invalid move. Must be diagonal!";
                                       DestinationPosition[0] = 0;
                                       Sleep(2000);                           
                                  }
                                  else
                                  {
                                      cout << "\n   That is an ACCEPTABLE and LEGAL move!";
                                      cout << "\n\n   Moving TO:  COL=" << DestinationPosition[0] 
                                           << " ROW=" << DestinationPosition[1];
                                      Sleep(1000);  
                                           
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);
                                      CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);
                                      
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(true);
                                      Sleep(1500);
                                      DisplayBoard();
                                      CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetSelected(false); 
                                  }                              
                              
                             }//close if moving diagonal
                             
                         }//close if more than one row forward    
                         
                     }//close if CHECKER moving backwards 
                     
                   }//close if CHECKER RED
                   
                   //----------------------------------------------------------                   
                     
                 }//close if move checker onto itself      
                  
            }///close if space is blank 
            
     }//close if not outside range       
     
   }//close while true loop   
 
   //DestinationPosition[0] = 0; 
     
}

//---------------------------------------------------------------------------------------------------------------------------

bool JumpChecker(int CurrentPosition[2], int COLOR, string NAME)
{
     string INPUT = "";
     char NUM;
     char * pNUM;
     pNUM = &NUM;     
     int DestinationPosition[2]; //COL, ROW

     while(DestinationPosition[0] < 1 || DestinationPosition[0] > 8 ||
           DestinationPosition[1] < 1 || DestinationPosition[1] > 8)
     {
          
     DisplayBoard();
  
     cout << "\n\n  " << NAME << ", where do you wish to move CHECKER for jump?"
          << "\n  If you cannot make a valid jump, enter (q)uit."
          << "\n  You will then be allowed to move CHECKER to another location.  ";
          
     cin >> INPUT;
     
     if(INPUT[0]=='q') { return false; }
     
     NUM = INPUT[0];
     DestinationPosition[0] = atoi(pNUM);
     NUM = INPUT[1];
     DestinationPosition[1] = atoi(pNUM);

     if(DestinationPosition[0] < 1 || DestinationPosition[0] > 8 ||
        DestinationPosition[1] < 1 || DestinationPosition[1] > 8)
     {
            cout << "\n   That was an invalid choice! Outside available range.";
            Sleep(2000);  
     }
     else
     {
            
            if(CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->GetColor() != BLANK)
            {
                 cout << "\n\n   You cannot jump there. A CHECKER is already there!";
                 DestinationPosition[0] = 0;
                 Sleep(2000);  
            }
            else
            {
                 if(DestinationPosition[0] == CurrentPosition[0])
                 {
                     cout << "\n   You cannot jump sideways!";
                     DestinationPosition[0] = 0;
                     Sleep(2000);  
                 }
                 else
                 { 
     //RED----------------------------------------------------------------------

                   if(COLOR == RED)
                   {
                     
                     if(DestinationPosition[0] < CurrentPosition[0])
                     {
                         cout << "\n   You cannot jump a normal RED CHECKER backwards!"; 
                         DestinationPosition[0] = 0;
                         Sleep(2000);                        
                     }
                     else
                     {
                         if(DestinationPosition[0] > CurrentPosition[0]+1)
                         {
                             cout << "\n   Good! To jump, you must move a normal RED"
                                  << "\n   CHECKER more than ONE row forward!";
                             
                             if(CurrentPosition[1] % 2 == 0)
                             {
                                 cout << "\n   Current Position of RED CHECKER is an EVEN number!";
                             
                                 if(DestinationPosition[1] % 2 == 0)
                                 {
                                      cout << "\n   Good! Jumping RED CHECKER to a BLANK, EVEN square 2 rows ahead!"; 
                                      //Are we moving left or right? By columns.
                                      //Moving RIGHT
                                      if(DestinationPosition[1] > CurrentPosition[1])
                                      {
                                          if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->GetColor() == BLACK)
                                          {
                                             cout << "\n   You jumped your RED CHECKER over your opponent's"
                                                  << "\n   BLACK checker. That is a LEGAL jump! Nice job.";
                                             CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK); //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == RED)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             
                                             DoubleJump(DestinationPosition, COLOR);
                                             
                                          }
                                          else if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->GetColor() == BLANK)
                                          {
                                               cout << "\n   You can't jump over a BLANK space.";
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own RED CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);     
                                          }
                                      }
                                      //Moving LEFT
                                      else
                                      {
                                          if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->GetColor() == BLACK)
                                          {
                                             cout << "\n   You jumped your RED CHECKER over your opponent's"
                                                  << "\n   BLACK checker. That is a LEGAL jump! Nice job.";  
                                             CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->SetColor(BLANK);       //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);     //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == RED)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                               
                                             DoubleJump(DestinationPosition, COLOR);                                                                                                
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own RED CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }                                          
                                      }                                 
                                                         
                                 }
                                 else
                                 {
                                     cout << "\n   Invalid move. You must jump to an EVEN numbered square.";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000); 
                                 }

                             }
                             else
                             {    
                                 cout << "\n   Current Position is an ODD number!";
                             
                                 if(DestinationPosition[1] % 2 != 0)
                                 {
                                      cout << "\n   Good! Jumping RED CHECKER to a BLANK, ODD square 2 rows ahead!";                         
                                      //Are we moving left or right? By columns.
                                      //Moving RIGHT
                                      if(DestinationPosition[1] > CurrentPosition[1])
                                      {
                                          if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->GetColor() == BLACK)
                                          {
                                             cout << "\n   You jumped your RED CHECKER over your opponent's"
                                                  << "\n   BLACK checker. That is a LEGAL jump! Nice job.";
                                             CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK); //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == RED)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             
                                             DoubleJump(DestinationPosition, COLOR);
                                             
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own RED CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);     
                                          }
                                      }
                                      //Moving LEFT
                                      else
                                      {
                                          if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->GetColor() == BLACK)
                                          {
                                             cout << "\n   You jumped your RED CHECKER over your opponent's"
                                                  << "\n   BLACK checker. That is a LEGAL jump! Nice job.";  
                                             CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->SetColor(BLANK);       //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);     //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == RED)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                           
                                             DoubleJump(DestinationPosition, COLOR);
                                                                                                                                             
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own RED CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }                                          
                                      }                                 
                                 }
                                 else
                                 {
                                     cout << "\n   Invalid move. Must jump RED CHECKER to an ODD number.";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000); 
                                 }                 
                              
                             }//close if moving diagonal 
                              
                         }
                         else
                         {
                             cout << "\n   You are not moving your RED CHECKER"
                                  << "\n   forward far enough for a jump!";
                             DestinationPosition[0] = 0;
                             Sleep(2000);  
                             
                         }//close if more than one row forward    
                         
                     }//close if CHECKER moving backwards 
                     
                   }//close if CHECKER RED
                   
                   
                   
     //BLACK--------------------------------------------------------------------
                   
                   else if(COLOR == BLACK)
                   {
                     
                     if(DestinationPosition[0] > CurrentPosition[0])
                     {
                         cout << "\n   You cannot jump a normal BLACK CHECKER backwards!"; 
                         DestinationPosition[0] = 0;
                         Sleep(2000);                        
                     }
                     else
                     {
                         if(DestinationPosition[0] < CurrentPosition[0]-1)
                         {
                             cout << "\n   Good! To jump, you must move a normal BLACK"
                                  << "\n   CHECKER more than ONE row forward!";
                             
                             if(CurrentPosition[1] % 2 == 0)
                             {
                                 cout << "\n   Current Position of BLACK CHECKER is an EVEN number!";
                             
                                 if(DestinationPosition[1] % 2 == 0)
                                 {
                                      cout << "\n   Good! Jumping BLACK CHECKER to a BLANK, EVEN square 2 rows ahead!"; 

                                      //Are we moving left or right? By columns.
                                      //Moving RIGHT
                                      if(DestinationPosition[1] > CurrentPosition[1])
                                      {   
                                          cout << "\n\n   Moving to the right for this jump!";
                                      
                                          if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->GetColor() == RED)
                                          {
                                             cout << "\n   WEEE! You jumped your BLACK CHECKER over your opponent's"
                                                  << "\n   RED checker. That is a LEGAL jump! Nice job.";
                                          
                                             CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);   //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);

                                             if(PLAYA_ONE->GetPlayerColor() == BLACK)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             
                                             DoubleJump(DestinationPosition, COLOR);
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own BLACK CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }
                                      }
                                      //Moving LEFT
                                      else
                                      {
                                           cout << "\n\n   Moving to the left for this jump!";
                                           
                                          if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->GetColor() == RED)
                                          {
                                             cout << "\n   You jumped your BLACK CHECKER over your opponent's"
                                                  << "\n   RED checker. That is a LEGAL jump! Nice job.";
                                            
                                             CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);     //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == BLACK)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             
                                             DoubleJump(DestinationPosition, COLOR);
                                                                                       
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own BLACK CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }                                          
                                      }                  
                                                         
                                 }
                                 else
                                 {
                                     cout << "\n   Invalid move. You must jump to an EVEN numbered square.";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000); 
                                 }

                             }
                             else
                             {    
                                 cout << "\n   Current Position is an ODD number!";
                             
                                 if(DestinationPosition[1] % 2 != 0)
                                 {
                                      cout << "\n   Good! Jumping BLACK CHECKER to a BLANK, ODD square 2 rows ahead!";                         
                                 
                                      //Are we moving left or right? By columns.
                                      //Moving RIGHT
                                      if(DestinationPosition[1] > CurrentPosition[1])
                                      {   
                                          cout << "\n\n   Moving to the right for this jump!";
                                      
                                          if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->GetColor() == RED)
                                          {
                                             cout << "\n   WEEE! You jumped your BLACK CHECKER over your opponent's"
                                                  << "\n   RED checker. That is a LEGAL jump! Nice job.";
                                          
                                             CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);   //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);

                                             if(PLAYA_ONE->GetPlayerColor() == BLACK)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             
                                             DoubleJump(DestinationPosition, COLOR);
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own BLACK CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }
                                      }
                                      //Moving LEFT
                                      else
                                      {
                                           cout << "\n\n   Moving to the left for this jump!";
                                           
                                          if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->GetColor() == RED)
                                          {
                                             CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->SetColor(BLANK);     //BLANK jumped checker
                                             CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);     //BLANK previous spot
                                             CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(BLACK);
                                             
                                             if(PLAYA_ONE->GetPlayerColor() == BLACK)
                                             {
                                                PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                                             }                                                                
                                             else  
                                             { 
                                                PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                                             }
                                             cout << "\n\n   Calling DoubleJump()!\n";
                                             Sleep(2000);
                                             DoubleJump(DestinationPosition, COLOR);
                                          }
                                          else
                                          {
                                             cout << "\n   You can't jump over your own BLACK CHECKERS."
                                                  << "\n   That's an illegal jump. Shame on you!";
                                             DestinationPosition[0] = 0;
                                             Sleep(2000);
                                          }                                          
                                      }                                           
                                 
                                 }
                                 else
                                 {
                                     cout << "\n   Invalid move. Must jump BLACK CHECKER to an ODD number.";
                                     DestinationPosition[0] = 0;
                                     Sleep(2000); 
                                 }                 
                              
                             }//close if moving diagonal 
                              
                         }
                         else
                         {
                             cout << "\n   You are not moving your BLACK CHECKER"
                                  << "\n   forward far enough for a jump!";
                             DestinationPosition[0] = 0;
                             Sleep(2000);
                             
                         }//close if more than one row forward    
                         
                     }//close if CHECKER moving backwards 
                     
                   }//close if CHECKER BLACK
                   
                   //----------------------------------------------------------                   
                     
                 }//close if sideways      
                  
            }///close if space is not blank 
            
     }//close if not outside range       
     
   }//close while true loop   
 
   //DestinationPosition[0] = 0; 

     CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetSelected(false);

     return true;       

}

//---------------------------------------------------------------------------------------------------------------------------

void DoubleJump(int CurrentPosition[2], int COLOR)
{
     string INPUT = "";
     
     //If CHECKER is RED
     if(COLOR == RED)
     {  
        //Double Jump Available to RIGHT?
        if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->GetColor() == BLACK &&
           CheckerBoard[CurrentPosition[0]+1][CurrentPosition[1]+1]->GetColor() == BLANK)
        {
                   cout << "\n\n  Awesome! You have a \"Double Jump\" available "
                        << "\n  to the RIGHT! Do you wish to take it?  ";
                        
                   cin >> INPUT;
                   
                   if(INPUT[0] == 'y')
                   {
                       CheckerBoard[CurrentPosition[0]][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                       CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK); //BLANK previous spot
                       CheckerBoard[CurrentPosition[0]+1][CurrentPosition[1]+1]->SetColor(RED);
                                             
                       if(PLAYA_ONE->GetPlayerColor() == RED)
                       {
                           PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                       }                                                                
                       else  
                       { 
                           PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                       }

                       return;
                   }
                   else
                   {
                       cout << "\n\n  O.k., for whatever reason you decide not to take it.";
                       Sleep(1500);
                   }

          }
          
          /*
          CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->SetColor(BLANK);       //BLANK jumped checker
          CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);     //BLANK previous spot
          CheckerBoard[DestinationPosition[0]-1][DestinationPosition[1]-1]->SetColor(RED);
          */
          
          //Double Jump Available to LEFT? (XY Coordinates are inverted...)
          if(CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->GetColor() == BLACK &&
             CheckerBoard[CurrentPosition[0]+1][CurrentPosition[1]-3]->GetColor() == BLANK)
          {  
             cout << "\n\n  Awesome! You have a \"Double Jump\" available"
                  << "\n  to the LEFT! Do you want to take it?  ";
                        
             cin >> INPUT;
                   
             if(INPUT[0] == 'y')
             {
                CheckerBoard[CurrentPosition[0]][CurrentPosition[1]-2]->SetColor(BLANK);    //BLANK jumped checker
                CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);  //BLANK previous spot
                CheckerBoard[CurrentPosition[0]+1][CurrentPosition[1]-3]->SetColor(RED);
                                             
                if(PLAYA_ONE->GetPlayerColor() == RED)
                {
                    PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                }                                                                
                else  
                { 
                   PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                }
                      
                return;
             }                   
             else
             {
                cout << "\n\n  O.k., for whatever reason you decide not to take it.";
                Sleep(1500); 
             }
                 
          }
          
          /*
          {
              cout << "\n\n   No DOUBLE JUMP available on either side.";
              Sleep(1500);
          } 
          */   
          
     }
 
 
     
     //If CHECKER is BLACK
     else
     {
        if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->GetColor() == RED)
        {
              //Double Jump Available to RIGHT?
              if(CheckerBoard[CurrentPosition[0]-3][CurrentPosition[1]+1]->GetColor() == BLANK)
              {
                   cout << "\n   Awesome! Double jump to RIGHT!";
                   
                   CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]]->SetColor(BLANK);     //BLANK jumped checker
                   CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);   //BLANK previous spot
                   CheckerBoard[CurrentPosition[0]-3][CurrentPosition[1]+1]->SetColor(BLACK);
                                             
                   if(PLAYA_ONE->GetPlayerColor() == BLACK)
                   {
                       PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                   }                                                                
                   else  
                   { 
                       PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                   }
                    
                   Sleep(1500);  
              }
              else
              {
                   cout << "\n   Space required for BLACK to Double Jump RIGHT is not BLANK.";
              }  
          }
          
          else if(CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->GetColor() == RED)
          {
              //Double Jump Available to LEFT?
              if(CheckerBoard[CurrentPosition[0]-3][CurrentPosition[1]-3]->GetColor() == BLANK)
              {
                   cout << "\n   Awesome! Double jump to LEFT!";
                   
                   //BLANK jumped checker
                   CheckerBoard[CurrentPosition[0]-2][CurrentPosition[1]-2]->SetColor(BLANK);     
                   //BLANK previous spot
                   CheckerBoard[CurrentPosition[0]-1][CurrentPosition[1]-1]->SetColor(BLANK);
                   CheckerBoard[CurrentPosition[0]-3][CurrentPosition[1]-3]->SetColor(BLACK);
                                             
                   if(PLAYA_ONE->GetPlayerColor() == BLACK)
                   {
                       PLAYA_ONE->SetPlayerScore(PLAYA_ONE->GetPlayerScore() + 1);
                   }                                                                
                   else  
                   { 
                       PLAYA_TWO->SetPlayerScore(PLAYA_TWO->GetPlayerScore() + 1);
                   }
                                      
                   Sleep(1500);  
              }
              
              else
              {
                   cout << "\n   Space required for BLACK to Double Jump LEFT is not BLANK.";
              }               
          }
          
          else
          {
              cout << "\n\n   No DOUBLE JUMP available on either side.";
          }   
                
     }//close if BLACK

}//close function

//---------------------------------------------------------------------------------------------------------------------------













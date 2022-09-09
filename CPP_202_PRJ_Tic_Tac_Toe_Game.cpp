//PRJ - Tic Tac Toe Game Console - 2006 - C. S. Germany
//Uses pointers to pass an array for more efficiency than passing by value

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
char CheckForAWinner(char * board);
int ComputerPlays(char * board, char playerpiece, char computerpiece);
void Display(char * board);
void DisplayWinner(char TheWinner, char computerpiece, char playerpiece);
char Introduction();
bool LegalMove(int move,char * board);
int PlayerPlays(char * board, char human);

//---------------------------------------------------------------------------------------------------------------------------

//Globals
const int SQUARES = 9;
bool stupid;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int choice;
    char GameBoard[SQUARES] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
  
    char playerpiece, computerpiece, currentplayer;

    //Start game and get player's choice to go first/last.
    playerpiece = Introduction();  

    //Whatever player chooses, 'X' or 'O', the computer gets the other.    
    if(playerpiece == 'X')  { computerpiece = 'O'; }
    else { computerpiece = 'X'; }
    
    currentplayer = 'X';
    Display(GameBoard);

    while (CheckForAWinner(GameBoard) == 'N')
    {
        if (currentplayer == playerpiece)
        {
            choice = PlayerPlays(GameBoard, playerpiece);
            GameBoard[choice] = playerpiece;
        }
        else
        {
            choice = ComputerPlays(GameBoard, playerpiece, computerpiece);
            GameBoard[choice] = computerpiece;
        }
        
        Display(GameBoard);
        
        if(currentplayer == playerpiece) { currentplayer = computerpiece; }
        else { currentplayer = playerpiece; }
    }

    DisplayWinner(CheckForAWinner(GameBoard), computerpiece, playerpiece);

    cout << "\nGame Over.\n\n"
         << "Exiting Tic Tac Toe 2.0 ...\n\n\n";
         
    system("PAUSE");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

char CheckForAWinner(char * GameBoard)
{
    //All the wining combinations, horizontal, vertical and diagonal.
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    //If an row has three values that are the same we have a winner
    //We will either return 'X' or 'O' as the winner or a tie and 
    //end the game, or else we will return 'N' and keep playing the game.
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (GameBoard[WINNING_ROWS[row][0]] != ' ') &&
             (GameBoard[WINNING_ROWS[row][0]] == GameBoard[WINNING_ROWS[row][1]]) &&
             (GameBoard[WINNING_ROWS[row][1]] == GameBoard[WINNING_ROWS[row][2]]) )
        {
            return GameBoard[WINNING_ROWS[row][0]];
        }
    }

    //If we don't have a winner, check for a possible tie.
    bool NoEmptySpaces = true;
    
    for(int x = 0; x < SQUARES; x++)
    {
        if(GameBoard[x] == ' ') { NoEmptySpaces = false; }
    }
    
    if(NoEmptySpaces == true)
       return 'T';

    //If nobdy wins and it's not a tie return 'N' and keep playing.
    return 'N';
}

//---------------------------------------------------------------------------------------------------------------------------

int ComputerPlays(char * GameBoard, char playerpiece, char computerpiece)
{
    cout << "\nThe computer chooses location: ";
     
    //1. If computer can win on next choice, make that choice.
        
    for(int choice = 0; choice < SQUARES; ++choice)
    {
        if (LegalMove(choice, GameBoard))
        {
            GameBoard[choice] = computerpiece;
            if (CheckForAWinner(GameBoard) == computerpiece)
            {
                cout << choice << "." << endl;
                return choice;
            }
            // done checking this choice, undo it
            GameBoard[choice] = ' ';
        }
    }

    //Note: Computer will not try to block player's winning move if stupid = true
    if(stupid == false)
    {        
        //2. If human can win on next choice, block that choice.
        char human = playerpiece;
        for(int choice = 0; choice < SQUARES; ++choice)
        {
            if(LegalMove(choice, GameBoard))
            {
                GameBoard[choice] = human;
                if(CheckForAWinner(GameBoard) == human)
                {
                    cout << choice  << "." << endl;
                    return choice;
                }
                // done checking this choice, undo it
                GameBoard[choice] = ' ';
            } //close inner if
        } //close for loop
    } //close outer if
    
    //3. If no one can win on next choice, pick best open square.
    const int PreferredChoices[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

    for(int i = 0; i < SQUARES; ++i)
    {
        int choice = PreferredChoices[i];
        if (LegalMove(choice, GameBoard))
        {
            cout << choice  << "." << endl;
            return choice;
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------

void Display(char * GameBoard)
{   
    cout << "\n\t" << GameBoard[0] << " | " << GameBoard[1] << " | " << GameBoard[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << GameBoard[3] << " | " << GameBoard[4] << " | " << GameBoard[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << GameBoard[6] << " | " << GameBoard[7] << " | " << GameBoard[8];
    cout << "\n\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void DisplayWinner(char TheWinner, char computerpiece, char playerpiece)
{
	if (TheWinner == computerpiece)
    {
        cout << "\n" << TheWinner << " wins the game. "
             << "The computer wins this match.\nSorry, you loose.\n";
    }

	else if (TheWinner == playerpiece)
    {
        cout << "\n" << TheWinner << " wins the game. "
             << "Excellent. You win this match. The computer looses.\n";
    }

	else
    {
        cout << "The game ends in a tie.\nNeither you nor the computer wins.\n\n";
	}
}

//---------------------------------------------------------------------------------------------------------------------------

char Introduction()
{
    char FirstOrSecond;
    char intelligence;
    char playerpiece = 'z'; 
     
    cout << "\aWelcome to Tic Tac Toe 1.0.\n";
    cout << "This game uses very basic A.I. in the form of several decision structures.\n\n";

    cout << "To play, enter a number, 0 - 8.  The number you enter will\n";
    cout << "indicate which of 9 positions you desire below:\n\n";
    
    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";

    cout << "The computer will play as your oponent in this game.\n\n";   
    
    while(intelligence != 'I' && intelligence != 'S')
    {
        cout << "\aDo you want your computer opponent to be (i)ntelligent or (s)tupid?\n"
             << "Choosing this option for your opponent sets the difficulty of the game. ";
        cin >> intelligence;
        intelligence = toupper(intelligence);
    
        switch(intelligence)
        {
           case 'I' : cout << "\nO.k., your computer opponent will be more dificult to beat.\n"; 
                      stupid = false;
                      break;
           case 'S' : cout << "\nO.k., your computer opponent will be easier to beat.\n"; 
                      stupid = true;
                      break;
           default : cout << "That is an invalid response.\n\n"; break;                     
        }
    }//close while true loop
    
    while(FirstOrSecond != 'Y' && FirstOrSecond != 'N')
    {
        cout << "\a\nDo you want to make the first move (y/n)? ";
        cin >> FirstOrSecond;
        FirstOrSecond = toupper(FirstOrSecond);
    
        switch(FirstOrSecond)
        {
           case 'Y' : cout << "\nO.k., you take the first move.\n"; 
                      playerpiece = 'X';
                      break;
           case 'N' : cout << "\nO.k., the computer takes the first move.\n"; 
                      playerpiece = 'O';
                      break;
           default : cout << "That is an invalid response.\n\n"; break;                     
        }
    }//close while true loop
    
    system("PAUSE");
    system("CLS");
    
    return playerpiece;
    
}//close function

//---------------------------------------------------------------------------------------------------------------------------

bool LegalMove(int choice, char * GameBoard)
{
    return (GameBoard[choice] == ' ');
}

//--------------------------------------------------------------------------

int PlayerPlays(char * GameBoard, char human)
{
    int PlayersMove;

    while(PlayersMove > SQUARES || PlayersMove < 0 || 
         (LegalMove(PlayersMove, GameBoard)== false))
    {
        cout << "\nChoose a location (0-8): ";
        cin >> PlayersMove;

        if(PlayersMove > SQUARES || PlayersMove < 0) 
        { cout << "\nThat number is outside of the valid range of 1-8.\n"; }
        
        else if(LegalMove(PlayersMove, GameBoard) == false) 
        {
          cout << "\nYou can not choose that location. It already has a(n) "
               << GameBoard[PlayersMove] << " in it.\n"; 
        }
    } 

    return PlayersMove;
}

//---------------------------------------------------------------------------------------------------------------------------




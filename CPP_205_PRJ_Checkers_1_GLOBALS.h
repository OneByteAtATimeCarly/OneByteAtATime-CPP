//PRJ - Checkers Game Console - 2006 - C. S. Germany
//File 1 of 4: GLOBALS

//---------------------------------------------------------------------------------------------------------------------------

//Global Variables
enum COLORS{RED,BLACK,BLANK};
bool CONTINUE;
bool KeepPlaying;

//---------------------------------------------------------------------------------------------------------------------------

//Global Class Prototypes
class Checker;
class Player;

//---------------------------------------------------------------------------------------------------------------------------

//Global Function Prototypes
void MainMenu();
void Begin();
void CreateBoard();
void DisplayBoard();
void PlayGame();
void SelectChecker(int COLOR, string NAME);
void MoveChecker(int CurrentPosition[2], int COLOR, string NAME);
bool JumpChecker(int CurrentPosition[2], int COLOR, string NAME);
void DoubleJump(int CurrentPosition[2], int COLOR);

//---------------------------------------------------------------------------------------------------------------------------

//Global Pointers and Arrays
Checker * CheckerBoard[8][8];
Player * PLAYA_ONE;
Player * PLAYA_TWO;

//---------------------------------------------------------------------------------------------------------------------------











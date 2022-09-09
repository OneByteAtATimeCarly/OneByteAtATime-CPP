//PRJ - Number Game Console - 2006 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <time.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype, has a default argument of 999
int GenerateRandomNumber(int n=999);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int guess; //Get the player's guess
    int counter = 0; //Count the number of guesses
    int num;
    //const int num = 69; //The number to guess
    
    num = GenerateRandomNumber(5);
    
    cout << "\n\nNumber guessing game 1.0\n\n";

    while(counter < 3)
    {
       cout << "Guess a number between 1 and 5:\t";
       cin >> guess;
       
       if(guess >= num)
       {
              if(guess == num)
              {
                  cout << "Congratulations! You win. You guessed the number!"
                       << "\nThe number was: " << num << ".\n\n\n";
                  break;      
              }
              else
              {
                  cout << "The number is smaller than what you have guessed.\n\n";  
              }              
       }
       else
            cout << "The number is larger than what you have guessed.\n\n";           
                  
       counter = counter + 1;           
    }
    
    if(counter >= 3)
        cout << "Sorry. It appears you have lost the game. You only get three guesses!"
             << "\nThe number was: " << num << ".\n\n\n";
    
    system("PAUSE");
    return 0;
      
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition

int GenerateRandomNumber(int n) 
{
    int ResultRandom;
    srand(time(NULL));
    ResultRandom = (rand()%n) + 1;
    return ResultRandom;
}  

//---------------------------------------------------------------------------------------------------------------------------

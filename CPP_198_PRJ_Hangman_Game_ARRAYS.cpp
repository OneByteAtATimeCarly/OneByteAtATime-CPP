//PRJ - Hangman Game Console - 2006 - C. S. Germany
//Implemented with ARRAYS of STRINGS

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int RandomNumber(int n) 
{
    int ResultRandom;
    srand(time(NULL));
    ResultRandom = (rand()%n) + 1;
    return ResultRandom;
}

//---------------------------------------------------------------------------------------------------------------------------

void DrawIntro()
{
     //Example of a whole ANSI man.  You could create a function to draw a leg or arm for each
     //guess the player gets wrong. It's up to you...
     
     cout << "\a"; //beep
     
     cout << "\n\n"
          << "                                 ***                  \n"
          << "                                *- -*                 \n"
          << "                                * | *                 \n"
          << "                                * - *                 \n"
          << "                                 ***                  \n"
          << "                                  *                   \n"
          << "                            *************             \n"
          << "                                  *                   \n"
          << "                                  *                   \n"    
          << "                                 * *                  \n"
          << "                                *   *                 \n"
          << "                               *     *                \n"
          << "                              *       *               \n"
          << "                             *         *              \n\n";
     cout << "                          LameMan       2.0           \n\n\n";
     cout << "                           2006 C. Germany            \n\n\n\n";

     cout.flush();
     system("PAUSE");
     system("CLS");
     cout << "\a"; //beep 
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    //Declaration of constants and initialization of locals in main() function
    const int NumberOfWrongGuessesAllowed = 5;
    const int NumberOfWordsInBank = 27;
    int WrongGuesses = 0; 
    
    DrawIntro(); 

    //Collection of possible WordBank to guess in an array of strings
    string WordBank[NumberOfWordsInBank] = {"CAPRICIOUS","TACIT","MELANCHOLY",
                                            "TOURNIQUET","PLAGIARISM","DECEPTIVE",
                                            "DECEITFUL","THIEF","ARROGANT","PATHETIC",
                                            "APOCALYPTIC","DELUSIONS","GRANDEUR",
                                            "WORTHLESS","SCUM","REVENGE", "ENTITLEMENT",
                                            "GENERATION","WEAK", "USELESS","FLUFFY",
                                            "BUNNY", "HOLLOW","LIAR","TASTES","LIKE",
                                            "CHICKEN"};
        
    int TheChosenOne = RandomNumber(NumberOfWordsInBank);
    
    //After the vectors are randomly shuffled, set "TheWordToGuess" to
    //whichever ends up the first one. Subscript value for vector works just like arrays.
    string TheWordToGuess = WordBank[TheChosenOne];            

    //Make a string object the same size as "TheWordToGuess" and fill it with the appropriate
    //number of dashes. Later, we'll replace dashes where a correct letter is guessed. 
    //The "TheWordToGuess" and "CorrectGuesses" will act as parallel arrays, where each "-"
    // in "CorrectGuesses" will correspond to a char in "TheWordToGuess".              
    string CorrectGuesses(TheWordToGuess.size(), '-'); 
    
    string LettersGuessedAlready = "";                 

    cout << "\nThe rules for LameMan 2.0 are simple. Try to guess the \nrandomly picked word."
         << " For each game, you get " << NumberOfWrongGuessesAllowed << " wrong\nguesses."
         << " Guess the word before exceeding " << NumberOfWrongGuessesAllowed 
         << " wrong guesses\nand you win!"
         << " If you do not guess the word before exceeding\n" 
         << NumberOfWrongGuessesAllowed << " wrong guesses, "
         << "you loose. Are you ready? Go!\n\n\n";

    //while true will break if they guess word or if they exceed number of guesses
    while((CorrectGuesses != TheWordToGuess) && (WrongGuesses < NumberOfWrongGuessesAllowed))
    {
        cout << "You have " << (NumberOfWrongGuessesAllowed - WrongGuesses) 
             << " incorrect guesses left.\n"
             << "This word has " << TheWordToGuess.size() << " letters in it.\n";
        cout << "\nYou have already guessed these letters:\n";
        
             if(LettersGuessedAlready == "")
             {
                 cout << "Nothing to display - You haven't guessed any letters yet!\n\n";
             }
             else
             {   cout << LettersGuessedAlready << endl; }
        
        cout << "\nThe result of all correctly guessed letters is:\n\n" 
             << CorrectGuesses << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        
        //toupper() converts characters to uppercase
        guess = toupper(guess); 
 
        //The find() function below pertains to string objects.
        //It will return the value "string::npos" if it can not find a 
        //string or char within another string. So we are saying in the 
        //loop below: keep looping until player guesses a char that is not
        //already in the string of dashes "CorrectGuesses". In this way, we
        //will not penalize them for guessing a correct char twice.     
        while(LettersGuessedAlready.find(guess) != string::npos)
        {
            cout << "\n" << guess << "? You've already guessed that letter!" 
                 << endl;
            cout << "\nLook above and make sure you know what you already guessed."
                 << "\nNow enter a fresh guess this time: ";
            cin >> guess;
            guess = toupper(guess);
        } //close nested inner while true
        
        //If it hasn't already been done, add it to letters guessed already
        //The while true loop above keeps multiple instances of the same letter
        //from being added.
        LettersGuessedAlready += guess;

        //If the char guessed is in the word, say so.
        if(TheWordToGuess.find(guess) != string::npos)
        {
            cout << "\nThat's right! " << guess << " is in the word.\n\n";

            //The for loop below will sequence every char in the string of "TheWordToGuess"
            //to see if it finds the char guessed. If so, it will replace the dash in
            //"CorrectGuesses" with the letter.
            //Note: The length() function automatically determines the length of a string.
            for(int i = 0; i < TheWordToGuess.length(); ++i)
            {
                if(TheWordToGuess[i] == guess)
                {  CorrectGuesses[i] = guess;  }
            } //close for loop
        } //close if
        else
        {
            cout << "\nSorry, " << guess << " isn't in the word.\n\n";
            ++WrongGuesses;
        }
    } //close outer while true loop
    
    //Win or loose?
    if (WrongGuesses == NumberOfWrongGuessesAllowed)
        cout << "\nYou are so lame. Your number of wrong guesses has " 
             << "exceeded the limit.\nThis means you loose the game.\n";
    else
        cout << "\nNice. You did it! You guessed the entire word!";
    
    cout << "\nThe chosen word was \"" << TheWordToGuess << "\".\n\n";

    cout << "Exiting program.\n\n";
    system("PAUSE");

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------



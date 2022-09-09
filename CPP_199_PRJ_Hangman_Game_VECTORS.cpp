//PRJ - Hangman Game Console - 2006 - C. S. Germany
//Implemented with VECTORS

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    //Initialize values here on start
    int NumberOfGuessesAllowed = 10; 
    int WrongGuesses = 0;  
    
    cout << "LameMan 1.0\n";  

    //Wussy string vectors hold collection of possible words to guess
    vector<string> WordBank;  
    WordBank.push_back("CAPRICIOUS");
    WordBank.push_back("TACIT");
    WordBank.push_back("APOCALYPTIC");
    WordBank.push_back("MELANCHOLY");
    WordBank.push_back("TOURNIQUET");
    WordBank.push_back("PLAGIARISM");    
    WordBank.push_back("DECEPTIVE");    
    WordBank.push_back("DECEITFUL");
    WordBank.push_back("THIEF");
    WordBank.push_back("ARROGANT");
    WordBank.push_back("PATHETIC");
    WordBank.push_back("DELUSIONS");
    WordBank.push_back("GRANDEUR");                    
    WordBank.push_back("WORTHLESS");
    WordBank.push_back("SCUM"); 
    WordBank.push_back("REVENGE");
        
    //srand() seeds random number generator with system time value
	srand(time(0));
	//random_shuffle is a built-in vector function, randomly shuffles string vectors
    random_shuffle(WordBank.begin(), WordBank.end()); 
    
    //After the vectors are randomly shuffled, set "TheWordToGuess" to
    //whichever ends up the first one. Subscript value for vector works just like arrays.
    string TheWordToGuess = WordBank[0];            

    //Make a string object the same size as "TheWordToGuess" and fill it with the appropriate
    //number of dashes. Later, we'll replace dashes where a correct letter is guessed. 
    //The "TheWordToGuess" and "CorrectGuesses" will act as parallel arrays, where each "-"
    // in "CorrectGuesses" will correspond to a char in "TheWordToGuess".              
    string CorrectGuesses(TheWordToGuess.size(), '-'); 
    
    string LettersGuessedAlready = "";                 

    //while true will break if they guess word or if they exceed number of guesses
    while((CorrectGuesses != TheWordToGuess) && (WrongGuesses < NumberOfGuessesAllowed))
    {
        cout << "\n\nYou have only " << (NumberOfGuessesAllowed - WrongGuesses) 
             << " incorrect guesses left.\n";
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
            cout << "\nYou've already guessed that letter! Guess again." 
                 << guess << endl;
            cout << "Look above and make sure you know what you already guessed."
                 << "Now enter a fresh guess this time: ";
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
            cout << "That's right! " << guess << " is in the word.\n";

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
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++WrongGuesses;
        }
    } //close outer while true loop
    
    //Win or loose?
    if (WrongGuesses == NumberOfGuessesAllowed)
        cout << "\nYou are so lame. Number of wrong guesses has exceeded limit.";
    else
        cout << "\nNice. You guessed it! You win. Yay.";
    
    cout << "\nThe word was " << TheWordToGuess << endl;

    system("PAUSE");
    return 0;

//---------------------------------------------------------------------------------------------------------------------------



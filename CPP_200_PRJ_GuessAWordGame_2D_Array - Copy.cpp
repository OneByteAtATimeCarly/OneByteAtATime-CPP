//PRJ - Guess A Word Game Console - 2006 - C. S. Germany
//Implements 2-D Multidimensional Array With Pointers

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Global variables outside of main
const int NumberOfWords = 15;
const int NumberOfWrongGuesses = 10;
const int NumWordsToGuess = 3;
int MakeSureTheyAreNotTheSame;
bool WorthyOfAClue; 
char CONTINUE;

//---------------------------------------------------------------------------------------------------------------------------

int randy()

{
   	int TheChosenOne;

        srand(time(0));

	TheChosenOne = (rand() % NumberOfWords);

	return TheChosenOne;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()

{
    CONTINUE = 'y';       

    while(CONTINUE == 'y')

    {
        //Initializing and declaring variables local to main()

        MakeSureTheyAreNotTheSame = 0;

        WorthyOfAClue = false;     

        int counter = 0;

        int WordsGuessed = 0;

        int TheChosenOne = 0;

        int Randy1 = 0, Randy2 = 0;

        int TheSizeOfMixItAllUp = 0;

        char temp = ' ';

        string UsersBestGuess = "";

        string TheWordToGuess = "";

        string ThrowMeAFrickinBoneHere = "";

        string MixItAllUp = "";



        //Store word to guess and a corresponding hint in a 2 dimensional array

        const string WORDS[NumberOfWords][2] =

        {

           {"entitlement", "You think you deserve it."},

           {"plagiarism", "Taking the credit for someone else's work."},

           {"revenge", "Don't get mad, get even."},

           {"generation", "By survival of the FITTEST, the present one will soon be extinct."},

           {"pathetic", "It's always someone else's fault, it's not my responsibility."},

           {"obsolete", "No longer relevant to the situation."},

           {"entrapment", "Deceptively misleading situation..."},

           {"scapegoat", "Blame it on me."},

           {"cryptic", "l00k @ th1s, 1 m sew kewl n a11 l0fte"},

           {"disembowel", "Gut-wrenching..."},

           {"adolescent", "You're not the boss of me..."},

           {"agoraphobia", "Fear of open spaces..."},

           {"claustrophobia", "Fear of closed spaces..."},

           {"apocalyptic", "Of or pertaining to the end..."},

           {"karma", "Getting what you deserve..."}                

       }; 



    cout << "\t\t\tGuessAWord 1.0 Instructions:\n\n";

    cout << "The object of this game is to guess " << NumWordsToGuess << " scrambled words\n";

    cout << "within " << NumberOfWrongGuesses << " wrong guesses with scrambled letters.\n\n\n";



    //Guess 3 words (outer loop)

    while((UsersBestGuess != "quit") && (counter < 10) && (WordsGuessed < NumWordsToGuess))

    {

	    TheChosenOne = randy();

        TheWordToGuess = WORDS[TheChosenOne][0];

        ThrowMeAFrickinBoneHere = WORDS[TheChosenOne][1]; 

        MixItAllUp = TheWordToGuess; 

        TheSizeOfMixItAllUp = MixItAllUp.size();



        //If by strange chance strings are same, keep scrambling until they are not.    

        while(MakeSureTheyAreNotTheSame == 0)

        {

            for(int i=0; i<TheSizeOfMixItAllUp; ++i)

            {

                Randy1 = (rand() % TheSizeOfMixItAllUp);

                Randy2 = (rand() % TheSizeOfMixItAllUp);

                temp = MixItAllUp[Randy1];

                MixItAllUp[Randy1] = MixItAllUp[Randy2];

                MixItAllUp[Randy2] = temp;

            }                  

        

            //The compare() fucntion returns 0 if strings are equal. Arguments are:

            //(start character, # characters, the string), hence:

            MakeSureTheyAreNotTheSame = TheWordToGuess.compare(0,TheSizeOfMixItAllUp,MixItAllUp);

        }   

        

        //By the time we get here, MakeSureTheyAreNotTheSame is currently not 0 but 1, so we

        //need to reset the variable so next word will be scrambled in the for loop above.

        MakeSureTheyAreNotTheSame = 0;

                   

        cout << "So far, you have guessed " << WordsGuessed << " word(s) of the "

             << NumWordsToGuess << " required.\n"; 

        cout << "So far, you have used " << counter << " of your " 

             << NumberOfWrongGuesses << " wrong guesses.\n";                 

        cout << "If you enter \"clue\", you'll get a clue.\n";

        cout << "If you enter \"quit\", you'll exit the game.\n\n";

        cout << "The word to guess is: " << MixItAllUp; 

                         

        //Guess each word (inner loop)

        while((UsersBestGuess != TheWordToGuess) && (UsersBestGuess != "quit") && 

              (counter < NumberOfWrongGuesses))

        {

            cout <<  "\n\nYour guess for word number " << (WordsGuessed + 1) << ": ";

            cin >> UsersBestGuess;

            

            for(int z = 0; z < UsersBestGuess.size(); z++)

            {  UsersBestGuess[z] = tolower(UsersBestGuess[z]);    }          

        

          

            if(UsersBestGuess == "clue")

            { 

               if(WorthyOfAClue == true)

               {                

                  cout << ThrowMeAFrickinBoneHere;

               }

               else

               {

                   cout << "You are not yet worthy of a clue. Try at least one guess first!";

               }  

            }            

            

            else if(UsersBestGuess == TheWordToGuess)

            {  

                 cout << "\nHooray! You have guessed word number " << (WordsGuessed + 1) << ".\n";

                 WordsGuessed = WordsGuessed + 1;

                 WorthyOfAClue = false; 

                 break;

            }

            

            else

            { 

               cout << "Sorry, but that is not what word number " << (WordsGuessed + 1) << " is.\n"; 

               counter = counter + 1;

               cout << "Careful, you only have " << (NumberOfWrongGuesses - counter) 

                    << " wrong guesses left!\n";

               WorthyOfAClue = true;                                   

            }

        

        } //close nested while true loop



    } //close outer while true loop



    if(WordsGuessed == 3)

    { 

       cout << "\n\nYou did it! You guessed all three words and therefore you win the game!"

            << "\n\nYAY!!!\n\n"; 

    }

    

    else

    { 

       cout << "\n\nSorry, you did not guess all three words before making\n"

            << NumberOfWrongGuesses << " incorrect guesses. As a result: \n\n"

            << "YOU LOSE!\n\n";

    }

    

    cout << "\n\nWould you like to play again?\n\n";

    cin >> CONTINUE;

    CONTINUE = tolower(CONTINUE);

    

  }//close outermost while



    cout << "\nExiting GuessAWord 1.0...\n\n\n";

    system("PAUSE");

    return 0;

}

//---------------------------------------------------------------------------------------------------------------------------



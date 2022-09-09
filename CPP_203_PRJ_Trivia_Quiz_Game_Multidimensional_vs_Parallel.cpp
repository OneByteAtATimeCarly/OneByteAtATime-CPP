//PRJ - Trivia Quiz Game Console - 2006 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Globals
const int NumberOfQuestions = 5;
const int NumWrongGuesses = 10;
int score;
int WrongCount;
int RightCount;

//---------------------------------------------------------------------------------------------------------------------------

//Function ProtoTypes
void quiz1();
void quiz2();

//---------------------------------------------------------------------------------------------------------------------------

int main()

{
        WrongCount = 0;
        RightCount = 0;
        score = 0;

        char choice;
        cout << "\nChoose an example to run:\n\n"

             << "(M)ulti-dimensional Array Quiz\n"

             << "(P)arallel Array Quiz\n\n";

        cin >> choice;

        switch(choice)
        {
            case 'm' : quiz1(); break;

            case 'p' : quiz2(); break;

            default: cout << "Invalid choice. Ending program."; break;
        }                    

        cout << "\n\n";

        system("PAUSE");

        return 0;



}//close main()

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

void quiz1()
{
     //This Function Illustrates a Multi-Dimensional Array, 1 array with 5 rows and 4 columns



     string QandClueandA[5][4] = {

     {"\nEl dia de los muertos? ","october_30","Same month as halloween.",""},

     {"\nFavorite game? ","descent_3","Maze-like first person shooter game.",""},

     {"\nBest new television show: ","bsg","Frack off cylon!",""},

     {"\nFavorite hobby? ","music","The hills are alive...",""},

     {"\nPopular vacation Destination? ","bahamas","Ja man, on da beaches.",""} };

     

     //Quiz Using Multi-dimensional arrays

     for(int x = 0; x < NumberOfQuestions && WrongCount < NumWrongGuesses; x++)

     {

         cout << QandClueandA[x][0];

         cin >> QandClueandA[x][3];

         

         //Convert User's Answer to lower case

         for(int z = 0; z < QandClueandA[x][3].size(); z++)

         { QandClueandA[x][3][z] = tolower(QandClueandA[x][3][z]); }

             

         if(QandClueandA[x][1] != QandClueandA[x][3])

         {

            cout << "\nHere's a hint: " << QandClueandA[x][2] << "\n\n";

            x--;   

            WrongCount++;                   

         }

         else

         { cout << "That's it! You got it right!"; score++; RightCount++; }     

         

         cout << "\n\nCurrent Status:   Wrong Guesses = " << WrongCount

              << "   Right Guesses = " << RightCount << "\n\n";

           

     }//close for loop



     score = score * 20;     



     switch(score)

     {                       

            case 0 : cout << "You got NOTHING! Try at least guessing next time! Grade = F."; 

                     break;

            case 20 : cout << "Score: " << score << " Got at least one right. Grade = F."; 

                      break;

            case 40 : cout << "Score: " << score << " Got at least two right. Grade = F."; 

                      break;

            case 60 : cout << "Score: " << score << " Got at least three right. Grade = F."; 

                      break;

            case 80 : cout << "Score: " << score << " Got at least four right. Grade = B."; 

                      break;

            case 100 : cout << "Score: " << score 

                            << " Got all of them right! Well done! Grade = A."; break;

            default : cout << "Should never happen.";                 

     }  

}//close quiz1()

//---------------------------------------------------------------------------------------------------------------------------

void quiz2()
{
    //This Function Illustrates a Parallel Array Example using 4 separate parallel arrays

    

     string Questions[5] = { "\nEl dia de los muertos? ", 

                            "\nFavorite game? ", 

                            "\nBest new television show: ", 

                            "\nFavorite hobby? ", 

                            "\nPopular vacation Destination? "};

                        

     string Answers[5] = { "october_30", 

                           "descent_3", 

                           "bsg", 

                           "music", 

                           "bahamas"};

                      

     string Clues[5] = { "Same month as halloween.", 

                         "Maze-like first person shooter game.", 

                         "Frack off cylon!", 

                         "The hills are alive...", 

                         "Ja man, on da beaches."};





     string UsersInput[5] = { "", "", "", "", ""};

     

     for(int x = 0; x < NumberOfQuestions && WrongCount < NumWrongGuesses; x++)

     {

         cout << Questions[x];

         cin >> UsersInput[x];

         

         //Convert User's Answer to lower case

         for(int z = 0; z < UsersInput[x].size(); z++)

         { UsersInput[x][z] = tolower(UsersInput[x][z]); }

             

         if(UsersInput[x] != Answers[x])

         {

            cout << "\nHere's a hint: " << Clues[x] << "\n\n";

            x--;   

            WrongCount++;                   

         }

         else

         { cout << "That's it! You got it right!"; score++; RightCount++; }     

         

         cout << "\n\nCurrent Status:   Wrong Guesses = " << WrongCount

              << "   Right Guesses = " << RightCount << "\n\n";

           

     }//close for loop

    

     score = score * 20;



     if(score <= 100 && score >= 90)

     { cout << "You earned and A for this quiz!"; }

     if(score <= 89 && score >= 80)

     { cout << "You earned and B for this quiz!"; }          

     if(score <= 79 && score >= 70)

     { cout << "You earned and C for this quiz!"; }  

     if(score <=69  && score >= 65)

     { cout << "You earned and D for this quiz!"; }

     if(score <= 64 && score >= 0)

     { cout << "You earned and F for this quiz!"; }
   
}//close quiz2()

//---------------------------------------------------------------------------------------------------------------------------


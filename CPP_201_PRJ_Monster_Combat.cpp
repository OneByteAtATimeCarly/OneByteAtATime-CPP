//PRJ - Monster Combat Game Console - 2006 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Class Defintions

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
  public:
  Monster(int hp)
  {
     cout << "A monster has been created.\n";
     hitpoints = hp;
             
  }     
  ~Monster() { cout << "Destroying a monster.\n"; } 
  
  //Accesor methods
  int getHit() { return hitpoints; }  
  void setHit(int hp) { hitpoints = hp; }
  char * getName() { return name; }
  void setName(char * nm) { name = nm; }   
         
  private:
  int hitpoints;
  char * name;                    
      
};

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void Attack();
int GenerateRandomNumber(int n);

//--------------------------------------------------------------------------------------------------------------------------- 

int main()
{
    //Since it was being called so rapidly within the while true loop,
    //srand had to be moved from the raondom number function to main().
    //Otherwise the random numbers are calculated too close together
    //and end up being many times the same.
    srand(time(NULL));
 
    cout << "\t\t\a     Welcome to Monster Mortal Combat 2.2\n"
         << "\t\t\a        Only the strong will survive.\n\n\n\n";
    
    Attack();
        
    system("PAUSE");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

void Attack()
{
   int damage;
   int hit;
   int MothraWins = 0;
   int GodzillaWins = 0;
   
   //Create 2 Monsters
   hit = GenerateRandomNumber(100);
   Monster Godzilla(hit);
   
   hit = GenerateRandomNumber(100);   
   Monster Mothra(hit);
      
   cout << "\n\n\nGodzilla and Mothra are locked in mortal combat!\n\n\n\n";
        
   system("PAUSE"); 
   
   //Have Monster objects loop into mortal combat, calculate the best of 3 matches
   for(int x = 0; x<3; x++)
   { 
      system("CLS"); 
         
      cout << "\nCombat session " << x+1 << ".\n\n";     
      cout << "Current Wins:\n\n";
      cout << "Mothra: " << MothraWins << "  Godzilla: " << GodzillaWins << "\n\n";       

      //Hitpoints begin with value initialized by the Monster constructor.                   
      cout << "Godzilla begins this fight with " 
           << Godzilla.getHit() << " hitpoints.\n";
        
      cout << "Mothra begins this fight with " 
           << Mothra.getHit() << " hitpoints.\n\n\n\n"; 
   
      system("PAUSE");   
      system("CLS");              
      //Each individual match of 3 between Monster objects plays out until one dies.
      while(Godzilla.getHit() > 0 || Mothra.getHit() > 0)      
      {      
           //Generate random number for combat                            
           damage = GenerateRandomNumber(30);                                               
           cout << "\nMothra attacks first, doing "
                << damage << " points of damage.\n";

            //We need to make sure Godzilla's hitpoints are at least equal to
            //or greater than damage, otherwise we'll end up with a negative
            //value. If so, we just set it to 0 and break out of the while
            //true loop - Godzilla dies. Without checking for this, Godzilla
            //may still be able to attack even when he is dead.      
           if(Godzilla.getHit() <= damage)
           {
              Godzilla.setHit(0);
              break;
           }
           else
           {  //Subtract the randomly calculated damage from Godzilla's hitpoints.
              Godzilla.setHit((Godzilla.getHit() - damage));
           }

           cout << "Godzilla now has " << Godzilla.getHit() << " hitpoints.\n";
 
            //Pauses program for 4 seconds. The Sleep() function requires you
           //to include the <windows.h> file and counts in milliseconds. 
           Sleep(5000);  
      
      
           damage = GenerateRandomNumber(30);                                               
           cout << "\nGodzilla attacks second, doing "
                << damage << " points of damage.\n";
           
           if(Mothra.getHit() <= damage)
           { 
               Mothra.setHit(0);
               break;
           }
           else
           {
               Mothra.setHit((Mothra.getHit() - damage));
           }
      
           cout << "Mothra now has " << Mothra.getHit() << " hitpoints.\n";     
               
      } //closes while true loop

      //Determine who wins each of the three battles and count wins.  
      if(Godzilla.getHit() <= 0)
      {
         cout << "\n\nGodzilla loses.\n";
         MothraWins = MothraWins + 1;
      } 
      if(Mothra.getHit() <= 0)
      {
         cout << "\n\nMothra loses.\n";
         GodzillaWins = GodzillaWins + 1;                   
      }
   
      Sleep(6000);
   
      hit = GenerateRandomNumber(100);
      Godzilla.setHit(hit);
      hit = GenerateRandomNumber(100);
      Mothra.setHit(hit);

   }//closes for loop

      cout << "\n\nFinal Results of All Three Battles:\n\n";
      cout << "Mothra: " << MothraWins << "  Godzilla: " << GodzillaWins << "\n\n"; 

   //Determine who won the war, best out of three battles.
   if(GodzillaWins > MothraWins)
   {
       cout << "Godzilla wins the war.\n\n\n\n";
   }
   else
   {
      cout << "Mothra Wins the war.\n\n\n\n"; 
   }   
   
}//closes attack function

//---------------------------------------------------------------------------------------------------------------------------

int GenerateRandomNumber(int n) 
{
    int ResultRandom;
    ResultRandom = (rand()%n) + 1;
    return ResultRandom;
}  

//---------------------------------------------------------------------------------------------------------------------------





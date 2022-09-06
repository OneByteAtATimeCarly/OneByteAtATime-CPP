//Defining a Monster Class - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
//---------------------------------------------------------------------------------------------------------------------------

class Monster {
public:
             
	Monster(int MonStrength = 10)  {
	       Strength = MonStrength;
	       cout << "You hear a monstrous, chilling, blood curdling "
                    << "sound in the distance.\n";
                }
	~Monster() { cout << "A monster has been destroyed!\n"; }

        //Accessor Methods - Needed to Access Private Data Members
	int getStrength() { return Strength; }
	void setStrength(int MonsStrength) { Strength = MonsStrength; }
	

        //OtherMethods
        void DestroyTokyo() { cout << "Ahhhh! Godzilla!"; }


        void Talk() {

	     int SayWhat;
             cout << "O.k. tough guy, pick a number (1-4)";
	     cin >> SayWhat;
	     cout << "\nThe monster looks at you and says, \n\""; 
	     switch(SayWhat) {
                                   
                    case 1 : cout << "C. Germany watches too many B movies.";
		             break;
                    case 2 : cout << "It\'s like Legos!  LEGOS, baby!";
		             break;
	            case 3 : cout << "Unfortunately, I have had a very bad day, and\n";
	                     cout << "you happen to be the first creature I\'ve met\n";
	                     cout << "that I can take it out on...\n";
		             break;
	            case 4 : cout << "How do you taste?  I don\'t think I\'ve eaten"
		                  << " your kind before...";
		             break;
	            default : cout << "Uh oh, tastes like chicken..."; 
             }  //close switch
	        
             cout << "\".\n";

	} //close talk function


private:
	int Strength;

}; //closes class specification

//---------------------------------------------------------------------------------------------------------------------------


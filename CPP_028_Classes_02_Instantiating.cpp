//Classes - 02 - Instantiating - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>  

//---------------------------------------------------------------------------------------------------------------------------

//Define the class
class Monster {
         Monster(){}
         ~Monster(){}

         public:
         int getLife() {return life;}
         void setLife(int x) {life=x;}
         AttackTokyo();

         private:
         int strength;
         int life;
};

//---------------------------------------------------------------------------------------------------------------------------

void main() {

//Create and instance of the class
Monster Godzilla;

//call the method for that instance using dot operator
Godzilla.AttackTokyo();
} 

//---------------------------------------------------------------------------------------------------------------------------



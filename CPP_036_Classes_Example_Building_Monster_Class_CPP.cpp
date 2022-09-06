//Building a Monster Class - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include  "CPP_035_Example_Defining_Monster_Class_HPP.h"

//---------------------------------------------------------------------------------------------------------------------------

void main() {

       Monster Godzilla;           //no argument passed in so default parameter will be used

       Godzilla.Talk();
       Godzilla.setStrength(100);
       Godzilla.DestroyTokyo();

  

       Monster Mothra(50);         //passes in argument to constructor
       Mothra.Talk();

} //close main()

//---------------------------------------------------------------------------------------------------------------------------




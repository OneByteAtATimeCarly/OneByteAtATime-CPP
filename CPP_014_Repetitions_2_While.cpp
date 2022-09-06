//Repetitions 2 - While Loops - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int counter = 0;          // initialize the condition

    while(counter < 5)         // test condition still true
    {
      counter++;              // body of the loop
      cout << "counter: " << counter << "\n";
    }
   
    cout << "Complete. Counter: " << counter << ".\n";
    
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


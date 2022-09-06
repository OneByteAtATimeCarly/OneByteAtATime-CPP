//Repetitions 6 - Basic For Loops - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

void Example_1_Basic()
{
	int counter;

	for(counter = 0; counter < 5; counter++)
	{   
            cout << "Looping! "; 
        }
	cout << "\nCounter: " << counter << ".\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Example_2_Multiple_Expressions()
{
     	for(int i=0, j=0; i<3; i++, j++)
        {
	    cout << "i: " << i << " j: " << j << endl;
        }
}

//---------------------------------------------------------------------------------------------------------------------------

void Example_3_Null_Statement_1()
{
	int counter = 0;
	for( ; counter < 5; )
	{
		counter++;
		cout << "Looping!  ";
	}
	cout << "\nCounter: " << counter << ".\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Example_4_Null_Statement_2()
{
	for(int i = 0; i<5; cout << "i: " << i++ << endl)
		
            {  ;  }
}

//---------------------------------------------------------------------------------------------------------------------------

void Example_5_Infinite_Loop()
{
	int counter=0;       // initialization
	int max;
	cout << "How many hellos?";
	cin >> max;

	for(;;)          // an infinite for loop that doesn't end
	{
		if(counter < max)       // test
		{
			cout << "Hello!\n";
			counter++;          // increment
		}
		else
			break;
	}
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Example_1_Basic();
    Example_2_Multiple_Expressions();
    Example_3_Null_Statement_1();
    Example_4_Null_Statement_2();
    Example_5_Infinite_Loop();
    
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




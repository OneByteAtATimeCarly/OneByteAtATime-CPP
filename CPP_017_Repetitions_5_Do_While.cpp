//Repetitions 5 - Do While Loops - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{

	int counter;
	cout << "How many hellos? ";
	cin >> counter;

	do
	{
		cout << "Hello\n";
		counter--;
	}  
        while(counter > 0);

                cout << "Counter is: " << counter << endl;

	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------




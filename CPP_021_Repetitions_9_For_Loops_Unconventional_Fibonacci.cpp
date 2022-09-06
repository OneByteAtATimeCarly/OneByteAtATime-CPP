//Repetitions 9 - Unconventional For Loops - Fibonaccie series - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

/Function declaration and prototype
int fib(int position); 

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	int answer, position;

	cout << "Which position? ";
	cin >> position;
	cout << "\n";
        //Call the Fibonacci function
	answer = fib(position);  
	cout << answer << " is the ";
	cout << position << "th Fibonacci number.\n";

	return 0;
} //end main()

//---------------------------------------------------------------------------------------------------------------------------

//Function definition
int fib(int n)
{
      int minusTwo; 
      int minusOne; 
      int answer;
      minusTwo=1;
      minusOne=1;
      answer=2;
      if(n < 3)
	 return 1;  //ends function
      for(n = n-3; n > 0; n--)  //like saying for(n -= 3; n; n--)
      {
		minusTwo = minusOne;
		minusOne = answer;
		answer = minusOne + minusTwo;
      }
      return answer;
} //Close function

//---------------------------------------------------------------------------------------------------------------------------




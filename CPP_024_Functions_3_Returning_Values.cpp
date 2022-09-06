//Functions 3 - Returning Values - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototype
int TripleIntegers(int AmountToTriple);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int result = 0;
    int input;
    cout << "Enter a number between 0 and 10,000 to triple: ";
    cin >> input;
    cout << "\nBefore TripleIntegers is called... ";
    cout << "\ninput: " << input << " Tripled: " << result << "\n";

    result = TripleIntegers(input);

    cout << "\nBack from TripleIntegers...\n";
    cout << "\ninput: " << input << "   Tripled: " << result << "\n";
 
    return 0;
 }

//---------------------------------------------------------------------------------------------------------------------------

//Function Definition
int TripleIntegers(int original)
{
    if(original <= 10000)
        return original * 3;
    else
        return -1;
 
    cout << "You can't reach this line! The function returns 1st.\n"; 

}

//---------------------------------------------------------------------------------------------------------------------------



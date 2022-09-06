//Arrays 7 - Strings Are Arrays of Type Char - 2004 C. S. Germany

//String - a series of characters, an array of variables of type char.  Example of an unnamed string constant:  cout << "Hello world.\n";
//This brings us to char arrays.  In C++, a string is an array of chars ending with a null character.  You declare and initialize a string as you do any other array:
//char Greeting[ ] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' }; The last character '\0', is the null character, which many functions recognize
//as the terminator for the string.  So each character in a char array is stored in a separate element.  You can use a shorthand mode to auto-allocate:
//char Greeting[ ] = "Hello World";  You don't need to add the null character, the compiler adds it for you.  The string "Hello World" is 12 bytes.
//Hello is 5, the space is 1, and World is 5.  Don't place more into the buffer than there is room for. Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    char buffer[80];
    cout << "Enter the string: ";
    cin >> buffer;
    cout << "Here's the buffer: " << buffer << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------







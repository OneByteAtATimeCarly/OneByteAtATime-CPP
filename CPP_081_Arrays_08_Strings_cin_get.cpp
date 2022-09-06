//Arrays 8 - Strings - cin.get() Method - 2004 C. S. Germany

//In the previous example, the char array, buffer[80], is declared to hold 80 characters, large enough for a 79 character string and the additional terminating null
//character. The user prompted to enter a string.  The user-entered string is entered into the buffer[80].  It is the syntax of cin to write a terminating null to
//the buffer after it writes the string. 

//There are two outstanding problems here.  First, if user enters more than 79 characters, cin writes past the end of the buffer and will overwrite what they
//previously entered. If the Second, user enters a space, cin thinks it is the end of the string and stops writing to the buffer[].  To solve these problems,
//call a special method on cin - get(). 

//The method cin.get() takes 3 parameters:
//1) The buffer to fill
//2) The max # of characters to get
//3) The delimiter that terminates input. (The default delimiter is newline.)

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    char buffer[80];
    cout << "Enter the string: ";

    cin.get(buffer, 79);        //get up to 79 or newline

    cout << "Here's the buffer: " << buffer << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------







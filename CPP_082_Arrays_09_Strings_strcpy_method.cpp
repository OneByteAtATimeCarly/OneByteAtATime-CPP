//Arrays - 9 - Strings - strcpy() Method - 2004 C. S. Germany

//strcpy() - The strcpy() method copies the entire contents of one string into a designated buffer.
//To use strcpy(), remember that you must include the string.h header file into your source code.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    const int MaxLength = 80;

    char String1[] = "Fun with LEGOS!";

    char String2[MaxLength+1];

    strcpy(String2,String1);

    cout << "String1: " << String1 << endl;
    cout << "String2: " << String2 << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


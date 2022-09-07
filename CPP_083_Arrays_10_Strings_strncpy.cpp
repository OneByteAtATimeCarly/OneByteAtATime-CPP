//Arrays - 10 - Strings - strncpy() Method - 2004 C. S. Germany

//strncpy() - The strncpy() method takes the maximum number of characters to copy, and copies up to the first null character or
//to the max # of characters specified in the destination buffer.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    const int MaxLength = 80;

    char String1[] = "Fun with LEGOS!";

    char String2[MaxLength+1];

    strncpy(String2,String1,MaxLength);

    cout << "String1: " << String1 << endl;
    cout << "String2: " << String2 << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


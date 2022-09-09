//PRJ - Console Morse Code App - 2006 - C. S. Germany
//Uses parallel arrays to convert Morse Code to ASCII and ASCII to Morse Code

//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
using namespace std; 

//---------------------------------------------------------------------------------------------------------------------------

//Parallel Arrays below match ASCII characters to Morse Code Sequences
//One is an array of type char for single letters, the other an array of strings

char MorseLetter[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
                      'S','T','U','V','W','X','Y','Z',' '};
                  
char * MorseCharacterSequence[] = { ".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",
                                    ".. ",".--- ",".-.- ",".-.. ","-- ","-. ","--- ",".--. ",
                                    "--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ",
                                    "-.-- ","--.. ","  "};
 
//---------------------------------------------------------------------------------------------------------------------------
 
void ConvertToMorse(const char *MessageInASCII)
{
   //Note: Changed from "size_t", which is an unsigned short integer
   int i, j;
   string AccumulatedString;
   
   for(i = 0; MessageInASCII[i]; ++i)
   {
      //Note: The expression (sizeof ACharArray / sizeof *ACharArray) will
      //automatically calculate the length of the array, like array.length in JavaScript.
      for(j = 0; j < (sizeof MorseLetter /sizeof *MorseLetter); ++j)
      {
         if(toupper(MessageInASCII[i]) == MorseLetter[j])
         {
            AccumulatedString = AccumulatedString + MorseCharacterSequence[j];
            break;
         }
      }
   }
   cout << "\n" << AccumulatedString << "\n";
} 
 
//---------------------------------------------------------------------------------------------------------------------------
 
void ConvertToASCII(const char *MessageInMorse)
{
   int i, j;
   string AccumulatedString;
   
   //Note: The "i++" in the for loop is intentionally left out and updated/incremented below
   for(i = 0; MessageInMorse[i];)
   {
      for(j = 0; j < (sizeof MorseCharacterSequence / sizeof *MorseCharacterSequence); ++j)
      {
         //strlen() =   Returns the number of characters in string before the 
         //terminating null-character. Example: int AVAriable = strlen( const char * string ); 
         int MorseStringSize = strlen(MorseCharacterSequence[j]);
         
         //The memcmp() function compares n bytes of two regions of memory, treating each byte 
         //as an unsigned character. It returns an integer less than, equal to, or greater than
         //zero according to whether s1 is lexicographically less than, equal to, or greater
         //than s2.  Example: int memcmp(const void *s1, const void *s2, size_t n);
         if ( memcmp(MorseCharacterSequence[j], &MessageInMorse[i], MorseStringSize) == 0 )
         {
            AccumulatedString = AccumulatedString + MorseLetter[j];
            //This actually increments the i missing from the Update section in
            //the first for loop above. We can't just increment it by ones, it must
            //be incremented by the number of characters in a particular morse string
            //as we sequence through each set of characters in Morse.
            i += MorseStringSize; 
            break;
         } //ends if
      }
   }
   cout << "\n" << AccumulatedString << "\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Test()
{
     char ASCIItext[] = "Hello World";
     char MorseCode[] = ".... . .-.. .-.. ---   .-- --- .-. .-.. -.. ";     
     
     cout << "\n\n";
     cout << "Morse Code is: ";
     ConvertToMorse(ASCIItext);
     cout << "\n\n";    
     cout << "ASCII Translation is: ";
     ConvertToASCII(MorseCode);
} 

//---------------------------------------------------------------------------------------------------------------------------

void GetMorse()
{ 
   char ASCIIPhrase[100];
   cout << "\n\nEnter an ASCII string to convert to Morse Code:\t";
   cin.ignore(); //necessary to prevent getline problems
   cin.getline(ASCIIPhrase, 100);
   ConvertToMorse(ASCIIPhrase);    
}

//---------------------------------------------------------------------------------------------------------------------------

void GetASCII()
{
   char MorsePhrase[100]; 
   
   cout << "\n\nImportant: Enter a Morse string to convert to ASCII. Make sure you\n"
        << "separate each morse letter sequence with a space, separate whole words\n" 
        << "with 3 spaces, and add a space at the end before pressing \"Enter\":\n\n";
   cin.ignore();  //necessary to prevent getline problems   
   cin.getline(MorsePhrase, 100);   
   ConvertToASCII(MorsePhrase);       
      
}

//---------------------------------------------------------------------------------------------------------------------------
 
int main() 
{  
  char choice;
  
  cout << "\nMorse to ASCII Converter 2.0\n\n"; 
  
  while(choice != 'q')
  {
      cout << "\n\nMorse to ASCII Converter 1.0 Menu:\n\n"
           << "(Q)uit\n"
           << "(M)orse to ASCII Conversion\n"
           << "(A)SCII to Morse Conversion\n"
           << "(T)est System\n\n";  
          
      cin >> choice;      

      switch(toupper(choice))
      {
          case 'Q' : choice = 'q'; break;
          case 'M' : GetASCII(); break;
          case 'A' : GetMorse(); break;
          case 'T' : Test(); break;
          default : cout << "Invalid response."; break;   
      }

  } // close while true loop   
    
   cout << "\n\nExiting program...\n\n";
   system("PAUSE");
   return 0;
   
}

//---------------------------------------------------------------------------------------------------------------------------






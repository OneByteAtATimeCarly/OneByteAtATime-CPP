//Strings 1 - The Basics - 2004 C. S. Germany

//A string is an array of type char. So, making the declaration:  

//     char FirstName[8] = "Carly";

//would create a "string", which is an array with the 5 elements {'C','a','r','l','y'}, leaving one element left for a terminating NULL character.

//We have declared and used pointers to char for strings of indefinite size. So, making the declaration:

//     char * LastName = "Germany";

//would create an array of characters just large enough (with enough elements) to hold {'G','e','r','m','a','n','y'}, in addition to the terminating NULL character.

//We have written our own String class and used it in many examples, overloading operators such as <<, [], and + to provide methods for copying strings and
//concatenating them together.  By this, we have seen first hand how strings as arrays of type char are copied and sorted as any other array of data would be - 
//using loops and iteration to pass through elements one by one.  Now that we have seen what goes on behind the scenes, we can move on.  Now that we know what's
//"under the hood", so to speak, let's drive the car!

//C++ offers an excellent string class that includes many functions for sorting, searching and manipulating string data.  In order to use this class, you will
//need to #include <string.h>.  It is based on a template class named basic_string.  For many reasons, you will also want to use the standard namespace with
//the string class by declaring using namespace std; at the top of your source file.  This std namespace will be a standard with many of the functions we will
//use.  If you do this, you should omit the file extension ".h" from your standard include files.  Let's look at some of the useful methods that <string.h>
//provides:

//     getline() - gets an entire line of text, including spaces.
//     get() - takes a line of input. 
//     ignore() - consumes/flushes characters in the data stream.
//     toupper() - converts a character to all uppercase.
//     isdigit() - determines whether string content is numerical.
//     tolower() - converts a character to all lowercase.
//     transform() - converts and entire string to uppercase or lowercase.
//     c_str - converts string objects into normal pointers to char arrays.  Necessary for many operations.
//     length() - returns the length of a string.
//     size() - returns the size of a string .
//     compare() - compares the contents of one string to another.
//     size() - returns the size of a string (the number of characters).
//     find() - determines whether a string is contained within a string.
//     replace() - replaces a portion of a string's contents.
//     assign() - assigns a portion of one string's contents to another string variable.
//     concatenate() - adds separate strings together.  Accomplished by overloading the C++ operator +.
//     insert() - inserts a string into the current string, starting at the specified location.
//     erase() - erases a string.
//     substr() - returns a substring of the current string.
//     begin() - returns a STL iterator specifying the beginning of the string.
//     end() - returns a STL iterator specifying the end of the string.
//     find_first_of - search for first occurrence of char that appears in the str argument.
//     find_first_not_of - search for first occurrence of char that does not appear in the str argument.
//     find_last_of - search for last occurrence of char that appears in the str argument.
//     find_last_not_of - search for lastoccurrence of char that does not appear in the str argument.
//     peek() - looks at but does not extract a character.
//     putback() - inserts a character into the input stream.

//IOS Flags:  For this you will need <iomanip.h>. There will be circumstances where you will want to utilize leading and trailing zeros,
//in which case you will want to employ some of the following flags:

//setw() = sets number of places to display leading or trailing zeros in the output stream

//Escape Sequences:

//     \a - sound a beep
//     \n - newline
//     \' - literal '
//     \\ - literal \
//     \b - backspace
//     \t - tab
//     \" - literal " 
//     \? - literal ?

//Example

//        #include <iomanip.h>
//
//        double TestMe = 0003.02;
//
//        cout << setfill('0') << setw(8) << TestMe;
//        cout.setf(ios::left);
//        cout.precision(10);
//        cout << endl << TestMe << endl << endl;

//Here are some old tools from the C library that we can use in C++:

//strcpy() - Takes 2 char arrays, copies one to another.  Syntax: strcpy(DestinationArray, SourceArray);

//strncpy() - Takes 2 char arrays, copies one to another.  Will not overwrite char arrays like strcpy, it will only copy to first null char or until
//            it reaches the max number of chars.  Syntax: strncpy(DestinationArray, SourceArray, MAXchars);


//To create an instance of a string and assign a value, there are several methods:

//        string NameFirst = "Charles";    //uses string class's overloaded assignment operator
//        string NameLast("Germany");      //uses string class's constructor

//The string class overloads many of our familiar operators in C++, so you can use +, -, +=, -=, <, >, [ ], and many other operators with strings.

//getline() - gets an entire line of text, including spaces, for input. Syntax:  getline(cin, VariableName, deLimiterChar);
//toupper() - converts characters to all uppercase.
//tolower() - converts characters to all lowercase. 

//transform() - converts an entire string to uppercase or lowercase.   It requires that you include the algorithm header file with: #include <algorithm>. It takes 4 arguments:

//      transform( stringName.begin, stringName.end, stringName.begin, function )

//argument 1 - stringName.begin =  signifies to start at the first character in the string.
//argument 2 - stringName.end =     signifies to select until the location just past the end of the string.
//argument 3 - stringName.begin =  signifies where to begin replacing the characters, in this case at the beginning.
//argument 4 - function =  the function to perform, be it toupper() or tolower().



//compare() - compares the contents of one string to another.  If the contents are equal, a 0 is returned by the function.  If the contents are not equal,
//a 1 or a -1 is returned.  A 1 is returned of the ASCII value of stringName1 is greater than stringName2, and a -1 is returned if the value is less than stringName2.
//Syntax:

//       stringName1.compare( StartCompare, NumCharsToCompare, stringName2 );

//argument 1 - signifies where in stringName1 the comparison should begin.  Default is 0, the first char.
//argument 2 - signifies the number of characters to compare between stringName1 and stringName2.
//argument 3 - the name of the string you are comparing to.

//       Example:
//       int result1, result 2;
//       string string1 = "Pablito";
//       string string2 = "Clavito";
//       result1 = string1.compare(0,7,string2);
//       result2 = string1.compare(5,3,"ito");

//In the example above, result1 would be -1 due to its ASCII value and the fact that the strings are not equal when starting at the beginning and comparing all 7
//characters.  On the other hand, result2 would be 0, since starting at the 5th character, and comparing 3, if we look for the string "ito", the two strings are equal. 


//size() - returns the size of a string (the number of characters). 

//       Example:
//       string string1 = "LEGOS";
//       if( string1.size() == 5 ) { cout << "Most definitely."; }


//find() - determines whether a string is contained within a string.  If a substring is not found within the string, the number -1 is returned.
//If the string text being searched for is found, a positive number is returned, indicating where the substring that was located begins in the
//string being searched.   Syntax:  stringName.find(SearchString, WhereToStart);

//argument 1 - The string you are searching for.  It can be a string variable or a literal string in quotes like "Hal".
//argument 2 - Where to start searching in stringName.  0 is the default, the beginning of the string.

//       Example:
//       #include <iostream>
//       #include <string>
//       using namespace std;

//       void main() 
//       {
//            int StringTest1;
//            int StringTest2;
//            string string1 = "Life is pain, princess.  Anyone who tells you different is selling something.";
//            StringTest1 = string1.find("princess",0);
//            StringTest2 = string1.find("PablitoClavoUnClavito",0);
//            cout << "Test1: " << StringTest1 << ".\n";
//            cout << "Test2: " << StringTest2 << ".\n";
//       }

//In the example above, StringTest1 would be 14, and StringTest2 would be -1.

//replace() - replaces a portion of a string's contents with a string that you specify.  
//Syntax: stringName.replace(StartPlace, NumChars, StringToReplace)

//       Example:
//       string Name = "Jacob Germany is the cutest baby in Daytona.\n";
//       Name.replace(36,7,"the universe");
//       cout << Name;

//Would display:  Jacob Germany is the cutest baby in the universe.

//assign() - assigns a portion of one string's contents to another string variable. 
//Syntax:  DestinationString.assign(SourceString, WhereToStart, NumOfCharacters);

//       Example:
//       string Location = "Daytona Beach, FL";
//       string City = "";
//       string State = "";
//       City.assign(Location, 0, 13);
//       State.assign(Location, 15, 2);
//       cout << "City: " << City << endl;
//       cout << "State: " << State << endl;

//Would display:   

//      City: Daytona Beach
//      State: FL

//concatenate() - adds separate strings together. Accomplished by overloading the C++ operator +, as we have previously studied. 

//       Example:
//       string string1 = "Margaret Thatcher rocks my world";
//       string string2 = "she is a very lovely woman!\n\n";
//       string string3 = string1 + " and " + string2;
//       cout << string3;

//Would display:  "Margaret Thatcher rocks my world and she is a very lovely woman!"

//c_str - converts string objects into normal pointers to char arrays.  Necessary for many operations, especially converting
//string objects to pointers to char arrays so they can be used as file names with ofstream and ifstream objects.

//       Example:
//       string filename;
//       cout << "Enter file name: ";
//       cin >> filename;
//       ofstream outfile (filename.c_str());
//       outfile << "Data" << endl;

//length() and size() - return the length (number of characters) in a string.  Syntax:

//       size_type length() const;
//       size_type size() const;

//The size_type return type is an unsigned int data type. (The type name usually must be scoped, as in string::size_type.)

//       Example:
//       string str = "Hello";
//       string::size_type  len;          //declare a size_type names "len"
//       len = str.length();                // len == 5
//       len = str.size();                   // len == 5

//insert() - Inserts a string into the current string, starting at the specified position. 
//Syntax: string & insert(size_type pos, const string& str);

//       Example:
//       string str1 = "abcdefghi";
//       string str2 = "0123";
//       str1.insert(3,str2);
//       cout << str1 << endl; // "abc0123defghi"
//       str2.insert (1,"XYZ");
//       cout << str2 << endl; // "0XYZ123"

//erase()  - deletes a substring from the current string.   The substring to be deleted starts as position pos and is n characters long.
//If n is larger than the number of characters between pos and the end of the string, the function takes care of it.  The default argument
//values cause deletion of the rest of the string, if only a starting position is specified.  The whole string is deleted if no arguments
//are specified. (The value string::npos represents the maximum number of characters there can be in a string, and is thus one greater than
//the largest possible character position.)  Syntax:  string & erase(size_type pos=0, size_type n=npos);

//       Example:
//       string str1 = "abcdefghi";
//       str1.erase(5,3);
//       cout << str1 << endl;          // "abcdei" - deletes 3 chars at position 5, f, g, and h

//substr() - Returns a substring of the current string, starting at position pos and of length n.  If used with the subscript operator ([]),
//it will retreive a single character at a time.  Syntax: string substr (size_type pos, size_type n) const;

//       Example:
//       string str1 = "abcdefghi"
//       string str2 = str1.substr (6,2);
//       cout << str2 << endl;               // "gh", startign at position 6, return "g" and "h" to str2


//find_first_of,  find_last_of,  find_first_not_of,  find_last_not_of - search for the first/last occurrence of a character that appears or
//does not appear in the str argument.  If found, return the position of the character that satisfies the search condition; otherwise, return
//string::npos.  The pos argument specifies the starting position for the search, which proceeds toward the end of the string (for "first" searches)
//or toward the beginning of the string (for "last" searches); note that the default values cause the whole string to be searched. 

//Syntax:
//size_type find_first_of (const string& str, size_type pos=0) const;
//size_type find_first_not_of (const string& str, size_type pos=0) const;
//size_type find_last_of (const string& str, size_type pos=npos) const;
//size_type find_last_not_of (const string& str, size_type pos=npos) const;

//       Example:
//       string str20 = "Hello there";
//       string str21 = "aeiou";
//
//       pos = str20.find_first_of (str21, 0);
//
//       cout << pos << endl;     // 1
//       pos = str20.find_last_not_of ("eHhlort");
//
//       cout << pos << endl;     // 5




//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Example: get(), peek() and putback()

void Use_Get_Peek_Putback
{
	char ch;
	cout << "Enter a phrase: ";

	while(cin.get(ch))
	{
		if(ch == '!')
		   cin.putback('$');
		else
			cout << ch;
		while(cin.peek() == '#')
			cin.ignore(1,'#');
	}
}

//---------------------------------------------------------------------------------------------------------------------------

//Example: getline()

void Use_getline()
{
     //Example 1
     string Answer = "";
     cout << "What is your address?";
     getline(cin, Answer);

     //Example 2:
     vector<string> vec1;
     string line;
     vec1.clear();

     ifstream infile ("stl2in.txt");

     while(getline(infile, line, '\n'))   //get until the end of the line encountered
     {
          vec1.push_back (line);
     }
}

//---------------------------------------------------------------------------------------------------------------------------

//Example: toupper() and tolower()

void Use_toupper_and_tolower()
{
     char choice;
     cout << "Which direction? (N,S,E,W)";
     cin >> choice;
     if(toupper(choice) == 'N'){cout << "North";}

     char choice;
     cout << "(C)elcius or (F)arenheit?";
     cin >> choice;
     if(tolower(choice) == 'c'){cout << "Celcius";}     
}

//---------------------------------------------------------------------------------------------------------------------------

//Example: transform()

void Use_transform()
{
     //Convert the string "godzilla" to "Godzilla"
     string Monster = "godzilla";
     transform(Monster.begin(), Monster.end(), Monster.begin(), toupper);  
}

//---------------------------------------------------------------------------------------------------------------------------

void Use_Replace()
{
     string phoneNum = "";
     cout << "Phone number (for example, 256-0169): ";
     getline(cin, phoneNum);

     //Replace hyphen with the empty string
     phoneNum.replace(3, 1, "");

     //Display phone number
     cout << "Phone number: " << phoneNum << endl;
}

//---------------------------------------------------------------------------------------------------------------------------

void Use_Compare()
{
     string phrase1 = "";
     string phrase2 = "";
     int compareValue = 0;

     cout << "Phrase 1: ";
     cin >> phrase1;
     cout << "Phrase 2: ";
     cin >> phrase2;

     compareValue = phrase1.compare(0, 3, phrase2);

     if(compareValue == 0)
            cout << "Equal" << endl;

     else if(compareValue == -1)
            cout << phrase1 << " " << phrase2 << endl;
     else
            cout << phrase2 << " " << phrase1 << endl;
}

//---------------------------------------------------------------------------------------------------------------------------

void Use_Transform_Assign_Size()
{
     string letters = "abcdefghijklmnopqrstuvwxyz";
     string randomLetter = "";
     string letterGuess = "";
     int randomNumber = 0;

     //Generate random number, then assign random letter.
     srand(time(NULL));
     randomNumber = 0 + rand() % (25 - 0 + 1);
     randomLetter.assign(letters, randomNumber, 1);

     cout << "Letter guess? ";
     getline(cin, letterGuess);

     //Verify that the user entered only one letter
    if(letterGuess.size() == 1)
    {
       while(letterGuess != randomLetter)
       {
           transform(letterGuess.begin(), letterGuess.end(), letterGuess.begin(), tolower);

           //Display appropriate message
           if(letterGuess < randomLetter)
              cout << "The correct letter comes after the letter " << letterGuess << "." << endl;
           else
              cout << "The correct letter comes before the letter " << letterGuess << "." << endl;

           cout << "Letter guess? ";
           getline(cin, letterGuess);

       } //end while

      cout << "You guessed the correct letter." << endl;

    } //end if

    else
        cout << "Enter one letter only." << endl;

   //end if
}

//---------------------------------------------------------------------------------------------------------------------------

void Using_Replace_and_Find()
{
     string phone = "";
     int hyphenLoc = 0;

     cout << "Enter phone number (9 to stop program): ";
     getline(cin, phone);

     while (phone != "9")
     {
         //Locate all hyphens, then replace with empty strings.
         hyphenLoc = phone.find("-", 0);

         while (hyphenLoc >= 0)
         {
            phone.replace(hyphenLoc, 1, "");
            hyphenLoc = phone.find("-", 0);
         } //end while

         cout << phone << endl;
         cout << "Enter phone number (9 to stop program): ";
         getline(cin, phone);

    } //end while
}

//---------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Use_Get_Peek_Putback();
    Use_getline();
    Use_toupper_and_tolower();
    Use_transform();
    Use_Replace();
    Use_Compare();
    Use_Transform_Assign_Size();
    
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









//File Access 1 - The Basics - 2004 C. S. Germany

//Well, now that we've got the basics of C++ down, wouldn't it be nice if we could save all this data we've been
//meticulousy preparing?  File access is where we can begin to expand our horizons into all sorts of new directions.
//This is where we can lay the foundation for databases, applications and games.  This is where the rubber meets
//the road, so to speak.

//To create, manipulate, write to and read from files in C++, we need the fstream class.
//You will need to  #include <fstream.h>  in your source file to enable this class's methods and functions.
//To read and write files, you will need to create instances of:

//       ifstream - for reading from files and input.             Syntax for creating an instance:  ifstream InputFile;
//       ofstream - for writing to files and output.               Syntax for creating an instance:  ofstream OutputFile;

//Once you instantiate objects from ifstream and ofstream, you may use the open and close methods on your objects via the dot operator:

//open() - opens a file.      Syntax:   OutputFile.Open("TheFileName",ios::METHODS);
//close() - closes a file.     Syntax:    OutputFile.close();   

//There are several modes you need to pass in to the open() method when you use it:

//       ios::in - Opens the file for input.  This is the default for ifstream objects.
//       ios::out - Opens the file for output.  This is the default for ofstream objects.
//       ios::app - Opens file for append, allows writing new data to the end of an existing file.  If  no file, the file will be created.
//       ios::binary - Opens/creates a binary file.  With binary files, entire objects can be written and read at once via pointers.
//       ios::ate - Seek to end of file when open ( "ate" = at end).
//       ios::nocreate - If the file does not exist, do not create a new file.
//       ios::noreplace - If the file already exists, do not overwrite it.
//       ios::trunc - Open and truncate an existing file.  New info written to the file will replace its contents.

//Let's look at a syntax example:

//       ifstream InputFile;
//       ofstream OutputFile;
//       InputFile.open("data.txt",ios::in);
//       OutputFile.open("data.txt", ios::out);
//       OutputFile.close();

//There are some useful methods that go with ifstream and ofstream objects:

//is_open - If file opens successfully, a boolean "true" is returned.  If not, false is returned.      Syntax:  Object.is_open();
//eof() - Returns the boolean value "true" if at the end of a file, otherwise it returns false.       Syntax:  Object.eof();
//ignore() - ignores specified number of chars.  Cleans input stream/searches.        Syntax: Object.ignore(N, deLimiter);
//get() - Gets line.  Takes 3 parameters: 1) string/char array, 2) max chars to get, 3) delimiter char to terminate input. 
//        Syntax:  Object.get(StringOrCharArray, MAXchars, deLimiterChar);

//To prevent data loss, be sure you always close any files that are open before a program ends.  Now that we can open and close files,
//how do we write data to them?   Hint: You have been using this tool since lesson 1 and your "Hello World" application.  In C++, we
//can send data to and retrieve data from a file via the datastream operator and cin/cout, just as we would from the keyboard and to
//the console.  

//There are always 4 basic processes to writing: 

//       1. Create the instance
//       2. Open the file
//       3. Write to it (stream the data)
//       4. Close the file.

//Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     ofstream OutputFile;  //Step 1
     OutputFile.open("income.txt",ios::out);  //Step 2
     int Income = 0;
     cout << "Enter weekly income.  (Enter -1 to stop.)";
     cin >> Income;
     while(Income != -1)
     {
           OutputFile << Income << endl;  //Step 3
           cout <<  "Enter weekly income.  (Enter -1 to stop.)";
           cin >> Income;
     }
     OutputFile.close();  //Step 4
} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









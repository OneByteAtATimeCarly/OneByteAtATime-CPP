//Sequential File Access  3 - Using the getline() method and a delimiter character to sort data from a sequential file - 2004 C. S. Germany

//Using the getline() method and a delimiter character to sort data from a sequential file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    string PeopleName = "";
    string PeopleCode = "";
    string searchFor = "";
    ifstream InputFile;
    InputFile.open("PeopleData.txt", ios::in);
    if(InputFile.is_open())
    {
         cout << "Enter the PeopleCode (F1, F2, P1, P2): ";
         getline(cin, searchFor);

         transform(searchFor.begin(), searchFor.end(), searchFor.begin(), toupper);
         getline(InputFile, PeopleName, '#');
         getline(InputFile, PeopleCode);
         while(!InputFile.eof())
         {
            transform(PeopleCode.begin(), PeopleCode.end(), PeopleCode.begin(), toupper);
            if(PeopleCode == searchFor)
               cout << PeopleName << endl;
            getline(InputFile, PeopleName, '#');
            getline(InputFile, PeopleCode);
         }
         InputFile.close();
    } //close if
    else
         cout << "Error opening file" << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









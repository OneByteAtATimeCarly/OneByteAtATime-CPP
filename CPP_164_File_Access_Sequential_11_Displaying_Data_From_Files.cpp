//Sequential File Access 11 - Displaying students and grade averages from a sequential file - 2004 C. S. Germany

//Displaying students and grade averages from a sequential file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 0;
    int minScore = 0;
    int maxScore = 0;
    int count = 0;

    int scores[20] = {0};

    ifstream inFile;
    inFile.open("scores.dat", ios::in);

    if(inFile.is_open())
    {
        while(x < 20 && !inFile.eof())
        {
            inFile >> scores[x];
            x = x + 1;
        }

        inFile.close(); //close file

        cout << "Enter minimum score: ";
        cin >> minScore;
        cout << "Enter maximum score: ";
        cin >> maxScore;

        x = 0;

        while(x < 20)
        {
             if(scores[x] >= minScore && scores[x] <= maxScore)
             count = count + 1;
             x = x + 1;
        }

        cout << "Number of students: " << count << endl;
    } //end if
    else
         cout << "File could not be opened" << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


//Sequential File Access  4 - Reading data from one file, processing it, and saving it in another sequential file - 2004 C. S. Germany

//Reading data from one file, processing it, and saving it in another sequential file
//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int num = 0;
    ifstream InputFile;
    InputFile.open("Numbers.txt", ios::in);
    ofstream OutputFile;
    OutputFile.open("NewNumbers.txt", ios::out);
    if(InputFile.is_open() && OutputFile.is_open())
    {
        InputFile >> num;
        while(!InputFile.eof())
	{
           if( (num % 2) == 0)
                OutputFile << num << endl;
           InputFile >> num;
	}
        cout << "Saved all the even numbers to \"NumbersNew.txt\"\n\n";   

        InputFile.close();
        OutputFile.close();

    } //close if
    else
        cout << "Error!  Can\'t open the file." << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









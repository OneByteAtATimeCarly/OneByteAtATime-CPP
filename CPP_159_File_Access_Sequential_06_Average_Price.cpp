//Sequential File Access 6 - Display the average price from a sequential access file - 2004 C. S. Germany

//Display the average price from a sequential access file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ifstream inFile;
    inFile.open("prices.dat", ios::in);

    float price = 0.0;
    int counter = 0;
    float sum = 0.0;

    if(inFile.is_open())
    {
        inFile >> price;

        while(!inFile.eof())
        {
            counter = counter + 1;
            sum = sum + price;
            inFile >> price;
        }

        inFile.close();

        if(counter > 0)
        {
            cout << fixed;
            cout.precision(2);
            cout << "Average price: " << sum / counter << endl;
        }

        else
            cout << "File is empty." << endl;

     } //close if

     else
         cout << "Error opening file." << endl;

     return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









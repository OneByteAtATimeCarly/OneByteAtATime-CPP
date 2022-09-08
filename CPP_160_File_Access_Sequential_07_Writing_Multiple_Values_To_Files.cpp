//Sequential File Access 7 - Writing multiple values to a sequential access file - 2004 C. S. Germany

//Display the average price from a sequential access file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ofstream outFile;
    outFile.open("inventory.dat", ios::out);

    string invNum = "";

    int quantity = 0;
    float price = 0;

    if(outFile.is_open())
    {
       cout << "Enter inventory number: ";
       getline(cin, invNum);

       while(invNum != "X" && invNum != "x")
       {

           transform(invNum.begin(), invNum.end(), invNum.begin(), toupper);
           cout << "Enter quantity: ";
           cin >> quantity;

           cout << "Enter price: ";
           cin >> price;
           cin.ignore(1);

           outFile << invNum << '#' << quantity << "#" << price << endl;

           cout << "Enter inventory number: ";
           getline(cin, invNum);
       }

    outFile.close();

    }

    else
         cout << "Error opening file." << endl;

    return 0; 
}

//---------------------------------------------------------------------------------------------------------------------------









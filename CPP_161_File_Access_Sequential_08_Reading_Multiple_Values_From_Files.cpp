//Sequential File Access 8 - Reading multiple values in a sequential file - 2004 C. S. Germany

//Reading multiple values in a sequential file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ifstream inFile;
    inFile.open("inventory.dat", ios::in);
    string number = "";
    int quantity = 0;
    float price = 0;
    float totalDol = 0;
    if(inFile.is_open()) 
    {
        getline(inFile, number, '#');
        inFile >> quantity;
        inFile.ignore(1);
        inFile >> price;
        inFile.ignore(1);
        while(!inFile.eof())
	{
             cout << "Item: " << number << endl;
             cout << "Quantity: " << quantity << endl;
	     cout << "Price: " << price << endl;
	     totalDol = totalDol + (quantity * price);  //accumulator
             getline(inFile, number, '#');
             inFile >> quantity;
             inFile.ignore(1);
             inFile >> price;
             inFile.ignore(1);
	}
        inFile.close();
        cout << "Total dollar value: " << totalDol << endl;
    }  //close if
    else 
         cout << "Error opening file." << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









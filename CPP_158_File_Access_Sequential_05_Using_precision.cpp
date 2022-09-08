//Sequential File Access 5 - Using precision() and sequential access - 2004 C. S. Germany

//Using precision() and sequential access

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ofstream outFile;
    outFile.open("prices.txt", ios::app);
    float price = 0.0;
    if(outFile.is_open()) 
    {
        cout << "Enter price: ";
        cin >> price;
        while(price > 0)
	{
              outFile << fixed;
              outFile.precision(2);
              outFile << price << endl;
              cout << "Enter price: ";
              cin >> price;
	} 
        outFile.close();

    } //close if
    else
         cout << "Error opening file." << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









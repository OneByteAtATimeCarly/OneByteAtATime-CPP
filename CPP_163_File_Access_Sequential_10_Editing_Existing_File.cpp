//Sequential File Access 10 - Edits an existing sequential access file - 2004 C. S. Germany

//Edits an existing sequential access file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void updatePrices(float []);
void writeToFile(float []);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 0; 
    float prices[10] = {0.0};
    ifstream inFile;
    inFile.open("Prices.txt", ios::in);
    if(inFile.is_open())
    {
        while(x < 10 && !inFile.eof())
        {
              inFile >> prices[x];
              x = x + 1;
	} 
    inFile.close(); 
    updatePrices(prices);
    writeToFile(prices);
    } //close if
    else
         cout << "File could not be opened" << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions:

//---------------------------------------------------------------------------------------------------------------------------

void updatePrices(float p[])
{
     float percent = 0.0;
     int num = 0;
     cout << "Which item (1 - 10, 99 to stop)? ";
     cin >> num;
     while(num != 99)
     {
           if(num >= 1 && num <= 10)
           {
               cout << "Enter increase percentage as a whole number: ";
               cin >> percent;
               p[num - 1] = p[num - 1] * (1.0 + percent / 100.0);
	   } 
	   else
		cout << "Item number is invalid" << endl;
     cout << "Which item (1 - 10, 99 to stop)? ";
     cin >> num;
     } 
} //End function

//---------------------------------------------------------------------------------------------------------------------------

void writeToFile(float p[])
{
     ofstream outFile;
     outFile.open("NewPrices.txt", ios::out);
     if(outFile.is_open())
     {
          int x = 0; //keeps track of subscripts
          outFile << fixed;
          outFile.precision(2);
          while(x < 10)
          {
                 outFile << p[x] << endl;
               x = x + 1;
	  }
     } //close if
     else
          cout << "Error opening file" << endl;
} //end function

//---------------------------------------------------------------------------------------------------------------------------











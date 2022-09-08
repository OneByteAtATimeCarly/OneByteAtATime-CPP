//File Access 6 - Reading Using getline() - 2004 C. S. Germany

//Reading Using getline()

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     ifstream InputFile;
     InputFile.open("SalesData.txt",ios::in);

     if(InputFile.is_open())
     {
        string SalesPerson = "";
        int sales = 0;
       
        getline(InputFile, SalesPerson, '#');

        while(!InputFile.eof())
        {
            InputFile >> sales;
            InputFile.ignore(1);
      
            cout << SalesPerson << ": " << sales << endl;
            getline(InputFile, SalesPerson, '#');
        } //close while true
       
        InputFile.close();

     } //close if
     
     else {
            cout << "Sorry, could not open file." << endl;
          }

     return 0;

} //close main()  

//---------------------------------------------------------------------------------------------------------------------------









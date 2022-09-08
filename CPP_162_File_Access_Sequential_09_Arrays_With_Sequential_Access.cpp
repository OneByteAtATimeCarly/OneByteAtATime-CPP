//Sequential File Access 9 - Uses arrays to calculate averages via a sequential access file - 2004 C. S. Germany

//Uses arrays to calculate averages via a sequential access file

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
float calcTotal(float []);
float calcAvg(float []);
float calcHigh(float []);
float calcLow(float []);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 0;
    float rainFall[12] = {0.0};

    ifstream inFile;
    inFile.open("RainFall.dat", ios::in);

    if(inFile.is_open())
    {
        while(x < 12 && !inFile.eof())
        {
            inFile >> rainFall[x];
            x = x + 1;
        }
    inFile.close(); //close file

    cout << "Total rainfall: " << calcTotal(rainFall) << endl;
    cout << "Average rainfall: " << calcAvg(rainFall) << endl;
    cout << "Highest rainfall: " << calcHigh(rainFall) << endl;
    cout << "Lowest rainfall: " << calcLow(rainFall) << endl;

    }

    else
         cout << "File could not be opened" << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions:

//---------------------------------------------------------------------------------------------------------------------------

float calcTotal(float r[])
{
    int x = 0; //keeps track of subscripts
    float total = 0.0; //accumulator

    while(x < 12)
    {
        total = total + r[x];
        x = x + 1;
    }

    return total;
}//end function

//---------------------------------------------------------------------------------------------------------------------------

float calcAvg(float r[])
{
    int x = 0;
    float total = 0.0;

    while(x < 12)
    {
        total = total + r[x];
        x = x + 1;
    }

    return total / 12.0;
} //end function

//---------------------------------------------------------------------------------------------------------------------------

float calcHigh(float r[])
{
     int x = 1; //keeps track of subscripts
     float high = r[0]; //keeps track of highest amount

     while (x < 12)
     {
        if(r[x] > high)
           high = r[x];
       
        x = x + 1;
     }

     return high;
} //end function

//---------------------------------------------------------------------------------------------------------------------------

float calcLow(float r[])
{
     int x = 1;
     float low = r[0];
     while(x < 12)
     {
        if(r[x] < low)
           low = r[x];

        x = x + 1;
     }

     return low;
} //end function

//---------------------------------------------------------------------------------------------------------------------------









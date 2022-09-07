//Arrays - 14 - MultiDimensional Arrays 2 - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int scores[10][2] = {  {98, 99}, {67, 54}, {78, 43},
                           {90, 86}, {88, 56}, {78, 56},
                           {87, 88}, {72, 96}, {44, 67},
                           {66, 34}  };

    int row = 0;
    int col = 0;
    int midHigh = 0;
    int finalHigh = 0;

    midHigh = scores[0][0];
    finalHigh = scores[0][1];

    while(row < 10)
    {
         col = 0; //reset column subscript

         while(col < 2)
         {
             if(scores[row][0] > midHigh)
                midHigh = scores[row][col];


             if(scores[row][1] > finalHigh)
                finalHigh = scores[row][col];

             col = col + 1;    //update column subscript
         } //end 2nd while

         row = row + 1;          //update row subscript

    } //end 1st while

    cout << "Highest score earned on midterm: " << midHigh << endl;
    cout << "Highest score earned on final: " << finalHigh << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------





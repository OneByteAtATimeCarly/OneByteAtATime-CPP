//Arrays - 13 - MultiDimensional Arrays 1 - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int sales[6][2] = {{12000, 10000},
                       {45000, 56000},
                       {32000, 42000},
                       {67000, 23000},
                       {24000, 12000},
                       {55000, 34000}};

    int row = 0;
    int DomesticSales = 0;
    int InternationalSales = 0;

    while(row < 6)
    {
        DomesticSales = DomesticSales + sales[row][0];
        InternationalSales = InternationalSales + sales[row][1];
        row = row + 1;
    }

    cout << "Total domestic sales: $" << DomesticSales << endl;
    cout << "Total international sales: $" << InternationalSales << endl;
    cout << "Total sales: $" << DomesticSales + InternationalSales << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------





//Arrays - 11 - Linear Searches Using Arrays - 2004 C. S. Germany

//Linear Search - cycle through all the elements in an array, looking for a particular item until we find it.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int LinearSearch(int *ArrayPointer, int key, int NItems) 
{   
    int n;
    for(n=0; n<NItems; ++n) 
        if (ArrayPointer[n] == key)
            return n;

    return -1;
}
//---------------------------------------------------------------------------------------------------------------------------

void SearchInputAndValidate(int *ArrayPointer, int NumItems) {
     int ValueToSearchFor;
     int ArrayElement;
     cout << "Enter a number between 1 and " << NumItems << ":  ";
     cin >> ValueToSearchFor;
     ArrayElement = LinearSearch(ArrayPointer, ValueToSearchFor, NumItems);
    
     if(ArrayElement != -1)
          cout << "Found value in element " << ArrayElement << ".\n\n";
     else
          cout << "Sorry, value not found.\n\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{
     int x;
     int NumberOfItems;
     NumberOfItems = 100;
     int *ArrayOfIntegers = new int[NumberOfItems];
     
     //Populate Array with even integer values from 0 to 198
     for(x=0; x<NumberOfItems; ++x) {
            ArrayOfIntegers[x] = 2 * x; }
     SearchInputAndValidate(ArrayOfIntegers, NumberOfItems);
     
}  // close main()

//---------------------------------------------------------------------------------------------------------------------------



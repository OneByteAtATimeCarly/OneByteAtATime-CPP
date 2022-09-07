//Arrays - 12 - Binary Searches Using Arrays - 2004 C. S. Germany

//Binary Search - unlike a linear search, we continuously halve the range where we look for our value. Reduces amount of time
//to find an object, faster than a linear search.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int BinarySearch(int *ArrayPointer, int key, int NItems) 
{ 
    int n;
    int High = NItems;
    int Low = -1;
    int Range;

    while(High-Low > 1) 
    {
          Range = (High + Low) / 2;
          if(ArrayPointer[Range] > key)
             High = Range;
    else 
         Low = Range; 
    } //end while loop

    if(Low == -1 || ArrayPointer[Low] != key)
       return -1;
    else
        return Low;
} //close function

//---------------------------------------------------------------------------------------------------------------------------

void SearchInputAndValidate(int *ArrayPointer, int NumItems) {
     int ValueToSearchFor;
     int ArrayElement;
     cout << "Enter a number between 1 and " << NumItems << ":  ";
     cin >> ValueToSearchFor;
     ArrayElement = BinarySearch(ArrayPointer, ValueToSearchFor, NumItems);
    
     if(ArrayElement != -1)
          cout << "Found value in element " << ArrayElement << ".\n\n";
     else
          cout << "Sorry, value not found.\n\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void main() {
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




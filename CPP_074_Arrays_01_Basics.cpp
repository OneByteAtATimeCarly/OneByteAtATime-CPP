//Arrays 1 - The Basics - 2004 C. S. Germany

//An array is a collection of data storage locations, each of which hold the same type of data. Arrays contain a series of objects that are indexed by a subscript.
//The index-referenced storage location of each item is known as an "element" of the array.  Arrays can be composed of pre-defined data types such as integers, floats,
//and doubles. Or they can be composed of user-defined objects such as Monsters, Mammals, Employees, etc.
//The important thing to remember is that arrays MUST contain objects of the SAME TYPE, not different types.

//We declare an array by writing the type followed by the array name and then subscript.
//The subscript is the number of elements in the array surrounded by square brackets.
//This subscript becomes a reference and a handle for manipulating the object stored at its location.
//Example: long AReallyBigArray[25]; declares an array of 25 long integers. The compiler sets aside enough memory to hold all 25 elements.
//Since each long int requires 4 bytes, this sets aside 100 bytes of memory.

//Array elements are counted from 0, therefore, the first array element is arrayName[0].  AReallyBigArray[25] would be numbered from 0-24, not 1-25.
//This creates a situation where a common mistake is often made by programmers.  Many times our code syntax may be fine, and our projects will compile.
//But they will not perform as expected.  We encounter logic errors, rather than syntax errors, and our programs do not behave as expected.
//This results many times from an array out of bounds error, often referred to as an "off by one" or "fencepost" error.  This is somthing to watch for.

//Strings - A string object is actually an array of ASCII char variables, so using a char array is synonymous with using string objects.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int myArray[5];

    for(int i=0; i<5; i++) // 0-4
    {
         cout << "Value for myArray[" << i << "]: ";
         cin >> myArray[i];
    }

    for(i = 0; i<5; i++)
        cout << i << ": " << myArray[i] << "\n";

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
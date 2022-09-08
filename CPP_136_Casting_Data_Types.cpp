//Casting - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

//Type casting in C++ involves converting data and object of on type into another type.  It is used in all sorts of ways.  There are three categories:

//---------------------------------------------------------------------------------------------------------------------------
 
//Implicit cast - In implicit type casting, a variable data type will always be converted to the largest data type necessary.
//You can go from a smaller type to a larger, but not from a larger to a smaller - without loosing some of the data held by the data type.
//In other words, if you assign a float or a double to an int, you will loose the fractional part of the data.   Implicit casts occur
//naturally by using the assignment operator with different data types.  In the example below, the "f" indicates that it is single
//precision floating point.  Example:

//     int number = 0;
//     float decimal = 2.5f;
//     number = decimal;

//---------------------------------------------------------------------------------------------------------------------------

//Explicit cast - In explicit type casting, you force a data type to take on the size of another data type.
//There are several methods, utilizing 4 keywords:

//1. static_cast - To do this we use the static_cast keyword and <>. This type of casting is only checked at compile time.
//After the program is compiled, there are no further checks. Therefore, this is not as safe as dynamic casting.
//The syntax is as:   static_cast<TypeToConvertTo>(TypeBeingconverted).  Example:

//     double val1 = 2.36;
//     int val2 = 5;
//     val2 = static_cast<int>(val1);

//2. dynamic_cast - Using this keyword causes a cast to be checked not only at compile time, but also at run time. 

//3. const_cast - Removes the "constantness" of an expression.

//4. reinterpret_cast - An unconditional cast, regardless of data type or amount of data shaved off during the conversion.

//---------------------------------------------------------------------------------------------------------------------------

//Old Style Casts - Old style casts are made using parentheses, and may be used to achieve any of the types of casting mentioned previously.
//Because of this, they are very powerful and therefore, subsequently, very error-prone.  Since they are a "one size fits all" type of casting,
//they can be employed many times with unexpected results.  However, they are used frequently in C++ expressions. Example:

//     double val1 = 2.36;
//     int val2 = 5;
//     val2 = (int)(val1);

//---------------------------------------------------------------------------------------------------------------------------

//This is particularly true in the fstream binary write and read process.  This is because the read() and write() methods don't support
//the sizes of programmer-defined data types such as class objects. They must reinterpret that data members of a class object through a
//pointer to a character since they were designed that way.  They have no implicit way of understanding the data members of a Monster or
//an Employee.  Example:

//     ofstream WriteObject;
//     WriteObject.open("TheFile.dat", ios::binary);
//     WriteObject.write((char*) &*TheToy, sizeof *TheToy);
//     WriteObject.close();







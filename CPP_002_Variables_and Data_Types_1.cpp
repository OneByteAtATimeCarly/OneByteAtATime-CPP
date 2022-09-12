//Variables and Data Types 1 - 2004 C. S. Germany

/*

Variables are containers for storing different types of data.  One might think of them as little Tupperware™ containers.
:).  For a more detailed exposition on the glories of Tupperware™, see the tutorial on Arrays.  But for our intents and
purposes, variables, like Tupperware™, come in all different sizes and can hold objects of different size based on the
variable container's size.  Variables have different types, and the data type of a variable tells the compiler how much
room to set aside in the computer's memory to hold the variable object's value. 

On any computer, each variable type takes up a single, unchanging amount of room.  Different containers are used for different
sized objects.  Remember that C++ is a strongly typed language, and thus it becomes very important to store the right kind of
data in the right kind of container.  The positive effect is that this gives the developer tight and precise control over memory
management.  Programs can be very efficient.  The negative effect of this is that C++ can be unforgiving when compared to other,
more loosely-typed languages such as Visual Basic.  Data types are, ultimately, different types of data.  Types of variables:

Type	Size	Values
unsigned short int	2 bytes	0 to 65,535
short int	2 bytes	-32,768 to 32,767
unsigned long int	4 bytes	0 to 4,294,967,295
long int	4 bytes	-2,147,483,648 to 2,147,483,647
char	1 byte	256 character values (ASCII)
float	4 bytes	1.2e-38 to 3.4e38
double	8 bytes	2.2e-308 to 1.8e308

Ultimately, all data is stored and processed in binary.  Computers store memory through manipulating millions of molecular-sized
"switches", sandwiched between neutral, negative, and positively charged layers of silicon.  These switches can be turned on and off,
giving us a very limited number of values - O represents off, and 1 represents on.  That's it, there's only two possiblities.  No
matter how complex the object, to be stored in memory at present it must be reduced into sets of "on's" and "off's".  The solution
lies in manipulating the "switches", like rows on an abacas, to hold larger values by their place value rather than their intrinsic
value.  Our modern society operates efficiently on a base 10 number system (i.e. powers of 10), while our computers operate on a base
2 number system.  Every type of data in memory is stored through conversion in binary. A base 2 number system represents everything
in powers of 2.   Let's look at some examples:

BASE 10

104      	103	102 	101  	100
10,000	1,000	100	10	1
 	
 
 	110 = 	1	1	0
5 = 	0	5
10 = 	1	0
11 = 	1	1

So in Base 10,  a 10 is a "1" in the tens place and a "0" in the ones place.  An 11 would be a "1" in the tens place and a "1" in
the ones place.  110 would be a "1" in the 100's place, a "1" in the 10's place, and a "0" in the 1's place.  Base 2 represents
everything in powers of 2. Bits are switched on and off in ascending place value to give us a range of possible values.  Example:

BASE 2 (Binary)

 	27	26	25	24	23	22	21	20
128	64	32	16	8	4	2	1
 
255 = 	1	1	1	1	1	1	1	1
69 = 	0	1	0	0	0	1	0	1
42 = 	0	0	1	0	1	0	1	0

These 8 positions of the powers of 2, or bits, combine to form a single byte, which can represent numbers from 0 to 255 as switches
are turned on and off in their corresponding place values.  ASCII characters are represented by these Base 2 values - each character
is given a value between 1 and 255.  Strings are arrays of ASCII characters.  In this way, large and complex data structures can
ultimately be reduced to "on" and "off".  This is the power of binary.  Data types are important in C++ because different types of
data - integer, single, or string - require different amounts of memory, and thus different amounts of on/off switches. 
Remember, 8 bits = 1 byte.

Signed Integers = can be either negative or positive from -32,768 to 32,767.. (can hold numbers half as large as unsigned short ints).
Unsigned integers = only positive. (can hold numbers twice as large as signed integers).  For a short int, numbers from 0 to 65,535.

The signed and unsigned integers wrap around from their highest positive value to their lowest negative value, like an odometer.
Type the following and compile:

#include <iostream.h>
int main()
{
    unsigned short int smallNumber;
    smallNumber = 65535;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;

    return 0;
}

Output:

small number: 32767
small number: -32768
small number: -32767

Integers without the word "unsigned" are assumed to be signed.  Let's use the sizeof() method in the C++ standard library to illustrate this -
it renders the size of the object passed in as an argument.  Type and compile the following:  

#include <iostream.h>

int main()
{
    cout << "The size of an int is:\t\t" << sizeof(int) << " bytes.\n";
    cout << "The size of a short int is:\t" << sizeof(short) << " bytes.\n";
    cout << "The size of a long int is:\t" << sizeof(long) << " bytes.\n";
    cout << "The size of a char is:\t\t" << sizeof(char) << " bytes.\n";
    cout << "The size of a float is:\t\t" << sizeof(float) << " bytes.\n";
    cout << "The size of a double is:\t" << sizeof(double) << " bytes.\n";

return 0;

}

Output:

The size of an int is:      2 bytes.
The size of a short int is: 2 bytes.
The size of a long int is:  4 bytes.
The size of a char is:      1 bytes.
The size of a float is:     4 bytes.
The size of a double is:    8 bytes.

Fundamental Variable Types:
Integer Variables - Whole numbers, signed or unsigned.
Floating Point Unit Variables - Have values that can be expressed as fractions. They are REAL numbers.
Character Variables - Hold a single byte and are used to hold the 256 characters of the ASCII character set.
ASCII = American Standard Code for Information Interchange.
                         
Defining a Variable
You create (define) a variable by stating its type, followed by 1 or more spaces, followed by the variable name and a semicolon.
The variable name can be any combination of letters but CAN NOT contain spaces.  Example: int myAge;  Though its instance name is
unimportant, the variable name should tell what it is used for and not be ambiguous.  Example:

Ambiguous	More Concise
 void main()
 {
      unsigned short x;
      unsigned short y;
      unsigned short z;
      z = x * y;
 }	 void main()
 {
      unsigned short Width;
      unsigned short Length;
      unsigned short Area;
      Area = Width * Length;
 }
 
C++ variables are case sensitive.  Be careful not to use C++ keywords as variable names (i.e. if, then, else, while, etc.).
You can create more than on variable of the same type in one statement by writing the type and then the variable names separated by commas.
Example:

unsigned int myAge, myWeight; //two unsigned int variables
long area, width, length; //three longs

You assign a value to a variable using the assignment operator (=).  You would assign 5 to the variable "Width" by writing:

unsigned short Width;
Width = 5;

First we defined/created Width, then we assigned a value to it.  We can combine these steps and initialize Width by writing:

unsigned short Width = 5;

Initialization looks like assignment, with integer variables the difference is minor. For constants, however, some values must be initialized
before they can be assigned to:

#include <iostream.h>

int main()
{
    int Width = 5, Length;
    Length = 10;

    int Area = Width * Length;

    cout << "Width:" << Width << "\n";
    cout << "Length: " << Length << endl;
    cout << "Area: " << Area << endl;

    return 0;
}

Output:
Width: 5
Length: 10
Area: 50

typedef = type definition, a keyword in C++ that allows you to create an alias for a phrase.  It is a synonym, not a new type.
To use it, write the keyword "typedef" followed by the existing type, followed by the new name:

typedef unsigned short int USHORT;

Creates a new name USHORT that you can use anywhere you would write an unsigned short int.  Example:

#include <iostream.h>
typedef unsigned short int USHORT; //typedef defined
typedef unsigned long ULONG;

int main()
{
    USHORT Width = 5;
    USHORT Length;
    Length = 10;

    ULONG Area = Width * Length;

    cout << "Width:" << Width << "\n";
    cout << "Length: " << Length << endl;
    cout << "Area: " << Area <<endl;

    return 0;
}

Output:

Width: 5
Length: 10
Area: 50

Constants - Constants are data storage locations like variables, but they are constant and do not vary.  YOU MUST INITIALIZE a constant
when you create it. You can not assign a new value later.  There are 2 kinds of constants: literal and symbolic.

literal constant - Literal constants are typed into your program wherever it is needed, they are "hard-coded". Example:  

int myAge = 39;  myAge is a variable of type int, but 39 is a literal constant, we can't assign a value to 39 and its value can't be changed - it's intrinsic.

symbolic constants - A symbolic constant is a constant that is represented by a name like a variable, but unlike a variable, once a constant is
                     initialized its value can't be changed.  The symbolic constant holds the value of a literal constant that it is initialized 
                     with at the beginning of the program.  This constant value never changes.  This is because constants are used to hold the
                     value for a fundamental ratio, rule or paradigm in your application.  They are preferred to hard coded values, since they
                     make the program easier to modify, but they still resist change once they are defined and so can be used as literal constants would. 

As an analogy, this can be compared to gravity, electromagnetism, and the strong and weak nuclear force in our known universe.
Without these four basic forces and the "constants" they supply, all existence as we know it would not be possible.  However,
sometimes the four forces are "bent" when trying to reconcile quantum mechanics and relativistic theory.  Quantum mechanics
defines gravity as an exchange of quantum media, or particles sometimes referred to as gravitons.  Relativity defines gravity
as a function of spatial geometry whereby, the more massive the object, the larger its gravity well - that is to say, the more
the object contorts and twists a sheet of space-time. There is a definite need for definite constants in both these theories,
and they appear irreconcilable at first glance.  But as we pursue a grand unified theory (GUT), quantum mechanics bends under
Heisenberg's uncertainty principle, then relativity cuts us some slack per frame of reference on the "constant" velocity of c (light). 

In the same way, in programming, symbolic constants, unlike literal constants, can be changed if the need arises.  This change will become
instant throughout the program and enforced globally or by the scope under which it was introduced.  It is a way of safely, rapidly and
efficiently "bending" the rules to suit our purpose or achieve a different outcome in our program.  Examples:  If you knew there would always
be 32 students in a class, the total number of students would be:  students = classes * 32;

15 is a literal constant, it can't be changed, it is not too flexible. A more flexible method would be using a symbolic constant like:

students = classes * studentsPerClass;

Then by changing the definition of studentsPerClass, you could change the value throughout the program without having to rewrite each instance.
The C++ advantage is that this has a type, therefore the compiler can enforce that it is used according to its type throughout the program. 
The old, evil, structural C way, way to define constants was typeless:

#define studentsPerClass 32;

The flashy, new and improved C++ way is:

const unsigned short int studentsPerClass = 32;

enumerated constants - create a set of constants with a range of values. The syntax for enumerated constants is to write the keyword enum
                       followed by the type name, an open brace, each of the legal values separated by commas, a closing brace and a semicolon. 
                       Example:

enum color {red, blue, green, white, black};

This statement makes "color" the name of an enumeration and "red" a symbolic constant with the value 0, "blue" 1, "green" 2, "white" 3, "black" 4
and so on.  Every enumerated constant has an integer value.  If unspecified, the first will have the value 0, and the rest will count up from there.
Any one of the constants can be initialized with a particular value and the ones that follow it will count up from there sequentially.  Example:

enum color {red=100, blue, green=500, white, black=700};

Red will have the value of 100, blue=101, green=500, white=501, black=700.

*/

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    unsigned short int smallNumber;
    smallNumber = 65535;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;
    smallNumber++;
    cout << "small number:" << smallNumber << endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------


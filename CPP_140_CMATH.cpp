//CMATH - 2004 C. S. Germany

//Using Cmath functions with arrays can accomplish many tasks in C++.
//Some of the available functions from Cmath are:

//     abs	Return absolute value of integer parameter
//     acos	Calculate arccosine
//     asin	Calculate arcsine
//     atan	Calculate arctangent
//     atan2	Calculate arctangent, 2 parameters
//     atof	Convert string to double
//     ceil	Return the smallest integer that is greater or equal to x
//     cos	Calculate cosine
//     cosh	Calculate hyperbolic cosine
//     exp	Calculate exponential
//     fabs	Return absolute value of floating-point
//     floor	Round down value
//     fmod	Return remainder of floating point division
//     frexp	Get mantissa and exponent of floating-point value
//     labs	Return absolute value of long integer parameter
//     ldexp	Get floating-point value from mantissa and exponent
//     log	Calculate natural logarithm
//     log10	Calculate logarithm base 10
//     modf	Spli floating-point value into fractional and integer parts
//     pow	Calculate numeric power
//     sin	Calculate sine
//     sinh	Calculate hyperbolic sine
//     sqrt	Calculate square root
//     tan	Calculate tangent
//     tanh	Calculate hyperbolic tangent

//Examples:

//     int m=abs(-11);
//     float result = acos(0.5) * 180 / PI;
//     printf("4.73 ^ 12 = %lf\n", pow(4.73,12));
//     float result = exp(5);
//     double result = sqrt(29);
//     double result = sin(45*PI/180);
//     double result = cos(45*PI/180);
//     double result = tan(45*PI/180);
//     printf("floor of 3.8 is %.1lf\n", floor(3.8) );
//     printf("Absoulte value of 3.1416 is %lf\n", fabs(3.1416) );
//     printf ("ceil of 2.3 is %.1lf\n", ceil(2.3) );

//Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Number
{
    public:
      //Overloaded constructor prototypes
      Number();
      Number(int, int, float);

      ~Number() { }

      //Accessor prototypes
      int getNum();
      int getSquare();
      float getSqRoot();

    private:
      int num;
      int sqNum;
      float sqRtNum;
};

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded constructor definitions
Number::Number()
{
     num = 0;
     sqNum = 0;
     sqRtNum = 0.0;
}

//---------------------------------------------------------------------------------------------------------------------------

Number::Number(int n1, int n2, float n3)
{
     num = n1;
     sqNum = n2;
     sqRtNum = n3;
}

//---------------------------------------------------------------------------------------------------------------------------

//Accessor method definitions
int Number::getNum()
{ return num; }

//---------------------------------------------------------------------------------------------------------------------------

int Number::getSquare()
{ return sqNum; }

//---------------------------------------------------------------------------------------------------------------------------

float Number::getSqRoot()
{ return sqRtNum; }

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int x = 0;
    int num = 0;

    //Create an array of 5 Number objects on the stack
    Number numArray[5] = {  Number(2, pow(2,2), sqrt(2)),
                            Number(4, pow(4,2), sqrt(4)),
                            Number(6, pow(6,2), sqrt(6)),
                            Number(8, pow(8,2), sqrt(8)),
                            Number(10, pow(10,2), sqrt(10))  };

    cout << "Enter an even number 2-10 (negative number to stop program): ";
    cin >> num;

    //while loop with -1 as sentinel value
    while(num >= 0)
    {
        x = 0;
        //Search through all 5 array elements looking for the number
        while(x < 5 && numArray[x].getNum() != num)
        x = x + 1;

        if(x < 5)
        {
           cout << "Square: " << numArray[x].getSquare() << endl;
           cout << "Square root: " << numArray[x].getSqRoot() << endl;
        }
        else
             cout << "Number is not in the array" << endl;

    cout << "Enter an even number 2-10 (negative number to stop program): ";
    cin >> num;
    } //end while

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------










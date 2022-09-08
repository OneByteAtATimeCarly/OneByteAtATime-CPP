//Project - Multiple Expression Parsing Calculator - 2004 C. S. Germany

//Implements a calculator by parsing string expressions

//---------------------------------------------------------------------------------------------------------------------------

//DESIGN: In the design process for the calculator above, we decide to divide the task of parsing the expression contained in the string among distinct
//functions, each suited to dealing with its part.

//---------------------------------------------------------------------------------------------------------------------------

//1. First, we need a way of getting ris of superfluous whitespace, since it is not a factor in dealing with our expression. 
//We decide to accomplish this by passing the string to a function called "eatspaces()".  This function will simply cycle through
//each character in the string by its array element and copy it to itself.  If it finds a white space in one of the elements, then
//it does not copy it, and copies the other elements over it.  It accomplishes this by incrementing "i" only if it is not a
//whitespace, whereas "j" will be incremented no matter what the element is. 

//---------------------------------------------------------------------------------------------------------------------------

//2. After we remove the whitespace, we need to evaluate the expression.  We decide to do this by passing the string, now free of whitespace, to another
//function that we will call "expr()".  In this function, we must deal with mathematical precedence.  As such, addition and subtraction must occur after
//multiplication and division.  This requires us to clearly break down the string and parse its expression.   The subcomponents of the string to be acted
//upon by our mathematical operators are terms, and these we will pass as distinct units to the function "term()".  Therefore, since multiplication and
//division take higher precedence over addition and subtraction, we will place multiplication and division operations inside the "term()" function to be
//called form within the "expr()" function.  In this way, multiplication/division will be carried out in the function first and only then will the value
//be returned from the function and addition/subtraction carried out.  The term() function is called once, regardless, even if no "+" or "-" is encountered. 
//In the case of multiplication or //division, term will have to take care of recursively calling itself or another function to deal with the terms in the
//string.  In this way, we can say that multiplication/division "bind tighter".  If addition/subtraction are present in the expression, since we are
//"passing the buck" to the "term()" function, there are only three possibilities for the expr() function: "+", "-", and "\0".
//If "\0" is detected, it signifies the end of the expression. 
 
//       Example: 7 +   8 * 6   -   25 / 5

//Note: In the expression above, the multiply/divide operation will be carried out when the term() function is called, and so those operations will occur
//FIRST.  Only after the function has returned will the add/subtract operations be performed and their results added to the accumulator.

//---------------------------------------------------------------------------------------------------------------------------

//3. The function "term()" is what the buck passes to from the function expr().  When the function "term()" is called, it immediately passes the buck to
//the function "number()".  That is, the string is passed, with the value of its current index, to number().   Number will take care of several things -
//determining what the numerical parts of the expression are on both sides of the "*" and "/" operators and evaluating "( parentheses )" expressions first.
//All term() has to do is loop through the string and either multiply or divide by the accumulator, "value".  Depending on which operator is encountered,
//the "number()" function will again be called to determine the numerical part of the expression.  Finally, the value of these operations will be returned
//for addition/subtraction operations.

//---------------------------------------------------------------------------------------------------------------------------

//4. The function "number()" receives the buck from the function "term()", and parses the string for numerical content.  The header file we included,
//"cctype.h", contains several functions useful in number detection.  They each return boolean:

//       isalpha(int arg) - returns true if argument is aplhabetic.
//       isupper(int arg) - returns true if argument is upper case.
//       islower(int arg) - returns true if argument is lower case. 
//       isdigit(int arg) - returns true if argument is a number. 

//The integer argument is the ASCII value of the char being evaluated in the array element.

//Let's clarify the expression (10 * value + (*(str+index++) - 48)).  We subtract 48 to get the integer equivalent of the ASCII value of the character
//in the string.  The (-48) reflects the relationship that the ASCII value of the char has with the integer it represents.  Example:
 
//       Decimal Value:	5	1	3
//       ASCII Code:	53	49	51
//       Subtract 48 = :	5	1	3

//This will give us the single digits 5, 1, and 3, but how will we determine their place values?  We must now loop through and multiply each converted
//"value" by 10 for each decimal place to the left.  If we find a decimal value to the right, we will deal with that later as well. In order to shift
//the decimal to the left one place, we multiply by 10.  As we loop through, we can therefore specify millions, thousands, hundreds, tens, and ones
//places.  Example:
 
//The variable "value" starts with a value of 0.0.   In the expression  value = (10 * value + (*(str+index++) - 48)), we loop and use the variable
//"value" as an accumulator:

//1st loop - The first digit, "5", is in the hundreds place.  It will therefore need to be in the first iteration of the loop so that it can be
//multiplied by 10.  The current value of "value" is 0.0, so 0.0 is multiplied by 10 for a value of 0.0, and that is added to 5, giving the result
//of 5.0 on the first loop.  The variable "value" is now 5.0.  The string is then incremented to advance to the next element, or "1". 

//2nd loop - The second digit, "1", is in the tens place.  In the second iteration of the loop, 5.0 is multiplied by 10 for a value of 50.0, and
//that is added to 1, giving the variable "value" a final value of 51.0.

//3rd loop - The third digit, "3", is in the ones place.  In the third iteration of the loop, 51.0 is multiplied by 10 for a value of 510.0, and
//that is added to 3, rendering the final value of "value" to be 513.0.

//This deals with the place values to the left of the decimal, but what of the fractional values of numbers to the right of the decimal?  First,
//we must detect a decimal point in the string, looking for  ".".  If we detect it, we must repeat the above process.  However, for digits to the
//left of the decimal, the factor multiplied by was 1.0, and looping this value and multiplying by 10 caused that 1.0 to jump to the next 10's place
//with each iteration.  Therefore, to compute the place values of the digits to the right, we must multiply by a factor of 0.1.  This will effectively
//divide by 10 for each iteration of the loop, advancing to the next 10th's place to the right of the decimal.  Example:

//       Decimal Value:	5	1	3	.	6	0	8
//       ASCII Code:	53	49	51	 	54	48	56
//       Subtract 48 = :	5	1	3	 	6	0	8
 
//The variable "factor" starts with a value of 1.0.  In each iteration of the loop, it is multiplied 0.1 and itself, and then that becomes the new value
//of "factor".  Therefore, it accumulates in reverse.  In the expression  value = (10 * value + (*(str+index++) - 48)),  we loop and use the variable
//"value" as an accumulator:

//1st loop - The first digit, "6", is in the 10th's place.  It will therefore need to be in the first iteration of the loop so that it can be multiplied by 0.1. 
//The current value of "value" is 513, and the current value of "factor" is 0.1, so 6 is multiplied by 0.1 for a value of 0.6, and that is added to 513, giving
//the result of 513.6 on the first loop.  The variable "value" is now 513.6. The string is then incremented to advance to the next element, or "0", and factor
// (0.1) is again multiplied by 0.1. 

//2nd loop - The second digit, "0", is in the hundredth's place.  In the second iteration of the loop, the value of factor (0.1) is multiplied again by 0.1,
//assigning the value of .01 to factor.   The value of "0" is then multiplied by .01, rendering .00, and that is added to 513.6, giving the variable "value"
//a final value of 513.60.  The string is then incremented to advance to the next element, or "8", and factor (.01) is again multiplied by 0.1.

//3rd loop - The third digit, "8", is in the thousandth's place.  In the third iteration of the loop, the value of factor (.01) is multiplied again by 0.1,
//assigning the value of .001 to factor.  the value of "8" is then multiplied by .001, rendering .008, and that is added to 513.60, rendering the final value
//of "value" to be 513.608.

//In this fashion, the number() function turns the string data into actual values that we can use in calculations. It passes these back to the term() function,
//which takes care of multiplying or dividing the values that the number() function returns.

//If the number() function finds parentheses, it calls the "extract()" function, which takes on the responsibility of figuring out what the sub-expression is.
//The number() function then calls expr(), which calls term(), which calls number().  This is a form of recursion, with one function calling another and
//another that eventually calls the original function and the process starts over. 

//---------------------------------------------------------------------------------------------------------------------------

//5. Finally, we will look at the "extract()" function.  It parses the string it is passed for "(" and ")", and returns the value of the substring to the expr()
//function so that it can be parsed and evaluated.  The variable "numL" is incremented each time a parentheses is opened and decremented each time it is closed.
//Its value is then checked to see if it is 0, indicating that all parentheses are properly opened/closed.  This function will create a new string of each
//substring on the heap and return a pointer to it, and this substring will then be processed by the other functions. 



//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>    //For stream input/output
#include <cstdlib>     //For the exit() function
#include <cctype>      //For the isdigit() function
#include <string>      //For the strcpy function
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
void eatspaces(char * str);               //Function to eliminate blanks
double expr(char * str);                  //Function evaluating an expression
double term(char * str, int & index);     //Function analyzing a term
double number(char * str, int & index);   //Function to recognize a number
char* extract(char * str, int & index);   //Function to extract a substring

//---------------------------------------------------------------------------------------------------------------------------

const int MAX = 80;     //Maximum expression string length including '\0'

//---------------------------------------------------------------------------------------------------------------------------

int main(void)
{
    char buffer[MAX] = {0};       //Input area for expression to be evaluated

    cout << endl << "Welcome to your friendly calculator." << endl;
    cout << "Enter an expression, or an empty line to quit." << endl;


    for(;;)
    {
        cin.getline(buffer, sizeof buffer);    //Read an input line
        eatspaces(buffer);                     //Remove blanks from input

        if(!buffer[0])                         //Empty line ends calculator
           return 0;

       cout << "\t= " << expr(buffer) << endl << endl;    //Output value of expression
            
    } //close infinite for loop

} //close main() function

//---------------------------------------------------------------------------------------------------------------------------

/Function to eliminate blanks from a string.  
//It will eat the white space by copying a string to itself element by element when i and j
//are incremented equally.  If a space is encountered, i will not be incremented, yet j will,
//thus the space will be removed as the loop iterates.  

void eatspaces(char * str)
{
     int i=0;             //'Copy to' index to string
     int j=0;             //'Copy from' index to string

     //Loop while character copied is not \0.  Note: Saying "(str+i)" is like saying str[i].  
     while(  (*(str+i) = *(str+j++))  != '\0'  )
     { 

            if(*(str+i) != ' ')       //Increment i as long as character is not a blank
               i++;                   

     } //close while true loop

     return;  //Empty return falls back to main() function
} //close function


//---------------------------------------------------------------------------------------------------------------------------

//Function to evaluate an arithmetic expression

double expr(char * str)
{
       double value = 0;            //Store result here
       int index = 0;               //Keeps track of current character position

       value = term(str, index);    //Get first term

       for(;;)                      //Infinite loop, all exits inside
       {
            switch(*(str+index++))   //Choose action based on current character
            {
                    //------------------------------------------------------------------------------------
                    case '\0':       //We're at the end of the string so return what we have got
                    return value;  
                    //------------------------------------------------------------------------------------
                    case '+':        //+ found so add in the next term
                    value += term(str, index);   
                    break;
                    //------------------------------------------------------------------------------------
                    case '-':        //- found so subtract the next term
                    value -= term(str, index); 
                    break;
                    //------------------------------------------------------------------------------------
                    default:        //If we reach here the string is in error!
                    cout << endl << "There's an error!" << endl;
                    exit(1);
                    //------------------------------------------------------------------------------------

            } //close the switch statement

       } //close for loop

} //close function


//---------------------------------------------------------------------------------------------------------------------------

//Function to get the value of a term

double term(char * str, int & index)
{
       double value = 0;   //Accumulator for the result

       value = number(str, index);     //Get the first number in the term

         //Loop as long as we have a good operator
       while( (*(str+index)=='*') || (*(str+index)=='/') )
       {

             if(*(str+index)=='*')                     //If it's multiply, multiply by next number
                  value *= number(str, ++index);  

             if(*(str+index)=='/')                     //If it's divide, divide by next number
                  value /= number(str, ++index); 
       }

       return value;                                      //Finished, so return what we've got

}

//---------------------------------------------------------------------------------------------------------------------------

//Function to recognize an expression in parentheses or a number in a string

double number(char * str, int & index)
{
       double value = 0.0;            //Store the resulting value


       if(*(str+index) == '(')       //Start of parentheses
       {
            char * psubstr = 0;       //Declare and initialize pointer for substring

            psubstr = extract(str, ++index);     //Extract substring in brackets
            value = expr(psubstr);                  //Get the value of the substring
            delete[] psubstr;                       //Clean up the free store
            return value;                           //Return substring value
       }


       while(isdigit(*(str+index)))        // Loop accumulating leading digits
       {
             value = 10 * value + (*(str+index++) - 48);
       }

       //Not a digit when we get to here
       if(*(str+index)!= '.')      //Check for decimal point, and if not, return value
          return value; 


       double factor = 1.0;      //Factor for decimal places


       while(isdigit(*(str+(++index))))                       //Loop as long as we have digits
       {
             factor *= 0.1;                                    //Decrease factor by factor of 10
             value = value + (*(str+index)-48) * factor;  //Add decimal place
       }

       return value;                                     //On loop exit, we are done
}

//---------------------------------------------------------------------------------------------------------------------------

//Function to extract a substring between parentheses (requires string)

char * extract(char * str, int & index)
{
     char buffer[MAX];            //Temporary space for substring
     char * pstr=0;               //Pointer to new string for return
     int numL = 0;                //Count of left parentheses found
     int bufindex = index;        //Save starting value for index

     do
     {
         buffer[index-bufindex] = *(str+index);


         switch(buffer[index-bufindex])
         {     
                //------------------------------------------------------------------------------------
                case ')':
                if(numL == 0)
                {
                    buffer[index-bufindex] = '\0';      //Replace ')' with '\0' 
                    ++index;
                    pstr = new char[index-bufindex];

                    if(!pstr)
                    {
                       cout << "Memory allocation failed, program terminated.";
                       exit(1);
                    }

                    strcpy(pstr,buffer);             //Copy substring to new memory
                    return pstr;            //Return substring in new memory
                } //close if
                
                else
                {   numL--;   }   //Reduce count of '(' to be matched

                break;

                //------------------------------------------------------------------------------------

                case '(':
                numL++; // Increase count of '(' to be matched
                break;
               //------------------------------------------------------------------------------------

         } //close switch statement

     } //close do

     while(*(str+index++) != '\0');     // Loop - but don't overrun end of string

     cout << "Ran off the end of the expression, must be bad input." << endl;
     exit(1);

     // return pstr;


//---------------------------------------------------------------------------------------------------------------------------




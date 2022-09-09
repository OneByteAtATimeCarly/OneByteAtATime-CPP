//PRJ - Console Calculator App - 2006 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
double CheckErrors(char * amountString);
void Calculate();
void Square(); 
void Cube();
void Convert();
void Kilometers();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
     //If we take input as a char or int the user can crash the program
     //by entering a string or invalid data type. Therefore we will take 
     //data as a string and switch on the 1st element in the char array.
	 char choice[10] = "#";

     cout << "\n\n\tCalculator 2.0 - 2007"
		  << "\n\tFor BulletProofing Calculator 1.0 - C. Germany\n\n";
     
     while(choice[0] != 'q') 
     {
            cout << "\n\t***************************************\n" 
                 << "\t*       MENU - Select an option       *\n"
                 << "\t*-------------------------------------*\n"
	             << "\t*                                     *\n"                 
                 << "\t*  (B)asic Calculations               *\n"
                 << "\t*  (S)quare a Number                  *\n"
                 << "\t*  (C)ube a Number                    *\n"
                 << "\t*  (F)arenheit or Celcius Conversion  *\n"
                 << "\t*  (K)ilometers or Miles Conversion   *\n" 
	             << "\t*  (Q)uit                             *\n"
	             << "\t*                                     *\n"
	             << "\t***************************************\n";

            cout << "\n\tEnter your choice: ";

            cin >> choice;

            switch(tolower(choice[0])) 
            {
                   case 'q' : break;
                   case 'b' : Calculate(); break;
                   case 's' : Square(); break;
                   case 'c' : Cube(); break;
                   case 'f' : Convert(); break;
                   case 'k' : Kilometers(); break;
                   default : cout << "Sorry, invalid choice."; break;
            } //close switch statement
            
	} //close while true loop on choice

    cout << "\n\tYou have choosen to quit.\n\tEnding calculator 2.0 program."
         <<  " Exiting...\n\n\t";
             
    system("PAUSE");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

//Function to correct user error (bulletproofing the calculator)
// This function encapsulates the error checking process.
// If we take input as a float or integer, when the user enters
// a character/string, it will throw the program into an infinite 
// loop and crash it.  If, on the other hand, we take input as 
// a string, we can parse the string for ASCII values that relate
// to numbers and then we can handle both kinds of input.
// The first part parses numbers to the left of the decimal,
// then the second part parses numbers to the right.
// If we get a non-number ASCII value, an error message is displayed
// and the the return value is set to 0.0.

double CheckErrors(char * amountString)
{
        int x = 0;
        double THEamount = 0.0;
        cout << "\tThe string value passed in is " << amountString << ".\n";
        
        //character must be between 10 and 0 to be valid     
        while( (amountString[x] - 48) < 10 && (amountString[x] - 48) >= 0 )       
        {                      
                  //Multiply by 10 to move digits to left of decimal.
                  //As each character is evaluated it will move in place
                  //value to the left.
                  THEamount = 10 * THEamount + (amountString[x] - 48);
                   x++;   //proceed to next character in the array
        } 
 
        //If last character is a decimal point, we need to move numbers to
       //the right instead of the left.
 
       if(amountString[x] == '.') 
       {
                cout << "\tI detect a decimal point!\n"; 
                x++;             //Need to increment x to the next character FIRST
 
               double factor = 1.0;    //factor needs to be reinitialized each time!
 
              while((amountString[x] - 48) < 10 && (amountString[x] - 48) >= 0)
              {
                          factor = factor * 0.1;  //Decrease by factor of 10
                          //Multiply by 0.1 to move digits to right of decimal.
                          //As each character is evaluated it will move in place value to the right.
                          THEamount = THEamount + (amountString[x] - 48) * factor;  
                          x++;
              }
 
              //If they type a non-number ASCII value after the decimal flag
              //it as an error and return 0.0 as the value.
               if(!(amountString[x] - 48) < 10 && (amountString[x] - 48) >= 0)
              {  
                      cout << "\tSorry, but that was not a valid number!\n";
                      cout << "\tTherefore, the number you have entered will be set to 1.\n";
                      THEamount = 1.0;
                      return THEamount;
               }
 
          }  //close block that executes if char was a '.'
 
          else
          {
                   //If they type a non-number ASCII value before the decimal flag
                   //it as an error and return 0.0 as the value.
                   if(!(amountString[x] - 48) < 10 && (amountString[x] - 48) >= 0)
                   {  
                        cout << "\tSorry, but that was not a normal number!\n";
                        cout << "\tTherefore, the strange string you have entered will be set to 1.\n";
                        THEamount = 1.0;
                        return THEamount;
                   }
          }
 
          return THEamount;
      
} //close function

//---------------------------------------------------------------------------------------------------------------------------

//Calculation Function for All Operations

void Calculate()
{
	 char NumberString[10] = "#";
	 char choice[10] = "#";
     char op;     
     double FirstNum;
     double SecondNum;
     double Answer;

     while(choice[0] != 'q')
     {
          cout << "\n\tBasic Calculations:\n\n";
     
          cout << "\n\tWhat would you like to do?\n"
               << "\t(A)dd\n"
               << "\t(S)ubtract\n"
               << "\t(M)ultiply\n"
               << "\t(D)ivide\n"
               << "\t(Q)uit\n\n\t";
          
          cin >> choice; //In case they enter more that 1 char, use a char array
          choice[0] = tolower(choice[0]); //tolower() here saves multiple calls

          if(choice[0] == 'q') { break; } //Don't ask for numbers if user quits

          cout << "\tEnter 1st number: "; 
          cin >> NumberString;
          FirstNum = CheckErrors(NumberString);
          cout << "\tEnter 2nd number: "; 
          cin >> NumberString;
          SecondNum = CheckErrors(NumberString);

          //Bulletproofing - If they enter a whole string, only accept 1st char
     
          switch(choice[0])
          {
              case 'a' : Answer = FirstNum + SecondNum; op = '+'; break;
              case 's' : Answer = FirstNum - SecondNum; op = '-'; break;
              case 'm' : Answer = FirstNum * SecondNum; op = 'x'; break;
              case 'd' : //Need to guard(bulletproof) against a divide by 0 error!
                         if(SecondNum != 0)
                         { Answer = FirstNum / SecondNum; op = '/';}
                         else 
                         { 
                              cout << "\n\tI can't really divide by 0! That will crash me!\n"
				   << "\n\tAnything divided by 0 is 0, so I will set answer to 0.\n";
                              Answer = 0; 
                         } 
                         break;
              default : cout << "\tInvalid response."; Answer = 0; break;    
          }

          cout << "\n\tResult: " << FirstNum << " " << op << " " << SecondNum
               << " = " << Answer << " .\n\n";    
     
     }//close while true loop 
     
}//close Calculate function

//---------------------------------------------------------------------------------------------------------------------------

void Square() 
{

     char NumberString[10];
     double Num;
     double Answer;
     
     cout << "\n\tSquare of Number\n";
     cout << "\tEnter number to be squared: "; 
     cin >> NumberString;
     Num = CheckErrors(NumberString);
     Answer = Num * Num;
     cout << "\n\tResult: " << Num << " to the power of 2 "
          << "(" << Num << " x " << Num << ")" << " is " 
          << Answer << " .\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Cube() 
{
     char NumberString[10];
     double Num;
     double Answer;
     
     cout << "\n\tCube of Number\n";
     cout << "\tEnter number to be cubed: "; 
     cin >> NumberString;
     Num = CheckErrors(NumberString);
     Answer = Num * Num * Num;
     cout << "\n\tResult: " << Num << " to the power of 3 "
          << "(" << Num << " x " << Num << " x " << Num << ")" << " is " 
          << Answer << " .\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Convert() 
{
	 char choice[10] = "#";
	 char NumberString[10];
     double TempFar;
     double TempCel;

     while(choice[0] != 'q')
     {     
         cout << "\tWhat would you like to convert?\n"
              << "\t(F)arenheit to Celcius\n"
              << "\t(C)elcius to Farenheit\n"
              << "\t(Q)uit\n\n\t";
     
         cin >> choice;
         choice[0] = tolower(choice[0]);
         
         if(choice[0] == 'q') { break; }
     
         if(choice[0] == 'f') 
         {
	         cout << "\tPlease enter the temperature in degrees Farenheit: ";
             cin >> NumberString;
             TempFar = CheckErrors(NumberString);
         
             TempCel = ((TempFar - 32) * 5) / 9;
             cout << "\n\t" << TempFar << " degrees Farenheit"
                  << " is equal to " << TempCel << " degrees Celcius.\n\n";
         }

         if(choice[0] == 'c')
         {
            cout << "\tPlease enter the temperature in degrees Celcius: ";
            cin >> NumberString;
            TempCel = CheckErrors(NumberString);
        
	        TempFar = (TempCel * 9 / 5) + 32;
            cout << "\n\t" << TempCel << " degrees Celcius"
                 << " is equal to " << TempFar << " degrees Farenheit.\n\n";
         }
        
         if(choice[0]!='f' && choice[0]!='c' && choice[0]!='q') 
         { cout << "\n\tSorry, that was an invalid choice.\n\n"; }

    }//close while true loop

} //close function

//---------------------------------------------------------------------------------------------------------------------------

void Kilometers()
{
	 char choice[10] = "#";
     char NumberString[10];
     double Kilometers;
     double Miles;

     while(choice[0] != 'q')
     {     
         cout << "\tWhat would you like to convert?\n"
              << "\t(K)Kilometers to Miles\n"
              << "\t(M)iles to Kilometers\n"
              << "\t(Q)uit\n\n\t";
     
         cin >> choice;
         choice[0] = tolower(choice[0]);
         
         if(choice[0] == 'q') { break; }
     
         if(choice[0] == 'k') 
         {
	         cout << "\tPlease enter the number of Kilometers to convert: ";
             cin >> NumberString;
             Kilometers = CheckErrors(NumberString);
         
             Miles = Kilometers / 1.60934;
             
             cout << "\n\t" << Kilometers << " kilometers"
                  << " is equal to " << Miles << " miles.\n\n";
         }

         if(choice[0] == 'm')
         {
            cout << "\tPlease enter the number of Miles to convert: ";
            cin >> NumberString;
            Miles = CheckErrors(NumberString);
        
	        Kilometers = Miles * 1.60934;
	        
            cout << "\n\t" << Miles << " miles"
                 << " is equal to " << Kilometers << " kilometers.\n\n";
         }
        
         if(choice[0]!='k' && choice[0]!='m' && choice[0]!='q') 
         { cout << "\n\tSorry, that was an invalid choice.\n\n"; }

    }//close while true loop     
}

//---------------------------------------------------------------------------------------------------------------------------




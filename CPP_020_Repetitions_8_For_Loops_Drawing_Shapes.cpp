//Repetitions 8 - Drawing Shapes With For Loops - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

//Function prototypes
void DrawRectangle();
void DrawTriangle1();
void DrawTriangle2();

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    cout << endl << endl;
    DrawRectangle();
    DrawTriangle1();
    DrawTriangle2();
    
    cout << endl << endl << "End of the program!";
    cout << endl << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function definitions

//---------------------------------------------------------------------------------------------------------------------------

void DrawRectangle()  {
     for(int row = 1; row <= 5; ++row ) {
         for(int column = 1; column <= 15 ; ++column ) {
             cout << "*";
         } //ends 2nd for loop
         cout << endl;
     } //ends 1st for loop
         cout << endl << endl << endl;
} //end function

//---------------------------------------------------------------------------------------------------------------------------

void DrawSquare() {
     for(int row = 1; row <= 15; ++row ) {
         for(int column = 1; column <= 15 ; ++column ) {
             cout << "*";
         } //ends 2nd for loop
         cout << endl;
     } //ends 1st for loop
            
         cout << endl << endl << endl;

}  //end function

//---------------------------------------------------------------------------------------------------------------------------

void DrawTriangle1() {

     int i, j ;

     for(i = 1 ; i <= 5 ; i++ )
     {
         for(j = 1 ; j <= i ; j++)
         {
             cout << "*";
         } //ends 2nd for loop

         cout << "\n";
     } //ends 1st for loop
} //end function

//---------------------------------------------------------------------------------------------------------------------------

void DrawTriangle2() {
     int i, j;
     cout << endl << endl;

     for(i = 1 ; i <= 5 ; i++ )
     {
         for(j = 1 ; j <= 5 ; j++)
         {
             if(i > 5 - j)
             {
                 cout << "*";
             }   
             else
             {
                 cout << " ";
             }
         } //ends 2nd for loop

         cout << endl;  
     } //ends 1st for loop

} //end function

//---------------------------------------------------------------------------------------------------------------------------

void DrawDiagonalO() {

     int i, j ;

     for(i = 1 ; i <= 5 ; i++ )
     {
         for(j = 1 ; j <= 5 ; j++)
         {
             if(i == j)
             {   
                 cout << "O";
             }
             else
             {
                 cout << "*";
             }
         } //ends 2nd for loop

         cout << endl;
     } //ends 1st for loop
} //end function

//---------------------------------------------------------------------------------------------------------------------------




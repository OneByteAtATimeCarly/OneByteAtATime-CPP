//Building Point and Square Classes - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include "CPP_033_Example_Defining_Point_and_Square_Classes_HPP.h"

//---------------------------------------------------------------------------------------------------------------------------

//Define Square constructor outside class using ::
Square::Square(int top, int left, int bottom, int right)  {

                 itsTop = top;
                 itsLeft = left;
                 itsBottom = bottom;
                 itsRight = right;    

                 itsUpperLeft.SetX(left);
                 itsUpperLeft.SetY(top);
                 itsUpperRight.SetX(right);
                 itsUpperRight.SetY(top);

                 itsLowerLeft.SetX(left);
                 itsLowerLeft.SetY(bottom);
                 itsLowerRight.SetX(right);
                 itsLowerRight.SetY(bottom);
}  

//---------------------------------------------------------------------------------------------------------------------------

//Define(Implement) Accessor methos outside class
int Square::GetArea() {

                     int Width = itsRight - itsLeft;
                     int Height = itsTop - itsBottom;

                     return (Width * Height);
}

//---------------------------------------------------------------------------------------------------------------------------

int main()  {

     Square MySquare(200, 50, 90, 100);

     int Area = MySquare.GetArea();
     cout << "Area: " << Area << "\n";

     cout << "Upper Left X Coordinate: "
          << MySquare.GetUpperLeft().GetX();

     return 0;

} // end main

//---------------------------------------------------------------------------------------------------------------------------


//Example: Defining Point and Square Classes, Header File - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Point  {

        public:
        void SetX(int x) { itsX = x; }
        void SetY(int y) { itsY = y; }
        int GetX()const { return itsX;}
        int GetY()const { return itsY;}

        private:
        int itsX;
        int itsY;

};  // end of Point class declaration

//---------------------------------------------------------------------------------------------------------------------------

class Square {

         public:
         Square (int top, int left, int bottom, int right);
         ~Square () {}

         int GetTop() const { return itsTop; }
         int GetLeft() const { return itsLeft; }
         int GetBottom() const { return itsBottom; }
         int GetRight() const { return itsRight; }
      
         //The accessor methods below return an object of type "Point", declared in the class above
         Point GetUpperLeft() const { return itsUpperLeft; }
         Point GetLowerLeft() const { return itsLowerLeft; }
         Point GetUpperRight() const { return itsUpperRight; }
         Point GetLowerRight() const { return itsLowerRight; }

         //The accessor methods below take an object of type "Point", declared in the class above
         void SetUpperLeft(Point Location) {itsUpperLeft = Location;}
         void SetLowerLeft(Point Location) {itsLowerLeft = Location;}
         void SetUpperRight(Point Location) {itsUpperRight = Location;}
         void SetLowerRight(Point Location) {itsLowerRight = Location;}

         void SetTop(int top) { itsTop = top; }
         void SetLeft (int left) { itsLeft = left; }
         void SetBottom (int bottom) { itsBottom = bottom; }
         void SetRight (int right) { itsRight = right; }

         int GetArea();

         private:
         //Create instances of the Point class as the private member data of this class
         Point itsUpperLeft;
         Point itsUpperRight;
         Point itsLowerLeft;
         Point itsLowerRight; 

         int itsTop;
         int itsLeft;
         int itsBottom;
         int itsRight;

};   //end class

//---------------------------------------------------------------------------------------------------------------------------


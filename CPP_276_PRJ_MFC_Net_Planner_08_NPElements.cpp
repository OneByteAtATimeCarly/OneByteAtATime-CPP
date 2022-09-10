//2006 C. Germany - Network Planner GUI App
//File: 8 of 25

//---------------------------------------------------------------------------------------------------------------------------

// Implementations of the element classes
#include "stdafx.h"
#include <math.h>
#include "NPconstants.h"
#include "NPelements.h"
IMPLEMENT_SERIAL(Element, CObject, VERSION_NUMBER)
IMPLEMENT_SERIAL(CLine, Element, VERSION_NUMBER)
IMPLEMENT_SERIAL(CRectangle, Element, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCircle, Element, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCurve, Element, VERSION_NUMBER)
IMPLEMENT_SERIAL(CText, Element, VERSION_NUMBER)
// CLine class constructor
CLine::CLine(const CPoint& Start, const CPoint& End, const COLORREF& Color, 
                                                     const int& PenWidth)
{
   m_StartPoint = Start;      // Set line start point
   m_EndPoint = End;          // Set line end point
   NPcolor = Color;          // Set line color
   m_Pen = PenWidth;          // Set pen width
   // Define the enclosing rectangle
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}
void CLine::Draw(CDC* pDC, const Element* pElement) const
{
   // Create a pen for this object and
   // initialize it to the object color and line width
   CPen aPen;
   COLORREF aColor = NPcolor;            // Initialize with element color
   if (this == pElement)                 // This element selected?
      aColor = SELECT_COLOR;             // Set highlight color
   if (!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
   {
      // Pen creation failed. Abort the program
      AfxMessageBox("Pen creation failed drawing a line", MB_OK);
      AfxAbort();
   }
   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen
   // Now draw the line
   pDC->MoveTo(m_StartPoint);
   pDC->LineTo(m_EndPoint);
   pDC->SelectObject(pOldPen);                // Restore the old pen
}
// Get the bounding rectangle for an element
CRect Element::GetBoundRect() const
{
   CRect BoundingRect;              // Object to store bounding rectangle
   BoundingRect = m_EnclosingRect;  // Store the enclosing rectangle
   // Increase the rectangle by the pen width
   int Offset = m_Pen == 0? 1:m_Pen;  // Width must be at least 1
   BoundingRect.InflateRect(Offset, Offset);
   return BoundingRect;
}
// CRectangle class constructor
CRectangle:: CRectangle(const CPoint& Start, const CPoint& End, 
const COLORREF& Color, const int& PenWidth)
{
   NPcolor = Color;           // Set rectangle color
   m_Pen = PenWidth;          // Set pen width
   // Define the enclosing rectangle 
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}
// Draw a CRectangle object
void CRectangle::Draw(CDC* pDC, const Element* pElement) const
{
   // Create a pen for this object and
   // initialize it to the object color and line width
   CPen aPen;
   COLORREF aColor = NPcolor;            // Initialize with element color
   if (this == pElement)                 // This element selected?
      aColor = SELECT_COLOR;             // Set highlight color
   if (!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
   { 
      // Pen creation failed
      AfxMessageBox("Pen creation failed drawing a rectangle", MB_OK);
      AfxAbort();
   }
   // Select the pen
   CPen* pOldPen = pDC->SelectObject(&aPen);   
   // Select the brush
   CBrush* pOldBrush = static_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH)); 
   // Now draw the rectangle
   pDC->Rectangle(m_EnclosingRect);
   pDC->SelectObject(pOldBrush);              // Restore the old brush
   pDC->SelectObject(pOldPen);                // Restore the old pen
}
// Constructor for a circle object
CCircle::CCircle(const CPoint& Start, const CPoint& End, const COLORREF& Color,
				                                         const int& PenWidth)
{
   // First calculate the radius
   // We use floating point because that is required by 
   // the library function (in math.h) for calculating a square root.
   long Radius = 
        static_cast<long>(sqrt(static_cast<double>((End.x-Start.x)*(End.x-Start.x)+
                                                   (End.y-Start.y)*(End.y-Start.y))));
   // Now calculate the rectangle enclosing
   // the circle assuming the MM_TEXT mapping mode
   m_EnclosingRect = CRect(Start.x - Radius, Start.y - Radius,
                           Start.x + Radius, Start.y + Radius);
   NPcolor = Color;          // Set the color for the circle
   m_Pen = PenWidth;         // Set pen width
}
// Draw a circle
void CCircle::Draw(CDC* pDC, const Element* pElement) const
{
   // Create a pen for this object and
   // initialize it to the object color and line width
   CPen aPen;
   COLORREF aColor = NPcolor;            // Initialize with element color
   if (this == pElement)                 // This element selected?
      aColor = SELECT_COLOR;             // Set highlight color
   if (!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
   {
      // Pen creation failed
      AfxMessageBox("Pen creation failed drawing a circle", MB_OK);
      AfxAbort();
   }
   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen
   // Select a null brush
   CBrush* pOldBrush = static_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH)); 
   // Now draw the circle
   pDC->Ellipse(m_EnclosingRect);
   pDC->SelectObject(pOldPen);                // Restore the old pen
   pDC->SelectObject(pOldBrush);              // Restore the old brush
}
// Constructor for a curve object
CCurve::CCurve(const CPoint& FirstPoint, const CPoint& SecondPoint, const COLORREF& Color,
			                                                        const int& PenWidth)
{
   m_PointList.AddTail(FirstPoint);    // Add the 1st point to the list
   m_PointList.AddTail(SecondPoint);   // Add the 2nd point to the list
   NPcolor = Color;                    // Store the color
   m_Pen = PenWidth;                   // Set pen width
   // Construct the enclosing rectangle assuming MM_TEXT mode
   m_EnclosingRect = CRect(FirstPoint, SecondPoint);
   m_EnclosingRect.NormalizeRect();
}
void CCurve::AddSegment(const CPoint& Point)
{
   m_PointList.AddTail(Point);                // Add the point to the end
   // Modify the enclosing rectangle for the new point
   m_EnclosingRect = CRect( min(Point.x, m_EnclosingRect.left),
                            min(Point.y, m_EnclosingRect.top),
                            max(Point.x, m_EnclosingRect.right),
                            max(Point.y, m_EnclosingRect.bottom) );
}
// Draw a curve
void CCurve::Draw(CDC* pDC, const Element* pElement) const
{
   // Create a pen for this object and
   // initialize it to the object color and line width of 1 pixel
   CPen aPen;
   COLORREF aColor = NPcolor;            // Initialize with element color
   if (this == pElement)                 // This element selected?
      aColor = SELECT_COLOR;             // Set highlight color
   if (!aPen.CreatePen(PS_SOLID, m_Pen, aColor))
   {
      // Pen creation failed. Close the program
      AfxMessageBox("Pen creation failed drawing a curve", MB_OK);
      AfxAbort();
   }
   CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen
   // Now draw the curve
   // Get the position in the list of the first element
   POSITION aPosition = m_PointList.GetHeadPosition();
   // As long as it's good, move to that point
   if(aPosition)
      pDC->MoveTo(m_PointList.GetNext(aPosition));
   // Draw a segment for each of the following points
   while(aPosition)
      pDC->LineTo(m_PointList.GetNext(aPosition));
   pDC->SelectObject(pOldPen);                // Restore the old pen
}
void CLine::Move(const CSize& aSize)
{
   m_StartPoint += aSize;            // Move the start point
   m_EndPoint += aSize;              // and the end point
   m_EnclosingRect += aSize;         // Move the enclosing rectangle
}
void CRectangle::Move(const CSize& aSize)
{
   m_EnclosingRect+= aSize;          // Move the rectangle
}
void CCircle::Move(const CSize& aSize)
{
   m_EnclosingRect+= aSize;          // Move rectangle defining the circle
}
void CCurve::Move(const CSize& aSize)
{
   m_EnclosingRect += aSize;          // Move the rectangle
   // Get the 1st element position
   POSITION aPosition = m_PointList.GetHeadPosition();
   while(aPosition)
      m_PointList.GetNext(aPosition) += aSize; // Move each pt in the list
}
CText::CText(const CPoint& Start, const CPoint& End, const CString& String, 
                                                     const COLORREF& Color)
{
   m_Pen = 1;                     // Pen width only for bounding rectangle
   NPcolor = Color;               // Set the color for the text
   m_String = String;             // Make a copy of the string
   m_StartPoint = Start;          // Start point for string
   m_EnclosingRect = CRect(Start, End);
   m_EnclosingRect.NormalizeRect();
}
void CText::Draw(CDC* pDC, const Element* pElement) const
{
   CFont aFont;
   aFont.CreatePointFont(100, "");
   CFont* pOldFont = pDC->SelectObject(&aFont);
   COLORREF Color(NPcolor);          // Initialize with element color
   if (this == pElement)
      Color = SELECT_COLOR;          // Set selected color
   // Set the text color and output the text
   pDC->SetTextColor(Color);
   pDC->TextOut(m_StartPoint.x, m_StartPoint.y, m_String);
   pDC->SelectObject(pOldFont);
}
void CText::Move(const CSize& aSize)
{
   m_StartPoint += aSize;               // Move the start point
   m_EnclosingRect += aSize;            // Move the rectangle
}
void Element::Serialize(CArchive& ar)
{
   CObject::Serialize(ar);         // Call the base class function
   if (ar.IsStoring())
   {
      ar << NPcolor                // Store the color,
         << m_EnclosingRect        // and the enclosing rectangle,
         << m_Pen;                 // and the pen width
   }
   else
   {
      ar >> NPcolor                // Retrieve the color,
         >> m_EnclosingRect        // and the enclosing rectangle,
         >> m_Pen;                 // and the pen width
   }
}
void CLine::Serialize(CArchive& ar)
{
   Element::Serialize(ar);        // Call the base class function
   if (ar.IsStoring())
   {
      ar << m_StartPoint           // Store the line start point,
         << m_EndPoint;            // and the end point
   }
   else
   {
      ar >> m_StartPoint           // Retrieve the line start point,
         >> m_EndPoint;            // and the end point
   }
}
void CRectangle::Serialize(CArchive& ar)
{
   Element::Serialize(ar);        // Call the base class function
}
void CCircle::Serialize(CArchive& ar)
{
   Element::Serialize(ar);        // Call the base class function
}
void CCurve::Serialize(CArchive& ar)
{
   Element::Serialize(ar);        // Call the base class function
   m_PointList.Serialize(ar);      // Serialize the list of points
}
void CText::Serialize(CArchive& ar)
{
   Element::Serialize(ar);        // Call the base class function
   if (ar.IsStoring())
   {
      ar << m_StartPoint           // Store the start point
         << m_String;              // and the text string
   }
   else
   {
      ar >> m_StartPoint           // Retrieve the start point
         >> m_String;              // and the text string
   }
}
// Add definitions for member functions here

//---------------------------------------------------------------------------------------------------------------------------


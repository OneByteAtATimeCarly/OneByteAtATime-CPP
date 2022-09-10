//2006 C. Germany - Network Planner GUI App
//File: 19 of 25

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(Elements_h)
#define Elements_h
class Element : public CObject
{
DECLARE_SERIAL(Element)
protected:
   COLORREF NPcolor;                       // Color of an element
   CRect m_EnclosingRect;                  // Rectangle enclosing an element
   int m_Pen;                              // Pen width
public:
   virtual ~Element(){}                   // Virtual destructor
   // Virtual draw operation
   virtual void Draw(CDC* pDC, const Element* pElement = 0) const {}
   virtual void Move(const CSize& Size) {} // Move an element
   CRect GetBoundRect() const;             // Get the bounding rectangle for an element
   virtual void Serialize(CArchive& ar);      // Serialize function for Element
protected:
   Element(){}                            // Default constructor
};
// Class defining a line object
class CLine : public Element
{
DECLARE_SERIAL(CLine)
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const Element* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element
   // Constructor for a line object
   CLine(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);
   virtual void Serialize(CArchive& ar);      // Serialize function for CLine
protected:
   CPoint m_StartPoint;          // Start point of line
   CPoint m_EndPoint;            // End point of line
   CLine(){}             // Default constructor - should not be used
};
// Class defining a rectangle object
class CRectangle : public Element
{
DECLARE_SERIAL(CRectangle)
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const Element* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element
   // Constructor for a rectangle object
   CRectangle(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);
   virtual void Serialize(CArchive& ar);      // Serialize function for CRectangle
protected:
   CRectangle(){}        // Default constructor - should not be used
};
// Class defining a circle object
class CCircle : public Element
{
DECLARE_SERIAL(CCircle)
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const Element* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element
   // Constructor for a circle object
   CCircle(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);
   virtual void Serialize(CArchive& ar);      // Serialize function for CCircle
protected:
   CCircle(){}           // Default constructor - should not be used
};
// Class defining a curve object
class CCurve : public Element
{
DECLARE_SERIAL(CCurve)
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const Element* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element
   // Constructor for a curve object
   CCurve(const CPoint& FirstPoint, const CPoint& SecondPoint, 
const COLORREF& Color, const int& PenWidth);
   virtual void Serialize(CArchive& ar);      // Serialize function for CCurve
   void AddSegment(const CPoint& Point);     //Add a segment to the curve
protected:
   // CCurve data members to go here
   CList<CPoint, const CPoint&> m_PointList;  // Type safe point list
   CCurve(){}           // Default constructor - should not be used
};
class CText : public Element
{
DECLARE_SERIAL(CText)
public:
   // Function to display a text element
   virtual void Draw(CDC* pDC, const Element* pElement = NULL) const;
   // Constructor for a text element
   CText(const CPoint& Start, const CPoint& End, const CString& String, const COLORREF& Color);
   virtual void Move(const CSize& Size);       // Move a text element
   virtual void Serialize(CArchive& ar);      // Serialize function for CText
protected:
   CPoint m_StartPoint;                   // position of a text element
   CString m_String;                      // Text to be displayed
   CText(){}                              // Default constructor
};
#endif //!defined(Elements_h)

//---------------------------------------------------------------------------------------------------------------------------


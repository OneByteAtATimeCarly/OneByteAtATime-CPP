//2006 C. Germany - Network Planner GUI App
//File: 6 of 25

//---------------------------------------------------------------------------------------------------------------------------

// NetProgPlannerDoc.cpp : implementation of the CNetProgPlannerDoc class
//
#include "stdafx.h"
#include "NetProgPlanner.h"
#include "PenDialog.h"
#include "NPelements.h"
#include "NetProgPlannerDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerDoc
IMPLEMENT_DYNCREATE(CNetProgPlannerDoc, CDocument)
BEGIN_MESSAGE_MAP(CNetProgPlannerDoc, CDocument)
	//{{AFX_MSG_MAP(CNetProgPlannerDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_GRAY, OnColorGray)
	ON_COMMAND(ID_COLOR_AQUA, OnColorAqua)
	ON_COMMAND(ID_COLOR_FUSCHIA, OnColorFuschia)
	ON_COMMAND(ID_COLOR_YELLOW, OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GRAY, OnUpdateColorGray)
	ON_UPDATE_COMMAND_UI(ID_COLOR_AQUA, OnUpdateColorAqua)
	ON_UPDATE_COMMAND_UI(ID_COLOR_FUSCHIA, OnUpdateColorFuschia)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, OnUpdateColorYellow)
	ON_COMMAND(ID_ELEMENT_CIRCLE, OnElementCircle)
	ON_COMMAND(ID_ELEMENT_CURVE, OnElementCurve)
	ON_COMMAND(ID_ELEMENT_LINE, OnElementLine)
	ON_COMMAND(ID_ELEMENT_RECTANGLE, OnElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, OnUpdateElementCircle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, OnUpdateElementCurve)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, OnUpdateElementLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, OnUpdateElementRectangle)
	ON_COMMAND(ID_PENWIDTH, OnPenwidth)
	ON_COMMAND(ID_ELEMENT_TEXT, OnElementText)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_TEXT, OnUpdateElementText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerDoc construction/destruction
CNetProgPlannerDoc::CNetProgPlannerDoc()
{
	// TODO: add one-time construction code here
   NPelement = LINE;   // Set initial element type
   NPcolor = BLACK;    // Set initial drawing color
   NPpenwidth = 0;     // Set 1 pixel pen
   NPdocsize = CSize(3000,3000); // Set initial document size 30x30 inches
}
CNetProgPlannerDoc::~CNetProgPlannerDoc()
{
   // Get the position at the head of the list
   POSITION aPosition = NPelementList.GetHeadPosition();
   // Now delete the element pointed to by each list entry
   while(aPosition)
      delete NPelementList.GetNext(aPosition);
   NPelementList.RemoveAll();   // Finally delete all pointers
}
BOOL CNetProgPlannerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerDoc serialization
void CNetProgPlannerDoc::Serialize(CArchive& ar)
{
   NPelementList.Serialize(ar);    // Serialize the element list
   if (ar.IsStoring())
   {
      ar << NPcolor                // Store the current color
         << NPelement              // the current element type,
         << NPpenwidth             // and the current pen width
         << NPdocsize;             // and the current document size
   }
   else
   {
      ar >> NPcolor                // Retrieve the current color
         >> NPelement              // the current element type,
         >> NPpenwidth             // and the current pen width
         >> NPdocsize;             // and the current document size
   }
}
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerDoc diagnostics
#ifdef _DEBUG
void CNetProgPlannerDoc::AssertValid() const
{
	CDocument::AssertValid();
}
void CNetProgPlannerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerDoc commands

//COLORS-------------------------------------------------------------------------------
void CNetProgPlannerDoc::OnColorBlack() 
{
   NPcolor = BLACK;        // Set the drawing color to black	
}
void CNetProgPlannerDoc::OnColorBlue() 
{
   NPcolor = BLUE;        // Set the drawing color to blue
}
void CNetProgPlannerDoc::OnColorGreen() 
{
   NPcolor = GREEN;        // Set the drawing color to green
}
void CNetProgPlannerDoc::OnColorRed() 
{
   NPcolor = RED;        // Set the drawing color to red
}
void CNetProgPlannerDoc::OnUpdateColorBlack(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is black
   pCmdUI->SetCheck(NPcolor==BLACK);
}
void CNetProgPlannerDoc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is blue
   pCmdUI->SetCheck(NPcolor==BLUE);
}
void CNetProgPlannerDoc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is green
   pCmdUI->SetCheck(NPcolor==GREEN);
}
void CNetProgPlannerDoc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is red
   pCmdUI->SetCheck(NPcolor==RED);
}






void CNetProgPlannerDoc::OnColorGray() 
{
   NPcolor = GRAY;        // Set the drawing color to black	
}
void CNetProgPlannerDoc::OnColorYellow() 
{
   NPcolor = YELLOW;        // Set the drawing color to blue
}
void CNetProgPlannerDoc::OnColorFuschia() 
{
   NPcolor = FUSCHIA;        // Set the drawing color to green
}
void CNetProgPlannerDoc::OnColorAqua() 
{
   NPcolor = AQUA;        // Set the drawing color to red
}
void CNetProgPlannerDoc::OnUpdateColorGray(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is black
   pCmdUI->SetCheck(NPcolor==GRAY);
}
void CNetProgPlannerDoc::OnUpdateColorYellow(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is blue
   pCmdUI->SetCheck(NPcolor==YELLOW);
}
void CNetProgPlannerDoc::OnUpdateColorFuschia(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is green
   pCmdUI->SetCheck(NPcolor==FUSCHIA);
}
void CNetProgPlannerDoc::OnUpdateColorAqua(CCmdUI* pCmdUI)
{
   // Set menu item Checked if the current color is red
   pCmdUI->SetCheck(NPcolor==AQUA);
}
//-------------------------------------------------------------------------------
void CNetProgPlannerDoc::OnElementCircle() 
{
   NPelement = CIRCLE;       // Set element type as a circle
}
void CNetProgPlannerDoc::OnElementCurve() 
{
   NPelement = CURVE;       // Set element type as a curve
}
void CNetProgPlannerDoc::OnElementLine() 
{
   NPelement = LINE;       // Set element type as a line
}
void CNetProgPlannerDoc::OnElementRectangle() 
{
   NPelement = RECTANGLE;       // Set element type as a rectangle
}
void CNetProgPlannerDoc::OnUpdateElementCircle(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a circle
   pCmdUI->SetCheck(NPelement==CIRCLE);
}
void CNetProgPlannerDoc::OnUpdateElementCurve(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a curve
   pCmdUI->SetCheck(NPelement==CURVE);
}
void CNetProgPlannerDoc::OnUpdateElementLine(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a line
   pCmdUI->SetCheck(NPelement==LINE);
}
void CNetProgPlannerDoc::OnUpdateElementRectangle(CCmdUI* pCmdUI)
{
   // Set Checked if the current element is a rectangle
   pCmdUI->SetCheck(NPelement==RECTANGLE);
}
void CNetProgPlannerDoc::DeleteElement(Element* pElement)
{
   if(pElement)
   {
      // If the element pointer is valid,
      // find the pointer in the list and delete it
      SetModifiedFlag();         // Set the modified flag
      POSITION aPosition = NPelementList.Find(pElement);
      NPelementList.RemoveAt(aPosition);
      delete pElement;           // Delete the element from the heap
   }
}
void CNetProgPlannerDoc::SendToBack(Element* pElement)
{
   if(pElement)
   {
      // If the element pointer is valid,
      // find the pointer in the list and remove the element
      POSITION aPosition = NPelementList.Find(pElement);
      NPelementList.RemoveAt(aPosition);
      NPelementList.AddHead(pElement);  // Put it back to the beginning
   }
}
// Handler for the pen width menu item
void CNetProgPlannerDoc::OnPenwidth()
{
   CPenDialog aDlg;     // Create a local dialog object
   // Set the pen width in the dialog to that stored in the document
   aDlg.NPpenwidth = NPpenwidth;
   // Display the dialog as modal
   // When closed with OK, get the pen width
   if(aDlg.DoModal() == IDOK)
      NPpenwidth = aDlg.NPpenwidth;
}
void CNetProgPlannerDoc::OnElementText() 
{
	NPelement = TEXT;
}
void CNetProgPlannerDoc::OnUpdateElementText(CCmdUI* pCmdUI) 
{
   // Set checked if the current element is text
   pCmdUI->SetCheck(NPelement == TEXT);
}
// Get the rectangle enclosing the entire document
CRect CNetProgPlannerDoc::GetDocExtent() const
{
   CRect DocExtent(0,0,1,1);    // Initial document extent
   CRect ElementBound(0,0,0,0); // Space for element bounding rectangle
   POSITION aPosition = NPelementList.GetHeadPosition();
   while(aPosition)      // Loop through all the elements in the list
   {
      // Get the bounding rectangle for the element
      ElementBound=(NPelementList.GetNext(aPosition))->GetBoundRect();
      // Make coordinates of document extent the outer limits
      DocExtent.UnionRect(DocExtent, ElementBound);
   }
   DocExtent.NormalizeRect();
   return DocExtent;
}

//---------------------------------------------------------------------------------------------------------------------------


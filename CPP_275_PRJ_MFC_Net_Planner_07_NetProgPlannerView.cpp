//2006 C. Germany - Network Planner GUI App
//File: 7 of 25

//---------------------------------------------------------------------------------------------------------------------------

// NetProgPlannerView.cpp : implementation of the CNetProgPlannerView class
//
#include "stdafx.h"
#include "NetProgPlanner.h"
#include <math.h>
#include "PrintData.h" 
#include "TextDialog.h"
#include "ChildFrm.h"
#include "ScaleDialog.h"
#include "NPelements.h"
#include "NetProgPlannerDoc.h"
#include "NetProgPlannerView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView
IMPLEMENT_DYNCREATE(CNetProgPlannerView, CScrollView)
BEGIN_MESSAGE_MAP(CNetProgPlannerView, CScrollView)
	//{{AFX_MSG_MAP(CNetProgPlannerView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MOVE, OnMove)
	ON_COMMAND(ID_DELETE, OnDelete)
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_SENDTOBACK, OnSendtoback)
	ON_COMMAND(ID_VIEW_SCALE, OnViewScale)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView construction/destruction
CNetProgPlannerView::CNetProgPlannerView()
{
	// TODO: add construction code here
   NPfirstpoint = CPoint(0,0);         // Set 1st recorded point to 0,0
   NPsecondpoint = CPoint(0,0);        // Set 2nd recorded point to 0,0
   NPelement = NULL;              // Set temporary element pointer to 0
   NPselected = NULL;                 // No element selected initially
   NPmovemode = FALSE;                 // Set move mode off
   NPcursorpos = CPoint(0,0);          // Initialize as zero
   NPfirstpos = CPoint(0,0);           // Initialize as zero
   NPscale = 1;                        // Set scale to 1:1
   SetScrollSizes(MM_TEXT, CSize(0,0));// Set arbitrary scrollers
}
CNetProgPlannerView::~CNetProgPlannerView()
{
}
BOOL CNetProgPlannerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView drawing
void CNetProgPlannerView::OnDraw(CDC* pDC)
{
   CNetProgPlannerDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   POSITION aPos = pDoc->GetListHeadPosition();
   Element* pElement = 0;              // Store for an element pointer
   while(aPos)                          // Loop while aPos is not null
   {
      pElement = pDoc->GetNext(aPos);   // Get the current element pointer
      // If the element is visible...
      if(pDC->RectVisible(pElement->GetBoundRect()))
         pElement->Draw(pDC, NPselected);  // ...draw it
   }
}
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView printing
BOOL CNetProgPlannerView::OnPreparePrinting(CPrintInfo* pInfo)
{
   // Create a print data object 
   CPrintData* pPrintData;
   pInfo->m_lpUserData = pPrintData = new CPrintData;
   CNetProgPlannerDoc* pDoc = GetDocument();    // Get a document pointer
   // Get the whole document area
   CRect DocExtent = pDoc->GetDocExtent();
   // Save the reference point for the whole document
   pPrintData->m_DocRefPoint = CPoint(DocExtent.left, DocExtent.bottom);
   // Get the name of the document file and save it
   pPrintData->m_DocTitle = pDoc->GetTitle();
   // Calculate how many printed page widths of 600 units are required
   // to accommodate the width of the document
   pPrintData->m_nWidths =
                         (UINT)ceil(static_cast<double>(DocExtent.Width()) / 600.0);
   // Calculate how many printed page lengths of 900 units are required
   // to accommodate the document length
   pPrintData->m_nLengths =
                         (UINT)ceil(static_cast<double>(DocExtent.Height()) / 900.0);
   // Set the first page number as 1 and
   // set the last page number as the total number of pages
   pInfo->SetMinPage(1);
   pInfo->SetMaxPage(pPrintData->m_nWidths * pPrintData->m_nLengths);
   if(!DoPreparePrinting(pInfo))
     {
        delete static_cast<CPrintData*>(pInfo->m_lpUserData);
        return FALSE;
     }
   return TRUE;
}
void CNetProgPlannerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}
void CNetProgPlannerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
   // Delete our print data object
   delete static_cast<CPrintData*>(pInfo->m_lpUserData);
}
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView diagnostics
#ifdef _DEBUG
void CNetProgPlannerView::AssertValid() const
{
	CView::AssertValid();
}
void CNetProgPlannerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
CNetProgPlannerDoc* CNetProgPlannerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetProgPlannerDoc)));
	return (CNetProgPlannerDoc*)m_pDocument;
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerView message handlers
void CNetProgPlannerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
   CClientDC aDC(this);                // Create a device context
   OnPrepareDC(&aDC);                  // Get origin adjusted
   aDC.DPtoLP(&point);                 // convert point to Logical
   if(NPmovemode)
   {
      // In moving mode, so drop the element
      NPmovemode = FALSE;                 // Kill move mode
      NPselected = 0;                    // De-select the element
      GetDocument()->UpdateAllViews(0);   // Redraw all the views
      GetDocument()->SetModifiedFlag();   // Set the modified flag
   }
   else
   {
      CNetProgPlannerDoc* pDoc = GetDocument();   // Get a document pointer
      if(pDoc->GetElementType() == TEXT)
      {
         CTextDialog aDlg;
         if(aDlg.DoModal() == IDOK)
         {
            // Exit OK so create a text element 
			CFont aFont;
            aFont.CreatePointFont(100, "");
            CFont* pOldFont = aDC.SelectObject(&aFont);
            CSize TextExtent = aDC.GetTextExtent(aDlg.m_TextString);
            // Get bottom right of text rectangle - MM_LOENGLISH
            CPoint BottomRt(point.x+TextExtent.cx, point.y-TextExtent.cy);
            CText* pTextElement = new CText(point, BottomRt,
                              aDlg.m_TextString, pDoc->GetElementColor());
            // Add the element to the document
            pDoc->AddElement(pTextElement);
            // Get all views updated
            pDoc->UpdateAllViews(0,0,pTextElement);
            aDC.SelectObject(pOldFont);
         }
         return;
      }
      NPfirstpoint = point;               // Record the cursor position
      SetCapture();                       // Capture subsequent mouse messages
   }
}
void CNetProgPlannerView::OnLButtonUp(UINT nFlags, CPoint point)
{
   if(this == GetCapture())
      ReleaseCapture();      // Stop capturing mouse messages
   // If there is an element, add it to the document
   if(NPelement)
   {
      GetDocument()->AddElement(NPelement);
      GetDocument()->UpdateAllViews(0,0,NPelement);  
                                // Tell all the views
      NPelement = 0;       // Reset the element pointer
   }
}
void CNetProgPlannerView::OnMouseMove(UINT nFlags, CPoint point)
{
   // Define a Device Context object for the view
   CClientDC aDC(this);
   OnPrepareDC(&aDC);            // Get origin adjusted
   // If we are in move mode, move the selected element and return
   if(NPmovemode)
   {
      aDC.DPtoLP(&point);        // Convert to logical coordinatess
      MoveElement(aDC, point);   // Move the element
      return;
   }
   if((nFlags & MK_LBUTTON) && (this == GetCapture()))
   {
      aDC.DPtoLP(&point);        // convert point to Logical
	  NPsecondpoint = point;     // Save the current cursor position
      if(NPelement)
      {
         if(CURVE == GetDocument()->GetElementType())   // Is it a curve?
         {  // We are drawing a curve
            // so add a segment to the existing curve
            (static_cast<CCurve*>(NPelement))->AddSegment(NPsecondpoint);
            NPelement->Draw(&aDC);  // Now draw it
            return;                      // We are done
         }
         aDC.SetROP2(R2_NOTXORPEN);                 // Set drawing mode
         // Redraw the old element so it disappears from the view
         NPelement->Draw(&aDC);
         delete NPelement;        // Delete the old element
         NPelement = 0;           // Reset the pointer to 0
      }
      // Create a temporary element of the type and color that
      // is recorded in the document object, and draw it
      NPelement = CreateElement();  // Create a new element
      NPelement->Draw(&aDC);        // Draw the element
   }
   else        // We are not drawing an element...
   {           // ...so do highlighting
      CRect aRect;
      Element* pCurrentSelection = SelectElement(point);
      if(pCurrentSelection!=NPselected)
      {
         if(NPselected)             // Old elemented selected?
         {                           // Yes, so draw it unselected
            aRect = NPselected->GetBoundRect(); // Get bounding rectangle
            aDC.LPtoDP(aRect);                   // Conv to device coords
            aRect.NormalizeRect();               // Normalize
            InvalidateRect(aRect, FALSE);        // Invalidate area
         }
         NPselected = pCurrentSelection;        // Save elem under cursor
         if(NPselected)                         // Is there one?
         {                                       // Yes, so get it redrawn
            aRect = NPselected->GetBoundRect(); // Get bounding rectangle
            aDC.LPtoDP(aRect);                   // Conv to device coords
            aRect.NormalizeRect();               // Normalize
            InvalidateRect(aRect, FALSE);        // Invalidate area
         }
      }
   }
}
// Create an element of the current type
Element* CNetProgPlannerView::CreateElement()
{
   // Get a pointer to the document for this view
   CNetProgPlannerDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);                  // Verify the pointer is good
   // Now select the element using the type stored in the document
   switch(pDoc->GetElementType())
   {
      case RECTANGLE:
         return new CRectangle(NPfirstpoint, NPsecondpoint,
                            pDoc->GetElementColor(), pDoc->GetPenWidth());
      case CIRCLE:
         return new CCircle(NPfirstpoint, NPsecondpoint,
                            pDoc->GetElementColor(), pDoc->GetPenWidth());
      case CURVE:
         return new CCurve(NPfirstpoint, NPsecondpoint,
                            pDoc->GetElementColor(), pDoc->GetPenWidth());
      case LINE:                         // Always default to a line
         return new CLine(NPfirstpoint, NPsecondpoint,
                            pDoc->GetElementColor(), pDoc->GetPenWidth());
      default:
         // Something's gone wrong
         AfxMessageBox("Bad Element code", MB_OK);
         AfxAbort();
         return NULL;
   }
}
void CNetProgPlannerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
   // Invalidate the area corresponding to the element pointed to
   // if there is one, otherwise invalidate the whole client area
   if(pHint)
   {
      CClientDC aDC(this);            // Create a device context
      OnPrepareDC(&aDC);              // Get origin adjusted
      // Get the enclosing rectangle and convert to client coordinates
      CRect aRect = static_cast<Element*>(pHint)->GetBoundRect();
      aDC.LPtoDP(aRect);
	  aRect.NormalizeRect();
      InvalidateRect(aRect);          // Get the area redrawn
   }
   else
      InvalidateRect(0);              // Invalidate the client area
}
void CNetProgPlannerView::OnInitialUpdate()
{
   ResetScrollSizes();               // Set up the scrollbars
   CScrollView::OnInitialUpdate();
}
void CNetProgPlannerView::OnMove()
{
   CClientDC aDC(this);
   OnPrepareDC(&aDC);              // Set up the device context
   GetCursorPos(&NPcursorpos);     // Get cursor position in screen coords
   ScreenToClient(&NPcursorpos);   // Convert to client coords
   aDC.DPtoLP(&NPcursorpos);       // Convert to logical
   NPfirstpos = NPcursorpos;       // Remember first position
   NPmovemode = TRUE;              // Start move mode
}
void CNetProgPlannerView::OnDelete()
{
   if(NPselected)
   {
      CNetProgPlannerDoc* pDoc = GetDocument();  // Get the document pointer
      pDoc->DeleteElement(NPselected);    // Delete the element
      pDoc->UpdateAllViews(0);             // Redraw all the views
      NPselected = 0;                     // Reset selected element ptr
   }
}
void CNetProgPlannerView::OnRButtonUp(UINT nFlags, CPoint point)
{
   // Create the cursor menu
   CMenu aMenu;
   aMenu.LoadMenu(IDR_CURSOR_MENU);    // Load the cursor menu
   ClientToScreen(&point);             // Convert to screen coordinates
   // Display the pop-up at the cursor position
   if(NPselected)
      aMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,
                                                  point.x, point.y, this);
   else
   {
      // Check color menu items
      COLORREF Color = GetDocument()->GetElementColor();
      aMenu.CheckMenuItem(ID_COLOR_BLACK,
                     (BLACK==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_COLOR_RED,
                       (RED==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_COLOR_GREEN,
                     (GREEN==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_COLOR_BLUE,
                      (BLUE==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      // Check element menu items
      WORD ElementType = GetDocument()->GetElementType();
      aMenu.CheckMenuItem(ID_ELEMENT_LINE,
                (LINE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_ELEMENT_RECTANGLE,
                (RECTANGLE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_ELEMENT_CIRCLE,
                (CIRCLE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_ELEMENT_CURVE,
                (CURVE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      aMenu.CheckMenuItem(ID_ELEMENT_TEXT,
                (TEXT==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND) ;
      // Display the context pop-up
      aMenu.GetSubMenu(1)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,
                                                  point.x, point.y, this);
   }
}
// Find the element at the cursor
Element* CNetProgPlannerView::SelectElement(CPoint aPoint)
{
   // Convert parameter aPoint to logical coordinates
   CClientDC aDC(this);
   OnPrepareDC(&aDC);
   aDC.DPtoLP(&aPoint);
   CNetProgPlannerDoc* pDoc=GetDocument();      // Get a pointer to the document
   Element* pElement = 0;                // Store an element pointer
   CRect aRect(0,0,0,0);                  // Store a rectangle
   POSITION aPos = pDoc->GetListTailPosition();  // Get last element posn
   while(aPos)                            // Iterate through the list
   {
      pElement = pDoc->GetPrev(aPos);
      aRect = pElement->GetBoundRect();
      // Select the first element that appears under the cursor
      if(aRect.PtInRect(aPoint))
         return pElement;
   }
   return 0;                              // No element found
}
void CNetProgPlannerView::MoveElement(CClientDC& aDC, const CPoint& point)
{
   CSize Distance = point - NPcursorpos;   // Get move distance
   NPcursorpos = point;          // Set current point as 1st for next time
   // If there is an element selected, move it
   if(NPselected)
   {
      // If the element is text use this method...
      if (NPselected->IsKindOf(RUNTIME_CLASS(CText)))
      {
         CRect OldRect=NPselected->GetBoundRect();  // Get old bound rect
         NPselected->Move(Distance);                // Move the element
         CRect NewRect=NPselected->GetBoundRect();  // Get new bound rect
         OldRect.UnionRect(&OldRect,&NewRect);       // Combine the bound rects
         aDC.LPtoDP(OldRect);                        // Convert to client coords
         OldRect.NormalizeRect();                    // Normalize combined area
         InvalidateRect(&OldRect);                   // Invalidate combined area
         UpdateWindow();                             // Redraw immediately
         NPselected->Draw(&aDC,NPselected);        // Draw highlighted
         return;
      }
      // ...otherwise, use this method
      aDC.SetROP2(R2_NOTXORPEN);
      NPselected->Draw(&aDC,NPselected); // Draw the element to erase it
      NPselected->Move(Distance);         // Now move the element
      NPselected->Draw(&aDC,NPselected); // Draw the moved element
   }
}
void CNetProgPlannerView::OnRButtonDown(UINT nFlags, CPoint point)
{
   if(NPmovemode)
   {
      // In moving mode, so drop element back in original position
      CClientDC aDC(this);
      OnPrepareDC(&aDC);                  // Get origin adjusted
      MoveElement(aDC, NPfirstpos);       // Move element to orig position
      NPmovemode = FALSE;                 // Kill move mode
      NPselected = 0;                    // De-select element
      GetDocument()->UpdateAllViews(0);   // Redraw all the views
      return;                             // We are done
   }
}
void CNetProgPlannerView::OnSendtoback() 
{
   GetDocument()->SendToBack(NPselected); 
	
}
void CNetProgPlannerView::OnViewScale() 
{
   CScaleDialog aDlg;            // Create a dialog object
   aDlg.NPscale = NPscale;       // Pass the view scale to the dialog
   if(aDlg.DoModal() == IDOK)
   {
      NPscale = 1 + aDlg.NPscale;  // Get the new scale
      // Get the frame window for this view
      CChildFrame* viewFrame = static_cast<CChildFrame*>(GetParentFrame());
      // Build the message string
      CString StatusMsg("View Scale:");
      StatusMsg += static_cast<char>('0' + NPscale);
      // Write the string to the status bar
      viewFrame->m_StatusBar.GetStatusBarCtrl().SetText(StatusMsg, 0, 0);
      ResetScrollSizes();         // Adjust scrolling to the new scale
      InvalidateRect(0);         // Invalidate the whole window
   }
}
void CNetProgPlannerView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
   int Scale = NPscale;              // Store the scale locally
   if(pDC->IsPrinting())
      Scale = 1;                     // If we are printing, set scale to 1
   CScrollView::OnPrepareDC(pDC, pInfo);
   CNetProgPlannerDoc* pDoc = GetDocument();
   pDC->SetMapMode(MM_ANISOTROPIC);           // Set the map mode
   CSize DocSize = pDoc->GetDocSize();        // Get the document size
   // y extent must be negative because we want MM_LOENGLISH
   DocSize.cy = -DocSize.cy;                  // Change sign of y
   pDC->SetWindowExt(DocSize);                // Now set the window extent
   // Get the number of pixels per inch in x and y
   int xLogPixels = pDC->GetDeviceCaps(LOGPIXELSX);
   int yLogPixels = pDC->GetDeviceCaps(LOGPIXELSY);
   // Calculate the viewport extent in x and y
   int xExtent = DocSize.cx * Scale * xLogPixels / 100;
   int yExtent = DocSize.cy * Scale * yLogPixels / 100;
   pDC->SetViewportExt(xExtent, -yExtent); // Set viewport extent
}
void CNetProgPlannerView::ResetScrollSizes()
{
   CClientDC aDC(this);
   OnPrepareDC(&aDC);                            // Set up the device context
   CSize DocSize = GetDocument()->GetDocSize();  // Get the document size
   aDC.LPtoDP(&DocSize);                         // Get the size in pixels
   SetScrollSizes(MM_TEXT, DocSize);             // Set up the scrollbars
}
// Print a page of the document
// Print a page of the document
void CNetProgPlannerView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
   CPrintData* pPrintData = static_cast<CPrintData*>(pInfo->m_lpUserData);
   // Output the document file name
   pDC->SetTextAlign(TA_CENTER);           // Center the following text
   pDC->TextOut(pInfo->m_rectDraw.right/2, -20,
                        pPrintData->m_DocTitle);
   CString PageNum;
   PageNum.Format("Page %d", pInfo->m_nCurPage);
   pDC->TextOut(pInfo->m_rectDraw.right/2, -1050, PageNum);
   pDC->SetTextAlign(TA_LEFT);             // Left justify text
   // Calculate the origin point for the current page
   int xOrg = pPrintData->m_DocRefPoint.x +
                  600 * ((pInfo->m_nCurPage - 1)%
                      (pPrintData->m_nWidths));
   int yOrg = pPrintData->m_DocRefPoint.y -
                  900 * ((pInfo->m_nCurPage - 1)/
                      (pPrintData->m_nWidths));
   // Calculate offsets to center drawing area on page as positive values
   int xOffset = (pInfo->m_rectDraw.right - 600) / 2;
   int yOffset = -(pInfo->m_rectDraw.bottom + 900) / 2;
   // Change window origin to correspond to current page & save old origin
   CPoint OldOrg = pDC->SetWindowOrg(xOrg - xOffset, yOrg + yOffset);
   // Define a clip rectangle the size of the printed area
   pDC->IntersectClipRect(xOrg, yOrg, xOrg + 600, yOrg - 900);
   OnDraw(pDC);                            // Draw the whole document
   pDC->SelectClipRgn(NULL);               // Remove the clip rectangle
   pDC->SetWindowOrg(OldOrg);              // Restore old window origin
}

//---------------------------------------------------------------------------------------------------------------------------


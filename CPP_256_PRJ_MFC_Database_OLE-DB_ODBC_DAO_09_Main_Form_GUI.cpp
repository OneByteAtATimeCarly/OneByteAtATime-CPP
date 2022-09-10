//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 9 of 20

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Contacts.h"
#include "MainFrm.h"
#include "ContactConstants.h"
#include "DetailsView.h"
#include "ContactsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CMainFrame
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
CMainFrame::CMainFrame()
{
	CurrentView = CONTACTS_VIEW;
	
}
CMainFrame::~CMainFrame()
{
}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	return 0;
}
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics
#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}
void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::SelectView(UINT ViewID)
{
   CView * pOldActiveView = GetActiveView();     // Get current view
   // Get pointer to new view if it exists
   // if it doesn't the pointer will be null
   CView * pNewActiveView = (CView *)GetDlgItem(ViewID);
   // If this is 1st time around for the new view, 
   // the new view won't exist, so we must create it
   if (pNewActiveView == NULL)
   {
      switch(ViewID)
      {
         case DETAILS_VIEW:      // Create an Order view
            pNewActiveView = (CView *)new DetailsView;
            break;
         default:
            AfxMessageBox("Invalid View ID");
            return;
   } 
      // Switching the views
      // Obtain the current view context to apply to the new view
      CCreateContext context;  //Necessary to create a window for a view
      context.m_pCurrentDoc = pOldActiveView->GetDocument();
      pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault,this, ViewID, &context);
      pNewActiveView->OnInitialUpdate();
   }
   SetActiveView(pNewActiveView);                 // Activate the new view
   pOldActiveView->ShowWindow(SW_HIDE);           // Hide the old view
   pNewActiveView->ShowWindow(SW_SHOW);           // Show the new view
   pOldActiveView->SetDlgCtrlID(CurrentView); // Set the old view ID
   pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
   CurrentView = ViewID;                      // Save the new view ID
   RecalcLayout();
}

//---------------------------------------------------------------------------------------------------------------------------


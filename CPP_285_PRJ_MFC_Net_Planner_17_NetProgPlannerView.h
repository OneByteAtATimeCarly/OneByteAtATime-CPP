//2006 C. Germany - Network Planner GUI App
//File: 17 of 25

//---------------------------------------------------------------------------------------------------------------------------

// NetProgPlannerView.h : interface of the CNetProgPlannerView class
//
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_NetProgPlannerVIEW_H__AD381310_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_NetProgPlannerVIEW_H__AD381310_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CNetProgPlannerView : public CScrollView
{
protected: // create from serialization only
	CNetProgPlannerView();
	DECLARE_DYNCREATE(CNetProgPlannerView)
// Attributes
public:
	CNetProgPlannerDoc* GetDocument();
protected:
   CPoint NPfirstpoint;      // First point recorded for an element
   CPoint NPsecondpoint;     // Second point recorded for an element
   Element* NPelement;    // Pointer to temporary element
   Element* NPselected;       // Currently selected element
   BOOL NPmovemode;           // Move element flag
   CPoint NPcursorpos;        // Cursor position
   CPoint NPfirstpos;         // Original position in a move
   int NPscale;         // Current view scale
// Operations
public:
protected:
   Element* CreateElement(); // Create a new element on the heap
   Element* SelectElement(CPoint aPoint);         // Select an element
   void MoveElement(CClientDC& aDC, const CPoint& point);  // Move an element
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetProgPlannerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
// Implementation
public:
	void ResetScrollSizes();
	virtual ~CNetProgPlannerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CNetProgPlannerView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMove();
	afx_msg void OnDelete();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSendtoback();
	afx_msg void OnViewScale();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in NetProgPlannerView.cpp
inline CNetProgPlannerDoc* CNetProgPlannerView::GetDocument()
   { return (CNetProgPlannerDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_NetProgPlannerVIEW_H__AD381310_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


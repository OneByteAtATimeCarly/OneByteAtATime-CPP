//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 15 of 20

//---------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
#include "ContactsDoc.h"
#if !defined(AFX_CONTACTSVIEW_H__177C9F16_CC80_420A_BBF1_F3122368B5C7__INCLUDED_)
#define AFX_CONTACTSVIEW_H__177C9F16_CC80_420A_BBF1_F3122368B5C7__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CContactsSet;
class CContactsView : public CDaoRecordView
{
protected: // create from serialization only
	CContactsView();
	DECLARE_DYNCREATE(CContactsView)
public:
	//{{AFX_DATA(CContactsView)
	enum { IDD = IDD_CONTACTS_FORM };
	CContactsSet* m_pSet;
	//}}AFX_DATA
// Attributes
public:
	CContactsDoc* GetDocument();
// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsView)
	public:
	virtual CDaoRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
// Implementation
public:
	virtual ~CContactsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CContactsView)
	afx_msg void OnDetails();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in ContactsView.cpp
inline CContactsDoc* CContactsView::GetDocument()
   { return (CContactsDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_CONTACTSVIEW_H__177C9F16_CC80_420A_BBF1_F3122368B5C7__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


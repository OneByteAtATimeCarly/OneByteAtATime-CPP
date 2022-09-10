//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 17 of 20

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_DETAILSVIEW_H__C607F9E3_A8B7_459E_9B42_BC75F0107A2D__INCLUDED_)
#define AFX_DETAILSVIEW_H__C607F9E3_A8B7_459E_9B42_BC75F0107A2D__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetailsView.h : header file
// ©2004 C. Germany
/////////////////////////////////////////////////////////////////////////////
// DetailsView DAO record view
#include "DetailsSet.h"
class DetailsView : public CDaoRecordView
{
public:
	DetailsView();           
protected:
	DECLARE_DYNCREATE(DetailsView)
// Form Data
public:
	//{{AFX_DATA(DetailsView)
	enum { IDD = IDD_DETAILS_FORM };
	DetailsSet * m_pSet;
	//}}AFX_DATA
// Attributes
public:
// Operations
public:
	BOOL HasDetails();
	DetailsSet* GetRecordset();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DetailsView)
		// NOTE - the ClassWizard will add and remove member functions here.
	public:
	virtual CDaoRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL
// Implementation
protected:
	virtual ~DetailsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	// Generated message map functions
	//{{AFX_MSG(DetailsView)
	afx_msg void OnContacts();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_DETAILSVIEW_H__C607F9E3_A8B7_459E_9B42_BC75F0107A2D__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 16 of 20

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_DETAILSSET_H__FDCDEB6F_6204_4B40_A10C_9A9F77F7D875__INCLUDED_)
#define AFX_DETAILSSET_H__FDCDEB6F_6204_4B40_A10C_9A9F77F7D875__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetailsSet.h : header file
// ©2004 C. Germany
/////////////////////////////////////////////////////////////////////////////
// DetailsSet DAO recordset
class DetailsSet : public CDaoRecordset
{
public:
	long m_DetailIDparam;
	DetailsSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(DetailsSet)
// Field/Param Data
	//{{AFX_FIELD(DetailsSet, CDaoRecordset)
	long	m_InfoID;
	long	m_ContactID;
	CString	m_Birthday;
	CString	m_Anniversary;
	CString	m_Likes;
	CString	m_Dis_likes;
	CString	m_Notes;
	//}}AFX_FIELD
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DetailsSet)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL
// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_DETAILSSET_H__FDCDEB6F_6204_4B40_A10C_9A9F77F7D875__INCLUDED_)
 

//---------------------------------------------------------------------------------------------------------------------------


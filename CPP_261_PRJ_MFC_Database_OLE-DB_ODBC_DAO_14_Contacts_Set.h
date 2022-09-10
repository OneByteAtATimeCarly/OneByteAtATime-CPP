//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 14 of 20

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_CONTACTSSET_H__7C1ECBA6_3D1A_4EAD_82A3_0AB6A8AABCC8__INCLUDED_)
#define AFX_CONTACTSSET_H__7C1ECBA6_3D1A_4EAD_82A3_0AB6A8AABCC8__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CContactsSet : public CDaoRecordset
{
public:
	CContactsSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CContactsSet)
// Field/Param Data
	//{{AFX_FIELD(CContactsSet, CDaoRecordset)
	long	m_ContactID;
	CString	m_First;
	CString	m_Last;
	CString	m_Email;
	CString	m_Street;
	CString	m_City;
	CString	m_State;
	CString	m_Zip;
	CString	m_Country;
	CString	m_HomePhone;
	CString	m_CellPhone;
	CString	m_WorkPhone;
	CString	m_Website;
	//}}AFX_FIELD
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsSet)
	public:
	virtual CString GetDefaultDBName();		// REVIEW:  Get a comment here
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL
// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_CONTACTSSET_H__7C1ECBA6_3D1A_4EAD_82A3_0AB6A8AABCC8__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


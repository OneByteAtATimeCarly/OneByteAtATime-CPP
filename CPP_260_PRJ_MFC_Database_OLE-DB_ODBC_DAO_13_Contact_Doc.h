//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 13 of 20

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_CONTACTSDOC_H__25517788_F5DB_4793_8E3A_66A4635A42C4__INCLUDED_)
#define AFX_CONTACTSDOC_H__25517788_F5DB_4793_8E3A_66A4635A42C4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ContactsSet.h"
#include "DetailsSet.h"	// Added by ClassView
class CContactsDoc : public CDocument
{
protected: // create from serialization only
	CContactsDoc();
	DECLARE_DYNCREATE(CContactsDoc)
// Attributes
public:
	CContactsSet m_contactsSet;
// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL
// Implementation
public:
	DetailsSet m_DetailsSet;
	virtual ~CContactsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CContactsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_CONTACTSDOC_H__25517788_F5DB_4793_8E3A_66A4635A42C4__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


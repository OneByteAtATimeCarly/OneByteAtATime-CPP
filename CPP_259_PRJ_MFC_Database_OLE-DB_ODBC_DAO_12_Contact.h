//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 12 of 20

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_CONTACTS_H__61904F71_FCB1_403C_A9C7_0D49A0F2F59D__INCLUDED_)
#define AFX_CONTACTS_H__61904F71_FCB1_403C_A9C7_0D49A0F2F59D__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CContactsApp:
// See Contacts.cpp for the implementation of this class
//
class CContactsApp : public CWinApp
{
public:
	CContactsApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
// Implementation
	//{{AFX_MSG(CContactsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_CONTACTS_H__61904F71_FCB1_403C_A9C7_0D49A0F2F59D__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


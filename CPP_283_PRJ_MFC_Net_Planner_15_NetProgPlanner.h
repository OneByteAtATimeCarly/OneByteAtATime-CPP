//2006 C. Germany - Network Planner GUI App
//File: 15 of 25

//---------------------------------------------------------------------------------------------------------------------------

// NetProgPlanner.h : main header file for the NetProgPlanner application
//
#if !defined(AFX_NetProgPlanner_H__AD381306_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_NetProgPlanner_H__AD381306_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CNetProgPlannerApp:
// See NetProgPlanner.cpp for the implementation of this class
//
#include "NPconstants.h"
class CNetProgPlannerApp : public CWinApp
{
public:
	CNetProgPlannerApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetProgPlannerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
// Implementation
	//{{AFX_MSG(CNetProgPlannerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_NetProgPlanner_H__AD381306_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


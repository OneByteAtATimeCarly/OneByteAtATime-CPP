//2006 C. Germany - Network Planner GUI App
//File: 12 of 25

//---------------------------------------------------------------------------------------------------------------------------

// TextDialog.cpp : implementation file
//
#include "stdafx.h"
#include "NetProgPlanner.h"
#include "TextDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CTextDialog dialog
CTextDialog::CTextDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTextDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextDialog)
	m_TextString = _T("");
	//}}AFX_DATA_INIT
}
void CTextDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextDialog)
	DDX_Text(pDX, IDC_EDITTEXT, m_TextString);
	DDV_MaxChars(pDX, m_TextString, 100);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CTextDialog, CDialog)
	//{{AFX_MSG_MAP(CTextDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CTextDialog message handlers
 

//---------------------------------------------------------------------------------------------------------------------------


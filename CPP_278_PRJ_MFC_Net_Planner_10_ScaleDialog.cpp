//2006 C. Germany - Network Planner GUI App
//File: 10 of 25

//---------------------------------------------------------------------------------------------------------------------------

// ScaleDialog.cpp : implementation file
//
#include "stdafx.h"
#include "NetProgPlanner.h"
#include "ScaleDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CScaleDialog dialog
CScaleDialog::CScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleDialog)
	NPscale = -1;
	//}}AFX_DATA_INIT
}
void CScaleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleDialog)
	DDX_LBIndex(pDX, IDC_SCALELIST, NPscale);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
	//{{AFX_MSG_MAP(CScaleDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CScaleDialog message handlers
BOOL CScaleDialog::OnInitDialog()
{
   CDialog::OnInitDialog();
   CListBox* pListBox = static_cast<CListBox*>(GetDlgItem(IDC_SCALELIST));
   pListBox->AddString("Scale 1");
   pListBox->AddString("Scale 2");
   pListBox->AddString("Scale 3");
   pListBox->AddString("Scale 4");
   pListBox->AddString("Scale 5");
   pListBox->AddString("Scale 6");
   pListBox->AddString("Scale 7");
   pListBox->AddString("Scale 8");
   pListBox->SetCurSel(NPscale - 1);
     return TRUE;  // return TRUE unless you set the focus to a control
                   // EXCEPTION: OCX Property Pages should return FALSE
}

//---------------------------------------------------------------------------------------------------------------------------


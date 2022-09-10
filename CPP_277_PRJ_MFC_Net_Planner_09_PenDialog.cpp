//2006 C. Germany - Network Planner GUI App
//File: 9 of 25

//---------------------------------------------------------------------------------------------------------------------------

// PenDialog.cpp : implementation file
//
#include "stdafx.h"
#include "NetProgPlanner.h"
#include "PenDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CPenDialog dialog
CPenDialog::CPenDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPenDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPenDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}
void CPenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPenDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CPenDialog, CDialog)
	//{{AFX_MSG_MAP(CPenDialog)
	ON_BN_CLICKED(IDC_PENWIDTH0, OnPenwidth0)
	ON_BN_CLICKED(IDC_PENWIDTH1, OnPenwidth1)
	ON_BN_CLICKED(IDC_PENWIDTH2, OnPenwidth2)
	ON_BN_CLICKED(IDC_PENWIDTH3, OnPenwidth3)
	ON_BN_CLICKED(IDC_PENWIDTH4, OnPenwidth4)
	ON_BN_CLICKED(IDC_PENWIDTH5, OnPenwidth5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CPenDialog message handlers
BOOL CPenDialog::OnInitDialog()
{
   CDialog::OnInitDialog();
   // Check the radio button corresponding to the pen width
   switch(NPpenwidth)
   {
      case 1:
         CheckDlgButton(IDC_PENWIDTH1,1);
         break;
      case 2:
         CheckDlgButton(IDC_PENWIDTH2,1);
         break;
      case 3:
         CheckDlgButton(IDC_PENWIDTH3,1);
         break;
      case 4:
         CheckDlgButton(IDC_PENWIDTH4,1);
         break;
      case 5:
         CheckDlgButton(IDC_PENWIDTH5,1);
         break;
      default:
         CheckDlgButton(IDC_PENWIDTH0,1);
   }
   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}
void CPenDialog::OnPenwidth0() 
{
   NPpenwidth = 0;
}
void CPenDialog::OnPenwidth1() 
{
   NPpenwidth = 1;
}
void CPenDialog::OnPenwidth2() 
{
   NPpenwidth = 2;
}
void CPenDialog::OnPenwidth3() 
{
   NPpenwidth = 3;
}
void CPenDialog::OnPenwidth4() 
{
   NPpenwidth = 4;
}
void CPenDialog::OnPenwidth5() 
{
   NPpenwidth = 5;	
}

//---------------------------------------------------------------------------------------------------------------------------


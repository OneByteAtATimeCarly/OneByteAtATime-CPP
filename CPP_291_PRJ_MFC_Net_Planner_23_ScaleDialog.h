//2006 C. Germany - Network Planner GUI App
//File: 23 of 25

//---------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_SCALEDIALOG_H__AD38131B_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_SCALEDIALOG_H__AD38131B_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScaleDialog.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CScaleDialog dialog
class CScaleDialog : public CDialog
{
// Construction
public:
	CScaleDialog(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CScaleDialog)
	enum { IDD = IDD_SCALE_DLG };
	int		NPscale;
	//}}AFX_DATA
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScaleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CScaleDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_SCALEDIALOG_H__AD38131B_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)

//---------------------------------------------------------------------------------------------------------------------------


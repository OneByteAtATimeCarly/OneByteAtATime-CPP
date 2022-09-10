//2004 C. S. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 6 of 20

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Contacts.h"
#include "ContactsSet.h"
#include "ContactsDoc.h"
#include "ContactsView.h"
#include "ContactConstants.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CContactsView


IMPLEMENT_DYNCREATE(CContactsView, CDaoRecordView)
BEGIN_MESSAGE_MAP(CContactsView, CDaoRecordView)
	//{{AFX_MSG_MAP(CContactsView)
	ON_BN_CLICKED(IDC_DETAILS, OnDetails)
	//}}AFX_MSG_MAP
	// Standard printing commands
 	ON_BN_CLICKED(IDC_DETAILS, OnDetails) 
	ON_COMMAND(ID_FILE_PRINT, CDaoRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CDaoRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CDaoRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CContactsView construction/destruction
CContactsView::CContactsView()
	: CDaoRecordView(CContactsView::IDD)
{
	//{{AFX_DATA_INIT(CContactsView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}
CContactsView::~CContactsView()
{
}
void CContactsView::DoDataExchange(CDataExchange* pDX)
{
	CDaoRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CContactsView)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ContactID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_First, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_Last, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_Email, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_Website, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT6, m_pSet->m_HomePhone, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT7, m_pSet->m_CellPhone, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT8, m_pSet->m_WorkPhone, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT9, m_pSet->m_Street, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT10, m_pSet->m_City, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT11, m_pSet->m_State, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT12, m_pSet->m_Zip, m_pSet);
	//}}AFX_DATA_MAP
}
BOOL CContactsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CDaoRecordView::PreCreateWindow(cs);
}
void CContactsView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_contactsSet;
	//SQL string to sort by when opening Contacts recordset
	m_pSet->m_strSort = "[ContactID]";
	CDaoRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}
/////////////////////////////////////////////////////////////////////////////
// CContactsView printing
BOOL CContactsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}
void CContactsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}
void CContactsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}
/////////////////////////////////////////////////////////////////////////////
// CContactsView diagnostics
#ifdef _DEBUG
void CContactsView::AssertValid() const
{
	CDaoRecordView::AssertValid();
}
void CContactsView::Dump(CDumpContext& dc) const
{
	CDaoRecordView::Dump(dc);
}
CContactsDoc* CContactsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CContactsDoc)));
	return (CContactsDoc*)m_pDocument;
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// CContactsView database support
CDaoRecordset* CContactsView::OnGetRecordset()
{
	return m_pSet;
}
/////////////////////////////////////////////////////////////////////////////
// CContactsView message handlers

void CContactsView::OnDetails() 
{
	((CMainFrame *)GetParentFrame())->SelectView(DETAILS_VIEW);
}

//---------------------------------------------------------------------------------------------------------------------------


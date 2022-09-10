//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 8 of 20

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Contacts.h"
#include "DetailsView.h"
#include "ContactsSet.h"
#include "DetailsSet.h"
#include "ContactsDoc.h"
#include "ContactConstants.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// DetailsView
IMPLEMENT_DYNCREATE(DetailsView, CDaoRecordView)
DetailsView::DetailsView()
	: CDaoRecordView(DetailsView::IDD)
{
	//{{AFX_DATA_INIT(DetailsView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
}
DetailsView::~DetailsView()
{
}
void DetailsView::DoDataExchange(CDataExchange* pDX)
{
	CDaoRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DetailsView)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ContactID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_InfoID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_Birthday, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_Anniversary, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_Likes, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT6, m_pSet->m_Dis_likes, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT7, m_pSet->m_Notes, m_pSet);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(DetailsView, CDaoRecordView)
	//{{AFX_MSG_MAP(DetailsView)
	ON_BN_CLICKED(IDC_CONTACTS, OnContacts)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// DetailsView diagnostics
#ifdef _DEBUG
void DetailsView::AssertValid() const
{
	CDaoRecordView::AssertValid();
}
void DetailsView::Dump(CDumpContext& dc) const
{
	CDaoRecordView::Dump(dc);
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// DetailsView message handlers
CDaoRecordset* DetailsView::OnGetRecordset()
{
	if (m_pSet != NULL)
		return m_pSet;
	m_pSet = new DetailsSet(NULL);
	m_pSet->Open();
	return m_pSet;
}
DetailsSet* DetailsView::GetRecordset()
{
	DetailsSet* pData = (DetailsSet*) OnGetRecordset();
	ASSERT(pData == NULL || pData->IsKindOf(RUNTIME_CLASS(DetailsSet)));
	return pData;
}
void DetailsView::OnInitialUpdate()
{
	BeginWaitCursor();
	CContactsDoc * pDoc = (CContactsDoc *)GetDocument();   // Get doc pointer
    m_pSet = &pDoc->m_DetailsSet;           // Get a pointer to the recordset
   // Use the DB that is open for details recordset
   m_pSet->m_pDatabase = pDoc->m_DetailsSet.m_pDatabase;
   // Set the current product ID as parameter
    m_pSet->m_DetailIDparam = pDoc->m_DetailsSet.m_InfoID;
   // Set the filter as product ID field
   m_pSet->m_strFilter = "[ContactID] = [ContactDetails].[ContactID]";
	GetRecordset();
	
	if (m_pSet->IsOpen())
	{
		CString strTitle = m_pSet->m_pDatabase->GetName();
		CString strTable = m_pSet->GetName();
		if (!strTable.IsEmpty())
			strTitle += _T(":") + strTable;
		GetDocument()->SetTitle(strTitle);
	}
    //Rendering improper number of arguments, commented out
	CDaoRecordView::OnInitialUpdate(); 
	EndWaitCursor();
}

BOOL DetailsView::HasDetails()
{
  CContactsDoc * pDoc = (CContactsDoc*)GetDocument();
  // If the dataset isn't open, we can't help
  if (!m_pSet->IsOpen())
    return FALSE;
  m_pSet->m_DetailIDparam = pDoc->m_DetailsSet.m_InfoID;
  m_pSet->Requery();      // Get data from the DB
  // If we're already at the end, there are no orders here
  if (m_pSet->IsEOF())
    return FALSE;
  else
    return TRUE;
}
void DetailsView::OnContacts() 
{
	((CMainFrame *)GetParentFrame())->SelectView(CONTACTS_VIEW);	
}

//---------------------------------------------------------------------------------------------------------------------------


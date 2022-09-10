//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 7 of 20

//---------------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Contacts.h"
#include "DetailsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DetailsSet

IMPLEMENT_DYNAMIC(DetailsSet, CDaoRecordset)

DetailsSet::DetailsSet(CDaoDatabase* pdb)
: CDaoRecordset(pdb)
{
//{{AFX_FIELD_INIT(DetailsSet)
m_InfoID = 0;
m_ContactID = 0;
m_Birthday = _T("");
m_Anniversary = _T("");
m_Likes = _T("");
m_Dis_likes = _T("");
m_Notes = _T("");
m_nFields = 7;
//}}AFX_FIELD_INIT

m_DetailIDparam = 0L; // Set initial parameter value
m_nParams = 1; // Set number of parameters

m_nDefaultType = dbOpenDynaset;
}


CString DetailsSet::GetDefaultDBName()
{
return _T("contacts.mdb");
}

CString DetailsSet::GetDefaultSQL()
{
return _T("[ContactDetails]");
}

void DetailsSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
//{{AFX_FIELD_MAP(DetailsSet)
pFX->SetFieldType(CDaoFieldExchange::outputColumn);
DFX_Long(pFX, _T("[InfoID]"), m_InfoID);
DFX_Long(pFX, _T("[ContactID]"), m_ContactID);
DFX_Text(pFX, _T("[Birthday]"), m_Birthday);
DFX_Text(pFX, _T("[Anniversary]"), m_Anniversary);
DFX_Text(pFX, _T("[Likes]"), m_Likes);
DFX_Text(pFX, _T("[Dis-likes]"), m_Dis_likes);
DFX_Text(pFX, _T("[Notes]"), m_Notes);
//}}AFX_FIELD_MAP

pFX->SetFieldType(CDaoFieldExchange::param);
DFX_Long(pFX, _T("DetailIDParam"), m_DetailIDparam);
}

/////////////////////////////////////////////////////////////////////////////
// DetailsSet diagnostics

#ifdef _DEBUG
void DetailsSet::AssertValid() const
{
CDaoRecordset::AssertValid();
}

void DetailsSet::Dump(CDumpContext& dc) const
{
CDaoRecordset::Dump(dc);
}
#endif //_DEBUG

//---------------------------------------------------------------------------------------------------------------------------


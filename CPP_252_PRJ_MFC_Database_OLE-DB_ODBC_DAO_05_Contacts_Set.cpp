//2004 C. Germany - Contacts.cpp : Defines the class behaviors for the application
//File: 5 of 20

//---------------------------------------------------------------------------------------------------------------------------

// ©2004 C. Germany - ContactsSet.cpp : implementation of the CContactsSet class

#include "stdafx.h"
#include "Contacts.h"
#include "ContactsSet.h"

//---------------------------------------------------------------------------------------------------------------------------

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CContactsSet implementation
IMPLEMENT_DYNAMIC(CContactsSet, CDaoRecordset)
CContactsSet::CContactsSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CContactsSet)
	m_ContactID = 0;
	m_First = _T("");
	m_Last = _T("");
	m_Email = _T("");
	m_Street = _T("");
	m_City = _T("");
	m_State = _T("");
	m_Zip = _T("");
	m_Country = _T("");
	m_HomePhone = _T("");
	m_CellPhone = _T("");
	m_WorkPhone = _T("");
	m_Website = _T("");
	m_nFields = 13;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}
CString CContactsSet::GetDefaultDBName()
{
	return _T("contacts.mdb");
}
CString CContactsSet::GetDefaultSQL()
{
	return _T("[ContactInfo]");
}
void CContactsSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CContactsSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[ContactID]"), m_ContactID);
	DFX_Text(pFX, _T("[First]"), m_First);
	DFX_Text(pFX, _T("[Last]"), m_Last);
	DFX_Text(pFX, _T("[Email]"), m_Email);
	DFX_Text(pFX, _T("[Street]"), m_Street);
	DFX_Text(pFX, _T("[City]"), m_City);
	DFX_Text(pFX, _T("[State]"), m_State);
	DFX_Text(pFX, _T("[Zip]"), m_Zip);
	DFX_Text(pFX, _T("[Country]"), m_Country);
	DFX_Text(pFX, _T("[HomePhone]"), m_HomePhone);
	DFX_Text(pFX, _T("[CellPhone]"), m_CellPhone);
	DFX_Text(pFX, _T("[WorkPhone]"), m_WorkPhone);
	DFX_Text(pFX, _T("[Website]"), m_Website);
	//}}AFX_FIELD_MAP
}
/////////////////////////////////////////////////////////////////////////////
// CContactsSet diagnostics
#ifdef _DEBUG
void CContactsSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}
void CContactsSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG

//---------------------------------------------------------------------------------------------------------------------------


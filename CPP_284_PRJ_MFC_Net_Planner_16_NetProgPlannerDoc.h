//2006 C. Germany - Network Planner GUI App
//File: 16 of 25

//---------------------------------------------------------------------------------------------------------------------------

// NetProgPlannerDoc.h : interface of the CNetProgPlannerDoc class
//
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_NetProgPlannerDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
#define AFX_NetProgPlannerDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CNetProgPlannerDoc : public CDocument
{
protected: // create from serialization only
	CNetProgPlannerDoc();
	DECLARE_DYNCREATE(CNetProgPlannerDoc)
// Attributes
public:
protected:
	COLORREF NPcolor;        // Current drawing color
	WORD NPelement;          // Current element type
    CTypedPtrList<CObList, Element*> NPelementList;  // Element list
	int NPpenwidth;          // Current pen width
	CSize NPdocsize;         // Document size
// Operations
public:
   WORD GetElementType() const               // Get the element type
   { return NPelement; }
   COLORREF GetElementColor() const          // Get the element color
   { return NPcolor; } 
   void AddElement(Element* pElement)       // Add an element to the list
   { 
	   NPelementList.AddTail(pElement); 
	   SetModifiedFlag();                    // Set the modified flag
   }
   POSITION GetListHeadPosition() const   // Return list head POSITION value
   { return NPelementList.GetHeadPosition(); }
   Element* GetNext(POSITION& aPos) const // Return current element pointer
   { return NPelementList.GetNext(aPos); }
   POSITION GetListTailPosition() const      // Return list tail POSITION value
   { return NPelementList.GetTailPosition(); }
   Element* GetPrev(POSITION& aPos) const   // Return current element pointer
   { return NPelementList.GetPrev(aPos); }
   int GetPenWidth() const                   // Get the current pen width
   { return NPpenwidth; }
   CSize GetDocSize() const
   { return NPdocsize; }                  // Retrieve the document size
   void DeleteElement(Element* pElement);  // Delete an element
   void CNetProgPlannerDoc::SendToBack(Element* pElement);
   CRect GetDocExtent() const ;  // Get the bounding rectangle for the whole document
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetProgPlannerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
// Implementation
public:
	virtual ~CNetProgPlannerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CNetProgPlannerDoc)
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorRed();
	afx_msg void OnColorGray();
	afx_msg void OnColorAqua();
	afx_msg void OnColorYellow();
	afx_msg void OnColorFuschia();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGray(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorAqua(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorYellow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorFuschia(CCmdUI* pCmdUI);
	afx_msg void OnElementCircle();
	afx_msg void OnElementCurve();
	afx_msg void OnElementLine();
	afx_msg void OnElementRectangle();
	afx_msg void OnUpdateElementCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementCurve(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateElementRectangle(CCmdUI* pCmdUI);
	afx_msg void OnPenwidth();
	afx_msg void OnElementText();
	afx_msg void OnUpdateElementText(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_NetProgPlannerDOC_H__AD38130E_1C8F_11D2_99B1_00104B4C84A4__INCLUDED_)
 

//---------------------------------------------------------------------------------------------------------------------------


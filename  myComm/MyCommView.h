// MyCommView.h : interface of the CMyCommView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)
#define AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyCommView : public CFormView
{
protected: // create from serialization only
	CMyCommView();
	DECLARE_DYNCREATE(CMyCommView)

public:
	//{{AFX_DATA(CMyCommView)
	enum { IDD = IDD_MYCOMM_FORM };
	CStatic	m_ctrlComImg;
	//}}AFX_DATA

// Attributes
public:
	CMyCommDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCommView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void RefreshControl();
// Generated message map functions
protected:
	
	//{{AFX_MSG(CMyCommView)
	afx_msg void OnBtopencomm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyCommView.cpp
inline CMyCommDoc* CMyCommView::GetDocument()
   { return (CMyCommDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)

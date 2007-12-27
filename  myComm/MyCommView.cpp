// MyCommView.cpp : implementation of the CMyCommView class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MyCommDoc.h"
#include "MyCommView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCommView

IMPLEMENT_DYNCREATE(CMyCommView, CFormView)

BEGIN_MESSAGE_MAP(CMyCommView, CFormView)
	//{{AFX_MSG_MAP(CMyCommView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommView construction/destruction

CMyCommView::CMyCommView()
	: CFormView(CMyCommView::IDD)
{
	//{{AFX_DATA_INIT(CMyCommView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMyCommView::~CMyCommView()
{
}

void CMyCommView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyCommView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMyCommView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMyCommView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMyCommView diagnostics

#ifdef _DEBUG
void CMyCommView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyCommView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMyCommDoc* CMyCommView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCommDoc)));
	return (CMyCommDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCommView message handlers

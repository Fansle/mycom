/*
*	myCom App 
*   Http://mycom.googlecode.com
*  
*   author: mrlong date:2007-12-22
*	
*   createdate: 2007-12-21
*	last modification date 2007-12-22
*	
*   update:
*  
*
*/

// MyCom.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyCom.h"
#include "MyComDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyComApp

BEGIN_MESSAGE_MAP(CMyComApp, CWinApp)
	//{{AFX_MSG_MAP(CMyComApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyComApp construction

CMyComApp::CMyComApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyComApp object

CMyComApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyComApp initialization

BOOL CMyComApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMyComDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();  //µ¯³ö´°¿Ú
	
	return FALSE;
}

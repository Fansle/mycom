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

// MyCom.h : main header file for the MYCOM application
//

#if !defined(AFX_MYCOM_H__1EE798C9_1966_4181_9B0A_130D09700D45__INCLUDED_)
#define AFX_MYCOM_H__1EE798C9_1966_4181_9B0A_130D09700D45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyComApp:
// See MyCom.cpp for the implementation of this class
//

class CMyComApp : public CWinApp
{
public:
	CMyComApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyComApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyComApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOM_H__1EE798C9_1966_4181_9B0A_130D09700D45__INCLUDED_)

/*
*	myCom App 
*   Http://mycom.googlecode.com
*
*   Main Dlg
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

// MyComDlg.h : header file
//

#if !defined(AFX_MYCOMDLG_H__12B7739A_C2C8_40FD_BBD4_117ACCBEE5A0__INCLUDED_)
#define AFX_MYCOMDLG_H__12B7739A_C2C8_40FD_BBD4_117ACCBEE5A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SerialPort.h"

/////////////////////////////////////////////////////////////////////////////
// CMyComDlg dialog

class CMyComDlg : public CDialog
{
// Construction
public:
	CMyComDlg(CWnd* pParent = NULL);	// standard constructor
	
	CSerialPort ComPort;  //串口类

	/*参数*/
	//int m_Port     ;  //串口
	//int m_BaudRate ;  //波特率
	//int m_DataBits ;  //数据位
	//int m_Parity   ;  //校验位
	//int m_StopBits ;  //停止位


// Dialog Data
	//{{AFX_DATA(CMyComDlg)
	enum { IDD = IDD_MYCOM_DIALOG };
	//}}AFX_DATA



// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyComDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCancelMode();
	afx_msg void OnBtOpenCom();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMDLG_H__12B7739A_C2C8_40FD_BBD4_117ACCBEE5A0__INCLUDED_)

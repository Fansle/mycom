/*
*	myCom App 
*   Http://mycom.googlecode.com
*
*   About Dlg
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

// MyComDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyComDlg dialog

CMyComDlg::CMyComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyComDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyComDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


BEGIN_MESSAGE_MAP(CMyComDlg, CDialog)
	//{{AFX_MSG_MAP(CMyComDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTOPENCOM, OnBtOpenCom)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyComDlg message handlers

BOOL CMyComDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		//网址
		CString strWeb;
		strWeb.LoadString(IDS_WEB);
		if (!strWeb.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_STRING, IDM_WEB, strWeb);
		}

	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	WINDOWPLACEMENT   WndStatus;  
    CRect   rect;  
	int nCmdShow;
    rect.left     = AfxGetApp()->GetProfileInt("WNDSTATUS","LEFT",100);  
	rect.top      = AfxGetApp()->GetProfileInt("WNDSTATUS","TOP",100);  
	rect.right    = AfxGetApp()->GetProfileInt("WNDSTATUS","RIGHT",500);  
	rect.bottom   = AfxGetApp()->GetProfileInt("WNDSTATUS","BOTTOM",400);  
	WndStatus.rcNormalPosition   =   rect;  
	WndStatus.flags=   AfxGetApp()->GetProfileInt("WNDSTATUS","FLAG",0);  
	nCmdShow   =   AfxGetApp()->GetProfileInt("WNDSTATUS","SHOWCMD",SW_SHOW);  
	WndStatus.showCmd   =   nCmdShow;  
	WndStatus.ptMinPosition   =   CPoint(0,0);  
	SetWindowPlacement(&WndStatus);  
	
	m_ComAction = FALSE;
	RefreshControl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyComDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 0xFFF0) == IDM_WEB)
	{
		MessageBox("web");
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyComDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	/*	CWnd * pWnd = GetDlgItem(IDC_BTOPENCOM);
		CDC * pDC = pWnd->GetDC();
		pWnd->Invalidate();
		pWnd->UpdateWindow();
		pDC->SelectStockObject(BLACK_BRUSH);
		pDC->Rectangle(0,0,10,10);
		pWnd->ReleaseDC(pDC);
	*/

		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyComDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyComDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CButton * myB = (CButton * )GetDlgItem(IDC_BTSEND);
}


void CMyComDlg::OnBtOpenCom() 
{
	// TODO: Add your control notification handler code here
	// open com or close com

	if (m_ComAction)
	{
		CBitmap myBitmap;
		myBitmap.LoadBitmap(IDB_BITMAPOPEN);
		//m_ComPort.KillThreadClosePort();
		//m_ComPort.StopMonitoring();
		m_ComPort.ClosePort();
		CButton * myb = ((CButton *)this->GetDlgItem(IDC_BTOPENCOM));
	    myb->SetWindowText(_T("打开串口"));
		m_ComAction = FALSE;
	}
	else {
		CBitmap myBitmap;
		myBitmap.LoadBitmap(IDB_BITMAPOPEN);
		CStatic * myPic = (CStatic *)GetDlgItem(IDC_STATIC);
		myPic->SetBitmap(myBitmap);
		m_ComPort.InitPort(this,1,57600,'N',8,1);
		m_ComPort.StartMonitoring();
		CButton * myb = ((CButton *)GetDlgItem(IDC_BTOPENCOM));
	    myb->SetWindowText(_T("关闭串口"));
		m_ComAction = TRUE;

	}
	RefreshControl();
}

void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//CDialog::OnLButtonDown(nFlags, point);
	CString myURL = "http://mycom.googlecode.com";
	ShellExecute(NULL, _T("open"), myURL.operator LPCTSTR(), NULL, NULL, 2); // open web
}



void CMyComDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	WINDOWPLACEMENT   WndStatus;  
	GetWindowPlacement(&WndStatus);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","FLAG",WndStatus.flags);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","SHOWCMD",WndStatus.showCmd);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","LEFT",WndStatus.rcNormalPosition.left);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","RIGHT",WndStatus.rcNormalPosition.right);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","TOP",WndStatus.rcNormalPosition.top);  
	AfxGetApp()->WriteProfileInt("WNDSTATUS","BOTTOM",WndStatus.rcNormalPosition.bottom);  
  
	CDialog::OnClose();
}

void CMyComDlg::RefreshControl(void)
{
	// send botton
	GetDlgItem(IDC_BTSEND)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_A)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_B)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_C)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_D)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_E)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_F)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_G)->EnableWindow(m_ComAction);
	GetDlgItem(IDC_BTCOMMAND_H)->EnableWindow(m_ComAction);

	// com param
	GetDlgItem(IDC_CBCOM)->EnableWindow(!m_ComAction);
	GetDlgItem(IDC_CBBaud)->EnableWindow(!m_ComAction);
    //GetDlgItem(IDC_STATICCOMIMG)->VisielbWindow(!m_ComAction);
}

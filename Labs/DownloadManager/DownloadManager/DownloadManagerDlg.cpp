
// DownloadManagerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DownloadManager.h"
#include "DownloadManagerDlg.h"
#include "afxdialogex.h"
#include "wininet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_UPDATE_PROGRESS (WM_USER+1)

struct DownloadParams {
	CDownloadManagerDlg* pDlg;
	CString url;
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDownloadManagerDlg dialog

UINT DownloadFileThread(LPVOID pParam) {
	auto* pParams = (DownloadParams*)pParam;
	CDownloadManagerDlg* pDlg = pParams->pDlg;

	if (!pParams || !pParams->pDlg) {
		return 0;  // Null check to prevent crashes
	}
	CString url = pParams->url;
	delete pParams;  // Ensure memory is cleaned up properly

	if (!::IsWindow(pDlg->GetSafeHwnd())) {
		return 0;  // Dialog is already destroyed, exit thread safely
	}

	int pos = url.ReverseFind('/');
	CString fileName = url.Mid(pos + 1);

	HINTERNET hInternet = InternetOpen(L"DownloadManager", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (!hInternet) {
		AfxMessageBox(L"Failed to initialize WinINet.");
		return 0;
	}

	HINTERNET hFile = InternetOpenUrl(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (!hFile) {
		AfxMessageBox(L"Failed to open URL.");
		InternetCloseHandle(hInternet);
		return 0;
	}

	HANDLE hOutputFile = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOutputFile == INVALID_HANDLE_VALUE) {
		AfxMessageBox(L"Failed to create file.");
		InternetCloseHandle(hFile);
		InternetCloseHandle(hInternet);
		return 0;
	}

	char buffer[4096];
	DWORD bytesRead = 0, bytesWritten = 0, totalRead = 0, filesize = 0;
	DWORD sizelen = sizeof(filesize);
	HttpQueryInfo(hFile, HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER, &filesize, &sizelen, NULL);

	while (InternetReadFile(hFile, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		WriteFile(hOutputFile, buffer, bytesRead, &bytesWritten, NULL);
		totalRead += bytesRead;
		int Progress = (int)((totalRead * 100) / filesize);

		if (::IsWindow(pDlg->GetSafeHwnd())) {
			pDlg->PostMessage(WM_UPDATE_PROGRESS, Progress, 0);
		}
		else {
			break;  // Dialog was destroyed, stop the thread safely
		}
	}

	CloseHandle(hOutputFile);
	InternetCloseHandle(hFile);
	InternetCloseHandle(hInternet);

	if (::IsWindow(pDlg->GetSafeHwnd())) {
		AfxMessageBox(L"Download Completed: " + fileName);
	}

	return 0;
}




CDownloadManagerDlg::CDownloadManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DOWNLOADMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDownloadManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDownloadManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CDownloadManagerDlg::OnClickedStart)
	ON_MESSAGE(WM_UPDATE_PROGRESS, &CDownloadManagerDlg::OnUpdateProgress)
END_MESSAGE_MAP()


// CDownloadManagerDlg message handlers

BOOL CDownloadManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_progressBar.SubclassDlgItem(IDC_PROGRESS_BAR,this);
	m_progressBar.SetRange(0, 100);
	m_progressBar.SetPos(0);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDownloadManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDownloadManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDownloadManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDownloadManagerDlg::OnClickedStart()
{
	CString url;
	GetDlgItemText(IDC_URL, url);
	if (!url.IsEmpty()) {
		DownloadParams* pParams = new DownloadParams{ this, url };
		AfxBeginThread(DownloadFileThread, pParams);
	}
}
LRESULT  CDownloadManagerDlg::OnUpdateProgress(WPARAM wParam, LPARAM lParam)
{
	int progress = (int)wParam;
	m_progressBar.SetPos(progress);

	//CString progressText;
	//progressText.Format(L"%d%%",progress);
	//m_progressText.SetWindowText(progressText);
	return 0;
}



// DownloadManagerDlg.h : header file
//

#pragma once


// CDownloadManagerDlg dialog
class CDownloadManagerDlg : public CDialogEx
{
// Construction
public:
	CDownloadManagerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOWNLOADMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedStart();
	afx_msg LRESULT OnUpdateProgress(WPARAM wParam,LPARAM lParam);
private:
	CProgressCtrl m_progressBar;
	CStatic m_progressText;
};

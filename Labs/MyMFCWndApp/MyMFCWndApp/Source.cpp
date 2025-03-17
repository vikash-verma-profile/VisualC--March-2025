#include "afxwin.h"

class MyMFCWindow :public CFrameWnd {
public:
    void CreateMyMFCWindow() {
        Create(NULL, _T("Sample Title"), WS_OVERLAPPEDWINDOW);
        ShowWindow(SW_SHOW);
    }
};
class MyMFCApp :public CWinApp {
    public:
         virtual INT InitInstance(){
            MyMFCWindow* pFrameWnd=new MyMFCWindow();
            m_pMainWnd=pFrameWnd;
            pFrameWnd->CreateMyMFCWindow();
            return TRUE;
         }
};

MyMFCApp theApp;

// CContentDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCTreeCtrl.h"
#include "CContentDlg.h"
#include "afxdialogex.h"


// CContentDlg 对话框

IMPLEMENT_DYNAMIC(CContentDlg, CDialogEx)

CContentDlg::CContentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONTENT, pParent)
{

}

CContentDlg::~CContentDlg()
{
}

void CContentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_content);
}


BEGIN_MESSAGE_MAP(CContentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CContentDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CContentDlg::OnBnClickedCancel)
	ON_WM_SHOWWINDOW()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CContentDlg 消息处理程序


void CContentDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CContentDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CContentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CContentDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	m_content.SetWindowText(_T(""));
	m_content.SetWindowText(m_data);
}


void CContentDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_content.GetSafeHwnd())
		m_content.MoveWindow(0, 0, cx, cy, TRUE);
}

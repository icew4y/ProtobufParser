
// MFCTreeCtrlDlg.h: 头文件
//

#pragma once

#include "CContentDlg.h"
#include "CParserDlg.h"
// CMFCTreeCtrlDlg 对话框
class CMFCTreeCtrlDlg : public CDialogEx
{
// 构造
public:
	CMFCTreeCtrlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTREECTRL_DIALOG };
#endif

	std::string& GetTemp_data() { return temp_data; }
	void SetTemp_data(std::string& val) { temp_data = val; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void PrintUnknownFields(const UnknownFieldSet& unknown_fields, HTREEITEM parent);
	CTreeCtrl m_tree;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	
	CParserDlg  parserdlg;
	std::string temp_data;
};


// MFCTreeCtrlDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCTreeCtrl.h"
#include "MFCTreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCTreeCtrlDlg 对话框



CMFCTreeCtrlDlg::CMFCTreeCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTREECTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}

BEGIN_MESSAGE_MAP(CMFCTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCTreeCtrlDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCTreeCtrlDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCTreeCtrlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCTreeCtrlDlg 消息处理程序

BOOL CMFCTreeCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tree.ModifyStyle(NULL, TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTreeCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTreeCtrlDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCTreeCtrlDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

LPWSTR asc_to_wide(const char* str)
{
	LPWSTR wstr;
	int len_0, sz;
	if (!str)
		return NULL;
	len_0 = strlen(str) + 1;
	sz = MultiByteToWideChar(CP_ACP, 0, str, len_0, NULL, 0);
	if (!sz) {
		return NULL;
	}
	wstr = (LPWSTR)malloc(sz * sizeof(wchar_t));
	if (!wstr) {
		return NULL;
	}
	if (!MultiByteToWideChar(CP_ACP, 0, str, len_0, wstr, sz)) {
		free(wstr);
		return NULL;
	}
	return wstr;
}


char *wide_to_asc(LPCWSTR wstr)
{
	char *str;
	int len_0, sz;

	if (!wstr)
		return NULL;
	len_0 = (int)wcslen(wstr) + 1; /* WideCharToMultiByte expects int */
	sz = WideCharToMultiByte(CP_ACP, 0, wstr, len_0, NULL, 0, NULL, NULL);
	if (!sz) {
		return NULL;
	}
	str = (char *)malloc(sz);
	if (!str) {
		return NULL;
	}
	if (!WideCharToMultiByte(CP_ACP, 0, wstr, len_0, str, sz, NULL, NULL)) {
		free(str);
		return NULL;
	}
	return str;
}


std::string _w2a(const wchar_t *w)
{
	std::string str;
	char *astr = wide_to_asc(w);
	if (astr) {
		str = astr;
		free(astr);
	}
	return str;
}

std::wstring _a2w(const char *a)
{
	std::wstring wstr;
	wchar_t *w = asc_to_wide(a);
	if (w) {
		wstr = w;
		free(w);
	}
	return wstr;
}

void HexToStr(unsigned char *pbDest, unsigned char *pbSrc, int nLen)
{
	char    ddl, ddh;
	int i;

	for (i = 0; i < nLen; i++)
	{
		ddh = 48 + pbSrc[i] / 16;
		ddl = 48 + pbSrc[i] % 16;
		if (ddh > 57) ddh = ddh + 7;
		if (ddl > 57) ddl = ddl + 7;
		pbDest[i * 2] = ddh;
		pbDest[i * 2 + 1] = ddl;
	}

	pbDest[nLen * 2] = '\0';
}

void StrToHex(char *pbDest, char *pbSrc, int nLen)
{
	char h1, h2;
	char s1, s2;
	int i;

	for (i = 0; i < nLen; i++)
	{
		h1 = pbSrc[2 * i];
		h2 = pbSrc[2 * i + 1];

		s1 = toupper(h1) - 0x30;
		if (s1 > 9)
			s1 -= 7;

		s2 = toupper(h2) - 0x30;
		if (s2 > 9)
			s2 -= 7;

		pbDest[i] = s1 * 16 + s2;
	}
}




void CMFCTreeCtrlDlg::PrintUnknownFields(
	const UnknownFieldSet& unknown_fields, HTREEITEM parent) {
	for (int i = 0; i < unknown_fields.field_count(); i++) {
		const UnknownField& field = unknown_fields.field(i);
		string field_number = SimpleItoa(field.number());

		switch (field.type()) {
		case UnknownField::TYPE_VARINT: {
			HTREEITEM hCurItem = m_tree.InsertItem(_a2w(std::string("(" + field_number + ")" + "VARINT").c_str()).c_str(), parent);
			hCurItem = m_tree.InsertItem(_a2w(SimpleItoa(field.varint()).c_str()).c_str(), hCurItem);
			break;
		}
		case UnknownField::TYPE_FIXED32: {
			HTREEITEM hCurItem = m_tree.InsertItem(_a2w(std::string("(" + field_number + ")" + "FIXED32").c_str()).c_str(), parent);
			hCurItem = m_tree.InsertItem(_a2w(SimpleItoa(field.fixed32()).c_str()).c_str(), hCurItem);
			break;
		}
		case UnknownField::TYPE_FIXED64: {
			HTREEITEM hCurItem = m_tree.InsertItem(_a2w(std::string("(" + field_number + ")" + "FIXED64").c_str()).c_str(), parent);
			hCurItem = m_tree.InsertItem(_a2w(SimpleItoa(field.fixed64()).c_str()).c_str(), hCurItem);
			break;
		}
		case UnknownField::TYPE_LENGTH_DELIMITED: {
			const string& value = field.length_delimited();
			UnknownFieldSet embedded_unknown_fields;

			HTREEITEM hCurItem = m_tree.InsertItem(_a2w(std::string("(" + field_number + ")" + "LENGTH_DELIMITED" + "(length: " + std::to_string(value.length()) + ")").c_str()).c_str(), parent);
			
			if (!value.empty() && embedded_unknown_fields.ParseFromString(value)) {

				PrintUnknownFields(embedded_unknown_fields, hCurItem);

			}
			else {
				// This field is not parseable as a Message.
				// So it is probably just a plain string.

				int len = value.length() * 2 + 1;
				std::shared_ptr<char> hexstr = std::shared_ptr<char>(new char[len], [](char *p) { delete[]p; });
				memset(hexstr.get(), 0, len);

				HexToStr((unsigned char *)hexstr.get(), (unsigned char *)value.c_str(), value.length());
				hCurItem = m_tree.InsertItem(_a2w( (std::string((const char *)hexstr.get()) + "(" + value + ")").c_str() ).c_str(), hCurItem);
			
			}
			break;
		}
		case UnknownField::TYPE_GROUP: {
			const string& value = field.length_delimited();
			UnknownFieldSet embedded_unknown_fields;

			HTREEITEM hCurItem = m_tree.InsertItem(_a2w(std::string("(" + field_number + ")" + "TYPE_GROUP").c_str()).c_str(), parent);

			if (!value.empty() && embedded_unknown_fields.ParseFromString(value)) {

				PrintUnknownFields(embedded_unknown_fields, hCurItem);

			}
			break;
		}
		}
	}
}

void ExpandAllNode(HTREEITEM hItem, CTreeCtrl& m_treeShow) {

	HTREEITEM hChild = m_treeShow.GetChildItem(hItem); //获得第一个子节点

	while (hChild) {

		m_treeShow.Expand(hItem, TVE_EXPAND); //展开当前节点

		ExpandAllNode(hChild, m_treeShow); //递归展开第一个子节点下所有节点

		hChild = m_treeShow.GetNextSiblingItem(hChild); //获得第二个子节点

	}

}

void CMFCTreeCtrlDlg::OnBnClickedButton1()
{
	HTREEITEM root = m_tree.InsertItem(_T("ROOT"));
	std::string filename = ".\\2.bin";
	std::ifstream infile(filename, std::ios::binary);
	if (infile.is_open()) {
		infile.seekg(0, ios_base::end);
		int len = infile.tellg();
		char *buffer = new char[len];
		infile.seekg(0, ios_base::beg);
		infile.read(buffer, len);
		infile.close();

		UnknownFieldSet unknown_fields;
		if (unknown_fields.ParseFromString(std::string((const char *)buffer, len))) {
			
			PrintUnknownFields(unknown_fields, root);
		}
	}
	ExpandAllNode(root, m_tree);
}

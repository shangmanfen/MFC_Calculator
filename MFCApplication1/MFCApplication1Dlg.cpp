
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region 系统自行生成
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::Add)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::Equal)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::subtract)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::Multiply)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::Divide)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::Empty)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication1Dlg::Delete)
END_MESSAGE_MAP()

CEdit* EditControl; CButton *Button1, *Button2;
// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	EditControl = (CEdit*)GetDlgItem(IDC_EDIT1);
	Button1 = (CButton*)GetDlgItem(IDC_BUTTON1);
	Button2 = (CButton*)GetDlgItem(IDC_BUTTON2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
#pragma endregion
CString control, control2;
#pragma region 输入0123456789
void fuzhi(CString a) {
	EditControl->GetWindowTextW(control);
	control += a;
	control2 += a;
	EditControl->SetWindowTextW(control);
}
void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("0"));
}
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("1"));
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("2"));
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("3"));
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("4"));
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("5"));
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("6"));
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("7"));
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("8"));
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	fuzhi(_T("9"));
}

#pragma endregion

#pragma region +-*/
double a, b; int add = 0, sub = 0, mult = 0, divide = 0;
void init() {
	add = 0;
	sub = 0;
	mult = 0;
	divide = 0;
	control2 = "";
	a = 0; b = 0;
}

void CMFCApplication1Dlg::Add()
{
	// TODO: 在此添加控件通知处理程序代码
	EditControl->GetWindowTextW(control);
	try
	{
		if (control2 != "") {
			add = 1, sub = 0, mult = 0, divide = 0;
			a = _wtof(control2.GetBuffer(0));
			control += "  +  ";
			EditControl->SetWindowTextW(control);
			control2 = "";
		}
	}
	catch (_com_error &e)
	{
		MessageBox(_T("请先输入数字！"));
		MessageBox(e.Description(), NULL, NULL);
	}
}


void CMFCApplication1Dlg::subtract()
{
	// TODO: 在此添加控件通知处理程序代码
	EditControl->GetWindowTextW(control);
	try
	{
		if (control2 != "") {
			add = 0, sub = 1, mult = 0, divide = 0;
			a = _wtof(control2.GetBuffer(0));
			control += "  -  ";
			EditControl->SetWindowTextW(control);
			control2 = "";
		}
	}
	catch (_com_error &e)
	{
		MessageBox(_T("请先输入数字！"));
		MessageBox(e.Description(), NULL, NULL);
	}
}



void CMFCApplication1Dlg::Multiply()
{
	// TODO: 在此添加控件通知处理程序代码
	EditControl->GetWindowTextW(control);
	try
	{
		if (control2 != "") {
			add = 0, sub = 0, mult = 1, divide = 0;
			a = _wtof(control2.GetBuffer(0));
			control += "  *  ";
			EditControl->SetWindowTextW(control);
			control2 = "";
		}
	}
	catch (_com_error &e)
	{
		MessageBox(_T("请先输入数字！"));
		MessageBox(e.Description(), NULL, NULL);
	}
}


void CMFCApplication1Dlg::Divide()
{
	// TODO: 在此添加控件通知处理程序代码
	EditControl->GetWindowTextW(control);
	try
	{
		if (control2 != "") {
			add = 0, sub = 0, mult = 0, divide = 1;
			a = _wtof(control2.GetBuffer(0));
			control += "  /  ";
			EditControl->SetWindowTextW(control);
			control2 = "";
		}
	}
	catch (_com_error &e)
	{
		MessageBox(_T("请先输入数字！"));
		MessageBox(e.Description(), NULL, NULL);
	}
}
#pragma endregion

#pragma region  等于
double result;
void CMFCApplication1Dlg::Equal()
{
	// TODO: 在此添加控件通知处理程序代码
	b = _wtof(control2.GetBuffer(0));
	if (add == 1)
		result = a + b;
	else if (sub == 1)
		result = a - b;
	else if (mult == 1)
		result = a * b;
	else if (divide == 1)
		result = a / b;
	CString str;
	str.Format(_T("%lf"), result);
	init();
	control += "  =\r\n"; control += str; control += "\r\n";
	EditControl->SetWindowTextW(control);
}
#pragma endregion

#pragma region 清空

void CMFCApplication1Dlg::Empty()
{
	// TODO: 在此添加控件通知处理程序代码
	init();
	control = "";
	result = 0;
	EditControl->SetWindowTextW(control);
}
#pragma endregion

#pragma region Delete
void CMFCApplication1Dlg::Delete()
{
	// TODO: 在此添加控件通知处理程序代码
	int a = control.GetLength();
	control = control.Left(a-1);
	a = control2.GetLength();
	control2 = control2.Left(a - 1);
	EditControl->SetWindowTextW(control);
}
#pragma endregion
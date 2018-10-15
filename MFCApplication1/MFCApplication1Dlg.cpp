
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region ϵͳ��������
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



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
// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	EditControl = (CEdit*)GetDlgItem(IDC_EDIT1);
	Button1 = (CButton*)GetDlgItem(IDC_BUTTON1);
	Button2 = (CButton*)GetDlgItem(IDC_BUTTON2);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
#pragma endregion
CString control, control2;
#pragma region ����0123456789
void fuzhi(CString a) {
	EditControl->GetWindowTextW(control);
	control += a;
	control2 += a;
	EditControl->SetWindowTextW(control);
}
void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("0"));
}
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("1"));
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("2"));
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("3"));
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("4"));
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("5"));
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("6"));
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("7"));
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fuzhi(_T("8"));
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�����������֣�"));
		MessageBox(e.Description(), NULL, NULL);
	}
}


void CMFCApplication1Dlg::subtract()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�����������֣�"));
		MessageBox(e.Description(), NULL, NULL);
	}
}



void CMFCApplication1Dlg::Multiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�����������֣�"));
		MessageBox(e.Description(), NULL, NULL);
	}
}


void CMFCApplication1Dlg::Divide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�����������֣�"));
		MessageBox(e.Description(), NULL, NULL);
	}
}
#pragma endregion

#pragma region  ����
double result;
void CMFCApplication1Dlg::Equal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

#pragma region ���

void CMFCApplication1Dlg::Empty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	init();
	control = "";
	result = 0;
	EditControl->SetWindowTextW(control);
}
#pragma endregion

#pragma region Delete
void CMFCApplication1Dlg::Delete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int a = control.GetLength();
	control = control.Left(a-1);
	a = control2.GetLength();
	control2 = control2.Left(a - 1);
	EditControl->SetWindowTextW(control);
}
#pragma endregion
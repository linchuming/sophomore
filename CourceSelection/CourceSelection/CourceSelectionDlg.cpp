
// CourceSelectionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CourceSelection.h"
#include "CourceSelectionDlg.h"
#include "afxdialogex.h"
#include "xkDlg.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCourceSelectionDlg 对话框



CCourceSelectionDlg::CCourceSelectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCourceSelectionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCourceSelectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_ie);
}

BEGIN_MESSAGE_MAP(CCourceSelectionDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCourceSelectionDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCourceSelectionDlg 消息处理程序

BOOL CCourceSelectionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_ie.Navigate(L"http://xk.fudan.edu.cn",NULL,NULL,NULL,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCourceSelectionDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCourceSelectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCourceSelectionDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	string html = GetHtmlSource(L"http://xk.fudan.edu.cn/xk/input.jsp");
	int isok = html.find("13300240020");
	if(isok==-1)
	{
		MessageBox(L"无效操作或学号错误！");
		return;
	}
	this->ShowWindow(SW_HIDE);
	xkDlg * xk = new xkDlg;
	xk->Create(IDD_DIALOG1);
	xk->ShowWindow(SW_SHOW);
	
}

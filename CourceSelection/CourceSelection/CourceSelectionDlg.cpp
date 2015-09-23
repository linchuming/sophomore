
// CourceSelectionDlg.cpp : ʵ���ļ�
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


// CCourceSelectionDlg �Ի���



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


// CCourceSelectionDlg ��Ϣ�������

BOOL CCourceSelectionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_ie.Navigate(L"http://xk.fudan.edu.cn",NULL,NULL,NULL,NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCourceSelectionDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCourceSelectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCourceSelectionDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	string html = GetHtmlSource(L"http://xk.fudan.edu.cn/xk/input.jsp");
	int isok = html.find("13300240020");
	if(isok==-1)
	{
		MessageBox(L"��Ч������ѧ�Ŵ���");
		return;
	}
	this->ShowWindow(SW_HIDE);
	xkDlg * xk = new xkDlg;
	xk->Create(IDD_DIALOG1);
	xk->ShowWindow(SW_SHOW);
	
}

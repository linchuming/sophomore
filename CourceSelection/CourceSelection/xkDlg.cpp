// xkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CourceSelection.h"
#include "xkDlg.h"
#include "afxdialogex.h"
#include "afxinet.h"

CString url;
CStringA course;
string Htmltemp , Htmltemp2;
int n1,n2;

DWORD WINAPI ThreadProc(LPVOID pParam);

// xkDlg 对话框

IMPLEMENT_DYNAMIC(xkDlg, CDialog)

xkDlg::xkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(xkDlg::IDD, pParent)
	, m_course(_T(""))
	, m_time(0)
	, m_n1(0)
	, m_n2(0)
{

}

xkDlg::~xkDlg()
{
}

void xkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_xk);
	DDX_Text(pDX, IDC_EDIT1, m_course);
	DDX_Text(pDX, IDC_EDIT3, m_time);
	DDX_Control(pDX, IDC_BUTTON2, m_bt2);
	DDX_Text(pDX, IDC_EDIT4, m_n1);
	DDX_Text(pDX, IDC_EDIT5, m_n2);
}


BEGIN_MESSAGE_MAP(xkDlg, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &xkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &xkDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &xkDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// xkDlg 消息处理程序


BOOL xkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_xk.Navigate(L"http://xk.fudan.edu.cn/xk/home.html",NULL,NULL,NULL,NULL);
	m_time = 1;
	UpdateData(false);
	return true;
}

void FindString(string str){
	int i;
	int l=str.length();
	int z1=str.find(course.GetBuffer(0));
	if (z1==-1) return;
	//for(i=0;i<=30;i++) s1[i]=str[z1+i]; s1[i+1]='\0';
    int z2=str.find("style1",z1);
	z2=str.find("style1",z2+10);
	z2=str.find("style1",z2+10);
	z2+=9;
	//for(i=0;i<=5;i++) s1[i]=str[z2+9+i]; s1[i+1]='\0';
	i=0;
	while(str[z2]>='0'&&str[z2]<='9') 
		{
			n1=n1*10+str[z2]-'0';
			z2++;
			//s1[i++]=str[z2++];
	}
	//s1[i]='\0';
	int z3=str.find("style1",z2);
	z3+=9;
	i=0;
	while(str[z3]>='0'&&str[z3]<='9') 
		{
			n2=n2*10+str[z3]-'0';
			z3++;
			//s2[i++]=str[z3++];
	}
	//s2[i]='\0';

}

void xkDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nIDEvent)
	{
	case 1:
		Htmltemp = GetHtmlSource(url);
		//AfxBeginThread((AFX_THREADPROC)ThreadProc,NULL,THREAD_PRIORITY_NORMAL,0,0,NULL);
		break;
	case 2:
		//char s1[100],s2[100];
		n1=0; n2=0;
		FindString(Htmltemp);

		m_n1 = n1;
		m_n2 = n2;
		UpdateData(false);

		if(n1-n2>0)
		{
			m_xk.Navigate(_T("javascript:window.frames['leftFrame'].submitchoice();"),NULL,NULL,NULL,NULL);
			KillTimer(2);
			KillTimer(1);
			m_bt2.EnableWindow(false);
		}
		break;
	case 3:
		Htmltemp2 = GetHtmlSource(url);
		break;
	case 4:
		//char s3[100],s4[100];
		n1=0; n2=0;
		FindString(Htmltemp2);

		m_n1 = n1;
		m_n2 = n2;
		UpdateData(false);

		if(n1-n2>0)
		{
			KillTimer(2);
			KillTimer(1);
			m_xk.Navigate(_T("javascript:window.frames['leftFrame'].submitchoice();"),NULL,NULL,NULL,NULL);

			m_bt2.EnableWindow(false);
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}


void xkDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_time<=0)
	{
		MessageBox(L"设置非法！");
		return;
	}
	m_bt2.EnableWindow(true);
	m_course.Replace(' ',NULL);
	course=m_course.GetBuffer(0);
	url=_T("http://xk.fudan.edu.cn/xk/sekcoursepeos.jsp?xkh=")+m_course;
	SetTimer(1,m_time,NULL);
	//SetTimer(3,m_time,NULL);
	Htmltemp = "";
	SetTimer(2,1,NULL);
	//SetTimer(4,5,NULL);
}


void xkDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_course.Replace(' ',NULL);
	course=m_course.GetBuffer(0);
	url=_T("http://xk.fudan.edu.cn/xk/sekcoursepeos.jsp?xkh=")+m_course;

	Htmltemp = GetHtmlSource(url);

	n1=0; n2=0;
	FindString(Htmltemp);

	m_n1 = n1;
	m_n2 = n2;
	UpdateData(false);
}


void xkDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bt2.EnableWindow(false);
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
}


void xkDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialog::OnClose();
}

string GetHtmlSource(CString strURL)
{
	CInternetSession session;
	CHttpFile *file = NULL; 

	CString strHtml = _T(""); //存放网页数据
	file =(CHttpFile*)session.OpenURL(strURL,1,INTERNET_FLAG_RELOAD);
 
	//CString strLine;
	char sRecived[1024];
	if(file != NULL) {
	while(file->ReadString((LPTSTR)sRecived,1024)!=NULL) {
	strHtml += sRecived; }
 }
	session.Close();
	if(file!=NULL) file->Close();
	delete file; file = NULL;

	string html =  CT2A(strHtml.GetBuffer(0));
	return html;
}

DWORD WINAPI ThreadProc(LPVOID pParam)
{
	Htmltemp = GetHtmlSource(url);
	return 0;
}
#pragma once
#include "explorer1.h"
#include "afxwin.h"
#include <string>

using namespace std;
string GetHtmlSource(CString strURL);

// xkDlg �Ի���

class xkDlg : public CDialog
{
	DECLARE_DYNAMIC(xkDlg)

public:
	xkDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~xkDlg();
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_xk;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_course;
	UINT m_time;
	CButton m_bt2;
	afx_msg void OnBnClickedButton1();
	int m_n1;
	int m_n2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
};

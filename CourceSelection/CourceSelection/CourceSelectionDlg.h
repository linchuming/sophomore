
// CourceSelectionDlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"

// CCourceSelectionDlg �Ի���
class CCourceSelectionDlg : public CDialog
{
// ����
public:
	CCourceSelectionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COURCESELECTION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_ie;
	afx_msg void OnBnClickedButton1();
};


// CourceSelection.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCourceSelectionApp:
// �йش����ʵ�֣������ CourceSelection.cpp
//

class CCourceSelectionApp : public CWinApp
{
public:
	CCourceSelectionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCourceSelectionApp theApp;
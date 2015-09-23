#pragma once

#include "stdafx.h"
#include <string>
#include "afxinet.h"

using namespace std;
string GetHtmlSource(CString strURL);

string GetHtmlSource(CString strURL)
{
	CInternetSession session;
	CHttpFile *file = NULL; 

	CString strHtml = _T(""); //´æ·ÅÍøÒ³Êý¾Ý
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



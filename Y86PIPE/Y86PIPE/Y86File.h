/*
	Y86File.h
	ʵ�ֽ�ָ���ļ���ȡ��ʶ��
	Author: cm.lin
	Data: 2015.5.28
*/
#include <iostream>
#include <map>
#include <string>
#include <fstream> 
#include <stdio.h>
typedef unsigned char BYTE;
using namespace std;
class Y86File{
	ifstream f;
	BYTE * data;
	map<int,int> insID;
	map<int,int> insAddr;
	map<int,string> insStr;
	map<int,string> idStr;
	string dataStr;
	int count;
	int maxAddr; //��¼����ַ��
	int StrToNum(char str){
		if(str>='0' && str<='9') return str-'0';
		if(str>='a' && str<='f') return str-'a' + 10;
		else return 0;
	}
public:
	Y86File(){
		data = NULL;
	}
	~Y86File(){
		if(data) delete[] data;
	}
	bool openFile(char* pathname){
		f.open(pathname,ios::in);
		if(f.fail()) return false;

		count = 0;
		string str; dataStr = ""; maxAddr = 0;
		int addr,preaddr=-1;
		unsigned pos,presize;
		while(getline(f,str)){ //���ж�ȡ�ļ��������ַ�������
			pos = str.find("0x");
			if(pos != 2) continue;
			addr = 0; pos+=2;
			if(pos >= str.size()) continue;
			while(str[pos]!=':'){
				addr = addr * 16 + StrToNum(str[pos++]);
				if(pos >= str.size()) break;
			}
			if(maxAddr<addr) maxAddr = addr;

			if(pos >= str.size()) continue;

			pos+=2;
			if(pos >= str.size()) continue;
			string temp=""; string tp="";
			while(str[pos]>='0'&&str[pos]<='9' || str[pos]>='a'&&str[pos]<='f'){
				temp+=str[pos++];
				if(pos >= str.size()) continue;
			}
			if(temp.size()==0) continue;
			if(preaddr>=0){
				if(presize/2 < (unsigned)(addr - preaddr)){
					for(unsigned i=0;i<(addr-preaddr)-presize/2;i++) tp+="00";
				}
			}
			preaddr = addr; presize = temp.size();
			dataStr+=tp+temp;
			string istr="";
			pos = str.find("|");
			if(pos!=string::npos){
				istr = str.substr(pos+2,str.size());
			}
			idStr[count] = istr;
			insAddr[count] = addr;
			insID[addr] = count++;
			insStr[addr] = istr;
		}
		//cout<<dataStr<<endl;
		f.close();
		return true;
	}

	BYTE* GetData(int& size){ //��ȡָ�����
		if(data) delete[] data;
		data = new BYTE[maxAddr+16];
		size = maxAddr+16;
		unsigned i,j=0;
		for(i=0;i<dataStr.size();i+=2){
			data[j++] = StrToNum(dataStr[i]) * 16 + StrToNum(dataStr[i+1]);
		}
		return data;
	}

	int GetAddrID(int addr){return insID[addr];} 
	string GetAddrStr(int addr){return insStr[addr];} //��ȡĳ��ַ�ϵ�ָ��˵��
	string GetInsStr(int index){return idStr[index];} //��ȡ��index��ָ���˵��
	int GetAddr(int index) {return insAddr[index];}   //��ȡ��index��ָ��ĵ�ַ
	int GetInsNumber() {return count;} //��ȡ�ܵ�ָ����
	bool isFile() { return data!=NULL;} //�ж��Ƿ��ȡ���ļ�

};
/*
	Y86Code.h
	实现汇编代码转指令功能
	Author: cm.lin
	Data: 2015.6.6
*/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
class Y86Code{

	int GetByte(int val,int n){
		n = (n-1)*8;
		return (val>>n) & 0xff;
	}
	string itoStr(int val){
		char ch[4];
		string str="";
		sprintf_s(ch,"%.2x",GetByte(val,1));
		str+=ch;
		sprintf_s(ch,"%.2x",GetByte(val,2));
		str+=ch;
		sprintf_s(ch,"%.2x",GetByte(val,3));
		str+=ch;
		sprintf_s(ch,"%.2x",GetByte(val,4));
		str+=ch;
		return str;
	}
	string regCode(string str){
		
		if(str=="eax") return "0";
		if(str=="ecx") return "1";
		if(str=="edx") return "2";
		if(str=="ebx") return "3";
		if(str=="esp") return "4";
		if(str=="ebp") return "5";
		if(str=="esi") return "6";
		if(str=="edi") return "7";
		return "8";
	}
	int FindNumber(string str){
		int pos = str.find("$") + 1;
		int res = 0;
		while(str[pos]>='0' && str[pos]<='9'){
			res = res * 10 + str[pos++] - '0';
		}
		return res;
	}
public:
	Y86Code(){
	}
	string TranslateStr(string str){
		string res=""; int pos;
		if(str.find("halt")!=string::npos) return "10";
		else if(str.find("nop")!=string::npos) return "00";
		else if(str.find("rrmovl")!=string::npos){
			res="20";
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("%",pos) + 1;
			res+=regCode(str.substr(pos,3));
		}else if(str.find("irmovl")!=string::npos){
			res="308";
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			res+=itoStr(FindNumber(str));
		}else if(str.find("rmmovl")!=string::npos){
			res="40";
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("%",pos) + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("(") - 1;
			int val = 0, p = 1;
			while(str[pos]>='0'&&str[pos]<='9'){
				val+= p * (str[pos--]-'0');
				p*=10;
			}
			res+=itoStr(val);
		}else if(str.find("mrmovl")!=string::npos){
			res="50";
			pos = str.find(")");
			pos = str.find("%",pos) + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("(") - 1;
			int val = 0, p = 1;
			while(str[pos]>='0'&&str[pos]<='9'){
				val+= p * (str[pos--]-'0');
				p*=10;
			}
			res+=itoStr(val);
		}else if(str.find("addl")!=string::npos){
			res="60";
			goto h1;
		}else if(str.find("subl")!=string::npos){
			res="61";
			goto h1;
		}else if(str.find("andl")!=string::npos){
			res="62";
			goto h1;
		}else if(str.find("xorl")!=string::npos){
			res="63";
h1:
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			pos = str.find("%",pos) + 1;
			res+=regCode(str.substr(pos,3));
		}else if(str.find("jmp")!=string::npos){
			res="70";
			goto h2;
		}else if(str.find("jle")!=string::npos){
			res="71";
			goto h2;
		}else if(str.find("jl")!=string::npos){
			res="72";
			goto h2;
		}else if(str.find("je")!=string::npos){
			res="73";
			goto h2;
		}else if(str.find("jne")!=string::npos){
			res="74";
			goto h2;
		}else if(str.find("jge")!=string::npos){
			res="75";
			goto h2;
		}else if(str.find("jg")!=string::npos){
			res="76";
h2:
			res+=itoStr(FindNumber(str));
		}else if(str.find("call")!=string::npos){
			res="80";
			res+=itoStr(FindNumber(str));
		}else if(str.find("ret")!=string::npos){
			return "90";
		}else if(str.find("pushl")!=string::npos){
			res="a0";
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			res+="8";
		}else if(str.find("popl")!=string::npos){
			res="b0";
			pos = str.find("%") + 1;
			res+=regCode(str.substr(pos,3));
			res+="8";
		}
		return res;
	}
	string Decode(char * code){
		stringstream ssm;
		stringstream out;
		string str,res;
		int addr = 0;;
		ssm<<code;
		while(!ssm.eof()){
			getline(ssm,str);
			res = TranslateStr(str);
			out<<hex;
			out<<"  0x"<<addr<<": "<<res<<'\t';
			if(res.length() <= 2) out<<'\t';
			if(res.length() <= 4) out<<'\t';
			out<<"| "<<str<<endl;
			addr+=res.length()/2;
		}
		return out.str();
	}
};
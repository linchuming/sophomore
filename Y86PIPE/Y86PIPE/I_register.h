/*
	I_register.h
	�Ĵ���ʵ��
	Author: cm.lin
	Data: 2015.5.28
*/
//�Ĵ����ļ�ʵ��
#include <string.h>
class I_register{
	int reg[8];
public:
	I_register(){
		memset(reg,0,sizeof(int)*8);
	}

	int GetRegisterValue(unsigned id){ //��ȡ�Ĵ���RXXX��ֵ
		if(id>=8) return 0;
		return reg[id];
	}

	void SetRegisterValue(unsigned dst,int val){ //���üĴ���RXXX��ֵ
		if(dst>=8) return;
		reg[dst] = val;
	}

	void reset(){ //���üĴ���
		memset(reg,0,sizeof(int)*8);
	}
};
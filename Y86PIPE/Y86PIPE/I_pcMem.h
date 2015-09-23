/*
	I_pcMem.h
	ָ��洢��ʵ��
	Author: cm.lin
	Data: 2015.5.28
*/
//ָ��洢��ʵ��
#include "string.h"
typedef unsigned char BYTE;
class I_pcMem{
	void * pcOffset;
	void * pcAddr;
public:
	bool imem_error;
	I_pcMem(){
		pcOffset = NULL;
		imem_error = false;
	}
	~I_pcMem(){
		if(pcOffset) delete[] pcOffset;
	}
	void InitMemory(BYTE * init,unsigned size){ //����ָ�����
		pcOffset = new BYTE[size];
		memcpy(pcOffset,init,size);
	}

	void SetPCaddr(int pc){ //����pc
		pcAddr = (void*)((unsigned)pcOffset + pc);
	}

	int GetVal(int offset,int size){ //��pc+offset��ȡ��size��С������
		int result = 0;
		memcpy(&result,(void*)((unsigned)pcAddr+offset),size);
		return result;
	}

	void* GetpcOffset(){ //��ȡ������ʵ�ʵ�ָ��洢��ͷ��ַ
		return pcOffset;
	}
};
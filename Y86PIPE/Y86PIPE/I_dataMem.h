/*
	I_dataMem.h
	���ݴ洢��ʵ��
	Author: cm.lin
	Data: 2015.5.28
*/
//���ݴ洢��ʵ��
#include "string.h"

class I_dataMem{
	void* offset; //��ַƫ��
public:
	bool dmem_error;
	I_dataMem(){
		offset = 0;
		dmem_error = false;
	}
	I_dataMem(void* init){
		offset = init;
	}
	void SetInitAddr(void *init){ //���ô�������ʵ��ͷ��ַ
		offset = init;
	}
	int ReadMemoryData(int Addr){ //��ȡAddr��������
		void * addr = (void*)((int)offset + Addr); //�õ��ڴ���ʵ�ʵĵ�ַ
		int result;
		memcpy(&result,addr,sizeof(int));
		return result;
	}

	void WriteMemoryData(int Addr,int val){ //������д��Addr��
		void * addr = (void*)((int)offset + Addr); //�õ��ڴ���ʵ�ʵĵ�ַ
		memcpy(addr,&val,4);
	}
};
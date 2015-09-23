/*
	I_pcMem.h
	指令存储器实现
	Author: cm.lin
	Data: 2015.5.28
*/
//指令存储器实现
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
	void InitMemory(BYTE * init,unsigned size){ //导入指令集代码
		pcOffset = new BYTE[size];
		memcpy(pcOffset,init,size);
	}

	void SetPCaddr(int pc){ //设置pc
		pcAddr = (void*)((unsigned)pcOffset + pc);
	}

	int GetVal(int offset,int size){ //从pc+offset处取出size大小的数据
		int result = 0;
		memcpy(&result,(void*)((unsigned)pcAddr+offset),size);
		return result;
	}

	void* GetpcOffset(){ //获取程序中实际的指令存储器头地址
		return pcOffset;
	}
};
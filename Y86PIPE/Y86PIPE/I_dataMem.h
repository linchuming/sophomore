/*
	I_dataMem.h
	数据存储器实现
	Author: cm.lin
	Data: 2015.5.28
*/
//数据存储器实现
#include "string.h"

class I_dataMem{
	void* offset; //地址偏移
public:
	bool dmem_error;
	I_dataMem(){
		offset = 0;
		dmem_error = false;
	}
	I_dataMem(void* init){
		offset = init;
	}
	void SetInitAddr(void *init){ //设置储存器的实际头地址
		offset = init;
	}
	int ReadMemoryData(int Addr){ //读取Addr处的数据
		void * addr = (void*)((int)offset + Addr); //得到内存中实际的地址
		int result;
		memcpy(&result,addr,sizeof(int));
		return result;
	}

	void WriteMemoryData(int Addr,int val){ //将数据写入Addr处
		void * addr = (void*)((int)offset + Addr); //得到内存中实际的地址
		memcpy(addr,&val,4);
	}
};
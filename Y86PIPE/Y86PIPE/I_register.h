/*
	I_register.h
	寄存器实现
	Author: cm.lin
	Data: 2015.5.28
*/
//寄存器文件实现
#include <string.h>
class I_register{
	int reg[8];
public:
	I_register(){
		memset(reg,0,sizeof(int)*8);
	}

	int GetRegisterValue(unsigned id){ //获取寄存器RXXX的值
		if(id>=8) return 0;
		return reg[id];
	}

	void SetRegisterValue(unsigned dst,int val){ //设置寄存器RXXX的值
		if(dst>=8) return;
		reg[dst] = val;
	}

	void reset(){ //重置寄存器
		memset(reg,0,sizeof(int)*8);
	}
};
/*
	keywords.h
	保存码值
	Author: cm.lin
	Data: 2015.5.28
*/
//状态码
#define SAOK 0x1  //正常操作
#define SHLT 0x2  //处理器执行halt指令
#define SADR 0x3  //遇到非法地址
#define SINS 0x4  //遇到非法指令
#define SBUB 0x5  //遇到气泡

//******************************************

//指令码
#define IHALT 0x1
#define INOP 0x0
#define IRRMOVL 0x2
#define IIRMOVL 0x3
#define IRMMOVL 0x4
#define IMRMOVL 0x5
#define IOPL 0x6
#define IJXX 0x7
#define ICMOVXX 0x2
#define ICALL 0x8
#define IRET 0x9
#define IPUSHL 0xA
#define IPOPL 0xB

#define IADDL 0x0
#define ISUBL 0x1
#define IANDL 0x2
#define IXORL 0x3

#define IJMP 0x0
#define IJLE 0x1
#define IJL  0x2
#define IJE  0x3
#define IJNE 0x4
#define IJGE 0x5
#define IJG  0X6

#define ICMOVLE 0x1
#define ICMOVL 0x2
#define ICMOVE 0x3
#define ICMOVNE 0x4
#define ICMOVGE 0x5
#define ICMOVG 0x6

//******************************************

//寄存器码
#define REAX 0x0
#define RECX 0x1
#define REDX 0x2
#define REBX 0x3
#define RESP 0x4
#define REBP 0x5
#define RESI 0x6
#define REDI 0x7
#define RNONE 0x8

//******************************************
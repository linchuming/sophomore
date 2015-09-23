/*
	PIPE.h
	PIPE总实现
	Author: cm.lin
	Data: 2015.5.28
*/
#include "keywords.h"
#include "I_register.h"
#include "I_dataMem.h"
#include "I_pcMem.h"
#include <iostream>
#include <fstream> 
using namespace std;
typedef unsigned char BYTE;

//流水线寄存器的声明
struct F_reg{
	bool stall;
	int predPC;
};

struct D_reg{
	bool bubble,stall;
	int stat,icode,ifun,rA,rB,valC,valP,pc;
};

struct E_reg{
	bool bubble;
	int stat,icode,ifun,valC,valA,valB,dstE,dstM,srcA,srcB,pc;
};

struct M_reg{
	bool bubble,Cnd;
	int stat,icode,valE,valA,dstE,dstM,pc;
};

struct W_reg{
	bool stall;
	int stat,icode,valE,valM,dstE,dstM,pc;
};

/*
struct IN_WRITEBALCK{
	int stat,valE,valM,dstE,dstM;
};*/

struct OUT_WRITEBALCK{
	int stat,valE,valM,dstE,dstM,pc;
};

/*
struct IN_MEMORY{
	int stat,icode,Cnd,valE,valA,dstE,dstM;
};*/

struct OUT_MEMORY{
	bool mem_read,mem_write;
	int stat,icode,valE,valM,dstE,dstM,mem_addr,pc;
};

struct OUT_EXECUTE{
	bool Cnd,ZF,SF,OF;
	int stat,icode,valE,valA,dstE,dstM,ALUfun,aluA,aluB,pc;
};

struct OUT_DECODE{
	int stat,icode,ifun,valC,valA,valB,dstE,dstM,srcA,srcB,pc;
};

struct OUT_FETCH{
	int stat,icode,ifun,rA,rB,valC,valP,predictPC,f_pc;
};

class PIPE{
	F_reg F; D_reg D; E_reg E; M_reg M; W_reg W;
	OUT_FETCH f; OUT_DECODE d; OUT_EXECUTE e; OUT_MEMORY m; OUT_WRITEBALCK w;
	I_register reg; I_dataMem dataMem; I_pcMem pcMem;
	bool open,isEnd; //表示流水线是否进行

	bool ZF,SF,OF; //条件码

	void PipeLogicControl(){ //模拟PIPE逻辑控制
		
		if((E.icode==IMRMOVL||E.icode==IPOPL) && (E.dstM==d.srcA||E.dstM==d.srcB)
			|| (D.icode==IRET || E.icode==IRET || M.icode==IRET)) F.stall = true; else F.stall = false;

		if((E.icode==IMRMOVL || E.icode==IPOPL) && (E.dstM==d.srcA || E.dstM==d.srcB)) D.stall = true; else D.stall = false;

		if((E.icode==IJXX && !e.Cnd) || !((E.icode==IMRMOVL || E.icode==IPOPL) && (E.dstM==d.srcA || E.dstM==d.srcB)) && (D.icode==IRET||E.icode==IRET||M.icode==IRET))
			D.bubble = true; else D.bubble = false;

		if((E.icode==IJXX && !e.Cnd) || (E.icode==IMRMOVL || E.icode==IPOPL) && (E.dstM==d.srcA || E.dstM==d.srcB)) E.bubble = true; else E.bubble = false;

		if((m.stat==SADR || m.stat==SINS || m.stat==SHLT) || (W.stat==SADR || W.stat==SINS || W.stat==SHLT )) M.bubble = true; else M.bubble = false;

		if(W.stat==SADR || W.stat==SINS || W.stat==SHLT ) W.stall = true; else W.stall = false;
	}

	void Update(){ //模拟新的周期开始时，各个流水线寄存器状态以及存储器更新

		if(m.mem_write) dataMem.WriteMemoryData(m.mem_addr,M.valA); //更新数据存储器

		reg.SetRegisterValue(W.dstE,W.valE);
		reg.SetRegisterValue(W.dstM,W.valM); //更新寄存器文件

		//分别更新FDEMW五个寄存器
		if(!F.stall) F.predPC = f.predictPC;

		if(D.bubble) { D.icode = INOP; D.ifun = 0; D.stat = SBUB;}
		else if(!D.stall){
			D.icode = f.icode; D.ifun = f.ifun; D.rA = f.rA; D.rB = f.rB; D.stat = f.stat; D.valC = f.valC; D.valP = f.valP; D.pc = f.f_pc;
		}

		if(E.bubble) { E.icode = INOP; E.ifun = 0; E.stat = SBUB;}
		else{
			E.icode = d.icode; E.ifun = d.ifun; E.stat = d.stat; E.valA = d.valA; E.valB = d.valB; E.valC = d.valC;
			E.dstE = d.dstE; E.dstM = d.dstM; E.srcA = d.srcA; E.srcB = d.srcB; E.pc = d.pc;
		}

		if(M.bubble) {M.icode = INOP; M.stat = SBUB;}
		else{
			M.icode = e.icode; M.stat = e.stat; M.Cnd = e.Cnd; M.valA = e.valA; M.valE = e.valE; M.dstE = e.dstE; M.dstM = e.dstM; M.pc = e.pc;
		}

		if(!W.stall){
			W.icode = m.icode; W.stat = m.stat; W.valE = m.valE; W.valM = m.valM; W.dstE = m.dstE; W.dstM = m.dstM; W.pc = m.pc;
		}

	}

	void WriteBack(){
		if(W.stat == SBUB) w.stat = SAOK;
		else w.stat = W.stat;
		w.valE = W.valE; w.valM = W.valM; w.dstE = W.dstE; w.dstM = W.dstM; w.pc = W.pc;
	}

	void Fetch(){
		//f.valC = f.valP = 0; f.rA = f.rB = RNONE;
		f.rA = f.rB = RNONE;
		int f_pc;
		//select PC
		if(M.icode == IJXX && !M.Cnd) f_pc = M.valA;
		else if(W.icode == IRET) f_pc = W.valM;
		else f_pc = F.predPC;
		f.f_pc = f_pc;
		pcMem.SetPCaddr(f_pc);
		int buf = pcMem.GetVal(0,1);
		f.icode = (buf>>4) & 0xF; if(pcMem.imem_error) f.icode = INOP;
		f.ifun = buf & 0xF; if(pcMem.imem_error) f.ifun = 0xF;
		//cout<<hex<<f_pc<<" "<<f.icode<<" "<<f.ifun<<endl;
		bool instr_valid = (f.icode==INOP||f.icode==IHALT||f.icode==IRRMOVL||f.icode==IIRMOVL||f.icode==IRMMOVL||f.icode==IMRMOVL||f.icode==IOPL
			||f.icode==IJXX||f.icode==ICALL||f.icode==IRET||f.icode==IPUSHL||f.icode==IPOPL);

		bool need_regids = (f.icode==IRRMOVL||f.icode==IOPL||f.icode==IPUSHL||f.icode==IPOPL||f.icode==IIRMOVL||f.icode==IRMMOVL||f.icode==IMRMOVL);

		bool need_valC = (f.icode==IIRMOVL||f.icode==IRMMOVL||f.icode==IMRMOVL||f.icode==IJXX||f.icode==ICALL);

		if(pcMem.imem_error) f.stat = SADR; else if(!instr_valid) f.stat = SINS; else if(f.icode == IHALT) f.stat = SHLT;
		else f.stat = SAOK;

		int poffset = 1; 
		if(need_regids){
			buf = pcMem.GetVal(poffset,1);

			f.rA = (buf>>4) & 0xF;
			f.rB = buf & 0xF;
			poffset+=1;
		}
		if(need_valC){
			f.valC = pcMem.GetVal(poffset,4);

			poffset+=4;
		}

		f.valP = f_pc + poffset;

		if(f.icode == IJXX || f.icode == ICALL) f.predictPC = f.valC; else f.predictPC = f.valP;
	}

	void Decode(){
		if(D.icode==IRRMOVL||D.icode==IRMMOVL||D.icode==IOPL||D.icode==IPUSHL) d.srcA = D.rA;
		else if(D.icode==IPOPL||D.icode==IRET) d.srcA = RESP; 
		else d.srcA = RNONE;

		if(D.icode==IOPL||D.icode==IRMMOVL||D.icode==IMRMOVL) d.srcB = D.rB;
		else if(D.icode==IPUSHL||D.icode==IPOPL||D.icode==ICALL||D.icode==IRET) d.srcB = RESP;
		else d.srcB = RNONE;

		if(D.icode==IRRMOVL||D.icode==IIRMOVL||D.icode==IOPL) d.dstE = D.rB;
		else if(D.icode==IPUSHL||D.icode==IPOPL||D.icode==ICALL||D.icode==IRET) d.dstE = RESP;
		else d.dstE = RNONE;

		if(D.icode==IMRMOVL||D.icode==IPOPL) d.dstM = D.rA;
		else d.dstM = RNONE;

		if(D.icode==ICALL||D.icode==IJXX) d.valA = D.valP;
		else if(d.srcA == e.dstE) d.valA = e.valE;
		else if(d.srcA == M.dstM) d.valA = m.valM;
		else if(d.srcA == M.dstE) d.valA = M.valE;
		else if(d.srcA == W.dstM) d.valA = W.valM;
		else if(d.srcA == W.dstE) d.valA = W.valE;
		else d.valA = reg.GetRegisterValue(d.srcA);

		if(d.srcB == e.dstE) d.valB = e.valE;
		else if(d.srcB == M.dstM) d.valB = m.valM;
		else if(d.srcB == M.dstE) d.valB = M.valE;
		else if(d.srcB == W.dstM) d.valB = W.valM;
		else if(d.srcB == W.dstE) d.valB = W.valE;
		else d.valB = reg.GetRegisterValue(d.srcB);

		d.stat = D.stat; d.icode = D.icode; d.ifun = D.ifun; d.valC = D.valC; d.pc = D.pc;
	}

	void Execute(){
		int aluA = 0,aluB = 0;
		bool need_aluA = true,need_aluB = true;
		if(E.icode==IRRMOVL||E.icode==IOPL) aluA = E.valA;
		else if(E.icode==IIRMOVL||E.icode==IRMMOVL||E.icode==IMRMOVL) aluA = E.valC;
		else if(E.icode==ICALL||E.icode==IPUSHL) aluA = -4;
		else if(E.icode==IRET||E.icode==IPOPL) aluA = 4;
		else need_aluA = false;

		if(E.icode==IRMMOVL||E.icode==IMRMOVL||E.icode==IOPL||E.icode==ICALL||E.icode==IPUSHL||E.icode==IRET||E.icode==IPOPL) aluB = E.valB;
		else if(E.icode==IRRMOVL||E.icode==IIRMOVL) aluB = 0;
		else need_aluB = false;

		int alufun;
		if(E.icode==IOPL) alufun = E.ifun; else alufun = IADDL;
		
		bool set_cc = E.icode == IOPL && !(m.stat==SADR||m.stat==SINS||m.stat==SHLT) && !(W.stat==SADR||W.stat==SINS||W.stat==SHLT);
		e.valE = 0;
		if(need_aluA && need_aluB)
		{
		switch (alufun){ //ALU实现
		case IADDL:
			e.valE = aluA + aluB; break;
		case ISUBL:
			e.valE = aluA - aluB; break;
		case IANDL:
			e.valE = aluA & aluB; break;
		case IXORL:
			e.valE = aluA ^ aluB; break;
		default:
			break;
		}
		}
		e.ALUfun = alufun;
		if(set_cc){ //设置条件码
			ZF = e.valE == 0;
			SF = e.valE < 0;
			OF = (aluA<0 == aluB<0) && (e.valE<0 != aluA<0);
		}
		e.valA = E.valA;  e.icode = E.icode; e.stat = E.stat; e.dstM = E.dstM; e.aluA = aluA; e.aluB = aluB; e.pc = E.pc;
		e.Cnd = false; e.ZF = ZF; e.SF = SF; e.OF = OF;

		if(E.icode == IJXX){ //如果是跳转指令
			if(E.ifun == IJLE && ((SF^OF)|ZF)) e.Cnd = true;
			else if(E.ifun == IJL && (SF^OF)) e.Cnd = true;
			else if(E.ifun == IJE && (ZF)) e.Cnd = true;
			else if(E.ifun == IJNE && (!ZF)) e.Cnd = true;
			else if(E.ifun == IJGE && (!(SF^OF))) e.Cnd = true;
			else if(E.ifun == IJG && (!(SF^OF)&(!ZF))) e.Cnd = true;
			else if(E.ifun == IJMP) e.Cnd = true;
		}
		bool Cnd;
		if(set_cc) Cnd = e.Cnd; else Cnd = true;
		if(E.icode == IRRMOVL && !Cnd) e.dstE = RNONE; else e.dstE = E.dstE;

	}

	void Memory(){
		if(M.icode==IRMMOVL||M.icode==IPUSHL||M.icode==ICALL||M.icode==IMRMOVL) m.mem_addr = M.valE;
		else if(M.icode==IPOPL||M.icode==IRET) m.mem_addr = M.valA;
		if(M.icode==IMRMOVL||M.icode==IPOPL||M.icode==IRET) m.mem_read = true; else m.mem_read = false;
		if(M.icode==IRMMOVL||M.icode==IPUSHL||M.icode==ICALL) m.mem_write = true; else m.mem_write = false;

		if(m.mem_read)
			m.valM = dataMem.ReadMemoryData(m.mem_addr);

		if(dataMem.dmem_error) m.stat = SADR; else m.stat = M.stat;

		m.icode = M.icode; m.valE = M.valE; m.dstE = M.dstE; m.dstM = M.dstM; m.pc = M.pc;
	}


public:
	PIPE(){ //初始化
		F.stall = 0; F.predPC = 0x0;
		D.bubble = 0; D.stall = 0; D.icode = 0; D.rA = RNONE; D.rB = RNONE;
		E.bubble = 0; E.icode = 0; E.dstE = RNONE; E.dstM = RNONE;
		M.bubble = 0; M.icode = 0; M.dstE = RNONE; M.dstM = RNONE; 
		W.stall = 0; W.icode = 0; W.dstE = RNONE; W.dstM = RNONE;
		m.mem_read = false; m.mem_write = false;
		open = false; isEnd = false;
	}

	void LoadINS(BYTE*data,unsigned size){ //放入程序指令数据
		pcMem.InitMemory(data,size);
		dataMem.SetInitAddr(pcMem.GetpcOffset());
	}

	void reset(){ //PIPE重置
		open = false;
		isEnd = false;
		F_reg Fp; Fp.predPC = 0; F = Fp;
		D_reg Dp; Dp.icode = 0; Dp.stat = 0; Dp.ifun = 0; D = Dp; 
		E_reg Ep; Ep.icode = 0; Ep.ifun = 0; E = Ep; E.dstE = RNONE; E.dstM = RNONE; E.stat = 0;
		M_reg Mp; Mp.icode = 0; Mp.Cnd=0;M = Mp; M.dstE = RNONE; M.dstM = RNONE; M.stat = 0;
		W_reg Wp; Wp.icode = 0; W = Wp; W.dstE = RNONE; W.dstM = RNONE; W.stat = 0;
		OUT_FETCH fp; fp.f_pc=0; f = fp;
		OUT_DECODE dp; dp.icode=0;d = dp; d.icode = 0; d.ifun = 0; d.stat = 0;
		OUT_EXECUTE ep; ep.icode=0;e = ep; e.icode = 0; e.stat = 0;
		OUT_MEMORY mp; mp.icode=0;m = mp; m.icode = 0; m.stat = 0; m.dstE = RNONE; m.dstM = RNONE;
		OUT_WRITEBALCK wp; wp.stat=0; w = wp; w.stat = 0; w.dstE = RNONE; w.dstM = RNONE;
		reg.reset();
	}
	int Run(){ //单次执行
		if(!open){
			open = true;
			F.predPC = 0x0;
		}else{
			PipeLogicControl();
			Update();
		}
		WriteBack();
	    Memory();
	    Execute();
		Decode();
		Fetch();
		int stat = w.stat;
		if(stat == SHLT) { open = false; isEnd = true;}
		return stat;
	}

	F_reg GetFetchReg(){return F;}
	D_reg GetDecodeReg() {return D;}
	E_reg GetExecuteReg() {return E;}
	M_reg GetMemoryReg() {return M;}
	W_reg GetWriteBackReg() {return W;}
	OUT_FETCH GetFetchInfo() { return f;}
	OUT_DECODE GetDecodeInfo() {return d;}
	OUT_EXECUTE GetExecuteInfo() {return e;}
	OUT_MEMORY GetMemoryInfo() {return m;}
	OUT_WRITEBALCK GetWriteBackInfo() {return w;}
	bool isHalt(){ return isEnd;}
	int GetRegValue(unsigned id){
		return reg.GetRegisterValue(id);
	}

	bool autoRunAndExport(char* pathname){ //PIPE自动运行并保存到文件中
		ofstream file;
		file.open(pathname,ios::out);
		if(file.fail()) return false;

	int stat;
	int cycle = 0;

	reset();
	do{
		stat = Run();
		
		file<<dec<<"cycle:"<<cycle++<<endl;
		file<<"-------------------------------------"<<endl;
		file<<"FETCH:"<<endl<<'\t'<<hex<<"F_predPC:"<<F.predPC<<endl;
		file<<"DECODE:"<<endl;
		file<<'\t'<<"D_icode:"<<hex<<D.icode<<endl;
		file<<'\t'<<"D_ifun:"<<hex<<D.ifun<<endl;
		file<<'\t'<<"D_rA:"<<hex<<D.rA<<endl;
		file<<'\t'<<"D_rB:"<<hex<<D.rB<<endl;
		file<<'\t'<<"D_valC:"<<hex<<D.valC<<endl;
		file<<'\t'<<"D_valP:"<<hex<<D.valP<<endl;
		file<<"EXECUTE:"<<endl;
		file<<'\t'<<"E_icode:"<<E.icode<<endl;
		file<<'\t'<<"E_ifun:"<<E.ifun<<endl;
		file<<'\t'<<"E_valC:"<<E.valC<<endl;
		file<<'\t'<<"E_valA:"<<E.valA<<endl;
		file<<'\t'<<"E_valB:"<<E.valB<<endl;
		file<<'\t'<<"E_dstE:"<<E.dstE<<endl;
		file<<'\t'<<"E_dstM:"<<E.dstM<<endl;
		file<<'\t'<<"E_srcA:"<<E.srcA<<endl;
		file<<'\t'<<"E_srcB:"<<E.srcB<<endl;
		file<<"MEMORY:"<<endl;
		file<<'\t'<<"M_icode:"<<M.icode<<endl;
		file<<'\t'<<"M_Cnd:"<<M.Cnd<<endl;
		file<<'\t'<<"M_valE:"<<M.valE<<endl;
		file<<'\t'<<"M_valA:"<<M.valA<<endl;
		file<<'\t'<<"M_dstE:"<<M.dstE<<endl;
		file<<'\t'<<"M_dstM:"<<M.dstM<<endl;
		file<<"WRITE BACK:"<<endl;
		file<<'\t'<<"W_icode:"<<W.icode<<endl;
		file<<'\t'<<"W_valE:"<<W.valE<<endl;
		file<<'\t'<<"W_valM:"<<W.valM<<endl;
		file<<'\t'<<"W_dstE:"<<W.dstE<<endl;
		file<<'\t'<<"W_dstM:"<<W.dstM<<endl;
		//system("pause");
	}while(stat!=SHLT);
	file.close();
	return true;
	}
};
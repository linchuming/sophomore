/*
	Form1.h
	UI实现
	Author: cm.lin
	Date: 2015.5.28
*/
#pragma once
#include "PIPE.h"
#include "Y86File.h"
#include "Form2.h"
namespace Y86PIPE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace MyForm;
	PIPE pipe;
	Y86File file;
	int cycle_count;
	int px[12],py[12];
	int t_count;
	bool * breakpoint;
	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

		

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  文件ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  打开ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  导出运行结果ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  退出ToolStripMenuItem;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  wp_stat;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  W_valM;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  W_valE;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  W_icode;




	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  W_stat;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  W_dstM;


	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  W_dstE;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  mem_write;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  mem_read;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  mp_stat;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  M_dstM;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  M_dstE;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  M_valA;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  M_valE;

	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  M_Cnd;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  M_icode;

	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  M_stat;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  mp_valM;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  mem_addr;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::TextBox^  ep_Cnd;

	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::TextBox^  aluA;

	private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  aluB;

	private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::TextBox^  ALUfun;

	private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::TextBox^  ep_valE;

	private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::TextBox^  ep_dstE;

	private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::TextBox^  E_dstE;

	private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::TextBox^  E_valB;

	private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::TextBox^  E_valA;

	private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TextBox^  E_valC;

	private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::TextBox^  E_ifun;

	private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  E_icode;

	private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  E_stat;

	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  E_srcB;

private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  E_srcA;

private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::TextBox^  E_dstM;

private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::TextBox^  dp_srcB;

private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  dp_srcA;

private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::TextBox^  dp_dstM;

private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  dp_dstE;

private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::TextBox^  dp_valB;

private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::TextBox^  dp_valA;

private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  D_valP;

private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::TextBox^  D_valC;

private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::TextBox^  D_rB;

private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::TextBox^  D_rA;

private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::TextBox^  D_ifun;

private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::TextBox^  D_icode;

private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::TextBox^  D_stat;

private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::TextBox^  fp_valP;

private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::TextBox^  fp_valC;

private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::TextBox^  fp_rB;

private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::TextBox^  fp_rA;

private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::TextBox^  fp_ifun;

private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::TextBox^  fp_icode;

private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::TextBox^  fp_stat;

private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::TextBox^  f_pc;

private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::TextBox^  F_predPC;

private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::TextBox^  predictPC;

private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Label^  cycle;

private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::TextBox^  time;

private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::TextBox^  edi;

private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::TextBox^  esi;

private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::TextBox^  ebp;

private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::TextBox^  esp;

private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::TextBox^  ebx;

private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::TextBox^  edx;

private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::TextBox^  ecx;

private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::TextBox^  eax;

private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::ComponentModel::IContainer^  components;
private: System::Windows::Forms::ToolStripMenuItem^  重置ToolStripMenuItem;
private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
	bool run_stat;
	System::Drawing::Pen^ myPen;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::ListView^  ins;
private: System::Windows::Forms::ColumnHeader^  ins_addr;
private: System::Windows::Forms::ColumnHeader^  ins_ins;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::Label^  OF;

private: System::Windows::Forms::Label^  SF;

private: System::Windows::Forms::Label^  ZF;

private: System::Windows::Forms::TextBox^  F_ins;

private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::TextBox^  D_ins;

private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::TextBox^  E_ins;

private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::TextBox^  M_ins;

private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::TextBox^  W_ins;

private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::ToolStripMenuItem^  编译器ToolStripMenuItem;


		 Form2^ form2;
		 System::Drawing::Bitmap^ bmp;
	String^ GetStat(int stat){
		switch (stat)
		{
		case SADR:
			return "SADR";
		case SAOK:
			return "SAOK";
		case SBUB:
			return "SBUB";
		case SHLT:
			return "SHLT";
		case SINS:
			return "SINS";
		}
		return "";
	}
	void UpdataState(){
		//寄存器部分
		this->eax->Text = "0x" + pipe.GetRegValue(REAX).ToString("x");
		this->ecx->Text = "0x" + pipe.GetRegValue(RECX).ToString("x");
		this->edx->Text = "0x" + pipe.GetRegValue(REDX).ToString("x");
		this->ebx->Text = "0x" + pipe.GetRegValue(REBX).ToString("x");
		this->esp->Text = "0x" + pipe.GetRegValue(RESP).ToString("x");
		this->ebp->Text = "0x" + pipe.GetRegValue(REBP).ToString("x");
		this->esi->Text = "0x" + pipe.GetRegValue(RESI).ToString("x");
		this->edi->Text = "0x" + pipe.GetRegValue(REDI).ToString("x");

		//流水线部分
		F_reg F = pipe.GetFetchReg();
		D_reg D = pipe.GetDecodeReg();
		E_reg E = pipe.GetExecuteReg();
		M_reg M = pipe.GetMemoryReg();
		W_reg W = pipe.GetWriteBackReg();
		OUT_FETCH f = pipe.GetFetchInfo();
		OUT_DECODE d = pipe.GetDecodeInfo();
		OUT_EXECUTE e = pipe.GetExecuteInfo();
		OUT_MEMORY m = pipe.GetMemoryInfo();
		OUT_WRITEBALCK w = pipe.GetWriteBackInfo();

		this->F_predPC->Text = "0x" + F.predPC.ToString("x");

		this->fp_icode->Text = "0x" + f.icode.ToString("x");
		this->fp_ifun->Text = "0x" + f.ifun.ToString("x");
		this->fp_rA->Text = "0x" + f.rA.ToString("x");
		this->fp_rB->Text = "0x" + f.rB.ToString("x");
		this->fp_valC->Text = "0x" + f.valC.ToString("x");
		this->fp_valP->Text = "0x" + f.valP.ToString("x");
		this->f_pc->Text = "0x" + f.f_pc.ToString("x");
		this->predictPC->Text = "0x" + f.predictPC.ToString("x");

		this->D_icode->Text = "0x" + D.icode.ToString("x");
		this->D_ifun->Text = "0x" + D.ifun.ToString("x");
		this->D_rA->Text = "0x" + D.rA.ToString("x");
		this->D_rB->Text = "0x" + D.rB.ToString("x");
		this->D_valC->Text = "0x" + D.valC.ToString("x");
		this->D_valP->Text = "0x" + D.valP.ToString("x");

		this->dp_valA->Text = "0x" + d.valA.ToString("x");
		this->dp_valB->Text = "0x" + d.valB.ToString("x");
		this->dp_dstE->Text = "0x" + d.dstE.ToString("x");
		this->dp_dstM->Text = "0x" + d.dstM.ToString("x");
		this->dp_srcA->Text = "0x" + d.srcA.ToString("x");
		this->dp_srcB->Text = "0x" + d.srcB.ToString("x");

		this->E_icode->Text = "0x" + E.icode.ToString("x");
		this->E_ifun->Text = "0x" + E.ifun.ToString("x");
		this->E_valA->Text = "0x" + E.valA.ToString("x");
		this->E_valB->Text = "0x" + E.valB.ToString("x");
		this->E_valC->Text = "0x" + E.valC.ToString("x");
		this->E_dstE->Text = "0x" + E.dstE.ToString("x");
		this->E_dstM->Text = "0x" + E.dstM.ToString("x");
		this->E_srcA->Text = "0x" + E.srcA.ToString("x");
		this->E_srcB->Text = "0x" + E.srcB.ToString("x");

		if(e.Cnd) this->ep_Cnd->Text = "True"; else this->ep_Cnd->Text = "False";
		this->ep_dstE->Text = "0x" + e.dstE.ToString("x");
		this->ep_valE->Text = "0x" + e.valE.ToString("x");
		this->aluA->Text = "0x" + e.aluA.ToString("x");
		this->aluB->Text = "0x" + e.aluB.ToString("x");

		this->M_icode->Text = "0x" + M.icode.ToString("x");
		this->M_dstE->Text = "0x" + M.dstE.ToString("x");
		this->M_dstM->Text = "0x" + M.dstM.ToString("x");
		this->M_valA->Text = "0x" + M.valA.ToString("x");
		this->M_valE->Text = "0x" + M.valE.ToString("x");
		if(M.Cnd) this->M_Cnd->Text = "True"; else this->M_Cnd->Text = "False";

		this->mp_valM->Text = "0x" + m.valM.ToString("x");
		this->mem_addr->Text = "0x" + m.mem_addr.ToString("x");
		this->mem_read->Text = m.mem_read.ToString();
		this->mem_write->Text = m.mem_write.ToString();

		this->W_icode->Text = "0x" + W.icode.ToString("x");
		this->W_valM->Text = "0x" + W.valM.ToString("x");
		this->W_valE->Text = "0x" + W.valE.ToString("x");
		this->W_dstE->Text = "0x" + W.dstE.ToString("x");
		this->W_dstM->Text = "0x" + W.dstM.ToString("x");
		
		this->fp_stat->Text = GetStat(f.stat);
		this->D_stat->Text = GetStat(D.stat);
		this->E_stat->Text = GetStat(E.stat);
		this->M_stat->Text = GetStat(M.stat);
		this->mp_stat->Text = GetStat(m.stat);
		this->W_stat->Text = GetStat(W.stat);
		this->wp_stat->Text = GetStat(w.stat);
		
		switch (e.ALUfun)
		{
		case IADDL:
			this->ALUfun->Text = "ADDL";
			break;
		case ISUBL:
			this->ALUfun->Text = "SUBL";
			break;
		case IANDL:
			this->ALUfun->Text = "ANDL";
			break;
		case IXORL:
			this->ALUfun->Text = "XORL";
			break;
		}

		//条件码部分
		if(e.ZF) this->ZF->Text = "ZF = 1"; else this->ZF->Text = "ZF = 0";
		if(e.SF) this->SF->Text = "SF = 1"; else this->SF->Text = "SF = 0";
		if(e.OF) this->OF->Text = "OF = 1"; else this->OF->Text = "OF = 0";

		//指令运行部分
		string str = file.GetAddrStr(f.f_pc);
		String ^ MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
		F_ins->Text = "0x" + f.f_pc.ToString("x") + ":" + MyStr;

		if(d.stat==SAOK||d.stat==SHLT){
			str = file.GetAddrStr(d.pc);
			MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
			D_ins->Text = "0x" + d.pc.ToString("x") + ":" + MyStr;
		}else D_ins->Text = "NOP";

		if(e.stat==SAOK||e.stat==SHLT){
			str = file.GetAddrStr(e.pc);
			MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
			E_ins->Text = "0x" + e.pc.ToString("x") + ":" + MyStr;
		}else E_ins->Text = "NOP";

		if(m.stat==SAOK||m.stat==SHLT){
			str = file.GetAddrStr(m.pc);
			MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
			M_ins->Text = "0x" + m.pc.ToString("x") + ":" + MyStr;
		}else M_ins->Text = "NOP";	

		if(w.stat==SAOK||w.stat==SHLT){
			str = file.GetAddrStr(w.pc);
			MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
			W_ins->Text = "0x" + w.pc.ToString("x") + ":" + MyStr;
		}else W_ins->Text = "NOP";
	}

	
	void pointReset(){
		px[0] = 0; py[0] = 10;
		px[1] = 30; py[1] = 10;
		px[2] = 30; py[2] = 40;
		px[3] = 60; py[3] = 40;
		px[4] = 60; py[4] = 10;
		px[5] = 90; py[5] = 10;
		px[6] = 90; py[6] = 40;
		px[7] = 120; py[7] = 40;
		px[8] = 120; py[8] = 10;
		px[9] = 150; py[9] = 10;
		px[10] = 150; py[10] = 40;
		px[11] = 180; py[11] = 40;
	}

	void movePoint(int m){
		for(int i=0;i<12;i++){
			px[i]-=m;
		}
	}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->文件ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->打开ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->导出运行结果ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->退出ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->重置ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->F_predPC = (gcnew System::Windows::Forms::TextBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->predictPC = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->f_pc = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->fp_valP = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->fp_valC = (gcnew System::Windows::Forms::TextBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->fp_rB = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->fp_rA = (gcnew System::Windows::Forms::TextBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->fp_ifun = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->fp_icode = (gcnew System::Windows::Forms::TextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->fp_stat = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->D_valP = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->D_valC = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->D_rB = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->D_rA = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->D_ifun = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->D_icode = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->D_stat = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->dp_srcB = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->dp_srcA = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->dp_dstM = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->dp_dstE = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->dp_valB = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->dp_valA = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->E_srcB = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->E_srcA = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->E_dstM = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->E_dstE = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->ep_dstE = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->ep_valE = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->ALUfun = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->aluB = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->aluA = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->ep_Cnd = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->M_dstM = (gcnew System::Windows::Forms::TextBox());
			this->E_valB = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->M_dstE = (gcnew System::Windows::Forms::TextBox());
			this->E_valA = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->M_valA = (gcnew System::Windows::Forms::TextBox());
			this->E_valC = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->M_valE = (gcnew System::Windows::Forms::TextBox());
			this->E_ifun = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->M_Cnd = (gcnew System::Windows::Forms::TextBox());
			this->E_icode = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->E_stat = (gcnew System::Windows::Forms::TextBox());
			this->M_icode = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->M_stat = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->mp_valM = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->mem_addr = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->mem_write = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->mem_read = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->mp_stat = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->W_dstM = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->W_dstE = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->W_valM = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->W_valE = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->W_icode = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->W_stat = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->wp_stat = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->cycle = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->time = (gcnew System::Windows::Forms::TextBox());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->edi = (gcnew System::Windows::Forms::TextBox());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->esi = (gcnew System::Windows::Forms::TextBox());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->ebp = (gcnew System::Windows::Forms::TextBox());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->esp = (gcnew System::Windows::Forms::TextBox());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->ebx = (gcnew System::Windows::Forms::TextBox());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->edx = (gcnew System::Windows::Forms::TextBox());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->ecx = (gcnew System::Windows::Forms::TextBox());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->eax = (gcnew System::Windows::Forms::TextBox());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->ins = (gcnew System::Windows::Forms::ListView());
			this->ins_addr = (gcnew System::Windows::Forms::ColumnHeader());
			this->ins_ins = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->OF = (gcnew System::Windows::Forms::Label());
			this->SF = (gcnew System::Windows::Forms::Label());
			this->ZF = (gcnew System::Windows::Forms::Label());
			this->F_ins = (gcnew System::Windows::Forms::TextBox());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->D_ins = (gcnew System::Windows::Forms::TextBox());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->E_ins = (gcnew System::Windows::Forms::TextBox());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->M_ins = (gcnew System::Windows::Forms::TextBox());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->W_ins = (gcnew System::Windows::Forms::TextBox());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->编译器ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox10->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->文件ToolStripMenuItem, 
				this->重置ToolStripMenuItem, this->编译器ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(976, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 文件ToolStripMenuItem
			// 
			this->文件ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->打开ToolStripMenuItem, 
				this->导出运行结果ToolStripMenuItem, this->toolStripMenuItem1, this->退出ToolStripMenuItem});
			this->文件ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->文件ToolStripMenuItem->Name = L"文件ToolStripMenuItem";
			this->文件ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->文件ToolStripMenuItem->Text = L"文件";
			// 
			// 打开ToolStripMenuItem
			// 
			this->打开ToolStripMenuItem->Name = L"打开ToolStripMenuItem";
			this->打开ToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->打开ToolStripMenuItem->Text = L"打开文件";
			this->打开ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::打开ToolStripMenuItem_Click);
			// 
			// 导出运行结果ToolStripMenuItem
			// 
			this->导出运行结果ToolStripMenuItem->Enabled = false;
			this->导出运行结果ToolStripMenuItem->Name = L"导出运行结果ToolStripMenuItem";
			this->导出运行结果ToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->导出运行结果ToolStripMenuItem->Text = L"导出运行结果";
			this->导出运行结果ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::导出运行结果ToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(143, 6);
			// 
			// 退出ToolStripMenuItem
			// 
			this->退出ToolStripMenuItem->Name = L"退出ToolStripMenuItem";
			this->退出ToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->退出ToolStripMenuItem->Text = L"退出";
			this->退出ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::退出ToolStripMenuItem_Click);
			// 
			// 重置ToolStripMenuItem
			// 
			this->重置ToolStripMenuItem->Name = L"重置ToolStripMenuItem";
			this->重置ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->重置ToolStripMenuItem->Text = L"重置";
			this->重置ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::重置ToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->F_predPC);
			this->groupBox1->Controls->Add(this->label62);
			this->groupBox1->Controls->Add(this->label63);
			this->groupBox1->Controls->Add(this->groupBox6);
			this->groupBox1->Controls->Add(this->D_valP);
			this->groupBox1->Controls->Add(this->label45);
			this->groupBox1->Controls->Add(this->D_valC);
			this->groupBox1->Controls->Add(this->label46);
			this->groupBox1->Controls->Add(this->D_rB);
			this->groupBox1->Controls->Add(this->label47);
			this->groupBox1->Controls->Add(this->D_rA);
			this->groupBox1->Controls->Add(this->label48);
			this->groupBox1->Controls->Add(this->D_ifun);
			this->groupBox1->Controls->Add(this->label49);
			this->groupBox1->Controls->Add(this->D_icode);
			this->groupBox1->Controls->Add(this->label50);
			this->groupBox1->Controls->Add(this->D_stat);
			this->groupBox1->Controls->Add(this->label51);
			this->groupBox1->Controls->Add(this->label52);
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->E_srcB);
			this->groupBox1->Controls->Add(this->label38);
			this->groupBox1->Controls->Add(this->E_srcA);
			this->groupBox1->Controls->Add(this->label37);
			this->groupBox1->Controls->Add(this->E_dstM);
			this->groupBox1->Controls->Add(this->label36);
			this->groupBox1->Controls->Add(this->E_dstE);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->label28);
			this->groupBox1->Controls->Add(this->M_dstM);
			this->groupBox1->Controls->Add(this->E_valB);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label29);
			this->groupBox1->Controls->Add(this->M_dstE);
			this->groupBox1->Controls->Add(this->E_valA);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label30);
			this->groupBox1->Controls->Add(this->M_valA);
			this->groupBox1->Controls->Add(this->E_valC);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->label31);
			this->groupBox1->Controls->Add(this->M_valE);
			this->groupBox1->Controls->Add(this->E_ifun);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label32);
			this->groupBox1->Controls->Add(this->M_Cnd);
			this->groupBox1->Controls->Add(this->E_icode);
			this->groupBox1->Controls->Add(this->label33);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->E_stat);
			this->groupBox1->Controls->Add(this->M_icode);
			this->groupBox1->Controls->Add(this->label34);
			this->groupBox1->Controls->Add(this->label20);
			this->groupBox1->Controls->Add(this->label35);
			this->groupBox1->Controls->Add(this->M_stat);
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->W_dstM);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->W_dstE);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->W_valM);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->W_valE);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->W_icode);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->W_stat);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(15, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(615, 503);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"流水线状态";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// F_predPC
			// 
			this->F_predPC->Location = System::Drawing::Point(293, 476);
			this->F_predPC->Name = L"F_predPC";
			this->F_predPC->ReadOnly = true;
			this->F_predPC->Size = System::Drawing::Size(45, 23);
			this->F_predPC->TabIndex = 72;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(242, 477);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(54, 17);
			this->label62->TabIndex = 71;
			this->label62->Text = L"predPC:";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(9, 477);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(14, 17);
			this->label63->TabIndex = 70;
			this->label63->Text = L"F";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->predictPC);
			this->groupBox6->Controls->Add(this->label61);
			this->groupBox6->Controls->Add(this->f_pc);
			this->groupBox6->Controls->Add(this->label60);
			this->groupBox6->Controls->Add(this->fp_valP);
			this->groupBox6->Controls->Add(this->label53);
			this->groupBox6->Controls->Add(this->fp_valC);
			this->groupBox6->Controls->Add(this->label54);
			this->groupBox6->Controls->Add(this->fp_rB);
			this->groupBox6->Controls->Add(this->label55);
			this->groupBox6->Controls->Add(this->fp_rA);
			this->groupBox6->Controls->Add(this->label56);
			this->groupBox6->Controls->Add(this->fp_ifun);
			this->groupBox6->Controls->Add(this->label57);
			this->groupBox6->Controls->Add(this->fp_icode);
			this->groupBox6->Controls->Add(this->label58);
			this->groupBox6->Controls->Add(this->fp_stat);
			this->groupBox6->Controls->Add(this->label59);
			this->groupBox6->Location = System::Drawing::Point(10, 393);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(595, 79);
			this->groupBox6->TabIndex = 69;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Fetch";
			// 
			// predictPC
			// 
			this->predictPC->Location = System::Drawing::Point(166, 51);
			this->predictPC->Name = L"predictPC";
			this->predictPC->ReadOnly = true;
			this->predictPC->Size = System::Drawing::Size(45, 23);
			this->predictPC->TabIndex = 86;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(100, 53);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(67, 17);
			this->label61->TabIndex = 85;
			this->label61->Text = L"predictPC:";
			// 
			// f_pc
			// 
			this->f_pc->Location = System::Drawing::Point(49, 50);
			this->f_pc->Name = L"f_pc";
			this->f_pc->ReadOnly = true;
			this->f_pc->Size = System::Drawing::Size(45, 23);
			this->f_pc->TabIndex = 84;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(15, 51);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(34, 17);
			this->label60->TabIndex = 83;
			this->label60->Text = L"f_pc:";
			// 
			// fp_valP
			// 
			this->fp_valP->Location = System::Drawing::Point(519, 20);
			this->fp_valP->Name = L"fp_valP";
			this->fp_valP->ReadOnly = true;
			this->fp_valP->Size = System::Drawing::Size(45, 23);
			this->fp_valP->TabIndex = 82;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(485, 20);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(34, 17);
			this->label53->TabIndex = 81;
			this->label53->Text = L"valP:";
			// 
			// fp_valC
			// 
			this->fp_valC->Location = System::Drawing::Point(437, 20);
			this->fp_valC->Name = L"fp_valC";
			this->fp_valC->ReadOnly = true;
			this->fp_valC->Size = System::Drawing::Size(45, 23);
			this->fp_valC->TabIndex = 80;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(402, 20);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(35, 17);
			this->label54->TabIndex = 79;
			this->label54->Text = L"valC:";
			// 
			// fp_rB
			// 
			this->fp_rB->Location = System::Drawing::Point(354, 20);
			this->fp_rB->Name = L"fp_rB";
			this->fp_rB->ReadOnly = true;
			this->fp_rB->Size = System::Drawing::Size(45, 23);
			this->fp_rB->TabIndex = 78;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(332, 20);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(24, 17);
			this->label55->TabIndex = 77;
			this->label55->Text = L"rB:";
			// 
			// fp_rA
			// 
			this->fp_rA->Location = System::Drawing::Point(283, 20);
			this->fp_rA->Name = L"fp_rA";
			this->fp_rA->ReadOnly = true;
			this->fp_rA->Size = System::Drawing::Size(45, 23);
			this->fp_rA->TabIndex = 76;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(262, 20);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(24, 17);
			this->label56->TabIndex = 75;
			this->label56->Text = L"rA:";
			// 
			// fp_ifun
			// 
			this->fp_ifun->Location = System::Drawing::Point(216, 20);
			this->fp_ifun->Name = L"fp_ifun";
			this->fp_ifun->ReadOnly = true;
			this->fp_ifun->Size = System::Drawing::Size(45, 23);
			this->fp_ifun->TabIndex = 74;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(184, 20);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(32, 17);
			this->label57->TabIndex = 73;
			this->label57->Text = L"ifun:";
			// 
			// fp_icode
			// 
			this->fp_icode->Location = System::Drawing::Point(136, 20);
			this->fp_icode->Name = L"fp_icode";
			this->fp_icode->ReadOnly = true;
			this->fp_icode->Size = System::Drawing::Size(45, 23);
			this->fp_icode->TabIndex = 72;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(96, 20);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(43, 17);
			this->label58->TabIndex = 71;
			this->label58->Text = L"icode:";
			// 
			// fp_stat
			// 
			this->fp_stat->Location = System::Drawing::Point(49, 19);
			this->fp_stat->Name = L"fp_stat";
			this->fp_stat->ReadOnly = true;
			this->fp_stat->Size = System::Drawing::Size(45, 23);
			this->fp_stat->TabIndex = 70;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(15, 20);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(32, 17);
			this->label59->TabIndex = 69;
			this->label59->Text = L"stat:";
			// 
			// D_valP
			// 
			this->D_valP->Location = System::Drawing::Point(529, 369);
			this->D_valP->Name = L"D_valP";
			this->D_valP->ReadOnly = true;
			this->D_valP->Size = System::Drawing::Size(45, 23);
			this->D_valP->TabIndex = 68;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(495, 369);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(34, 17);
			this->label45->TabIndex = 67;
			this->label45->Text = L"valP:";
			// 
			// D_valC
			// 
			this->D_valC->Location = System::Drawing::Point(447, 369);
			this->D_valC->Name = L"D_valC";
			this->D_valC->ReadOnly = true;
			this->D_valC->Size = System::Drawing::Size(45, 23);
			this->D_valC->TabIndex = 66;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(412, 369);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(35, 17);
			this->label46->TabIndex = 65;
			this->label46->Text = L"valC:";
			// 
			// D_rB
			// 
			this->D_rB->Location = System::Drawing::Point(364, 369);
			this->D_rB->Name = L"D_rB";
			this->D_rB->ReadOnly = true;
			this->D_rB->Size = System::Drawing::Size(45, 23);
			this->D_rB->TabIndex = 64;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(342, 369);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(24, 17);
			this->label47->TabIndex = 63;
			this->label47->Text = L"rB:";
			// 
			// D_rA
			// 
			this->D_rA->Location = System::Drawing::Point(293, 369);
			this->D_rA->Name = L"D_rA";
			this->D_rA->ReadOnly = true;
			this->D_rA->Size = System::Drawing::Size(45, 23);
			this->D_rA->TabIndex = 62;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(272, 369);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(24, 17);
			this->label48->TabIndex = 61;
			this->label48->Text = L"rA:";
			// 
			// D_ifun
			// 
			this->D_ifun->Location = System::Drawing::Point(226, 369);
			this->D_ifun->Name = L"D_ifun";
			this->D_ifun->ReadOnly = true;
			this->D_ifun->Size = System::Drawing::Size(45, 23);
			this->D_ifun->TabIndex = 60;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(194, 369);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(32, 17);
			this->label49->TabIndex = 59;
			this->label49->Text = L"ifun:";
			// 
			// D_icode
			// 
			this->D_icode->Location = System::Drawing::Point(146, 369);
			this->D_icode->Name = L"D_icode";
			this->D_icode->ReadOnly = true;
			this->D_icode->Size = System::Drawing::Size(45, 23);
			this->D_icode->TabIndex = 58;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(106, 369);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(43, 17);
			this->label50->TabIndex = 57;
			this->label50->Text = L"icode:";
			// 
			// D_stat
			// 
			this->D_stat->Location = System::Drawing::Point(59, 368);
			this->D_stat->Name = L"D_stat";
			this->D_stat->ReadOnly = true;
			this->D_stat->Size = System::Drawing::Size(45, 23);
			this->D_stat->TabIndex = 56;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(25, 369);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(32, 17);
			this->label51->TabIndex = 55;
			this->label51->Text = L"stat:";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(9, 369);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(17, 17);
			this->label52->TabIndex = 54;
			this->label52->Text = L"D";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->dp_srcB);
			this->groupBox5->Controls->Add(this->label39);
			this->groupBox5->Controls->Add(this->dp_srcA);
			this->groupBox5->Controls->Add(this->label40);
			this->groupBox5->Controls->Add(this->dp_dstM);
			this->groupBox5->Controls->Add(this->label41);
			this->groupBox5->Controls->Add(this->dp_dstE);
			this->groupBox5->Controls->Add(this->label42);
			this->groupBox5->Controls->Add(this->dp_valB);
			this->groupBox5->Controls->Add(this->label43);
			this->groupBox5->Controls->Add(this->dp_valA);
			this->groupBox5->Controls->Add(this->label44);
			this->groupBox5->Location = System::Drawing::Point(7, 299);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(598, 63);
			this->groupBox5->TabIndex = 53;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Decode";
			// 
			// dp_srcB
			// 
			this->dp_srcB->Location = System::Drawing::Point(519, 22);
			this->dp_srcB->Name = L"dp_srcB";
			this->dp_srcB->ReadOnly = true;
			this->dp_srcB->Size = System::Drawing::Size(45, 23);
			this->dp_srcB->TabIndex = 43;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(473, 23);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(49, 17);
			this->label39->TabIndex = 42;
			this->label39->Text = L"d_srcB:";
			// 
			// dp_srcA
			// 
			this->dp_srcA->Location = System::Drawing::Point(425, 21);
			this->dp_srcA->Name = L"dp_srcA";
			this->dp_srcA->ReadOnly = true;
			this->dp_srcA->Size = System::Drawing::Size(45, 23);
			this->dp_srcA->TabIndex = 41;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(379, 22);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(49, 17);
			this->label40->TabIndex = 40;
			this->label40->Text = L"d_srcA:";
			// 
			// dp_dstM
			// 
			this->dp_dstM->Location = System::Drawing::Point(334, 21);
			this->dp_dstM->Name = L"dp_dstM";
			this->dp_dstM->ReadOnly = true;
			this->dp_dstM->Size = System::Drawing::Size(45, 23);
			this->dp_dstM->TabIndex = 39;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(284, 22);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(54, 17);
			this->label41->TabIndex = 38;
			this->label41->Text = L"d_dstM:";
			// 
			// dp_dstE
			// 
			this->dp_dstE->Location = System::Drawing::Point(237, 21);
			this->dp_dstE->Name = L"dp_dstE";
			this->dp_dstE->ReadOnly = true;
			this->dp_dstE->Size = System::Drawing::Size(45, 23);
			this->dp_dstE->TabIndex = 37;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(191, 22);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(49, 17);
			this->label42->TabIndex = 36;
			this->label42->Text = L"d_dstE:";
			// 
			// dp_valB
			// 
			this->dp_valB->Location = System::Drawing::Point(144, 21);
			this->dp_valB->Name = L"dp_valB";
			this->dp_valB->ReadOnly = true;
			this->dp_valB->Size = System::Drawing::Size(45, 23);
			this->dp_valB->TabIndex = 35;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(99, 21);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(48, 17);
			this->label43->TabIndex = 34;
			this->label43->Text = L"d_valB:";
			// 
			// dp_valA
			// 
			this->dp_valA->Location = System::Drawing::Point(52, 20);
			this->dp_valA->Name = L"dp_valA";
			this->dp_valA->ReadOnly = true;
			this->dp_valA->Size = System::Drawing::Size(45, 23);
			this->dp_valA->TabIndex = 33;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(7, 21);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(48, 17);
			this->label44->TabIndex = 32;
			this->label44->Text = L"d_valA:";
			// 
			// E_srcB
			// 
			this->E_srcB->Location = System::Drawing::Point(308, 275);
			this->E_srcB->Name = L"E_srcB";
			this->E_srcB->ReadOnly = true;
			this->E_srcB->Size = System::Drawing::Size(45, 23);
			this->E_srcB->TabIndex = 52;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(273, 275);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(36, 17);
			this->label38->TabIndex = 51;
			this->label38->Text = L"srcB:";
			// 
			// E_srcA
			// 
			this->E_srcA->Location = System::Drawing::Point(226, 275);
			this->E_srcA->Name = L"E_srcA";
			this->E_srcA->ReadOnly = true;
			this->E_srcA->Size = System::Drawing::Size(45, 23);
			this->E_srcA->TabIndex = 50;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(191, 275);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(36, 17);
			this->label37->TabIndex = 49;
			this->label37->Text = L"srcA:";
			// 
			// E_dstM
			// 
			this->E_dstM->Location = System::Drawing::Point(146, 275);
			this->E_dstM->Name = L"E_dstM";
			this->E_dstM->ReadOnly = true;
			this->E_dstM->Size = System::Drawing::Size(45, 23);
			this->E_dstM->TabIndex = 48;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(109, 275);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(41, 17);
			this->label36->TabIndex = 47;
			this->label36->Text = L"dstM:";
			// 
			// E_dstE
			// 
			this->E_dstE->Location = System::Drawing::Point(59, 274);
			this->E_dstE->Name = L"E_dstE";
			this->E_dstE->ReadOnly = true;
			this->E_dstE->Size = System::Drawing::Size(45, 23);
			this->E_dstE->TabIndex = 46;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->ep_dstE);
			this->groupBox4->Controls->Add(this->label27);
			this->groupBox4->Controls->Add(this->ep_valE);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Controls->Add(this->ALUfun);
			this->groupBox4->Controls->Add(this->label25);
			this->groupBox4->Controls->Add(this->aluB);
			this->groupBox4->Controls->Add(this->label24);
			this->groupBox4->Controls->Add(this->aluA);
			this->groupBox4->Controls->Add(this->label23);
			this->groupBox4->Controls->Add(this->ep_Cnd);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(7, 185);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(598, 54);
			this->groupBox4->TabIndex = 32;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Execute";
			// 
			// ep_dstE
			// 
			this->ep_dstE->Location = System::Drawing::Point(501, 22);
			this->ep_dstE->Name = L"ep_dstE";
			this->ep_dstE->ReadOnly = true;
			this->ep_dstE->Size = System::Drawing::Size(45, 23);
			this->ep_dstE->TabIndex = 31;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(455, 23);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(48, 17);
			this->label27->TabIndex = 30;
			this->label27->Text = L"e_dstE:";
			// 
			// ep_valE
			// 
			this->ep_valE->Location = System::Drawing::Point(407, 21);
			this->ep_valE->Name = L"ep_valE";
			this->ep_valE->ReadOnly = true;
			this->ep_valE->Size = System::Drawing::Size(45, 23);
			this->ep_valE->TabIndex = 29;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(363, 22);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(46, 17);
			this->label26->TabIndex = 28;
			this->label26->Text = L"e_valE:";
			// 
			// ALUfun
			// 
			this->ALUfun->Location = System::Drawing::Point(313, 21);
			this->ALUfun->Name = L"ALUfun";
			this->ALUfun->ReadOnly = true;
			this->ALUfun->Size = System::Drawing::Size(45, 23);
			this->ALUfun->TabIndex = 27;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(264, 22);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(52, 17);
			this->label25->TabIndex = 26;
			this->label25->Text = L"ALUfun:";
			// 
			// aluB
			// 
			this->aluB->Location = System::Drawing::Point(217, 21);
			this->aluB->Name = L"aluB";
			this->aluB->ReadOnly = true;
			this->aluB->Size = System::Drawing::Size(45, 23);
			this->aluB->TabIndex = 25;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(183, 22);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(36, 17);
			this->label24->TabIndex = 24;
			this->label24->Text = L"aluB:";
			// 
			// aluA
			// 
			this->aluA->Location = System::Drawing::Point(138, 21);
			this->aluA->Name = L"aluA";
			this->aluA->ReadOnly = true;
			this->aluA->Size = System::Drawing::Size(45, 23);
			this->aluA->TabIndex = 9;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(101, 21);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(36, 17);
			this->label23->TabIndex = 8;
			this->label23->Text = L"aluA:";
			// 
			// ep_Cnd
			// 
			this->ep_Cnd->Location = System::Drawing::Point(52, 20);
			this->ep_Cnd->Name = L"ep_Cnd";
			this->ep_Cnd->ReadOnly = true;
			this->ep_Cnd->Size = System::Drawing::Size(45, 23);
			this->ep_Cnd->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"e_Cnd:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(24, 274);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(36, 17);
			this->label28->TabIndex = 45;
			this->label28->Text = L"dstE:";
			// 
			// M_dstM
			// 
			this->M_dstM->Location = System::Drawing::Point(560, 161);
			this->M_dstM->Name = L"M_dstM";
			this->M_dstM->ReadOnly = true;
			this->M_dstM->Size = System::Drawing::Size(45, 23);
			this->M_dstM->TabIndex = 31;
			// 
			// E_valB
			// 
			this->E_valB->Location = System::Drawing::Point(477, 245);
			this->E_valB->Name = L"E_valB";
			this->E_valB->ReadOnly = true;
			this->E_valB->Size = System::Drawing::Size(45, 23);
			this->E_valB->TabIndex = 44;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(521, 161);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(41, 17);
			this->label15->TabIndex = 30;
			this->label15->Text = L"dstM:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(441, 245);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(35, 17);
			this->label29->TabIndex = 43;
			this->label29->Text = L"valB:";
			// 
			// M_dstE
			// 
			this->M_dstE->Location = System::Drawing::Point(473, 161);
			this->M_dstE->Name = L"M_dstE";
			this->M_dstE->ReadOnly = true;
			this->M_dstE->Size = System::Drawing::Size(45, 23);
			this->M_dstE->TabIndex = 29;
			// 
			// E_valA
			// 
			this->E_valA->Location = System::Drawing::Point(395, 245);
			this->E_valA->Name = L"E_valA";
			this->E_valA->ReadOnly = true;
			this->E_valA->Size = System::Drawing::Size(45, 23);
			this->E_valA->TabIndex = 42;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(438, 161);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(36, 17);
			this->label16->TabIndex = 28;
			this->label16->Text = L"dstE:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(361, 245);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(35, 17);
			this->label30->TabIndex = 41;
			this->label30->Text = L"valA:";
			// 
			// M_valA
			// 
			this->M_valA->Location = System::Drawing::Point(391, 161);
			this->M_valA->Name = L"M_valA";
			this->M_valA->ReadOnly = true;
			this->M_valA->Size = System::Drawing::Size(45, 23);
			this->M_valA->TabIndex = 27;
			// 
			// E_valC
			// 
			this->E_valC->Location = System::Drawing::Point(308, 245);
			this->E_valC->Name = L"E_valC";
			this->E_valC->ReadOnly = true;
			this->E_valC->Size = System::Drawing::Size(45, 23);
			this->E_valC->TabIndex = 40;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(358, 161);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(35, 17);
			this->label17->TabIndex = 26;
			this->label17->Text = L"valA:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(274, 245);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(35, 17);
			this->label31->TabIndex = 39;
			this->label31->Text = L"valC:";
			// 
			// M_valE
			// 
			this->M_valE->Location = System::Drawing::Point(304, 161);
			this->M_valE->Name = L"M_valE";
			this->M_valE->ReadOnly = true;
			this->M_valE->Size = System::Drawing::Size(45, 23);
			this->M_valE->TabIndex = 25;
			// 
			// E_ifun
			// 
			this->E_ifun->Location = System::Drawing::Point(226, 245);
			this->E_ifun->Name = L"E_ifun";
			this->E_ifun->ReadOnly = true;
			this->E_ifun->Size = System::Drawing::Size(45, 23);
			this->E_ifun->TabIndex = 38;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(271, 161);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(34, 17);
			this->label18->TabIndex = 24;
			this->label18->Text = L"valE:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(194, 245);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(32, 17);
			this->label32->TabIndex = 37;
			this->label32->Text = L"ifun:";
			// 
			// M_Cnd
			// 
			this->M_Cnd->Location = System::Drawing::Point(224, 161);
			this->M_Cnd->Name = L"M_Cnd";
			this->M_Cnd->ReadOnly = true;
			this->M_Cnd->Size = System::Drawing::Size(45, 23);
			this->M_Cnd->TabIndex = 23;
			// 
			// E_icode
			// 
			this->E_icode->Location = System::Drawing::Point(146, 245);
			this->E_icode->Name = L"E_icode";
			this->E_icode->ReadOnly = true;
			this->E_icode->Size = System::Drawing::Size(45, 23);
			this->E_icode->TabIndex = 36;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(106, 245);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(43, 17);
			this->label33->TabIndex = 35;
			this->label33->Text = L"icode:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(192, 161);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(34, 17);
			this->label19->TabIndex = 22;
			this->label19->Text = L"Cnd:";
			// 
			// E_stat
			// 
			this->E_stat->Location = System::Drawing::Point(59, 244);
			this->E_stat->Name = L"E_stat";
			this->E_stat->ReadOnly = true;
			this->E_stat->Size = System::Drawing::Size(45, 23);
			this->E_stat->TabIndex = 34;
			// 
			// M_icode
			// 
			this->M_icode->Location = System::Drawing::Point(146, 161);
			this->M_icode->Name = L"M_icode";
			this->M_icode->ReadOnly = true;
			this->M_icode->Size = System::Drawing::Size(45, 23);
			this->M_icode->TabIndex = 21;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(25, 245);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(32, 17);
			this->label34->TabIndex = 33;
			this->label34->Text = L"stat:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(106, 161);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(43, 17);
			this->label20->TabIndex = 20;
			this->label20->Text = L"icode:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(9, 245);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(15, 17);
			this->label35->TabIndex = 32;
			this->label35->Text = L"E";
			// 
			// M_stat
			// 
			this->M_stat->Location = System::Drawing::Point(59, 160);
			this->M_stat->Name = L"M_stat";
			this->M_stat->ReadOnly = true;
			this->M_stat->Size = System::Drawing::Size(45, 23);
			this->M_stat->TabIndex = 19;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(25, 161);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(32, 17);
			this->label21->TabIndex = 18;
			this->label21->Text = L"stat:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(9, 161);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(20, 17);
			this->label22->TabIndex = 17;
			this->label22->Text = L"M";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->mp_valM);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->mem_addr);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->mem_write);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->mem_read);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->mp_stat);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Location = System::Drawing::Point(7, 97);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(598, 58);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Memory";
			// 
			// mp_valM
			// 
			this->mp_valM->Location = System::Drawing::Point(511, 22);
			this->mp_valM->Name = L"mp_valM";
			this->mp_valM->ReadOnly = true;
			this->mp_valM->Size = System::Drawing::Size(45, 23);
			this->mp_valM->TabIndex = 13;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(457, 24);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(55, 17);
			this->label14->TabIndex = 12;
			this->label14->Text = L"m_valM:";
			// 
			// mem_addr
			// 
			this->mem_addr->Location = System::Drawing::Point(409, 21);
			this->mem_addr->Name = L"mem_addr";
			this->mem_addr->ReadOnly = true;
			this->mem_addr->Size = System::Drawing::Size(45, 23);
			this->mem_addr->TabIndex = 11;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(337, 23);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(73, 17);
			this->label13->TabIndex = 10;
			this->label13->Text = L"mem_addr:";
			// 
			// mem_write
			// 
			this->mem_write->Location = System::Drawing::Point(291, 21);
			this->mem_write->Name = L"mem_write";
			this->mem_write->ReadOnly = true;
			this->mem_write->Size = System::Drawing::Size(45, 23);
			this->mem_write->TabIndex = 9;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(219, 23);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(73, 17);
			this->label12->TabIndex = 8;
			this->label12->Text = L"mem_write:";
			// 
			// mem_read
			// 
			this->mem_read->Location = System::Drawing::Point(169, 20);
			this->mem_read->Name = L"mem_read";
			this->mem_read->ReadOnly = true;
			this->mem_read->Size = System::Drawing::Size(45, 23);
			this->mem_read->TabIndex = 7;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(98, 22);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(72, 17);
			this->label11->TabIndex = 6;
			this->label11->Text = L"mem_read:";
			// 
			// mp_stat
			// 
			this->mp_stat->Location = System::Drawing::Point(52, 20);
			this->mp_stat->Name = L"mp_stat";
			this->mp_stat->ReadOnly = true;
			this->mp_stat->Size = System::Drawing::Size(45, 23);
			this->mp_stat->TabIndex = 5;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(18, 21);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 17);
			this->label10->TabIndex = 4;
			this->label10->Text = L"stat:";
			// 
			// W_dstM
			// 
			this->W_dstM->Location = System::Drawing::Point(482, 73);
			this->W_dstM->Name = L"W_dstM";
			this->W_dstM->ReadOnly = true;
			this->W_dstM->Size = System::Drawing::Size(45, 23);
			this->W_dstM->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(445, 73);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 17);
			this->label9->TabIndex = 14;
			this->label9->Text = L"dstM:";
			// 
			// W_dstE
			// 
			this->W_dstE->Location = System::Drawing::Point(398, 73);
			this->W_dstE->Name = L"W_dstE";
			this->W_dstE->ReadOnly = true;
			this->W_dstE->Size = System::Drawing::Size(45, 23);
			this->W_dstE->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(362, 73);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 17);
			this->label8->TabIndex = 12;
			this->label8->Text = L"dstE:";
			// 
			// W_valM
			// 
			this->W_valM->Location = System::Drawing::Point(317, 73);
			this->W_valM->Name = L"W_valM";
			this->W_valM->ReadOnly = true;
			this->W_valM->Size = System::Drawing::Size(45, 23);
			this->W_valM->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(282, 73);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(39, 17);
			this->label7->TabIndex = 10;
			this->label7->Text = L"valM:";
			// 
			// W_valE
			// 
			this->W_valE->Location = System::Drawing::Point(228, 73);
			this->W_valE->Name = L"W_valE";
			this->W_valE->ReadOnly = true;
			this->W_valE->Size = System::Drawing::Size(45, 23);
			this->W_valE->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(195, 73);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"valE:";
			// 
			// W_icode
			// 
			this->W_icode->Location = System::Drawing::Point(147, 74);
			this->W_icode->Name = L"W_icode";
			this->W_icode->ReadOnly = true;
			this->W_icode->Size = System::Drawing::Size(45, 23);
			this->W_icode->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(108, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"icode:";
			// 
			// W_stat
			// 
			this->W_stat->Location = System::Drawing::Point(59, 73);
			this->W_stat->Name = L"W_stat";
			this->W_stat->ReadOnly = true;
			this->W_stat->Size = System::Drawing::Size(45, 23);
			this->W_stat->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"stat:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"W";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->wp_stat);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(6, 15);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(599, 50);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Write Back";
			// 
			// wp_stat
			// 
			this->wp_stat->Location = System::Drawing::Point(53, 21);
			this->wp_stat->Name = L"wp_stat";
			this->wp_stat->ReadOnly = true;
			this->wp_stat->Size = System::Drawing::Size(45, 23);
			this->wp_stat->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(19, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"stat:";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button3);
			this->groupBox7->Controls->Add(this->button2);
			this->groupBox7->Controls->Add(this->cycle);
			this->groupBox7->Controls->Add(this->button1);
			this->groupBox7->Controls->Add(this->time);
			this->groupBox7->Controls->Add(this->label64);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox7->Location = System::Drawing::Point(640, 27);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(143, 177);
			this->groupBox7->TabIndex = 2;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"操作";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(31, 140);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 28);
			this->button3->TabIndex = 14;
			this->button3->Text = L"单步运行";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(31, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 28);
			this->button2->TabIndex = 13;
			this->button2->Text = L"暂停";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// cycle
			// 
			this->cycle->AutoSize = true;
			this->cycle->Location = System::Drawing::Point(8, 21);
			this->cycle->Name = L"cycle";
			this->cycle->Size = System::Drawing::Size(41, 17);
			this->cycle->TabIndex = 12;
			this->cycle->Text = L"Cycle:";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(31, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 28);
			this->button1->TabIndex = 11;
			this->button1->Text = L"自动运行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// time
			// 
			this->time->Location = System::Drawing::Point(88, 42);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(45, 23);
			this->time->TabIndex = 10;
			this->time->Text = L"1000";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(6, 45);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(84, 17);
			this->label64->TabIndex = 0;
			this->label64->Text = L"时钟周期(ms):";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->edi);
			this->groupBox8->Controls->Add(this->label70);
			this->groupBox8->Controls->Add(this->esi);
			this->groupBox8->Controls->Add(this->label71);
			this->groupBox8->Controls->Add(this->ebp);
			this->groupBox8->Controls->Add(this->label72);
			this->groupBox8->Controls->Add(this->esp);
			this->groupBox8->Controls->Add(this->label73);
			this->groupBox8->Controls->Add(this->ebx);
			this->groupBox8->Controls->Add(this->label69);
			this->groupBox8->Controls->Add(this->edx);
			this->groupBox8->Controls->Add(this->label68);
			this->groupBox8->Controls->Add(this->ecx);
			this->groupBox8->Controls->Add(this->label67);
			this->groupBox8->Controls->Add(this->eax);
			this->groupBox8->Controls->Add(this->label66);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox8->Location = System::Drawing::Point(642, 212);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(140, 246);
			this->groupBox8->TabIndex = 3;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"寄存器";
			// 
			// edi
			// 
			this->edi->Location = System::Drawing::Point(42, 214);
			this->edi->Name = L"edi";
			this->edi->ReadOnly = true;
			this->edi->Size = System::Drawing::Size(73, 23);
			this->edi->TabIndex = 50;
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(8, 215);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(29, 17);
			this->label70->TabIndex = 49;
			this->label70->Text = L"edi:";
			// 
			// esi
			// 
			this->esi->Location = System::Drawing::Point(42, 187);
			this->esi->Name = L"esi";
			this->esi->ReadOnly = true;
			this->esi->Size = System::Drawing::Size(73, 23);
			this->esi->TabIndex = 48;
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(8, 188);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(27, 17);
			this->label71->TabIndex = 47;
			this->label71->Text = L"esi:";
			// 
			// ebp
			// 
			this->ebp->Location = System::Drawing::Point(42, 160);
			this->ebp->Name = L"ebp";
			this->ebp->ReadOnly = true;
			this->ebp->Size = System::Drawing::Size(73, 23);
			this->ebp->TabIndex = 46;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(8, 161);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(34, 17);
			this->label72->TabIndex = 45;
			this->label72->Text = L"ebp:";
			// 
			// esp
			// 
			this->esp->Location = System::Drawing::Point(42, 132);
			this->esp->Name = L"esp";
			this->esp->ReadOnly = true;
			this->esp->Size = System::Drawing::Size(73, 23);
			this->esp->TabIndex = 44;
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(8, 133);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(32, 17);
			this->label73->TabIndex = 43;
			this->label73->Text = L"esp:";
			// 
			// ebx
			// 
			this->ebx->Location = System::Drawing::Point(42, 105);
			this->ebx->Name = L"ebx";
			this->ebx->ReadOnly = true;
			this->ebx->Size = System::Drawing::Size(73, 23);
			this->ebx->TabIndex = 42;
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(8, 106);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(32, 17);
			this->label69->TabIndex = 41;
			this->label69->Text = L"ebx:";
			// 
			// edx
			// 
			this->edx->Location = System::Drawing::Point(42, 78);
			this->edx->Name = L"edx";
			this->edx->ReadOnly = true;
			this->edx->Size = System::Drawing::Size(73, 23);
			this->edx->TabIndex = 40;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(8, 79);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(32, 17);
			this->label68->TabIndex = 39;
			this->label68->Text = L"edx:";
			// 
			// ecx
			// 
			this->ecx->Location = System::Drawing::Point(42, 51);
			this->ecx->Name = L"ecx";
			this->ecx->ReadOnly = true;
			this->ecx->Size = System::Drawing::Size(73, 23);
			this->ecx->TabIndex = 38;
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(8, 52);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(30, 17);
			this->label67->TabIndex = 37;
			this->label67->Text = L"ecx:";
			// 
			// eax
			// 
			this->eax->Location = System::Drawing::Point(42, 23);
			this->eax->Name = L"eax";
			this->eax->ReadOnly = true;
			this->eax->Size = System::Drawing::Size(73, 23);
			this->eax->TabIndex = 36;
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(8, 24);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(31, 17);
			this->label66->TabIndex = 35;
			this->label66->Text = L"eax:";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->pictureBox1);
			this->groupBox9->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox9->Location = System::Drawing::Point(643, 461);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(138, 69);
			this->groupBox9->TabIndex = 4;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Clock";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(3, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(129, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"yo文件|*.yo";
			this->openFileDialog1->Title = L"打开";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"txt";
			this->saveFileDialog1->Filter = L"文本文件|*.txt";
			this->saveFileDialog1->Title = L"保存";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->button5);
			this->groupBox10->Controls->Add(this->button4);
			this->groupBox10->Controls->Add(this->ins);
			this->groupBox10->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox10->Location = System::Drawing::Point(793, 27);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(172, 287);
			this->groupBox10->TabIndex = 5;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"指令集";
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(92, 248);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(74, 28);
			this->button5->TabIndex = 13;
			this->button5->Text = L"取消断点";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(6, 248);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(74, 28);
			this->button4->TabIndex = 12;
			this->button4->Text = L"设置断点";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// ins
			// 
			this->ins->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->ins_addr, this->ins_ins});
			this->ins->FullRowSelect = true;
			this->ins->GridLines = true;
			this->ins->Location = System::Drawing::Point(6, 19);
			this->ins->Name = L"ins";
			this->ins->Size = System::Drawing::Size(160, 217);
			this->ins->TabIndex = 0;
			this->ins->UseCompatibleStateImageBehavior = false;
			this->ins->View = System::Windows::Forms::View::Details;
			// 
			// ins_addr
			// 
			this->ins_addr->Text = L"地址";
			this->ins_addr->Width = 46;
			// 
			// ins_ins
			// 
			this->ins_ins->Text = L"指令";
			this->ins_ins->Width = 200;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->OF);
			this->groupBox11->Controls->Add(this->SF);
			this->groupBox11->Controls->Add(this->ZF);
			this->groupBox11->Controls->Add(this->F_ins);
			this->groupBox11->Controls->Add(this->label77);
			this->groupBox11->Controls->Add(this->D_ins);
			this->groupBox11->Controls->Add(this->label76);
			this->groupBox11->Controls->Add(this->E_ins);
			this->groupBox11->Controls->Add(this->label75);
			this->groupBox11->Controls->Add(this->M_ins);
			this->groupBox11->Controls->Add(this->label74);
			this->groupBox11->Controls->Add(this->W_ins);
			this->groupBox11->Controls->Add(this->label65);
			this->groupBox11->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox11->Location = System::Drawing::Point(793, 322);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(171, 207);
			this->groupBox11->TabIndex = 6;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"其他";
			// 
			// OF
			// 
			this->OF->AutoSize = true;
			this->OF->Location = System::Drawing::Point(119, 179);
			this->OF->Name = L"OF";
			this->OF->Size = System::Drawing::Size(48, 17);
			this->OF->TabIndex = 12;
			this->OF->Text = L"OF = 0";
			// 
			// SF
			// 
			this->SF->AutoSize = true;
			this->SF->Location = System::Drawing::Point(67, 179);
			this->SF->Name = L"SF";
			this->SF->Size = System::Drawing::Size(45, 17);
			this->SF->TabIndex = 11;
			this->SF->Text = L"SF = 0";
			// 
			// ZF
			// 
			this->ZF->AutoSize = true;
			this->ZF->Location = System::Drawing::Point(10, 179);
			this->ZF->Name = L"ZF";
			this->ZF->Size = System::Drawing::Size(45, 17);
			this->ZF->TabIndex = 10;
			this->ZF->Text = L"ZF = 0";
			// 
			// F_ins
			// 
			this->F_ins->Location = System::Drawing::Point(26, 139);
			this->F_ins->Name = L"F_ins";
			this->F_ins->ReadOnly = true;
			this->F_ins->Size = System::Drawing::Size(139, 23);
			this->F_ins->TabIndex = 9;
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(9, 142);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(14, 17);
			this->label77->TabIndex = 8;
			this->label77->Text = L"F";
			// 
			// D_ins
			// 
			this->D_ins->Location = System::Drawing::Point(26, 110);
			this->D_ins->Name = L"D_ins";
			this->D_ins->ReadOnly = true;
			this->D_ins->Size = System::Drawing::Size(139, 23);
			this->D_ins->TabIndex = 7;
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(9, 113);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(17, 17);
			this->label76->TabIndex = 6;
			this->label76->Text = L"D";
			// 
			// E_ins
			// 
			this->E_ins->Location = System::Drawing::Point(26, 81);
			this->E_ins->Name = L"E_ins";
			this->E_ins->ReadOnly = true;
			this->E_ins->Size = System::Drawing::Size(139, 23);
			this->E_ins->TabIndex = 5;
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(9, 84);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(15, 17);
			this->label75->TabIndex = 4;
			this->label75->Text = L"E";
			// 
			// M_ins
			// 
			this->M_ins->Location = System::Drawing::Point(26, 53);
			this->M_ins->Name = L"M_ins";
			this->M_ins->ReadOnly = true;
			this->M_ins->Size = System::Drawing::Size(139, 23);
			this->M_ins->TabIndex = 3;
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(8, 56);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(20, 17);
			this->label74->TabIndex = 2;
			this->label74->Text = L"M";
			// 
			// W_ins
			// 
			this->W_ins->Location = System::Drawing::Point(26, 24);
			this->W_ins->Name = L"W_ins";
			this->W_ins->ReadOnly = true;
			this->W_ins->Size = System::Drawing::Size(139, 23);
			this->W_ins->TabIndex = 1;
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(8, 27);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(20, 17);
			this->label65->TabIndex = 0;
			this->label65->Text = L"W";
			// 
			// 编译器ToolStripMenuItem
			// 
			this->编译器ToolStripMenuItem->Name = L"编译器ToolStripMenuItem";
			this->编译器ToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->编译器ToolStripMenuItem->Text = L"编译器";
			this->编译器ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::编译器ToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(976, 542);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Y86流水线模拟器";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void 退出ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void 操作ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 myPen = gcnew System::Drawing::Pen(System::Drawing::Color::Black,2);
			 bmp = gcnew System::Drawing::Bitmap(pictureBox1->Width*2,pictureBox1->Height);
			 pointReset();
			 Graphics^g = Graphics::FromImage(bmp);
			 g->Clear(pictureBox1->BackColor);
			 int i ;
			 for(i=0;i<11;i++) g->DrawLine(myPen,px[i],py[i],px[i+1],py[i+1]);
			 pictureBox1->Image = bmp;
			 delete g ;

			 breakpoint = NULL;
			 form2 = nullptr;
		 }
private: System::Void 打开ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ filename;
			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 filename = openFileDialog1->FileName;
			 }else return;
			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(filename); //String 转 char*
			 file.openFile(str);
			 int size;
			 BYTE * data = file.GetData(size);
			 pipe.reset();
			 pipe.LoadINS(data,size);
			 cycle->Text = "Cycle:";
			 cycle_count = -1;
			 button1->Enabled = true;
			 button3->Enabled = true;
			 button4->Enabled = true;
			 button5->Enabled = true;
			 导出运行结果ToolStripMenuItem->Enabled = true;
			 for(int i = ins->Items->Count-1 ;i>=0; i--) ins->Items->RemoveAt(i);
			 int count = file.GetInsNumber();
			 for(int i = 0; i<count; i++){
				 ListViewItem^ lvi = gcnew ListViewItem();
				 lvi->ImageIndex = i;
				 lvi->Text = "0x" + file.GetAddr(i).ToString("x");
				 string str = file.GetInsStr(i);
				 String ^ MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)str.c_str());
				 lvi->SubItems->Add(MyStr);
				 ins->Items->Add(lvi);

			 }
			 if(breakpoint) delete[] breakpoint;
			 breakpoint = new bool[size];
			 memset(breakpoint,false,sizeof(bool)*size);
			 MessageBox::Show("打开文件成功！");
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(pipe.isHalt()){
				 MessageBox::Show("指令已执行完毕！");
				 return;
			 }
			 pipe.Run();
			 cycle_count++;
			 cycle->Text = "Cycle:" + cycle_count.ToString();
			 UpdataState();

		 }
private: System::Void 导出运行结果ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ filename;
			 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 filename = saveFileDialog1->FileName;
			 }else return;
			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(filename); //String 转 char*
			 pipe.reset();
			 pipe.autoRunAndExport(str);
			 pipe.reset();
			 cycle_count = -1;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 t_count++; t_count = t_count % 10;
			 if(t_count!=0){
				Graphics^g = Graphics::FromImage(bmp);
				g->Clear(pictureBox1->BackColor);
				movePoint(6);
				int i ;
				for(i=0;i<11;i++) g->DrawLine(myPen,px[i],py[i],px[i+1],py[i+1]);
				pictureBox1->Image = bmp;
				delete g ;
				return;
			 }else{
				Graphics^g = Graphics::FromImage(bmp);
				g->Clear(pictureBox1->BackColor);
				pointReset();
				int i ;
				for(i=0;i<11;i++) g->DrawLine(myPen,px[i],py[i],px[i+1],py[i+1]);
				pictureBox1->Image = bmp;
				delete g ;
			 }
			 if(pipe.isHalt()){
				 this->timer1->Enabled = false;
				 this->button2->Enabled = false;
				 MessageBox::Show("指令已执行完毕！");
				 return;
			 }
			 cycle_count++;
			 cycle->Text = "Cycle:" + cycle_count.ToString();
			 pipe.Run();
			 UpdataState();
			 if(breakpoint[pipe.GetFetchInfo().f_pc]){
				 timer1->Stop();
				 run_stat = false;
				 button2->Text = "继续";
				 MessageBox::Show("遇到断点处（地址：0x" + pipe.GetFetchInfo().f_pc.ToString("x") + ")");
			 }


		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Stop();
			 timer1->Enabled = true;
			 int t = int::Parse(time->Text);
			 t = t/10; if(t<=0) t = 1;
			 timer1->Interval = t;
			 timer1->Start();
			 t_count = -1;
			 run_stat = true;
			 button2->Text = "暂停";
			 button2->Enabled = true;
			 //pipe.reset();
			 //cycle_count = -1;

		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(run_stat){
				 timer1->Stop();
				 run_stat = false;
				 button2->Text = "继续";
			 }else{
				 timer1->Start();
				 run_stat = true;
				 button2->Text = "暂停";
			 }
		 }
private: System::Void 重置ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pipe.reset();
			 UpdataState();
			 cycle->Text = "Cycle:";
			 cycle_count = -1;

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(ins->SelectedItems->Count > 0){
				 int index = ins->SelectedItems[0]->ImageIndex;
				 ins->SelectedItems[0]->ForeColor = Color::Red;
				 breakpoint[file.GetAddr(index)] = true;
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(ins->SelectedItems->Count > 0){
				 int index = ins->SelectedItems[0]->ImageIndex;
				 ins->SelectedItems[0]->ForeColor = Color::Black;
				 breakpoint[file.GetAddr(index)] = false;
			 }
		 }
private: System::Void 编译器ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(form2==nullptr) form2 = gcnew Form2();
			 form2->Show();
		 }
};
}


#pragma once
#include "Y86Code.h"
#include <msclr\auto_handle.h>
namespace MyForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	/// <summary>
	/// Form2 摘要
	/// </summary>
	
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  code1;
	private: System::Windows::Forms::TextBox^  code2;
	protected: 

	protected: 

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->code1 = (gcnew System::Windows::Forms::TextBox());
			this->code2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// code1
			// 
			this->code1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->code1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->code1->Location = System::Drawing::Point(12, 2);
			this->code1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->code1->Multiline = true;
			this->code1->Name = L"code1";
			this->code1->Size = System::Drawing::Size(358, 539);
			this->code1->TabIndex = 0;
			// 
			// code2
			// 
			this->code2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->code2->Location = System::Drawing::Point(479, 1);
			this->code2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->code2->Multiline = true;
			this->code2->Name = L"code2";
			this->code2->Size = System::Drawing::Size(396, 539);
			this->code2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(376, 164);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 44);
			this->button1->TabIndex = 2;
			this->button1->Text = L"转换->";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(376, 254);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 44);
			this->button2->TabIndex = 3;
			this->button2->Text = L"保存";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"yo 文件|*.yo";
			this->saveFileDialog1->Title = L"保存";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 543);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->code2);
			this->Controls->Add(this->code1);
			this->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Y86汇编指令转换";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form2::Form2_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form2_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 e->Cancel = true;
				 this->Hide();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Y86Code dc;
				 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(code1->Text);
				 string res = dc.Decode(str);
				 String ^ MyStr = Marshal::PtrToStringAnsi((IntPtr)(char *)res.c_str());
				 code2->Text = MyStr;
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ filename;
			 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 filename = saveFileDialog1->FileName;
			 }else return;
			 FileStream^ fs = gcnew FileStream(filename,FileMode::Create);
			 StreamWriter^ sw = gcnew StreamWriter(fs);
			 sw->Write(code2->Text);
			 sw->Flush();
			 sw->Close();
			 fs->Close();
		 }
};
}
